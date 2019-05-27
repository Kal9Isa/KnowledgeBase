# **Networking Services**

## **Name Resolution**

* Why Do We Need DNS?

    * Domain Name System (DNS): A global and highly distributed network service
    that resolves strings of letters into IP addresses.

        * Domain Name: The term we use for something that can be resolved by DNS.

* The Many Steps of Name Resolution

    * The process of using a DNS to convert a domain name into an IP address is
    known as name resolution.

    * The information below need to be specifically configured at a node on the
    network:

        - IP address

        - Subnet mask

        - Gateway for a host

        - DNS Server

    * There are five primary types of DNS servers:

        1- Caching name servers: Purpose is to store known domain name lookups
        for a certain amount of time.

            - Generally provided by ISP or local network.

        2- Recursive name servers: Perform full DNS resolution requests.

            * To perform a full recursive resolution, the first step is always
            to contact a root name server, there are 13 total authorities with
            root name servers and they're responsible for directing queries towards
            the appropriate TLD name server. These used to be restricted to regions
            but now they're available world-wide thanks to Anycast.        

            * The root servers respond to a DNS lookup with the TLD name server
            that should be queried.

            * The TLD name server will respond again with what Authoritative name
            server to contact.

            * Finally the DNS lookup can be redirected at the authoritative server
            for the desired domain name which would finally provide the actual IP of the
            server in question.

        3- Root name servers: 13 authorities that provide root name lookups as a
        service.

            * Anycast: A technique that's used to route traffic to different
            destinations depending on factors like location, congestion, or link
            health.

        4- TLD name servers: A global distribution of anycast accessible servers
        responsible for each TLD.

            * Top-Level Domain (TLD): Represents the top of the hierarchical DNS
            name resolution system. It is the last part of any domain name, like
            .com, .ir, .org, etc.

        5- Authoritative name servers: Are responsible for the last two parts
        of any domain name which is the resolution at which a single organization
        may be responsible for DNS lookup.

    * Any given DNS server can fulfill many of these roles at once.

    * All domain names in the global DNS system have a TTL, which in modern days
    has dropped from a day or so to only a few hours or minutes.

    * Time To Live (TTL): A value, in seconds, that can be configured by the owner
    of a domain name for how long a name server is allowed to cache an entry before
    it should discard it and perform a full resolution again.

    * Every device can have its own temporary DNS cache as well.

* DNS and UDP

    * DNS is an example of application layer service that uses UDP for transport
    layer. Reasons are:

        - UDP is connectionless, which means there is no setup or tear down of the
        connection. so much less traffic needs to be transmitted as well.

        - A single DNS request and response can usually fit into a single UDP
        datagram.

        - DNS can generate alot of traffic.

    * To handle errors, if there is no responses, the DNS resolver just asks
    again.

    * In situations that the DNS lookup doesn't fit into one UDP datagram, a DNS
    server would respond with a packet explaining that the response is too large.
    The DNS client would then establish a TCP connection in order to perform the
    lookup.

## **Name Resolution in Practice**

* Resource Record Types

    * The most common resource record is known as an A record.

    * A record: Is used to point to a certain domain name at a certain IPv4 address.

        * In the most basic scenario, an A record is configured for a single
        domain name. But a single domain name can have multiple A records. This
        allows for a technique known as DNS round robin to balance traffic across
        multiple IPs.

        * Round robin: A concept that involves iterating over a list of items one
        by one in an orderly fashion. The hope is that it ensures a fairly equal
        balance of each entry on the list that's selected.

        * To use this technique, for example we configure four A records for
        www.microsoft.com at the authoritative name server for the microsoft.com
        domain. Let's say we use 10.1.1.1, 10.1.1.2, 10.1.1.3, 10.1.1.4. Now when
        the DNS resolver performs a lookup of microsoft.com, all 4 IPs would be
        returned in the same order as we configured. The next lookup gets the entries
        with a different order which means 10.1.1.2 is now the first and 10.1.1.1 has
        moved to last position.
    * AAAA - Quad A record: Is becoming more popular, similar to A record except that it
    returns an IPv6 address.

    * CNAME record: Is used to redirect traffic from one domain to another. They're
    really useful because they ensure you only have to change the canonical IP address
    of a server in one place.

        * For example, by configuring a CNAME record for microsoft.com that resolves
        to www.microsoft.com, the resolving client would know then to perform another
        resolution but this time with www.microsoft.com and use that IP address for
        contact.

    * MX - Mail Exchange record: Is used in order to deliver e-mail to the correct
    server. Ensures that the email gets delivered to a company's mail server, while
    other traffic goes to the corresponding servers.

    * SRV - Service record: Similar to MX, but used to define the location of various
    specific services. It can be defined to return the specifics of many different
    service types.

        * For example, SRV records are often used to return the records of services
        like CalDAV, which has a calendar and scheduling service.

    * TXT - Text record: Intended to be used for associating some descriptive text
    with a domain name for human consumption, But now it's used to convey additional
    data intended for other computers to process.

        * It's often used to communicate configuration preferences about network
        services that you've entrusted other organizations to handle for your domain.

        * For example, it's common to use TXT reccord to convey additional information
        to an email as a service provider, which is a company that handles email delivery.

    * NS or SOA records: Used to define authority information about DNS Zones.

