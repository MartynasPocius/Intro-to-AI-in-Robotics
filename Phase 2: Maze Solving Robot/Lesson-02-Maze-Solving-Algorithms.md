# Lesson 02: Maze Solving Algorithms

Before discussing how IR sensors can be implemented in our maze solving robot, let's look at some of the maze solving algorithms.


Generally speaking, all algorithms can be divided into two categories - those designed for a solver without any prior knowledge of the maze, and algorithms that require the user to see all maze at once. Some of the techniques that belong to the first category are **random mouse**, **wall follower**, **pledge**, and **Tremaux's**, while **dead-end** and **shortest path** algorithms are attributed to the second category.


## Algorithms without prior knowledge

### Random mouse algorithm

As the name suggests, the user in this algorithm wanders around the maze until it reaches the end of the maze. According to the rules, the bot has to move in its current passage until reaching the junction. At that point, the bot makes a random decision and continues to move until the other junction. Although this trivial method ultimately is going to lead to the end of the maze, it is extremely slow, and inefficient.

### Wall follower

Wall follower algorithm (also known as the *left-hand* or *right-hand* rule) states that if the maze is *simply connected* and the bot keeps to one side of the path, it is going to reach the end eventually if that end exists. Let's break down this definition. For this strategy to work, our maze has to be *simply connected* - in other words, all walls should be connected and there should not be any loops (otherwise, we could end up in the infinite loop). If this condition is met, then the agent should travel near one of the sides of all passages **without changing that side** as if it would put a virtual hand on one of the walls and traveled until the end not taking of that hand (that's where the alternative names of this rule came from). The choice for the side at which the bot is traveling does not matter (although depending on the maze we are trying to solve, one of the choices might take longer). One thing to note is that for this strategy to work, the starting position of the bot should be at one of the entrance points, otherwise, it might get stuck on the section disjoint from the exit.

<img src = "https://upload.wikimedia.org/wikipedia/commons/f/f7/Maze01-02.png" width = "400">

### Pledge algorithm

This algorithm is quite similar to the wall follower algorithm - the bot orientates itself by keeping a "hand" on the wall. On the other hand, in the pledge algorithm, the choice of the side is not constant, as it is changed according to the following rule. The bot starts by going forward and then choosing one of the sides, while also keeping a record of its turns (let's say that all clockwise turns are positive, while the anticlockwise turns are negative). The bot keeps traveling along the wall until the number of turns is 0 and it is facing the same direction it was traveling at first. Then the process repeats with the bot traveling directly under another obstacle. *Note that both of these conditions have to be satisfied - as you can see in the following figure, the bot does not escape at the point where it is facing the initial direction, but the turned angle is 360*.

<img src = "https://upload.wikimedia.org/wikipedia/commons/thumb/2/27/Pledge_Algorithm.png/440px-Pledge_Algorithm.png" width = "500">

### Tremaux's algorithm

This algorithm is a bit more complex than the previous ones, but in general, it can possibly be applied to the majority of mazes out there. One of the most important features of this algorithm is that the bot marks the path it travels through and acts based on the number of marks on the passage. According to Tremaux's algorithm, there are three types of passages:
- Empty - a passage that has not yet been visited.
- Marked once - the passage was visited only once.
- Marked twice - the passage was visited two times which indicates the wrong path, as the bot was forced to turn back.

Consequently, the agent in the maze has to obey the following rules:
- It should never enter the passage that was market twice.
- If the bot travels at the junction with an empty passage, choose any free path and mark it
- If you travel at the junction with one mark, you should turn around and mark the passage you used to come to that junction (*same applies to the dead-ends).
- If there are more marks at the junction, follow the path with the least marks.

*You can refer to the following resource for a more visual explanation - http://www.cems.uvm.edu/~rsnapp/teaching/cs32/notes/tremaux_rules.pdf*

## Algorithms with prior knowledge

As the following algorithms require prior knowledge of the maze, they are not so useful for our maze solving bot project, however, let's look at them for the sake of a general understanding.

### Dead-end algorithm

The main idea behind the dead-end algorithm is that it fills the dead-ends until the first junction - this only leaves the correct passages. One important note here is that the speed at which you are filling passage from the ends has to be the same.

![Alt Text](https://user-images.githubusercontent.com/73468790/107852321-cf3bb800-6e18-11eb-8fa7-9cf0bc97a90d.gif)

### Shortest path

When the maze has more than more solution it might be useful to find the shortest possible path. There a several graph theory based techniques that might be applied when searching for the shortest path, however, the most commonly used is the bread-first search (BFS). In this technique, the maze is divided into cells. Then each of the cells is visited in the increasing distance order, and at the end, the overall distances for each path are compared.
