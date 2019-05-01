# **Radio Interface**

## **Radio Transmission**

* Physical Layer

    * The goal is to transfer binary messages between two points. Namely an
    eNodeB and a UE.

    * LTE uses Modulation and Error correction techniques.

* Modulation

    * Radio relys on electromagnetic waves to transmit information, waves can 
    travel a long distance but they're subject to disturbance.

    * Modulation is a transmission technique that consists of using a high-frequency
    bearer to transmit a message.

* BPSK: Binary Phase Shift Keying

    * Simplest modulation done in LTE.

    * Operates on the phase of the bearer.

    * In transmit of 0 we do nothing but in transmit of 1 we shift the phase by a 
    factor of Pi.

    * If the information changes, the phase changes too, otherwise it remains constant.

    * For example: Phase 0 => 0, Phase Pi => 1

* QPSK: Quanternary Phase Shift Keying

    * It enables 4 phase states as opposed to 2 states of BPSK.

    * So we can transmit 2 bits at a time.

    * For example: Phase Pi/4 => 00, Phase 3Pi/4 => 01, Phase 5Pi/4 => 10, Phase 7Pi/4 => 11

    * We call a "Symbol" the period of time during which the information transmitted is
    constant.

    * We can transmit 2 bits per symbol in QPSK and 1 bit per symbol in BPSK.

    * Since states are closer to each other in QPSK than in BPSK, in the case of disturbance 
    the states will drift from their original position and they may overlap and corrupt the data.

* To use an efficient modulation, we need a good quality of channel.

* Transmission Reliability

    * The idea is to increase the redundancy of information to increase the chance of reconstruction
    upon reception.

* Coding Rate

    * Coding Rate = Useful Information / Total Transmitted

    * In LTE it can vary from 1/3 extensive correction to almost 1 nearly no correction.

* MCS: Modulation Coding Scheme

    * Modulation (BPSK, QPSK, etc.) + Coding Rate (1/3 ... 1) => MCS (29 in LTE) 

    * MCS is the combination of Modulation and Coding Rate.

    * Channel conditions change continously for each mobile, LTE has to adapt MCS of each mobile
    in real-time.

* Summary

    * Compromise: Throughput vs. Immunity

        - High throughput requires good propagation

    * LTE adapts the MCS

        - In real time

        - Independently for each user.

* Tips

    * BPSK modulation is less sensitive to perturbations than QPSK, BPSK modulation provides a
    lower gross bit rate than QPSK.

    * LTE utilizes an error correction system.

    * BPSK corresponds to 1 bit/symbol while QPSK corresponds to 2 bits/symbol.

    * In LTE, two terminals can use different modulations.

## **Resource Blocks and Sub-frames**

* Radio Resource Sharing

    * Spectrum is sparse and expensive

    * Several users => Allocation must be dynamic.

    * Division by frequency and time.

    * LTE operates on a spectrum band between minimum and maximum frequency, whihc varies 
    from 1.4 - 20 MHz

    * This band is divided to sub-carriers, and each can be allocated to a different user.
    These frequencies are periodically allocated based on users need.

* Resource Element / Resource Block / Sub-frame

    * Resource Elements (RE)

        - 1 RE = 1 symbol

        - 1 sub-carrier (15 KHz, 66 μs)

    * Resource Block

        - 84 REs distributed to 12 sub-carriers (180 KHz)

        - 0.5 ms, 7 symbols

    * Number of available RBs on different bands

        - 1.4 MHz: 6

        - 5 MHz: 25

        - 10 MHz: 50

        - 20 MHz: 100

    * Every 1 ms, LTE allocates the RBs to users that need to communicate. RBs
    are allocated in pairs.

    * Sub-frame = 2 RB

        - The pattern formed by RBs during 1 ms.

        - 1 ms

        - Heartbeat of allocation

    * Wrap-Up

        * The available spectrum is cut into resource blocks that are allocated every
        1 ms.

        * The pattern formed by resource blocks every second is called a sub-frame.

        * Each resource block contains 84 resource elements. And each resource element
        transports one symbol.

* Reserved Resource Elements

    * Some REs are reserved

        - LTE internal control

        - Group of reserved resources = "physical channel"

