# Lesson 1: Structure of Robot

<p float = "left">
  <img src = https://cdn.mos.cms.futurecdn.net/s9sxXfjdJwNhnpAoHgFegF.jpg width = "400"/>
  <img src = https://images-na.ssl-images-amazon.com/images/I/71M45gF1qKL._SL1500_.jpg width = "400"/>
</p>


At the first glance, both of these robots seem to have more differences than similarities. However, it isn't the right assumption - every robot, no matter the complexity or application, have common structural characteristics, components and operate in quite similar manner.

## Common components and structure
<Make a diagram showing the relationship between these things>

Every robot needs a ***platform*** or other structural unit that becomes the basis for the other components. We usually want our robot to move in space which is achieved with a help of ***actuators***. As it moves through space, robot has to have ***sensors*** that analyze the surrounding environment and send data to the ***microcontroller*** which then processes signal and makes a decision about the robot's next step. Every component has to have some kind of source of energy or ***power unit***. At some cases, it is quite useful to have ***motor controller*** which connects all components to the power supply making the control of the system a lot easier.

## Our bot

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

There are going to be separate lessons that are going to cover some of the types of components (microcontroller, actuators and motor controller, sensors) more in depth. Before moving on to other lessons, however, we should first cover another important component that hasn't been mentioned before - ***breadboard***.

## Breadboard

As we start building the prototype for robot or any other electrical device in general, we tend to make a lot of mistakes. Therefore, connecting electrical components by soldering might not be our go to option at the start. 

***Breadboard*** is a special board perfectly suited for prototyping. It is covered with a grid of pins that have a row of electrically continuos holes connected to it. Without going much in-depth, let's now look into the layout of breadboard.

![Image of breadboard layout](https://www.tweaking4all.com/wp-content/uploads/2013/12/basic_breadboard_layout.png)

The structure has two main parts:
- Grid (B and C areas in the figure)
- Power rails (A and D areas)

Grid pins (B and C) are connected vertically with each other, while power rail pins are connected horizontally and are usually connected to the power source.

## Tasks

**Exercise 1**

Throughout the series, various exercise are going to be used to embed theoretical material. In general, all exercises can be completed either by using physical parts or Tinkercad. This introductory task, however, should be completed with Tinkercad (just to make sure, everyone has basic understanding). 

Exercise1: Use ***small breadboard*** and ***9V battery*** to power ***LED***.
