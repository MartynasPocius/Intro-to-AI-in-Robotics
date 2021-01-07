# Lesson 1: Structure of Robot

<Insert two photos, one very advanced and other one quite simple>

At the first glance, both of these robots seem to have more differences than similarities. However, it isn't the right assumption - every robot, no matter the complexity or application, have common structural characteristics, components and operate in quite similar manner.

<Make a diagram showing the relationship between these things>

Every robot needs a ***platform*** or other structural unit that becomes the basis for the other components. We usually want our robot to move in space which is achieved with a help of ***actuators***. As it moves through space, robot has to have ***sensors*** that analyze the surrounding environment and send data to the ***microcontroller*** which then processes signal and makes a decision about the robot's next step. Every component has to have some kind of source of energy or ***power unit***. At some cases, it is quite useful to have ***motor controller*** which connects all components to the power supply making the control of the system a lot easier.

Let's now look at our parts list.

| Part | Type | What it does? |
| --- | --- | --- |
| Arduino Uno | Microcontroller | It serves as the *'brain'* of our robot |
| Motor shield | Motor controller | Responsible for distributing power across the motors |
| Chassis | Platform | The basis on which we built our robot |
| DC motor | Actuator | Responsible for the movement of our wheeled bot |
| Servo motor | Actuator | Motor able to turn at precise angle |
| Ultrasonic sensor | Sensor | It uses ultrasound to measure the distance from the object|
| IR sensor | Sensor | Uses IR to measure the distance from the object |
| 9V battery | Power unit | Provides power to our bot |

There are going to be separate lessons that are going to cover some of the types of components (microcontroller, actuators and motor controller, sensors) more in depth. 

## Breadboard
