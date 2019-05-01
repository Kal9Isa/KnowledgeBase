# **Massive Machine-to-Machine Communication**

## **Introduction**

* ![img-trends]()

* Massive Number of Things requires:

    * Ultra-low energy
    
    * Ultra-lo cost
    
    * Deep coverage
    
* M2M Scenario

    * ![img-scenario]()

    * Monitoring/metering purpose:
    
        * Electricity/gas consumption, building status, nature observation etc.
        
        * Small packets (few bytes), latency-tolerant, non-critical.
        
        * Requirements will be: Inexpensive devices, self-organizing, long network lifetime.
    
* Technical Challange: Device Lifetime & Cost

    * Major driver for massive scenario: Cost savings

        * Low investment costs: inexpensive devices!

        * Low operational costs: Self-X, battery-driven, long lifetime.

    * How to design low-cost, low-power devices?

    * How to maximize lifetime of networks?

    * How still to achieve self-organization and security?

* Technical Challange: Scalability

    * Potentially, huge number of devices deployed:

        * Electricity metering example - one meter per household, base station connectivity.

        * ![img]()

    * How to manage such large device numbers?

    * How to dimension networks?

    * How to ensure wide coverage?

* Classification of Systems

    * Traditional short range sensor networks:

        * IEEE802.15.4, BLE - Bluetooth Low Energy

        * Ranges up to 100m, extremely cheap, ISM band operation. (2.4 GHz)

            * ISM is the Industrial, Scientific, and Medical frequency band which
            is the publicly available part of the radio spectrum.

    * Newer, long range sensor networks:

        * LoRaWAN, Weightless, SigFox.

        * Several km range, requires operator, ISM band operation below 1 GHz.

    * Cellular M2M systems:

        * EC-GSM, LTE-M, NarrowBand-IoT

            * LTE-M is a subsystem of LTE designed for M2M communications.

            * NarrowBand-IoT is a wireless system for M2M communications.

        * Several km range, requires operator, based on operator frequencies.

* Chapter Overview

* Principles of Massive M2M Communications:

    * Low-Complexity, Low-power Nodes

    * Scheduling and Duty Cycling

    * Access Control for Massive Systems

    * Security and Privacy
    
## **Low-Complexity, Low-Power Nodes**

* How to achieve low-complexity, low-power nodes?

    * Minimun Set of components:

        * interface, sensor, microcontroller, transceiver, antenna, battery.

* Low-complexity Components

    * Microcontroller: Very limited computational capacity, little memory

        * 16-bit RISC, ~10 MHz processor speed, ~100 KB memory

        * Costs: ~$1, for example TI MSP430

    * Sensors: Minimum accuracy and robustness, ideally passive

        * Costs: ~$1, for example SHT11 for temp & humidity.

    * Transceiver: Limited bandwidth, simple waveform, no coding.

        * Costs: ~$3, for example TI CC2420

    * Often microcontroller and transceiver are integrated in one module.

* Low-power Components

    * Transceiver consumes by far the most power during the operations:

        * Microcontroller: ~1 mA @ 3 V during computations

        * Transceiver: ~20 mA @ 3 V for transmission/reception

        * Sensor: ~1 mA @ 3 V during measurements.

    * How to optimize the power consumption of the transceiver?

        * Complex topic, many factors impact this.

    * Basically transceiver can be in different state:

        * Transmission, reception, idle, sleeping.

        * Single and aggregate consumption needs to be considered.

* Low-Power Transceivers

    * Design Goal

        * Effect

    * Reduce transmit frequency:

        *  Better range, lower clock frequency, lower noise and lower 
        front-end power consumption.

    * Reduce transmit power:

        * Lower voltage supply

    * Apply constant-envelope modulation:

        * More efficient power ampilifier, modulation circuitry less
        complex.

    * Utilize higher modulations:

        * Shorter active periods.

    * Increase receiver sensitivity:

        * Lower transmit power.

    * Lower leakages/start-up time:

        * More efficient sleep mode/transition

    * ![img-trasnceiver]()

* Summary

    * Reduce complexity by limiting the functional components:

        * Microcontroller, sensor, transceiver, battery.

    * Power consumption mainly driven by transceiver:

        * Minimize power consumption of transceiver is involved.

    * Four modes: Transmit, receive, idle, sleep.

        * Transmit and receive almost same consumption.

    * Transceiver power consumption minimized by

        * Lowering frequency, transmit power, leakage.

* Lowering the transmission frequency leads in particular to a better
transmisson characteristic over the distance, this is the biggest advantage 
as in general, lowers the amount of time that M2M device need to be in 
transmit or receive mode which are the modes that consume the most power. 
In contrast, lowering the clock frequency reduces the consumed power 
only marginally but generally lowers the cost of the device.

## **Scheduling and Duty Cycling**

* Year-long Device Lifetime?

    * Key question in sensor networks/massive M2M communications: 
    Devices are supposed to run for years on low-capacity batteries, how to 
    achieve that?

    * Despite low-complexity, low-power transceivers, sensor nodes can not 
    operate for years unless we carefully steer operations.

    * Key solution is to minimize the activity time of the nodes as much as
    possible according to application needs. --> Duty Cycling.

* Duty Cycling

    * Set nodes to be in sleep mode for an extended amount of time, and have 
      the node only wake up for a short time span during which data can be 
      transmitted or received.

        * Tcycle = Ton + Toff ,     Toff > Ton

    * Duty cycling ratio: Ratio between active time and cycle duration.

    * Scheduling: Synchronous and Asynchronous duty cycling.

