# **Service Transition**

## **Goals and Processes**

* Service Transition Processes:

    - Change Management

        - ![Processes](https://organizationalexcellence.virginia.edu/sites/organizationalexcellence.virginia.edu/files/change_management_framework_visual.PNG)

            - Change Plan

            - Define

            - Communicate and Engage

            - Embed in Culture

            - Prepare Individuals and Organization

        - Monitor and control the life cycle of a change.

        - Allow beneficial changes to be made with minimal risk/interruption.

        - Subprocesses:

            - Chnage Management support

                - Create a framework of templates and guidance for assessing change
                requests.

            - Assessment of proposals

                - Apply the CM framework to CRs proposed by the previous service
                strategy or design phases.

            - RFC logging and review

                - This reviews the design RFC from the previous phase.

                - Bounce incomplete CRs.

            - Emergency change assessment

                - Rapidly assess, authorize and implement a change requiring immediate
                action.

            - Change assessment by business manager

                - Decide level of authorization required to proceed with the change.

            - Change assessment by CAB - Change Assessment Board:

                - Committee ruling on proposals needing more authority than the BM.

            - Change scheduling and build authorization

                - Assess the WBS.

                - Put it on the schedule of work with resources defined.

            - Change Deployment authorization

                - Determine if all change components meet requirements.

                - Authorize release to production environments.

            - Minor change Deployment

                - Fast-track low-risk well understood changes.

            - Post implementation review

                - Assess the life cycle of a change and the achieved results.

    - Change Evaluation

        - Assess major changes, like the introduction of a new service or a substantial
        change to an existing service.

        - ![Checklist](http://recrea.co/wp-content/uploads/2018/10/sub-questions-key-evaluating-change-management-assessment-template-gap-analysis-checklist.jpg)

        - Evaluation prior to planning

            - Assess the feasibility at a conceptual level.

        - Evaluation prior to build

            - Reassesses concept weighted against the plan to implement.

        - Evaluation prior to Deployment

            - Verify all components were tested and meet requirements.

        - Post implementation review

            - Validate change met objectives.

            - Identify any lessons to be learned.

    - Project Management

        - Plan and Coordinate the resources required for a significant change
        request.

        - Monitor cost, time, and quality metrics of deployment. (Scope in a triad
        of Time, Cost, and Quality)

        - Subprocesses:

            - Project initiation

                - Define stakeholders, responsibilities and resources available.

                - Document risks, constraints and assumptions.

            - Project planning and coordination

                - Ensure service transitions projects are planned within project
                management guidelines.

                - Coordinate activities and resources across projects.

            - Project control

                - Monitor progress and resource consumption.

                - Expedite progress when required.

                - Initiate corrective action if required.

            - Project reporting and communication

                - Provide an overall summary of all planned or ongoing service
                transition projects.

                - Informs customers and other service management processes.

    - Application Development

        - Real-world need for this process

            - Integrate with other SDLC frameworks like Agile.

        - No subprocesses defined.

        - ![Application Development Services](https://3.imimg.com/data3/BG/LW/MY-8969659/our-application-development-services-250x250.jpg)

            - Custom Application Design and Development

            - Application Enhancement

            - Application Integration

            - Application Maintenance

            - Application re-engineering

            - Application Migration

            - Web Enablement

    - Release/Deployment Management

        - Control services components through their movement through the development
        environment.

            - i.e. moving from development to testing or testing to staging.

        - Subprocesses:

            - Release management support

                - Define a framework for a release life cycle.

                - Document release steps and checks, even under CI/CD.

                    - Always explicitly define the deployment steps taken, outside
                    the program that implements them aswell.

            - Release planning

                - Assign authorized CRs to planned release cycles.

                - DevOps defines the scope and content of release tags.

            - Release build

                - Assemble all work products required to fulfill a CR from internal
                and external sources.

                - At the end of this process, all required components are ready to
                enter the testing phase.

            - Release deployment

                - Release components into the live production environment.

                - Train end-users on any significant differences.

            - Early life support

                - Rapid response to any unforeseen  issues in the production environment.

            - Release closure

                - Finalize a release after all service portfolio and CM activity logs
                are up-to-date.

            - ![Life cycle](https://www.plutora.com/wp-content/uploads/2016/04/Release-Management-Process-Stages1.png)

    - Service Validation and Testing

        - Ensure that deployed releases and the resulting services meet customer
        expectations.

        - Verify that Operations are able to support the new service.

            - Validation ensures that product meets customers needs.

            - Verification ensures that product meets the required specifications.

        - Subprocesses:

            - Test model definition

                - Specify how a release will be tested and quality-assured.

                - Defines the testing concept and specific test cases to be used
                during validation.

            - Release component acquisition

                - Acquire the components of a release and submit them to an initial
                assessment.

                - Takes in the output from the release build subprocesses.

            - Release Testing

                - Test all components and all tools and mechanisms required for
                deployment, migration and back out.

            - Service acceptance testing

                - Verify all business conditions are met for the new service to be
                activated.

                - Obtain a binding consent from the stakeholders that the new service
                fulfills agreed SLA requirements.

    - Asset and Configuration Management

        - Maintain the information about configuration items(CIs) required to
        deliver a service, including their relationships.

        - Subprocesses:

            - Configuration identification

                - Define and maintain the underlying structure of the CMS (the
                configuration models).

                - Identify assets which need configuration control.

            - Configuration control

                - Ensure no CIs are added or modified w/o authorization.

                - Verify modifications are recorded in the CMS.

            - Configuration verification

                - Perform regular checks that the CMS is an exact representation
                of the CIs actually deployed in production environments.

            - ![work flow](https://itprocessed.com/wp-content/uploads/clip_image006_thumb1.gif)

    - Knowledge Management

        - Gather, analyze, store and share knowledge within an organization.

        - Knowledge management is dealt with in many other service management
        processes.

        - Ensures that all information used within service management, stored in
        the service KMS, is consistent and readily available.

        - Improve efficiency by reducing the need to rediscover knowledge about
        services.

        - No subprocesses.

        - ![flow](https://www.nairaland.com/attachments/7526978_knowledgembanner4_jpeg0b196978a8a7f794656c13bc6fd30cf0)

            - Collect

            - Use

            - Enrich

            - Share

            - Access

            - Build/Sustain/Divest

## **KPIs and Monitoring**

* Change Management KPIs

    - # major changes assessed by CAB (CAMC)

    - # of CAB meeitngs (CCM)

    - # Open RFCs (CORfc)

    - Mean days RFC open (MDOR)

        - Sum(Days open)/CORfc

     - # Accepted RFCs (CARfc)

     - # Rejected RFCs (CRRfc)

     - # Emergency changes (CECh)

* Project Management KPIs

    - # of Major projects being planned for release (CPOp)

    - # Closed Projects (CPCI)

    - Mean Project lifespan (MPL)

        - Sum(Project life) / CPCI

    - # of days a project is delayed (CDL)

        - Actual completion - expected completion

        - Early < 0 < Late

    - Mean days delay on projects (MeanCDL)

        - Sum(CDL) across completed projects / CPCI

    - $ Adherence to budget (CDAB)

        - Actual spend - Expected spend

        - Over budget < 0 < Under budget

    - Mean $ budget adherence (MDBA)

        - Sum(CDAB) across completed projects / CPCI

        - Possible to get a negative mean (under budget)

        - To find just variance take |MDBA|

* Release/Deployment KPIs

    - # of releases (CCRIs)

        - Version info (e.g. v1.3.6-x64)

        - Major. Minor. Patch - Tag

    - # of time to release (CTRIs) per release.

    - Mean time to release (MTRIs)

        - Sum(CTRIs) / CCRIs

    - # Release rollbacks (CRRIs)

    - % Automated release procedures (PARIs)

        - # Automated steps / # total steps in life cycle.

* Validation and Testing KPIs

    - # of tests for release components (CRCT)

    - % Failed component tests (CFCT)

        - # Failed tests / CRCT

        - 0 <= CRCT <= 1.0

    - Mean failed test % (MFTP)

    - # of Failures after release (CFAR)

        - Failures attributed to release only

    - Mean time to release fix (MTRF)

        - Sum(Time to fix) / CFCT

* Asset and Configuration Management KPIs

    - # Weeks between verifications (CWBC)

    - # Verification cycles completed (CVCC)

    - # Hours spent on component verification (CHCV)

    - # of incidents w/ root cause 'Misconfiguration' (CMInc)

        - Operational or security Misconfiguration

    - % of environments covered by configuration management (PCMC)

        - # Covered components / # total components

        - 0 <= PCMC <= 1.0
