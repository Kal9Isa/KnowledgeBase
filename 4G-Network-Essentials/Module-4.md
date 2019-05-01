# **Management of Data Flow**

## **Principle of Encapsulation and Tunnels**

* Fixed Network

    * The IP address (the prefix) is used for routing

    * A "machine" which changes location, changes prefix (therefore IP address).

    * A sub-network is characterized by a prefix (subnet mask).

    * Inside an interconnection network, only prefix is used for routing.

* Principle of Encapsulation

    * Same prefix for all subscribers of a mobile network.

    * Routing from the internet to PGW.

    * Encapsulation = putting the "user" IP packet in another IP packet.

    * Encapsulation is used to route data from Internet to PGW, SGW, eNB and thus to the terminal
    in the correct subnet. Encapsulation in eNB occurs with placing IP packets in transport blocks
    and sending it to the corresponding RNTI of the destination terminal.

* Encapsulation and the Use of Tunneling

    * Independently of the network topology used, the packet leaves the PGW and arrives at the SGW
    as if a tunnel was established between the PGW and SGW thanks to encapsulation.

    * To make it clear, IP packets that should be transmitted to a mobile terminal are systematically
    routed to the PGW. They're then put in other IP packets within 4G core network. This operation is 
    called encapsulation. These packets are transmitted hop by hop to the terminal as if they were in a
    tunnel from the PGW to SGW to eNB where the terminal is.

## **The GTP Protocol**

* Reminder on Encapsulation

    * The PGW's purpose is to send the packet to SGW.

    * The PGW doesn't care what happens to the packet past SGW.

    * Encapsulation = putting the "user" IP packet in another IP packet.

* Need for a Layer 4 Protocol between Intermediary Nodes

    * Need for a transport protocol (coherent with the IP stack of all equipment)

        - TCP? Too complex

            - Retransmission of lost packets

            - A complex congestion control

        - UDP? Simple, Reliability (when needed) is managed by endpoints (UE, Server).

    * Use of UDP

        - Between SGW and PGW

        - Between SGW and eNodeB

    * Addition of a new layer (new protocol, new format)

        - GTP: GPRS Tunneling Protocol

* Place of GTP-U in the Protocol Stack and its Principle Function

    * GTP-U: Transporting user data with established tunnels (U = User plane).

    * Only the GTP-U header is analyzed to process the packet (forwarding, managing QoS)

    * Protocol Stack:   User IP | GTP-U | UDP | IP 

    * GTP-U

        - On the S1-U interface between the eNodeB and SGW.

        - On the S5/S8 interface between SGW and PGW.

* Summary

    * User IP packets are put in GTP-U packets, which are themselves put in UDP packets 
    transported in IP packets. The protocol stack between the SGW and PGW, and between 
    SGW and eNodeB includes IP/UDP/GTP-U/IP.

* Tips

    * IP packet remains unchanged during its transfer within the EPC network. The destination 
    address is still the address of the mobile terminal.

## **Identifying and Managing Tunnels**

* Managing Multiple Tunnels

    * Tens of millions of users per network

        - Not all are on the same eNB.

        - Not all are serviced by the same SGW.

    * Several tunnels possible for users

    * Need for very rapid processing

* Numbering of Tunnel Endpoints

    * TEID = Tunnel Endpoint IDentifier

    * Each node affected by a tunnel gives a unique identifier to the local end of the tunnel.

    * Therefore, each tunnel has 2 identifiers.

    * The TEID is coded on 32 bits in GTP (4 bytes).

* 1st Possibility: Put the TEID Allocated by the Sender in the GTP Header

    * Complex processing

        - The receiver has to know the TEID used by the body at the other end of the tunnel

        - For that, it needs to analyze the TEID and the source address.

        - => We need a different method.

* 2st Possibility: Put the TEID Allocated by the Recipient in the Header

    * The sender has to know the TEID used by the body at the other end.

    * Slight increase in complexity for the sender.

    * Processing much simpler for recipient.

* 3rd Possibility: Put Both TEIDs

    * Same processing as when only the recipient TEID is there.

    * Header is a bit longer.

    * Advantage: if equipment wants to change the value of TEID, it can do so without extra
    signaling.

    * This sholution not used for GTP but used between eNB and MME.

* Summary

    * A TEID on each end of each tunnel

    * TEID allocated by each node: locally unique.

    * The GTP header of each packet includes the TEID on the receiver side.

* Tips

    * Each tunnel is identified by a pair of numbers each allocated by the device at the end
    of this tunnel.

    * The TEID is coded over 32 bits and is placed in the GTP header. The main role of GTP is 
    to handle TEID.

    * We must be able to handle over 256 tunnels on a node of the 4G network.

    * A packet sent in a tunnel from the SGW to PGW. The TEID that is placed in the GTP header
    is the one allocated by the PGW.

    * The TEID put in the GTP header is always the TEID of the destination.

