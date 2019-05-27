# **Connecting to the Internet**

## **POTS and Dial-up**

* Dial-up, Modems and Point-to-Point Protocols

    * Public Switched Telephone Network (PSTN) is also referred to as POTS -
    Plain Old Telephone Service.

        - USENET was made by two Duke graduates in late 1970s.

        - A dial-up connection uses POTS for data transfer and the connection is
        actually established by dialing a phone number.

        - Modem: Was used to transfer data on dial-up connections. It stands for
        Modulator/Demodulator which take digital data and turn it into analog
        audible wavelength that could be transmitted over POTS.

        - Baud Rate: A measurement of how many bits can be passed across a phone
        line in a second. By the late 50s this was 110 bps, by the time of USENET
        it was around 300 bps. In early 1990s it increased to 14.4 Kbps.

## **Broadband Connection**

* What is Broadband?

    * Broadband: Any connectivity technology that isn't dial-up Internet.

    * T-carrier technologies: Originally invented by AT&T in order to transmit
    multiple phone calls over a single link.

        - These technologies require dedicated lines that makes them an expensive
        option.

* T-carrier technologies

    * Each individual phone call was made over individual pairs of copper wire.

    * Then Transmission System 1 or T1 was introduced that allowed to carry up to
    24 simultaneous phone calls across a single piece of twisted pair copper. Years
    later it was modified to allow for data transfers, so each of the 24 lines could
    carry data at 64 kbps which makes a single T1 line capable of 1.544 Mbps.

        - Originally T1 was used to connect telecom companies together.

    * Later T3 was introduced, that consisted of 28 T1s all multiplexed acheiving
    a total throughput of 44.736 Mbps.

* Digital Subscriber Lines

    * By operating at a frequency range different from phone calls, DSL was able
    to send much more data across the wire than traditional dial-up technologies.

        - DSL modems are called DSLAMs -Digital Subscriber Line Access Multiplexers-
        unlike modems, they establish long-running connections.

        - ADSL -Asynchronous Digital Subscriber Line- offers a greater download
        speed than upload speed which makes it efficient for home users.

        - SDSL -Synchronous Digital Subscriber Line- caps both download and upload
        speed at 1.544 Mbps.

        - HDSL -High Bit-rate Digital Subscriber Line-Increases the maximum speed
        offered by DSL lines and it's the most common in use today.

* Cable Broadband

    * Originally all television broadcasts were wireless transmission sent out by
    television towers and received by smaller antennas.

    * By using frequencies that don't interfere with television broadcast, cable-
    based Internet access technologies were able to deliver high speed Internet
    across the coaxial cables.

        - This technology uses shared bandwidth.

        - With technologies like DSL or dial-up, connections from clients would
         go directly to Central Office or CO. These technologies can guarantee a
         certain amount of bandwidth available over that connection, since it's
         point-to-point. However on cable Internet technologies, many users share
         a certain amount of bandwidth until the transmissions reach the ISP's
         core network.

         - Cable connections are usually managed by what's known as a cable modem.
         This is a device that sits at the edge of a consumer's network and connects
         it to the CMTS.

         - Cable Modem Termination System (CMTS): Connects lots of different cable
         connections to an ISP core network.

* Fiber Connections

    * FTTX - Fiber To The X is the general idea of using fiber connections for
    communications.

        - FTTN - Fiber To The Neighborhood: Used to deliver data to a single
        physical cabinet that serves a certain amount of population. From this
        cabinet, copper twisted pair or coax might be used for the last length of
        distance.

        - FTTB - Fiber To The Building: This is generally where cables to buildings
        physically enter. Used for data delivery to an individual building. After
        that twisted pair copper is used to actually connect those inside of the
        building.

        - FTTH - Fiber To The Home: Used in instances where fiber actually runs to
        each individual resident in a neighborhood or apartment building.

        * FTTH and FTTB may both refer to FTTP -Fiber To The Premises.

        - The demarcation point for fiber technologies is ONT.

        - Optical Network Terminator (ONT): Converts data from Protocols the fiber
        network can understand, to those that more traditional, twisted pair copper
        networks can understand.

