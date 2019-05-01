# **Management of the Sporadic Nature of Data Flows**

## **Attachment and Detachment Procedures Revisited**

* Establishment of a Default Bearer

    * Permanent IP connectivity

        - As soon as the terminal is powered up, it requests the establishment of
        tunnels for IP connectivity.

    * Independently of the terminal's activity, there's an established bearer.

        - Default bearer

    * EPS Connectivity request procedure

        - Message included in the attachment message.

        - Attachment and establishment of connectivity realized simultaneously.

* Initital State

    * We have a notion of "state" which is memorized for each terminal. This state when
    attachment has not been made is called "EMM-deregistered", which means that the cellphone
    is not reachable; It could be powered down or in flight mode.

    * ![img]()

    * The process of Attachment:

        * When the UE tries attachment, it sends a "EMM ATTACH REQUEST (GUTI1, ESM PDN CONNECTIVITY 
        REQUEST (IPvx))" - AKA procedure (Authentication and Key Agreement) - the connectivity request
        means that the UE requests connectivity to the external IP network.

        * Then the S1-AP connection is established, MME analyzes the IPvx field and APN to determine the
        SGW and PGW for this terminal. Then it sends a "GTP-C CREATE SESSION REQUEST (IMSI, IPvx, APN)" to 
        the proper SGW and the message is forwarded by SGW to the right PGW.

        * On arrival a DHCP takes care of the IP allocation for the terminal. It's important to note that all
        the messages except for radio interface here include TEIDs. After assigning an IP address, a 
        "GTP-C CREATE SESSION RESPONSE (IP address)" is sent back to SGW to be forwarded to MME. Also the 
        S5/S8 bearer is established.

        * Upon receiving the response message from PGW, MME chooses a GUTI2 and sends a "EMM ATTACH ACCEPT (GUTI2, 
        ESM ACTIVATE DEFAULT EPS BEARER CONTEXT REQUEST (IP address))" back to the terminal.

        * Terminal stores the GUTI2 and the IP address and sends a "EMM ATTACH COMPLETE (ESM ACTIVATE DEFAULT 
        BEARER CONTEXT ACCEPT)" back to MME.

        * After receiving this request, MME sends a "GTP-C MODIFY BEARER REQUEST" to SGW to configure a data tunnel
        from SGW to corresponding eNB.

        * Finally, SGW sends back a "GTP-C MODIFY BEARER COMPLETE" request back to MME, and establishes a S1 bearer
    to the eNB.

* Detach Procedure

    * Terminal powered down

        - The terminal makes a detach request.

    * Release of all connections and tunnels.

    * The MME aswell as the SIM will retain the GUTI and the security keys.

    * The process of Detachment:

        * UE sends a "RRC UL INFORMATION TRANSFER [EMM DETACH REQUEST (GUTI2)]" to the eNB. Then as soon as the Radio bearer
        is dropped it can power down.

        * Following that, the eNB sends a "S1AP UPLINK NAS TRANSPORT [EMM DETACH REQUEST (GUTI2)]" to MME.

        * MME will release all the context but retains the GUTI and the security keys. After that sends a "GTP-C DELETE SESSION 
        REQUEST" to SGW and it will be forwarded to PGW.

        * PGW drops the S5/S8 bearer and sends back a "GTP-C DELETE SESSION RESPONSE" to SGW to be forwarded to MME.

        * Upon receiving the response, MME sends a "S1AP UE CONTEXT RELEASE COMMAND" to eNB and the eNB will release the
        radio connection (RNTI) and the radio bearer. Following that it sends a "S1AP UE CONTEXT RELEASE COMPLETE" to MME.

        * Then MME sends a "DIAM NOTIFICATION REQUEST (PGW and APN removed)" to HSS, to let it know that the terminal is
        unreachable. After that the S1 bearer is released and a "DIAM NOTIFICATION ANSWER" is sent from HSS to MME to acknowledge
        the terminal state.

