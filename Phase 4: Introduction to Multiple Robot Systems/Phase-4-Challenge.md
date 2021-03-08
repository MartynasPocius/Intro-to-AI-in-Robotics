# Phase 4 Challenge

For this week's challenge, we are going to build a master/slave robot system. In the next week's material, we are going to discuss this topic more in-depth, but for now, you can imagine it as a multiple robot system in which one robot is responsible for the environment processing and other robot's control.

#### Challenge

*Create a simulation with two e-pucks: one of them is going to scan the environment and search for a chosen color object. After finding that object, our "master" robot is going to send its' coordinates to another bot, which then is going to travel to those coordinates.*

Here are some tips for this week's challenge:
- For the scanning and object searching, you can implement the same code you used for the last week's challenge.
- Although we haven't discussed ```Supervisors```, they could be implemented for sending coordinates data.
- It's possible to write everything in one code block, however, it would be quite useful to create a separate function for the controlled robot.
