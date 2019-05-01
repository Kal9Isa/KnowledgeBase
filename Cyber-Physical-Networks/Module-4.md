# **Higher-layer Networking for Cyber-Physical Networking**

## **Introduction**

* Networking Stack & CPN

    * ![img]()

    * Physical and Data Link layers have been the focus of the previous 2
    modules on Massive M2M and Critical M2M communications.

* Technical Challange: Overhead

    * Massive M2M systems optimized for energy efficiency and scalability.

    * Monitoring and metering functionality to be provided in WAN context.

    * Relative big overhead incurred by the IP headers.

        - => Reduces energy efficiency of networks!

    * How to mimimize the impact from WAN functionality?

* Example: Few bytes MAC/PHY overhead + few bytes payload => Few bytes MAC/PHY overhead +
48 Bytes UDP/IP headers + few bytes payload.

* Technical Challange: Low Latency

    * Extend low latency characteristics of air interface to WAN context.

    * WAN protocols like IP don't come with any latency guarantees.

    * Large physical separations incur natural (rather large) latencies.

    * What are the WAN latency requirements of typical applications?

    * How to achieve low latencies for the applications?

        - Air interface low latency

        - End-to-end low latency

* Technical Challange: Critical Applications

    * Safety-critical applications: Potential damage of humans/goods

        - => If hard deadlines are violated.

    * But: Even best system design might lead to breach of deadline.

    * Unlikely, but with very low probability this might happen.

    * How to deal with such violations to avoid critical damage?

* A network layer header is needed to route a packet from one machine to another
through internet.

* A transport layer header allows for distinguishing between different applications
running on the same computer/machine.

* The combined size of a full IPv6 header and a UDP header is 48 bytes.

## **OverHead Reduction**

* Example: IEEE802.15.4 Network

    * PHY data unit has maximum length of 127 Bytes.

    * MAC header consumes 9 Byte + 4 Byte CRC at the end.

    * Effective PDU size: 113 Bytes

    * But: UDP/IPv6 header consumes another 48 Bytes.

    * Practically almost halves the protocol efficiency.

    * ![img]()

* Technical Solution: Overhead Reduction

    * Eliminate redundancies:

        - IEEE802.15.4 MAC header and UDP/IPv6 headers both indicate packet length,
        and addresses of destination/source.

    * Strip-off non-essential or well-defined functionality

        - Optional fields in IP header (traffic class, flow label), prefixes (if known)

    * Gateway translates between contexts (adaptation layer).

    * All this functionality (and more) provided by 6LowPAN.

    * ![img]()

* Summary

    * WAN functionality important for massive M2M systems.

    * Introduces additional significant overhead, reduces energy efficiency.

    * Eliminate redundancies of headers and non-essential functions.

* If a packet is sent from a sensor to a server we can omit the source address, to compress
the header.

* 6LowPAN reconstructs an omitted IPv6 address from the MAC header addresses.

* The 6LowPAN Access point/Gateway must decompress the header before the packet can be 
forwarded to the internet. Since the Access Point can read the source address from MAC header
it can identify the original sender.

## **Latency Reduction for Critical Applications**

* Technical Challange: Low Latency

    * Point of control/computation typically somewhere in the internet (cloud services)

    * IP provides merely layer 3 connectivity, but no guarantees.

    * Typical latencies to cloud resource are high (several tens of miliseconds and more), 
    cloud centers are geographically far away.

    * How to achieve low latencies for critical control applications?

* Technical Solution: Edge Computing

    * Introduce a new type of computational service: Edge computing.

    * Smaller computational resources, residing at the network edge.

    * Physically close, one or two hops away.

    * Also referred to as Fog computing or cloudlets.

    * Application area spans also into analytics.

    * Moible network operators typically don't offer such resources yet.

    * Many open research problems in this area.

* Summary

    * Critical control application require a point of computation.

    * Legacy internet architecture: Cloud resources for computation.

    * But too far away, no latency guarantees.

    * Edge computing: Bring the computation resources closer to applications.

    * Drastically reduce latencies.

* Ideally the edge computing resources are deployed close to base stations of
the mobile network.

* There are no guarantees for the end-to-end delay between two points on internet, 
as no resources are reserved along the routing path in the internet. Forwarding is 
based on the principle of best effort.

## **Critical Applications Interfacing**

* Overhead reduction and Edge computing focuses on Network and Transport layers.

* ![img]()

* Example : Sensor is a light barrier (operation box), actuation command is then to 
  stop a robot in a manufacturing hall (fail-safe state). Assumption is that a human
  passed the light barrier and is in danger. Maximum reaction time of the entire loop 
  is 10 ms. How to protect the human againt losses of transmissions?

    - => Any networked system can be turned into a safe system! However, if network is 
    unreliable, many transitions to fail-safe state occur, which reduces the availability 
    of the system.

* Techincal Solution: Safety Layer

    * Add a software entity on top of the network at all application points.

    * This entity operates without knowledge of the underlying network. (Black box principle)

    * Periodically, packets are sent from one entity to another.

    * If out of n such messages m, are not recived, entity fires an alarm.

    * Alarm drives the control system to fail-safe state. (halt the roboter!)

    * Resolution from fail-safe state can only be done by human interventions.

* Summary

    * Critical applications rely on keeping hard deadlines.

    * Networked systems can never guarantee this to 100%.

    * Introduce an application layer entity that guards network output.

    * If network becomes unreliable, fail-safe transition is activated.

    * Allows to make any networked system safe.

    * Potential drawback is availability of the system.

