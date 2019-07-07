# **Quectel U15 module**

## **Objective**

* It's a wireless module that is supposed to work with an embedded 
linux system. Have to study the design and implement the technology.

* Pin definitions
* Configure the module based on API or default values.
* Implement the commands to access and interact with the module.
* Communicate with serial ports.

## **Resources**

### **Quectel UC15 Mini PCIe**

* Dual-mode and multi band for UMTS & GSM.

* HSDPA 3.6 Mbps downlink & 384 Kbps uplink. Global network coverage with HSDPA/WCDMA, 
and fully backwards compatible with existing EDGE and GSM/GPRS networks through multi-band
combination of dual-band WCDMA and GSM.

* 52-pin Mini PCIe package

* USB 2.0 high speed.

* USB drivers

* Quectel enhanced AT commands

* GPRS multi-slot Class 12

* Low power consumption and supports Plug & Play.

* Rich set of internet protocols, industry-standard interfaces (USB/UART/Analog Audio/LED_WWAN), 
and abundant functions (Windows family, Linux and Android).

#### **General Features**

* Frequency Bands: 

    - UMTS/HSDPA --> 900/2100 MHz
  
    - GSM/GPRS/EDGE --> 900/1800 MHz
  
* HSDPA Release 5 (cat6), EDGE downlink only, GPRS Multi-slot Class 12, UMTS Relase 99/5,
GSM Release 99/4

* Supply Voltage Range: 3.0 V ~ 3.6 V, Typ 3.3 V

* Operation Temperature: 

    - Normal operation: -30°C ~ +70°C
    - Restricted operation: -40°C ~ -30°C and +70°C ~ +80°C▲
    - Storage temperature: -45°C ~ +90°C

* Controls via AT commands: 3GPP TS27.007, 27.005, and other enhanced AT commands.

#### **Specifications**

* SMS: Point-to-Point MO and MT, SMS cell broadcast, Text and PDU mode. SMS cell broadcast, SMS storage: ME by default.

* Data: 

    - HDSPA: Max.3.6Mbps
    
    - UMTS: Max.384Kbps (DL)/Max.384Kbps (UL)
    
    - CSD: 64kbps non-transparent. Support Unstructured 
    Supplementary Services Data (USSD).

    - EDGE: Support EDGE multi-slot class 12 (12 by default).
    Support GMSK and 8-PSK for different MCS (Modulation and
    Coding Scheme). Downlink coding schemes: CS 1-4 and MCS 1-9.
    
    - GPRS: Max.85.6Kbps (DL)/Max.85.6Kbps (UL). Coding scheme: 
    CS-1, CS-2, CS-3 and CS-4. Maximum of four Rx time slots 
    per frame.
    
* Voice 

    - Speech Codec Modes: HR, FR, EFR, AMR,AMR-WB
    
    - Echo Arithmetic: Echo Cancellation, Noise Reduction
    
* Protocols: TCP/UDP/PPP/FTP/HTTP/SMTP/MMS/SSL, Support the 
protocols PAP (Password Authentication Protocol) and
CHAP (Challenge Handshake Authentication Protocol) usually used for
PPP connections.

#### **Special Features**

* Drivers:

    - USB Serial: Windows family, Linux and Android
    
    - RIL: Windows CE6.0*, Windows Mobile 6.1/6.5 *
    Android
    
    - MUX: Linux /Android 
    
* Firmware Update: via USB interface

* eCall:  Accident, Emergency Services

#### **Electrical Characteristics**

* Output Power: 

    - Class 3 (24dBm +1/-3dB) for UMTS Bands
    - Class 4 (33dBm ±2dB) for GSM 900MHz 
    - Class 1 (30dBm ±2dB) for GSM 1800MHz
    - Class E2 (27dBm±3dB) for EGSM900 8-PSK
    - Class E2 (26dBm+3/-4dB) for DCS1800 8-PSK

* Consumption: 

    - 5.8mA@Sleep
    - 80mA@Idle, USB active
    - 320mA@GSM voice, max power
    - 600mA@UMTS voice, max power
    - 400mA@GPRS data, max power
    - 520mA@HSDPA, max power

* Sensitivity: 

    - -110dBm@ UMTS Bands
    - -108.5dBm@ GSM 900MHz
    - -108.5dBm@ GSM 1800MHz

