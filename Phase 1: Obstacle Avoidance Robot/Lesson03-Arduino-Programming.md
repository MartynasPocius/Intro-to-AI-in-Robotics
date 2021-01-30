<h1> Lesson 03: Arduino Programming </h1>

<h2> Introduction </h2>

In this lesson, we'll have a look at how to write the program for the Arduino board using both the Arduino IDE (Integrated Development Environment) and TinkerCAD. 

<h2>An overview of both interfaces</h2>
As mentioned at the end of the previous lesson, Arduino programming is based on the the C/C++ language, however no prior experience of these languages is required to learn how to program an Arduino.

To start off, we’ll look at the Arduino IDE interface and how it’s replicated in TinkerCAD.  

<h3>Arduino IDE</h3>

The Arduino IDE is a software used to write and upload code to the physical board (the microcontroller introduced in Lesson 01). 

The Arduino IDE can be downloaded from the Arduino website  <a href="https://www.arduino.cc/en/software" target="_blank">here</a> and you’ll find all the instructions to do this for your operating system. It is completely free and open-source and can be used with any Arduino board, not just the Arduino Uno we’ll be using.

Once you’ve got this downloaded and opened, the interface that you’ll see will look something like this. 

<p align="center">
<img src="https://user-images.githubusercontent.com/39732505/106220413-5bbc6880-61d3-11eb-8995-037a52112092.png" alt="Screenshot of Arduino IDE" width="487" height="520">  </p>
 
When the board and components are connected, we can upload the program (called a <b>sketch</b>) we want to run to the Arduino. 

As you can see in the figure above, the IDE automatically adds the main structure of the program of the `setup` and `loop` functions. These are explained in more detail later. 

The labelled buttons are mainly self-explanatory, with the Verify button checking the code for errors, the Upload button compiling the code and uploading it to the configured board, the New button creating a new sketch, the Open button presenting a menu of all sketches in your sketchbook, the Save button saving your sketch and finally the Serial Monitor button which displays serial sent from the Arduino or Genuino board over USB or serial connector. 

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

An Arduino sketch consists of two main functions, the `setup()` and `loop()` functions. The `void` keyword simply means that the function does not return any information.

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

The code for a function goes inside the curly brackets: `{` and `}`. 

Each statement (line of code) must be terminated by a semicolon `;`. 

You can add single-line comments using `//` and multi-line comments by starting with `/*` and ending with `*/`

<h4>Programming basics</h4>

If you've done programming before, you will find that the data types, variables and operators are identical or very similar to what you have seen before. While most of these will be introduced through examples, you can learn more about these  <a href="https://www.tutorialspoint.com/arduino/arduino_data_types.htm" target="_blank">here</a>. 

<h2>Controls and loops</h2>

<h3>Control structures</h3>
Similar to other programming languages, the Arduino programming language contains selection constructions such as the if statement as well as the if...else conditional statement. The syntax for these can be seen below:

```c
if (expression) {
  statement 1;
  statement 2;
  }
```

```c
if (expression) {
  statement 1;
  statement 2;
 }
else {
  statement 3;
}
```

<h3>Loops</h3>
In addition, the programming language also contains both definite and indefinite iteration in the form of while loops and for loops respectively. Where while loops continue to be executed until the expression equates to being false, for loops instead are only executed a certain number of times.

```c
while (expression) {
  statement 1;
  statement 2;
  }
```


```c
for (initialize; control; increment or decrement) {
  statement 1;
  statement 2;
  }
```

<h2>Input/Outputs</h2>

<h3>Initialising pin modes</h3>

The first thing that needs to be done in when writing the program once the physical parts, or simulation parts in TinkerCAD have been connected, is to intialise the pins of the Arduino that are being used as inputs or outputs. This is done inside the `setup()` function. 

The general syntax for this is as follows. 

```c
void setup() {
pinMode(pin, mode)
  }
```
Here, the `pin` is the number of the pin for which we are setting the mode. The `mode` can either be INPUT, OUTPUT, or INPUT_PULLUP. 

- Arduino pins are configured as inputs, so it is not necessary to explicitly define them as inputs. Pins in this state are referred to being in `high-impedance` states in which they take a very small amount of current from the circuit and thus require very little current to move the input state from one state to another. 
- If a pin is configured as an output then it is in a `low-impedance` state in which it provides a current (of up to 40 mA for Atmega pins) to other circuits, which as we can see in the example, allows us to turn on a bright LED.
- It is important to note that in order to prevent a circuit/device to draw maximum current from an output pin and thus result in a short circuit, a resistor (usually with resistance of 470Ω or 1KΩ) is connected in series with the devices. Short circuits will usually result in the pin no longer functioning and signficant current being drawn through these pins can also damage the entire Atmega cip.
- We won't go into much detail about the INPUT_PULLUP state but it essentially is used to invert the behaviour of the INPUT mode (swapping the HIGH and LOW).

To demonstrate this, we can take the example of the blinking LED that was shown in Exercise 01 of Lesson 02. 

The `setup()` function for this program was as follows:

```c
void setup() {
pinMode(LED_BUILTIN, OUTPUT);
}
```

In this code, the pin we are initialising is the `LED_BUILTIN` which is an LED already built in the Arduino, to the OUTPUT mode. 

The value of an OUTPUT pin can be set to `HIGH` or `LOW` which corresponds to the voltage of 5V (or 3.3V depending on the Arduino board) or 0V (i.e. ground) respectively. 

If instead we want to add an LED component to the circuit (with a 1K resistor to prevent a short circuit), we can connect these components manually to the Arduino. The simulation for this in TinkerCAD connects these components directly (you can find this in Starters -> Arduino -> Blink), however you can also connect them using a breadboard using what you learnt in Lesson 01. 

The LED in this case is connect to pin `13`, so the above `setup()` function for this circuit will become:

```c
void setup() {
pinMode(13, OUTPUT);
}
```

<h3>digitalWrite() function</h3>

Now we can have a look at the `loop()` function for the blinking LED code. 

```c
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);                       
}
```

This first thing in this loop is the `digitalWrite()` function which is used to change the value of a digital pin to either HIGH or LOW. In this function we first specify the pin number (here it is the inbuilt LED instead of a pin number) and secondly, whether we want to set this value to HIGH or LOW (corresponding to the voltage as explained above). 

The general syntax of this is `digitalWrite(pin, value)`. 

The second function used in this program is the `delay()` function. This tells the program to wait for a specified period of time as an **integer** in **milliseconds** before moving to the next statement (line of code).

If we want to use an even shorter period of time, there is also a `delayMicroseconds()` function which takes an **integer** in **microseconds**. 

1 second = 1000 milliseconds = 1000000 microseconds






