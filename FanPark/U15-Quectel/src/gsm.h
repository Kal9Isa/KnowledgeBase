#ifndef GSM

#include "Serial.h"
#include "devicemanager.h"
#include "global.h"

#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include <chrono>
#include <ctime>

extern int const modem_pwrkey_gpio;
extern int const modem_reset_gpio;
extern int const modem_usb_vbus_gpio;
extern string const ppp_file;
extern vector <string> modem_config_mode;
extern vector <int> mode_values;

class gsm {
private:
    Serial *port_gsm;
    DeviceManager dev_man;
    ifstream fd;

public:

    gsm(string port, int baudrate);
    string read_string();
    void write_string(string message);
    bool init();

    // Utilities

    /* APIs to read and write from and on the open serial port
    @parameters: <command>: the AT command to be sent,
             <res_time>: maximum response time of the AT command in ms
    @returns: a string as a response to the AT command */
    string send_com(string command, int res_time = 300);

    /* String to integer converter
    @parameters: <input>: string
    @returns: <input>: int */
    int str_2_int(string input);

    /* String parser
    @parameters: <input>: string to parse, <start_pos>: starting position of cursor, <delimeter>: the character to split the input based upon
    @returns: a vector of input parts divided by delimeters */
    std::vector <string> parse_str(string input, int start_pos, string delimeter);

    /* Read Variables state using AT
    @parameters: <command>: AT command to be sent, <pos>: postition of the desired variable
    @returns: Variable value, error message if failed */
    string read_var(string command, int pos = 0);

    /* Read GPIO port states
    @parameters: <gpio_port> to check
    @returns: 0 or 1 */
    int read_gpio(string gpio_port);

// Baisc Functions

    // Coreboard initiation

    /* Turns on USB hub, UC15 USB VBUS and CP2105 IC */
    bool pwron_dependencies();

    // Hardware Control and Configurations

    /* Modem Power on and off
    @parameters: <gpio_port>: Modem PWRKEY GPIO port number , <timer>: amount of time to hold down the pwrkey of UC15 in ms
    @returns: true if succ, false otherwise */
    bool pwron_modem(int timer = 0, int gpio_port = modem_pwrkey_gpio);

    /* Reboot Modem
    @parameter: <timer>: countdown to start rebooting in seconds
    @returns: true if succ, false otherwise */
    bool reboot_modem(int timer, int gpio_port = modem_reset_gpio);


    /* Clock
    @returns: true if succ, false otherwise */
    string modem_time();

    /* Sleep mode, needs to enable the QSCLK and disconnect USB_VBUS to enter sleep mode
    @parameters: <state>: 0 -> wake up, 1 -> sleep mode
    @returns: true if succ, false otherwise */
    bool modem_sleep(int state, int gpio_port = modem_usb_vbus_gpio);


    // Serial Interface Configurations

    /* TE-TA Control Character Framing
    @parameters: <parity>: 0 -> Odd, 1 -> Even, 2 -> Mark, 3 -> Space
    @returns: <format>: 3 -> 8 data 0 parity 1 stop */
//    string serial_ccf(int parity);

    /* Set TE-TA baudrate
    @parameters <rate> bps
    @returns true if succ, false otherwise */
    bool set_baudrate(int baudrate);

    /* Set Ring Line to deactive
    @returns: true if succ, false otherwise */
    bool rl_deactive();


    // Status Control Configurations

    /* Enable/Disable DTR to control power save state
    @parameters: <value>: 0 -> deactive, 1 -> active
    @returns: true if succ, false otherwise */
    bool dtr_state(int value);

    /* Temperature detection
    @parameters: <value>: 0 -> deactive, 1 -> active,
                 <min_temp>: in dV = 10 * V,
                 <max_temp>: in dV,
                 <warning_threshold>: in percent
    @returns: true if succ, false otherwise
    If activated, it can output URCs on temperature limits */
    bool voltage_detect(int value, int min_v = 32, int max_v = 44, int warning_threshold = 10);

    /* Voltage detection
    @parameters: <value>: 0 -> deactive, 1 -> active,
                 <min_temp>: in Celsius,
                 <max_temp>: in Celsius,
                 <warning_threshold>: in percent
    @returns: true if succ, false otherwise
    If activated, it can output URCs on temperature limits */
    bool temp_detect(int value, signed int min_temp = -40, signed int max_temp = 90, int warning_threshold = 10);

    /* GPRS Attach mode
    @params: <mode>: 0 -> manual, 1 -> auto
    @returns: true if succ, false otherwise */
    bool gprs_attach_mode(int mode);

    /* Network Search Configurations
    @params: <scanmode>: 0 -> auto, 1 -> GSM only, 2 -> UMTS only,
             <effect>: 0 -> after UE reboot, 1 -> immediately,
             <priority>: 0 -> auto, 1 -> GSM prior to WCDMA, 2 -> WCDMA prior to GSM,
             <domain>: 0 -> CS only, 1 -> PS only, 2 -> CS & PS,
             <band>: band of UE based on the coding speified in manual, 512 -> any,
             <roam>: 1 -> disable, 2 -> enable, 255 -> auto */
    void mode_config(vector <string> modem_config_mode, vector <int> mode_values, int effect = 1);

