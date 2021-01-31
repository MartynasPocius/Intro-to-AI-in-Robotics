# Microcontrollers and Arduino Uno

## What is a microcontroller?

<p>
  <img src = "https://store-cdn.arduino.cc/usa/catalog/product/cache/1/image/500x375/f8876a31b63532bbba4e781c30024a0a/a/0/a000066_front_8.jpg" width = "300"/>
  <img src = "https://www.elektor.com/media/catalog/product/cache/1404d1bfd8e1ad71cc6f16950ff5c805/r/a/raspberry-pi-4-4gb.jpg" width = "300"/>
  <img src = "https://5.imimg.com/data5/OG/KA/MY-58765457/318469-500x500.png" width = "300"/>
</p>
The microcontroller is a computing device that executes a given program and functions as the *"brain"* of the robot. In most cases, it is the main device responsible for all decision-making, computation, and communication between other electrical components. The communication with the surrounding environment is achieved with the use of pins that can either be turned on (HIGH) or off (LOW) by the program. For example, if we want to control the blinking light with the microcontroller, we should connect a device to pins and write a repeating program that sends HIGH signal (light turns on) followed by the LOW one (light turns off).

## Arduino Uno

There are a number of microcontrollers available in the market differing by their architecture and simplicity. During this course, however, we are going to focus on the Arduino Uno microcontroller board (left picture at the top), as it is rather simple, popular among the hobbyist, and one of the best price to functionality ratios.


### Structure

<img src = "https://learnstempedia-e872.kxcdn.com/wp-content/uploads/2018/08/Arduino-Pins-Description.png" width = "400"/>

From the architecture perspective, Arduino Uno is based on the ATmega328 microchip and is equipped with 14 digital input/output and 6 analog input pins. Although each of 14 digital pins can be used both, as an input or output, it is a general consensus that the output components (LED, LCD, etc.) should be powered using the digital pins. The sensors, on the contrary, should be plugged into the analog pins as they have analog value. In addition, to the mentioned pins, there are a few power supply pins (3.3V, 5V, GND, Vin) - these are used to supply power to the external input or output components. 
Arduino UNO can be powered either via a USB port or an external power supply. There are few ways in which the external power can be provided: we can use a 2.1mm center-positive plug and connect it to the board's power hack or we could use a battery and connect it to the power pins (Vin and GND). Although the board can withstand a voltage range from 6V to 20V, the supply of 7V and less may not be sufficient enough, while the voltages higher than 12V might cause heating.
Finally, there is a reset button and a few LEDs.

## Programming

<Insert a photo of IDE>

For the programming part, Arduino uses its own language which is mainly built upon C/C++ (to be particular, a newly written code undergoes some minor changes and is directly passed to the C/C++ compiler). In addition, Arduino also has its own software for creating new sketches - Arduino IDE. We are not going to analyze Arduino programming too much in-depth in this lesson, as it is going to be discussed further in the next lesson.

### Tinkercad environment

In addition to the native Arduino IDE, it is possible to develop code in other environments. One of the examples of such software is Tinkercad which not only allows to write an Arduino code but also can be used for simple real-time circuit simulation. Therefore, we chose the Tinkercad circuit simulator for the Arduino practice part. Even though the Arduino programming is going to be covered in the next section, it is quite useful to start getting more comfortable with this software by completing an example exercise (*The following code is going to be covered more in-depth in the next section*).

### Warm-up exercise

In the Tinkercad circuit simulator, create a new circuit file. After doing so, drag the Arduino UNO object to the workspace, upload the following code, and have a look at the built-in LED.
```c
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  
  delay(500);                       
  digitalWrite(LED_BUILTIN, LOW);    
  delay(500);                       
}
```