* Broadband Protocols

    * The two primary Protocols that operate on Data Link layer are:

        - PPP: Point-To-Point Protocol

            * Used to establish a direct connection between two nodes, routers
            without any other networking device in between and is capable of
            connection authentication, transmission encryption and compression.

            * Two derivatives of PPP are PPPoE and PPPoA (Point-To-Point over ATM)

        - PPPoE: Point-To-Point over Ethernet

            * It is a network Protocol to encapsulate PPP frames into Ethernet
            frames.

            * Typical use of PPPoE involves leveraging the PPP facilities for
            authenticating user with username and password, predominantly via
            the PAP Protocol and less often via CHAP.

            * PPPoE is available as an informational RFC 2516.

            * PPPoE has two stages:

                1- PPPoE Discovery: This stage exchanges the MAC address of two
                nodes trying to connect to each other. In addition, establishes
                a session ID that can later be used to exchange packets.

                2- PPP Session: Once the MAC address of the peer is known and the
                session has been established , the session stage will start.

            * PPPoE Discovery: consists of 4 stages between the host computer and
            the access concentrator at the ISP's end. The fifth step is a way to
            close a session.

                - C -> S, Initiation (PADI - PPPoE Active Discovery Initiation):
                The computer first must find the DSL access concentrator (DSL-AC) at
                the user's ISP's Point of Presence (POP). So the computer sends a PADI
                packet via an Ethernet broadcast (FF:FF:FF:FF:FF:FF) which contains the
                source MAC address. This packet can be received by many DSL-ACs but only
                the one that can server the "Service-Name" Tag should respond.

                - S -> C, Offer (PADO): Once PADI received, a PADO containing the
                MAC address of the DSL-AC, its name  and the name of the service is
                sent back to client. If more than one DSL-AC respond, the client will
                select the particular POP using the supplied name or service.

                - C -> S, Request (PADR): A PADR packet is sent by the user's client
                to the DSL-AC following receipt of an acceptable PADO packet from the
                DSL-AC. It confirms acceptance of the offer of a PPPoE connection
                made by the DSL-AC issuing the PADO packet.

                - S -> C, Session-Confirmation (PADS): A PADS is sent to confirm the
                PADR and a session ID is given out with it. The connection with the
                DSL-AC for that POP has now been fully established.

                - Either end, Termination (PADT): This packet terminates the connection
                to the POP.

        - PPPoA - Point-to-Point over ATM: Used to connect domestic broadband modems
        to ISPs via phone lines.

            - Mainly used with DOCSIS and DSL carriers, by encapsulating
            PPP frames in ATM AAL5.

            - It's addressed by RFC 2364.

            - It offers standard features of PPP, and also supports (as does PPPoE) the
            encapsulation types: VC-MUX and LLC.

            - Configuration of PPPoA requires:

                - PPP configuration:

                    - User credentials

                    - Username and Password, which is unique to each user.

                - ATM configuration:

                    - Virtual Channel Link (VCL) - Virtual Path Identifier &
                    Virtual Channel Identifier (VPI/VCI) such as 0/32 (analogous
                    to phone number).

                    - Modulation type such as G.dmt

                    - Multiplexing Method: such as VC-MUX or LLC

    * Logical Link Layer (LLC): Is a sublayer of DLL (Data Link Layer) and interfaces
    with Network layer.

        - It provides multiplexing mechanisms to allow for multiple network Protocols
        to coexist within a multipoint network and to be transported over the same
        network medium. It can also provide Flow control and Automatic Repeat Request (ARQ)
        error management mechanisms.

## **WANs**

* Wide Area Network Technologies

    * WAN: Acts like a single network, but spans across multiple physical locations.

        - It usually requires to contract a link with the ISP so they handle the
        data being sent across physical locations.

        - The area between each demarcation point and the ISP's actual core network
        is called a local loop.