* Transport Block

    * At each sub-frames (1 ms)

        - Devices are allocated with 1 or several RBs.

        - By the eNodeB

    * Transport Block

        - Size of the data to transmit on allocated RBs.

    * The size depends on 

        - Number of RB allocated

        - MCS in use. (The more efficient the modulation, the bigger the transport block.)

    * Maximum available throughput is 75 Mb/s.

    * Size of a RB ranges from 16 bits (using MCS 0, and 1 RB) to 75 Kb (using MCS 28, and 100 RBs).

    * The same size of RB can be found in different combinations of RB count and MCS. This is interesting,
    when the condition changes and we have to use a different modulation, so we can keep our RB size and 
    increase or decrease RB counts needed.

* Summary

    * Resource sharing

        - In time and frequency

        - RE: 1 symbol

        - RB: Block of 84 RE.

    * Allocation of Transport Blocks

        - At each sub-frame (1 ms)

        - By the eNodeB.

* Transmission Chain

    * ![img]()

* Tips

    * A resource element contains one symbol and a number of variable bits which depends on the 
    modulation.

    * A resource block typically contains 84 REs.

    * In LTE resources are allocated every 1 ms.

    * The transmission duration of a transport block is always equal to or less than 1 ms.

    * The size of the transport blocks can vary depending on the modulation used and on the number 
    of available RBs

## **Packet Allocation**

* Principles of allocation: Scheduling

    * Allocation by eNodeBs

        - For both uplink (UL) and downlink (DL).

    * Allocation only if needed.

    * eNodeBs publish allocation tables.

        - One for DL

        - One for UL

* Addresses on the radio: RNTI

    * Addressing

        - Identification terminals within a given cell.

        - Needs to be short

    * Radio Network Temporary Identifier (RNTI)

        - Allocated by the eNB when a new terminal arrives.

    * 16 bits long

        - ~ 65 000 mobiles / cell

* Allocation on DL

    * Resource allocation by the eNB.

    * Short UE identification

        - RNTI

    * Allocation table

        - Indicates the recipient of each RB.

        - At the beginning of sub-frame.

    * UE only decodes its own messages

        - => Energy saving.

* Allocation on UL

    * Same as DL but ...

    * The UE first makes a request.

    * The eNB allocates a resource

        - Publication in the allocation table.

    * Anticipation of 4 ms.

        - Reaction time of the terminal.

* Data Channels / Control Channels

    * ![img]()

    * Physical Downlink Control CHannel (PDCCH) / Physical Uplink Control CHannel (PUCCH) are used to 
    transmit signaling messages, control messages and publish allocation tables.

    * Physical Downlink Shared CHannel (PDSCH) / Physical Uplink Shared CHannel (PUSCH) used to transfer
    user data.

    * In the uplink the control channel resides on RBs on either start or end of the band, however in downlink it 
    starts before a sub-frame and can be sent on any band.

    * Each terminal in LTE has the right to access uplink control channel to request RBs to transmit data.

* Summary

    * Allocation

        * Managed by the eNB (on both UL and DL)

        * When there is a need for transmission.

        * Control Channels are reserved for exchanges related to allocation:

            - Allocation tables (DL and UL), requests for transmission, etc.

    * On Uplink

        * The terminal must first make a request on the control channel.

        * And be allocated a resource which will be active 4 sub-frames later.

* Tips

    * In LTE, the radio resource allocation is handled by eNodeBs.

    * Devices that have nothing to transmit use less radio resources than others.

    * On the downlink, only the base station transmits.

    * The eNB cannot transmit on the uplink.

    * The RNTI is chosen by the eNB, and is a way to uniquely identify a terminal within a cell.

    * The base station publishes the allocation table of the downlink for the current sub-frame, and
    the allocation table of the uplink 4 sub-frames in advance.

    * A terminal that sends a very small amount of data cannot transmit it on the control channel of the
    uplink.

## **Transmission Reliability**

* 10 ^ -6 is an acceptable bit error rate in radio.

* The MAC layer handles the errors that have not been corrected by the physical layer, and another function
of MAC is that it allows for several services to communicate with the same mobile at the same time, which is
called Multiplexing.

