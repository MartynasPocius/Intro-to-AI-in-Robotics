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
int motorSpeed = 13;

void setup()
{
  pinMode(motorSpeed, OUTPUT);
  digitalWrite(motorSpeed, HIGH)
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop()
{
   digitalWrite(motorPin1, HIGH);
   digitalWrite(motorPin2, LOW);
}
```
First of all, we define motor positive and negative pins (``` motorPin1 ``` and ```motorPin2```) and alocate them to digital pins 11 and 10. In addition, we define ```motorSpeed``` variable responsible for the voltage across the motor control (*just for now, we'll assume that the speed of the motor is constant*). In the further ```setup()``` section, we define all three pins as ```OUPUT``` devices and set value for the motor speed to ```HIGH```(by definition, L293D is going to output the maximum voltage). Finally, in the loop section, by using ```digitalWrite()``` function, we set ```motorPin1``` value at ```HIGH```, while leaving ```motorPin2``` at ```LOW```(to ensure flow across the motor).

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
As it was mentioned earlier, servo motor is a linear actuator which provides an accurate angle control. In contrast to DC motors, servo motors have built in driver meaning that they can be sufficiently powered by Arduino UNO itself (although, we are going to use Arduino motor shield for this). Let's look at the following setup

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

As it was mentioned before, sensors is the main way of communication for any robot. Overall, all sensors can be divided into the following subcategories (most of them are rather self explanatory):
 * Contact
    * Push button
    * Pressure sensor
 * Distance
    * Ultrasonic sensors (uses acoustics to measure the time between when a signal is sent and when it is received)
    * Infrared (can also be used in communication)
    * Laser (used over longer distances)
 * Positioning
    * Indoor localization (triangulates the robot's position with a use of beacons)
    * GPS
 * Rotation
    * Potentiometer (essentially a voltage divider)
    * Gyroscope (measures the rate of the angular acceleration)
 * Environmental conditions
    * Light
    * Humidity
 * ...
 
For this project, however, we are mostly going to focus on the ultrasonics sensors.

### Ultrasonics sensors

As it was mentioned earlier, ultrasonics sensors are responsible for measuring distance to an object using ultrasonic sound waves. It works by sending a higher than hearable frequency sound wave and then measures the time between the moment of emitting soundwave and receiving its echo. It usually has a working range between 2 cm and 400 cm (it depends on the model, which in our case is going to be HC-SR04), however, these sensors are usually chosen for applications involving 2-60 cm range. For larger ranges or less structured materials, other sensors might be a better solution. 
The way of connecting this sensor to Arduino UNO is quite straightforward.

<img src = "https://csg.tinkercad.com/things/f0QtxyoIE7z/t725.png?rev=1573033997297000000&s=&v=1&type=circuits" width = "500">

Similarly to the actuators, we first connect VCC pin to 5V and GND to GND in the Arduino board. Trig and echo pins that are responsible for the transmitting and receiving sound signals respectively and are usually connected to the analog pins on the Arduino board. On the other hand, it is completely possible to connect HC-SR04 to the digital pins that support input devices as well. For the programming part, there are multiple ways in which we could write a code for the distance measurement.
```c
#define trigPin 2
#define echoPin 7

int duration, distance;

void setup() {
  //Starting serial monitor
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  distance = (duration/2) / 29.1;
  
  ///Checking distance output
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
  
  delay(250);
}
```
The code above does not use any external libraries. We first define the trig, echo pins, and create variables for distance and duration measurements. Then in the ```void setup()```, we state that trig pin is going to be responsible for the output sound signal (```pinMode(trigPin, OUTPUT)```), while the echo pin is going to record the received signal (```pinMode(echoPin, INPUT)```).
To measure the distance, we first make sure that at the beginning of every loop, we aren't transmitting sound waves. Then, we send ultrasound signal (```digitalWrite(trigPin, HIGH)```) for
10 microseconds, after which, we again turn off the trig pin. At the same time, we record the received signal using ```pulseIn``` function, assign this value to the ```duration```, and convert it into ```distance```. To check whether or not our code works as expected, we output this data in the serial monitor.

Similarly to DC motors, HC-SR04 has an external library (```<NewPing.h>```) that makes programming process a lot easier.
```c
#include <NewPing.h>

#define trigPin 2
#define echoPin 7
#define maxDistance 400

int distance;
NewPing sonar(trigPin, echoPin, maxDistance);

void setup()
{
}
void loop()
{
  distance = sonar.ping()/US_ROUNDTRIP_CM;
  
  ///Checking distance output
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
}
```
The code above differs from its predecessor in a few ways. First of all, we have to define the maximum operating distance (```#define maxDistance 400```) for which we picked 400 cm. You can pick practially any number you want - just make sure it is in between the physical operating limits (just keep in mind that ultrasonic sensors tend to be inaccurate at large distances). Using this defined variable and ```NewPing``` function, we then create ```sonar``` object. Finally, to measure the distance, we record distance value in milimeter using ```sonar.ping()``` and then convert it to centimeters (```US_ROUNDTRIP_CM```).

## Exercises

Now it's time to embed your knowledge with the following exercises. *For some of these exercises, you will need to look at the online documentation.*

### Exercise01
**Tinkercad**
- Replicate the circuit presented in the DC motor section (this time change the ```motorSpeed``` pin to 9) and try to make a program that changes the motor speed according to the value you provided in the serial monitor. (Search for Arduino Serial documentation).


**Additional practice for people with physical components**
- Connect Arduino motor shield to the Arduino UNO by simply putting it on top. Then connect both of your DC motors and write code that uses serial monitor input as a value for motor speed. This time, however, use ```<AFDC_Motor.h>``` library.

### Exercise02
**Tinkercad**
- Connect micro servo motor to the Arduino and write a program for the following sequence of events: make sure that the servo motor is at 90 degrees position, then turn it 90 degrees to the right, wait there for 2 seconds, turn 180 degrees to the left, wait there 2 seconds, come back to the initial position and wait 4 seconds before starting a new loop. (*remember that you can create a variable in which you can store and change the position value*)

**Additional practice for people with physical components**
- Repeat the same exercise, but this time connect servo motor to the Arduino motor shield which is plugged to the Arduino UNO.

### Exercise03
**Tinkercad**
- Replicate the same circuit you did in the first exercise, but this time also connect the HC-SR04 sensor. Without using ```<NewPing.h>``` library, make a program that turn on the motors, whenever there is an object closer than 50 cm.
