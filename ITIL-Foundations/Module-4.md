# **ITIL Service Strategy**

## **Goals and Processes**

* Goals must be:

    - Specific

    - Measurable

    - Achievable

    - Realistic

    - Timely

* Goals

    - Decide on a strategy to serve customers

        - Market needs assessment.

        - Use case research.

    - Define what services and products will be offered to which markets.

    - Define any missing capabilities (HR, Technical, material, etc.)

* Main Processes:

    - Strategy Management

        - ![Processes](https://i.pinimg.com/originals/90/71/55/907155d42398364cfb1d3ce0b98e7cb4.png)

            - Gather Inputs

            - Strengths, Weaknesses, Opportunities, Treats - SWOT Analysis

            - Review Inputs

            - Strategic Matrix

            - Define Strategies

            - Final Reviews

        - In Short:

            - Assess the service provider's offerings, capabilities and competitors.

            - Current and potential market spaces.

            - Develop a strategy to serve customers.

                - MUST focus on securely delivering services by design.

            - Responsible for ensuring the implementation of the strategy through the
            current - and all future - iteration.

    - Service Portfolio Management

        - ![Processes](https://image.slidesharecdn.com/itiltrainingsscertificationserviceportfoliomanagement-160208173333/95/itil-training-ss-certification-service-portfolio-management-6-638.jpg?cb=1454953022)

            - Service Pipeline

            - Service Catalogue

            - Retired Service

        - Configuration Management System: Used to keep the services running, if a
        new service is added, there should be changes in the configuration system
        to allow that to use resources, if a service is retired, it's configuration
        should be removed.

        - Service Portfolio Consists of:

            - Customer portfolio: The list of people who are using particular
            services.

            - Application portfolio: Applications and services in use to serve
            client needs.

            - Supplier and Contract Management Information System: Used by resource
            planning team.

            - Customer Agreement portfolio: A list of SLAs and contracts with clients.

            - Project portfolio: Upcoming works joining or leaving the portfolio
            management system.

            - Customer Management Database - CMDB: Holds all the information for
            relationship management.

        - In Summary:

            - Create and manage the Service Portfolio

            - Document

                - Service name

                - Life-cycle state

                - Service type: Client-facing, Internal, External.

                - Customers using the service

                - Service sign-up contacts and procedures, e.g. contact information
                for a service manager and a list of qualification criteria for
                signing up.

                - Description of justification. What issues does it solve on the
                client-side?

                - List of desired outcomes.

                - Package variations (e.g. different service levels, different
                service options based on timezones or geographic location).

                - Cost-to-Serve and pricing.

                - Rules for service use and penalties/charge-backs

                - Dependencies (Internal or External).

                - Supported services (opposite of dependencies).

                - Change road map (added during future iterations).

                - Glossary of nomenclature (terminology used to describe aspects
                of the service).

        - Service Catalog Management - SCM Software:

            - Improves maintainability, portability, and error protection (software
            -enforced dependencies).

            - Open-source and Paid options.

            - Easy-to-use.

    - Financial Management for IT Services

        - In Short:

            - Define and manage service budget, accounting requirements, and
            charging structure.

                - Financial planning and review.

                - Analysis and reporting.

                - Service invoicing guidelines.

                - Budget request / Allocation process.

                - Cost to serve analysis.

                - Indirect cost allocation.

        - Processes:

            - Planning: Plan, budget effectively based on analysis and incorporating
            strategic plan, Think long range.

            - Accounting: Put good systems in place, policies and processes that
            ensure good internal controls and accuracy.

            - Reporting: Know what is going on, get and use good reports, ask
            questions, provide oversight through understanding of financial statements.

            - Analysis: Evaluate, analyze data to determine necessary course corrections
            and to inform planning.

            - Record, present, interpret, and respond to financial data, incorporating
            it in a meaningful way for decision making and planning.

    - Demand Management

        - ![Process](https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRIVg4W8t5A9bWof_nYRFrvz1fJJj-gEi54jK41sFngkuyAgW7t)

            - Capacity planning includes scaling:

                - Horizontally: Adding more of the same service to fit the needs
                of customers.

                - Vertically: Adding resources to a specific service to suit customer
                demands. Not popular anymore due to Cloud services.

        - In Short:

            - Estimate service demand and plan for how to accommodate different
            demand levels over time.

                - With Horizontal scaling, elastic load balancers can be utilized
                to tailor the resources to demands.

            - Cloud services often use Auto-Scaling features (horizontal) to assist
            with automating demand management.

            - Balance between not enough services and idle resources to optimize
            cost efficiency.

    - Business Relationship Management

        - ITIL is driven by market needs. BRM is about building positive relationships
        with clients.

        - Gain insight into upcoming needs and meet them in step with newly created
        services.

        - Reduces risk of client turnover.

        - Supports the sustainability portion of the business plan.

        - A model of BRM flow:

            - Engage clients

            - Form relationships

            - Understand rules

            - Bring value to the relationship

            - Demonstrate value added

    * Each of these processes have these phases:

        - Planning and Decision Making: Determining the courses of action.

        - Organizing: Coordination of activities and resources.

        - Leading: Managing and motivating people.

        - Controlling: Monitoring and evaluating activities.

## **KPIs and Monitoring**

* Goodhart's law: When a measure becomes a target, it ceases to be a good measure.

    - Also called the Cobra effect or the law of unintended consequences.

    - Can use statistics to check for.

    - Don't tie KPIs up to performance incentives.

* KPIs of Strategy Management:

    - # of strategic initiatives launched through service portfolio management (SIC).

    - % of new services that were planned prior to implementation (PNS).

        - PNS = # new services w/ plan /# new services

        - 0 <= PNS <= 1.0

    - % of new services that were launched without a strategic review (PAS).

        - PAS = # unplanned new services /# new services

        - 0 <= PAS <= 1.0

    - # of new customers (CCI)

    - # of customers lost (CCO)

    - # of incidents responded to (CRI).

* Dashboards are used to measure and visualize KPIs.

* KPIs of Financial Management

    - % of over-spend on the approved IT budget (OSP)

        - OSP = $ IT spent / $ approved budget

        - Not constrained.

    - % of services on a standardized budget plan (PBP)

        - PBP = # budgeted services / # total services

        - 0 <= PBP <= 1.0

    - % of service projects with a CBA+/- - Cost Benefit Analysis- attached (PCB).

        - PCB = # of projects w/ CBA / # total projects

        - 0 <= PCB <= 1.0

    - % of services with a post-implementation reviews (PIR)

        - PIR = # of services w/ PIR / # total services

        - 0 <= PIR <= 1.0

    - % of service overspend (per-service OSP).

        - $ spent on service / $ budgeted for service

        - Not constrained.

    - % of cost optimization plans for services (COP).

        - COP = # of CO services w/ CO plans / # of service

        - 0 <= COP <= 1.0

* BRM KPIs

    - # of received customer complaints (TCC)

    - # of accepted customer complaints (TAC)

    - # of customer satisfaction surveys (TSO)

    - % of returned surveys (PSR)

        - PSR = # surveys in / TSO

        - 0 <= PSR <= 1.0

    - Mean customer satisfaction per service (MCSS)

        - Average measured customer satisfaction for each service (including standard
        deviation).

        - determined by means of CS surveys.