* Automatic Repeat reQuest (ARQ)

    * Error detection

        - Cyclic Redundancy Check (CRC)

    * Send and Wait ARQ

    * If transmission problem

        - retransmission

    * If too many retransmissions

        - Discontinue (taken up by higher levels)

* Acknowledgement

    * Processing time: 8 sub-frames

    * Fixed delay: 8 ms

        - 4 ms for the reciver + 4 ms for the sender.

* Parallel Acknowldegements

    * Optimization: Parallel send and wait

        - 8 parallel cycles

        - For each eNB-UE couple

    * Used in LTE.

    * The problem with it is that causes De-sequencing

    * De-sequencing

        - Losses of each process are independent.

    * Not handled by the MAC layer (Resequencing)

        - Left to the upper level (RLC)

* Hybrid ARQ (HARQ)

    * Retransmission = Redundancy

        - Redundancy increases error correction performance.

    * Hybrid because the MAC layer has to collaborate with the physical layer to let it
    know that the data it processes are actually repetitions of the same transport block.

* Multiplexing

    * ![img]()

    * MAC-SDU (Service Data Unit)

        - Data from the upper layer

        - Several sources = logical channels (different levels of QoS)

    * MAC-PDU (Protocol Data Unit)

        - Output of MAC layer

        - => Transport Block

    * MAC receives SDUs and produces PDUs.

    * Data handeled by the MAC layer are provided by the upper layer RLC, which are provided through
    message queues that are known as logical channels. The output of the MAC would be MAC-PDUs that are 
    transport blocks that will be transmitted by the physical layer (2 to 9422 bytes). To form the transport
    blocks, the MAC layer assembles the SDUs from different logical channels (multiplexing). To help the 
    receiver de-multiplex, the MAC layer adds headers to indicate where each message starts and to which 
    logical channel they belong to. Padding can also be added to ensure that the size of the MAC-PDU is 
    exactly the same size as the transport block to be transmitted (16 kb/s to 75 Mb/s).

* Summary

    * Functions of the MAC layer:

        * Resource allocation

        * HARQ: Transmission reliability

            - Retransmission of corrupted transport blocks

            - Several processes in parallel.

        * Multiplexing

            - Management of the priorities of several logical channels

            - Assembly of data to make transport blocks.

* Tips

    * The MAC layer detects errors at the granularity of a transport block.

    * In the case of error, the retransmission occurs 8 ms later.

    * Parallel send and wait can lead to out-of-order delivery, and allows the throughput
    to be increased up to 8 times.

    * The MAC-PDUs correspond to transport blocks.

    * In the downlink, a MAC-PDU can group data from different sources, group data of different
    types and include signaling and data.

## **RLC Protocol**

* In LTE it is the RLC layers role to contorl QoS.

* Radio Link Control (RLC) is just above MAC layer.

* Quality of Service (QoS)

    * Applications have varying needs

        - Latency

        - Reliability (error rate)

        - (De)-sequencing

    * QoS is a compromise

        - Especially latency vs. reliability

        - Several compromises available

        - Depending on the application needs.

* RLC: Radio Control Link

    * Additional services over MAC layer

        - Re-sequencing

        - Segmentation

        - Additional re-transmission stage

    * Optional services

        - 3 classes of service

* RLC Modes

    * TM: Transparent Mode

        - No additional service

        - => short signaling messages (RRC)

    * UM: Unacknowledged Mode

        - Re-sequencing

        - Segmentation according to MAC layer needs.

        - Low latency but low reliability => VoIP, real-time video, etc.

    * AM: Acknowledged Mode

        - Like UM + Re-transmission of lost packets

        - Reliability => Web, emails, file transfer, etc.

    * Several instances can operate parallel

    * MAC layer picks up packets on all instances depnding on the parametrized priorities and
    throughput targets.