* Anatomy of a Domain Name

    * Any given domain name has 3 primary parts. For example www.google.com:

        - .com -> TLD or Top level domain, which is the last part of a domain name.

            * There are only a certain restricted number of defined TLDs available.

            * Administration and definition of TLDs is handled by a non-profit
            organization known as ICANN (the Internet Corporation for Assigned Names
            and Numbers). ICANN along with IANA help control both the global IP spaces,
            along with the global DNS system.

        - google -> referred to as domain, Used to demarcate where control moves
        from a TLD name server to an authoritative name server.

        - www -> known as Subdomain, sometimes referred to as a hostname, if it's
        been assigned to only one host.

    * Fully Qualified Domain Name (FQDN): When you combine all of these three parts
    together, you have a FQDN.

        * While it costs money to officially register a domain with a registrar, subdomains
        can be freely chosen and assigned by anyone who controls such a registered
        domain.

        * Registrar: A company that has an agreement with ICANN, to sell unregistered
        domain names.

        * You can have alot of subdomains for example:

            - host.sub.sub.subdomain.domain.com is totally valid.

        * DNS can technically support up to 127 levels of domains in total for a
        single fully qualified domain name.

        * Each individual section in a domain name, can be 63 characters long and
        a complete FQDN is limited to a total of 255 characters.

* DNS Zones

    * An authoritative name server is actually responsible for a specific DNS zone,
    on top of responding to name resolution requests for specific domains.

    * DNS zones: Allow for easier control over multiple levels of a domain.

        * DNS zones is a hierarchical concept, The root name servers are responsible
        for the root zones, each TLD name server is responsible for the zone covering
        its specific TLD and so on. Both of these name servers are also authoritative.

        * Zones don't overlap, for example the administrative authority of the TLD
        name server doesn't encompass the google.com domain. instead it ends at the
        authoritative server responsible for the google.com.

        * Usually each subdomain requires its own DNS zone.

        * Zone Files: Simple configuration files that declare all resource records
        for a particular zone. They're configured through what's known as zone files.

            * So a zone file has to contain an Start of Authority (SOA) resource record
            declaration. This declares the zone and the name of the name server that
            is authoritative for it.

            * NS record: Indicate other name servers that might also be responsible for
            this zone.

            * Besides SOA and NS records, you'll find all other record types like
            A, Quad A or CNAME along with configurations such as default TTL value
            for the records served by the zone in the zone files.

        * Reverse Lookup Zone Files: These let DNS resolvers ask for an IP and
        get the FQDN associated with it returned.

            * PTR - Pointer Resource record: Resolves an IP address to a name.

            * Sometimes there would be Reverse lookup zone files and they contain
            PTR declarations.

        * Having multiple servers in place for DNS is pretty common.

    * A domain name can point to one IP, many IPs or Many domains can point to the
    same IP.

## **Dynamic Host Configuration Protocol**

* Overview of DHCP

    * DHCP: An application layer protocol that automates the configuration process
    of hosts on a network.

        - With this server setup, a computer queries DHCP server when it connects
        to the network and receive all the configurations in one go.

        - For network equipment, static IP is pretty important.

        * Dynamic Allocation: A range of IP addresses is set aside for client devices
        and one of these IPs is issued to these devices when they request one.

        * Automatic Allocation: A range of IP addresses is set aside for assignment
        purposes. The difference here is that the DHCP server is asked to keep
        track of which IPs it's assigned to certain devices in the past so it will
        assign them the same IP each time, if possible.

        * Fixed Allocation: Requires a manually specified list of MAC address and
        their corresponding IPs.

            - If the MAC address is not found, the DHCP server may fall back to
            automatic or dynamic allocation or it might refuse to assign an IP
            altogether.

        * DHCP discovery can  be used to configure much more many things for each
        host on a network like NTP servers or etc.

        * Network Time Protocol (NTP) servers: Used to keep all computers on a
        network synchronized in time.

* DHCP in Action

    * DHCP Discovery: The process by which a client configured to use DHCP attempts
    to get network configuration information. This process has 4 steps:

        1- DHCPDISCOVER: Since the machine doesn't ahve an IP and doesn't know the
        IP od DHCP server, a specially crafted broadcast message is formed instead.

            * DHCP listens on UDP port 67 and DHCP Discovery message are always
            sent from UDP port 68.

        * So DHCPDISCOVER message is encapsulated in a UDP datagram and is sent
        with source address of 0.0.0.0:68 to 255.255.255.255:67. Next DHCP would
        examine his own configuration and prepare a response.

        2- DHCPOFFER: This message is then sent to 255.255.255.255:68 with source
        address  of its own on port 67. The original client would know its intended
        for it since it has its MAC address specified.

            * Technically a client can reject this offer from DHCP server if its
            set to accept IPs of certain range.

        3- DHCPREQUEST: Then the client would respond to DHCP server to request an
        IP.

        4- DHCPACK: Is sent from server to the client, containing all the configurations
        needed for the client's network stack to configure itself.

    * All of this configuration information is known as a DHCP lease which includes
    an expiration date, that can range from days to minutes. Once expired, the
    client needs to perform the DHCP Discovery all over again. Once client gets
    disconnected from the network, it releases the lease and DHCP server returns
    the IP to its available IP pool.

