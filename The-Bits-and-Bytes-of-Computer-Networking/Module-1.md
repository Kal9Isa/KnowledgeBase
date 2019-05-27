# **Introduction to Networking**

## **Introduction to Computer Networking**

* Protocol is a defined set of standards that computers must follow in order to
communicate properly.

* Computer Networking is the name we've given to the full scope of how computers
communicate with each other.

## **The TCP/IP Five-Layer Network Model**

* Physical layer: 10 Base T, 802.11 | Bits | n/a

    * Represents the physical devices that interconnect computers.

* Data Link layer: Ethernet, Wi-Fi | Frames | MAC Address

    * Responsible for  defining a common way of interpreting these signals so
    network devices can communicate.

    * Ethernet standards also define a protocol responsible for getting data to
    nodes on the same network or link.

* Network layer: IP | Datagram | IP address

    * Allows different networks to communicate with each other through devices
    known as routers.

    * Internetwork: A collection of networks connected together through routers,
    the most famous of these being the Internet.

    * IP is the heart of the Internet and most smaller networks around the world.

    * Network software is usually divided into client and server categories,
    with the client application initiating a request for data and the server
    software answering the request across the network. A single node may be
    running multiple client or server applications.

* Transport layer: TCP / UDP | Segment | Port #'s

    * Sorts out which client and server programs are supposed to get that data.

    * The big difference between the two  is that TCP provides mechanisms to ensure
    that data is reliably delivered while UDP does not.

    * Network layer, IP is responsible for getting data from one node to another.
    Also they make sure that data is transported to the right application on those
    nodes.

* Application layer: HTTP, SMTP, etc. | Messages | n/a

* The OSI Model

    * The Open Systems Interconnection Model is a conceptual model that characterizes
    and standardizes the communication functions of a telecommunication or computing
    system without regard to its underlying internal structure and technology.

    * Application layer: PDU - Data

        - High-level APIs, including resource sharing, remote file access.

    * Presentation layer: PDU - Data

        - Translation of data between a networking service and an application,
        including character encoding, data compression and encryption / decryption.

    * Session layer: PDU - Data

        - Managing communication sessions, i.e. continuous exchange of information
        in the form of multiple back-and-forth transmissions between two nodes.

    * Transport layer: PDU - Segment, Datagram

        - Reliable transmission of data segments between points on a network,
        including segmentation, acknowledgement, and multiplexing.

    * Network layer: PDU - Packet

        - Structuring and managing a multi-node network, including addressing,
        routing and traffic control.

    * Data Link layer: PDU - Frame

        - Reliable transmission of data frames between two nodes connected by a
        physical layer.

    * Physical layer: PDU - Symbol

        - Transmission and reception of raw bit streams over a physical medium.

## **The Basics of Networking Devices**

* Connect different devices to each other. allowing data to be transmitted over
them.

    * Most cables today are divided into two categories:

        - Copper

            - Most common type, that are made up of multiple pairs of copper wires
            inside plastic insulator.

            - The most common forms of copper twisted-pair cables used in networking
            are Cat5, Cat5e, and Cat6 cables.

            - These categories have different physical characteristics like the
            number of twists in the pair of copper wires that result in different
            usable length and transfer rates.

            - Crosstalk: When an electrical pulse on one wire is accidentally
            detected on another wire.

        - Fiber

            - Contain individual optical fibers, which are tiny tubes made out of
            glass about the width of a human hair.

* Hub

    * A physical layer device that allows for connections from many computers at
    once.

    * Collision domain is a network segment where only one device can communicate
    at a time. If multiple systems try sending data at the same time, the electrical
    pulses sent across the cable can interfere with each other.

    * The difference is that while a hub is a layer 1 or physical layer device,
    a switch is a level 2 or data link device. This means that a switch can actually
    inspect the contents of the Ethernet protocol data being sent around the network,
    determine which system the data is intended for and then only send that data
    to that one system. This reduces or even completely eliminates the size of
    collision domains on a network. Which leads to fewer retransmissions and a higher
    overall throughput.

    * Hubs and Switches are the primary device used to connect computers on a
    single network, usually referred to as a LAN.

