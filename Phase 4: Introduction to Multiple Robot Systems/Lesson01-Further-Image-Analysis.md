# Further Image Analysis

In the last week's material, we have started working with the basic robotic vision by analyzing pixel colour levels and determining the maximum intensity point. On the other hand, the intensity itself does not show us much information, therefore, we are going to look at other types of data that can be extracted from the image.

## Recognition node

As it was mentioned in the last week's challenge, the Webots Camera device has a special node associated with the object recognition capability (*Recognition*). When such a Camera has this node in its recognition field, it has the ability to recognize Solids in the Camera image. One thing to note is that the Recognition node cannot identify objects with empty ```recognitionColors``` field.
In addition, the Recognition node also provides a segmentation function only displaying the recognized objects with ```recognitionColors```. This is particularly useful when we try to identify objects in a more precise manner, as the robot image is no longer distorted by the surrounding noise. Just for a better understanding, look at the regular vs segmentation image comparison below:

<img src = "https://raw.githubusercontent.com/cyberbotics/webots/released/docs/reference/images/recognition_segmentation_image.png" width = "600">

On the left, you can see a regular image, while the right field corresponds to the segmented view. As you can see, the background, as well as, other objects with empty ```recognitionColors``` fields cannot be seen (they are identified as black objects). The identified objects with a specific value in the ```recognitionColors``` field are assigned a unitary colour across that object (there are no shades).

The Recognition node (depending on the "camera model"), can have a variety of parameters associated with our Camera device some of which can be seen in the table below:

| **Field** | **Function** |
| --- | --- |
| ```maxRange``` | defines the maximum distance at which an object can be recognized |
| ```maxObjects``` | defines the maximum number of images that can be recognized (-1 = unlimited) |
| ```occlusion``` | defines if the occlusion between the camera and the object should be checked |
| ```frameColor``` | defines the virtual frame colour for the recognized object |
| ```frameThickness``` | virtual frame thickness |


### Recognition node in e-puck

If you had a chance to open the e-puck object file in the ```Screen Tree```, you have probably realized that there is no Recognition node. As every object in Webots, e-puck consists of multiple nodes corresponding to a physical part, including, the Camera device. On the other hand, the ```Base Nodes``` of the e-puck are already grouped together which means that it is impossible to get to the ```Recognition Node``` straight away. To do that, you first have to convert your e-puck object to its base nodes and then locate the Recognition node: right click on the ```e-puck```, and then select ```Convert to Base Node(s)```. To locate and enable the Recognition node (which is disabled by default), go to ```children``` -> ```DEF EPUCK_CAMERA Camera``` -> ```recognition NULL```, then ```Add New```, and select ```Recognition``` from the base nodes.
Now, we can move on to some of the useful commands that can be implemented with the Recognition node.

## Useful commands

### Library and initialization

As it goes with the majority of functions, before using the image recognition node, we must first include a specific library (```camera_recognition_objects.h```) and then enable the image recognition method (```wb_camera_recognition_enable()```).
```c
... //other libaries we are going to use
#include <webots/camera_recognition_objects.h>
#include <webots/camera.h>

int main()
{
  cam = wb_robot_get_device("camera");
  wb_camera_enable(cam, TIME_STEP);
  wb_camera_recognition_enable(cam, TIME_STEP); //enabling image recognition
}
```

### Image analysis

After the initialization process, in the ```while()``` loop, we can use a variety of commands to extract data.

#### Counting objects

```c
int object_number = wb_camera_recognition_get_number_of_objects(cam);
```

#### Extracting object's information

After counting the number of objects present in our image, we can use a ```wb_camera_recognition_get_objects(camera_object_name);``` function. The output of this function can be further analyzed to retrieve the name, relative position, relative orientation, and many other parameters of our identified object.

```c
const WbCameraRecognitionObject *objects = wb_camera_recognition_get_objects(cam);

for (int i = 0; i < object_number; i++)
{
  objects[i].model; //returns the name of the object
  
  //Relative position
  objects[i].position[0];
  objects[i].position[1];
  objects[i].position[2];
  
  //Relative orientation
  objects[i].orientation[0];
  objects[i].orientation[1];
  objects[i].orientation[2];
  
  //Size of an object (only x and y)
  objects[i].size[0];
  objects[i].size[1];
  
  //Position in the image
  objects[i].position_on_image[0];
  objects[i].position_on_image[1];
  
  //Size in the image
  objects[i].size_on_image[0];
  objects[i].size_on_image[1];
}
```
