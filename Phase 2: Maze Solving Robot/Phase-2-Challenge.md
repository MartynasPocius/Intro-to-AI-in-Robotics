# Phase 2 Challenge

As in the previous part of the series, this week you are going to have a new challenge. On the other hand, Tinkercad does not support IR sensor modules that are going to be used for the physical bot. Therefore, the Phase 2 challenge is going to be separate for people with and without the physical kit.

## Challenge with physical parts


**1. First, construct and program a line following robot. There are no general requirements for the path size or shape, however, try avoiding sharp corners, as we are using only 2 IR sensors (you could use the path presented below)**

<img src = "https://lejosnews.files.wordpress.com/2015/05/follower3.jpg">

**2. Build a maze solving robot and implement the wall following algorithm. You can choose your own maze design, or you could build the setup presented below.**

<img src = "https://user-images.githubusercontent.com/73468790/107856492-1fbf0f80-6e31-11eb-9a6e-ce7e1d26ca12.png">


As always, here are some tips regarding, these two challenges:
- Before doing the programming part of both tasks, first, upload a sample code and use a serial monitor just to check that your sensors are functioning appropriately. If there is no output, there might distance adjustment or your choice for Vout pins (in the second case, it would be useful to search what pins does the L293D motor shield use).
- Just for the simplicity of the second task, your robot is not required to stop at the end of the maze.
- There are multiple ways and combinations in which you could construct the maze solving bot, however, you should aim to use both, IR and ultrasonic sensors (some of them could be used to simulate a *"virtual hand"* on the wall, while others could indicate the obstacle ahead).
- For the first part of the challenge, your IR sensors should be facing downwards, and the line should go in between the sensors (so that the bot would adjust its path, whenever, crossing the line).

## Challenge without the physical parts

For this week's challenge, we are going to use the [robotbenchmark website](https://robotbenchmark.net) - it offers a series of Webots software-based robot programming tasks that are also going to work as an introduction to the Phase 3 material. Even though we are going to use C for the programming part later on, for this task, we are going to use Python. The challenge is as follows.

**1. First go through tasks 1 to 4 (including the last exercise) to get familiar with the simulation software**

<img src = "https://user-images.githubusercontent.com/73468790/107873359-b4ba1b00-6eba-11eb-9e77-cda7c6bfb2c6.png" width = "500">

**2. Then complete the "Wall Following" challenge aiming to achieve at least 50% performance**

<p float = "left">
  <img src = "https://user-images.githubusercontent.com/73468790/107873436-3ad66180-6ebb-11eb-85f9-74b350793e88.png" width = "400">
  <img src = "https://user-images.githubusercontent.com/73468790/107873476-7a04b280-6ebb-11eb-8adb-54d185ae03cd.png" width = "400">
</p>
