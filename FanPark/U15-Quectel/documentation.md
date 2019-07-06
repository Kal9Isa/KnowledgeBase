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