* Tips

    * In 4G there are two different procedures:

        1- Network attachment, which consists of transferring the subscriber profile from HSS to the MME, establishing a secure 
        association and having a mobile handled by the MME.

        2- Connectivity request, which consists of requesting access to the IP data network, which implies having an IP address.
        (DHCP mechanism). This latter procedure is rather related to the PGW even if it involves the MME and the SGW.

    The two procedures are merged and performed upon power up. We can imagine that an operator can provide a service to have a
    permanent public address. Even in this case, the connectivity establishment procedure is performed.

    * The EMM-deregistered state corresponds to a mobile that has no access to the network. By analogy, it is equivalent to 
    a residential gateway powered down in a fixed network. A terminal in the EMM-Deregistered state is usually a powered-down
    terminal but it can also be a terminal for which the attachment has been refused by the network.

    * The EMM-Registered state corresponds to a mobile that is correctly attached to the network, which has a valid security
    association and which has an IP address.

## **Concept of ECM Connected and ECM Idle States**

* Permanent Connection in EPC

    * When a terminal powers up, establishment of a default bearer

        - An IP packet arriving from the network must be routed as quickly as possible.

        - An IP packet created by the terminal must be transmitted as quickly as possible (e.g. the user requests a web page)

    * When a terminal is used (transmission or reception of data by the UE)

        - Use of the RNTI for radio transmission.

        - Measurment of the power levels to verify that the UE is still in the cell.

    * When a terminal is not in use (user is reading the screen, no transmission or reception on the radio channel), do we 
      keep radio connection?

        - Necessary for the UE to transmit from time to time to verify that it is still in the cell.

        - RNTI reserved but not used. (16 bit in length, over 65000 available)

* Radio Inactivity Timer

    * Timer (in the eNodeB) set at the end of an exchange

        - RRC inactivity timer

    * When the timer runs out

        - The RRC connection is released.

        - The UE loses its RNTI.

* Release of the Radio Connection

    * If there is no radio transmission for a while, the radio connection is released.

    * Releasing the radio connection prevents the MME from knowing exactly which base station the UE is under.

    * At the same time that the radio connection is released:

        - The data tunnel between the eNodeB and the SGW is destroyed (S1-U tunnel)

        - The S1-AP connection is destroyed.

* Definition of the ECM-Idle State

    * In ECM-IDLE state, the terminal stays attched to the network (it keeps the IP address) but is no longer 
    really connected to the radio access network.

* Definition of ECM-Connected State

    * In the ECM-Connected state, the radio connection and all tunnels and connections are estabkished. (RNTI is activated.)

* Summary

    * Tunnels and bearers are always maintained between the PGW, SGW and the MME.

    * A timer is managed by the eNB in case of inactivity of the UE.

    * The radio bearers, the S1-AP connection and S1 bearer are released.

    * There are frequent switches between the ECM-IDLE and ECM-Connected states.

* Tips

    * The radio connection is maintained as long as data is exchanegd between the terminal and the network, either on the uplink or downlink.

    * The radio connection is released when there are no exchanges on the radio channel during a few seconds to a few dozen seconds typically. 
    This criterion takes into account both downlink and uplink transmissions. In practice a one-way data transfer triggers the transmission of 
    acknowledgements the other way: from the network and lower layers points of view, there are always both downlink and uplink transmission if 
    we look at the radio channels during several hundred ms. 

## **Passing to Standby Mode After a Long Period of Inactivity**

* S1 Release Procedure upon Inactivity

    * The process:

        * After user inactivity on the radio channel and the timer on eNB running out, eNB sends a "S1AP UE CONTEXT RELEASE REQUEST (cause = User 
        Inactivity)" to MME.

        * Then MME sends a "GTP-C RELEASE ACCESS BEARERS REQUEST" to SGW and gets a "GTP-C RELEASE ACCESS BEARERS RESPONSE" from it. Following that
        it sends a "S1AP UE CONTEXT RELEASE COMMAND" to eNB.

        * Upon receiving this request, eNB sends a "RRCConnectionRelease" to the terminals and drops the radio connection and RNTI. It also causes 
        the terminal to return to standby mode, and it will lose its access to RNTI. Then a "S1AP UE CONTEXT RELEASE COMPLETE" is sent to MME to let
        it know about the state of the terminal.

    * At the end of this procedure, the terminal and the MME of that terminal are in the ECM-IDLE (and EMM-Registered) state.

