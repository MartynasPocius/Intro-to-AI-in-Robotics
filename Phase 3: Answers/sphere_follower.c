//Code for the "White Sphere Follower" task

#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/camera.h>
#include <stdlib.h>
#include <math.h>


#define TIME_STEP 64
#define MAX_SPEED 600
#define BACK_SPEED 200
#define S_UNIT 0.00628
#define T 200

WbDeviceTag cam;
unsigned short width, height;


WbDeviceTag leftMotor, rightMotor;

int main()
{
  wb_robot_init();
  
  leftMotor = wb_robot_get_device("left wheel motor");
  rightMotor = wb_robot_get_device("right wheel motor");
  wb_motor_set_velocity(leftMotor, 0.0);
  wb_motor_set_velocity(rightMotor, 0.0);
  wb_motor_set_position(leftMotor, INFINITY);
  wb_motor_set_position(rightMotor, INFINITY);
  
  cam = wb_robot_get_device("camera");
  wb_camera_enable(cam, TIME_STEP);
  width = wb_camera_get_width(cam);
  height = wb_camera_get_height(cam);
  
  float *intensity = (float *)malloc(sizeof(float) * width);
  
  while(wb_robot_step(TIME_STEP) != -1){
    int delta, max, max_id = 0, leftSpeed, rightSpeed;
    const unsigned char *img;
  
    img = wb_camera_get_image(cam);
    
    //reading camera and determining values along x-axis
    for(int i = 0; i < width; i++){
      int c = 0;
      for(int j = 0; j < height; j++){
        c += wb_camera_image_get_gray(img, width, i, j);
      }
      intensity[i] = c;
    }
    
    
    //determinin the offset from the middle point
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
    if (max_id >= 0 && max_id < height) {
      for (int j = 0; j < height; j++) {
        if (T < wb_camera_image_get_gray(img, width, max_id, j))
          it++;
      }
    } else
      it = (MAX_SPEED * height) / (MAX_SPEED + BACK_SPEED);
    
    
    
    leftSpeed = MAX_SPEED - (MAX_SPEED + BACK_SPEED) * it / height;
    rightSpeed = MAX_SPEED - (MAX_SPEED + BACK_SPEED) * it / height;
    
    wb_motor_set_velocity(leftMotor, S_UNIT * (leftSpeed + 4 * delta));
    wb_motor_set_velocity(rightMotor, S_UNIT * (rightSpeed - 4 * delta));
    
  }
  
  free(intensity);
  wb_robot_cleanup();
  
  return 0;
}
