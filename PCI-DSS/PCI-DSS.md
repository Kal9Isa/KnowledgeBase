# **Payment Card Industry Data Security Standards**

## **PCI DSS Framework Introduction**

* The Agenda

    * PCI DSS: Why, What, How, Who?

        * Why do we need the PCI DSS?

        * What is PCI DSS and what does it do?

        * How does PCI-DSS protect financial and personal information?

        * Who is affected by PCI DSS and to whom does it apply?

* Why do we need PCI-DSS?

    * Fraud losses estimated to be in billions.

    * Identity theft

    * Legal costs, settlements and judgements.

    * Higher subsequent cost of compliance.

    * Lost customer confidence

    * Lost sales

    * Cost of reissuing new payment cards

    * Loss of ability to process payment cards.

* Who?

    * PCI security for merchants and payment card processors is the vital
    result of applying the information security best practices in PCI DSS.
    The standard includes 12 requirements for any business that stores, 
    processes or transmits payment cardholder data.

    * PCI DSS is the gobal data security standard that any business of any
    size must adhere to in order to accept payment cards, and to store, 
    process, and/or transmit cardholder data. It presents common-sense steps 
    that mirror best security practices.

* Where is data vulnerable?

    * Data in payment system database

    * Compromised card readers and PoS systems

    * Paper records improperly stored.

    * Hidden camera recording entry of authentication data

    * secret tap into store's wireless or wired network

    * ATMs modified to contain software or hardware shims.

    * Residual Information in RAM of system that accept payment card
    information. (RAM Scraping)

    * Everywhere else

## **PCI DSS - Attacks and Sources of Risk**

* Sources and Types of Attack

    * Sources:

        * Ousiders:                 64%

        * Insiders-accident:        29%

        * Insiders-malicious:       7%

    * Type:

        * Stolen laptop or computer:            37%

        * Exposure on internet or email:        27%

        * Hack:                                 26%

        * Document loss in mail or disposal:    6%

        * Scams and social engineering:         4%

* Types of data on a payment card

    * ![payment-card-img]()

    * Parts of Payment card:

        * Chip (data on magnetic stripe image) running JavaCard OS

        * Primary Account Number (PAN), Serial code on card in which contains a 
          hashing mechanism. if we multiply numbers in odd positions and then sum up 
          all the digits together and then use the remainder and subtract it from 10, 
          we'll get the last digit of the card.for example:

            6221 0610 5890 8296 

            12,2,4,1,0,6,2,0,10,8,18,0,16,2,18 --> 1 + 2 + 2 + 4 + ... = 54 => 10 - 4 = 6

        * Expiration Date

        * Magnetic Stripe (data on tracks 1 & 2)

        * CAV2/CID/CVC2/CVV2

* Sources of risk

    * Risky behavior A survey of business in the US and Europe reveals activites
      that may put cardholder data at risk:

        * 81% store payment card numbers

        * 73% store payment card expiration date

        * 71% store payment card verification codes

        * 57% store customer data from the payment card and magnetic stripe

        * 16% store other personal data

## **PCI DSS PCI Tools**

* PCI SSC: The PCI Security Standards Council offers robust and comprehensive standards
and supporting materials to enhance payment card data security.

* PCI DSS: Which provides an actionable framework for developing a robust payment card 
data security process -- including prevention, detection and appropriate reaction to 
security incidents.

* Qualified Security Assessors: QSAs are approved by the Council to assess comilance with
the PCI DSS

* Self-Assessment Questionnaire: The SAQ is a validation tool for organizations that are 
not required to undergo an on-site assessment for PCI DSS compilance.

## **PCI DSS - Goals and Requirements**

* What is PCI DSS?

    * The goal of the PCI DSS is to protect cardholder data that is processed, stored 
    or transmitted by merchants.

    * The security controls and processes required by PCI DSS are vital for protecting 
    cardholder account data, including the PAN printed on the front of a payment card.

* What are the goals and requirements?

    * Goals

        * Build and Maintain a secure network

            1- Install and maintain a firewall configuration to protect cardholder data.

            2- Do not use vendor-supplied defaults for system passwords and other security
            parameters.

        * Protect Cardholder Data

            3- Protect stored data

            4- Encrypt transmission of cardholder data across open, public networks.

        * Maintain a Vulnerability Management Program

            5- Use and regulary update anti-virus software.

            6- Develop and maintain secure systems and applications.

        * Implement Strong Access Control Measures

            7- Restrict access to cardholder data by business need-to-know.

            8- Assign a unique ID to each person with compuetr access.

            9- Restrict physical access to cardholder data

        * Regularly Monitor and Test Networks

            10- Track and monitor all access to network resources and cardholder data.

            11- Regularly test security systems and processes.

        * Maintain an Information Security Policy

            12- Maintain a policy that addresses information security.

## **PCI DSS - Requirements in Depth**

* Build and Maintain a secure network

    1- Install and maintain a firewall and router configuration to protect cardholder
    data.

        * Standards for Configuration and testing

        * Deny all form of untrusted network.

        * Prohibit direct public access between the internet and any system component 
        in the cardholder data enviornment.

        * Personal firewall software must be installed on mobile devices and/or employee
        owned computers used to access the organization's network.

    2- Do not use vendor-supplied defaults for system passwords and other security parameters.
    
        * Most vendor defaults are simple and easy to guess.

            * The default password for Cisco devices is "cisco".

        * Frequently designed for ease-of-use.

        * Passwords and other default settings should be changed before connected installing on 
        a network.

        * Define and apply system base-lines and standard configurations addressing known 
        vulnerabilities.

            * Renaming admin accounts

            * disabling guest accounts

        * Encrypt all non-console administrative access.


