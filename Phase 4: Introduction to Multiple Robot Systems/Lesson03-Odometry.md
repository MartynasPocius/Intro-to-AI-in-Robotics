# Odometry

In the last lesson, we have introduced the concept of the coordinate system which particularly is going to be important for the remaining tutorial series. On the other hand, we haven't yet discussed, how can we use the coordinate data to adjust our movement in a precise manner. In this lesson, we are going to learn the basics of odometry which will allow us to control and estimate the robot's path.

## Theory

Odometry as a field describes how we can use motion sensors to estimate the relative position of the robot after a certain amount of time. To achieve this, we have to make use of the robot motor encoders which basically count the number of increments (in other words, steps) completed by motor. By knowing the number of increments it takes to complete one rotation (for the e-puck case, it is 1000 steps for one revolution), and the dimensions of the wheels, we can calculate the distance covered by each wheel which can be translated into trajectory using the basic trigonometry.

On the other hand, it is important to understand that this is only an approximation, as it is practically impossible to calculate trajectory without any error (this especially applies in the real setting). This error is accumulated with each step, which demonstrates a more significant effect, as the time goes on. Therefore, at large distances, the odometry losses its purpose. We aren't going to face such a problem, however, as our simulations are going to involve short distances in which odometry can provide precise results.

### Determining the position

<img src = "https://www.researchgate.net/publication/335317557/figure/fig1/AS:794513966637068@1566438299741/Mobile-robot-odometry-and-its-relevant-variables.jpg" width = "400">

Let's say our robot is at position *p = [x, y, &theta;]*. After moving by *[&Delta;x, &Delta;y, &Delta;&theta;]*, our new position becomes *P = [x, y, &theta;] + [&Delta;x, &Delta;y, &Delta;&theta;]*. Let's say our encoders of the left and right wheels have *&Delta;s1* and *&Delta;s2* respectively. With this in mind, we can express *&Delta;x, &Delta;y,* and *&Delta;&theta;* in terms of encoder values:

*&Delta;x = (&Delta;s1 + &Delta;s2)/2 * cos(&theta; + (&Delta;s1 - &Delta;s2)/2b)*

*&Delta;y = (&Delta;s1 + &Delta;s2)/2 * sin(&theta; + (&Delta;s1 - &Delta;s2)/2b)*

*&Delta;&theta; = (&Delta;s1 - &Delta;s2)/b*

Therefore, according to odometry, our position functions becomes:

*P = [x, y, &theta;] + [(&Delta;s1 + &Delta;s2)/2 * cos(&theta; + (&Delta;s1 - &Delta;s2)/2b), (&Delta;s1 + &Delta;s2)/2 * sin(&theta; + (&Delta;s1 - &Delta;s2)/2b), (&Delta;s1 - &Delta;s2)/b]*