## **Network Address Translation**

* Basics of NAT

    * NAT: A technology that allows a gateway, usually a router or firewall, to
    rewrite the source IP of an outgoing IP datagram while retaining the original
    IP in order to rewrite it into the response.

        - It's a technique rather than a standard, so it can vary from OS to OS or
        from vendor to vendor.

        - It can be used for security measures, or to preserve IPv4 address space.

    * IP Masquerading: To hide IP of a computer inside a network from the outside.

    * One to Many NAT: The technique that all the hosts on a network send their
    data to the router and it's translated as its own data.

* NAT and the Transport Layer

    * Port Preservation: A technique where the source port chosen by a client is
    the same port used by the router.

        - However in this technique, sometimes two computers chose the same port
        at the same time, in this case, router randomly selects an unused port
        to use instead.

    * Port Forwarding: A technique where specific destination ports can be configured
    to always be delivered to specific nodes.

        - This technique allows for IP Masquerading and it also simplifies how
        external users might interact with lots of services.

* NAT, Non-Routable Address Space and the Limits of IPv4

    * The IANA has been primarily responsible with assigning address blocks to the
    5 different Regional Internet Registries (RIRs)

        - AFRINIC: Africa

        - ARIN: US, Canada, Caribbean

        - APNIC: Asia, Australia, New Zealand

        - LACNIC: Central and South America, Other part of Caribbean

        - RIPE: Europe, Middle East, Russia, Central Asia.

    * Port Forwarding is the technique that allows for inbound traffic through NAT.

## **VPNs and Proxies**

* Virtual Private Networks

    * VPN: A technology that allows for the extension of a private or local network
    to hosts that might not be on that local network.

        - VPNs are tunneling protocols meaning, they provision access to something
        not locally available.

        - It can be used for remote access to internal resources, or they can be
        used to establish Site-to-Site connectivity where two gateways use a VPN
        tunnel to transfer data back and forth.

        - The VPN tunnel would provision the client with a virtual interface, with
        an IP that matches the address space of the network that established a VPN
        connection.

        - Most VPNs encrypt the payload section of the transport layer which contains
        a whole network stack to use in the destination.

        - VPNs just like NAT are a technology ant not a protocol, so it can vary
        from platform to platform.

    * Two-factor authentication: A technique where more than just a username and
    password are required to authenticate.

* Proxy Services

    * Proxy Service: A server that acts on behalf of a client in order to access
    another service. They offer:

        - Anonymity

        - Security

        - Content filtering

        - Increased performance

        * Web proxies: Are specifically built for web traffic.

        * Before proxy servers where used in organizations to allow them to retrieve
        web pages and cache them so if requested again, it would be served faster.

        * By using a web proxy, an organization can direct all web traffic to it,
        allow the proxy to inspect what data is being requested, and then allow or
        deny this request depending on what site is being requested.

    * Reverse Proxy: A service that might appear to be a single server to external
    clients, but actually represents many servers living behind it.

        * Popular websites, use reverse proxy as a load balancing technique just
        like DNS round robin, to direct the incoming traffic through proxy and
        distribute it between different servers.

        * Some websites use proxies to add in an extra decryption or encryption
        hardware before to free up the servers processing power to just serve the
        requests.

    * In general, proxies are any server that act as an intermediary between a client
    and another server.

* Summary

    * A technique that's used to route traffic to different destinations, depending
    on factors like location, congestion, link health is known as Anycast.

    * A concept that involves iterating over a list of items one by one in an
    orderly fashion is known as Round robin.

    * A DNS record that's used to redirect all traffic from one domain to another
    is known as a CNAME record.

    * Administration and definition of TLDs are handled by a non-profit organization
    known as ICANN.

    * A PTR record is responsible for resolving an IP to a domain name.

    * Along with an IP address, a subnet mask, and a name server, the other thing
    required for a computer to operate on a network is gateway.

    * When a range of IP addresses is set aside for client devoces, and one of these
    IPs is issued to these devices when they request one, this is known as dynamic
    allocation.

    * The final step of the DHCP Discovery process i known as DHCPACK.

    * When NAT hides the source IP of an originating device, that is known as
    IP masquerading.

    * A service that might appear to be a single server to external clients, but
    actually represents many servers living behind it, is known as a reverse proxy.
