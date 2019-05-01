# **Architecture-and-General-Principles**

## **What are the visible elements of a mobile network**

* The Terminal

    * The Terminal is called UE, User Equipment in the LTE standard.

    * To work, it must be equipped with a Subscriber Identity Module card (SIM).

    * The SIM contains:

        * The subscriber identity unique throughout the world.

        * The subscription data (e.g. the subscription identity).

    * The SIM

        * Is called more precisely, Universal SIM (USIM) for 3G/4G

        * Is provided by the operator.

        * It can be found in a 4G Key, or a router also.

* Antenna

    * A radiating device that transforms high frequency alternating current (AC)
    into electromagnetic waves or the other way around.

    * Sometimes they're installed on a mast and beside a technical cabinet.

    * In the technical cabinets are a set of transceivers that will enable radio
    transmission between the therminal (the transceiver) and the netwrok.

* The Base Station Antennas

    * Base Station: set of transceivers in one place.

    * Each base station is equipped with antennas.

    * Terminals around the base station can communicate with the base station by
    radio transmission.

    * In 4G technology, a base station is called eNodeB (eNB):

        * e for "evolved" (evolution in comparison with 3G).

        * Node because the base station is inserted in a network.

        * B for Base station.

* A mobile network is a group of base stations spread out over a territory. and
are connected to an IP network of the cell phone operator and it's interconnected
to the internet through the IP networks of other operators via routers.

* Access Network and Core Network

    * evolved Universal Terrestrial Radio Access Network (eUTRAN)

        * Consists of a group of eNodeBs that are connected to the same IP network
        so they can communicate with each other.

    * Evolved Packet Core (EPC)

# **The Cellular Concept**

## **How is it possible that I can communicate anywhere**

* The Need to cover the entire territory with base stations.

    * The transmission power of a UE is typically 0.2 W (200 mW).

    * The maximum range is typically several kilometers for a signal of this strength.

    * The operator deploys base stations on the territory to be covered so that a 
    terminal is always less than a few kilometers away from a base station.

    * Areas without coverage are known as "White Areas".

* General Principle of the Beacon Channel

    * Each base station broadcasts a signal regularly.

        * Which indicates its existence.

        * Which gives the characteristics of the network. (e.g. identity of the operator)

    * Concept of the beacon channel. (broadcast control channel)

    * By measuring the strength of the signal received, each terminal can indicate if it
    receives the base station well or not.

* Capacity and Coverage

    * Dividing the territory up into cells.

        * Each cell is served by a base station.

        * The division into cells is not perceptible to the user.

            * Passing from one cell to another is ideally, imperceptible.

        * The capacity of a cell in Mbit/s does not depend on the size of the cell.

    * Urban Zone = High user density

        * The base stations are deployed to provide sufficient "Capacity".

        * Deploy enough base stations so that the capacity in Mbit/s per km2 is superior
        to the traffic created by the customers.

    * Rural Zone = Low user density

        * The base stations are deployed to insure "Coverage".

        * Deploy enough base stations so that, at every point of the territory, a 
        terminal is under the range of a base station and can connect.

# **Nodes With Data Plane (SGW, PGW)**

## **Where do the packets pass when I consult a server**

* The Packet GateWay (PGW)

    * The Internet cannot manage mobility.

    * The data packets must be routed to a "gateway": PGW.

    * ![img-PGW]()

    * PGW

        * Routes data to the terminal and termical data to the internet. (through operators 
        PGW and IP network)

        * Ensures certain security functions.

    * Several PGWs may be required to have redundancy and ensure reliability.

* The need for an internediary gateway

    * Since the UE is mobile, we need an intermediary system for devices in cell network to
    send the packets to the current eNodeB of the UE, to avoid rerouting which requires some 
    signaling messages to be traded between network devices.

* The Regional Gateway or Serving GateWay (SGW)

    * They serve a geographical zone.

    * An SGW enables:

        * Collecting data sent by the mobile terminals through various eNodeBs.

        * The distribution of data coming from servers to eNodeBs where the terminals are 
        located.

        * ![img-SGW]()

# **Nodes of the Control Plane (HSS, MME)**

## **Can I use my terminal freely on any network**

* The need for control procedures.

    * Before data can be transmitted by a terminal, there are several access and control 
    procedures.

* The Home Subscriber Server (HSS), Subscriber Database

    * Contains the profile of all the network subscribers. such as services they use or 
    their imprecise location.

    * It was called Home Location Register (HLR) in 2G/3G.

    * There are also security data which enables access control.

    * The HSS only exchanges signaling.

    * Signaling: set of messages exchanged to manage network access, tracking terminals
    when moving and etc.

    * To check the access permission of a subscriber we use signaling.

    * Mobility and the sporadic nature of terminal activity lead to sending (or receiving)
    frequent signaling by the terminal.

* Mobile Management Entity (MME)

    * The objective of MME machine is to control mobility. which controls the subscribers 
    present in the zone.

    * Attachment of the terminal to the network upon powering up, means when you turn your 
    terminal on, it sends a request to eNodeB which will forward the request to the MME at 
    the moment that we call "Attachment to the network" and then MME checks to see if it 
    knows the subscriber. if not HSS will transfer the profile of the subscriber along with
    security data to MME so each time an access verification is required, it will be done 
    locally by MME to reduce the load on HSS.

    * Signaling exchanges occur between terminal and MME.