* Conclusion on ECM and EMM states

    * EMM-Deregistered (necessarily ECM-IDLE)

        - Terminal not connected to the network, no IP address.

    * EMM-Registered and ECM-Connected

        - Terminal connected to the network, with an IP address.

        - RNTI allocated to the terminal.

        - Location of the UE known. (in which cell the UE is)

        - All tunnels and connections are established.

    * EMM-Registered and ECM-IDLE

        - Terminal (apparently) connected to the network, with an IP address.

        - No RNTI allocated to the temrinal.

        - No tunnels, nor connection from an eNodeB.

        - Tunnels between SGW and PGW and between SGW and MME are maintained.

        - Relative location of the UE (group of cells)

* Tips

    * The terminal keeps its IP address. The principle is to suspend radio connectivity but to keep upper layers (application, transport,
    network) in a stable situation.

## **UE-Triggered Service Request**

* Connection Re-establishment after Inactivity

    * Simple Process:

        * UE uses the random access channel to request for a RNTI from eNB and sends a "RRCConnectionRequest (TMSI)" to eNB. Then eNB responds
        with a "RRCConnectionSetup" and after this handshake, it assigns a RNTI to the UE and it's saved by both endpoints.

        * Then a "RRCConnectionSetupComplete [EMM Service Request (KSI)]" is sent to eNB. eNodeB sends a "S1AP INITIAL UE MESSAGE (TMSI, CELLID) 
        [EMM Service Request (KSI)]" to MME using the KSI which is a security key.

        * MME verifies and authenticates the subscriber and sends a "S1AP INITIAL CONTEXT REQUEST (E-RAB to be set up list)" to eNB. Then a message
        "RRCConnectionReconfiguration (E-RAB to be set up list)" is sent to UE by eNB and a value of TEID is selected and sent to MME using
        "S1AP INITIAL CONTEXT SETUP COMPLETE (TEID)" message.

        * MME sends a "GTP-C MODIFY BEARER REQUEST (TEID)" to SGW and after selection of TEID by SGW, a "GTP-C MODIFY BEARER RESPONSE (TEID1, TEID2)"
        is sent back to MME and forwarded to eNB to establish the S1 bearer.

        * Now this process consumes a lot of time.

    * Partial Release of S1 Tunnel

        * The TEID of the SGW on S1 tunnel is retained in MME to speed up the process.

        * After initial handshake, connection request and authentication which was sent to eNB and forwarded to MME by the UE, this time MME sends a
        "S1AP INITIAL CONTEXT REQUEST (TEID2, E-RAB to be set up list)" to eNB which contains the previous TEID of SGW. This sets up a bearer between
        SGW and eNB.

        * Then eNB sends a "RRCConnectionReconfiguration (E-RAB to be set up list)" to UE, chooses a value of TEID and sends a "S1AP INITIAL CONTEXT
        SETUP COMPLETE (TEID1)" to MME, which is forwarded to SGW by this messgae "GTP-C MODIFY BEARER REQUEST (TEID1)". SGW sends a "GTP-C MODIFY 
        BEARER RESPONSE" to MME and the S1 bearer is established.

        * The difference is after MME receives a connection request and authorizes the UE, it sets up the S1 bearer by sending SGW's TEID to eNB, and 
        from that point data can be transmitted uplink. However only after SGW updates its information about the eNB's TEID, data can be transmitted both ways.

* Summary

    * After radio inactivity, the S1 bearer is partially released and the TEID value of SGW for it is stored in MME.

    * A procedure called UE-Triggered service request is defined to re-establish the bearers and connections as quickly as possible.

* Tips

    * After a long period of inactivity, the mobile goes back to the ECM_idle state. The IP address is kept but the radio connection, 
    the S1-AP connection and the S1 tunnel are released. So it is impossible to immediately transmit data. The aim of the “UE-triggered 
    service request procedure”  is to reestablish all the connections and tunnels to enable transmission.

    * The radio transmission is done on a transport-block basis in a 1-ms sub-frame. So at least 1 ms is required to transmit an IP packet 
    in LTE (a longer delay is required because of the resource request procedure). 

    * The LTE network has been designed to have a relatively low latency compared to 3G. It is not impossible to have several hundred milliseconds 
    roundtrip delays but it corresponds to a case when the network is extremely overloaded.

    * The first ping is sent while the mobile is in the ECM-idle state. The UE-triggered Service Request procedure must be done before transmitting 
    a packet. So the delay for the first ping is longer than the next ones. 

    * The uplink tunnel is never fully released because the TEID is kept in memory by the SGW. The uplink is active as soon as the eNodeB knows this 
    TEID, in other words upon reception of the S1-AP Initial Context Request. Regarding the downlink, it is only necessary for the SGW to know the 
    TEID allocated by the eNodeB for this tunnel. This is done upon reception of GTP-C Modify Bearer Request. 

