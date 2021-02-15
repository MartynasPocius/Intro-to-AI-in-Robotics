# Lesson 1: IR Sensors and Line Followers

Welcome to the Phase 2 asynchronous material! In this week, we are going to focus on building our own maze-solving robot, but, before that, we have to cover a few concepts starting off with a new kind of sensor - IR sensors.
## IR sensors

<p float = "left">
  <img src = "https://www.picaxestore.com/media/catalog/product/cache/8ac9a141e70c036fd47be7fa5376b415/l/e/led020_1.jpg" width = "400">
  <img src = "https://images-na.ssl-images-amazon.com/images/I/41qR9Tsh2JL.jpg" width = "440">
</p>

IR sensors interact with the surrounding environment by scanning IR signals in the specific frequency range and converting them into electrical signals. They are most commonly used for communication within relatively short distances (typically, 2 meters), however, we are going to focus on their other use - distance measurement.
When used as proximity sensors, they function similarly to the ultrasonics sensors - both of them emit and record waves to identify an object. There are only a few differences. 
First of all, (as you probably have already guessed) IR transmitter emits infrared waves, whereas the receiver records these waves and translates them in the form of 0 and 1 to the Vout pin of the sensor. When there is an object nearby, the emitted signal triggers the receiver and the module outputs 0 value, while 1 means no obstacle nearby. In addition, IR sensors tend to have a closer working range, with an effective range of 2cm - 30 cm. Finally, even though the IR module can output an analog signal, it does not translate into the distance, but rather, indicates the strength of a signal.

<img src = "https://i0.wp.com/www.etechnophiles.com/wp-content/uploads/2018/10/Arduino-IR-Collision-Detection-Module-Pin-Outs.png?resize=600%2C250&ssl=1">

The figure above demonstrates the main structural parts of the IR sensor module. Although you should be already familiar with the majority of pins, there is one thing to note - IR sensor modules usually have distance adjust bolt which comes in handy when adjusting the sensitivity of the module.

## Programming

The programming of the IR sensor is quite similar to other sensors. Even though Tinkercad does not support IR modules used for the proximity measurements, we can still illustrate the microcontroller sensor interaction with the following circuit.

<img src = "https://user-images.githubusercontent.com/73468790/107830191-02883380-6d94-11eb-846b-b11171fc3c5f.png">

The circuitry is quite straightforward - we simply power the IR sensor by connecting GND and V++ pins to the microcontroller and then connect Vout to one of the digital pins (we are going to focus on the digital signal just for now). If we would like to connect this circuit in real life and use it as a proximity sensor, we would need to implement the following code.

```c
#define irPin 2

void setup()
{
  pinMode(13, OUTPUT); //Setting up the built-in LED
  pinMode(irPin, INPUT);
}
void loop()
{
  if(irPin == 0) // When there is an object nearby
  {
    digitalWrite(13, HIGH); //LED is turned on
  }
  else
  {
    digitalWrite(13, LOW); // LED is turned off
  }
}
```
Despite the fact, that we cannot simulate this circuit in the Tinkercad environment, we can still apply our knowledge but in a bit different manner.

### Exercise01
Construct a circuit that takes an input from remote control object and uses it as a speed value for 1 DC motor. (Look at remote control documentation)

## Line following robots

Line following robots (as the name suggests) is the type of automated robots that follow a visual line on the floor or the ceiling. Even though it is possible to construct a magnetic field based path (something similar to the mechanism Roomba's used), the most common way is having black lines on the white surface. When the transmitter sends an IR wave and it is reflected by the surface, it indicates that the sensor is facing a white surface. On the other hand, when the IR wave interacts with the black object, it gets absorbed, therefore the receiver does not get the signal.

<p>
  <img src = "https://hackster.imgix.net/uploads/attachments/496036/Concept-of-White-Line-Follo.gif?auto=compress&gifq=35&w=680&h=510&fit=max" alt>
  <img src = "https://hackster.imgix.net/uploads/attachments/496035/Concept-of-Black-Line-Follo.gif?auto=compress&gifq=35&w=680&h=510&fit=max" alt>
</p>

Just for now, we are not going to discuss the concept of the line following bots or the coding part, as this is going to be one of this week's challenges for people with physical kits (*we are also going to come back to these types of bots in the Phase 3 material*).
