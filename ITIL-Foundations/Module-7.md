# **Service Operation**

## **Goals and Processes**

* ![Phase Goal](https://i2.wp.com/www.certguidance.com/wp-content/uploads/2017/11/SO080-ITIL-IT-Operations-Management-Function-process-flow-small.png?w=600&ssl=1)

    - Ensure the timely and efficient delivery of services

        - Fulfilling of user requests

        - Resolving service failures

        - Fixing problems

        - Routine operational tasks

* Event Management

    - Make sure services are constantly monitored.

    - Filter and categorize events in order to decide on appropriate actions.

    - If the correction of root cause of an incident is not possible, a Problem  
    Record is created and the error-correction transferred to Problem Management.

    - Subprocesses:

        - Event monitoring mechanisms and rules maintenance

            - set up and maintain mechanisms for generating meaningful events and
            effective rules for their filtering and correlating.

        - Event Filtering (1st level correlation)

            - Filter informational events, and communicate any warning and exception
            events.

        - Response selection (2nd level correlation)

            - Interpret the meaning of an event and select a suitable response if
            required.

        - Event review and closure

            - Verify events are handled appropriately and may be closed.

            - Make sure that event logs are analyzed in order to identify trends
            or patterns which suggest corrective action must be taken.

* Incident Management

    - Manage the life cycle of all unplanned interruptions (or reductions in quality)
    of IT services.

    - Return the IT service to users as quickly as possible.

    - Subprocesses:

        - Incident management support

            - Provide the tools, processes, skills and rules required for the
            effective handling of incidents.

        - Incident logging and categorization

            - Record and categorize an incident using due diligence.

        - Immediate incident resolution (1st tier support)

            - Solve a service interruption within agreed upon time levels.

        - Escalated incident resolution (2nd tier support)

            - Involve more resources to investigate incidents not resolved by the
            1st tier. Invite 3rd party assistance if required.

        - Handling of major incidents

            - Major incidents cause serious interruptions of business activities
            and must be resolved with greater urgency.

        - Incident monitoring / escalation

            - Monitor the processing of ongoing incidents, so that counter-measures
            may be introduced as soon as possible if service levels are likely
            to be re-affected.

        - Incident closure / evaluation

            - Submit the incident record to a final quality check before it is closed.
            Keep record for future reference.

        - Pro-actively inform users

            - Let users know as soon as a service problem is noticed. Also handles
            other types of alerts. Aims to reduce inbound queries.

        - Incident management reporting

            - Supply incident-related information to the other service management
            processes.

        - ![process](https://i.ytimg.com/vi/6In3cC3Hqkk/maxresdefault.jpg)

* Request Fulfillment

    - Provides minor change support. Often times 1st tier help desk services.

    - Subprocesses:

        - Request Fulfillment support

            - Provide and maintain the tools, processes, skills and rules for
            efficient handling of service requests.

        - Request logging / categorization

            - Validate the requester's authorization to submit the request.

            - Record and categorize the service request with due diligence.

        - Request Model execution

            - Process service requests within the agreed time schedule.

        - Request Monitoring / escalation

            - Monitor the status of ongoing service request tasks so that
            counter-measures may be introduced as soon as possible if request
            fulfillment service levels are likely to be breached.

        - Request closure / evaluation

            - Submit the request record to a final quality check before it is
            closed. Keep record for future reference.

* Access Management

    - Overview

        - Identification - Who are you?

            - Username, ID

        - Authentication - Prove it:

            - Password, Token, Biometrics

        - Authorization - What can you do?

            - Permissions and Rights

    - Grant authorized users the right to use a service.

    - Prevent access to non-authorized users.

    - Executes policies defined in information security management process.

    - Referred to as 'Rights Management' or 'Identity & Access Management'.

    - Subprocesses:

        -  User roles/access profile catalog maintenance

            - Ensure the catalog of user roles and access profiles is still valid
            for the services offered to customers.

            - Prevent unwanted accumulation of access rights.

        - User access request processing

            - Process internal/external requests to add, change, or revoke access
            rights.

            - Make sure that only authorized users are granted the right to use a
            service.

* Problem Management

    - Manage the life cycle of all problems.

    - Prevent incidents from happening.

    - Minimize the impact of incidents that cannot be prevented.

    - Incidents with no satisfactory resolution to the root.

    - Subprocesses:

        - Proactive problem identification

            - Improve service availability by proactively identifying problems.

            - Solve problems or provide suitable workarounds before (further)
            incidents occur.

        - Problem categorization / prioritization

            - Record and prioritize a problem with due diligence.

        - Problem diagnosis / resolution

            - Identify root cause of a problem.

            - Initiate appropriate (economical) solution, if possible, a temporary
            workaround is supplied.

        - Problem control

            - Monitor ongoing problems processing status.

            - Add corrective measures as required to aid in the quick response
            to problems.

        - Problem closure and evaluation

            - Ensure that the problem record contains a full historical description,
            and that related known error records are updated.

        - Major problem review

            - Review the resolution of a major problem in order to prevent recurrence
            and learn any lessons for the future.

            - Verify the problems marked as closed have actually been terminated.

        - Problem management reporting

            - Ensure that the other service management processes / IT management are
            informed of ongoing problems, their processing-status and existing
            workarounds.

        - ![work flow](https://media10.connectedsocialmedia.com/intel/11/5771/Intel_IT_Best_Practices_Improving_Client_Stability_Proactive_Problem_Management.jpg)

* IT Operation Control

    - Monitor and control IT services and their underlying infrastructure.

    - Execute day-to-day tasks related to the operation of infrastructure components
    and applications.

    - No subprocess, dependent upon the infrastructure.

    - Consists of three major parts:

        - Development (Software Engineering)

        - Quality Assurance (QA)

        - Technology Operations

        - DevOps is the intersection of all these parts.

* IT Facilities Management

    - Manage the physical environment where the IT infrastructure is located.

    - Environments are constantly evolving. From Data centers to Cloud providers
    to Hybrid clouds and on-demand infrastructure.

    - No subprocesses, dependent on organization structure.

* Application Management Function

    - Plays a role in all application-related aspects of designing, testing, operating
    and improving IT services.

    - Developing the skills required to operate the IT organization's applications.

    - Ties into the development life cycle.

    - No subprocesses.

* Technical Management Function

    - Provide technical expertise/support for the management of the IT infrastructure.

    - Plays a role in all application-related aspects of designing, testing, operating
    and improving IT services.

    - Developing the skills required to operate the IT infrastructure required.

    - No subprocesses.

## **KPIs and Monitoring**

* Incident Management KPIs

    - # of incident detected (CID)

        - Sub totals for each category of incident.

    - # of incidents marked resolved (CRI)

    - Mean First-Response Time (MFRT)

        - Sum(FRTs)/CID

        - Describes our ability to rapidly triage an incident.

    - % First-try resolutions (PFTR)

        - # incidents resolved by 1st tier support / # total incidents

        - Can also be broken out by incident category.

    - # of detected incidents which escalated (CEI)

    - # incidents resolved wihtin SLA (CIRS)

        - % resolved within SLA can also be computed.

    - Mean Incident resolution time (MIRT)

        - Sum (RTs) / CRI

    - Mean incident resolution labor (MIRL)

        - Sim ($ labor) / CRI

        - Split up by incident category for more detailed view.

* Problem Management KPIs

    - # of problems registered to problem management (CRP)

    - # of outstanding problems (still unresolving)

    - Time before problem identification (TBPI)

        - Retroactively try to determine when a problem first arose.

    - Mean time problem open (MTPO)

        - Sum(eime open) / CRP

    - # of incidents per problem (CIPP)

    - Mean number of incidents per problem (MIPP)

        - Ssum(CIPP) / CRP

    