## **Network-Triggered Service Request**

* Service Request Procedure

    * Initial state of the cell phone

        - EMM-Registered and ECM-IDLE

    * UE triggered service request

        - Request made by UE

        - Example: user action (consulting a web page)

    * Network triggered service request

        - Request made by the network

        - Example: application with messages sent by a server, SIP (Session Initiation Protocol) phone call

    * At the end of the procedure (if it succeeds)

        - EMM-Registered and ECM-Connected

* Network Triggered Service Request

    * The Process:

        * A "GTP-U [IP Packet]" message is sent to SGW by PGW that comes from external network. Since the UE has
          been inactive and the S1 bearer is partially released, SGW does not know the corresponding eNB of the 
          terminal, so there are two mechanisms depending on the operator:

            1- To buffer the message and call MME. (High QoS)

            2- To drop the message and call MME and let the applications on endpoints handle the packet loss.

        Then SGW sends a "GTP-C DOWNLINK DATA NOTIFICATION" to MME and receives an ACK from it. This message means
        that SGW has a packet but does not know the location of its terminal, and asks MME to handle locating the UE.

        * MME sends a speical type of message to a set of eNBs "S1AP PAGING (S-TMSI)" to page the UE with the specific 
        TMSI. Since MME keeps track of an approximate location of the UE while in idle mode, there is no need to send this
        paging message to all eNBs. 

        * Then the eNBs send a "RRC Paging (TMSI)" message over radio interface, and as soon as the UE receives this message
        it initiates a UE Triggered Service Request Procedure, and after establishment of S1 bearer, buffered packets are
        sent to UE.

* Summary

    * When? 

        - When the UE is in EMM-Registered and ECM-IDLE states

        - When a packet should be sent to the UE.

    * What is the problem?

        - To reach the UE

    * How? 

        - Paging the UE on a set of cells using its TMSI

        - The UE triggeres the Sevice Request Procedure.

* Tips

    * The server does not know the state of the terminal. So there is no buffering done by the server. The tunnel between the 
    SGW and the PGW is maintained as long as the terminal is attached (EMM-Registered state). So, the data IP packet is routed 
    to the SGW. The SGW buffers it until the S1-AP connection and the data tunnel on the S1 interface are reestablished (i.e. 
    until the terminal enters the ECM-Connected state). The paging is only used to “wake up” a terminal. It contains no data.

    * Buffering is not required by the standards. A simple strategy consists in establishing all the connections and tunnels 
    upon reception of the IP packet but without storing it by “betting” that if the packet is important it will be retransmitted 
    (this is the case if there is TCP between the server and the terminal).

    * The control tunnel between the SGW and the MME is not released when the terminal gets into the ECM-idle state. This allows 
    the SGW to contact the MME as quickly as possible.

## **Principle of Dedicated Bearers**

* Limits of the Default Bearer

    * As soon as the UE powers up, a default bearer is established.

        - A priority, no guarantee of QoS (best effort).

            - The transit delays of packets can fluctuate.

            - Certain packets can be lost.

        - The default bearer is suitable for a very large range of services

            - Reliability from one end to the other (UE and server) managed by TCP

            - Long delays are tolerated.

            - Example: consulting web pages, messages, etc.

    * Need to guarantee QoS

        - IP telephony (principally)

        - Critical applications

* General Presentation of Dedicated Bearers

    * Possibility of establishing one or several supplementary bearers.

        - Dedicated bearer.

        - Establishment triggered by the network (PGW)

        - Request made by UE with signaling at the application level.

            - SIP signaling transmitted on the default bearer.

    * Different cases possible

        - Dedicated bearer: dedicated to the same context as the context of default bearer (same APN and same IP address)

            - Case handled in the course

        - Establishment of a new context (e.g. different PGW)

            - Not seen in this course

