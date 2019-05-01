# **Securing IoT**

## **Introduction**

* Securing IoT

    * In this module you will learn about:

        - The security implications of IoT.

        - The privacy implications of IoT, for both business data and
        personal data.

## **Design for Protection**

* Security and Privacy Implications of IoT overview

    * We now have a picture of the IoT that involves:

        - Extra devices being connected.

        - Extra networking to connect all these devices.

        - Extra programming to direct the devices and networking.

        - A massive volume of extra data pouring into the internet.

        - More M2M interactions and autonomous decision making.

    * Many of IoT devices are purposely very small and low powered, and this
    increases the difficulty of securing them.

    * Connecting things up makes private data about ourselves, our lives, and 
    our businesses accessible.

    * There is also the concern that IoT technology development is outpacing 
    governance and regulations required.

    * We also need to know how to keep IoT devices physically secure.

    * IoT Security Issues:

        - Data Private

        - Data Access

        - Secure M2M

        - Data Theft or Corruption

        - Unauthorized Access to network.

        - Secure Network

        - Hacked and Broken IoT devices

        - Hacked and Misused IoT devices.

## **Privacy and Ethics**

* Privacy and Ethics

    * Sorts of data that can be collected from individuals through IoT:

        - Personal Information.

        - Locations and Movements.

        - Habits

        - Physical Condidtions

    * Personal data is valuable to others for the following reasons:

        - Sales and Marketing

        - Services Planning

        - Health Intervention

        - Credit Descisions

        - Insurance Descisions

        - Employment Decisions

        - Fraud and Theft.

    * Good product development practice involves developers:

        * Conducting a privacy and security risk assessment.

        * Building security into the product from the outset.

        * Testing the security measures before launching.

        * Using a service provider capable of providing security.

        * Monitoring a product through its life cycle.

        * Minimise the data collected and retained, and the length of 
        time data is required.

        * Consider who should have access to data.

        * Educate employees about good security practices.

    * The FTC refers to Fair Information Practice Principles (FIPP):

        * Notice (consumer being given notice of practice)

        * Choice (consumer having choice over how data is used)

        * Access (consumer's ability to view the data collected)

        * Accuracy (consumers collected data being accurate, and consumer's ability
        to contest accuracy)

        * Data minimisation

        * Security (consumer's held data being accurate and secure)

        * Accountability

## **Security**

* Hackable Devices

    * Successful Attacks on a Pacemaker:

        - Triggered ICD identification

        - Disclose patient data: name, diagnoses, and other data.

        - Disclose Cardiac Data

        - Change Patient Name

        - Change ICD's Clock

        - Change therapies, including disable the device.

        - Including fibrillation.

        - Power denial of service, run down the battery.

    * System Analyses on a Car

        * Extract device's firmware: 

            - Read memory out over the CAN bus (CarShark)

            - Desolder flash memory chips in ECUs.

        * Reverse Engineer firmware:

            - IDA Pro

            - Custom Tools

        * Identify and test vulnerable code paths.

        * Weaponize exploits

    * Results on a Car:

        * Able to affect numerous critical components:

            - Brake computer

            - Lighting computer

            - Engine computer

            - Dash computer

            - Radio computer

        * Able to perform these attcks by calling telematics unit over
        cellular network.

    * Post-compromise control

        * Remotely trigger code from prior compromise

            - FM RDS: broadcast trigger

            - Bluetooth: short-range targeted trigger

            - Cellular: global targeted trigger

    * APCO Project 25

        * Standard for digital two-way radio:

            - Widely fielded by gov't: local police, fire & federal, law 
            enforcement and security services.

            - P25 in widespread use in the field.

        * Cryptographic security options

            - Content confidentiality.

    * Denial of Service in P25

        * Build a P25 subframe jammer

        * TI CC1110 is a single-chip digital radio transceiver chip.

            - Supports native protocol similar to p25

            - Sufficiently close to recognize start of p25 frames.

    * Intercepting the Federal Specturm

        * 2000 discrete VHF and UHF voice channels allocated to government.

            - 24 MHz of spectrum.

            - 12.5 KHz channels

            - Law enforcement mixed in among less sensitive users.

        * Easy to identify the channels used locally for covert tactical LE
        activities.

            - They're the ones with encrypted traffic on them.

        * Many p25 recivers on the market.

        * Icom R-2500

* Cyber security Methods

    * Shadowing is the act of decoupling device owener and the data collected 
    through the device.

    * A Secure IoT Framework outlines the following components:

        * Authentication: IoT devices connecting to the network create a trust
        relationship, based on validated identity through mechanisms such as:
        passwords, tokens, biometrics, RFID, X.509 digital certificate, shared
        secret, or endpoint MAC address.

        * Authorization: A trust relationship is established based on authentication
        and authorization of a device that determines what information can be accessed 
        and shared.

        * Network Enforced Policy: Controls all elements that route and transport endpoint
        traffic securely over the network through established security protocols.

        * Secure Analytics: Visibility and Control provides reconnaissance, threat detection,
        and threat mitigation for all elements that aggregate and correlate inforamation.

    * Pay attention to these tips if you use an off-the-shelf IoT product:

        * Disable default password.

        * Disable Universal Plug and Play (UPnP) - which allows the device to automatically
        make itself available to networks.

        * Disable remote management.

        * Keep software (firmware) up to date.

        * Use encryption and/or certificates where possible.

        * Physically keep device secure.

    * Fog computing

        * The fog extends the reach of the cloud so it is closer to devices that create and act
        on IoT data.


