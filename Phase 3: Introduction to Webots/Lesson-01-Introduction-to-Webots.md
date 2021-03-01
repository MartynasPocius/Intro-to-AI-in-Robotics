# Webots simulation software

Webots is a professional robot simulation software that uses a rapid prototyping environment that allows to create realistic 3D worlds with fundamental physics properties (mass, friction, etc.). The software comes with a range of prebuilt robot models equipped with a number of sensors and actuator devices (motors, proximity sensors, cameras, etc.) that can be programmed for the desired behaviour.

<img src = "https://raw.githubusercontent.com/cyberbotics/webots/released/docs/guide/images/1234web.png">

## The user interface

<img src = "https://user-images.githubusercontent.com/73468790/109425006-e53ba200-79ee-11eb-8f4b-68325aad260b.png">

Although we are going cover the user interface more in detail as we progress with the series, we still need to get some things straight. Generally, the GUI of Webots can be splitted into 9 sections: File, Edit, View, Simulation, Build, Overlays, Tools, Wizards, Help.

| **Menu Section** | **Function** |
| --- | --- |
| File | Allows to save, load files and perform any other common operations |
| Edit | Allows to do usual functions with the files opened in the text editor |
| View | Controlling viewing in the editor: changing viewpoints, showing *measurement rays* (is going to be quite useful in our projects), interactions, etc |
| Simulation | Used to control the simulation: **Pause**, **Reset**, **Step** |
| Build | Here you compile your code for the controller (*is going to be discussed a bit later*) |
| Overlays | Specific parameters related to the camera devices |
| Tools | Opening specific windows |
| Wizards | Creating new projects, controllers, plugins |
| Help | Accessing documentation, etc. |

## 3D Simulation Window

The controls within 3D simulation are not so different from any other modeling software. To select an object, simply use the left mouse button, while clicking the right button will open the context menu (can be used for copying, pasting, and performing other similar operations). To move the object in the space, simply press <kbd>ctrl</kbd> key.

<img src = "https://user-images.githubusercontent.com/73468790/109424812-17003900-79ee-11eb-9454-c93889b0a989.png">

For the navigation in the scene use the following combinations:
- **Left mouse button** + **drag** = camera rotation
- **Right mouse button** + **drag** = camera translation
- **Scroll button** = Zoom in/out
