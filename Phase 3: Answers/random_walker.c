//Code for the Optional Challenge: robot travels in a random path, until it facing blue sphere, and stops

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/camera.h>
#include <webots/position_sensor.h>
#include <webots/distance_sensor.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define SIMULATION 0  // for robot_get_mode() function
#define REALITY 2     // for robot_get_mode() function


#define THRESHOLD_DIST 300
#define TIME_STEP 32

#define S_UNIT 0.00628
#define WHEEL_R 0.02
#define AXLE_L 0.026

#define FORWARD 0
#define STOP 1
#define UTURN 2

#define T 200

WbDeviceTag leftMotor, rightMotor;
WbDeviceTag sens[8], leftPositionSensor, rightPositionSensor, cam;

char names[8][4] = {"ps0", "ps1", "ps2", "ps3", "ps4", "ps5", "ps6", "ps7"};  
int sens_data[8];
bool obstacle[8]; //could be int

int leftSpeed = 0;
int rightSpeed = 0;

int state = FORWARD;
int n = 0;
double old_encoder = 0.0;

unsigned short width, height;
int delta, max, max_id = 0, leftSpeed, rightSpeed;
const unsigned char *img;

static void reset(void)
{
  srand(time(0));
  
  //initiating and enabling distance sensors
  for (int i = 0; i < 8; i++)
  {
    sens[i] = wb_robot_get_device(names[i]);
    wb_distance_sensor_enable(sens[i], TIME_STEP);
  }
  
  //initiating and enabling motors
  leftMotor = wb_robot_get_device("left wheel motor");
  rightMotor = wb_robot_get_device("right wheel motor");
  wb_motor_set_position(leftMotor, INFINITY);
  wb_motor_set_position(rightMotor, INFINITY);
  wb_motor_set_velocity(leftMotor, 0.0);
  wb_motor_set_velocity(rightMotor, 0.0);
  
  
  //initiating and enabling position sensors
  leftPositionSensor = wb_robot_get_device("left wheel sensor");
  rightPositionSensor = wb_robot_get_device("right wheel sensor");
  wb_position_sensor_enable(leftPositionSensor, TIME_STEP);
  wb_position_sensor_enable(rightPositionSensor, TIME_STEP);
  
  //camera initiation and getting dimensions
  cam = wb_robot_get_device("camera");
  wb_camera_enable(cam, TIME_STEP);
  width = wb_camera_get_width(cam);
  height = wb_camera_get_height(cam);
  
}

//function for the random movement
static int operate(void)
{
  for (int i = 0; i < 8; i++)
  {
    sens_data[i] = wb_distance_sensor_get_value(sens[i]);
    obstacle[i] = sens_data[i] > THRESHOLD_DIST;
  }
    
  int test = 20.0 * rand() / (double)RAND_MAX;
  
  switch (state) 
  {
    case FORWARD:
    
      leftSpeed = 300;
      rightSpeed = 300;
      if (obstacle[0] || obstacle[7]) 
      {
        state = STOP;
        n = 0;
      }
      break;
      
    case STOP:
    
      leftSpeed = 0;
      rightSpeed = 0;
      n++;
      
      if (n > 40) 
      {
        state = UTURN;
        old_encoder = fabs(wb_position_sensor_get_value(leftPositionSensor));
      }
      break;
      
    case UTURN:
    
      leftSpeed = 150;
      rightSpeed = -150;
      
      double new_encoder = fabs(wb_position_sensor_get_value(leftPositionSensor));
      double d_step = new_encoder - old_encoder;
      double d_meter = (double)d_step * WHEEL_R;
      
      if (d_meter / AXLE_L > test + 1)
      {
        state = FORWARD;
      }
      break;
      
    default:
      state = FORWARD;
  }


  // Send the values to actuators
  wb_motor_set_velocity(leftMotor, S_UNIT * leftSpeed);
  wb_motor_set_velocity(rightMotor, S_UNIT * rightSpeed);

  return TIME_STEP;
}

int colourIntensity()
{
  float *intensity = (float *)malloc(sizeof(float) * width);
  img = wb_camera_get_image(cam);
  for(int i = 0; i < width; i++)
  {
      int c = 0;
      for(int j = 0; j < height; j++){
        c += wb_camera_image_get_blue(img, width, i, j);
      }
      intensity[i] = c;
  }
  max = 0;
  delta = 0;
    
  for (int i = 0; i < width; i++){
    if(intensity[i] > max){
      max = intensity[i];
      max_id = i;
      delta = i - (width/2); //if <0, then object is to our left
    }
  }
  
  int it = 0;
    if (max_id >= 0 && max_id < height) 
    {
      for (int j = 0; j < height; j++) 
      {
        if (T < wb_camera_image_get_blue(img, width, max_id, j))
          it++;
        
      }
    }
    
  return it;
}


int main()
{
  wb_robot_init();
  
  reset();
  
  while(wb_robot_step(TIME_STEP) != -1)
  {
    operate();
    
    if(colourIntensity()>20)
    {
      wb_motor_set_velocity(leftMotor, 0);
      wb_motor_set_velocity(rightMotor, 0);
    }
  }
  
  wb_robot_cleanup();
  
  return 0;
}