* Protect Cardholder Data

    * In general, no cardholder data should ever be stored unless it is necessary to meet the needs
      of the business, and then it should be rendered unreadable if possible.

    3- Protect stored data

        * Limit storage and retention

        * Don't store sensitive authentication information after authorization.

        * Mask the PAN when displayed.

        * If stored, the PAN should always be unreadable.

        * Protect keys used for encryption.

        * Document and manage all key management processes and procedures.

    4- Encrypt transmission of cardholder data across open, public networks.

        * Use strong cryptography and transport protocols like SSL/TLS or IPSEC
        for transmission over open, public networks (internet, wireless)

        * Never send PANs unencrypted by end-user messaging technologies.

* Maintain a Vulnerability Management Program

    * Vulnerability management is the process of systematically and continously
    finding weaknesses in an organization's payment card infrastructure. security
    procedures, system design implementation, and internal controls are included.
    
    5- Use and regulary update anti-virus software.

        * Deploy anti-virus software on all systems affected by malicious software.

        * Ensure that all anti-virus software is current, actively running and 
        capable of generating audit logs.

    6- Develop and maintain secure systems and applications.

        * Ensure all system components and software have the latest vnedor-supplied
        patches (critical patches installed within a month)

        * Establish a process to identify new vulnerabilities (alert services, 
        vulnerability scans/services)

        * Develop software applications in accordance with PCI DSS based on industry
        best practices and incorporate information security throughout the SDLC.

        * Follow Change Control procedures for all changes to system components.

        * Develop web-based applications based on secure coding guidelines.

        * Ensure all public web-facing applications are protected.

* Implement Strong Access Control Measures

    * Access control allows merchants to allow or restrict the use of cardholder data.
    should include physical and technical controls.
    
    7- Restrict access to cardholder data by business need-to-know.

        * Allow access only as job requires access.

            * Identification, Authentication, Authorization, Accountability.

            * Multifactor authentication is a combination of:

                * Things that a user knows. (PIN)

                * Things that a user has. (Card)

                * How the user is (Biometric)

        * Establish access control system for components with multiple users. default 
        to "deny all" unless specifically allowed.

    8- Assign a unique ID to each person with compuetr access.

        * Assign all users a unique username before allowing them access.

        * Require authentication by password, passphrase, or two-factor authentication.

        * Implement two-factor authentication for remote access to the network by 
        employees, administrators and third parties.

        * Render all passwords unreadable for storage and transmission.

        * Ensure proper user authentication and password management for non-consumer 
        users and administrators on all system components.

    9- Restrict physical access to cardholder data

        * Use facility controls to limit and monitor physical access in the data 
        enviornment.

        * Develop procedures to help personnel easily distinguish between employees 
        and visitors.

        * Ensure all visitors are authorized before allowing entry to sensitive areas.

        * Use a visitor log to maintain a physical audit trail.

        * Store media back-ups in a secure location.

        * Physically secure all paper and electronic media, containing cardholder data.

        * Control internal/external distribution of any kind of media containing cardholder
        data.

        * Ensure that management approves moving secured media.

        * Maintain strict access control over storage and accessibility of media.

        * Destroy media containing cardholder data when no longer needed.

* Regularly Monitor and Test Networks

    10- Track and monitor all access to network resources and cardholder data.

        * Link all access to an individual user.

        * Implement audit trails.

        * Record audit trail entries for each event including user id, type of event, 
        dates and time, success/failure, identity or name of affected data, synchronize
        all critical system clocks and times.

        * Secure audit trails to prevent alteration.

        * Review logs for security funcitions (at least) daily.

        * Retain audit trail history for at least one year with 3 months being immediately
        avilable for analysis.

    11- Regularly test security systems and processes.

        * Test for unauthorized wireless access points at least qaurterly.

        * Run internal and external network vulnerability scans.

        * Perform internal and external penetration testing.

        * Use network IDS/IPS to monitor all traffic in cardholder data enviornment.

        * Deploy file integrity checkers to alert personnel to unauthorized modification
        of critical system files, configuration files or content files.

* Maintain an Information Security Policy

    * A strong security policy sets expectation for an organization's employees and informs
    them security-related duties.

    12- Maintain a policy that addresses information security.

        * Establish, publish, maintain, and distribute a security policy that addresses all
        PCI DSS requirements.

        * Develop daily operational security procedures that are consistent with requirements 
        of PCI DSS.

        * Develop usage policies for critical employee-facing technologies to define proepr 
        usage including remote access, wireless, removable media, laptops,handheld devices, etc.

        * Ensure the policy and procedures clearly define information security responsibilities 
        for all employees and contractors.

        * Assign to an individual or team information security responsibilities.

        * Implement a formal security awareness program to make all employees aware of the 
        importance of cardholder data security.

        * Screen employees prior to hiring.

        * If cardholder data is shared with service providers, then require them to implement 
        PCI DSS policies and procedures.

        * Implement an Incident Response Plan.
