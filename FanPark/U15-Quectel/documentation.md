# **Quectel U15 module**

## **Objective**

* It's a wireless module that is supposed to work with an embedded 
linux system. Have to study the design and implement the technology.

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

### **Glossary**

* UMTS: Is a 3G cellular system network based on the GSM standard. 

    - It is a part of the ITU IMT-2000 standard set and compares 
    with CDMA2000 standard set for networks based on competing 
    cdmaOne technology.

    - Uses Wideband CDMA (W-CDMA), radio access technology to offer
    greater spectral efficiency and bandwidth to mobile network 
    operators.

    - It specifies a complete network system, which includes the radio 
    access network - UTRAN, the core network MAP - Mobile 
    Application Part - and the authentication of users via SIM 
    cards.
