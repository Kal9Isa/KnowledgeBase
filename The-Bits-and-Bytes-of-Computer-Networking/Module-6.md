# **Troubleshooting and the Future of Networking**

* Error Detection: The ability for a protocol or program to determine that
something went wrong.

* Error Recovery: The ability for a protocol or program to attempt to fix it.

## **Verifying Connectivity**

* Ping: Internet Control Message Protocol

    * ICMP is used to communicate issues such as if a router doesn't know how to
    route a destination, a certain port isn't reachable or that the TTL of an
    IP datagram expired and no further router hops will be attempted.

        - Mainly used by a router or a remote host to communicate while the
        transmission has failed back to the origin of the transmission.

        - ICPN structure:

            - Type field: 8-bits long, specifies what type of message is being
            delivered. For instance, "Destination unreachable" or "Time exceeded".

            - Code field: 8-bits long, Indicates a specific reason for the message
            than just the type. For example "Destination host unreachable", "Destination
            network unreachable" or "Destination port unreachable".

            - Checksum field: 16-bits long

            - Rest of header field: 32-bits long, Optionally used by some of the
            specific types and codes to send more data.

            - Data Payload field: It exists so the recipient of the message knows
            which of their transmissions caused the error being reported. Contains
            the entire IP header and the first 8 bytes of the data payload section
            of the offending packet.

        * Ping: Allows us to send a special type of ICMP message called an Echo
        Request. It just asks the destination to respond to the transmission.

            - If the destination is up and running and able to communicate on the
            network, it'll send back an ICMP Echo Reply message type.

            - Usage:

                $ ping <Destination IP address - FQDN>

            - Results:

                Address sending the ICMP Echo Reply | Size of the ICMP packet | How long it took | TTL count

            - It supports a number of flags:

                - Number of Echo Requests to send: -c<Desired number> like -c4.

                - How large ICMP packets should be

                - How quickly they should be sent: -i<Desired seconds>

* Traceroute

    * With `ping` you can understand whether you have a connection to a destination
    or not, also you can get a general idea about the quality of the connection.

    * Traceroute: A utility that lets you discover the path between two nodes, and
    gives you information about each hop along the way.

        - When the TTL reaches 0, the packet is discarded and an ICMP Time Exceeded
        message is sent back to the originating host.

        - `Traceroute` sets TTL to 1 for the first packet and then increments it
        for the next ones until the packet makes it to the destination.

        - Usage:

            $ traceroute <Destination IP address - FQDN>

        - Results:

            Number of the hop | IP of the device at the hop (hostname if resolvable)| Round Trip Time - RTT

        - On Linux and MacOS, `traceroute` sends UDP packets to very high port numbers.

        - On Windows it's known as `tracert` and it defaults to using ICMP Echo
        Requests.

        - `traceroute` has flags too, Plus two more tools that are similar to it
        are `mtr` on Linux and MacOS and `pathping` on Windows. These tools act
        as long running tools to see changes over time. `mtr` reports on a real-time
        basis, however `pathping` runs for 50 seconds and then displays the final
        aggregates all at once.

* Testing Port Connectivity

    * Two powerful tools to test the transport layer connectivity are `netcat` on
    Linux and MacOS, and `Test-NetConnection` on Windows.

    * Netcat: Can be run using `nc` command and has two mandatory arguments:

        - A host

        - A port

        - Usage:

            $ nc <Destination IP address - FQDN> <Port number>

        - You can use `-z` flag as Zero Input/Output Mode to just test the port
        connectivity. `-v` flag as Verbose mode, helps to see the results in
        cmd, however it's used in non-verbose mode in scripts.

        - Its list of features includes port scanning, transferring files, and
        port listening, and it can be used as a backdoor.

    * If `Test-NetConnection` is sued without a port number, it will default to
    ICMP Echo Request, much like `ping`.

        - Use `-port` flag to test connectivity on a specific port.

        - It supports ping tests, TCP test, route tracing, and route selection
        diagnostics.

        - The output can include DNS lookup results, a list of IP interfaces,
        IPSec rules, route/source address selection results, and/or confirmation
        of connection establishment.

## **Digging into DNS**

* Name Resolution Tools

    * `nslookup` is a common tool for DNS configurations.It gives you the name
    server used to resolve the request and the results of the lookup.

        - Usage:

            $ nslookup <hostname>

        - It also supports an interactive mode where you can run lots of queries,
        to enter this mode simply type `nslookup`.

        - You can also do some extra configuration for more in-depth Troubleshooting,
        For example if you type `server <DNS name server>` in the interactive mode,
        you can set the DNS to that server temporarily to perform lookups.

        - You can also change the type of records you want to lookup by using  
        `set type=<Record type>` command in the interactive mode. `nslookup` by
        default return A records.

        - To see what's happening under the hood, you can use `set debug`, it can
        contain data about the TTL if it was cached, or the serial number of the
        zone file the request was made against.

