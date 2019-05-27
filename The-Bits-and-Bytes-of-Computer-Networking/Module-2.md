
# **The Network Layer**

## **The Network Layer**

* MAC addressing isn't a scheme that scales well.

* IP addresses

    * Are 32 bit long numbers made up of 4 octets and each octet is described in
    decimal numbers. An octet can represent numbers from 0 to 255.

    * IP addresses are shown in dotted decimal notation, like 172.2.5.6 .

    * IP addresses belong to networks, not to the devices attached to those
    networks.

* You can connect a new device to a network and an IP address will be assigned
to it automatically through a technology known as Dynamic Host Configuration Protocol.

    * An IP address assigned this way is known as a dynamic IP address. The opposite
    is the static IP address, which must be configured on a node, manually.

    * In Most cases, Static IP addresses are reserved for servers and network
    devices, while dynamic IP addresses are reserved for clients.

* IP Datagram

    * Under the IP protocol, a packet is usually referred to as an IP datagram.

    * Is a highly structured series of fields that are strictly defined.

    * The two primary sections of an IP datagram are the header and the payload.

    * IP Datagram dissection:

        Version 4 bits | Header length 4 bits | Service type 8 bits | Total length 16 bits
                Identification 16 bits         | Flags 4 bits | Fragment offset 12 bits
        TTL 8 bits | Protocol 8 bits          |           Header checksum 16 bits
                                    Source IP address 32 bits
                                    Destination IP address 32 bits
                                    Options 22 bits                     | Padding 10 bits

    * Version: Indicates what version of internet protocol is being used.

        - Most common versions are:

            - IPv4

            - IPv6

    * Header Length: Declares how long the entire header is. Which is almost always
    20 bytes in length when dealing with IPv4. (minimum length)

    * Service Type: These 8 bits can be used to specify details about quality of
    service, or QoS technologies.

    * Total Length: Indicates the total length of the IP datagram it's attached to.

    * Identification: A 16 bit number that's used to group the messages together.

        - The maximum size of a single IP datagram is the largest number you can
        represent with 16 bits: 65,535.

        - If the total amount of data that needs to be sent is larger than what can
        fit in a single datagram, the IP layer needs to split this data up into many
        individual packets. When this happens, the Identification field is used so
        that the receiving end understands that every packet with the same value in
        that field is a part of the same transmission.

    * Flag: Used to indicate if a datagram is allowed to be fragmented, or to indicate
    that the datagram has already been fragmented.

        - Fragmentation is the process of taking a single IP datagram and splitting it
        up into several smaller datagrams.

    * Fragmentation Offset: Contains values used by the receiving end to take all the
    parts of a fragmented packet and put them back together in the correct order.

    * Time To Live (TTL): An 8 bit field that indicates how many router hops a datagram
    can traverse before it's thrown away.

    * Protocol: Another 8 bit field that contains data about what transport layer
    protocol is being used.

        - The most common protocols of transport layer are:

            - TCP

            - UDP

    * Header Checksum: A checksum of the contents of the entire IP datagram header.

    * IP Options: An optional field and is used to set special characteristics for
    datagrams primarily used for testing purposes.

    * Padding: A series of zeroes used to ensure the header is the correct total
    size.

* IP addresses can be split into two sections:

    * Network ID

    * Host ID

* Address class system

    * A way of defining how the global IP address space is split up.

    * There are 3 types of classes:

        - Class A: These addresses are where the first octet is used for network ID,
        and the last three are used for the host ID.

        - Class B: These addresses are where the first two octets are used for the
        network ID, and the second two are for the host ID.

        - Class C: These addresses are where the first three octets are used for the
        network ID, and the last is for the host ID.

Class | Range | Max Hosts
------|-------| ----------
A     | 0 - 126 | 16 Million
B     | 128 - 191 | 64,000
C     | 192 - 223 | 254
D     | 224 - 239 | N/A
E     | 240 - 255 | N/A

* Class D addresses always begin with the bits 1110, and are used for multicasting,
which is how a single IP datagram can be sent to an entire network at once.

* Class E addresses are unassigned and for testing purposes.

* This class system has mostly been replaced by a system known as CIDR or Class
Inter-Domain Routing.

