# **Mobility Management**

## **Managing Location**

* Review the Concept of a Cell

    * Each base station (eNodeB) covers a cell

    * To simplify calculations, we assume that the cell is square.

        - The same calculations are psooible with hexagonal cells.

    * The terminal can be in any cell.

        - How to reach it? How to establish a link wherever it is?

* Need for a Beacon Channel (Broadcast Control Channel)

    * Each eNodeB regularly broadcasts its identify on the beacon channel (typically every 
    1 to 5 seconds).

* Concept of a Tracking Area (Location Area in 2G, 3G)

    * Tracking Area Identity: TAI

        - MCC: Mobile Country Code

        - MNC: Mobile Network Code

        - TAC: Tracking Area Code

    * The TAI of the tracking zone is broadcast regularly by each eNodeB.

    * Moving inside this area does not exchange any signaling messages to update its location.

    * Ambiguity of location is a disadvantage in this method.

* Principle of Paging

    * Paging consists of broadcasting the identity (TMSI, Temporary Mobile Subscriber Identity)
    to all the cells in the Tracking Area (TA).

* Summary

    * A tracking area regroups several cells

        - A UE can move within the tracking area without updating its location.

    * The larger the area

        - The lower the frequency of terminal updates.

        - The greater the load of paging messages.

    * At first approximation

        - A tracking area of N cells allows you to divide the number of updates made per unit of time
        by sqrt(N)

        - The number of paging messages is multiplied by N.

* Tips

    * Location management in a 4G network is based on the transmission by the terminal of a tracking update
    message each time it changes tracking areas.

    * Location management must not depend on another system. It cannot rely on GPS and must be done while 
    consuming as little radio resources as possible, in other words by reducing the terminal transmission.

    * The size of the tracking areas is chosen by the operator and it is usually smaller than the area covered
    by a SGW.

    * The identity of the tracking area to which an eNodeB belongs is broadcasted by the eNB on the beacon channel.
    The identity of the tracking area is regularly broadcasted on the beacon channel. This allows the operator to 
    reconfigure his network if he wishes so (changing the tracking areas). If everything was stored in the SIM card,
    it would be much more complicated to make changes.

## **Balancing the Location Update Load**

* Signaling Load on Edge Cells

    * The location updates are made in the cells on the edge of the tracking area.

* Principle of Tracking Area Lists or TA lists

    * With each update, the network provides a tracking area list

        - Tracking Area List or TA List

    * Two terminals in the same cell can have different lists.

    * Paging must be made on all cells of the TA list.

    * Terminals only make location update when they leave their TA List.

* Tips

    * In 4G, location management is managed with tracking area lists (TALs). An eNodeB belongs to only one tracking
    area but the network transmits a tracking area list (TAL) to the terminal when location is updated.

    * In 4G, as soon as a terminal leaves a cell that is part of a tracking area and enters a cell belonging to
    another tracking area, it performs a tracking update procedure only if the new area does not belong to the 
    list of areas it has in its memory.

    * Changing tracking areas does not systematically trigger a tracking update, there can be a periodical tracking
    update in 4G for example in an hour, but that is caused by a timer.

    * The mobility management in 4G aims at better distributing the tracking update signaling load over all the cells.

    * The tracking update principle is identical in 4G and in 2G/3G. The addition of the list concept does not reduce
    the signaling load if the average size of a list is the same as the size of a 2G/3G tracking area.

## **Mobility Management of a Terminal in Idle Node**

* The location update is done in ECM-IDLE state

    - Management of mobility in ECM-Connected state = Handover

* Location Update Process

    * UE detects a TA off the list and establishes a radio connection to the eNB, sends a "EMM TRACKING AREA UPDATE REQUEST 
    (GUTI, old TAL)" to MME.

    * MME performs AKA (Authentication and Key Agreement) optionally, activates cyphering and sets up a S1-AP connection. 
    Then it allocates a new TMSI => new GUTI, and chooses a new TAL. Finally sends a "EMM TRACKING AREA UPDATE ACCEPT (newGUTI, 
    newTAL)" back to the UE.

    * Terminals stores the newGUTI and newTAL in the SIM and sends a "EMM TRACKING AREA UPDATE COMPLETE" to MME, which causes 
    MME to release radio and S1-AP connection.

* Location Update

    * In ECM-IDLE state

    * Set up of a radio connection and S1-AP connection

    * NAS signaling

    * Possibly allocation of a new GUTI

    * Update of the Tracking Area List (TAL)

* Tips

    * The tracking of a terminal is handled by the MME. The terminal decides to send a message when it notices that it is
    entering a cell belonging to a tracking area that is not in its current list. The tracking update is triggered by the 
    terminal not the network. The tracking update request is a NAS message so it's forwarded by the eNB to MME.

    * Adding the IMSI could enable a third party to follow the movement of a subscriber. So it is the GUTI built from TMSI
    that is used in exchanges.

    * A 4G network manages the mobility of the terminal not the mobility of IP addresses.

    * No matter the duration of exchanges, an S1-AP connection is required for the NAS signaling to be exchanged between
    the terminal and MME via eNB.

