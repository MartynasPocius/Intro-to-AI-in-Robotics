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
To understand the principles of DC motors programming, let's analyse a following example involving only 1 DC motor *(as Tinkercad simulation software does not support Arduino motor shield, we are going to analyse L293D motor driver combination).*

<img src = "https://csg.tinkercad.com/things/3ierCt4F3Uv/t725.png?rev=1520142661994824596&s=&v=1&type=circuits" width = "500">

For now, let's ignore the circuitry and better analyse a following code.
```c
int motorPin1 = 11;
int motorPin2 = 10;

void setup()
{
  //power supply
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop()
{
   digitalWrite(motorPin1, HIGH);
   digitalWrite(motorPin2, LOW);
}
```
First of all, we define the motor positive and negative pins (``` motorPin1 ``` and ```motorPin2```) and alocate them pins (digital pins 11 and 10 respectively). In the further setup section, we define both pins as ```OUPUT``` devices by using ```pinMode``` function. Finally, in the loop section, by using ```digitalWrite()``` function, we set ```motorPin1``` value at ```HIGH```, while leaving ```motorPin2``` at ```LOW```.

If instead of using L293D motor driver, we connect motors using Arduino motor shield, the same functionality can be achieved with the following code:

```c
#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup()
{
}
void loop()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}
```
The built-in ```<AFMotor.h>``` library shortens the code by allowing us to create ```AF_DCMotor``` object which is particularly useful when we use more motors.


### Servo motors
As it was mentioned earlier, servo motor is a linear actuator which provides an accurate angle control. In contrast to DC motors, servo motors have built in driver meaning that they can be sufficiently powered by Arduino UNO itself. Let's look at the following setup

<img src = "https://csg.tinkercad.com/things/lr6LBSqFryb/t725.png?rev=1523859684531520732&s=&v=1&type=circuits" width = "500">

As we can see, servo motor has 3 pins: positive (red, connected to 5V), negative (black, connected to GND), and signal (yellow, connected to the digital pin 9). The control principle of servo motor is quite simple.

```c
#include <Servo.h> 
int servoPin = 9; 
Servo myservo; 

void setup() { 
   myservo.attach(servoPin); 
}
void loop(){ 
   myservo.write(0); 
   delay(1000);
  
   myservo.write(90); 
   delay(1000); 
}
```
We first have to import servo motor library (```<Servo.h>```) this is followed by the initiation of the signal pin (since our signal wire is connected to the digital pin 9, ```int servoPin = 9```) as well as the creation of ```myservo``` object. The pin initiation step is optional, as we could do that in the following setup block (instead of ```myservo.attach(servoPin)```, we could use ```myservo.attach(9)```), however, pin initiation at the start of program is quite a good practice for the future projects. To change the angle of the servo motor, we use ```myservo.write()``` function and specify the angle inside the brackets. Note that the angle value in the brackets acts as a position point: when we input the 90 degrees value (```myservo.write(90)```), object is going to remain in place, as 90 degrees is at 12 o'clock direction.


## Sensors

### Ultrasonics sensors


### Exercises

<Use keypad to control the speed of motor>

<Connect 2 DC motors and create a loop for the speed control>

<Ultrasonic sensor and piezo buzzer>
