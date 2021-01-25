# Microcontrollers and Arduino Uno

## What is a microcontroller?

<p>
  <img src = "https://store-cdn.arduino.cc/usa/catalog/product/cache/1/image/500x375/f8876a31b63532bbba4e781c30024a0a/a/0/a000066_front_8.jpg" width = "300"/>
  <img src = "https://www.elektor.com/media/catalog/product/cache/1404d1bfd8e1ad71cc6f16950ff5c805/r/a/raspberry-pi-4-4gb.jpg" width = "300"/>
  <img src = "https://5.imimg.com/data5/OG/KA/MY-58765457/318469-500x500.png" width = "300"/>
</p>
The microcontroller is a computing device that executes a given program and functions as the *"brain"* of the robot. In most cases, it is main device responsible for all decision making, computation and communication between other electrical components. The communication with the surrounding environment is achieved with a use of pins that can either be turned on (HIGH) or off (LOW) by the program. For example, if we want to control the blinking light with microcontroller, we should connect device to pins and write a repeating program that sends HIGH signal (light turns on) followed by the LOW one (light turns off).

## Arduino Uno

There are a number of mictrocontrollers available in the market differing by their architecture and the simplicity. During this course, however, we are going to focus on Arduino Uno microcontroller board (left picture at the top), as it is rather simple, popular among the hobbyist, and one of the best price to functionality ratios.


### Structure

<img src = "https://learnstempedia-e872.kxcdn.com/wp-content/uploads/2018/08/Arduino-Pins-Description.png" width = "400"/>

From the architecture perspective, Arduino Uno is based on the ATmega328 microchip and is equiped with 14 digital input/output, and 6 analog input pins. Although each of 14 digital pins can be used both, as an intput or output, it is a general consensus that the output components (LED, LCD, etc.) should be powered using the digital pins. The sensors, on the contrary, should be plugged into the analog pins as they have analog value. In addition, to the mentioned pins, there are a few power supply pins (3.3V, 5V, GND, Vin) - these are used to supply power to the external input or output components. Arduino UNO also has a USB port (used to program the board) and a power jack used to provide 9V. Finally, there is a reset button and a few LEDs.

## Programming

### Tinkercad environment

## Exercises

### Exercise 

### Exercise02
