# **Programming in IoT**

## **Introduction**

* Programming in IoT

    * By the end of this module you will be able to:

        * Recognise where programming is needed in the IoT process

        * Examine programming logic and identify key programming languages

        * Develop a definition of Big Data and its defining characteristics.

    * What is Programming?

        * The process of creating a set of instructions that tell a computer
        how to perform a task or sequence of tasks.

        * The engineering aspect focuses on descovering and implementing the
        most efficient algorithms to address a specific class of problems.

## **When Programming is Needed**

* Programming for Feet

    * At an application level, the programming allows the devices to talk to
    other devices or machines and to respond to the data with actions.

    * Case Study: Foot Drop Analysis

        * From the initial measurments we have:

            - The acceleration in 3 axes.

            - The magnetic field in 3 axes.

            - Velocity in 3 axes.

        * There are two stages of programming at the moment:

            - The Harverst Codes, that organizes the data recieved from the 
            sensors and communications and then written as a CSV file.

            - The Post Processing, which focuses on filtering and cleaning of
            the data to make sense out of it.

        * Once the data is captured and normalized and filtered in case of any
        noise, they will provide the angle of the movement for each body
        section.

        * Usually for a normal type of gait pattern, the foot and thigh and shank
        should have both positive and negative peaks in different cycles of
        movement. However in foot drop, one of these negative values goes missing 
        which produces a different pattern from normal subjects.

* What Programming Where?

    * Use Case: Smart Sprinkler System

        - Existing programming to make weather forecasts and records avilable online.

        - Programming to read from sensor and detect moisture levels, collate and send
        sensor data.

        - Programming to communicate between application and actuator.

        - Programming to put together weather predictions and sensor data to make smart
        decisions about watering time.

        - Embedded programming to control water release and shut off.        

## **Programming**

* Programming Languages

    * Python is used as a high-level language to code fast and time-efficiently.

    * To code for smaller processors with limited resources, C and Fortran are the best 
    tools to go with along with C#.

    * To Visualize data and analyze them, using a statistical language like R would be 
    useful, however that also can be done in Python aswell.

    * 12 Popular Programming languages for IoT Development

        * Top four favoured languages for IoT by developers:

            - Java

            - C

            - JavaScript

            - Pyhton
        
        * There are 3 major sections in an IoT architectural enviornment. These are the 
        sensors that generate the data, the local gateways or hubs that organize it, and 
        the geographically distant and centralized servers where all the data ends up.

        * Using C for sensors that need RAM is highly efficient.

        * Assembly

            * It's a great option if you want to keep your IoT applications compact.

        * B#

            * Originally was developed for small applications and it can be used on multiple
            platforms using Embedded Virtual Machine (EVM).

        * C

            * Useful for embedded devices

        * C++

            * An Object Oriented version of C that is pre-processed.

            * Required when you need processing power.

        * Go

            * It's like C but it allows devices to work together to send and receive data in 
            many channels simultaneously. But there's a high possibility for data loss or errors
            if not managed properly during the coding phase.

        * Java

            * It's well known to enable debugging code on a computer and then moving it to a chip 
            via a Java Virtual Machine (JVM).

            * Write it once, Run it anywhere.

        * JavaScript

            * The popular offshoot in IoT development has been Node.js as much of the work is 
            focused on hubs and servers to gather the data and store it.

            * Two microcontrollers that run JS from the start are Espruino and Tessel.
        
        * Parasail

            * Used for Parallel programming applications.

        * PHP

            * Used to develop microservices

        * Python

        * Rust

            * Is enabled to share information among different channels automatically. However, 
            one drawback is that for Rust to function properly, the processor must be enabled to
            support concurrent processing.

        * Swift

* Main Considerations for Programming IoT

    * Small devices generally have:

        - Limited power supply

        - Limited computational power

        - Limited Memory

    * Other languages include:

        - R

        - Form

        - Hive QL

        - Pig Latin

        - Julia

## **Data and Big Data**

* What is IoT Data?

    * Traditionally Information has come into our house in different ways:

        * Television: uses a connection to either aerial or satellite dish

        * Telephone: comes through the telephone connection.

        * Internet and Email: comes through an internet connection.

    * In a converged network there are still many points of contact and many 
    specialized devices, but there is only one common network infrastructure 
    that uses the same set of rules, agreements and implementaion standards.

* Digital Data

    * Digital data is represented using a binary system of 0s and 1s.

    * Data is packaged into Bytes- bite sized pieces that can travel along the
    network from one device to another using various protocols.

    * Bytes are sometimes further split into Nibbles (4 bits).

    * Big Data: is data sets that have become so large and so complex that 
    advanced programming and processing is required to capture the data, and 
    then appropriately store, analyse, search, share, transfer and visualise it.

* The Pawsey Centre and Big Data

    * International Centre for Radio Astronomy Research (ICRAR) is building the 
    Square Kilometre Array (SKA), the world's largest scientific facility and the 
    most sensitive telescope ever developed. Which means they have to come to terms
    with collecting and organising Big Data which consists of massive amounts of radio
    telescope data.

* Real-time Data and Historic Data

    * A component in the car Called Diagnostic Bus, gathers data from sensors and passes
    it to a gateway, then the data gets sorted and integrated there and this way only the
    most relevant diagnostic messages are sent to manufacturer.

* Data Types

    * IBM describes the 4 V's of Big Data as:

        * Volume/Quantity: big data observes and tracks what happens without sampling.

        * Velocity/Speed: big data is generally available in real-time.

        * Variety: big data extracts from multiple sources such as texts, images, audios
        and videos.

        * Veracity/Data Quality: whether is stays true, or some is lost or damaged.

* Playing with Data

    * Data Sort Strategies

        * Bubble sort: compare two items, swap if necessary, otherwise move to the next pair.

        * Insertion sort: Extending a sorted array of items inserting one item at a time.

        * Quick sort: choose an item as a flag and move all the other items in comparison to 
        that.

* Big Data and the Cloud

    * The roles of cloud computing and fog computing in the Internet of Things revolution

        * IBM has helpfully broken down cloud computing into six different categories:

            - Software as a service (SaaS): Cloud-based applications run on computers off site 
            (or "in the cloud"). Other people or companies own and operate these devices, which connect 
            to users' computers, typically through a web browser.

            - Platform as a service (PaaS): Here, the cloud houses everything necessary to build 
            and deliver cloud-based applications. This removes the need to purchase and maintain 
            hardware, software, hosting, and more.

            - Infrastructure as a service (IaaS): IaaS provides companies with servers, storage, 
            networking, and data centers on a per-use basis.

            - Public Cloud: Companies own and operate these spaces and provide quick access to 
            users over a public network.

            - Private Cloud: Similar to a public cloud, except only one entity (user, organization, 
            company, etc.) has access.

            - Hybrid Cloud: Takes the foundation of a private cloud but provides public cloud access.

        * Amazon Web Services, one of several IoT cloud platforms at work today, points out six advantages 
          and benefits of cloud computing:

            - Variable expense allows you to only pay for the computing resources you use, and not more.

            - Providers such as AWS can achieve greater economies of scale, which reduce costs for customers.

            - You no longer need to guess your infrastructure capacity needs.

            - Cloud computing increases speed and agility in making resources available to developers.

            - You can save money on operating data centers.

            - You can deploy your applications worldwide in a matter of minutes.

        * Fog computing is more than just a clever name. Also known as edge computing, provides a way to gather 
        and process data at local computing devices instead of in the cloud or at a remote data center. Under this 
        model, sensors and other connected devices send data to a nearby edge computing device. This could be a gateway 
        device, such as a switch or router, that processors and analyzes this data.
