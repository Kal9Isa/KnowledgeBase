# **Networking IoT**

## **Introduction**

* By the end of module 3 you will be able to:

    * Describe how information/data travels through an IoT network.

    * List the components of a basic network and their properties.

    * Describe the types of connections in IoT networks.

    * Understand the role of internet protocols, and describe how 
    their various properties make them suited to deifferent types 
    of IoT project.

## **Gateways and Routing**

* Message in a Network

    * ![](http://www.ciscopress.com/articles/article.asp?p=2180208&seqNum=5)

    * This simple network has several key components:

        - Devices: include the computers, printers, routers and servers.

        - Media: include the cabling or wireless connections.

        - Services: includes the software that support operations such as hosting.

    * IoT adds many more devices and services to a network.

* Gateways and Routing

    * Communication in the network is carried by a medium - currently means either
    cable or the air.

    * The different media have different characteristics, which makes each better
      suited to different circumstances, taking into consideration factors such as:

        - the Distance a signal needs to travel.

        - the Enviornment it is travelling in.

        - the Amount and Speed of the data

        - the Cost of the media and its installation.

    * Types of Media:

        * Metallic wires => Transfers data in electrical signals that match specific patterns.

        * Glass or plastic fiber cables => Transfers data in pulses of light either infrared or visible light range.

        * Wireless transmission => Transfers data in patterns of electromagnetic waves.

* Trace the Route

    * Sending a `tracert` or `traceroute` command to trace the route of a website request sill show you the route in 
    detail - you will see all the different routers and networks that the request travels through (up to maximum of 
    30) and finally the destination site with its IP address.

## **Protocols and Standards**

* Internet Protocols (IP addresses)

    * End devices are those that provide a way for user to interact with the network.

    * End devices are either the source or destination of data going over the network.

    * Every device has a unique IP address so it is distinguishable from all other devices. When sending a message, 
    the IP address of the destination is used to specify where the message is being sent.

    * Intermediary devices interconnect end devices, host to the network and network to other networks. They also
    manage the data through the network, they act like post master.

    * These devices take the destination host address and combine that with information about the network 
    connectedness to decide on the path that message takes through the network. Therefore they need to maintain
    network information (frequently update the network map) and may also notify other devices of errors. This 
    allows them to choose alternative pathways, or retransmit data or even deny the flow of data based on security
    settings.

    * IPv4 Consists of four sets of numbers separated by periods, and each number is between 0 to 255.

    * IPv6 is being developed using six sets of numbers, colons, and hexadecimal numbering to allow many more
    destination addresses. This will help IoT as well as adding features for improved routing, security and data flow.

    * IPv6 has around 340 undecillion IP addresses: 340 * 10 ^ 36.

* IP address lookup

    * Using `nslookup` command you can see the IP address of the desired website.

* Domain Name Servers (DNS)

    * DNS is the internet equivalent of a telephone book. It's a large database of computer names and their internet
    addresses, but it is spread out so that no server has all the information.

    * If a computer requests a domain name and that server doesn't have it, it forwards the request to another DNS
    server. The Domain name system has a hierarchical structure, so requests get sent from the bottom up.

    * ![](https://technet.microsoft.com/en-us/library/2005.01.howitworksdns.aspx)

    * When setting up an internet connection on a computer, it is usual to allocate a primary DNS server and one or 
    more secondary servers. This information is generally provided by your ISP.

* Playing at Protocols

    * Having agreed protocols that operate at a set standard allows for computers on different sides of the world to
    communicate with each other.

    * A Protocol is an agreed (or accepted) set of rules for a procedure.

## **IoT Connecting**

* IoT connecitng
    
    * Currently use of 4G and Ethernet is common in IoT.

    * However new protocols such as LoRaWAN are being developed. LoRa stands for Long Range Radio. It is a wireless
    technology trageting M2M and IoT networks. This technology will enable public or multitenated networks to connect
    multiple applications running in the same network.

    * LoRaWAN could be used with LoRa sensors and automated products and applications.

    * LoRa is a type of NarrowBand RF technology. They operate over long distances and at lower power levels, but their
    trade off is that they only offer smaller bandwidth connectivity, limiting their use to restricted data and 
    bandwidth applications. like alarm systems, critical sensor arrays and many M2M applications.

    * Main advantage of NarrowBand RF is that they are low cost to set up and operate, and the devices that they support
    use minimal power. This means they can be operated in an autonomous manner for longer periods.

    * Examples of NarrowBand RF are SIGFOX (Ultra NarrowBand), NB-IoT (NarrowBand IoT).

* Case Study: Networking Devices

    * Dairy Farm

        - All the responders transmit data to the antenna thus the server up to 1 km.

        - Lower power in sensors (battery life of 5 years)

        - RFID on cow entering/leaving dairy.

        - Protocol: UHF

    * Foot drop/gait analysis

        - Lightweight devices (low power but rechargable)

        - Range in home or clinic situation.

        - Protocol: RF, could use PAN or Bluetooth

    * Autonomous Bus

        - Mobile device

        - Safety and security critical

        - Protocol: Wired, 3G, 4G (LTE), GPS, RF, Wi-Fi

    * Sydney Harbour Bridge

        - Large structure

        - 3200 sensors

        - Protocol: Fiber optics/ Ethernet

    * Various Curtin University Projects

        - 5 Km range

        - Limited power to devices

        - Limited data

        - Protocol: Wireless/ LoRaWAN

    * Rotating Machines Monitoring

        - Various situations, some of them remote or difficult to access.

        - Low range and long range

        - Protocol: Bluetooth, WiFi, Bluetooth Low Energy, LoRa, Zigbee

* Pick your IoT Connection Type

    * The majority of IoT cases require wireless conenction, and there are many aspects
      to consider when choosing a protocol:

        * Is the connection over a very short distance, or might it be citywide?

        * What is the volume of data being sent? Is it huge or small?

        * Is the speed and frequency fast and contionous (with the benefit of real-time
        information) or only occasional?

    * 11 IoT Protocols you need to know about

        * Depending on the application, factors such as range, data requirements, security,
        and power demands and battery life will dictate the choice of one or some form of 
        combination of technologies.

        * Bluetooth

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/5534ffdacf0c4fcb821a72bc0ab56371bluetooth.jpg)

            * It is expected to be key for wearable products in particular, again connecting 
            to the IoT albeit probably via a smartphone in many cases.

            * The new BLE or Smart Bluetooth offers similar range to Bluetooth but it has been 
            designed to offer significantly reduced power consumption.

            * It's more useful for small chuncks of data.

            * Bluetooth Smart feature is included in version 4.0 or higher (latest is 4.2) with a
            combined basic data-rate and low-energy core configuration for a RF transceiver, 
            baseband and protocol stack. Importantly version 4.2 via its Internet Protocol 
            Support Profile will allow Bluetooth Smart sensors to access the Internet directly 
            via 6LowPAN connectivity. This will make it possible to use existing IP infrastructure
            to manage Bluetooth Smart edge devices.

            * Specifications:

                - Standard: Bluetooth 4.2 core specification

                - Frequency: 2.4 GHz (ISM)

                - Range: 50 - 150 m (Smart/BLE)

                - Data Rates: 1 Mbps (Smart/BLE)

        * Zigbee

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/55350099dff044218bce24e00ab544b9zigbee_logo.jpg)

            * ZigBee PRO and ZigBee Remote Control (RF4CE), among other profiles are based on the 
            IEEE802.15.4 protocol, which is an industry-standard wireless networking technology
            operating at 2.4 GHz targeting applications that require relatively infrequent data 
            exchanges at low data-rates over a restricted area and within a 100 m range.

            * It offers low-power operation, high security, robustness and high scalability with
            high node counts and is well positioned to take advantage of wireless control and sensor
            networks in M2M and IoT applications.

            * Specifications:

                - Standard: ZigBee 3.0 based on IEEE802.15.4

                - Frequency: 2.4 GHz 

                - Range: 10 - 100 m 

                - Data Rates: 250 kbps

        * Z-Wave

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/55350145125045fe86fa33170ab56371zwave_logo.jpg)

            * Z-Wave is a low-power RF communications technology that is primarily designed for home 
            automation for products such as lamp controllers and sensors among many others. Optimized 
            for reliable and low-latency communication of small data packets with data rates up to 
            100kbit/s, it operates in the sub-1GHz band and is impervious to interference from WiFi 
            and other wireless technologies in the 2.4-GHz range such as Bluetooth or ZigBee.

            * It supports full mesh networks without the need for a coordinator node and is very scalable, 
            enabling control of up to 232 devices. Z-Wave uses a simpler protocol than some others, which 
            can enable faster and simpler development, but the only maker of chips is Sigma Designs.


            * Specifications:

                - Standard: Z-Wave Alliance ZAD12837 / ITU-T G.9959

                - Frequency: 900 MHz (ISM)

                - Range: 30 m

                - Data Rates: 9.6/40/100 kbps

        * 6LowPAN

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/553509fee7bc4f64aad139790ab563716lowpan.jpg)

            * A key IP based technology is IPv6 Low-power wireless Personal Area Network (6LowPAN) is a network
            protocol that defines encapsulation and header compression mechanisms. 

            * The standard has the freedom of frequency band and physical layer and can also be used across 
            multiple communications platforms, including Ethernet, WiFi, 802.15.4 and sub-1 GHz ISM.

            * IPv6 provides a basic transport mechanism to produce complex control systems and to communicate with
            devices in a cost-effective manner via a low-power wireless network.

            * Designed to send IPv6 packets over IEEE802.15.4-based networks and implementing open IP standards
            including TCP, UDP, HTTP, COAP, MQTT, and websockets, the standard offers end-to-end addressable nodes,
            allowing a router to connect the network to IP. 

            * It's a mesh network that is robust, scalable and self-healing. Mesh router devices can route data 
            destined for other devices, while hosts are able to sleep for long periods pf time.

            * Specifications:

                - Standard: RFC6282

                - Frequency: (adapted and used over a variety of other networking media including Bluetooth Smart 
                (2.4GHz) or ZigBee or low-power RF (sub-1GHz)

                - Range: N/A

                - Data Rates: N/A

        * Thread

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/553502cce0b44b78886e27250ab544b9thread.jpg)

            * A new IP based IPv6 networking protocol aimed at home automation.

            * It is based on various standards including IEEE802.15.4 (as the wireless air-interface protocol), 
            IPv6 and 6LoWPAN, and offers a resilient IP-based solution for the IoT. Designed to work on existing 
            IEEE802.15.4 wireless silicon from chip vendors such as Freescale and Silicon Labs, Thread supports 
            a mesh network using IEEE802.15.4 radio transceivers and is capable of handling up to 250 nodes with 
            high levels of authentication and encryption.

            * Specifications:

                - Standard: Thread, based on IEEE802.15.4 and 6LowPAN

                - Frequency: 2.4 GHz (ISM)

                - Range: N/A

                - Data Rates: N/A

        * WiFi

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/5535036288484c99b4b13f4e0ab544b9wifi_logo.jpg)

            * Currently, the most common WiFi standard used in homes and many businesses is 802.11n, which offers 
            serious throughput in the range of hundreds of megabit per second, which is fine for file transfers, 
            but may be too power-consuming for many IoT applications.

            * Specifications:

                - Standard: Based on 802.11n (most common usage in homes today)

                - Frequency: 2.4 GHz and 5 GHz bands

                - Range: Approximately 50 m

                - Data Rates: 600 Mbps maximum, but 150-200Mbps is more typical, depending on channel frequency 
                used and number of antennas (latest 802.11-ac standard should offer 500Mbps to 1Gbps) 

        * Cellular

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/553503f4b2884789a7f650f30ab544b9cellular.jpg)

            * Any IoT application that requires operation over longer distances can take advantage of GSM/3G/4G cellular 
            communication capabilities. While cellular is clearly capable of sending high quantities of data, especially 
            for 4G, the expense and also power consumption will be too high for many applications, but it can be ideal 
            for sensor-based low-bandwidth-data projects that will send very low amounts of data over the Internet. A 
            key product in this area is the SparqEE range of products, including the original tiny CELLv1.0 low-cost 
            development board and a series of shield connecting boards for use with the Raspberry Pi and Arduino platforms. 

            * Specifications:

                - Standard: GSM/GPRS/EDGE (2G), UMTS/HSPA (3G), LTE (4G)

                - Frequency: 900/1800/1900/2100 MHz

                - Range: 35 km max for GSM; 200 km max for HSPA

                - Data Rates: (typical download): 35-170 kbps (GPRS), 120-384 kbps (EDGE), 384 Kbps-2 Mbps (UMTS), 
                600 kbps-10 Mbps (HSPA), 3-10 Mbps (LTE) 

        * NFC

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/553507572f144f7a94a650f30ab544b9nfc_logo.jpg)

            * NFC (Near Field Communication) is a technology that enables simple and safe two-way interactions between 
            electronic devices, and especially applicable for smartphones, allowing consumers to perform contactless 
            payment transactions, access digital content and connect electronic devices. Essentially it extends the 
            capability of contactless card technology and enables devices to share information at a distance that is 
            less than 4cm.

            * Specifications:

                - Standard: ISO/IEC 18000-3

                - Frequency: 13.56MHz (ISM)

                - Range: 10cm

                - Data Rates: 100–420kbps

        * Sigfox

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/553504867f4c4b5e892d24e30ab544b9sigfox_logo.jpg)

            * An alternative wide-range technology is Sigfox, which in terms of range comes between WiFi and cellular. 
            It uses the ISM bands, which are free to use without the need to acquire licenses, to transmit data over 
            a very narrow spectrum to and from connected objects.

            * Sigfox uses a technology called Ultra Narrow Band (UNB) and is only designed to handle low data-transfer 
            speeds of 10 to 1,000 bits per second. It consumes only 50 microwatts compared to 5000 microwatts for 
            cellular communication, or can deliver a typical stand-by time 20 years with a 2.5Ah battery while it is 
            only 0.2 years for cellular. 

            * The network offers a robust, power-efficient and scalable network that can communicate with millions of 
            battery-operated devices across areas of several square kilometres, making it suitable for various M2M 
            applications that are expected to include smart meters, patient monitors, security devices, street lighting 
            and environmental sensors.

            * The Sigfox system uses silicon such as the EZRadioPro wireless transceivers from Silicon Labs, which deliver 
            industry-leading wireless performance, extended range and ultra-low power consumption for wireless networking 
            applications operating in the sub-1GHz band. 

            * Specifications:

                - Standard: Sigfox

                - Frequency: 900 MHz (ISM)

                - Range: 30-50km (rural environments), 3-10km (urban environments)

                - Data Rates: 10 - 1 kbps   

        * Neul

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/5535052d66344641942b325d0ab56371neul_logo.jpg)

            * Similar in concept to Sigfox and operating in the sub-1GHz band, Neul leverages very small slices of the 
            TV White Space spectrum to deliver high scalability, high coverage, low power and low-cost wireless networks. 

            * Systems are based on the Iceni chip, which communicates using the white space radio to access the high-quality 
            UHF spectrum, now available due to the analogue to digital TV transition.

            * The communications technology is called Weightless, which is a new wide-area wireless networking technology 
            designed for the IoT that largely competes against existing GPRS, 3G, CDMA and LTE WAN solutions. Data rates 
            can be anything from a few bits per second up to 100kbps over the same single link; and devices can consume as 
            little as 20 to 30mA from 2xAA batteries, meaning 10 to 15 years in the field. 
        
            * Specifications:

                - Standard: Neul

                - Frequency: 900MHz (ISM), 458MHz (UK), 470-790MHz (White Space)

                - Range: 10km

                - Data Rates: Few bps up to 100kbps

        * LoRaWAN

            * ![](https://www.rs-online.com/designspark/rel-assets/ds-assets/uploads/images/55350679f99044c1865f32880ab56371lora_logo.jpg)

            * Again, similar in some respects to Sigfox and Neul, LoRaWAN targets wide-area network (WAN) applications and 
            is designed to provide low-power WANs with features specifically needed to support low-cost mobile secure bi-directional 
            communication in IoT, M2M and smart city and industrial applications. Optimized for low-power consumption and supporting 
            large networks with millions and millions of devices, data rates range from 0.3 kbps to 50 kbps. 


            * Specifications:

                - Standard: LoRaWAN
                - Frequency: Various

                - Range: 2-5km (urban environment), 15km (suburban environment)

                - Data Rates: 0.3-50 kbps

        * Classification:

            * Long Range (km)/High data rate (mbps): Cellular/4G

            * Long Range (km)/Low data rate (bps-kbps): LoRaWAN, SigFox, Neul

            * Medium Range (m)/Medium data rate (kbps): ZigBee, Zwave, BT, BLE

            * Medium Range (m)/High data rate (mbps): WiFi

            * Short Range (cm)/Medium data rate (kbps): NFC

    