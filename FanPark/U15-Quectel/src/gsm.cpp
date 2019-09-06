#include "gsm.h"

using namespace std;

int const modem_pwrkey_gpio = 65;
int const modem_reset_gpio = 64;
int const modem_usb_vbus_gpio = 28;
string const ppp_file = "lte";

vector <string> modem_config_mode = {
            "nwscanmode",
            "nwscanseq",
            "roamservice",
            "servicedomain",
            "band"
};

vector <int> mode_values = {
            0,
            2,
            255,
            2,
            512
};

// Constructor
gsm::gsm(string port, int baudrate) {
    port_gsm = new Serial(port, baudrate);
    if(!port_gsm->open()) {
        cout << "GSM serial can't be opened" << endl;
    }
}

string gsm::read_string() {
    return port_gsm->readString();
}

void gsm::write_string(string message) {
    port_gsm->writeString(message);
}

bool gsm::init() {
    return port_gsm->open();
}


// Utilities

/* APIs to read and write from and on the open serial port */
string gsm::send_com(string command, int res_time) {
    port_gsm->writeString(command);
    int sleep_time = res_time * 1000;
    usleep(sleep_time);
    return port_gsm->readString();
}

/* Convert string to integer */
int gsm::str_2_int(string input) {
    stringstream tmp(input);
    int val = 0;
    tmp >> val;
    return val;
}

/* String Parser */
vector <string> gsm::parse_str(string input, int start_pos, string delimiter) {
    string result, token;
    int pos = 0;
    vector <string> tokens;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(start_pos, pos);
        tokens.push_back(token);
        input.erase(start_pos, pos + delimiter.length());
    }
    return tokens;
}

/* Read Variables state using AT */
string gsm::read_var(string command, int pos) {
    string at_res = send_com(command);
    if(at_res.find("OK") != string::npos){
        vector <string> res_stack = parse_str(at_res, 0, ": ");
        string final_stack = res_stack[1];
        vector <string> variables = parse_str(final_stack, 0, ",");
        if (variables.size() > 1) return variables[pos];            // If more than 1 variable is available
        else return variables[0];
    }
    else return at_res;
}

/* Read GPIO port state */
int gsm::read_gpio(string gpio_port) {
    int val = 0;
    string file_name = "/sys/class/gpio/gpio" + gpio_port + "/value";
    fd.open(file_name);
    if(!fd) {
        cout << "Unable to open file!" << endl;
        exit(1);
    }
    fd >> val;
    fd.close();
    return val;
}

// Coreboard initiation

/* Turns on USB hub, UC15 USB VBUS and CP2105 IC */
bool gsm::pwron_dependencies() {
    if(read_gpio("26") == 1) dev_man.openPort(26, 1, 0);     // Power on USB Hub
    if(read_gpio("27") == 1) dev_man.openPort(27, 1, 0);     // Power on CP2105
    if(read_gpio("28") == 1) dev_man.openPort(28, 1, 0);     // Power on UC15 USB VBUS
    return true;
}

// Hardware Control and Configurations

/* Modem Power on and off  */
bool gsm::pwron_modem(int timer, int gpio_port) {
    dev_man.openPort(gpio_port, 1, 0);
    usleep(timer * 1000);
    dev_man.openPort(gpio_port, 1, 1);
    return true;
}

/* Reboot Modem */
bool gsm::reboot_modem(int timer, int gpio_port) {
    usleep(timer * 1000 * 1000);        // Sleep timer in seconds
    dev_man.openPort(gpio_port, 1, 0);
    usleep(2 * 1000 * 1000);
    dev_man.openPort(gpio_port, 1, 1);
    return true;
}

/* Clock */
string gsm::modem_time() {
    string at_res = send_com("AT+CCLK?");
    if(at_res.find("OK") != string::npos){
        vector <string> results = parse_str(at_res, 0, ":");
        string res_time = results[1];
        return res_time;
    }
    else return at_res;
}