* Unacknowledged Mode (UM)

    * ![img]()

    * Segmentation / concatenation

        - Fit to the size of the MAC-SDU

    * Header

        - Identification messages boundaries.

        - Sequence number (for re-sequencing)

    * When it receives a packet from the upper layer, RLC saves it in a buffer while waiting for the 
    MAC layer to request a MAC-SDU. When requested, it specifies the size for the MAC-SDU that is 
    expecting. RLC then assembles the stored packets to make a RLC-PDU of the requested size. To do so
    it can concatenate packets or split them to reach the specified size. RLC also adds headers to tell 
    receiver where to find the differnet fragments and which RLC instance they belong to. These headers 
    also contain sequence numbers that will enable putting blocks in the correct order if they're 
    de-sequenced by HARQ.

    * Two important notes:

        * The MAC layer can regroup in the same transport block, SDUs from different RLC instances.

        * When trying to retrieve the correct sequence of messages, RLC in UM can remain blocked if 
        an intermediate segment never arrives. To avoid this, after a certain time, RLC will eventually
        consider this packet as lost and will go on to the next.

* Acknowledged Mode (AM)

    * ![img]()

    * Same function as UM plus Retransmission of lost data

        - => Memorisation of transmitted messages

        - Protocol:

            - Transmitter requests recipient's status.

            - Response by RLC message (list of received / expected PDUs)

            - Free Memory (messages OK) or retransmit lost messages.

    * In AM mode, RLC memorizes the MAC-SDUs it delivers to the MAC layer, so that it will be resent if
    necessary. It regularly asks the recipient to send the status of the message it has received. The 
    receiver answers to this request by sending an RLC signaling message that is transferred on the data
    channel instead of control channel. The answer from recipient must be separated from the data flow and
    delivered to RLC controller, then the controller can erase from its memory the messages that are being 
    correctly received and resend ones that have not been delivered to the recipient.

    * For AM mode it must be the same body that manages the transmission and the reception part, while in UM
    these processes are independent.

* Summary

    * RLC is above the MAC layer

    * RLC Functions:

        - Re-sequencing of blocks held by HARQ.

        - Concatenation / segmentation to fit the size requested by the MAC layer.

        - Retransmission of lost blocks.

    * QoS is a compromise

        - Re-sequencing and repetition generate delays.

        - RLC enables 3 modes:

            - Transparent, Unacknowledged, Acknowledged

* Tips

    * RLC does not introduce latency.

    * In UM or AM mode, the receiver does not send an ACK each time it receives a message.

    * RLC needs sequence numbers for both UM and AM mode.

## **Random Access**

* Access Methods

    * Access Protocols decide when, how and which user has to use the communincation media.

    * Contention

        - Competition for resources

        - Collisions

        - Re-transmission in case of error

        - like WiFi

    * Reservation

        - Breaking up in elemental resources

        - Static or dynamic allocation

        - like LTE

    * Issues in LTE

        - Newcomers

        - Solution => a bit of contention within the uplink.

* Physical Random Access Channel (PRACH)

    * Contention based access

        - 6 RB, 1 ms wide

        - Every 1 to 20 ms (configurable)

        - Access by CDMA (Code Division Multiple Access)

            * In CDMA, transmitters encode their transmissions with sequences. The mathematical
            properties of these sequences are such that, if 2 devices transmit simultaneously with
            different sequences, the receiver can still distinguish between the two transmissions.

        - On this 1 ms frame, only 1 symbol is sent which takes up all 6 RBs. The base station infers
        that there's a new terminal that's asking for resources.

        - 64 different sequences. (up to 64 different simultaneous requests)

* Arrival of new UE / RNTI

    * The terminal that arrives listens to the eNB to identify when the random access channel is scheduled.
    It then chooses, at random, one of the 64 sequences, and transmits on the random access channel, using
    this sequence at the right moment. The eNB detects this transmission and the sequence. It does not know
    the identity of mobile, but will use the sequence to temporarily identify the terminal and will then 
    assign it an RNTI. However at this point RNTI is only known by the eNB, so it cannot use it as an address
    to send a message to the terminal. Instead it will use RA-RNTI (Random Access RNTI), which is calculated 
    using the sequence already used by the mobile. Now, the eNB can transmit a message to mobile to send a few
    parameters, including the assigned RNTI and it will use the RA-RNTI as the destination address of this
    message. The eNB can allocate a resource to that terminal so that it can send a connection request 
    (RRCConnectionRequest(TMSI)).

