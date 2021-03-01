# Phase 3: Challenge

This week you are going to have 2 challenges and one optional one:
* Create a lawnmower bot that moves by passing every point on the arena.
* Make a bot that identifies the white sphere and follows it

* *(optional)* Simulate a bot that **randomly** wanders around the arena (make it compact) until it finds a specific colour sphere, while also avoiding obstacles.

## Lawnmower

Overall, there are two ways in which a bot can cover a given area: it can choose a random path, or it can use a more structured way of movement. It's quite obvious that the first way has many disadvantages, including the long simulation time, inefficiency, and increasing chance that the bot will not manage to cover all the area. Therefore, for this challenge, we are going to use the second way. You can come up with many ways of doing so, however, for the introduction let's stick to the 'automated mower' movement:
<img src = "https://upload.wikimedia.org/wikipedia/commons/c/ca/Trajectory_walk_by_scanning.png">
This task is not so straightforward, therefore, it is completely understandable, if you do not manage to complete it (we are going to come back to this challenge in the next week). However, these are some tips that might make it easier:
- Try to think of the possible combinations of the obstacle detection and try to come up with a "plan" describing the decisions your bot is going to make accordingly to the sensor readings. For example, if you are moving forward and your sensors indicate an obstacle on the right and front, however, the left way is free, turn left and continue.
- To make everything simpler, you can use 3 IR sensors (just keep in mind, that in some cases, the bot may get stuck if the duration of your turn is not correct).
- For the starting position, try to align your bot to one of the walls.

## White sphere follower

For this task, you have to create a bot that identifies the white sphere you created and tries to follow it. You begin by including required libraries and initializing your motors as well as the camera. The sensory data handling is a bit more problematic, however, there are a few things that might help:
- Camera is gathering the intensity data for each point for the colour you specify with ```wb_camera_image_get_colourOfYourChoice()``` function.
- It might be useful to look through [camera documentation](https://cyberbotics.com/doc/reference/camera).

<img src = "https://user-images.githubusercontent.com/73468790/109414952-8e1dd900-79be-11eb-9031-82da9b040273.png">

## Optional challenge

This challenge sort of combines the previous tasks. You have to randomly wander around the relatively small arena with a few different colour solid spheres places inside of it. Whenever a bot runs into one of the specified colour spheres, it should stop. When facing the regular sphere, the e-puck should continue moving to avoid any obstacles in its path. There are few considerations for this:
- Thing how your bot is going achieve a random movement (what is the parameter that is going to be random?).
- You might use a similar code to that in *'White sphere follower'* task, or you could implement the [recognition node](https://www.cyberbotics.com/doc/reference/camera?tab-language=c#wb_camera_has_recognition) in the camera module.
