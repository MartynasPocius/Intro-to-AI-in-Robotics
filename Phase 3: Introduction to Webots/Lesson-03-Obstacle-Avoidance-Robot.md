# Obstacle avoidance robot

After covering some basics, it's now time to apply your skills by replicating the obstacle avoidance bot, we build for the Phase 1 challenge.

## E-puck

Before going too much in-depth into the algorithm, let's first analyze the structure of our e-puck model. As has been mentioned a bit earlier, the e-puck is equipped with 8 IR sensors located around the chassis structure of which can be seen below.

<img src = "https://raw.githubusercontent.com/cyberbotics/webots/released/docs/guide/images/tutorial_e-puck_top_view.thumbnail.jpg">

All 8 sensors are simulated using DistanceSensor nodes that are given names according to their assigned field (ranging from ps0 to ps7). Similarly to Arduino, there is sensory data in Webots that has a separate library - ```webots/distance_sensor.h``` - that must be included at the start of the program. In contrast to the IR sensors, we used in Phase 2, the IR sensors in Webots are analog devices - they return values in a range of 0 (far away from the obstacle) to 4096 (the obstacle is close). To manipulate, and real this output, we can use a simple ```wb_distance_sensor_get_value(name_of_your_sensor)``` command.

## Obstacle avoidance bot

Now, we are going to apply what we have learned so far in our example step-by-step project. Open the simulation file you have created the last time, create a new controller, and assigning it to our e-puck in the ```Controller``` field. Even though we have changed our development platform, the workflow remains the same:
1. Including the required libraries and defining some of the constant variables.
2. Initializing devices (in our case, motors and IR sensors).
3. Reading sensory data.
4. Acting according to our sensory data.

### Libraries and constant variables

In our case, we are going to need libraries for importing our e-puck, controlling motors and reading our sensors. Thus the we are going to need ```robot.h```, ```distance_sensor.h```, and ```motor.h``` libraries that can be included in the following way:
```c
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
```
In addition to libraries, we also have to define a few constant variables. First, we need to set a value for our TIME_STEP variable which was discussed more in detail in the last week's Lesson 03. Just to quickly recall this, the TIME_STEP variable describes the duration of step in the code in milliseconds. In addition to that, we should probably also define the values of MAX_SPEED.

```c
#define TIME_STEP 64 //every step is going to take 64 miliseconds
#define MAX_SPEED 6.30
```

### Initializing devices

After setting up libraries and defining some of the constant variables, let's define our sensors and motors.

To create a variable to which we assign one of 8 sensors, we use ```WbDeviceTag``` and then retrieve the object with ```wb_robot_get_device```. Then we can enable (basically, turn on) our sensor by using ```wb_distance_sensor_enable(sensor_name, TIME_STEP)```, while the distance measurements can be retrieved using ```wb_distance_sensor_get_value(sensor_name)``` function. As we have 8 sensors, however, it wouldn't be logical to assign and manipulate each sensor manually. Therefore, by applying ```for``` loop, we can do this in the following way:
```c
WbDeviceTag sens[8];
char names[8][4]={"ps0", "ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"};

//Initializing sensors
for  (int i = 0; i < 8; i++)
{
  sens[i] = wb_robot_get_device(names[i]);
  wb_distance_sensor_enable(sens[i], TIME_STEP);
}
```

To initialize the motors, the process is rather similar to the initialization of IR sensors.
```c
WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
wb_motor_set_position(left_motor, INFINITY);
wb_motor_set_position(right_motor, INFINITY);
wb_motor_set_velocity(left_motor, 0.0);
wb_motor_set_velocity(right_motor, 0.0);
```
One important thing to note is that since we are not interested in the position control of the motors, we are setting the initial position to ```INFINITY```. We are also setting the initial motor velocity to ```0.0``` to ensure that our robot is stoped at the beginning of the controller simulation.

### Reading and analyzing sensory data

As we have mentioned before, to read the sensory data, we have to use ```wb_distance_sensor_get_value()``` function. So,
```c
//Reading sensor data
double sens_data[8];
for (int i = 0; i < 8; i++)
{
  sens_data[i] = wb_distance_sensor_get_value(sens[i]);
}
```

