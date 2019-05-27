# **The Transport Layer and Application Layers**

## **The Transport Layer**

* The Transport Layer

    * This layer is responsible for multiplexing, and demultiplexing the traffic,
    establishing long running connections, and ensuring data integrity through
    error checking and data verification.

    * Multiplexing on transport layer means that nodes on the network have the
    ability to direct traffic towards many different receiving services.

    * Transport layer handles this function through ports.

    * Port: A 16-bit number that's used to direct traffic to specific services
    running on a networked computer.

        * Different network services run while listening on specific ports for
        incoming requests.

        * The port used for HTTP is 80, FTP is 21.

        * Ports are normally denoted after a colon at the end of an IP address,
        like 10.1.1.100:80. This notation is known as Socket Address or socket
        number.
* Dissection of a TCP Segment

    * An IP datagram encapsulates a TCP segment into the payload section.

    * TCP Segment: made up of TCP header and a data section.

        * Data section is a payload for Application layer.

        * TCP Segment Header Parts:

                    Source port (16 bits) |  Destination port (16 bits)
                                Sequence number (32 bits)
                            Acknowledgement number (32 bits)
Header length (4 bits) | empty (6 bits) | Control flags (6 bits) | Window (16 bits)
                       Checksum (16 bits) | Urgent (16 bits)
                       Options (0 or 16 bits if any) | Padding
                                Data Payload (varies)

            - Destination port: The port of the service the traffic is intended for.

            - Source port: A high-numbered port chosen from a special section of
            ports known as ephemeral ports.

            - Sequence number: A 32-bit number that's used to keep track of where
            in a sequence of TCP segments this one is expected to be.

                - An Ethernet frame is usually limited in size to 1,518 bytes.

            - Acknowledgement number: The number of the next expected segment.

            - Data offset field (Header length): A 4-bit number that communicates
            how long the TCP header for this segment is.

            - TCP Window: Specifies the range of sequence numbers that might be
            sent before an acknowledgement is required.

            - TCP Checksum: Operates just like the checksum field at the IP and
            Ethernet level. Once all the segment has been ingested by a recipient,
            the checksum is calculated across the entire segment and is compared
            with the checksum in the header to make sure of data integrity.

            - Urgent Pointer field: Used in conjunction with one of the TCP control
            flags to point out particular segments that might be more important
            than others.

            - Options field: It is sometimes used for more complicated flow control
            protocols.

            - Padding: Just a sequence of 0s to ensure that the data payload section
            begins at the expected location.

* TCP Control Flags and the Three-Way Handshake

    * TCP Control flags:

        - URG (Urgent):

            * A value of 1 indicates that the segment is considered urgent and
            that the urgent pointer field has more data about this.

            * This flag is not normally used.

        - ACK (Acknowledged):

            * A value of 1 means that the acknowledgement number field should be
            examined.

        - PSH (Push):

            * The transmitting device wants the receiving device to push currently
            -buffered data to the application on the receiving end as soon as possible.

            * A buffer is a computing technique which a certain amount of data is
            held somewhere, before being sent somewhere else.

        - RST (Reset):

            * One of the sides in a TCP connection hasn't been able to properly
            recover from a series of missing or malformed segments.

        - SYN (Synchronize):

            * It's used when first establishing a TCP connection and make sure the
            receiving end knows to examine the sequence number field.

        - FIN (Finish):

            * When the flag is set to 1, it means the transmitting computer doesn't
            have any more data to send and the connection can be closed.

    * TCP connection establishment

        * To start things off, Computer A (sender) sends a TCP segment to B with
        the SYN flag set.

        * Computer B then responds with a TCP segment where both the SYN and ACK
        flags are set.

        * Then computer A responds again with just the ACK flag set.

        * This is called the Three-Way Handshake.

        * Handshake: A way for two devices to ensure that they're speaking the
        same protocol and will be able to understand each other.

        * After this handshake, a TCP connection is operating in full duplex mode.

        * Each message sent in this connection, should be responded with a TCP
        segment that has the ACK flag set.

    * Four-Way Handshake

        * When one side is ready to close the connection, this process occurs.

        * Computer ready to close the connection sends a FIN flag.

        * The other computer responds with an ACK flag.

        * Then if this computer is ready to close the connection which is the case
        for majority of times, it sends a FIN flag back to the original computer.

        * Which is responded to by an ACK flag.

        * Hypothetically, a TCP connection can stay open in simplex mode with
        only one side closing the connection.