* WAN Protocols

    * Frame Relay: Is a standardized WAN technology that specifies the physical and
    DLL layers of telecommunications channels using a packet switching methodology.

        - The frame relay network handles the transmission over a frequently changing
        path transparent to all end-user extensively used WAN protocols.

        - With the advent of Fiber optics, MPLS, VPN and dedicated broadband, the end
        may loom for frame relay protocol.

        - Two types of circuits exist:

            - Permanent Virtual Circuits (PVCs): Which are used to form logical end-to
            -end links mapped over a physical network.

            - Switched Virtual Circuits (SVCs): Analogous to the circuit-switching
            concepts of the PSTN.

    * High-Level Data Link Control (HDLC): Is a bit-oriented code-transparent synchronous
    DLL protocol developed by ISO under ISO/IEC 13239:2002.

        - Provides both connection-oriented and connectionless services.

        - Mostly used to connect one device to another using Asynchronous Balanced Mode
        (ABM).

        - Structure:

            - Flag (8 bits)| Address (8 or more) | Control (8 or 16) | Information (variable length 8xn) | FCS (16 or 32) | Flag (8)

            - Frame Check Sequence is a 16-bit CRC-CCITT or 32-bit CRC-32 computed
            over the Address, Control and Information fields.

        - Three fundamental HDLC frame types:

            - Information frame or I-frame: transport user data from the network layer.
            They can also include flow and error control information piggybacked on the
            data.

            - Supervisory frame or S-frame: Used for flow and error control whenevr
            piggybacking is impossible or inappropriate such as when a station does
            not have a data to send. These frames don't have information fields.

            - Unnumbered frame or U-frame: Are used for various miscellaneous purposes,
            including link management. Some contain information field.

    * Asynchronous Transfer Mode (ATM): A telecommunication concept defined by ANSI
    and CCITT standards for carriage of a complete range of user traffic.

        - It was designed for networks that must handle both high-throughput data traffic
        and real-time, low-latency content.

        - ATM is a core protocol used over the SONET/SDH backbone of PSTN and ISDN, but
         it's use is declining in favor of All IP (Next Generation Network (NSN)).

        - Provides functionality similar to both packet switching and circuit switching
        networks, It uses Asynchronous time-division multiplexing and encodes data
        into small fixed size packets (ISO-OSI frames) called cells. This differs from
        the approach of Ethernet and IP that use variable packet size.

* Point-to-Point VPNs

    * An alternate to WAN technologies.

    * WAN technologies not needed anymore since most companies outsource their
    infrastructure to cloud providers. So they can ensure site-to-site connectivity
    using VPN tunnels.

    * Also called a Site-to-Site VPN, establishes a tunnel between two sites.

## **Wireless Networking**

* Introduction to Wireless Networking

    * Wireless Networking: A way to network without wires.

    * The IEEE 802.11 standards family is known as WiFi technologies.

    * These technologies use radio waves as carriers.

    * Frequency Band: A certain section of the radio spectrum that's been agreed upon
    to be used for certain communications.

        - In North America, FM radio transmissions operate between 88 and 108 MHz,
        called the FM Broadcast Band.

    * Wi-Fi usually operates on 2.4 GHz and 5 GHz bands.

    * Most common Wi-Fi specifications are:

        - 802.11b -> 2.4 GHz, 22 MHz bandwidth, Modulation: OFDM/OFDM (PHY/DLL)

        - 802.11a -> 5 GHz, 5/10/20 MHz, OFDM/OFDM

        - 802.11g -> 2.4 GHz, 5/10/20 MHz, ERP-OFDM/OFDM

        - 802.11n -> 2.4/5 GHz, 20/40 MHz, HT-OFDM/MIMO-OFDM

        - 802.11ac -> 5 GHz, 20/40/80/160 MHz, VHT-OFDM/MIMO-OFDM

        * These specifications have been improved upon either increasing their speed
        or the amount of simultaneous devices they can serve.

    * 802.11 = Physical and Data link layers.

    * 802.11 Frame:

        - Frame Control (16 bits)| Duration/ID (16)| Address 1 (48)| Address 2 (48)| Address 3 (48)| Sequence Control (16)| Address 4 (48)| Data Payload (0-7951)| FCS (32)

        - Frame Control field: 16-bits long and contains an number of sub-fields that
        are used to describe how the frame itself should be processed. Including
        what version of 802.11 was used.

        - Duration field: Specifies how long the total frame is.

        - Address 1: Represents the MAC address of the source device.

        - Address 2: Intended destination on the network.

        - Address 3: Receiving address. Would be the MAC address of the access point
        that should receive the frame.

        - Address 4: Transmitter address. Would be the MAC address of whatever has
        just transmitted the frame.

        - Sequence Control field: 2 bytes long and mainly contains a sequence number
        used to keep track of ordering the frames.

        - Data Payload: Which has all the data of the protocols further up the stack.

        - Frame Check Sequence field: Which contains a checksum used for cyclical
        redundancy check (CRC).

    * Wireless Access Point: A device that bridges the wireless and wired portion
    of a network.

