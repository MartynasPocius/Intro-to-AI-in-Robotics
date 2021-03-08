# Coordinates

In the last lesson, we covered the steps required to extract the relative position data which is useful in the case of a single bot. However, as we move to a larger number of bots in the same environment, the ability to extract the absolute coordinate value becomes more useful. In this rather short lesson, we are going to look at how can we extract and manipulate such data using GPS Node

#### Adding GPS to e-puck

<img src = "https://user-images.githubusercontent.com/73468790/110221266-f21b3280-7ed3-11eb-9fae-2ce2fb548c68.png" width = "400">

Similar to the image recognition, the GPS node is not so easily accessible in the e-puck, as it has to be manually added. To do this, you first have to make sure that your e-puck is converted into ```Base Node(s)``` (*see the previous lesson*). Then, you need to navigate to ```children```  and right-click to ```Add New```->```Base Nodes```->```GPS```.

<Insert a picture of this navigation>
  
## GPS Node

As it was mentioned a bit earlier, one of the main use of GPS Node is to extract the absolute position of the controller. Similar to the ```Recognition```, the ```GPS Node``` also has some parameters, some of whom we might find useful for our challenge.

| **Field** | **Function** |
| --- | --- |
| ```type``` | determines the type of our GPS technology |
| ```accuracy``` | defines the precision of GPS (*standart deviation value*) |
| ```noiceCorrelation``` | defining the value of the noice correlation level |
| ```resolution``` | the smallest change GPS is able to measure (-1 = *infinite*) |
| ```speedNoise``` | standart deviation of the noice added to the speed measurement |
| ```speedResolution``` | the smallest speed change GPS is able to measure |

### GPS Functions

The programming of the GPS Node is quite similar to the image recognition: we include the GPS library (```<webots/gps.h>```), initialize the node, and manipulate data using functions.

### Libraries and Initialization

```c
...  //Other libraries
#include <webots/gps.h>

#define TIME_STEP 64

int main()
{
  //Creating GPS object
  WbDeviceTag gps;
  gps = wb_robot_get_device("gps");
  
  //Enabling GPS object
  wb_gps_enable(gps, TIME_STEP);
}

```
### Useful commands

After initialization, the GPS node can be manipulated using the following commands.

#### Extracting coordinates
```c
double *values = wb_gps_get_values(gps);
```
#### Extracting speed
```c
double *speed = wb_gps_get_speed(gps);
```

That is practically everything you need to know about the GPS nodes. In the following example, we are going to look, how the GPS node can be implemented in our Obstacle Avoidance Robot, which we created last week (*lesson03*).

### Example

In this example case, we are going to implement, what we have learned so far about the GPS nodes to our obstacle avoidance simulation: whenever a robot is going to face an obstacle, it is going to send its coordinates to the console, thus, providing us an approximate location of an object. First, follow the steps written above and add a ```GPS``` node to the e-puck.

From the *lesson03*, you should have the following code:

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

To implement GPS node, include ```<webots/gps.h>```library, enable ```gps``` object and extract the coordinate data in the case of an obstacle.

```c
#include <webots/robot.h>
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <webots/gps.h>

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
  
  //Initializing GPS node
  WbDeviceTag gps = wb_robot_get_device("gps");
  wb_gps_enable(gps, TIME_STEP);
  
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
    if (rightObs || leftObs)
    {
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
      const double *gps_values = wb_gps_get_values(gps);
      printf("Using the GPS device: %.3f %.3f %.3f\n", gps_values[0], gps_values[1], gps_values[2])
    }
    wb_motor_set_velocity(left_motor, left_speed);
    wb_motor_set_velocity(right_motor, right_speed);
    
  }
  
  // In the case of exit, clean the API and exit
  wb_robot_cleanup();
  return 0;
}
```

Just like that, we have created a bot that provides us with the obstacle coordinates. Although this might not look super useful at the moment, it is going to play one of the key roles, as we start to work with the multiple robot systems.