    /* AP_READY configuration ?
    @parameters: <enable>: 0 -> disable, 1 -> enable
                 <level>: 0 -> low, 1 -> high,
                 <interval>: detection period in ms
    @returns: true if succ, false otherwise */
    bool ap_ready(int enable, int level, int interval = 500);

    /* Query module operation band
    @returns: current band */
    string operation_band();


    // SIM Related Configurations

    /* Request IMSI
    @returns: IMSI */
    string query_imsi();

    /* SIM detection
    @parameters: <enable>: 0 -> off, 1 -> on,
                 <insert_level>: 0 -> low , 1 -> high
    @returns: true if succ, false otherwise */
    bool sim_detect(int enable = 0, int insert_level = 0);

    /* Query status of SIM initialization
    @returns: status */
    string sim_stat();

    /* SIM Card initialization
    @parameters: <pin>
    @returns: true if succ, false otherwise */
    bool sim_init(string pin = "");    

    /* Perform power up/down to SIM
    @parameters: <op>: 0 -> powerdown, 1 -> powerup
    @returns: true if succ, false otherwise */
    bool sim_power(int op);

    /* SIM inserted status report
    @parameters: <enable>: 0 -> off, 1 -> on,
    @return: status */
    bool sim_det_report(int enable = 0);


    // Network Service Configurations

    /* Operator selection
    @parameters: <mode>: 0 -> auto, 1 -> manual,
                 <format>: 0 -> long alphanum, 1 -> short alphanum, 2 -> numeric,
                 <act>: 0 -> GSM, 2 -> UTRAN, 3 -> GSM W/EGPRS, 4 -> UTRAN W/HSDPA
    @returns: selected operator */
    bool op_select();

    /* Network registration */
    string cs_reg();

    /* Check signal quality
    @Returns Poor sq <= -111 dBm, Avergae -109 dBm < sq < -53 dBm, Good sq >= -51 dBm, Unknown sq = 99
    @AT response format: +CSQ: <rssi>,<ber>
    @Example: +CSQ: 28,0 */
    string signal_quality();

    /* Automatic Timezone Update
    @parameters: <on_off>: 0 -> Disable, 1 -> Enable
    @returns: true if succ, false otherwise */
    bool auto_timezone(int on_off = 0);

    //  Packet Domain Configurations

    /* PS Attach/Detachment
    @parameters: <state>: 0 -> detached, 1 -> attached
    @returns: true if succ, false otherwise */
    bool ps_attachment(int state);

    /* Define PDP context
    @Returns  pdp context
        <cid>,<PDP_type>,<APN>,<PDP_addr>,<data_comp>,<head_comp>[...]
        <cid>: PDP context ID
        <PDP_type>: Packet data protocol type, "IP", "PPP", "IPV6", "IPV4V6"
        <APN>: Access point name, a string parameter that is a logical name that is used to select the GGSN  or  the
        external  packet data network. if null, the subscription value will be requested.
        <PDP_addr>: A string parameter identifies the MT in the address space applicable to the PDP. can be read
        using the +CGPADDR command.
    <data_comp>: Data compression format
    <head_comp>: Header compression format */
    bool pdp_define();

    /* QoS profiles */

    /* Acti/Deactivate PDP context
    @parameters: <state>: 0 -> deactivate, 1 -> activate
                 <cid>: context id
    @returns true if succ, false otherwise */
    bool pdp_activate(int state, int cid);

    /* Network Registration and URC Status
    @parameters: <urc>: 0 -> disabled, 1 -> enabled, 2 -> enabled with location
    @returns: <state>: 0 -> not registered, searching,
                       1 -> registered, home network,
                       2 -> not registered, trying to attach,
                       3 -> registration denied,
                       4 -> registered, roaming
             <lac>: location area code in hex,
             <ci>: cell ID,
             <act>: access technology: 0 -> GSM, 2 -> UTRAN */
    string ps_reg();


    // Switch Modes

    /* Enter data mode using pppd
    @parameters: <file_name>: PPP options file, <port>: Serial port to connect on, <baudrate>: 115200 default
    @returns: messages */
    string to_data(string port, int baudrate);

    /* Enter command mode by killing pppd */
    string to_command();

    // PPP Connection Configurations

    /* Show Modem Staus */
    void print_modem();

    /* Show IP Address
    @returns: IP address of the device */
    string show_ip();

    /* Initialize PPP call
    @parameters: <file_name>: PPP options file, <port>: Serial port to connect on, <baudrate>: 115200 default */
    void ppp_script_ini(string file_name, string port, int baudrate);




// Module's Operation

    /* Initialize modem on startup
    @parameters: <pin>: SIM PIN, <file_name>: PPP settings file, <port>: Modem Serial/USB port to enter Data mode
    @returns: */
    string module_start(string file_name, string port, int baudrate, string pin = "");

    /* Module reconnect on connection failure */

};

#endif
