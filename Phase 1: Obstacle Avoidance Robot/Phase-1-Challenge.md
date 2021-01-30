# Phase 1 Challenge

We have finally come to our first challenge:

***Construct an obstacle avoidance robot that stops whenever there is an obstacle closer than 30 cm, compares the distance to the nearest object on the right and left, and then chooses the path with the further obstacle.***

Next week, we are going to release additional tips for this challenge, but for now, let's think about the following things:

* First, consider how your robot is going to be moving in space. It would be quite useful to write separate functions for driving stopping, driving forward, turning left and right.
* In addition, try to write a separate functions for recording the distance.
* There are many ways in which we can approach this problem, however, try to divide the operation process into a sequence of events (*going forward, while checking the distance, stopping whenever there is an obstacle closer than 30 cm, etc*).

## Challenge using Tinkercad

This challenge can also be completed using the Tinkercad software in a following way:
* Connect 2 DC motors to L293D motor driver and assume that one of them is left motor, while the other one is right.
* Although you cannot physically record the values to the right and left distances, as you cannot attach ultrasonic sensor on top of the servo motor in the circuit simulator, however, you could write a program that replicates a similar logic (whenever, there is a close object, servo motor turns to the right and left, and the sensor records the distance data).
* Whenever you add a new object to the Tinkercad circuit simulator, the code in the editor is updated.
