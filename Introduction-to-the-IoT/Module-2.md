# **The Things of Internet of things**

## **Introduction**

* Two key IoT componenets:

    * Sensor: A sensor detects changes in its enviornment and sends
    information about that change.

    * Actuator: An actuator moves or controls something.

* We put microcontrollers, sensors and actuators together to make 
the "things".

## **What Sort of Things are We Talking About?**

* IoT streamlining mining operations

    * Today's mining enviornments:

        * Operate indepndently

        * Use propprietary networks.

    * Operational Technology network + Enterprise systems:

        - Fully connected, converged pit-to-port network.

        - Lean, efficient, collaborative, safe, highly secure operations.

        - Lower costs, Increased profit.

* IoT case study: Dairy Farm

    * All the cows have a responder on them which has a motion sensor in it,
    also has a transponder. They've got battery with five-years life capacity.
    and after 5 years the responder has to be changed which are $140 each.

    * The data from the responder is sent back to the herd to know which cows are 
    on heat and which ones are ill or not moving. If they're on heat they spend most 
    of their time moving around so they eat less, and looking at the history of that cow
    we can say whether that's a normal behavior or there's something else. 

    * There is a drafting system where the computer will draft cows off based on their 
    behaviors,like those who are on heat would be separated and inseminated after examining 
    the cause of the behavior.

    * With the conductivity sensors in the dairy, we would know when the cows got mastitis.
    Their milk conductivity increases. Then we'll do physical test on them to validate mastitis.
    And we're able to pick up cows quickly and treat them before mastitis gets a hold of them.

    * One of the things with actual activity meter is, if a cow is not eating and she's in the herd
    we know that cow's sick. So we need to identify her and draft her out.

    * There are computer monitors behind each cow in the parlor which contains a whole heap of data
    about the cow and the milk. If there's a cow with high somatic cell count, we divert her milk 
    out of the system and feed it to the calves. And there are safety measures to ensure that milk 
    goes to the right containers either as a product or for calves.

    * There are also milk meters, which tell us how much milk the cows produce and feeds them with 
    grain based on their profile, for example cows with 20 liters of milk production only get 2 kilos
    of grain, and cows with 45 liters get 7 kilos.

* IoT case study: Gait Analysis

    * This device uses three separate IMUs devices placed in three color coded 3D printed boxes. And 
    the sensors will be attched to different sections of the lower limb, for example thigh, shank and
    foot of the subject. And the data will be captured simultaneously and sent to the receiver dongle
    that connects to a computer.

    * We can provide some information about the movement of that body section, for example angle of 
    thigh during walking trial or positive/negative movements in the whole gait cycle.

    * The sensors of this device are Inertial Measurment Units which is a kind of sensor that consists
    of accelerometer gyroscope, and magnetometer in a single unit that provides a good range of data.

    * Accelerometer actually reads the acceleration of the device for the angle velocity in different 
    x, y and z directions. And a magnetometer also looks for the magnetic field in the area which could
    get noise easily by any MF near the sensor.

* IoT case study: Self-Powering Remote Sensors

    * To know if things need maintenance you either have to work on a time-schedule basis but if you try
    to save money and maintenance smarter, you would go for predictive-condition monitoring basis and that
    requires sensors, vibration sensors, pressure, sound microphone sensors, etc.

    * As far as the IoT goes we want to embed these sensors in equipment  with its own power supply or battery
    or renewable energy supply, and then we have some means of digitizing that signature and be able to 
    communicate to the web.

    * There's a sensor that was developed to fit onto large rotating equipments, it has built-in  MEMS 
    transducer, which measures the acceleration and also has a thermometer to measure temperature of the 
    device. We needed to put these in remote places with little to no accessibility and you don't want them 
    running on battery so you have to replace it on a period. That brought the topic to Energy Harvesting.

    * We've been working on energy harvesting from the vibration enviornment. And we've been particularly 
    looking at the piezoelectric energy harvesting method. Using a miniature piezoelectric beam which would 
    be clamped into the machine, Since it's a base-excited vibration, the beam vibrates back and forth and 
    can extract fractions of milliwatt of energy per meter squared per g from these devices if they're 
    operating at resonance. Since it's generating power continously, if we couple that with smart supercapacitors
    or other recharging devices, it will give us enough energy to communicate the information to the web.

* IoT case study: Autonomous Bus

    * KIP is an autonomous bus in Curtin University.

    * It has a 360 Lidar, which operates like a radar except that it shoots out laser beams 360 degress,
    to tell how far the objects are, and where they are relative to its position.

    * Similar to that we have 2D Lidar down at the bottom to see objects in front of it.

    * There are also stereo cameras to be able to read signs and see lights.

    * There are 2D Lidars on each side to detect how far the crub is, and how far the bus stop is.

    * On wheels we have sensors to actually know how fast each wheel is moving so its accuracy to the ground
    is centimeter-perfect.

    * In additon to that there are GPS, 4G, 3G, radio and Wi-Fi systems to connect it to the access points of 
    the campus to aid its location positioning.

## **Sensors and Actuators**

* Sensors in Your Smart Phone

    * A smart phone touch screen works through one of these sensor types:

        * Capacitative

        * Resistive

        * Surface Acoustic Sensor

    * A typical smart phone contains many sensors of various types, and is generally internet capacble:

        * Magnetometer: Detects magnetic fields.

        * Accelerometer: Detects the movement of the phone.

        * Gyroscope: Detects a change in the phone's orientation.

    * GPS: Uses radio signals from satellites to detect positoning.

* Phone as an IoT Device

    * Using IMU sensor in a phone to measure thigh angle, we can tell what someone is doing (sitting, 
    walking) for the purpose of assisting vision-impaired people with indoor navigation. When a person 
    changes position, the sensor senses the small changes in atmospheric pressure, rather than the more 
    commonly used accelerometer with magnetometer, to detect movement.

* Actuators in Your Phone

    * They operate in one of several ways:

        * Electrical

        * Pneumatic (uses air pressure)

        * Hydraulic (uses fluid pressure)

        * Mechanical

    * Actuators take a source of power and convert the energy to create motion and/or control a system.

* Actuators in Your house

    * Things in a farm:

        - Land-monitoring tractor: Cameras, GPS, soil sensors

        - Fertilising decisions spade: Chemical sensors and Display panel (actuator)

        - Smart irrigation: Soil moisture detctor and Value (actuator)

        - Smart animal feeder: Level sensor and Animal ID detector Feed release (actuator)

        - Automatic secure gate: ID sensor and Pneumatic arm (actuator)

## **Lining up Devices**

* Interactions: 

    * IoT solutions often involve machines talking to each other and making smart decisions based on 
    software and/or machine learning.

    * At other times, sensors and data analysis provide people with information to make good decisions
    and facilitate planning. The IoT can increase the potential for collboration by connecting remotely
    located people.

    * There are 3 different types of interactions:

        - M2M: Machine to Machine

        - M2P: Machine to People

        - P2P: People to People