## **Transmitting Packets in a Tunnel**

* Initialization of a Tunnel

    * Exchange of control messages to establish the tunnel: GTP-C protocol.

    * A the end of the exchange, each end knows the TEID allocated by the opposite body.

    * Process:

        - A device sets up a tunnel with a new locally unqiue chosen TEID by sending a message to
        the other device.

        - The device on the other end chooses a new locally unique TEID. Stores the sender's
        address and the received TEID and the link.

        - Then an ACK message containing its TEID and sender's TEID is sent back.

        - The initiator store's the sender's address, the received TEID and the link from the ACK.

        - The tunnel is up.

    * Each device would have a table that includes (its own TEIDs, peer's address and its corresponding 
    TEID, actions to perform upon receiving packets and details). Like lookup table in routing.

    * The action of retransmission is called Forwarding.

* Use of Data Tunnels in the Core of the EPC Network

    * User Plane

        - All the mechanisms and protocols that are directly related to the transmission of user data
        and the messages/packets/frames containing user data (as seen from the EPC network).

        - Remark: A connection request to a web site, the set-up of a phone call, ... are seen by the 
        EPC network as being part of the user plane.

    * For each tunnel, a pair of TEIDs.

    * Many data tunnels

        - Various tunnels to manage levels of QoS.

        - The association of a data tunnel and a QoS level (perhaps best effort) is called a data bearer.

## **S1-AP Connection**

* One MME is responsible for several million terminals.

* Managing the dialogue between the UE and the MME

    * Native approach: place the mobile identity in every message received or sent by MME.

        - IMSI = problem of confidentiality, GUTI => what if the GUTI changes?

* S1-AP Protocol

    * Every terminal with a radio connection has its own RNTI (within one eNB) which is allocated by eNB.

    * Signaling radio bearer identified by RNTI + Logical Channel Identifier (LCID).

    * Specification of a connection-oriented protocol between the eNB and the MME. One connection per UE
    identified by a pair of connection IDs.

    * Association in the eNB: RNTI + LCID <-> Connection identity (S1-AP).

* Example of the Transimission of a Signaling Message from a Terminal to the MME

    * Imagine a terminal, an eNB, a MME, an established radio connection, a S1-AP connection that we presume
    has been established. Each connection is referenced at each endpoint by an identifier. When the terminal
    sends a message, for example a specific request to the network, this message includes, in the header, the
    LCID value in a radio block associated with an RNTI corresponding to the cell phone. The eNB has in memory
    a lookup table. Each RNTI and LCID pair is associated with the local connection identifier and the connection
    identifier of the distant entity, in this case the MME as well as the IP address of the MME. This way when 
    the signaling message is retransmitted, by the eNB it includes the connection identifier on the eNB side.

    * The choice here was made to set both identifiers systematically in each message, in order to easily keep 
    the reference of a connection when a terminal is moving to a new cell.

* Summary

    * For each UE

        * Radio connection between the UE and the eNB

        * S1-AP connection

            - Between the eNB and the MME

            - Identified by a pair of connection ID

        * On each side (eNB, MME), the connection ID is unique.

* Tips

    * The S1-AP protocol operates between the eNB and the MME. It is connection-oriented and there are as many
    connections between an eNB and a MME as there are terminals connected in the cell. It enables direct signaling
    messages between the two entities.

    * Many eNBs are connected to the same MME. Several terminals can send requests in a very short amount of time
    in the same cell. To differentiate the message sent by different terminals, the RNTI of the subscriber is 
    specified on the radio channel and corresponds to a pair of connection identities on the S1 interface.

## **Establishing an S1-AP Connection**

* Example of Establishment of an S1-AP Connection (Attachment)

    * ![img]()

    * Let's presume, at this moment, that both RNTIs are confirmed. And take a look at the attachment
    to the network.

    * The messgae sent by a mobile terminal is an [EMM ATTACH REQUEST] which will be put in an 
    "RRCConnectionSetupComplete". This message is associated to a RNTI and a LCID. The eNB will choose
    the identity of the local S1-AP connection and send a "S1 AP INITIAL UE MESSAGE (ID1)".
    Due to the encapsulation mechanism it also contains the [EMM ATTACH REQUEST] which is issued by the
    terminal.

    * The MME will store the received value, choose its own connection identity and memorize the link between 
    the two IDs. The MME then sends back a message "S1 AP DOWNLINK NAS TRANSPORT (ID2, ID1)" with the two 
    connection identities and the response to the Attach Request which is [EMM AUTHENTICATION REQUEST] to verify
    that the terminal actually has the correct secret key.

    * What the eNB does is, it stores ID2 (chosen by MME) and also the link between the two IDs. It will also
    forward the message to terminal as "RRC DL INFORMATION TRANSFER [EMM AUTHENTICATION REQUEST]". For all the
    following messages the same process is applied.

    * Because these connection identities are numbered over 3 or 4 bytes, a very large number of simultaneous 
    connections are possible.