* Public DNS Servers

    * An ISP almost always gives you access to a recursive name server as part of
    the service it provides.

    * Public DNS Servers: Name servers specifically set up so that anyone can use
    them, for free.

        - The Level 3 communications is a company that offers DNS for free.

            - 4.2.2.1 through 4.2.2.6 are the IP address of its name servers.

        - Google offers Public DNS servers also.

            - 8.8.8.8 and 8.8.4.4 are its IP addresses.

        * Most public DNS servers are available globally through Anycast.

        * Hijacking outbound DNS requests with faulty responses is an easy way to
        redirect your users to malicious sites.

        * Most of these servers also respond to ICMP Echo Requests.

* DNS Registration and Expiration

    * Registrar: An organization responsible for assigning individual domain names
    to other organizations or individuals.

    * Once you own a domain name, you can either have the registrar's name servers
    act as the authoritative name servers for the domain, or you can configure your
    own servers to be authoritative.

    * Domains can be transferred to another party, by getting a unique string
    generated by the registrar that proves you own the domain and can transfer it.
    You configure your DNS settings to contain the string in a specific record,
    usually a TXT record. Once this info is propagated, it can be confirmed that
    you both own the domain and can transfer it.

* Hosts Files

    * The original way that numbered network addresses were correlated with words
    was through hosts files.

    * Hosts File: A flat file that contains, on each line, a network address
    followed by the host name it can be referred to as.

    * These files are read by the OS networking stack.

    * A Loopback Address always refers to itself. So it is a means that you can
    send network traffic to yourself and it will never leave the node.

        - For IPv4 is 127.0.0.1

    * Almost every hosts file in existence will, in the very least, contain a line
    that reads `127.0.0.1 localhost`, most likely followed by `::1 localhost` where
    ::1 is the loopback address for IPv6.

    * Hosts files are a popular way for computer viruses to disrupt and redirect
    user's traffic.

    * Hosts files are examined before a DNS resolution attempt occurs on just
    about every major operating system. This lets you force an individual computer
    to think a certain domain name always points at a specific IP.

## **The Cloud**

* What is the Cloud?

    * Cloud Computing: A technological approach where computing resources are
    provisioned in a shareable way, so that lots of users get what they need, when
    they need it. A new model in computing where large clusters of machines let us
    use the total resources available in a better way.

    * Hardware Virtualization: Allows the concept of a physical machine and logical
    machine to be abstracted away from each other.

    * Virtualization: A single physical machine, called a host, could run many
    individual virtual instances, called guests.

    * Hypervisor: A piece of software that runs and manages virtual machines, while
    also offering these guests a virtual operating platform that's indistinguishable
    from actual hardware.

    * Public Cloud: A large cluster of machines run by another company.

    * Private Cloud: Used by a single large corporation and generally physically
    hosted on its own premises.

    * Hybrid Cloud: A term used to describe situations where companies might run
    things like their most sensitive proprietary technologies on a private cloud,
    while entrusting their less-sensitive servers to a public cloud.

* Everything as a Service

    * IaaS - Infrastructure as as Service: You shouldn't have to worry about building
    your own network or your own servers.

    * PaaS - Platform as a Service: A subset of cloud computing where a platform
    is provided for customers to  run their services.

    * SaaS - Software as a Service: A way of licensing the use of software to
    others while keeping that software centrally hosted and managed.

        - Gmail for business by Google or Office 365 Outlook by Microsoft are a
        good examples of SaaS.

* Cloud Storage

    * In this service, a customer contracts a service provider to keep their data
    secure, accessible and available.

## **IPv6**

* IPv6 Addressing and Subnetting

    * IPv6 is 128-bits long, they're written out as 8 groups of 16 bits each, which
    are made up of four hexadecimal numbers.

    * Every single IP address that begins with `2001:0db8` has been reserved for
    documentation and education, or for books and courses

    * There are two rules when it comes to shortening the IPv6 address:

        1- You can remove any leading zeroes from a group.

        2- Any number of consecutive groups composed of just zeroes can be replaced
        with two colons. (can be used only once)

        - For example:

            - This IP -> 2001:0db8:0000:0000:0000:ff00:0012:3456

            - After applying first rule: 2001:db8:0:0:0:ff00:12:3456

            - Applying the second rule: 2001:db8::ff00:12:3456

        - Another example is the loopback address in IPv6 which is 31 0s and a 1
        at the end translating to -> ::1.

        - Any address that begins with `FF00::` is used for multicast, which is a
        way of addressing groups of hosts all at once.

        - Addresses beginning with `FE80::` are used for link-local unicast.

        - Link-local Unicast Addresses: Allow for local network segment communications
        and are configured based upon a host's MAC address.

            - This link is used by IPv6 addresses to receive their network configuration
            which is a lot like DHCP. The host;s MAC address is run through an
            algorithm to turn it from 48-bit number into a unique 64-bit number.
            It's then inserted into the address's host ID.

    * The first 64-bits of any IPv6 address is the network ID and the rest if used
    for host ID.

    * CIDR notation is used with a subnet mask against the network ID portion of
    IPv6 addresses for administrative purposes.

