# **Introduction - Requirements of Cyber-Physical Systems**
    
## **Examples of CPSs**

* Industrial manufacturing systems.

* Autonomous systems

* Power grid
    
## **CPS definition**

* CPSs are co-engineered interacting networks of physical and computational components.

* CPS record physical data using sensors and affect physical processes using actuators. 
they are furthermore potentially connected and interacting with other CPS.
    
## **CPS characteristics**

* A CPS involves some form of sensing, feedback, control and actuation.

* There are different types of CPS referring (among other things) to the:

    * Scale (size) of the CPS
    
    * Level of life-cycle integration of the CPS
    
    * Level of automation and whether the CPS directly includes humans.
    
    * Domains: A specific CPS will refer to one or more domains and thus relate to specific 
    requirements and regulations.
    
## **Theorical Base of CPS: Control**

* Open Loop --> No feedback, simple system behavior.

* Closed Loop --> Control based on feedback, can result in complex system behavior.

* Principle of Closed-Loop Control:

    * Its components are: Controller, Controlled System and Measurment System.
    
    * ![](img-1)
    
    * the controller gets an input based on a set-point from an external system, then it
    generates an error based on the state of the system, then it sends a command to the 
    controlled system which we would like to stabilize. then there is a feedback loop from 
    the controlled system to the measurment system which would evaluate the values and then 
    its response is sent to the controller.
    
## **Control Loops and CPS**

* Control thory provides idealized base for CPS.

* CPS, however, deal with many more implementation aspects:

    * Which processor to use for the implemented control algorithm
    
    * How to implement the corresponding algorithm
    
    * How to control the cycle time of the system
    
    * Which network to use to connect all components
    
    * How to protect the system against malicious interaction
    
    * How to guarantee various features except stability of the plant
    
## **Outline of the Chapter**

* Dependability of CPS

* Networks for CPS

* CPN


# **Dependability of Control systems and CPS**

## **PID Regulator**

* Proportional Integral Derivative (PID)

* Different aspects of the error can be used for correcting the system:
    
    * Use instaneous error, possibly rescale it. (proportional factor)
    
    * Use history of the error. (integral)
    
    * Consider the trend of the error. (derivative)
    
## ** Realizing Closed Loop Control**

* Sensor, actuator and controller need to be connected.

* Realized by __communicaton system__  which introduces delays and losses!

    * ### **Impact of Delay and Losses**
    
        * Consider the PID controller:
            
            * Assume sensor readings are randomly delayed.
            
            * Controller receives outdated state with large error.
            
            * Controller will regulate strongly, although plant is in a much better state.
            
            * Can lead to strong oscillations of the plant!
            
        * Losses potentially have equally negative effect.
        
        * In general we should avoid losses and delay of the network for control systems.
        
## **Generalization to CPS**

* CPS also actuate on sensor readings.

* They're equally impacted by latencies and losses of the network!

* In contrast, we would like CPS to be dependable:

    * The ability to deliver service that can justifiably be trusted.
    
    * Dependability of a system is the ability to avoid service failures that are more frequent
    and more severe than is acceptable.
    
## **Communication Requirements of CPS**

* Dependable CPS require the associated communication network:

    * To deliver messages within a target latency.

    * To guarantee the correct delivery of the message with a target probability.
    
    * To protect message delivery from security threats.
    
    * To take measures that ensure the privacy of CPS.
    
## **Summary**

* Any CPS or control system require communication networks to deliver messages between the 
elements. (sensors, actuators, controllers)

* The network typically have a latency and can lead to message losses.

* Potentially, these latencies and losses lead to severe impairments of the CPS.

* Thus, dependable CPS have tight requirements regarding latency, losses, security and privacy 
of underlying communication networks.

# **Networks for Cyber-Physical Systems**

## **Human-Centric Applications**

* Networks have been traditionally designed for humans.

* Typical applications are telephony or exchanging messages.