* Synchronous Duty Cycling

    * ![img]()

    * Sender/receiver pair wakes up simultaneously to exchange data.

    * Wake-up times determined by previous beacon exchange.

    * Efficient network operation possible for small group of nodes.

    * Requires synchronized clocks, does not scale to larger settings.

* Asynchronous Duty Cycling

    * ![img]()

    * Sender wakes up arbitrarily and tries to reach destination, referred 
    to as channel sampling.

    * Successfully received packet needs to be acknowledged.

    * No coordination overhead, no synchronization required.

    * Channel sampling costs energy.

Duty Cycling Example: 

* IEEE802.15.4

    * Beacon | CAP | CFP | Inactive Period  radio frame on a time axis.

    * Nodes wake up synchronously

    * Coordinator node transmits beacon frame (sync event)

        * Information on frame structure, i.e. sleeping duration.

    * Data transmission on CAP and CFP.

    * At the end of active period, node switch to sleep.

    * Max frame duration: 252 s => min. duty cycling ratio of 0.006%

    * Challange: Clock Drift

        * ![img]()

        * Extreme duty cycling ratios lead to long lifetimes.

        * Resynchronization necessity: Transceiver clocks drift over time 
        due to imperfect materials used in production.

        * Lower-drifting clocks are more expensive.

* Summary

    * Key element to energy saving: Duty cycling

    * Essentially, switching the entire network to sleep mode.

    * Synchronous and Asynchronous duty cycling.

    * Low duty cycling ratios lead to long lifetimes.

* Collison can occur with asynchronous duty cycling.

## **Access Control for Massive Systems**

* The Massive Access Problem

    * Assume a long-range system (like LoRaWAN or LTE-M)

        * Cells easily cover a few km of area.

        * Potentially, thousands of nodes might be deployed.

    * With duty cycling, these nodes will periodically try to access
    the system, for example to push a sensor reading through the uplink.

    * If many nodes try this simultaneously, the network becomes congested, 
    preventing the nodes from successful transmission, which wastes energy 
    and reduces lifetime.

* Potential System Bottlenecks

    * Air interface: Nodes contend for limited radio resources.

    * Backbone servers: Connection requests need to be registered and processed,
    servers have limited computational capacity.

* Air Interface Bottleneck

    * Reactivated nodes need to acquire radio resources.

    * Always some from of ranodm access channel involved.

    * If too many nodes contend, this channel breaks down.

    * ![img]()

        * If the node gets the Contention Resolution, it means they can join the 
        network and use the resources.

    * Example LTE: 64 preamble codes, selected randomly by node => code collisions,
    no follow up reply by base station, nodes go in back-off.

    * LTE practise: Collision probability already significant if 20 nodes compete for 
    access.

* Solution: Access Class Barring

    * Example: 

        * Each node i generates a random number ai

        * Base station announces a threshold θ between 0 and 1. its value is 
        determined by the ratio of how many nodes we want to access the AP out of 
        all the nodes.

        * Node waits for base station to get i, then only attempts access if ai < θ.

        * Results: Lowers contention, allows thousands of nodes to operate.

* Backbone Bottlenecks and Protection

    * Several backbone servers involved in M2M transmissions

    * Overload generated from multiple cells can occur.

    * Locally detected by built-in functions, and then either laod is locally dropped 
    or back-off indications sent back to the cells.

* Summary

    * M2M communication systems are vulnerable to overload:

        * Air interface as well as backbone server bottlenecks.

        * Only applies to long-range systems.

    * Access class barring solves the air interface bottleneck.

    * Load shedding and load reduction solve the backbone bottleneck.

* Load shedding simply ignores some requests when the server is under heavy load.

## **Security and Privacy**

* Security and Privacy Challanges

    * Low complexity, low power: Restricts use of cryptographic algorithms.

    * Massive, dense deployment: Complicates key management.

    * Wireless broadcast channel: Vulnerability to denial-of-service attacks, 
    necessitates authenticated routing broadcast.

    * Network data aggregation: Requires secure point-wise communication and 
    routing.

* Cryptographic Algorithms

    * Large number of nodes => Public-key cryptography preferred.

    * Public-key cryptography is complex and power-consuming.

        * Encryption/decryption operations consume seconds on low-complexity nodes.

        * ![img]()
    
    * Symmetric cryptography is executed faster and consumes less power.

        * About a factor of 10 faster and lower energy consumption.

        * ![img]()

    * Symmetric is preferred in M2M systems.

* Key Management

    * Key management challanged by:

        * Complexity of public-key cryptography.

        * Massive amount of nodes, consumes too much memory to store pair-wise keys.

    * Proposed key management schemes utilize symmetric cryptography:

        * Pre-distribute a shared key with a centralized point, and another one between
        all nodes in the network.

        * From that, generate pair-wise and/or cluster keys at run-time.

    * Alternatively, use public-key approach to exchange a symmetric key.

* Data Aggregation

    * Sensor fusion: communication is expensive, only forward data if necessary.

        * Results: Data aggregation protocols eliminate redundancies.

    * Aggregation and confidentiality are conflicting targets!

    * Approaches:

        * Aggregate on clear-text, requires end-to-end encryption/decryption.

        * Aggregate on ciphered text, reduces level of security.

* Privacy Aspects

    * Massive M2M systems => Open significant privacy concerns!

    * Countermeasures:

        * Access to data only to authenticated peers over encrypted channels.

        * Generally, access only to non-critical data, i.e. averages etc.

        * Distributed organization of data in s sensor network.

* Summary

    * Massive M2M systems have security and privacy challanges:

        * Low complexity processing hardware.

        * Large number of nodes.

        * Wireless broadcast channel.

    * Solutions rest on symmetric encryption and good key management:

        * Enables secure routing as well as data aggregation.

        * Privacy achieved through proper data handling.
