# Running your first simulation

In this lesson, we are going to look at some basics of "Webots" to get you started with your first simulation. After downloading the package from [cyberbotics.com](https://cyberbotics.com/#download), follow the installation instructions, open the program to continue with the following tutorial.

## Creating a new world

<img src = "https://user-images.githubusercontent.com/73468790/109425134-904c5b80-79ef-11eb-9f92-d6f6f33bbe8d.png" width = "500">

Worlds in Webots are the files (having .wbt extension) containing a variety of information ranging from the location in the space to the physical appearance, masses of the objects, and many more. It basically contains all the initial data of the simulation. Objects within this simulation are hierarchically organized in a Scene Tree and called Nodes. Consequently, all sensors, actuators, and other pieces of equipment attached to the robot object are called sub-nodes.

- Create a new project by selecting ```Wizard```, ```New Project Directory```. Then choose the names for the project directory, world file, and tick "Add rectangular arena" (we are going to need it for the latter exercises).

If you have followed these instructions correctly, you should now have your first world with a rectangular arena. Most of the time, however, the default conditions of our arena size or other characteristics are not suitable. The properties of the arena size or any other object in Webots can be done in the scene tree viewer. It should update whenever you add or remove an object - as we added a rectangular arena, there should be a RectangleArena node used to describe the physical parameters.

- We want our arena to be twice smaller. To achieve this, double click on the arena node and decrease the values of ```floorTitleSize``` and ```wallHeight``` twice.

## Adding Objects

<img src = "https://user-images.githubusercontent.com/73468790/109425179-c7227180-79ef-11eb-889e-426b8f03640f.png" width = "500">

The process of adding objects is relatively straightforward. To illustrate this, let's add a wooden box to our arena:
- Select ```RectangleArena``` node, and then click on the ```Add``` button. To add a wooden box navigate ```PROTO nodes (Webots Projects)``` -> ```objects``` -> ```factory``` -> ```containers``` -> ```WoodenBox```. We need to reduce the size of our box, therefore, follow the same principles as with the rectangular arena to reduce the size. Finally, move your box to our desired location and save our simulation.

As we have our environment setup, we can now add our robot. Although, it is possible to import your own robot objects, for this instance we are going to use the pre-installed e-puck robot. It is a relatively small robot equipped with 10 LEDs, 8 distance sensors, and a camera. To add e-puck to our environment, do the following steps:
- First reset the simulation, so it shows 00:00:00 (important for the timestep value). Then select the wooden box node and navigate to ```PROTO nodes (Webots Projects)``` -> ```robots``` -> ```gctronic``` -> ```e-puck``` -> ```E-puck (Robot)```. Finally save your simulation and run it.

## Controller

As we have created our simulation environment, as well as, our e-puck, we have to find a way to control it. For this purpose, Webots uses *controllers* that basically describe the behaviour of your robot or any other node. There are many programming languages in which you can write your code in the controller including Java, Python (we used it in the last week's material), MATLAB, however, for the sake of continuity, we are mainly going to focus on C.
One important thing to note when using the controllers is that the same code in the controller can be used by the multiple nodes (usually robots), however, it is impossible to assign multiple nodes for the same controller. The process of creating a new controller is relatively straightforward:
- Using the same ```Wizards```->```New Robot Controller``` menu, create a new controller which is going to be saved under your simulation directory.

If you followed the steps correctly, you should now see a new code file in the text editor window.
<Insert a picture of the text editor window>

In order to program our e-puck, however, we need to assign our controller to the bot. To do this, select your robot node and in the ```controller``` field press ```Select``` and then pick your controller from the list.
Now let's change some portions of the default code. 

- First include ```<webots/motor.h>``` library which will allow us to create our motor objects by using ```WbDeviceTag name_of_your_motor = wb_robot_get_device("motor_name");```(similarly to assigning object to a pin). Set the distance which you want your motors to travel with ```wb_motor_set_position(name_of_your_motor, distance);``` (can be imagined as ```digitalWrite()``` function, just this time, instead of the state of the pin, we are assigning the distance). Finally, save your code by navigating ```File```->```Save Text File``` and compile with ```Build```.

The controlling motor speed is quite similar to setting the position we want our bot to travel to: we can use ```we_robot_set_valocity(name_of_your_motor, velocity_value)```.

## Further modifying the environment

In the further example, we are going to add another body to our simulation - a rigid ball. Rigid bodies are defined as solid node objects with a negligible deformation (the distance between two points remains constant with the time) which particularly is going to be useful when introducing physics. You can add the ball in the following way:
- Similar to the previous example with the e-puck, select the last added node and press ```Add``` button to select ```Solid node```. Then in the tree view select ```Children``` field and add a shape node to it by pressing ```Add``` button. Select the ```Appearance``` field of the Shape node and add a ```PBRAppearance```. To specify and further characterize our sphere, add ```Sphere``` node as a geometry field, another ```Sphere```node to the ```boundingObject``` field, and finally add ```Physics``` field to the physics field of the sphere.

For the time being, we are not going to discuss other variables related to the environment specification - instead, we are going to test our skills in the replication of the obstacle avoidance robot.