* These applications have relatively relaxed requirements regarding latency and reliability 
of the data transmission

    * For example, real-time voice or video communication requires about 200ms end-to-end 
    latency with packet loss rates below 5%.
    
    * Data applications (message exchange, or surfing the internet) require 0% packet loss rate
    but have no latency requirements.

## **Time Resolution of CPS**

* Time resolution is essentially the operating cycle or the operating period of the chain, of the
sensor, the actuator and the controller.

* Time resolution of different industrial CPS:

    * 10 μs: Positioning of cylinder in offset printing (0.2 mm @ 20 m/s).
    * 100 μs: Clock resolution in high-speed vehicles (1 cm @ 360 km/h).
    * 1 ms: Typical resolution time in factory automation.
    * 10 ms: Typical resolution time in process industry.
    
* Given a certain time resolution of the CPS, the processing speed of the underlying network 
must be much faster to allow still for processing at the elements of the CPS (factor of ten at least).

## **Reliability Requirements**

* Latency reuirements are usually coupled with reliability requirements --> Real-time requirements!

* Distinguish:
    
    1. Hard real-time requirements: Meet all latency constraints exactly (i.e. deterministic 
    behavior with respect to deadline under normal system operation conditions).
    
    2. Soft real-time requirements: Meet latency constraints only most of the time (with a specified
    reliability level under normal system operation conditions).

* ![image of reliability table]()

* **Example**

    * Assume a system with Safety Integrity Level 2 (SIL2) safety level (error rate of 10^-6 per hour).
    
    * Error rate needs to be distributed over all system elements!
    
        * Netwrok connection the elements should follow 1% rule:
        
        * ![image of a sample system]()
        
## **Networks for CPS**

* Requirements of CPS very different to human-centric applications.

* Normal human-centric networks can not be applied for CPS.

* These issuse lead to development of specialized networks called "fieldbus"

    * ![image of the car connected by fieldbus]()
        
## **Summary**

* Human-centric applications have relaxed latency and reliability requirements.

* In contrast, CPS have very strict latency and reliability requirements.

    * Miliseconds latency and extreme reliability requirements at the same time!

* Therefore, traditional networks can not be applied for CPS.

* Lead to the development of the fieldbus

# **Cyber-Physical Systems**

## **What is a FieldBus**

* A wired data network, interconnecting a CPS, characterized by:

    * small data packets (process variables) with bounded delay (1 ms .. 1 s).
    
    * Harsh enviornment (temperature, vibrations, EM-disturbance, ...).
    
    * Dependable (no undetected errors, redundant layout).
    
    * Clock synchronization (miliseconds to microseconds).
    
    * Moderate data rates (50 kbit/s - 5 Mbit/s).

    * Large distance range (10 m - 4 km).

## **Basic Principle FieldBus**

* ![Basic FieldBus]()

## **Example Fieldbuses**

* Controller Area Network (CAN)

    * Developed for automative applications in the 80s.
    
* PROFIBUS

    * Developed for industrial process control in the 80s.
    
* Industrial Ethernet (EtherCat, PROFINET, ...)

    * Developed on top of Ethernet in the 90s.

## **Fieldbus Challanges**

* Were developed in 80s and 90s.

* Major limitaions come from the wired cabling

    * Limits flexibility and mobility of (elements of) CPS.
    
    * Damage of cable shuts down the network.
    
    * Scalability
    
    * Weight
    
## **Cyber-Physical Networks**

* The core idea is to overcome limitaions and challanges of Fieldbus.

* Wireless systems could solve these challanges.

* But traditionally not applied for dependable application scenarios.

* ![CPN graphical representation]()

* There are two scenarios:

    1. A massive number of sensors, monitoring and metering applications connecting to an
    Access Point and send all their data through that to a Server that collects this data 
    and sensor readings. (Unidirectional communication)
    
    2. The other is that there are Critical sensing and actuation processes that are connected
    to a Point of Control (Server) through an Access Point and this server generates a control 
    command just like a closed loop control system. here latency and reliability play a crucial 
    role in the elimination of entire system.
   