* Address Resolution Protocol (ARP)

    * A protocol used to discover the hardware address of a node with a certain
    IP address.

    * ARP table: A list of IP addresses and the MAC addresses associated with them.

    * ARP table entries generally expire after a short amount of time to ensure
    changes in the network are accounted for.

    * When a node wants to send a message and doesn't have the MAC address of its
    destination , it broadcasts ARP message to the MAC broadcast address which is
    all Fs. These messages are delivered to all computers on the local network.
    When the device that has the corresponding IP to the broadcasted MAC receives
    the message, it sends back an ARP response, which contains the MAC address for
    the network interface in question.

## **Subnetting**

* Subnetting

    * The process of taking a large network and splitting it up into many individual
    and smaller subnetworks, or subnets.

    * Incorrect subnetting setups  are a common problem you might run into as an
    IT support specialist, so it's important to have a strong understanding of
    how this works.

    * A gateway router serves as the entry and exit path to a certain network.

    * All the subnets will have their own gateway routers serving as the ingress
    and the egress point for each subnet.

    * At the internet level core routers only care about Network ID and use this
    to send the datagram along to the appropriate gateway router to that network.
    And finally the host ID is used by the last router to deliver the datagram to
    the intended recipient machine.

    * Subnet IDs are calculated via what's known as subnet mask.

    * Subnet mask

        * 32-bit numbers that are normally written out as four octets in decimal.

        * A subnet mask is a binary number that has two sections. The beginning
        part, which is the mask itself is a string of 1s followed by 0s
        after. The subnet mask which is the part with all 1s, tells us what we
        can ignore when computing a host ID. The rest will all the 0s tells us what
        would the host ID be.

        * The purpose of the mask or the part that's all 1s is to tell a router what
        part of an IP address is the subnet ID.

        * The size of a subnet is entirely defined by its subnet mask.

        * In general, a subnet can usually contain two less than total number of
        host IDs available. 0 is used for Network ID and 255 is normally reserved
        as a broadcast address for the subnet.

        * Let's say we're dealing with our old friend 9.100.100.100 with a subnet
        mask of 255.255.255.224. Since that subnet mark represents 27 ones followed
        by 5 zeroes, a quicker way is with the notation /27. Now the entire IP
        address and the subnet mask can be written as 9.100.100.100/27.

        * Subnet mask is a way for a computer to use and operators to determine if an IP address
        exists on the same network.

        * Once an AND operation is performed on the IP address and the Subnet mask,
        the network ID would be the result.

* Two of the most important operators are AND and OR.

* In computer logic, a 1 represents true, and a 0 represents false.

* To demarcate something means to set something off.

* Demarcation Point

    * To describe where one network or system ends and another one begins.

* CIDR

    * The slash notation is also known as CIDR notation.

    * In previous model, we relied on network ID, subnet ID, and host ID to deliver
    an IP datagram to the correct location. With CIDR, the network ID and subnet IDs
    are combined into one.

## **Routing**

* Router

    * A network device that forwards traffic depending on the destination address
    of that traffic.

    * Basic Routing:

        1- Receive data packet

        2- Examines the destination IP address.

        3- Looks up IP destination network in routing table.

        4- Forwards traffic to destination.

* Routing Table

    * The most basic routing table has these 4 columns:

        - Destination Network: would contain a row for each network that the router
        knows about. (CIDR notation).

            * A routing table will generally have a catchall entry, that matches
            any IP address that it doesn't have an explicit network listing for.

        - Next Hop: this is the IP address of the next router that should receive
        data intended for the destination network in question.

        - Total Hops: for each next hop, and each destination network, the router
        will have to keep track of how far away the destination address currently is.
        That way, when it receives updated information from neighboring routers, it
        will know about the best path or if a new better path is available.

        - Interface: the router also has to know which of its interfaces it should
        use for traffic matching the destination network out of.