#### **Interfaces**

* USB: 2.0 High Speed

* Analog Audio: 

    - Support one differential input and one differential output channel.
    - GSM: HR/FR/EFR/AMR/AMR-WB
    - WCDMA: AMR/AMR-WB
    - Echo cancellation and noise suppression

* PCM Digital Audio:

    - Support 16-bit linear data formats.
    - Support long frame sync and short frame sync.
    - Support master and slave mode, but must be the master in long frame
    - sync.

* UART: 

    - Support seven lines on UART interface.
    - Support RTS and CTS hardware flow control.
    - Baud rate can reach up to 230400 bps, 115200 bps by default.
    - Used for AT command and data transmission.
    - Support multiplexing function.

* USIM: 1.8V/ 3V (USIM hoder)

* LED_WWAN#: Network status indication

* W_DISABLE#: Disable RF function

* PERST#: Reset function

* Antenna: One GSM/UMTS antenna connector.

#### **Certificates**

* Approval: CE/GCF/NCC

#### **[Link to datasheet](https://www.jetone.com.tw/uploadfiles/327/datasheet/Quectel/quectel-wireless-module-uc15_mini_pcie.pdf)**

#### **[UC15 Mini PCIe Hardware Design](http://www.es.co.th/Documents/UC15.PDF)**

### **UART**

* It's a physical circuit in a microcontroller or a stand-alone IC.

* UART adds start and stop bits to the data packet being 
transferred.

* The baud rate between the two endpoints can only differ by about 10% before timing of bits gets too far.

* Each packet contains 1 start bit, 5 to 9 data bits (depending 
on the UART), an optional parity bit, and 1 or 2 stop bits.

