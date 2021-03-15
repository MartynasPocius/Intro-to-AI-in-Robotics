# Introduction-to-AI-in-Robotics

Welcome to the "Introduction to AI in Robotics" tutorial series!

## Media

All assynchronous material can be found here, while the live sessions are going to be uploaded into society's YouTube Channel ([UCL Artificial Intelligence Society](https://www.youtube.com/channel/UC-5Whp878nPjOqKaL0tsDoA)).

Remember to check our Facebook channel for the link of the live session ([AISoc.ucl](https://www.facebook.com/AISoc.ucl)).

If you have any questions, you can send them to us on ([Discord](https://discord.gg/KSUZuQx)). 

## Syllabus

1. Phase 1: Obstacle Avoidance Robot
   - Lesson 1: Common Structure
   - Lesson 2: Microcontrollers and Arduino Uno
   - Lesson 3: Arduino programming
   - Lesson 4: Actuators and Sensors
   - Lesson : Putting everything together
2. Phase 2: Maze solving Robot
3. Phase 3: Introduction to Webots simulation software
4. Phases 4-5: Webots: Project Breakdown

## Timeline

| Title | Date |
| --- | --- |
| Phase 1 material release | 1 Feb |
| Additional material for Phase 1 release | 8 Feb |
| Live session for Phase 1 challenge + Phase 2 material release | 15 Feb |
| Live session for Phase 2 challenge + Phase 3 material release | 1 Mar |
| Live session for Phase 3 challenge + Phase 4 material release | 8 Mar |
| Live session for Phase 4 challenge | 15 Mar |


## Equipment

In the normal setting, the tutorial series would require physical components. However, due to the current pandemic situation, learners without bot kits are not going to be disadvantaged, as the practical part for the Phases 1-2 can be completed with Tinkercad circuit simulator. 
Although, having physical kits is encouraged.

| Part | Price (pounds) | Link |
| --- | --- | --- |
| Arduino UNO | 19.15 | https://www.robotshop.com/uk/arduino-uno-rev3-smd.html |
| L293D motor shield | 8.30 | https://www.robotshop.com/uk/l293d-motor-drive-shield.html |
| 2WD robot chassis | 14.50 | https://www.robotshop.com/uk/2wd-beginner-robot-chassis-v2-red-old.html |
| HC-SR04 ultrasonic sensor | 1.39 | https://www.robotshop.com/uk/hc-sr04-ultrasonic-range-finder-tys.html |
| 9g micro servo motor | 3.29 | https://www.robotshop.com/uk/9g-micro-servo-motor-4-8v.html |
| Battery holder (4xAA) | 0.54 | https://www.robotshop.com/uk/battery-holder-4xaa-flat.html |
| 4xAA batteries (any generic ones) | 1.62 | https://www.robotshop.com/uk/tenergy-15v-alkaline-aa-batteries-4pk.html |
| Dual female Jumper wires | 1.85 | https://www.robotshop.com/uk/40-pin-dual-female-splittable-jumper-wire-30cm.html |
| 2 IR sensors | 2x3.59 | https://www.robotshop.com/uk/infrared-reflective-sensor.html |
| Ultrasonic sensor holder (optional) | 1.80 | https://www.robotshop.com/uk/jsumo-ultrasonic-sensor-bracket.html |

### Alternative Parts

As some of you have noted, there are some parts in the list that might not be available. Therefore, we are providing you with a list of alternative parts and suppliers that are going to be updated on a daily basis. 

If you have found a more reasonable option (for example, your local supplier with shorter delivery time, etc.), but don't know whether that part is suitable, you can post your question on [Discord](https://discord.gg/KSUZuQx) under Robotics Tutorial Series channel. We are more than happy to help you!

 | Part | Supplier (price) |
| --- | --- |
| Arduino UNO | [Cool Components](https://coolcomponents.co.uk/collections/arduino-original-boards/products/arduino-uno-revision-3) (19.19), [Amazon](https://www.amazon.co.uk/Arduino-A000066-ARDUINO-UNO-REV3/dp/B008GRTSV6/ref=sr_1_3?dchild=1&keywords=arduino+uno&qid=1613470004&sr=8-3) (20.40) |
| Motor shield* | [Robo Savvy](https://robosavvy.com/store/dagu-commotion-motor-driver-shield.html) (22.62), [Amazon](https://www.amazon.co.uk/Hobby-Components-Ltd-Shield-Electronics/dp/B00D86NZBY) (5.88), [Cool Components](https://coolcomponents.co.uk/collections/arduino-shields/products/arduino-motor-shield-rev3 ) (25.19) |
| Ultrasonic sensor | [Robo Savvy](https://robosavvy.com/store/ultrasonic-distance-sensor-hc-sr04.html) (3.10), [Amazon](https://www.amazon.co.uk/HILABEE-Ultrasonic-Distance-Measuring-Transducer/dp/B07SKT2P5F/ref=sr_1_8?crid=3B1PKC297AQ7W&dchild=1&keywords=hc-sr04+ultrasonic+sensor&qid=1613469858&s=electronics&sprefix=HC-%2Celectronics%2C282&sr=1-8) (3.63), [Cool Components](https://coolcomponents.co.uk/products/ultrasonic-distance-sensor-hc-sr04-with-jumper-wires?_pos=4&_sid=eb7df3e45&_ss=r) (2.75) |
| Robot chassis | [Robo Savvy](https://robosavvy.com/store/dagu-magician-chassis.html) (13.10), [Amazon](https://www.amazon.co.uk/Chassis-Intelligent-Tracking-Encoder-Raspberry/dp/B076BPY2L3/ref=sr_1_4?crid=221KNRGTSCR2F&dchild=1&keywords=2wd+robot+car+chassis&qid=1613469972&sprefix=2wd+robot%2Celectronics%2C354&sr=8-4) (11.10) |
| 2 IR sensors | [Amazon](https://www.amazon.co.uk/HALJIA-Infrared-Avoidance-Reflective-photoelectric/dp/B06Y1KB536/ref=sr_1_7?dchild=1&keywords=ir+sensor+module&qid=1613470037&sr=8-7 ) (2x4.99) |
| 9g micro servo motor| [Robo Savvy](https://robosavvy.com/store/dagu-9g-2-kg-cm-micro-servo-motor.html) (5.10), [Amazon](https://www.amazon.co.uk/HaavPoois-Helicopter-Airplane-Walking-Control/dp/B08L4ZNY8K/ref=sr_1_12?crid=H3YEHBE06TLV&dchild=1&keywords=servo+motor+sg90&qid=1613470114&sprefix=servo+motor%2Caps%2C287&sr=8-12) (6.49) |

**L298P motor shields function a bit differently than L293D as they only support 2 DC motors, and don't have specific libraries (pin initialization process has to be done manually). On the other hand, it is sufficient for our series, and learners who choose this kind of shield, are going to be supported.*

## Software

There are two pieces of software that are mainly going to be used throughout the series - [Tinkercad circuit simulator](https://www.tinkercad.com/) and [Webots](https://cyberbotics.com).