/* Sleep Mode */
bool gsm::modem_sleep(int state, int gpio_port) {
    string at_res;
    switch (state) {
    case 0:
        dev_man.openPort(gpio_port,1, 1);
        cout << "Waking up the modem" <<endl;
        return true;
    case 1:
        at_res = send_com("AT+QSCLK=1");
        if(at_res.find("OK") != string::npos){
            dev_man.openPort(gpio_port,1,0);
            cout << "Entering Sleep mode" << endl;
            return true;
        }

    }
    return false;
}

// Serial Interface Configurations

/* Set TE-TA baudrate */
bool gsm::set_baudrate(int baudrate) {
    string at_res = send_com("AT+IPR=" + to_string(baudrate) + "&W");
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}


// Status Control Configurations

/* GPRS attach mode */
bool gsm::gprs_attach_mode(int mode = 1) {
    string at_res = send_com("AT+QCFG=\"gprsattach\"," + to_string(mode));
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}

/* Network Search Configurations */
void gsm::mode_config(vector <string> modem_config_mode, vector <int> mode_values, int effect){
    for ( unsigned int i = 1 ; i < modem_config_mode.size() ; i++) {
        string at_res = send_com("AT+QCFG=\"" + modem_config_mode[i] + "\"," + to_string(mode_values[i]) + "," + to_string(effect));
        if(at_res.find("OK") != string::npos) cout << modem_config_mode[i] + "set" << endl;
        else cout << "Error setting" + modem_config_mode[i] << endl;
    }
}

/* AP_READY Configurations */

/* Query Module's Operation Band */
string gsm::operation_band() {
    return send_com("AT+QGBAND?");
}


// SIM Related Configurations

/* Request IMSI */
string gsm::query_imsi() {
    return send_com("AT+CIMI");
}

/* SIM detection */
bool gsm::sim_detect(int enable, int insert_level) {
    string at_res = send_com("AT+QSIMDET=1,0");
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}

/* Query Staus of SIM Initialization */
string gsm::sim_stat() {
    int stat = str_2_int(read_var("AT+QINISTAT"));
    switch (stat) {
    case 0:
        return "Initial State";
    case 1:
        return "CPIN READY";
    default:
        return "SIM Ready";
    }
}

/* SIM Card Initialization */
bool gsm::sim_init(string pin) {
    string at_res = read_var("AT+CPIN?");
    if(at_res.find("READY") != string::npos) return true;
    else {
        if(at_res.find("SIM PIN") != string::npos){
            at_res = send_com("AT+CPIN=" + pin);
            if(at_res.find("OK") != string::npos) return true;
            else return false;
        }
    }
}


/* Perform Powerup/down to SIM */
bool gsm::sim_power(int op) {
    string at_res;
    switch (op) {
    case 0:
        at_res = send_com("AT+QFUN=5");
        if(at_res.find("OK") != string::npos){
            cout << "Performing a power down to SIM" <<endl;
            return true;
        }
        else {
            cout << at_res <<endl;
            return false;
        }

   case 1:
        at_res = send_com("AT+QFUN=6");
        if(at_res.find("OK") != string::npos){
            cout << "Performing a power up to SIM" <<endl;
            return true;
        }
        else {
            cout << at_res <<endl;
            return false;
        }
    default:
        cout << "Wrong input, only 0 and 1 are acceptable!" <<endl;
        return false;
    }
}

/* SIM Inserted Status Report */
bool gsm::sim_det_report(int enable) {
    string at_res = send_com("AT+QSIMSTAT=" + to_string(enable));
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}



// Network Service Configuration

/* Operator Selection */
bool gsm::op_select(){
    string at_res = send_com("AT+COPS=0");
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}

/* Network Registration CS */
string gsm::cs_reg(){
    string res = read_var("AT+CREG?");
    if(res.find("ERROR") != string::npos) return res;
    else {
        int cs_status = str_2_int(res);
        switch (cs_status) {
        case 0:
            return "Not registered, looking for an operator to register to";
        case 1:
            return "Registered home network";
        case 2:
            return "Searching";
        case 3:
            return  "Registration denied";
        case 4:
            return "Unknown";
        case 5:
            return "Registered, roaming";
        }
    }
    return "CG Reg Done";
}