* TCP Socket States

    * Socket: The instantiation of an end-point in a potential TCP connection.

        * TCP sockets require actual programs to instantiate them.

        * TCP Socket state:

            - LISTEN: A TCP socket is ready and listening for incoming connections.

                * Server-side

            - SYN_SENT: A synchronization request has been sent, but the connection
            hasn't been established yet.

                * Client-side

            - SYN_RECEIVED: A socket previously in a LISTEN state has received a
            synchronization request and sent a SYN/ACK back, but it hasn't received
            the final ACK from the client yet.

                * Server-side

            - ESTABLISHED: The TCP connection is in working order and both sides
            are free to send each other data.

                * Server and Client-side

            - FIN_WAIT: A FIN has been sent, but the corresponding ACK from the
            other end hasn't been received yet.

            - CLOSE_WAIT: The connection has been closed at the TCP layer, but that
            the application that opened the socket hasn't released its hold on the
            socket yet.

            - CLOSED: The connection has been fully terminated and that no further
            communication is possible.

        * Socket states and names can differ from OS to OS.

    * Instantiation: The actual implementation of something defined elsewhere.

* Connection-Oriented and Connectionless Protocols

    * Connection-Oriented Protocol: Establishes a connection, uses this to ensure
    that all data has been properly transmitted.

        * In Ethernet or IP layer, if the data is corrupted, the whole frame or
        datagram is discarded and it's up to transport layer to determine whether
        a resend is necessary or not.

    * User Datagram Protocol (UDP)

        * Is a transport layer protocol which is connectionless. Unlike TCP, doesn't
        rely on connections or doesn't even support the concept of an acknowledgement.
        With UDP, you just set a destination port and send the packet.

* System Ports vs Ephemeral Ports

    * Ports are represented by a single 16-bit number, meaning that they can
    represent the numbers 0-65535.

    * This range has been split up by IANA into independent sections:

        - Port 0 isn't in use for network traffic, but it's sometimes used in
        communications taking place between different programs on the same computer.

        - Ports 1-1023: Are referred to as system ports, which represent the official
        ports for most well-known network services, like 80 for HTTP, 21 for FTP. In
        most OSs, administrator level access is required to start a program that listens
        on a system port.

        - Ports 1024-49151: Known as registered ports that are used for lots of
        other network services that are not quite common, like 3306 for most databases.
        These ports are sometimes officially registered and acknowledged by IANA. In
        most OSs, any user of any access level can start a program listening on a
        registered port.

        - Ports 49152-65535: Known as private or ephemeral ports can't be registered
        with IANA and are generally used for establishing outbound connections. When a
        client wants to communicate with a server, the client will be assigned an
        ephemeral port to be used for that one connection, while the server uses a
        static port.

    * Not all OSs follow this standard.

* Firewalls

    * Firewall: A device that blocks traffic that meets certain criteria.

        * They can operate at lots of different layers of the network. They can
        perform inspection of application layer traffic, blocking a certain ranges
        of IP addresses but they're mostly used at transport layer. These Firewalls
        will have a configuration that enables them to block traffic to certain ports
        while allowing traffic to other ports.

        * Firewalls are sometimes independent network devices.

## **The Application Layer**

* The Application Layer

    * Web Protocols

        * Most popular Web browsers are Chrome, Safari, Firefox which act as a
        web client.

        * Most popular Web servers are Microsoft IIS, Apache and nginx which act as
        web servers.

        * For web traffic, the application layer protocol is known as HTTP.

* The Application Layer and the OSI Model

    * Open Systems Interconnection model has 7 layers and introduces two additional
    layers between our transport layer and application layer:

        - Session layer: Facilitating the communication between actual applications
        and the transport layer. Takes application layer data and hands it off
        to the presentation layer.

        - Presentation layer: Responsible for making sure that the unencapsulated
        application layer data is able to be understood by the application in question.
        This is the part that might handle encryption or compression of data.

    * Standard counter for TTL is 64.

* Summary

    * Ports 1-1023 are known as system ports.

    * Ports 1024-49151 are known as registered ports.

    * The instantiation of an endpoint in a potential TCP connection is known as
    a socket.

    * Most common example of a connection-oriented protocol is TCP.

    * I transmitting device would like for the receiving device to push currently
    buffered data to the application on the receiving end immediately, it would
    set the PSH flag.

    * The sequence of SYN, SYN/ACK, ACK packets is known as the three-way handshake.

    * A 32-bit number that's used to keep track of where you are in a sequence of
    TCP segments is known as a sequence number.

    * HTTP is an example of an application layer protocol.

    * Application layer data lives in the data payload of the transport layer protocol.

    * Ports that are generally used to establish outbound connections are known as
    ephemeral ports.

    * The control flag that isn't really in use by modern networks is the URG flag.

    * The concept of taking traffic that's all aimed at the same node and delivering
    it to the proper receiving service is known as demultiplexing.