* ![Packet Structure](http://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-UART-Packet-Frame-and-Bits-2.png)

* The UART data transmission line is normally held at high voltage
level when it's not transmitting data.

* Data is usually sent starting from the LSB.

* To signal the end of the data packet , the sending UART drives 
the data transmission line from a low voltage to a high voltage 
for at least two bit durations.

### **I2C**

* With I2C, you can connect multiple slaves to a single master
(like SPI), and you can have multiple masters controlling single, 
or multiple slaves. Extremely useful when you want to have more 
than one microcontroller logging data to a single memory card or 
displaying text to a single LCD.

* I2C uses two wires to transmit data.

* Serial Data - SDA: The line for slave and master to send and receive data.

* Serial Clock - SCL: The line that carries the clock signal.

* I2C is synchronous and the clock signal is always controlled by the master.

* With I2C, data is transferred in messages. They're broken into 
frames of data. Each message has an address frame that contains 
the binary address of the sleve, data frames, read/write bits, ACK/NACK bits between each data frame.

* ![Message Structure](http://www.circuitbasics.com/wp-content/uploads/2016/01/Introduction-to-I2C-Message-Frame-and-Bit-2-768x194.png)

* Start condition - The SDA line switches from 

### **Hardware Design Manual**

#### **Operation Modes**

* Normal Operation:

    - Idle 

    - Talk/Data 

* Minimum functionality mode:

    - `AT+CFUN=0` command can set the module entering into a minimum functionality mode without removing the power supply. 

    - In this case both RF and USIM are invalid.

* Sleep mode:

    - Current consumption reduced to minimal.

    - Can still receive paging messages, SMS, voice call and TCP/UDP data.

    - Any URC can be output.

#### **Power Saving**

* Sleep Mode - UART Application

    * Execute AT command `AT+QSCLK=1` to enable the sleep mode.

    * Drive DTR to high level.

    - The RI of module is used to wake up the processor, and AP_READY will detect the sleep state of processor. (High or Low level detection)

    * Drive DTR to low level will wake up the module. 

* Sleep Mode - USB Application with Suspend Function

    * Execute AT command `AT+QSCLK=1` to enable the sleep mode.

    * The processor's USB bus enters into suspend state.

    - When the proessor's USB bus returns to resume state, the module will be woken up.

* Sleep Mode - USB Application without Suspend Function

    - Disconnect USB_VBUS with additional control circuit to let the module enter into sleep mode.

    * Execute AT command `AT+QSCLK=1` to enable the sleep mode.

    * Disconnect USB_VBUS.

    - Supply power to USB_VBUS will wake up the module.

* Minimum Functionality Mode

    - Command `AT+CFUN` provides the choice of the cuntionality levels: `<fun>=0,1,4`.

    * `AT+CFUN=0` Minimum functionality, RF part and USIM card will be closed.

    * `AT+CFUN=1` Full functionality (by default).

    * `AT+CFUN=4` Disable RF function (airplane mode), AT commands of RF are not accessible aswell.

#### **Monitor the Power Supply**

* You can use `AT+CBC` command to monitor the VBAT_BB voltage value.

#### **Turn ON and OFF Scenarios**

* Turn ON Module by PWRKEY Pin

    - It can be turned on by driving the PWRKEY pin to low level at least 0.1s.

    - Recommended to use an open collector driver to control the PWRKEY.

    - The STATUS outputs high level after module is turned on.

    - The other way to control the PWRKEY is to use a button directly. A TVS component is dispensable to be placed nearby the button for ESD protection.

    - Make sure the VBAT is stable before pulling down PWRKEY pin. The time between then is recommended to be more than 0.03s.

* Turn OFF Module

    -  Turn of the module by PWRKEY pin.

    -  Turn off the module by command `AT+QPOWD` 

    -  Automatic shutdown:: Turn off the module automatically if under-voltage or over-voltage is detected.

* Turn OFF Module by PWRKEY Pin

    - Drive the PWRKEY to low level at least 0.6s, the module will execute the prcoedure adter the PWRKEY is released.

    - During power-down, module will send out URC "NORMAL POWER DOWN" via URC port first, then log off network and save important data.

    - After logging off, module sends out "POWERED DOWN" and shuts down the internal power supply. The power on VBAT pins are not allowed to be switched off before this URC is out put to avoid data loss.

    - If module is not logged off within 60s, module will force to shut down internal power supply.

    - In this state, no AT commands can be executed.

* Turn OFF Module by AT Command

    * Using the `AT+QPOWD` command.

* Automatic  Shutdown

    - The module will constantly monitor the voltage applied on the VBAT_BB and the following URCs are presented:

        - `+QIND: "vbatt",-1`      <= 3.5 V

        - `+QIND: "vbatt",1`      >= 4.21 V

        - `+QIND: "vbatt",-2`     < 3.2 V

        - `+QIND: "vbatt",2`     > 4.35 V

        - The uncritical voltage is 3.3 V - 4.3 V, if the voltage goes above 4.35 V or drops below the 3.2 V, the module will automatically shutdown itself.

    - The value of voltage threshold can be revised by AT command `AT+QCFG="vbatt"`.

#### **Reset the Module**

- You can reset the module by driving the RESET_N to low voltage for 0.05 ~ 0.2 s and then releasing.

- The low-level pulse through the RESEST_N pin cannot last for more than 0.2s, otherwise the module will be powered off.

#### **UART Interface**

- The module provides one 7-wire UART interface, and is designed as the DCE.

- It supports 300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800 and 921600bps baud rate. The default is 115200bps.

- The interface can be used for data transmission, AT communication and firmware upgrade.

* Logic Levels of Digital IO

Parameter | Min | Max 
----------|------|-------
VIL | -0.3 | 0.91
VIH | 1.69 | 2.9
VOL | 0 | 0.45
VOH | 2.15 | 2.6

- The module disables the hardware flow control by default. AT command `AT+IFC=2,2` is used to enable hardware flow control. AT command `AT+IFC=0,0` is used to disable the hardware flow control.

* UART Application

- Rising edge on DTR will let the module exit from the data mode by default. It can be disabled by command.

- DCD is used as data mode indication. (`AT&C`, `AT&V`).

* Behavior of  the RI

    * You can use command `AT+QCFG="risignaltype", "physical"` to configure RI behavior.

    - URC will trigger the behavior of RI no matter which port it is presented on.

    - URC can be output from UART port, USB AT port, USB modem port by command `AT+QURCCFG`. The default port is USB AT port.

    - RI behavior can be configured flexible.

    State | Response
    ------|----------
    Idle  | RI keeps in high level
    URC | RI outputs 120ms low pulse when new URC is reported

    -  The RI behavior can be changed by command `AT+OCFG="urc/ri/ring"`.

#### **USIM Card Interface**

- Some AT commands are invalid when USIM card is not applied.

- UC15 supports USIM card hot-plugging via the USIM_PRESENCE pin.

#### **USB Interface**

#### **ADC Function**

- The module provides two ADC to digitize the analog signal to 12-bit signal data. Using AT command `AT+QADC=0` can read the voltage value on ADC0 pin.

- In order to improve the accuracy of ADC, the trace should be surrounded by ground.

Parameter | Min | Typical | Max | Unit
----------|-----|---------|-----|------
ADC Voltage Range | 0 |  | 2.1 | V
Sample Rate | | 2.4 | | MHz
ADC Resolution | | 12 | | bits

#### **Network Status Indication**

Pin Name | Status | Desc
---------|--------|------
NETLIGHT | 200 ms High/1800 ms Low | Network searching
 | 1800 ms High/200 ms Low | Idle
 | 125ms High/125 ms Low | Data transfer is ongoing
 | Always High | Voice calling
 | Always Low | Sleep

#### **Operating Status Indication**

- When the module is turned on normally, the STATUS will output high level.

#### **Power Supply Ratings**

Parameter | Desc | Conditions | Min - Typ. - Max | Unit
----------|------|------------|------------------|------
VBAT | VBAT_BB and VBAT_RF | Voltage must stay within the min/max values, including voltage drops, ripple, and spikes | 3.3 - 3.8 - 4.3 | V
VBAT | Voltage drop during transmitting burst | Maximum power control level on GSM850 and EGSM900 | - - 400 | mV
IVBAT | Peak supply current (during transmission slot) | Maximum power control level on GSM850 and EGSM900 | - 1.8 - 2.0 | A
USB_VBUS | USB detection | 3.0 - 5.0 - 5.25 | V

### **Design Tips**

* When the module cannnot be turned off by PWRKEY pin, or other abnormalities occur, it is suggested to switch off the pwoer supply for module to shut it down, and then power on again.

* USIM Design Notes !!!!
+
### **AT Commands**

#### **Introduction**

* The `AT` prefix must be set at the beginning of each command line.

* To terminate a command line enter `<CR>`.

* Commands are usually followed by a response that includes `<CR><LF><response><CR><LF>`.

* All AT commands can be split into three categories:

    - "basic"
    
    - "S parameter"
    
    - "extendded"   

* Basic syntax

    - `AT<x><n>` or `AT&<x><n>` where `<x>` is the command, and the `<n>` is the argument for that command.

* S paramter syntax

    - `ATS<n>=<m>` where `<n>` is the index of the S register to set, and `<m>` is the valye to assign to it.

* Extended Commands:

Test Command | `AT+<x>=?` | This command returns the list of parameters and value ranges set by the corresponding Write Command or internal processes.
Read Command | `AT+<x>?`| This command returns the currently set value of the parameter or parameters.
Write Command | `AT+<x>=<...>` | This command sets the user-defined parameter values.
Execution Command | `AT+<x>` | This command reads non-variable parameters affected by internal processes in the UE.

* THe UC15 command interface defaults to the "GSM" character set. It supports the following charcter sets:

    - GSM

    - UCS2

    - IRA

* The character set can be configured and interrogated by using the `AT+CSCS` command.

* The character set affects transmission and reception of SMS and SMS cell broadcast messages, the entry and display of the phone book entries text field.

* The UC15 AT command interface includes two USB MODEM and USB AT ports. Both the UART and USB MODEM support AT command and data transfer. The USB AT supports only AT command.

* AT command Interface - UART port

    - The baud rates of 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600, 3200000, 3686400 and 4000000 are supported at present. The default is 115200.

    - The main UART port supports hardware flow control lines RTS and CTS. But it is off by default. AT command `AT+IFC=2,2` is used to enable hardware flow control.

* URC 

    - URC is issued by the UC15 without being requested by the TE and it is issued automatically when a certain event occurs. Typical events leading to URCs are incoming calls ("RING"), received short messages, high/low voltage alarm, high/low temperature alarm.

    - For most of these messages, they will be outputted from USB AT port by default if CMUX function is disabled, and you can configure the interface for URC output by using the AT command `AT+QURCCFG` (This command only effects when CMUX function is disabled).

    - If CMUX function is enabled, URCs will be outputted from CMUX2 port by default. While the interface used for URC output is reserved by an active data connection or a long running AT command, URCs are buffered internally and will be issued after the interface becomes idle status.

* Turn off Procedure

    - It is recommended to execute `AT+QPOWD` command to turn off the module.

    - In order to avoid data loss, it is suggested to wait for 1s to switch off the VBAT after the STATE pin is set as low and the URC "POWERED DOWN" is outputted.

    - If this URC has not been received after 65s, you should force to seitch off the VBAT.

#### **General Commands**

* `ATI` Display Product Identification Information

* `AT+GMI` Request Manufacturer Identification

* `AT+GMM` Request TA Model IDentification

* `AT+GMR` Request TA Revision Identification of Software Release

* `AT+CGMI`  Request Manufacturer Identification

* `AT+CGMM` Request Model Identification

* `AT+GSN` Request International Mobile Equipment Identity (IMEI)

* `AT+CGSN` Request Product Serial Number Identification

* `AT&F` Set all current parameters to manufacturer defaults, does not change the current baudrate of the UARt.

* `AT&V` Display Current Configuration - including the single-letter AT command parameters which are not readable otherwise.

* `AT&W` Store Current Parameters to User Defined Profile -  in non-volatile memory

* `ATZ` Set all Current Parameters to User Defined Profile - does not change the current baudrate of UART.

* `ATQ` Set Result Code Presentation Mode

* `ATV` TA Response Format

* `ATE` Set Command Echo Mode

    - <value>: 0 Echo off, 1 Echo on

* `A/` Repeat Previous Command Line

* `ATS3` Set Command Line Termination Character

    - Read Command: `ATS3?` 

    - Write Command: `ATS3=<n>`

* `ATS4` Set Response Formatting Character

    - Read Command: `ATS4?` 

    - Write Command: `ATS4=<n>`

* `ATS5` Set Response Formatting Character

    - Read Command: `ATS5?` 

    - Write Command: `ATS5=<n>`

* `ATX` Set CONNECT Result Code Format and Monitor Call Progress

<value> | Desc
--------|-------
0 | CONNECT result code only returned, dial tone and busy detection are both disabled.
1 | CONNECT<text> result code only returned, dial tone and busy detection are both disabled.
2 | CONNECT<text> result code only returned, dial tone detection is enabled and busy detection is disabled.
3 | CONNECT<text> result code only returned, dial tone detection is disabled and busy detection is enabled.
4 | CONNECT<text> result code returned, dial tone and busy detection are both enabled.

* `AT+CFUN` Set Phone Functionality - can also be used to reset the UE

    - Test Command `AT+CFUN=?` 

    - Read Command `AT+CFUN?`

    - Write Command `AT+CFUN=<fun>[,<rst>]`


Parameter | Value | Desc
----------|------|-------
<fun> | 0 | Minimum functionality
 | 1 | Full functionality (Default)
 | 4 | Disable phone both transmit and receive RF circuits
<rst> | 0 | Do no nreser the ME before setting it to <fun> power level. This is default when <rst> is not given.
 | 1 | Reset the ME. The device is fully functional after the reset. This value is available only for <fun>=1.

* `AT+CMEE` Erro Message Format

    - Test Command `AT+CMEE=?` 

    - Read Command `AT+CMEE?`

    - Write Command `AT+CMEE=<n>`

Parameter | Value | Desc
----------|-------|-------
<n> | 0 | Disable result code
 | 1 | Enable result code and use numeric value
 | 2 | Enable result code and use verbose values

* `AT+CSCS` Select TE Character Set

    - Test Command `AT+CSCS=?` 

    - Read Command `AT+CSCS?`

    - Write Command `AT+CSCS=<chset>`

Parameter | Value 
----------|-------
<chset> | GSM
 | IRA
 | UCS2

* `AT+QURCCFG` Configure URC indication option - will be saved to NV immediately.

    - Test Command `AT+QURCCFG=?` 

    - Read Command `AT+QURCCFG?`

    - Write Command `AT+QURCCFG="urcport"[,<urcportvalue>]`

Parameter | Value | Desc
----------|-------|-------
<urcportvalue> | usbat | USB AT port
 | usb modem | USB modem port
 | uart1 | Main UART

#### **Serial Interface Control Commands**

* `AT&C` Set DCD Function Mode

    - <value>:  0 DCD line is always ON, 1 DCD line is ON only in the presence of data carrier.

* `AT&D` Set DTR Function Mode

    - <value>: 0 TA ignores status on DTR, 1 ON -> )OFF on DTR: Change to command mode with remaining the connected call, 2 ON -> OFF on DTR: Disconnect data call, change to command mode. During state DTR=OFF, auto-answer is off.

* `AT+ICF` Set TE-TA Control Character Framing

    - Test Command `AT+ICF=?` 

    - Read Command `AT+ICF?`

    - Write Command `AT+ICF=[<format>,[<parity>]`
    
Parameter | Value | Desc
----------|-------|-------
<format> | 3 | 8 data 0 parity 1 stop
<parity> | 0 | Odd
 | 1 | Even 
 | 2 | Mark(1)
 | 3 | Space (0)

- The <parity> field is ignored if the <format> field specifies no parity.

* `AT+IFC` Set TE-TA Local Data Flow Control

    - Test Command `AT+IFC=?` 

    - Read Command `AT+IFC?`

    - Write Command `AT+IFC=<dce_by_dte><dte_by_dce>`

Parameter | Value | Desc
----------|-------|------
<dce_by_dte> | 0 | None
 | 2 | RTS flow control
<dte_by_dce> | 0 | None
 | 2 | CTS flow control

- This flow control is applied for data mode.

* `AT+IPR` Set TE-TA Fixed Local Rate (baudrate)

    - Test Command `AT+IPR=?` 

    - Read Command `AT+IPR?`

    - Write Command `AT+IPR=<rate>`

- The value of `AT+IPR` cannot be restored with `AT&F` and `ATZ`, but it is still storable with `AT&W`.

- In multiplex mode, none of the above command including `AT+IPR` are valid.

- The following sequence of commands can be summarized into `AT+IPR=115200;&W`:

    AT+IPR=115200
    OK
    AT&W
    OK

* `AT+QRIR` Set Ring Line to Inactive

    - Test Command: `AT+QRIR=?`

    - Execution Command: `AT+QRIR`

#### **Status Control COmmands**

* `AT+CPAS` Mobile Equipment Activity Status

    - Test Command: `AT+CPAS=?`

    - Execution Command: `AT+CPAS`

Parameter | Value | Desc 
----------|-------|--------
`<pas` | 0 | Ready
`<pas` | 3 | Ringing
`<pas` | 4 | Call in progress

* `AT+QCFG` Extended Configuration Settings (Page  39)

* `AT+QINDCFG` URC Indication Configuration

    - Test Command: `AT+QINDCFG=?`

    - Read Command: `AT+QINDCFG?`

    - Write Command: `AT+QINDCFG=<urctype[,<enable>[.<savetonvram>]]>`

Parameter | Value | Desc
----------|-------|----------
`<urctype>` | "all" | Main switch of all URCs. Default is on.
`<urctype>` | "csq" | Indication of signal strength and channel bit error rate change. Dfault is off. If this configuration is present: `+QIND: "csq",<rssi><ber>`
`<urctype>` | "smsfull" | SMS storage is full. Default is off. If this configuration is present: `+QIND: "smsfull",<storage>`
`<urctype>` | "ring" | RING indicartion. Default is on.
`<urctype>` | "smsincoming" | Incoming message indication, default is on. Related URCs list: +CMTI, +CMT, +CDS, +CBM.
`<urctype>` | "ccinfo" | INDication of voice call state change, default is off.
`<enable>` | 0 | Off
`<enable>` | 1 | On
`<savetonvram>` | 0 | Not save
`<savetonvram>` | 1 | Save

* `AT+CEER` Extended Error Report

    - Test Command: `AT+CCEER=?`

    - Execution Command: `AT+CEER`

* `AT+QGBAND` Get Module Operation Band

    - Test Command: `AT+QGBAND=?`

    - Execution Command: `AT+QGBAND`

Parameter | Value | Desc
----------|-------|---------
`<currentband>` | 1 | GSM 900
`<currentband>` | 2 | GSM 1800
`<currentband>` | 4 | GSM 850
`<currentband>` | 8 | GSM 1900
`<currentband>` | 16 | WCDMA 2100
`<currentband>` | 32 | WCDMA 1900
`<currentband>` | 64 | WCDMA 850
`<currentband>` | 128 | WCDMA 900
`<currentband>` | 256 | WCDMA 800

#### **SIM Related Commands**

*  `AT+CIMI` Request International Mobile Subscriber Identity (IMSI) - returns a string without double quotes

    - Test Command: `AT+CIMI=?`

    - Execution Command: `AT+CIMI`

* `AT+CLCK` Facility Lock

    - Test Command: `AT+CLCK=?`

    - Execution Command: `ALT+CLCK=<fac>,<mode>,[<passwd>[<class>]]`

    - References on page 69

* `AT+CPIN` Enter PIN

    - Test Command: `AT+CPIN=?`

    - Read Command: `AT+CPIN`

    - Write Command: `AT+CPIN=<pin>[,<new pin>]`

    - References on page 72

* `AT+CPWD` Change Password

    - Test Command: `AT+CPWD=?`

    - Write Command: `AT+CPWD=<fac>,<oldppwd,<newpwd>`

    - References on page 73

* `AT+CSIM` Generic SIM Access

    - Test Command: `AT+CSIM=?`

    - Write Command: `AT+CSIM=<length>,<command>`

    - References on page 75

* `AT+CRSM` Restricted SIM Access

    - Test Command: `AT+CRSM=?`

    - Write Command: `AT+CRSM=<command>[,<filed>[,<P1>,<P2>,<P3>[,<data>][,<pathid>]]]`

    - References on page 75

* `AT+QFUN` Set Phone Extended Functionality

    - Test Command: `AT+QFUN=?`

    - Write Command: `AT+QFUN=<op>`

    Parameter | Value | Desc
    ----------|-------|-------
    `<op>` | 5 | Perform a power down to the SIM card
    `<op>` | 6 | Perform a power up to the SIM card

    - If you want to use `+QFUN` to swap SIM card, there should be some delay of 5s at least between power up and down.

    - It is not recommended to swap SIM cards fleetly or frequently.

* `AT+QINISTAT` Query Status of SIM Card Initialization

    - Test Command: `AT+QINISTAT=?`

    - Write Command: `AT+QINISTAT`

    Parameter | Value | Desc
    ----------|-------|-------
    `<status>` | 0 | initial state
    `<status>` | 1 | CPIN READY. Operation like lock/unlock PIN is allowed.
    `<status>` | 2 | SMS initialization complete
    `<status>` | 3 | Phonebook initialization complete

* `AT+QPIN2` Query/Unlock SIM PIN2/PUK2

    - Test Command: `AT+QPIN=?`

    - Read Command: `AT+QPIN2?`

    - Write Command: `AT+QPIN2=<pin>[,<newpin>]`

    Parameter | Value | Desc
    ----------|-------|------
    `<code>` | READY | MT is not pending for SIM PIN2/PUK2
    `<code>` | SIM PIN2 | MT is waiting SIM PIN2 to be given
    `<code>` | SIM PUK2 | MT is waiting SIM PUK2 to be given
    `<pin>` | Password (String type) | If the requested password is PUK, then `<pin>` must be followed by `<newpin>`.
    `<newpin>` | Password (String type) | If the requested code is PUK.

* `AT+QPINC` Display PIN Remainder Counter

    - Test Command: `AT+QPINC=?`

    - Read Command: `AT+QPINC?`

    - Write Command: `AT+QPINC=<facility>`

    Parameter | Value | Desc
    ----------|-------|-------
    `<facility>` | SC | SIM PIN
    `<facility>` | P2 | SIM PIN2
    `<pincounter>` | number of attempts left to enter the password of PIN.
    `<pukcounter>` | number of attempts left to enter the password of PUK.

* `AT+QSIMDET` SIM Card Detection

    - Test Command: `AT+QSIMDET=?`

    - Read Command: `AT+QSIMDET?`

    - Write Command: `AT+QSIMDET=<enable>,<insert_level>`

    Parameter | Value | Desc
    ----------|-------|-------
    `<enable>` | 0 | off
    `<enable>` | 1 | on
    `<insert_level>` | 0 | Low level
    `<insert_level>` | 1 | High level

* `AT+QSIMSTAT` SIM Inserted Status Report

    - Test Command: `AT+QSIMSTAT=?`

    - Read Command: `AT+QSIMSTAT?`

    - Write Command: `AT+QSIMSTAT=<enable>`

    Parameter | Value | Desc
    ----------|-------|-------
    `<enable>` | 0 | off
    `<enable>` | 1 | on
    `<insert_level>` | 0 | Low level
    `<insert_level>` | 1 | High level
    `<insert_level>` | 2 | Unknown, before SIM initialization

    - References on page 82



### **Glossary**

* **UMTS**: Is a 3G cellular system network based on the GSM standard. 

    - It is a part of the ITU IMT-2000 standard set and compares 
    with CDMA2000 standard set for networks based on competing 
    cdmaOne technology.

    - Uses Wideband CDMA (W-CDMA), radio access technology to offer
    greater spectral efficiency and bandwidth to mobile network 
    operators.

    - It specifies a complete network system, which includes the radio access network - UTRAN, the core network MAP - Mobile 
    Application Part - and the authentication of users via SIM 
    cards.

* **PCM**: Is a digital representation of an audio signal, 

    - I2S is a electrical serial interface used to transmit data 
    from one device to another.

    - It has a line used to deliniate frames called frame clock, a 
    line for maeking individual bits called the bit clock and 1 or 
    more lines for the data.

    - At the start pf each frame clock a PCM sample is serialized 
    bit by bit with a high voltage for a 1 and a zero voltage for 
    0 . This bit is held at that value for the entire duration of 
    a bit clock and then it moves onto the next bit.

* **Unsoliticied Result Code - URC**: Is the message that is sent from
  ME that's not the result of the AT command.

    - Unless you have programmed any of application that deals with the modem directly, you will notice that URC sometimes destroys your parser state machine when it fires in the middle of executing AT command.

    - To fix this issue:

        1- Turn ON the ECHO: this way, you can detect the sequence of the command /URC that's received by the modem. If not enabled, has to be activated via `ATE1` command.

        2- Give delay for each AT command: All AT commands are ended with OK (or ERROR/+CME ERROR/+CMS ERROR).Once you received the string, you need to wait before launching another AT command. This way, the modem guarantees that it will not issue URC while AT command is processed.

        3- Use the special purpose pin: There is a special pin on certain modems that will be pulled low during the URC.  This might be used as the low triggered interrupt for the main MCU/MPU.

* **Low Dropout - LDO**: Is a DC-voltage regulator that can regulate the output voltage even when the supply voltage is very close to the output voltage.

* **Transient Voltage-Suppression diode - TVS**: TVS diodes are constructed with large cross sectional area junctions for absorbing high transient currents. 

    - As a result, the transient current is diverted away from the protected components and shunted through the TVS diode. 

    - The voltage across the protected circuit is limited to the clamping voltage of the TVS diode.

* **Hayes-compatible Modems**: These modems are named after the Hayes smartmodem, and any modem that complies with AT commands is called Hayes-compatible.

    - AT is used since the command try to  grab the modem\s "attention".

    - The DCE components are controlled by the DTE equipments.

    - Outband Signaling is known as the technique used in most RS232 modems, which would be using separate Rx and Tx lines and different control lines. 

    - Inbound signaling is used in Hayes-compatible modems, and it uses same Rx, Tx lines to transmit control signals over the lines as well.

    - It requires for both enpoints to be synced together since, if that's not the case, either data will be lost or interpreted as commands.

    - Some virtual ports are used recently to separate the control signals from data lines.

    - Modems have multiple states:

        * Command State: While in this mode, modem interprets all the input as commands, it can still be connected to a third party.

        * On-line State: In this state, data is interpreted as payload and it requires a remote connection to another 3rd party to forward the data.

        * Originating Mode: Setting up a connection by calling or initiating the protocols.

        * Answer Mode: Waiting to be contacted.

    - Modems are supposed to send responses to all commands, which can be in either ASCII, numeriacal or string. These responses have to be revised with great care and should be parsed and look for interesting data or keywords, as it can notify the DTE on connection states.

    - The S-registers are permanent storages that store various settings. Data can be saved either using AT commands or directly through S-registers.

    -  
    `