* Router

    * A device that knows how to forward data between independent networks.

    * A router operates at layer 3, network layer.(IP). It inspects IP data to
    determine where to send them.

    * Routers store internal tables containing information about how to route
    traffic between lots of different networks all over the world.

    * Border Gateway Protocol (BGP)

        - Routers share data with each other via this protocol, which lets them
        learn about the most optimal paths to forward traffic.

## **The Physical Layer**

* Bit

    * Is  the smallest representation of data that a computer can understand. it's
    a one or a zero.

* Modulation

    * A way of varying the voltage of this charge moving across the table.

    * When used in computer networks, this kind of modulation is more specifically
    known as line coding. It allows devices on either end of a link to understand
    that an electrical charge in a certain state is a zero, and in another state
    is a one.

* A standard Cat6 cable has 4 twisted pairs inside a jacket. These cables allow for
duplex communication.

* Duplex communication

    * The concept that information can flow in both directions across the cable.

* Simplex communication

    * This process in unidirectional.

* Full-Duplex communication

    * The concept that information can flow in both directions simultaneously across
    the cable.

* Half-Duplex communication

    * If there's something wrong with the connection, you might see a network link
    degrade and report itself as operating in half-duplex mode. While communication
    is possible in both directions, only one device can be communicating at the same
    time.