* Routing Protocols

    * These are special protocols that routers use to speak to each other in order
    to share what information they might have.

    * Routing protocols fall into two main categories:

        - Interior gateway protocols: Are further split into two categories:

            - Link state routing protocols

                * Link state protocols got their name because each router advertises
                the state of the link of each of its interfaces.These interfaces can be
                connected to other routers or they could be direct connections to networks.

                * The information about each router is propagated to every other router
                on the autonomous system. Each router then uses this much larger set of
                information and runs complicated algorithms against it to determine
                what the best path to any destination network might be.

                * Link state protocols require both more memory in order to hold all of
                this data and also much more processing power.

            - Distance vector protocols

                * Older standard, A router using this protocol, basically just takes
                its routing table, which is a list of every network known to it and
                how far away these networks are in terms of hops. Then the router
                sends this list to every neighboring router, which is basically every
                router directly connected to it.

                * With a distance vector protocol, routers don't really know that
                much about the total state of an autonomous system.

                * In a computer science, a list is known as a vector.

            * Used by routers to share information within a single autonomous system.

            * Autonomous system: A collection of networks that all fall under the
            control of a single network operator.

        - Exterior gateway protocols

            * These are used to communicate data between routers representing the
            edges of an autonomous system.

            * At the highest levels, core internet routers need to know about
            autonomous systems in order to properly forwarded traffic.

            * Since autonomous systems are known and defined collections of networks,
            getting data to the edge router of an autonomous system is the number
            one goal of core internet routers.

            * Internet Assigned Numbers Authority (IANA): A non-profit organization
            that helps manage things like IP address allocation. Along with managing
            IP address allocation, the IANA is also responsible for ASN, or Autonomous
            System Number allocation.

            * Autonomous System Number: Numbers assigned to individual autonomous
            system. They're 32-bit addresses and they're referred to as just a single
            decimal number, there are two reasons for this:

                - IP address need to be able to represent a network ID portion and
                a host ID portion for each number.An ASN, never needs to change in
                order for it to represent more networks or hosts. Its just the core
                internet routing tables that need to be updated to know what the ASN
                represents.

                - ASNs are looked at by humans, far less often, than IP addresses are.


* The most common distance vector protocols are:

    - Routing Information Protocol (RIP)

    - Enhanced Interior Gateway Routing Protocol (EIGRP)

* The most common link state protocol is Open Shortest Path First (OSPF).

* In terms of exterior gateway protocols, there is only one in use today. This
standard is known as BGP or Border Gateway Protocol.

* RIP

    * Employs the hop count as a routing metric. RIP prevents routing loops by
    implementing a limit on the number of hops allowed in a path from source
    to destination. The largest number of hops allowed for RIP is 15, which limits
    the size of networks that RIP can support.

    * RIP implements the split horizon, route poisoning and holddown mechanisms
    to prevent incorrect routing information from being propagated.

    * In most networking environments, RIP is not the preferred choice for routing
    as its time to converge and scalability are poor compared to EIGRP, OSPF, or IS-IS.
    However, it is easy to configure, because RIP does not require any parameters
    unlike other protocols.

    * RIP uses the User Datagram Protocol (UDP) as its transport protocol, and is
    assigned the reserved port number 520.

    * All RIP messages exchanged between routers are encapsulated in a UDP segment.

    * RIP Messages:

        - Request Message: asking a neighboring RIPv1 enabled router to send its
        routing table.

        - Response Message: carries the routing table of a router.

    * The routing information protocol uses the following timers as a part of its
    operation:

        - Update Timer: controls the interval between two gratuitous response messages.
        By default the value is 30 seconds. The response message is broadcast to all
        its RIP enabled interface.

* EIGRP

    * Stands for Enhanced Interior Gateway Routing Protocol which is an advanced
    distance-vector routing protocol that is used on a computer network for automating
    routing decisions and configurations. It was first developed by Cisco and then
    became an open standard with informational status as RFC7868 in 2016.

    * It is used on a router to share routes with other routers within the same
    autonomous system. Unlike other well known protocols, EIGRP only sends incremental
    updates, reducing the workload on the router and the amount of data that needs
    to be transmitted.

    * Almost all routers contain a routing table that contains rules by which traffic
    is forwarded in a network. If the router does not contain a valid path to the
    destination, the traffic is discarded. EIGRP is a dynamic routing protocol by
    which routers automatically share route information.

    * In addition to routing table, EIGRP uses the following tables to store information:

        - Neighbor Table: Keeps a record of the IP addresses of routers that have a
        direct physical connection with this router. Routers that are connected
        to this router indirectly, through another router, are not recorded in this
        table as they are not considered neighbors.

        - Topology Table: It stores routes that it has learned from neighbor routing
        tables. Unlike a routing table, the topology table does not store all routes
        but only routes that have been determined by EIGRP.

    * Some features of EIGRP:

        - Support for CIDR and variable length subnet masking. Routes are not summarized
        at the classful network boundry unless auto summary is enabled.

        - Support for load balancing on parallel links between sites.

        - The ability to use different authentication passwords at different times.

        - MD5 and SHA-2 authentication between two routers.

        - Send topology changes, rather than sending the entire routing table when
        a route is changed.

        - Periodically checks if a route is available, and propagates routing changes
        to neighboring routers if any changes have occured.

        - Runs separate routing processes for IP, IPv6, IPX and AppleTalk, through
        the use of Protocol-Dependent Modules (DPM).

        - Backward compatibility with the IGRP routing protocols.

