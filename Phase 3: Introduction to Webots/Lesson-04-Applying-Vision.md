# Introduction to cameras

Before going too much in-depth to other future projects, we are first going to have a very brief introduction to cameras.

## Basic Commands

Generally speaking, cameras are like any other devices in Webots: you include the library, define relevant constant, initialize the camera object, enable it and finally read the data. Although the ```camera``` module itself is very vast (it is going to be one of our main focus areas for the remaining tutorial series), the process described above can be achieved with these lines of code.

**Library and constants**
```c
#include <webots/camera.h>
#define TIME_STEP 64 //the TIME_STEP for the camera can differ from the main TIME_STEP
```

**Initialize camera and enable it**
```c
WbDeviceTag cam;
cam = wb_robot_get_device("camera");
wb_camera_enable(cam, TIME_STEP);
```
**Capturing an image**
```c
const unsigned char *image = wb_camera_get_image(cam);
```

Before moving on to the further analysis of our image data, let's think about our ```image``` variable for a moment. The ```wb_camera_get_image()``` function that we have used returns the last image picked up by the camera. On the other hand, just taking an image is not sufficient enough for further image analysis (at least for now). Therefore, we have to analyze each individual pixel of the object to retrieve any useful information.
Pixels in the image are stored in the horizontal lines and ranges from the top left corner to the bottom right. Each of them have can have three levels - red, green, or blue. When analyzing our image, we usually tend to 'scan' the image from the top left to the bottom right corner, and record the level data for each of the pixels. To access these levels, ```wb_camera_image_get_red()```, ```wb_camera_image_get_green()```, ```wb_camera_image_get_blue()```, or ```wb_camera_image_get_gray()```(returns gray level by averaging RGB levels) are used. The result of these functions is in the range of 0 to 255, that's why we use ```unsigned char *``` type.

Let's say we would like to take an image, and then retrieve the red level data for our image. This can be achieved with the following code:
```c
const unsigned char *image = wb_camera_get_image(cam);
for (int x = 0; i < image_width; x++){
  for (int y = 0; i < image_height; y++){
    int rLevel = wb_camera_image_get_red(image, image_width, x, y)
  }
}
```
The code above scans our image, and assigns red level at coordinates ```x``` and ```y```. As you have noticed, we are putting ```image_width``` and ```image_height```, as our boundaries, even though, we haven't found the size of them. To get the dimensions of our image, we can use the following code:
```c
int width = wb_camera_get_width(cam);
int height = wb_camera_get_height(cam);
```
Therefore, our final code for **capturing the image and retrieving a specific level data are:**
```c
const unsigned char *image = wb_camera_get_image(cam);
int width = wb_camera_get_width(cam);
int height = wb_camera_get_height(cam);

for (int x = 0; i < image_width; x++){
  for (int y = 0; i < image_height; y++){
    int rLevel = wb_camera_image_get_red(image, image_width, x, y)
  }
}
```

## Further image analysis

In the last example, we managed to successfully retrieve the red level data at each specific coordinate, however, this knowledge itself is not super useful. For example, if we want to determine the location of the red square, this command would only provide us with the level data throughout the coordinates. On the other hand, if we would create a block of memory that would store these level values at each position, it would represent the object we are trying to perceive (*for example, if we would have a red square in the green background, we could run the loop to retrieve the red level data at each pixel and then the positions at which red level has a high value would indicate the point located on the square*).

There are many ways in which we could create this memory block array being one of the obvious ones. However, as we take an image, we do not particularly know the dimensions our image window is going to have. This is solved, by the concept of **dynamic memory allocation**. 

### Dynamic memory allocation

We are not going to cover the dynamic memory allocation too much in-depth (at least, in this phase). There are a few functions in ```<stdlib.h>``` library that is used, however, the ones that we are going to use for our series are ```malloc()```, and ```free()```

**malloc()**

This function basically reserves a specified size memory block. It has the following syntax:
```c
variable = (typeOfVariable*)malloc(size);
```

**free()**

Since the block of memory, we created in the last portion of the code cannot be relieved on its own, we are using ```free()``` function to do so.
```c
free(variable);
```

Let's now come back to our example with the red square. For example, we are interested in navigating our bot according to the position of our square. In the case our bot only moves in the horizontal plane, we are only interested in the x component of the image, as it is completely sufficient enough to determine the position of our red square as well as its middle point. With this in mind, we can create a variable ```ins``` that is going to store our intensity value of red level along the x axis (*basically, we are going to add all red level y-axis values along the x-axis and allocate these sums to x coordinate*).

```c
float *ins = (float *)malloc(sizeof(float) * width);

for (int x = 0; x < width; x++){
  int a = 0;
  for (int y = 0; y < height; y++){
    a += wb_camera_image_get_red(image, width, x, y);
    ins[x] = a;
  }
}
```
The code above creates an ```ins``` block with a size equal to the ```width``` of our image **times** the size for the variable type we are using (size of ```float``` is 4 bytes). Finally, we scan throughout the image and read the red levels values. The integer ```a``` acts as a sum counter which stores the level data across the y coordinates for the same x coordinate.
