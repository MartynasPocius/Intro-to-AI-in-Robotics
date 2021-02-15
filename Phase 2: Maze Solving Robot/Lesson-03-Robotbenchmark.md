# Robotbenchmark

As it was mentioned before, Tinkercad does not support IR sensors' proximity feature, therefore, it is impossible to visualize this week's challenge (maze solving robot based on the wall follower algorithm) with the Tinkercad circuit simulator. Consequently, we are going to use the [Robotbenchmark online simulator](https://robotbenchmark.net) which is based on Webots software and offers robot programming challenges, including the "Wall Following" task.
As this online simulator only supports Python at the time, we first need to get a bit more comfortable with the Python syntax used in robotics.

## Python syntax

We are not going to cover Python programming language as a whole, but rather, we are going to look at it through Webots simulation software examples.

### "Hello world"

```python
from controller import Robot

robot = Robot()

while robot.step(32) != -1:
    print("Hello World!")
```
Similar to Arduino development and C language, we first define the libraries we are going to use (```from controller import Robot```). Then create the robot object and assign it to a ```robot``` variable. The following loop (``` while robot.step(32) != -1: ```) serves a similar purpose to the ```void loop()```. Finally, we print out "Hello world".


### Reading sensory data

```python
from controller import Robot, DistanceSensor

TIME_STEP = 32

robot = Robot()

sensor = robot.getDevice("my_distance_sensor")
sensor.enable(TIME_STEP)

while robot.step(TIME_STEP) != -1:
    value = sensor.getValue()
    print("Sensor value is: ", value)
```

We again start by importing the required libraries - Robot and Distance (as we are going to use distance sensors). After assigning the ```Robot()``` object to the ```robot```, we then start the initiation of our sensor. ```robot.getDevice()``` method can be viewed as assigning sensor to a specific pin, but instead of the pin, we use a tag as the argument (```"my_distance_sensor"```). The following line (```sensor.enable(TIME_STEP)```) functions as ```pinMode()``` method, but instead it takes the ```TIME_STEP``` variable which describes the rate at which the sensor perceives the data. Finally, in the loop, we use the ```getValue()``` method to record the value of the sensor.

### Programming actuators

```python
from controller import Robot, Motor
from math import pi, sin

TIME_STEP = 32

robot = Robot()
motor = robot.getDevice("my_motor")

F = 2.0   # frequency 2 Hz
t = 0.0   # elapsed simulation time

while robot.step(TIME_STEP) != -1:
    position = sin(t * 2.0 * pi * F)
    motor.setPosition(position)
    t += TIME_STEP / 1000.0
```
This example code how to make a motor oscillate with 2Hz frequency. As with the sensory part, we first include the libraries we would like to use and create a motor object to which we assign ```"my_motor"```. On the other hand, motors do not have ```enable()``` function which tells the speed at which we want to read/write data. Motors operate inside the ```while``` loop: ```position``` variable stores the oscillation behaviour which is then used to ```setPosition(position)```. On the other hand, the ```while``` loop does not "wait" until the motor is at a specific position, but rather, it functions for a specific period of time and then repeats the behaviour.

#### ```TIME_STEP```

As you have probably noticed, ```step()``` and ```TIME_STEP``` commands plays a crucial part in the simulation. One important thing to note is that the Webots simulator has two distinct time steps:
- The simulation step or ```WorldInfo.basicTimeStep``` - determines the duration of a single simulation (time interval between the calculations of speed, position, etc).
- The control step (```wb_robot_step```) that we have been previously using. It mainly determines the duration of one loop and the rate at which motors and sensors are updated. In addition, it cannot be interrupted, thus the value of ```TIME_STEP``` is usually a multiple of the simulation step (16, 32, 64, 128, etc).

### Putting everything together

```python
from controller import Robot, Motor, DistanceSensor

TIME_STEP = 32

robot = Robot() #creating robot object

#Setting up sensors
#Similar to pin declaration in Arduino
left_sensor = robot.getDevice("left_sensor")
right_sensor = robot.getDevice("right_sensor")
#Functions as pinMode()
left_sensor.enable(TIME_STEP)
right_sensor.enable(TIME_STEP)

#Setting up motors
left_motor = robot.getDevice("left_motor")
right_motor = robot.getDevice("right_motor")
#Setting initial value to the infinity, as we are not going to focus on the position of the motor, but rather the velocity
left_motor.setPosition(float('inf'))
right_motor.setPosition(float('inf'))
#Initializing velocity
left_motor.setVelocity(0.0)
right_motor.setVelocity(0.0)
MAX_SPEED = 5.00 #Maximum operating speed

while robot.step(TIME_STEP) != -1:

    # read sensors
    left_dist = left_sensor.getValue()
    right_dist = right_sensor.getValue()
    
    if left_sensor > right_sensor:
        left_motor.setVelocity(MAX_SPEED * 0.5)
        right_motor.setVelocity(MAX_SPEED)
    else:
        left_motor.setVelocity(MAX_SPEED)
        right_motor.setVelocity(MAX_SPEED * 0.5)
```

The code above combines what we have learned during this lesson - our bot record distance values from both sides (```left_dist = left_sensor.getValue()``` and ```right_dist = right_sensor.getValue()```), compares these measurements (```if left_sensor > right_sensor```), and changes motors' velocity accordingly.
