# **Critical Machine-to-Machine**

## **Introdcution**

* ![Advancements-of-tecchnology]()

    - Mission Critical Services features:

        * Ultra-high reliability

        * High security

        * Flawless mobility

        * Ultra-low latency

* In this mode of operation, we have sensors that send their
data through wireless media to access points, to a server and
this server calculates upon that data and makes decisions and
sends those activities to the actuators to push the system into 
the beneficial desired state.

* Critical M2M Scenario

    * Control/Actuation Purpose:

        - Industrial automation systems, traffic coordination

        - Small packets (few bytes), strict deadline, potentially critical.

        - => Low latency systems, high availability

* Technical Challanges: Availibility 

    * Critical systems: contionous operation => high availability

    * Quality of wireless channel varies randomly.

    * ![img]()

    * Frequency bands might experience random interference.

    * How to maximize reliability despite random channel behavior?

    * How to deal with interference?

* Technical Challanges: Low-Latency

    * latency can easily be 1 ms end-to-end.

    * Latency influenced by:

        - Computational power and complexity of the transceiver.

        - Medium access control scheme.

        - Bandwidth of the wireless link.

    * How to design suitable medium access control schemes?

    * How to balance reliability with low latency and complexity?

* Classification of Systems

    * Area heavily researched currently

    * Operator-free systems:

        - iWLAN, WISA, EchoRing

        - ISM band operation, usage of IEEE802.11/15 related transceivers.

    * Cellular-based Systems:

        - 4G & 5G

        - Licensed spectrum, new/redefined air interface.

* Two major challanges of M2M communications are:

    - The wireless channel changes randomly.

    - Other transmitters may interfere with the communication.

## **Diversity**

* Chllange: Availiability

    * Safety-critical communication: Hard deadlines.

        - Drive system to fail state, if deadline not met.

    * => Critical M2M communication needs to provide high reliability

        - Translate into high availability.

    * Challange: Random behavior of the wireless channel.

* Safety-critical System

    * Emergency Stop

* Random Channel: Multipath Fading

    * Reflections on walls, floors.

    * Original and all reflected signals recombine at the receiver.

    * Constructive recombining or destructive recombining possible.

* Multipath Fading and Diversity

    * Fading leads to a random behavior of the wireless channel.

    * Sometimes, the signal cannot be decoded.

    * Solution: Diversity

    * The channel behaves differently at different points in

        * Time

        * Space

        * Frequency

    * ![img]()

* Time Diversity

    * Exploit diversity in time?

        * Wait until channel becomes better.

        * Generally applied, but no option for critical M2M systems!

        * ![img]()

* Spatial Diversity

    * Exploit diversity in space?

        * Install multiple antennas => Large/complex devices.
    
    * ![img]()

    * At least half wavelength antenna spacing to ensure indepencdent 
      channel realizations:

        - Ex: Carrier frequency 2.4 GHz

        - => Wavelength 12.5 cm

        - => > 6.25 cm between the antennas

    * This method, increases the size of the transmitter and also the receiver,
    since we need to space these antennas. It also makes the transceivers more 
    complex, since we need more radio front-end circuits to drive different 
    antennas on the transmit or receiver side.

    * Preferred solution for cellular systems.

* Cooperative Diversity

    * Exploit diversity in space with low complexity?

        - Cooperation between devices.

        - Each device has only one antenna.

        - Overhearing nodes can repeat transmission.

        - Implemented in EchoRing and OccupyCow

    * ![img]()

    * The disadvantage of this system is that it needs time and hence increases 
    latency in the system.

    * Increases reliability of the system but you can also realize low latencies.

* Frequency Diversity

    * Exploit diveristy in frequency?

        - Little chance of success when repeating the transmission at the same 
        frequency.

        - High chance of success when hopping to a different frequency or parallel
        transmission.

        - Coherence bandwidth defines separation in frequency leading to independent
        channels => large frequency requirements.

        - ![img]()

        - Frequency hopping applied in WISA.