### Putting everything together

Finally, we compare our measured distances to our set collision value, to control our motors accordingly. For this purpose, we are going to create logic variables ```rightObs``` and ```leftObs``` that are going to indicate whenever there is an obstacle on either sides

**When there is an obstacle on the right:**

```c
bool rightObs = sens_data[0] > 80.0 || sens_data(1) > 80.0 || sens_data(2) > 80.0;
if(rightObs)
{
  left_speed = -0.6 * MAX_SPEED;
  right_speed = 0.6 * MAX_SPEED;
}
```

**Obstacle on the left:**

```c
bool leftObs = sens_data[5] > 80.0 || sens_data(6) > 80.0 || sens_data(7) > 80.0;
else if(leftObs)
{
  left_speed = 0.6 * MAX_SPEED;
  right_speed = -0.6 * MAX_SPEED;
}
```

**No obstacle:**

```c
double left_speed = 0.6 * MAX_SPEED;
double right_speed = 0.6 * MAX_SPEED;

wb_motor_set_velocity(left_motor, left_speed);
wb_motor_set_velocity(right_motor, right_speed);
```

On the other hand, at this time, we only have snippets of code that yet have to be put in the right order. In Webots we have the following structure for writing the code:
```c
int main(int argc, char **argv){
  //Initializing Webots API
  wb_robot_init();
  //Initializing devices and variables
  
  //Constantly running loop until the exit event
  while (wb_robot_step(TIME_STEP) != -1) {
  
  }
  
  // In the case of exit, clean the API and exit
  wb_robot_cleanup();
  return 0;
}
```
Skipping the Webots API initialization and exit conditions, we could reimagine this code in the following way:
```c
void setup()
{
  void loop()
  {
  
  }
}
```
Therefore, it seems quite logical, why in the ```int main(){}``` we define variables and initialize objects, while we leave ```while``` loop for the reading sensory data and controlling motors. With this in mind, we can write the final code:

```c
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>

#define TIME_STEP 64 //every step is going to take 64 miliseconds
#define MAX_SPEED 6.30

int main(int argc, char **argv){
  //Initializing Webots API
  wb_robot_init();
  
  //Initializing sensors
  WbDeviceTag sens[8];
  char names[8][4]={"ps0", "ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"};
  for (int i = 0; i < 8; i++)
  {
    sens[i] = wb_robot_get_device(names[i]);
    wb_distance_sensor_enable(sens[i], TIME_STEP);
  }
  
  //Initializing motors
  WbDeviceTag left_motor = wb_robot_get_device("left wheel motor");
  WbDeviceTag right_motor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(left_motor, INFINITY);
  wb_motor_set_position(right_motor, INFINITY);
  wb_motor_set_velocity(left_motor, 0.0);
  wb_motor_set_velocity(right_motor, 0.0);
  
  //Constantly running loop until the exit event
  while (wb_robot_step(TIME_STEP) != -1) {
  
    //Reading sensor data
    double sens_data[8];
    for (int i = 0; i < 8; i++)
    {
      sens_data[i] = wb_distance_sensor_get_value(sens[i]);
    }
    
    double left_speed = 0.6 * MAX_SPEED;
    double right_speed = 0.6 * MAX_SPEED;
    
    bool leftObs = sens_data[5] > 80.0 || sens_data[6] > 80.0 || sens_data[7] > 80.0;
    bool rightObs = sens_data[0] > 80.0 || sens_data[1] > 80.0 || sens_data[2] > 80.0;
    
    if(rightObs)
    {
      left_speed = -0.6 * MAX_SPEED;
      right_speed = 0.6 * MAX_SPEED;
    }
    else if(leftObs)
    {
      left_speed = 0.6 * MAX_SPEED;
      right_speed = -0.6 * MAX_SPEED;
    }
    
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
    
  }
  
  // In the case of exit, clean the API and exit
  wb_robot_cleanup();
  return 0;
}
```