* S1-AP Protocol Functions

    * The S1-AP protocol permits:

        - The MME and the eNB to exchange general configuration messages.

        - The MME to send messages to an eNB to activate certain functions related to tunnel connection.

        - The eNB to signal state changes of a terminal to the MME.

        - Transporting messages exchanged between a terminal and the MME.

    * Each time a message is linked to a particular terminal

        - Presence in the header of a pair of connection identities (except fo the first message which only
        has one identity)

* Tips

    * For any type of exchange (attachment, detachment, service request, etc.), the S1-AP connection is 
      established at the beginning of the exchange since it's this connection that will enable:

        1- The messages sent by the terminal on the radio channel to be correctly forwarded by the eNB to
        the MME

        2- The messages sent by the MME to be correctly forwarded by the eNB to the terminal

    The operator is responsible for securing its eNB-MME links (IPSec or other mechanisms.)

    * Once the connection is established, that is to say from the transmission of an "S1AP Downlink
    NAS Transport" message in response to an "S1AP Initial UE" message, each device knows the 2 connection
    identifiers chosen by MME and eNB. The two identifiers are systematically added to the "S1AP Downlink
    NAS Transport" and "S1AP Uplink NAS Transport" messages.

## **Non Access Stratum and Global View of the Protocol Stack**

* The Control Plane

    * The control plane

        - All the protocols, mechanisms, and messages that enable the configuration of network (informatic or
          telecom) elements in order to permit the effective delivery of a communication service.

            - Signaling transport

        - Example: attachment to network, security exchanges, mobility management, routing, etc.

    * Dialogue between UE and MME

        - Exclusively in the control plane

    * Control

        - Mobility, security management => between UE and MME

        - Allocation of radio resources, establishment of connection => between UE and eNB

            - Messages, protocols, linked to radio technology.

* Non Access Stratum (NAS) vs, Access Stratum (AS)

    * NAS messages are exchanges between the terminal and the MME

        - They are relayed by the eNB without any analysis of their contents.

    * AS messages are exchanged between the terminal and eNB

        - Example: modification of the radio bearer

        - Includes all the messages related to the radio technology, to the establishment and management of 
        the radio connection.

    * LCID is used to distinguish between the user data and sginaling messages.

        - We use LCID = 2 for signaling messages from terminal to MME.

        - LCID = 0/1 is used for signaling messages between eNB and terminal. 0 for urgent and 1 for non-urgent
        messages.

* AS, NAS and S1-AP in the Protocol Stack

    * SCTP transport protocol: Stream Control Transmission Protocol

        - Reliable transport protocol but avoids unnecessary retransmissions.

        - Better adapted to message transport than TCP (stream-oriented)

    * S1-AP protocol, Application protocol

        - Management of messages between eNB and MME.

        - Messages related to the dialogue of a specific UE with the network.

    * NAS messages that are meant for MME and UE are transported via RRC protocol.

    * Two NAS protocols: 

        - EMM: Evolved Mobility Management

        - ESM: Evolved Session Management

    * Protocol Stack in UE: PHY | MAC | RLC | PDCP | RRC (AS) | EMM (NAS)| ESM (NAS)

    * Protocol Stack in eNodeB:

        - PHY | MAC | RLC | PDCP | RRC (AS)

        - PHY | DLL | IP | SCTP | S1-AP

        - S1-AP and RRC are used to relay NAS messages.

    * Protocol Stack in MME: PHY | DLL | IP | SCTP | S1-AP | EMM (NAS)| ESM (NAS)

* Control Tunnels and Bearers (Data Tunnel)

    * GTP Control = GTP-C

        - Messages necessary to establish, maintain, and release data tunnels.

        - Rests as well on the TEIDs (different values of TEIDs on the user plane)

        - Between the PGW, SGW and MME.

        - Protocol Stack of PGW, SGW and MME: PHY | DLL | IP | UDP | GTP-C

* Global View of the Control Protocol Stacks

    * ![img]()

* Global View of Protocol Stacks

    * ![img]()

* Sumamry

    * AS, NAS control messages and data packets are transported on different logical channels, 
    different LCIDs over the radio interface.

    * AS messages are processed by the eNB, NAS messages are forwarded by the eNB to MME on the
    S1-AP connections.

    * Data messages are sent through tunnels.

* Tips

    * All the fixed interfaces of the EPC network are based on IP. The S1-MME interface is between
    eNB and the MME. No user data goes through the MME because the MME is a deivce that only operates
    in the control plane.