* Ethernet over twisted pair

    * These technologies are the communication protocols that determine how much
    data can be sent over a twisted pair cable, how quickly that data can be sent,
    and how long a network cable can be before the data quality begins to degrade.

    * Early Ethernet had used various grades of coaxial cable, but in 1984, StarLAN
    showed the potential of simple unshielded twisted pair. This led to the
    development of 10BASE-T and its successors 100BASE-TX, 1000BASE-T and 10GBASE-T,
    supporting speeds of 10, 100 Mbit/s and 1 and 10 Gbit/s respectively.

    * All these standards use 8P8C connectors and the cables from Cat3 to Cat8.

    * StarLAN was the first twisted pair design as IEEE 802.3e.

    * 10BASE-T is also known as IEEE 802.3i. Although 10BASE-T is rarely used as a
    normal operation signaling rate today, it is still in wide use with NICs in
    Wake-on-LAN power-down mode and for special, low-power, low-bandwidth applications.
    10BASE-T is still supported on most twisted-pair Ethernet ports with up to
    Gigabit Ethernet speed.

    * 10 refers to its transmission speed in Mbit/s. BASE denotes the baseband
    transmission is used. the T designates the twisted-pair cable. Other symbols
    such as TX or T4 after T, refer to the encoding and number of lanes.

    * Most cables are wired "straight-though" (pin 1 to pin 1, pin 2 to pin 2, ...).
    In some instances the "crossover" form may still be required.

    * Since the T568A and T568B standards differ only in that they swap the positions
    of the two pairs used for transmitting and receiving, a cable with T568A at one
    end and T568B on the other end results in a crossover cable.

    * A 10BASE-T or 100BASE-TX host uses a connector wiring called Medium Dependent
    Interfaces (MDI), transmitting on pins 1 and 2 and receiving on pins 3 and 6 to
    a network device. An infrastructure node (a hub or a switch) accordingly uses a
    connector wiring called MDI-X, transmitting on pins 3 and 6 and receiving on
    pins 1 and 2. These ports are connected using a straight-through cable so
    each transmitter talks to the receiver on the other end of the cable.

    * Nodes can have two types of ports: MDI (uplink port) or MDI-X (regular port,
    X for internal crossover). Hubs and Switches have regular ports, while Routers,
    servers and end hosts have uplink ports.

    * When two nodes having the same type of ports need to be connected, a crossover
    cable may be required, especially for older equipment. Connecting nodes having
    different types of ports (MDI, MDI-X) requires straight-through cable.

    * Many modern Ethernet host adapters can automatically detect another computer
    connected with a straight-through cable and then automatically introduce the
    required crossover, if needed. Auto MDI-X allows for all connections to be made
    with straight-through cables.

    * A 10BASE-T transmitter sends two differential voltages: +2.5 V or -2.5 V.
    A 100BASE-TX transmitter sends three differential voltages: +1 V, 0 V, -1 V.

    * Some of the specified characteristics for cables in 10BASE-T is attenuation,
    characteristic impedance, timing jitter, propagation delay, and several types
    of noise and crosstalk. These characteristics are expected to be met by 100
    meters of 24-gauge UTP cables. 100BASE-TX follows the same wiring patterns but
    is more sensitive to wire quality and length, due to the higher bit rates.

    * 1000BASE-T uses all four pairs bi-directionally using hybrid circuits and
    cancellers. Data is encoded using 4d-PAM5; four dimensions using PAM (Pulse
    Amplitude Modulation) with 5 voltages: -2 V, -1 V, 0 V, +1 V, +2 V. While +2 V
    and -2 V, may appear at the pins of the line driver, the voltage on the cable
    is nominally +1 V, +0.5 V, 0V, -0.5 V, -1 V.

    * 100BASE-TX and 1000BASE-T were both designed to require a minimum of Cat5
    cable and also specify a maximum cable length of 100 meters. Since then the Cat5
    is replaced by Cat5e.

    * Shared Cable

        * 10BASE-T and 100BASE-TX require only two pairs to operate (pins 1-2, 3-6).
        Since common Cat5 has 4 pairs, it's possible to use the spare pairs (pins
        4-5, 7-8) in 10 and 100 Mbit/s configurations for other purposes. It may be
        used for Power over Ethernet (PoE), for two Plain Old Telephone Service (POTS)
        lines, or for a second connection of the same kind. However shared cable is
        not an option for Gigabit Ethernet (1000BASE-T) as it requires all four pairs
        to operate.

    * Single-pair

        * The 100BASE-T1 and 1000BASE-T1 single pair Ethernet PHYs (SPE) are intended
        for automotive applications or as optical data channels in other applications.
        This single pair operates at full duplex and has  a minimum reach of 15 m
        (100BASE-T1 and 1000BASE-T1 link segment type A) or up to 40 m (1000BASE-T1 Link
        segment type B) with up to 4 in-line connectors. Similar to PoE, Power over Data
        Lines (PoDL) can provide up to 50 W to a device.Cable must be capable of transmitting
        600 MHz for 1000BASE-T1 and 66 MHz for 100BASE-T1.

    * Transfer speed = lanes x bits per hertz x spectral bandwidth

    * Effective bits/Hz/lane after loss to encoding overhead.

    * The spectral bandwidth is the maximum rate at which the signal will complete
    one Hz cycle. It is typically half the symbol rate, because one can send a
    symbol both at the positive and negative peak of the cycle. Exceptions are
    100BASE-T where it is equal because it uses Manchester Code, and 100BASE-TX where
    it is one quarter because it uses MLT-3 encoding.

    * At shorter cable length, it is possible to use cable of a lower grade than
    it is required for 100 m.

* The most common plug is Registered Jack 45 (RJ45, RJ11 for phone cables).

* Network ports

    * Are generally directly attached to the devices that make up a computer network.

    * Most ports have two lights:

        * Link light: will be lit when a cable is properly connected to two devices
        that are both powered on.

        * Activity light: will flash when data is actively transmitted across the
        cable.

    * Patch Panel

        * Is a device containing many net ports but it does no other work.

## **The Data Link Layer**

* Ethernet is the most widely used protocol to send data across individual links.

