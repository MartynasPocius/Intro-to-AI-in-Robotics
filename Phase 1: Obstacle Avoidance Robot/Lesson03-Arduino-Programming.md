<h1> Lesson 03: Arduino Programming </h1>

<h2> Introduction </h2>

In this lesson, we'll have a look at how to write the program for the Arduino board using both the Arduino IDE (Integrated Development Environment) and TinkerCAD. 
The lesson will cover: 
<ul>
  <li> an overview of both interfaces </li>
  <ul>
    <li> Arduino IDE </li>
    <li>TinkerCAD</li>
  </ul>
<li> the basic syntax of the code </li>
  <ul>
    <li>setup() and loop() functions</li>
    <li>some useful programming tips</li>
    <li>defining pins</li>
  </ul>
<li> explanation of simple examples with more to try</li>
</ul>

<h2>An overview of both interfaces</h2>
As mentioned at the end of the previous lesson, Arduino programming is based on the the C/C++ language, however you don’t need any prior experience of this to learn how to program an Arduino.

To start off, we’ll look at the Arduino IDE interface and how it’s replicated in TinkerCAD.  

<h3>Arduino IDE</h3>

The Arduino IDE is a software used to write and upload code to the physical board (the microcontroller introduced in Lesson 01). 

The Arduino IDE can be downloaded from the Arduino website  <a href="https://www.arduino.cc/en/software" target="_blank">here</a> and you’ll find all the instructions to do this for your operating system. It is completely free and open-source and can be used with any Arduino board, not just the Arduino Uno we’ll be using.

Once you’ve got this downloaded and opened, the interface that you’ll see will look something like this. 

<p align="center">
<img src="https://user-images.githubusercontent.com/39732505/106220413-5bbc6880-61d3-11eb-8995-037a52112092.png" alt="Screenshot of Arduino IDE" width="487" height="520">  </p>
 
When the board and components are connected, we can upload the program (called a <b>sketch</b>) we want to run to the Arduino. 

As you can see in the figure above, the IDE automatically adds the main structure of the program of the `setup` and `loop` functions. These are explained in more detail later. 

The labelled buttons are mainly self-explanatory. Some that may not be as obvious are the serial monitor and the verify buttons.  

<h3>TinkerCAD</h3>

In TinkerCAD, we can build our Arduino circuit from the parts provided instead of building these physically and use simulations to test our code. 

There are two ways to code the Arduino board and connected components: 
<ul>
  <li> using blocks that can be dragged and connected </li>
  <li> writing code in the same way as the Arduino IDE (TinkerCAD calls this text) </li>
</ul>

In order to write code in TinkerCAD, you must first have the required components and board connected. 

In this lesson, we’ll show the examples using TinkerCAD, but the code will be very similar if using physical parts (you may need to change pin numbers depending on the individual setup, but the main logic of the code will remain the same). 


<h2>The basic syntax of the code</h2>


<h3>setup() and loop() functions</h3>

An Arduino sketch consists of two main functions, the `setup()` and `loop()` functions. The `void` simply means that the function does not return any information.

<h4>void setup()</h4>
<ul>
  <li>This is the setup function that is called at the start of the program. </li>
  <li>It runs only once</li>
  <li>It is used to initialize the pin modes, variables, start the serial communication, start using libraries, etc. </li>
</ul>

You must always have the setup function in your code regardless of whether there is anything to execute inside this. 

<h4>void loop()</h4>
<ul>
  <li>This function is executed after the setup() function</li>
  <li>It repeats (loops, as suggested by the name) continuously, until the Arduino board is switched off or reset</li>
  <li>This is where the main bulk of the code will go</li>
</ul>

<h3>Syntax essentials</h3>

The code for a function goes inside the curly brackets/braces: `{` and `}`. 

Each statement (line of code) must be terminated by a semicolon `;`. 

You can add single-line comments using `//` and multi-line comments by starting with `/*` and ending with `*/`

<h4>Programming basics</h4>

If you've done programming before, you will find that the data types, variables and operators are identical or very similar to what you have seen before. While most of these will be introduced through examples, you can learn more about these  <a href="https://www.tutorialspoint.com/arduino/arduino_data_types.htm" target="_blank">here</a>. 

<h2>Controls and loops</h2>

<h3>Control structures</h3>


```c
if (expression) {
  statements;
  }
```

```c
if (expression) {
  statements;
 }
else {
  more statements;
}
```

<h3>Loops</h3>

```c
while (expression) {
  statements;
  }
```


```c
for (initialize; control; increment or decrement) {
  statements;
  }
```