* Summary

    * Unreliable transmission translate into low availability

        - => maximize reliability of critical M2M communications.

    * Challange: Random behavior of wireless channel.

    * Solution: Exploit diversity

        - Time diversity: cannot be exploited for critical M2M systems.

        - Spatial diversity: Multiple antennas.

        - Cooperative diversity: Multiple terminals.

        - Frequency diversity: Hopping, simultaneous transmission.

* Spatial diversity requires multiple antennas at the transmitter and receievr 
(so called Multiple Input Multiple Output (MIMO) systems). A prerequisite for this
is that the antennas can be placed such that the signal attenuation between any 
antenna pair is ideally uncorrelated. This requires a significant spacing between the 
antennas.

* A reliability better than 1 - 10 ^ -4 means that the probability to not have received 
the packet after a certain number of attempts must be lower than 0.0001.

## **Scheduling**

* Technical Challange: Low Latency

    * Latency influenced by:

        - Computauional power and complexity of the transceiver.

        - Medium access control scheme

        - Bandwidth of the wireless link.

    * How to design suitable medium access control schemes?

    * How to balance reliability with low latency and complexity?

* Scheduling and MAC

    * Medium Access Control governs the way how different nodes access the communication channel.

    * When do devices access the channel?

    * Mission-critical services => Guaranteed medium access.

* Random MAC

    * ![img]()

    * Common scheme used.

    * Devices access the channel whenever there is data to send.

    * Problem: Collisions are possible (packets are lost)

    * Example: Wi-Fi (IEEE802.11)

        * ![img]()

        * Access the channel when free, random back-off after a collision.

        * A round of backoff is a random number of so-called time slots that are generated at 
        a particular node when the transmission attempt was not successful.
    
    * Long and random delay: Acceptable for Wi-Fi but not suitable for mission critical services.

* Orthogonal MAC

    * ![img]()

    * Assign devices orthogonal sets of frequencies/time slots.

    * Orthogonal manner refers to exclusive assignment of certain frequencies and time slots to 
    certain nodes.

    * Cycle time is referred to the time it takes for every node to access the communication channel
    before the first node in the queue gets to access the channel again.

    * Delay increases with number of nodes (admission control)

    * Low utilization if some terminals do not have data.

    * WISA system uses this method.

* Decentralized Orthogonal MAC

    * ![img]()

    * Token-passing: A control packet is sent from node to node.

    * Upon reception of the token, node can access the channel.

    * Timer governs the token forwarding after certain duration.

    * Implemented by EchoRing

    * To achieve lower latency, we simply have to transmit the token fast enough through the system,
    and we have to shrink the token holding times per node. And by that we can scale the latency with 
    which the system is operated.

* Scheduling / Polling

    * ![img]()

    * Coordinated medium access

    * A central controller (base station) polls each device, the device then send data if they have any.
    if not they send a "no data" message to base station.

    * A downside to this scheme is that we have to introduce a central entity called base station.

    * industrial WLAN (iWLAN), 4G, 5G uses this scheme.

* Summary

    * Careful design of MAC for critical M2M communications

        - Main goal: Guaranteed latency! (Compare: main goal in massive M2M scenario was power saving.)

    * Collision-free orthogonal MAC:

        - Guarantees latency but potentially low utilization.

    * Scheduled MAC:

        - Better use of resources, but requires additional overhead.

    * Generally, issue of centralization vs. decentralized approach (single point of failure)

* Orthogonal MAC is superior in terms of worst-case latency to a random MAC:

    - When most of the devices regularly have data to send.

    - When there are many devices and they have regular data to send.

* A random backoff means no acknowledgement of the transmission was received. The device will try
to transmit again after a random time.

## **Transceiver Complexity**

* Latency and Reliability Requirements

    * Smart grid: Synchronization of generators

        - Time max < 5 ms & Packet Error Rate out > 10 ^ -5

    * Industrial automation: Factory control

        - Tmax < 1 ms & Pout > 10 ^ -7

    * Traffic safety: Brake indications in platoons

        - Tmax < 10 ms & Pout > 10 ^ -5

    * Tactile interaction over a network

        - Tmax < 10 ms & Pout > 10 ^ -6

* Factors Impacting the Latency

    * Medium access control cycle

    * Data transmission over the air

    * Transceiver pre-/post processing

    * Computational resources of transceiver.

    * Required reliability of level