* OSPF

    * Called Open Shortest Path First is a routing protocol for IP networks. It uses
    a link state routing (LSR) algorithm and falls into the group of Interior Gateway
    Protocols, operating within a single autonomous system. The updates for IPv6
    are specified as OSPF version 3 in RFC 5340 in 2008. it also supports CIDR.

    * OSPF is widely used IGP in large enterprise networks. IS-IS another LSR-based
    protocol, is more common in large service provider networks.

    * Operation: It implements Dijkstra's algorithm, also known as shortest path first.
    OSPF was developed so that the shortest path through a network is calculated based
    on the cost of the route, taking into account bandwidth, delay and load. It maintains
    link state databases, which are network topology maps. The state of a given route
    is the cost, and OSPF allows every router to calculate the cost of routes to the
    given reachable destination. Unless the administrator has made a configuration,
    the link cost of a path connected to a router is determined by the bit rate of
    the interface.

    * A router interface with OSPF then advertises its link cost to neighboring routers
    through multicast, known as hello procedure. This process of flooding the network
    with link state information is known as synchronization.

    * OSPF Areas: An OSPF network can be divided into multiple logical groupings of
    hosts and networks known as areas, which maintain a separate link state database
    that can be summarized with the rest of network. Thus, the topology is unknown to
    the ouside area, which reduces the routing traffic between parts of an autonomous
    system. These areas are identified uniquely with 32-bit numbers that are totally
    independent of IP addresses but in a familiar form.

        - Backbone Area: The backbone area (also known as area 0 or area 0.0.0.0) forms
        the core of an OSPF network. All other areas are connected to it, either directly
        or through other routers. Inter-area routing happens via routers connected to the
        backbone area and to their own associated areas. It is the logical and physical
        structure for the 'OSPF domain' and is attached to all nonzero areas in the OSPF
        domain. The backbone area is responsible for distributing routing information between
        nonbackbone areas. All OSPF areas must connect to the backbone area. This connection,
        however, can be through a virtual link.

        - Stub Area: A stub area is an area which does not receive route advertisements
        external to the AS and routing from within the area is based entirely on a default
        route. An ABR deletes type 4, 5 LSAs from internal routers, sends them a default
        route of 0.0.0.0 and turns itself into a default gateway. This reduces LSDB and
        routing table size for internal routers.

        - Not So Stubby Area (NSSA): A not-so-stubby area (NSSA) is a type of stub area that
        can import autonomous system external routes and send them to other areas, but still
        cannot receive AS-external routes from other area.

        - Totally Stubby Area (TSA): this area does not allow summary routes in addition to
        not having external routes, that is, inter-area (IA) routes are not summarized into
        totally stubby areas. The only way for traffic to get routed outside the area is a
        default route which is the only Type-3 LSA advertised into the area. Occasionally, it
        is said that a TSA can have only one ABR.

        - NSSA totally stubby area: is an NSSA that takes on the attributes of a TSA, meaning
        that type 3 and 4 summary routes are not flooded into this type of area. It is also possible
        to declare an area both totally stubby and not-so-stubby, which means that the area will receive
        only the default route from area 0.0.0.0, but can also contain an autonomous system boundary
        router (ASBR) that accepts external routing information and injects it into the local area,
        and from the local area into area 0.0.0.0. Redistribution into an NSSA area creates a special
        type of LSA known as type 7, which can exist only in an NSSA area. An NSSA ASBR generates this
        LSA, and an NSSA ABR router translates it into type 5 LSA which gets propagated into the OSPF domain.

        - Transit Area: A transit area is an area with two or more OSPF border routers and is used to pass
        network traffic from one adjacent area to another. The transit area does not originate this traffic
        and is not the destination of such traffic.

    * Router Types:

        - Internal Router: An internal router has all its interfaces belonging to the same area.

        - Area Border Router (ARB): An area border router is a router that connects one or more
        areas to the main backbone network. It is considered a member of all areas it is connected
        to. An ABR keeps multiple instances of the link-state database in memory, one for each area
        to which that router is connected.

        - Backbone Router (BR): A backbone router has an interface to the backbone area. Backbone
        routers may also be area routers, but do not have to be.

        - Autonomous System Boundary Router (ASBR): An autonomous system boundary router is a router
        that is connected by using more than one routing protocol and that exchanges routing information
        with routers autonomous systems. ASBRs typically also run an exterior routing protocol (e.g., BGP),
        or use static routes, or both. An ASBR is used to distribute routes received from other, external
        ASs throughout its own autonomous system. An ASBR creates External LSAs for external addresses and
        floods them to all areas via ABR. Routers in other areas use ABRs as next hops to access external
        addresses. Then ABRs forward packets to the ASBR that announces the external addresses.

