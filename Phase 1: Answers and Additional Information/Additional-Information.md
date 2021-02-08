# Additional information related to Phase 1 challenge

## Challenge using Tinkercad

Phase 1 challenge might be a bit difficult to visualize in the Tinkercad environment, therefore, you can use the circuit bellow as a reference.

<img src = "https://user-images.githubusercontent.com/73468790/107127061-3e1a8d80-68bc-11eb-8194-c7246bc06c43.png" width = "700">

A few things to note:

* The two LEDs were connected for the visualization purposes. You could try to implement the code, so that when there is no obstacle in front of the "bot", the LEDs are turned on.
When there is an obstacle less than 30 cm away, turn LED off, and then after checking the distance, indicate at which side you are turning with the blinking LED
* Simulate the obstacle on the right or left by changing the distance from the virtual object.

### Code chunks

Although there are many possible ways in which you could construct you algorithm, you can use the following code examples as an inspiration (insert your own code instead of ___).

#### Function for measuring distance
```c
int measure()
{
  digitalWrite(___, LOW);
  delayMicroseconds(5);
  digitalWrite(___, HIGH);
  delayMicroseconds(10);
  digitalWrite(___, LOW);
  duration = pulseIn(___, HIGH);
  
  cm = (duration/2) / 29.1;
  
  return cm; 
}
```

#### Function for comparing left and right distance
```c
void compare()
{
  if (leftDistance < rightDistance)
  {
  	//turn right and turn on right LED
  }
  else
  {
  	//turn left and turn on left LED
  }
}
```
#### Function for controlling servo and checking distances from both sides

```c
void changePath()
{
  // Stop motors
  ___;
  // Turn servo at one side
  ___;
  rightDistance = ___;
  delay(1000);
  
  // Turn servos at other side
  ___;
  leftDistance = ___;
  delay(1000);
  
  //Compare distances
  ___;
}
```

### Useful functions for physical bot

#### Distance measuring using NewPing.h

```c
int readSensor()
{
  delay(70);   
  ___ = sonar.ping();
  ___ = uS/US_ROUNDTRIP_CM; //Converting distance to cm
  if (___ == 0)
  {
    ___ = 300; // Think why this is essential
  }
  return ___;
}
```

#### Motor control using AFMotor.h

```c
void turnRight()
{
  motor1.run(FORWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(BACKWARD);
  motor2.setSpeed(maxSpeed);
  delay(300);
}
```