* Worst-case Latency Computation

    * ![img]()

    * Operation cycle for packets (Payload and Control):

        - Packet arrives

        - MAC delay

        - Preprocessing

        - Transmission

        - Postprocessing

        - Packet delivered

    * Usually in an effiecient implementation MAC delay is negligable.

    * Transmission delay is only a fraction of overall delay.

    * Many different trade-offs:

        - Transmission delay vs. reliability: as we increase the modulation coding scheme
        setting with which we're operating the wireless front ends, then the transmission 
        delay is decreased but on the other hand, the reliability of the transmission goes
        down because the packet error rate for higher modulation coding scheme typically 
        also goes up.

        - Processing delay vs. reliability: if we use more sophisticated error correction
        schemes at the receiver, then this processing delay in tendency is longer. On the other
        hand, we reap off a higher reliability because we can correct more errors that have been
        happening during the transmission.

        - Control plane vs. data plane: the more control plane data packet transmissions we have, 
        the more we can assure a synchronous operation and a consistent operation of the protocol 
        on that different entities of the network. On the other hand that puts a significant overhead
        cost with respect to latency that payload packets on the data plane experience.

        - Processing delay vs. security/privacy level: the higher these constraints are, so the 
        higher the requirements to fulfill, the more complex algorithms we have to apply in order
        to assure security and privacy and that requires longer processing delay on the particular
        transceiver.

* Computational Architecture

    * ![img]()

    * Most commercial wireless systems today realized as System-on-Chip (SoC)

    * Only MAC processing latency can be varied.

    * MAC processing latency dependent on software implementation.

    * From the AD conversion on, we're basically on the SoC. So once the analog processing and the AD 
    conversion is done, and that happens at the circuits of the radio frequency of the RF front-end, which
    typically takes a really short processing time, then the corresponding samples from radio front end are 
    processed in the physical layer of the transceiver, which is happening by dedicated electronics - that
    are hardware structures that cannot be chanegd, except for maybe activating some of these structures and 
    deactivating other structures. Once these samples are then converted into bits, we're on the MAC layer, and
    there MAC processing is done through a software that is run on a general purpose hardware that can be 
    reprogrammed. And this is where which can only be reprogrammed and an efficient implementation can 
    drastically reduce the postprocessing of a packet transmission and all the other steps of this system 
    cannot be optimized. So to achieve that we need to redesign the hardware structure.

* Summary

    * Realizing low latency is a challange for critical M2M communications.

    * Several factors contribute to the system latency:

        - Medium access control

        - Processing

        - Packet transmission

    * Many Trade-offs exist that influence latency.

    * Unless doing chip redesign, MAC processing is main variable factor.

* Postprocessing is an influencing factor in the communication delay, since the packet is short, two aspects
are more important: The medium access delay and the post processing delay. Both are typically bigger than the 
preprocessing delay and the transmission delay. For postprocessing  typically rather complex and often times 
iterative algorithms need to bo employed to perform error correction decoding.

## **Interference**

* Two challanges to provide highly available M2M systems:

    1- Random behavior of the wireless channel.

    2- Interference

* Sources of Interference

    * Radio communication systems:

        - Same vs. cross-technology interference

        - Co-channel vs, adjacent-channel interference

    * Other man-made technical systems:

        - Microwave ovens

        - Automobile ignition systems

        - Welding

    * Malicious systems: Jamming attack

    * Natural sources:

        - lightning

* Impact of Interference

    * Random disturbing sequence with no meaning to receiver.

    * Interference during ongoing reception:

        - Decreases receiver performance due to higher noise background.

        - Complete loss of signal-of-interest (capture, gain & sync. disturbance) if it happens
        at the begining the transmission, then the calibration process will be disrupted.

    * Interference before incoming reception:

        - Occupy transceiver circuits.

        - Occupy channel if clear channel assessment required.