* BGP

    * Border Gateway Protocol is a standardized exterior gateway protocol designed to exchange routing
    and reachability information among autonomous systems (AS) on the Internet. It is classified as a
    path-vector protocol and makes routing decisions based on paths, network policies, or rule-sets
    configured by a network administrator and is involved in making core routing decisions.

    * It may be used inside an autonomous system as iBGP (internal) or over internet as eBGP (external).

    * Operation:

        - BGP neighbors, called peers, are established by manual configuration among routers to create a
        TCP session on port 179. A BGP speaker sends 19-byte keep-alive messages every 60 seconds to maintain
        the connection. Among routing protocols, BGP is unique in using TCP as its transport protocol.

        - Routers on the boundary of one AS exchanging information with another AS are called border or edge
        routers or simply eBGP peers and are typically connected directly, while iBGP peers can be interconnected
        through other intermediate routers. Other deployment topologies are also possible, such as running eBGP
        peering inside a VPN tunnel, allowing two remote sites to exchange routing information in a secure and
        isolated manner.

        - How routes are propagated can be controlled in detail via the route-maps mechanism. This mechanism consists
        of a set of rules. Each rule describes, for routes matching some given criteria, what action should be taken.
        The action could be to drop the route, or it could be to modify some attributes of the route before inserting
        it in the routing table.

    * BGP4 is standard for Internet routing and required of most Internet service providers (ISPs) to establish routing
    between one another. Very large private IP networks use BGP internally.

* RFC is a Request for Comment that is used for keeping the internet running to agree
upon the standard requirements to do so. RFC 1918, outlined a number of networks that
would be defined as non-routable address space.

* Non-routable Address Space

    * Is a range of IPs set aside for use by anyone that cannot be routed to.

    * RFC 1918 defined these three ranges of IP that will never be routed anywhere
    by core routers.

    * The primary three ranges of non-routable address space are:

        - 10.0.0.0/8

        - 172.16.0.0/12

        - 192.168.0.0/16

    * Interior gateway protocols will route these address spaces.

* RFC

    * An RFC would be published, people would leave comments on, eventually a
    consensus would be formed, and a new standard would be developed.

    * Over many decades, RFCs have come to belong to the Internet Engineering Task
    Force (IETF), which is an open community charged with developing and maintaining
    the standards that required for the internet to continue to operate.

* Summary

    * ARP stands for Address Resolution Protocol.

    * An ARP broadcast is sent to the special MAC address FF:FF:FF:FF:FF:FF.

    * The entirety of a packet at one layer becoming the payload sections at another
    layer is known as encapsulation.

    * The process of taking a large network and splitting it up into many individual
    and smaller subnetworks is known as subnetting.

    * A subnet ID is calculated via a subnet mask.

    * A network device that knows how to forward data along to other networks is
    known as a router.

    * TTL stands for Time To Live.

    * Interior gateway protocols are used by routers in order to share information
    within a single autonomous system.

    * Ranges of IP addresses that anyone can use for their internal network as
    known as Non-routable Address Space.

    * A demarcation point is where one network ends and another begins.
    