## **Mobility Management with a Change of SGW or MME**

* Tracking Area Update with a Change of SGW

    * The Process:

        * UE sends a "EMM TRACKING AREA UPDATE REQUEST (GUTI, old TAL)" to MME.

        * MME performs AKA (Authentication and Key Agreement) optionally, activates cyphering and sets up a S1-AP connection.
        Then a "GTP-C CREATE SESSION REQUEST" is sent to new SGW and a "GTP-C MODIFY BEARER REQUEST" is sent from new SGW to 
        PGW.

        * PGW proceeds with "GTP-C MODIFY BEARER RESPONSE" message to the new SGW and that is forwarded to MME with
        "GTP-C CREATE SESSION RESPONSE" message.

        * MME then sends a "EMM TRACKING UPDATE ACCEPT (newGUTI, newTAL)" back to UE, and sends a "GTP-C DELETE SESSION REQUEST"
        to the old SGW. It receives a "GTP-C DELETE SESSION RESPONSE" from the old SGW. Also it receives an ACK message of
        "EMM TRACKING AREA UPDATE COMPLETE" from UE.

* Tracking Area Update with a Change of MME

    * The terminal must indicate its GUTI while changing MME to the new MME so the new one can deduce the previous MME that was
    taking care of the terminal and contact it to retrieve subscriber's profile using "GTP-C IDENTIFICATION REQUEST (GUTI)" message
    and receive "GTP-C IDENTIFICATION RESPONSE (IMSI)" from the old MME.

* Synthesis

    * The location update procedure is defined for all cases

        - New SGW, new MME

    * In all cases, the procedure is the same from the UE point of view

        - The UE puts its GUTI in the "TRACKING AREA UPDATE REQUEST" message

    * When the procedure in the network involves a new MME

        - The GUTI is analyzed by this MME to find the previous MME.

        - The previous MME sends the IMSI of the UE.

* Tips

    * The tracking update procedure involves the PGW if the UE moves from an eNB linked to a SGW to an eNB linked to another SGW.

    * The tunnel between the SGW and PGW is maintained as long as the mobile is in the EMM-Registered state whatever the ECM state
    (ECM-IDLE, ECM-Connected). The modification of SGW-PGW tunnel only happens when SGWs change. Changing MME does not imply changing
    SGW (even if it is plausible that MMEs often changes if SGWs change since there are less MMEs than SGWs.)

    * The allocation of TEID is local to each device and a TEID is only used once. In the case of changes in SGW of a temrinal, PGW
    may have to change the content of the lookup table with TEIDs.

    * The MME chooses the TMSI allocated to each terminal. The HSS does not know that TMSI. When a TMSI is sent to the terminal, the
    MME identity is also given to allow the construction of the GUTI.

## **Overview of the Handover**

* A user can have an active session while moving

    - User close to the base station => strong signal => high data bit rate

* The more the user distances himself from the base station, the weaker the signal received from the base station becomes

    - Decrease of throughput, risk of loss of connection

    - The radio connection must be transferred to another eNodeB.

* Handover (or handoff): transfer of a connection (active) from one eNodeB to another eNodeB.

* Transmission by each eNB of a specific reference signal (in conjunction with an identity called PCI, Physical Cell Identity).

* Terminal measures the strength of signals received from the 6 best received base stations.

* Regular upload to the eNB of measurements made

    - UE-assisted Network-triggered Handover

* Identification of the target cell by the eNB, since the network has a better overview of the load on the system.

* The transfer of measurements is based on a signal threshold. The measurements are reported to the network, only if the signal
received is lower than this threshold.

* Packet-switched network

    - Buffer containig packets in the intermediary equipment: PGW, SGW and especially eNB.

    - The further the terminal is from the eNB, the lower the throughput on the radio band => strong possibility of loss of queued
    packets.

* Handover, a complex operation

    - Not too early, not too late

    - Transfer of the radio connection, tunnels or connections, queued packets (if possible)

    - The target eNodeB must have sufficient reosurces to accomodate the terminal.

* Inside the network, two types of handover

    * X2 handover: Interface between eNBs

        - Practically no break in connectivity in the core of the network.

        - Transfer of queued SeNB (Source) packets to TeNB (Target).

    * S1 handover

        - Break in connectivity

        - Possibility of re-routing packets but more complex.

* Phases of the Handover

    * Before the handover

        - Activation of the transmission of measurements by the terminal when the signal strength of the base station is
        below the threshold.

        - Analysis by the eNB of the levels of the signal strength indicated by the terminal for the current eNB and the 
        neighbouring eNBs.

    * Handover in 3 phases

        * Handover Preperation

            - Reservation of resources in the network. (target eNB)

        * Handover Execution

            - Transmission of handover order to the terminal, rerouting packets, modifying tunnels and connections, establishing
            the radio connection with the target eNB.

        * Handover Completion