* Interference Mitigation

    * Arbitrarily complex approaches:

        - Simple: Increase transmit power, use stronger codes & retransmissions, RF front-end 
        discrimination (in which receivers synchronize only to incoming signals that are within 
        a certain range of received power).

        - Medium: Frequency hopping (vacating the communciation channel or vacating the channel
        on a periodic base), directive reception (if the receiver has multiple antennas).

        - Complex: Interference coordination (Typically multiple wireless communication systems
        are connected to a backbone, then the utilization of the frequency at different points in 
        time, and also with spatial signature. Then it's coordicanted by different algorihtms and 
        by different entities), successive interference cancellation.

* Key Factor: Used Frequency Band

    * Operator-based systems:

        - Type of interfernce well understood (same-technology interfernece)

        - Either avoid completely or coordinate

        - => Interference is little threat to availability.

    * Operator-free systems:

        - Diverse set of interference sources.

        - Limited possibility to control interference for some area.

        - => Interference potentially large threat to availability.

* Summary

    * Interference potentially harms availability.

    * Many different sources of interference with different impact.

    * Different interference mitigation strategies:

        - From simple (coding) to complex (coordination).

    * Choice of used frequency band is key

        - Licensed spectrum: Rule out interference impact.

        - Unlicensed spectrum: Interference impact potentially severe.

* The wireless systems are most susceptible to interference at the beginging of the 
transmission, when the receiver calibrates.

## **Fault Tolerance**

* Fault-tolerant design can help to maximize availability!

* Definiton of Fault Tolerance

    * System continues operating "normally" despite a failure occurrence.

    * Failure is defined as the outcome of a fault:

        - Fault: Transceiver fails to receive a packet due to the channel behavior.

        - Failure: Transmitter application is indicated a violation of deadline (missing ACK)

    * Fault tolerant schemes are based on detection, diagnosis and recovery.

    * Is an important feature for high-availability and critical systems.

* Fault Tolerance & Critical M2M

    * Critical M2M systems consist basically of transceivers and channels

        - Faults can occur with both components.

    * Typical channel fault: Packet loss

        - Wireless channel quality

        - Interference

        - Payload vs. control channel faults

    * Typical node faults:

        - Hardware or software faults

        - External issues with transceivers (power supply, external force)

* Examples of Fault Tolerant Design

    * Avoiding Single-point-of-failure

        - Central organization of critical M2M system assuming base station.

        - Provide back-up base stations in case the active one fails and also implement
        algorithms, such that there is a seamless recovery of the system in case that one
        base station fails and the other takes control of the operation.

    * Fall-back Routines:

        - Signaling channel is another source of errors.

        - Define basic communication behavior in case of signaling channel errors.

    * Use of redundant components

        - Extensively done for communication over wireless channel.

        - Provide second front-end for wireless transceivers.

* Summary

    * Complex systems are subject to faults of their individual components.

        - Impacts the availability of the system!

    * Fault-tolerant design ensures system operation despite resulting failures.

    * Several components of critical M2M systems vulnerable.

    * Countermeasures include providing redundancy and fall-back schemes.

* In critical M2M systems faults can occur, however it must be designed such that the system
can continue operation despite a fault.

* Low packet error and High error detection is crucial in critical M2M systems.

## **Security and Privacy**

* Critical M2M & Security

    * Recall: Critical M2M systems optimized for latency and reliability.

    * Cryptographic functions (ensuring security and privacy) are quite complex with respect to
      micro second-processing scale!

        - => Cryptographic functions potentially impact latnecy.

    * Security and critical M2M communications not well-understood so far.

* Physical Layer Security

    * Instead of relying on traditional cryptographic functions, utilize characteristics of the 
      physical layer between two transceivers:

        - Channel characteristics, RF impairments, location characteristics etc.

    * Primarily allows:

        - Generation of the key for symmetric cryptography (unique to the pair)

        - Directly allows to authenticate incoming packets.

        - Very little additional computational costs involved.

        - Probability Density Function of the channel is distinct for different locations.

* Summary

    * Secrecy and authentication are based on cryptographic functions.

    * Traditional cryptographic functions are too complex for critical M2M communication systems,
    especially if low latencies are required.

    * Open problem to date

    * Potential Approach: Physical layer security, utilize unique characteritics of the communicating
    pair for authentication and key generation.

* Physical properties of the channel (signal strength, carrier frequency offset, angle of arrival, ...)
can  be used as a weaker but faster alternative to cryptography.

    