/* Check signal quality */
string gsm::signal_quality(){
    string res = read_var("AT+CSQ");
    if(res.find("ERROR") != string::npos) return res;
    else {
        signed int signal_q = str_2_int(res);
        switch (signal_q) {
        case 0:
            return "Extremely Poor";
        case 1:
            return "Poor";
        case 3:
            return "Excellent";
        case 99:
            return "Unknown";
        default:
            return "Good";
        }
    }
}

/* Automatic Timezone Update */
bool gsm::auto_timezone(int on_off){
    string at_res = send_com("AT+CTUZ=" + to_string(on_off));
    if(at_res.find("OK") != string::npos) return true;
    else return false;
}

// Packet Domain Configurations

/* PS Attach/Detachment */
bool gsm::ps_attachment(int state){
    string res = read_var("AT+CGATT?");
    if(res.find("ERROR") != string::npos) return false;
    else {
        int attach_state = str_2_int(res);
        if(state == attach_state) return true;
        else {
            string at_res = send_com("AT+CGATT=" + to_string(state));
            if(at_res.find("OK") != string::npos) return true;
            else return false;
        }
    }
}

/* Network Registration PS */
string gsm::ps_reg(){
    string res = read_var("AT+CGREG?");
    if(res.find("ERROR") != string::npos) return res;
    else {
        int ps_status = str_2_int(res);
        switch (ps_status) {
        case 0:
            return "Not registered, looking for an operator to register to";
        case 1:
            return  "Registered home network";
        case 2:
            return "Searching";
        case 3:
            return "Registration denied";
        case 4:
            return "Unknown";
        case 5:
            return "Registered, roaming";
        }
    }
    return "PS reg Done";
}

// Switch Modes

/* Enter Data mode using PPP */
string gsm::to_data(string port, int baudrate){
    string res = exec("pppd " + port + to_string(baudrate) + "call " + ppp_file + " &");
    if(res.find("Connected") != string::npos) return "Connected to Internet";
    else return res;
}

/* Enter Command mode */
string gsm::to_command(){
    string res = exec("killall pppd");
    if(res.find("no process found") != string::npos) return "Process is not running";
    else return res;
}

// PPP Connection Configuration

/* Show Modem Status */
void gsm::print_modem(){
    if(pwron_dependencies()){
        cout << "Dependent ICs and Hubs turned ON!" << endl;
        if(pwron_modem()){
            cout << "3G Modem turned ON!" << endl;
            cout << "Modem Time: " + modem_time() << endl;
            cout << "Modem's Operation Band: " + operation_band() << endl;
            cout << "IMSI: " + query_imsi() << endl;
            if(sim_init()) cout << "Entering PIN" << endl;
            cout << "SIM Status: " + sim_stat() << endl;
            cout << "CS Network Status: " + cs_reg() << endl;
            cout << "Signal Quality: " + signal_quality() << endl;
            cout << "PS Network Status: " + ps_reg() << endl;
            cout << "Starting PPP connection" << endl;

        }
        else cout << "Could not turn on Modem!";
    }
    else cout << "Could not turn on modem dependencies!" << endl;
}

/* Show IP address */
string gsm::show_ip(){
    string ip_addr = exec("ip addr | grep eth0 | grep inet");
    vector <string> ppp_if = parse_str(ip_addr, 0, " ");
    return ppp_if[1];
}

/* Initialize PPP call */
void gsm::ppp_script_ini(string file_name, string port, int baudrate){
    string res = to_data(file_name, port, baudrate);
    cout << res << endl;
    cout << show_ip() << endl;
}

/* Modem's Operation */
string gsm::module_start(string file_name, string port, int baudrate, string pin){
    print_modem();
    ppp_script_ini(file_name, port, baudrate);
}