* QoS can be implemented at TEID level or message queue level.

* DiffServ protocol to manage QoS on IP networks.

* Dedicated Bearer Activation Procedure

    * The Process:

        * A "GTP-C CREATE BEARER REQUEST (QoS level)" message is sent from PGW to SGW and relayed to MME. MME sends a
        "S1AP E-RAB SETUP REUQEST (QoS level) [ESM ACTIVATE DEDICATED EPS BEARER CONTEXT REQUEST]" to eNB.

        * Then the scheduler in eNB takes into account the QoS and eNB sends a "RRCConnectionReconfiguration [ESM 
        ACTIVATE DEDICATED EPS BEARER CONTEXT REQUEST]" to terminal. Then a "RRCConnectionReconfigurationComplete" message
        is sent back to eNB and is relayed to MME using "S1AP E-RAB SETUP RESPONSE" message and informs the MME that both
        the eNB and the UE are aware of the dedicated bearer.

        * Then a "RRC UL INFORMATION TRANSFER [ESM ACTIVATE DEDICATED EPS BEARER CONTEXT ACCEPT]" ACK message is sent from UE to
        eNB, relayed to MME using "S1AP UPLINK NAS TRANSPORT [ESM ACTIVATE DEDICATED EPS BEARER CONTEXT ACCEPT]" and sent to
        SGW using "GTP-C CREATE BEARER RESPONSE" and forwarded to PGW.

    * At the end we have different TEIDs for the different bearers of the same user.

* Dedicated Bearer De-activation Procedure

    * The Process:

        * A "GTP-C DELETE BEARER REQUEST (cause)" message is sent from PGW to SGW and relayed to MME. MME sends a
        "S1AP E-RAB RELEASE COMMAND [ESM DEACTIVATE DEDICATED EPS BEARER CONTEXT REQUEST]" to eNB.

        * Then the scheduler in eNB takes into account the removal of QoS and eNB sends a "RRCConnectionReconfiguration [ESM 
        DEACTIVATE DEDICATED EPS BEARER CONTEXT REQUEST]" to terminal. Then a "RRCConnectionReconfigurationComplete" message
        is sent back to eNB and is relayed to MME using "S1AP E-RAB RELEASE RESPONSE" message and informs the MME that both
        the eNB and the UE are aware of the removal of dedicated bearer.

        * Then a "RRC UL INFORMATION TRANSFER [ESM DEACTIVATE DEDICATED EPS BEARER CONTEXT ACCEPT]" ACK message is sent from UE to
        eNB, relayed to MME using "S1AP UPLINK NAS TRANSPORT [ESM DEACTIVATE DEDICATED EPS BEARER CONTEXT ACCEPT]" and sent to
        SGW using "GTP-C DELETE BEARER RESPONSE" and forwarded to PGW.

* Tips

    * In 4G, the default bearer is adapted to a wide range of applications and services that do not demand a high level of QoS.

    * The default bearer transports what is seen by the 4G network as data. Signaling (SIP for example) exchanged between a 
    terminal and a server outside the EPC network is seen as data by the 4G network. The default bearer is systematically 
    established.

    * In 4G, the establishment of a dedicated bearer corresponds to the establishment of data tunnels between eNB, SGW and PGW to 
    get a guaranteed level of QoS.

    * There can be several dedicated bearers. The terminal keeps the same IP address. A single control tunnel is enough between 
    SGW and PGW, SGW and MME.

    * The PGW decides to establish a dedicated bearer. The standard defines the PCEF function (Policy Control Enforcement Function)
    in the PGW. The PGW is connected to a PCRF entity (Policy Control Resource Function), which decides if a bearer with a quality
    of service can be opened or not. The establishment of a dedicated bearer can be suggested by the terminal.

    * Guaranteeing a QoS means that we should make sure there are enough available transmission resources in each node of the 
    service chain. This also implies that the establishment of a dedicated bearer can be refused if there is a lack of resource
    somewhere. This is called "Admission Control".