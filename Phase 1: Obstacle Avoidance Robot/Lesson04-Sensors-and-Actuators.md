# Sensors and Actuators

As we now have some basic understanding of Arduino programming, it's time for the last step before this week's challenge - sensory input and actuator output. Let's first start from some general overview of actuators.

## Actuators

As it was mentioned in the first lesson, actuators are electrical components responsible for the robot's movement in space. There are many different types of actuators, however, the most commonly used in the robotics projects are:
- DC motor. It is a motor with a shaft that is driven by DC voltage at different levels. It is mainly responsible for the mobility of robot.
- Servo motor. It functions in a similar principle as the DC motor. The only difference is that Servo motor is usually responsible for a more precise rotational motion.
- Stepper motor. It is a mix between the DC motor and servo motor, but it provides even better accuracy at quite low torque (used in 3D printers).
- Linear actuators. Similarly to servo motors, it provides a linear motion (used in worm mechanism robots).
- Solenoids. Actuator that can assume a binary position. Usually used in valves, locks, etc.

In our robotics series, we mostly are going to use DC and servo motors, thus, let's consider them more in depth.

### DC motors

DC motor is the most common type of motor. It has the two leads - positive and negative - and is controlled by the DC input level. The latter concept brings us to the way in which Arduino UNO communicates with this actuator - it controls the input voltage which allows speed and direction control. 
On the other hand, Arduino UNO itself cannot provide enough power supply for multiple DC motors. The power comming from the supply is instead distributed by the special kind integrated circuits, *motor drivers*. Sometimes, these motors can be combined together with a few other electrical components to make a *motor shield*. In addition to an increase in the number of actuators, the use of motor shield brings another benefit - the build-in functions makes programming process a lot easier. In our series, we are mostly going to focus on Arduino motor driver shield with 2 integrated L293D motor drivers which can power up to 4 DC motors, 2 servo and stepper motors. 
To understand the principles of DC motors programming, let's analyse a following example *(as Tinkercad simulation software does not support Arduino motor shield, we are going to analyse L293D motor driver combination)*

<img src = "https://lastminuteengineers.com/wp-content/uploads/arduino/Wiring-L293D-Motor-Driver-IC-with-DC-Motors-Arduino.png" width = "400">


<Here insert the code for L293D motor driver. Explain about the init processes and so on>

### Servo motors

<Make a similar explanation using code example>

<Talk a bit about L293D and then about the motor shield we are going to be using. Add a separate section for people with the physical parts>

## Sensors

### Ultrasonics sensors


### Exercises

<Use keypad to control the speed of motor>

<Connect 2 DC motors and create a loop for the speed control>

<Ultrasonic sensor and piezo buzzer>