* Carrier Sense Multiple Access with Collision Detection

    * CSMA/CD is used to determine when the communication channels are clear and
    when the device is free to transmit data.

    * The way CSMA/CD works is if there's no data currently being transmitted on
    the network segment, a node will feel free to send data. If it turns out that
    two or more computers end up trying to send data at the same time, the computers
    detect this collision and stop sending data. Each device involved with the
    collision then waits a random interval of time before trying to send data again.

    * When a network segment is a collision domain, it means that all devices on
    that segment receive all communications across the entire segment.

* MAC address

    * A globally unique identifier attached to an individual network interface. It's
    a 48 bit number normally represented by six groupings of two hexadecimal numbers.

    * Is split into two sections:

        - Organizationally Unique Identifier (OUI): The first 3 octets of a MAC address.

        - Vendor Assigned (NIC cards, Interfaces)

* Hexadecimal

    * A way to represent numbers using 16 digits.

* Octet

    * In computer networking, any number that can be represented by 8 bits.

* Ethernet uses MAC address to ensure that the data it sends has both an address
for the machine that sent the transmission, as well as the one the transmission
was intended for.

* Types of transmission

    * Unicast: Is always meant for just one receiving address.

        - If the least significant bit in the first octet of a destination address
        is set to zero, it means that ethernet frame is intended for only the
        destination address. It's received by all devices on the collision domain
        but only processed by the destination.

        - If the least significant bit in the first octet of a destination address
        is set to one, it means you're dealing with a multicast frame. Network
        interfaces can be configured multicast addresses for these sort of communication.

    * Broadcast: Is sent to every single device on a LAN.

        - This is accomplished by using a special destination known as a broadcast
        address. The ethernet's broadcast address is FF:FF:FF:FF:FF:FF.

* Data packet

    * An all-encompassing term that represents any single set of binary data being
    sent across a network link.

* Ethernet frame

    * A highly structured collection of information presented in a specific order.

    * Almost all sections of an ethernet frame are mandatory and most of them have
    a fixed size.

    * Ethernet frame dissection:

        - Preamble 8 bytes | destination address 6 bytes | Source Address 6 bytes | Tag 4 bytes | Ether-type 2 bytes | Payload 0 - 1500 bytes | FCS 4 bytes

    * Preamble: 8 bytes (or 64 bits) long, and can itself be split into two sections.

        - The first seven bytes are a series of alternating ones and zeros, that
        act as a buffer between frames and can also be used by the network interfaces
        to synchronize internal clocks they use, to regulate the speed at which
        they send data.

        - This last byte in the preamble is known as the SFD or Start Frame Delimeter.
        This signals to a receiving device that the preamble is over and that the
        actual frame contents will now follow.

    * EtherType field

        * 16 bits long and used to describe the protocol of the contents of the frame.

    * VLAN header

        * Can also come before the EtherType.

        * It indicates that the frame itself is what's called a VLAN frame.

        * If a VLAN header is present, the EtherType field follows it.

    * Payload: In networking terms, is the actual data being transported , which
    is everything that isn't a header.

    * Frame Check Sequence

        * A 4-byte (or 32-bit) number that represents a checksum value for the
        entire frame.

        * This checksum value is calculated by performing what's known as a cyclical
        redundancy check against the frame.

* Virtual LAN (VLAN)

    * A technique that lets you have multiple logical LANs operating on the same
    physical equipment.

    * Any frame with a VLAN tag will only be delivered out of a switch interface
    configured to relay that specific tag. This way you can have a single physical
    network that operates like it's multiple LANs. VLANs are usually used to segregate
    different forms of traffic.

* Cyclical Redundancy Check (CRC)

    * An important concept for data integrity, and is used all over computing, not
    just network transmissions.

    * A CRC is basically a mathematical transformation that uses polynomial division
    to create a number that represents a larger set of data.

    * Ethernet itself only reports on data integrity, it doesn't perform data recovery.