* IPv6 Headers

    * Version field: 4-bits that defines what version of IP is in use.w

    * Class field: 8-bits that defines the type of traffic contained within the
    IP datagram and allows for different classes of traffic to receive different
    priorities.

    * Flow Label field: 20-bits that's used in conjunction with the traffic class
    field for routers to make decisions about the QoS level for a specific datagram.

    * Payload Length field: 16-bit that defines how long the data payload section
    of the datagram is.

    * Next Header field: Unique to IPv6. Defines what kind of header is immediately
    after this current one.

        - The reason for this field is that, since the IPv6 address is 4 times bigger
        than IPv4, the header would be too large and would take long to transmit across
        the link, so the optional fields are removed from the header itself and become
        a type of header.

        - These additional headers are optional, meaning they're not required.

    * Hop Limit field: 8-bit field that's identical in purpose to TTL field.

    * Source Address: 128-bits long.

    * Destination Address: 128-bits long.

    * If the Next header field is set, at this time it will follow the datagram,
    if not, the data payload will follow.

* IPv6 and IPv4 Harmony

    * IPv4 Mapped Address Space

        - The IPv6 specifications have set aside a number of addresses that can
        be directly correlated to an IPv4 address.

        - Any IPv6 address that begins with 80 zeroes and is then followed by 16
        ones, is understood to be part of the IPv4 mapped address space. The
        remaining 32 bits are just the IPv4.

    * IPv6 Tunnels: Servers take incoming IPv6 traffic and encapsulate it within
    traditional IPv4 datagram.

        - They consist of IPv6 tunnel servers on either end of a connection.

    * IPv6 Tunnel Broker: Companies that provide IPv6 tunneling endpoints for you,
    so you don't have to introduce additional equipment to your network.

* IPv6 and IPv4 Harmony Protocols

    * 6in4: Uses tunneling to encapsulate IPv6 traffic over explicitly-configured
    IPv4 links as defined in RFC 4213.

        - The 6in4 traffic is sent over the IPv4 Internet inside IPv4 packets whose
        IP headers have the IP protocol number set to 41, which is specifically
        designed for IPv6 encapsulation.

        - Since the IPv6 header immediately follows after IPv4's 20 byte long header,
        and with Ethernet's Maximum Transmission Unit (MTU) of 1500 bytes, one can
        send IPv6 packets of 1480 bytes without fragmentation.

        - Also referred to as proto-41 static, because the endpoints are configured
        statically.

    * Tunnel Setup Protocol: TSP is a networking control protocol used to negotiate
    IP tunnel setup parameters between a tunnel client host and a tunnel broker
    server, the tunnel endpoints.

        - Defined as RFC 5572 and is majorly used in IPv6 transition mechanisms.

        - TSP performs negotiation of the following parameters:

            - User authentication using the Simple Authentication and Security Layer
            (SASL) protocol known as RFC 4422.

            - Tunnel encapsulation for a variety of scenarios:

                - IPv6 over IPv4 tunnels -> RFC 4213

                - IPv4 over IPv6 tunnels -> RFC 2473

                - IPv6 over UDP/IPv4 tunnels for built-in traversal of NAT.

            - IP address assignment for both tunnel endpoints.

            - DNS registration of endpoint addresses and reverse DNS.

            - Tunnel keep-alive mechanisms as needed.

            - IPv6 address prefix assignment for routers.

            - Routing protocols.

        - TSP Session: Is initiated by the TSP client to establish an end-to-end
        tunnel with the TSP server. It consists of basic exchange of XML-encoded data
        using TCP or UDP. After the negotiation of tunnel setup parameters, the
        session is terminated and the client undertakes the task of configuring
        its local tunnel endpoint.

    * AYIYA - Anything in Anythin: A networking protocol in use between separated
    IP networks. Most often used to provide IPv6 transit over an IPv4 network link
    when NAT masquerades a private network with a single IP address that may change
    frequently because of DHCP provisioning by ISPs.

        - Features:

            - Tunneling of networking protocols within another IP protocol.

            - Network security is provided by preventing tunneled packets to be
            spoofable or replayable.

            - Transparent handling of NAT.

            - The endpoint of at least one of the two tunnel endpoints should be
            able to change to provide mobility features.

* Summary

    * The ability for a protocol or program to determine that something went wrong is known as error detection.

    * When you send an echo request message with the ping program, a successful attempt will return an Echo Reply message.

    * The Linux and macOS program `traceroute` is known by a slightly different name on Windows. It's referred to as `tracert`.

    * While in an interactive nslookup session, you'd use the `server` keyword to change the DNS server you're using.

    * An organization responsible for assigning individual domain names to other organizations or individuals is known as a DNS registrar.

    * The IPv6 loopback address is 0000:0000:0000:0000:0000:0000:0000:0001 or ::1 in short.

    * With virtualization, a single physical machine, called a host, can run many individual virtual instances, called guests.

    * IPv6 addresses beginning with FE80:: are used for link-local unicast.

    * For all IPv6 addresses, the network ID is always the first 64 bits.

    * The equivalent of the TTL field in an IPv4 header is known as the hop limit field in an IPv6 header.

    * The IPV4 mapped address space within IPv6 always starts with 80 zeroes.