* Principle Functions of the MME

    * Communicates with a set of base stations.

    * Communicates with HSS to get the profiles and the security information of the subscribers
    present in the zone it manages.

    * Stores these profiles and security data.

    * Manages control mechanisms related to network access, security and mobility for terminals
    present in its zone.

    * Maintains awareness of the location of terminals in its area.

    * Selects the PGW and the SGW when the terminal attaches to the network and connects to 
    internet.

    * Ensures the reachability of the terminal.

    * Is involved in handover. (handoff)

        * Handover: the possibility of keeping a session active when the user moves and changes
        cells.

# **Synthesis of the Architecture and Interfaces (S1. S5/S8, S6a, S11, X2)**

## **What is the architecture of the 4G network**

* Physical Interface vs Logical Interface

    * All the network equipment has a protocol stack from the IP family.
    
    * ![img-architecture]()

    * The IP network of the operator is made up of routers.

    * Equipment can communicate between each other even if they're not directly physically 
    interconnected by a link: communicate via the IP network.

* Interfaces between equipment of the network core

    * SGi interface

        * Between the PGW and the external IP network. (Internet)

    * S5 interface

        * Between the SGW and the PGW. (same network)

        * Transporting user data + a few signaling messages.

    * S11 interface

        * Between the SGW and the MME

        * Transporting signaling messages.

    * S6a interface

        * Between the MME and the HSS

        * Transporting signaling messages.

    * S1-MME interface

        * Between the eNodeB and the MME.

        * Transporting signaling messages.

    * S1-U interface

        * Between the eNodeB and the SGW.

        * Transporting user data, no signaling exchange.

    * X2 interface

        * Between 2 eNodeBs

        * Transporting user data and signaling messages.

    * Uu or Radio interface

        * Between the terminal (UE) and the eNodeB.

        * Transporting user data and signaling messages.

    * S8 interface

        * Between the SGW and the PGW of another network.

    * S13 interface

        * Between EIR and MME.

    * Gx interface

        * Between PCRF and PGW.

* Interconnection of Network Cores

    * Principle of International Roaming.

    * Uses S8 interface to transfer data.

* Otehr equipment and interfaces not covered in the course

    * ![img-general architecture]()

    * Equipment Identity Register (EIR): terminal database of terminals stolen.

        * Interface S13 with MME.

    * Policy and Charging Rules Function (PCRF): service quality management.

        * Interface Gx with PGW.

# **Structure of the MOOC**

## **How is this course structured**

* A 4G network consists of:

    * UE

    * eNB

    * SGW

    * PGW

    * HSS

    * MME

* In week 2 we will look at security procedures and the initial attachment of UE 
  to the network.

    * We will look at the interaction between UE, eNB, MME and MME and HSS.

    * We will see the mechanisms in place to stop just anyone accessing the network
    or anyone who is listening for what a user transmits or receives.

* In week 3 we will concentrate on the radio interface.

    * To present the essential elements to understand how exchanges happen between 
    the UE and eNB.

* In week 4 we will look at how transmissions of data flows are organized with the 
  concept of tunnels between PGW, SGW and eNB.

    * we will see how signaling exchanges are organized between the UE, eNB and the 
    MME.


* In week 5 we'll look at how the sporadic nature of data flows is managed.

    * We'll see how tunnels are established and how we manage transmissions.

* In week 6 we'll look at mobility.

    * Mobility when UE is on but not used or when it's used it for exchanegs.

    * Handover mechanisms and location management mechanisms.

# **European History of the Mobile Networks**

## **What do 2G, 3G, 4G mean**

* Frequency Divison Multiple Access (FDMA) is the principle to transmit a communication
  on a frequency.

    * From 1980 to 1995

    * Used analog transmission.

    * Only able to telephony.

* Global System for Mobile communications (GSM) was the first transmission digital 
  transmission network.

    * Time Division Mulitiple Access (TDMA) is the principle to use one frequency to 
    transmit several communications by deviding the time into slots, each slot supporting 
    one communication.

    * Are called 2G, and are only able to telephony and exchange SMS.

* Global Packet Radio Service (GPRS) was added on top of 2G for packet access and new 
  modulation.

    * Updated with an evolution Enhanced Data rate for the GSM Evolution (EDGE). which
    increased GPRS's throughput.

    * Able to telephony, SMS and IP access at 100 kbit/s.

    * Known as 2.5G.

* Universal Mobile Telecommunication System (UMTS)

    * Uses Code Divison Multiple Access (CDMA) which is based on spread spectrum.

    * Increased IP access data rate to 1 Mbit/s

    * Called 3G.

* High Speed Data Packet Access (HSDPA) completed 3G networks.

    * Increased throughput by changing the modulation.

    * Increased IP access data rate to 10 Mbit/s.

    * Known as 3.9G.

* Long Term Evolution (LTE)

    * Just the transmission of IP packets between hosts.

    * Increased IP data access rate to 100 Mbit/s with low latency.

    * Transmission on radio interface is used by Orthogonal Frequency Divison Multiple
    Access (OFDMA). It enables parallel transmission using mathematical processing.

    