* Tips

    * Handover must work for a terminal without a GPS receiver. It relies on the measurements of the reference signals that are
    systematically transmitted by each eNB on a regular basis. Only the network has a view of the available resources. So the network
    determines the target cell, helped by the measurements done by the terminal.

    * The change of eNBs necessarily leads to a modification of the data tunnels but also of the S1-AP connection, since it is
    established between the eNB that serves the terminal and MME.

    * The establishment of 2 simultaneous radio connections was done in 3G but it is costly because 2 radio resources are
    used for a terminal. It was abandoned in 4G.

    * In 4G during the handover operation, the transmitted packets are buffered before being transmitted as soon as the 
    tunnels and connections are re-established.

## **Progress of the X2 Handover**

* X2 Protocol Stack

    - Based on IP

    - Same philosophy as S1-U/S1-MME

    - Control plane: X2-AP on SCTP

    - User plane: GTP-U on UDP

    - Protocol stack: PHY | DLL | IP | [SCTP | X2-AP (Control plane)]  | [UDP | GTP-U (User plane)]

    - X2-AP similar to S1-AP, connection-oriented and is used for handover preperation, execution and completion.

* X2 Handover Without a Chnage of SGW or MME

    * The Process:

        * SeNB sends a "RRCConnectionReconfiguration (trigger measurements)" to the UE, when the signal threshold drops
        below a certain level. Then measurements are continously done and reported by the UE to eNB using "RRC MeasurementReport"
        without interferring in the packet data flow. Then a handover decision is made by SeNB and a target cell is chosen. A
        "X2AP HANDOVER REQUEST" is sent to TeNB and after admission control by TeNB, either a "X2AP HANDOVER REQUEST ACKNOWLEDGE 
        (preamble)" is sent to the SeNB which contains a preamble that is used for random physical access later on the radio channel,
        or the "X2AP HANDOVER PREPERATION FAILURE" is sent and request is denied.

        * Then SeNB sends a "RRCConnectionReconfiguration (newRNTI, TeNB, preamble)" to UE and detaches itself from the terminal.
        After that a "X2AP SN STATUS TRANSFER" is sent to TeNB to forward the data packets from SeNB to TeNB and allow TeNB to
        buffer the data.

        * Then UE starts the handshake with the TeNB using the preamble that was received. Following that a 
        "RRCConnectionReconfigurationComplete" ACK message is sent to TeNB. Data is still being forwarded on the downlink but it can
        directly be sent on the uplink through the TeNB to SGW.

        * TeNB sends a "S1AP PATH SWITCH REQUEST" to MME and a "GTP-C MODIFY BEARER REQUEST" is sent from MME to SGW to route
        the data to TeNB. Following that a marker is added to the final packet sent to SeNB by SGW using "on S1-U tunnel
        GTP-U END MARKER" then it's relayed to TeNB using "on X2AP tunnel GTP-U END MARKER" to send all the buffered packets on 
        SeNB to TeNB. Now SGW sends a "GTP-C MODIFY BEARER RESPONSE" to MME and a "S1AP PATH SWITCH REQUEST ACKNOWLEDGE" is sent
        from MME to TeNB. Finally the data flow is established in both ways.

        * TeNB sends a "X2AP UE CONTEXT RELEASE" to SeNB to let it release the resources.

* X2 Handover

    * X2-AP connection

        - Used by the SeNB to request that the TeNB accommodate the terminal.

    * Tunnel GTP-U

        - The source eNB temporarily forwards downlink data packets to target eNB.

* Tips

    * X2 is the name of the interface between 2 eNodeBs. Note that:

        1-  The presence of this interface does not mean that the eNodeBs are directly linked together but that they can talk 
        via an IP network.

        2-  The use of this interface is optional. The X2-based handover indeed involves the interface between 2 eNodeBs.

    * The "RRCConnectionReconfiguration" triggers the access of the terminal on the new cell (preamble transmission). The SeNB 
    sends this command to the UE only if it is sure that the TeNB agrees to accept the UE. This is admission control. 

## **Other Handover Cases**

* X2-handover with a change of MME is not possible. If two eNBs are not connected to the same MME, the only possible 
handover is an S1-handover.

* S1-based Handover Without Change of SGW or MME

    * First the downlink connection is maintained and the uplink connection is initiated, then the downlink is also transferred 
    to the new devices and old connections are released.

* Conclusions on the Handover

    * All cases of handovers within the same network are specified.

    * Temporary service disruption

        - From several tens to several hunderds of ms

        - The handover must be fast enough to avoid disturbing the upper layers (TCP, applications)

    * The handover based on X2 enables a lower rate of packet loss.

    * Disconnections noticed by the user are often failed handovers.

    * There is an automatic connection re-establishment procedure in case of an interruption.

* Tips

    * S1-based handover refers to a handover for which the S1 bearer is switched from the source eNodeB to the target eNodeB.

    * No matter the handover type (X2 or S1), it can be done when the SGW changes or not. However, the PGW does not change because 
    it would imply an IP address change.

    * There is no direct signaling exchange between the eNodeB and the SGW (apart from very specific cases such as the GTP-C End 
    Marker message). Indeed, the MME must know the characteristics of the tunnels between the eNodeB and the SGW. So the S1-based 
    handover is a handover in which the S1 bearer is progressively switched from the source eNodeB to the target eNodeB.