* Arrival of new UE - Competition on Random Access

    * UEs access the contention channel with the same sequence. Each terminal goes through random access procedure.
      the eNB will note one request thinking it is the only one and will then go through the procedure. It will assign 
      RNTI and allocate a transmission resource, and send this information to the mobile. The 2 phones will receive
      the message adn each will transmit a connection request which contains their TMSI and interference will occur.
      There are 2 cases possible:

        - In the first case, eNB is not able to decode either of the messages and will not respond. The terminals will
        then repeat the process later.

        - In the other case, the base station can decode one of the messages, it believes there is only one user and
        continues the procedure. This is a problem because we don't know which UE is registered. So to solve this 
        the standared dictates that eNB must send to the UE and echo of its connection request. Since this request
        contains terminals TMSI, the termianl can compare its own with it and if it's the same it continues the procedure.

* Summary

    * LTE is reservation-based

        - Allocation is managed dynamically by the eNB.

        - On the uplink, terminals must first make a request.

    * Random-access channel on UL (PRACH)

        - New terminals announcement

        - Contention-based (CDMA)

        - Collisions managed by the protocols.

* Tips

    * In a contention based protocol, there can be collisons, however in reservation protocols, there cannot
    be collisions.

    * The access on the radio interface in LTE is mainly based on a dynamic reservation protocol.

    * The eNB is not allowed to transmit on the random access channel.

    * If the access requests of two different terminals collide, the conflict is resolved by the eNB.

## **PDCP and Global Vision**

* Radio Interface Protocol Stack:

    - PDCP

    - RLC

    - MAC

    - Physical

* Packet Data Convergence Protocol (PDCP)

    * One instance of PDCP per RLC instance.

        - Except for TM

    * Header compression

        - RoHC: Robust Header Compression (IETF protocol)

        - Point to point => headers vary little => compression is possible.

    * Handovers mitigation

        - To avoid packet loss or de-sequencing that happens during handovers.

        - Old -> New eNB

        - Packet ordering, waiting for ACK, duplication, etc.

    * Security

        - Cyphering

        - Error detection

    * It provides the interface with the core network, with IP protocol of user data and RRC
    for signaling messages.

    * For example VoIP packets are 30 bytes long, with RTP header that adds extra 12 bytes header. Then
      encapsulated in UDP which adds 8 bytes and finally IPv6 which adds 40 bytes. So the total length of 
      header is 60 bytes.

        - IPv6 (40 B) | UDP (8 B) | RTP (12 B) | VoIP packet (30 B)

* PDCP Functionalities

    * Data Plane (IP): Header compression (RoHC) is available, Loss prevention (Handover) is applied to AM 
    packets, Cyphering is possible and optional.

    * Control Plane (RRC): Does not support RoHC, Loss prevention available for AM packets, Cyphering is 
    possible and optional, Integrity check is applied.

* Summary 

    * Radio Interface Protocol Stack:

    * PDCP

        - Header compression (RoHC)

        - Handover mitigation

        - Cyphering / Integrity check

        - IP for user data and RRC for signalling messages

    * RLC

        - Re-sequencing

        - Retransmission (AM)

        - Segmentation (According to MAC requirements)

    * MAC

        - Logical channels multiplexing (Priorities management)

        - HARQ

        - Radio resource allocation

        - Controls:

            - Size of RLC PDU

            - Adaptive modulation (MCS)

    * PHY

        - Coding (Error correction)

        - Modulation

    * ![img]()

* Tips

    * RoHC is not available for signalling data (RRC) because RoHC only applies to IP packets.

    * PDCP provides services for security, header compression and handle problems linked to handovers.

    * Security is handled in PDCP layer.

    * Error correction is handled by PHY.

    * Resource allocation is handled by MAC.

    * Packet segmentation and assembly is handled by RLC.

    * PDCP helps with the transition from one cell to another.

    * MAC layer builds the transport blocks.

    * The MAC layer retransmits transport blocks thanks to the HARQ protocol. The RLC layer in AM mode 
    can also retransmit packets.