* Alphabet Soup

    * The many different specifications of 802.11 family, all operate with the
    same basic data link protocol. But, how they operate at the physical layer
    varies. Each can have different ranges, can use different modulation techniques,
    can have different transmission bit rates, operate on different frequency bands, etc.

    * Networks that operate on 5 GHz band are almost always faster, but have less
    of a range. Most of the 2.4 GHz networks are slightly slower and more susceptible
    to interference, but usually cover a larger area.

* Wireless Network Configurations

    * Different ways that wireless networks can be configured:

        - Ad-hoc Network: Where all nodes speak directly to each other.

            - Simplest type without any supporting network infrastructure.

            - All nodes help pass along messages.

            - Used for personal sharing or within industrial settings where nodes
            need to directly communicate with each other.

            - Powerful tools to use during disaster.

        - Wireless LAN - WLAN: Where one or more access points act as a bridge
        between a wireless and a wired network.

            - Most common in business settings.

        - Mesh Network: Which are a hybrid of two.

* Wireless Channels

    * Channels: Individual, smaller sections of overall frequency band used by the
    wireless network.

        - They can help address collision domains which are anyone network segments
        where one computer can interrupt another.

        - This issue has been fixed on wired connections using switches, since they
        remember which computer is on which physical interface, so traffic is only
        sent to the node that its intended for.

        - Wi-Fi operates on 2.4 - 2.5 GHz band, meaning there are a lot of channels
        with their own bandwidth in the middle. Exactly how many channels can be
        used differs from region to region.

        - Since radio waves are imprecise, there has to be a buffer around the
        expected bandwidth.

        - Todays networking devices can sense congestion on these channels, some
        devices assess this at their startup and some dynamically change their
        channel as needed.

* Wireless Security

    * WEP - Wired Equivalent Privacy: An encryption technology that provides a
    very low level of privacy.

        - 40-bit long keys.

    * The more bits in an encryption key, the more it takes for someone to crack
    the encryption.

    * WPA - WiFi Protected Access

        - Uses a 128-bit key by default.

    * WPA2

        - Uses a 256-bit key.

    * Through MAC filtering, networks can be secured even more.

    * MAC Filtering: To configure the access point to only allow for connections
    form a specific set of MAC addresses belonging to the trusted devices.

* Cellular Networking

    * They have a lot in common with 802.11.

    * Use specific frequency bands reserved for cellular transmissions. These
    can travel over longer distances than WiFi.

    * Each cell is assigned a specific frequency band to use.

* Summary

    * The rate at which a dial-up connection can send data across a telephone wire
    is known as a baud rate.

    * A T1 consists of 24 telephone channels.

    * A T3 consists of 28 T1 lines.

    * The more accurate name for a modem used for a DSL connection is a DSLAM.

    * The more accurate name for a cable modem is a CMTS.

    * A section of the radio spectrum that’s been agreed upon to be used for certain
    communications is known as a frequency band.

    * ONT stands for optical network terminator.

    * FTTP stands for fiber to the premises.

    * The first field in an 802.11 header is known as a frame control field.

    * A traditional wireless network involving access points that all have wired
    connections is known as a WLAN.

    * The original and flawed wireless security protocol is known as WEP.

    * Another name for cellular networking is mobile networking.
