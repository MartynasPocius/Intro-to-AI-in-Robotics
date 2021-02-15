#include <Servo.h>

//Left motor
#define speedMotorA 9
#define motorPin1 8
#define motorPin2 7
//Right motor
#define speedMotorB 3
#define motorPin3 5
#define motorPin4 4
//Defining ultrasonic sensor pins
#define trigPin A0
#define echoPin A1
//Defining servo pin
#define servoPin 2
//Defining LEDs for demonstration purposes
#define leftLED 13
#define rightLED 12

int maxSpeed = 160;
long duration, cm, distance;
Servo myservo; //Creating servo object
int collisionDistance = 30; //Minimum allowed distance from the object
int leftDistance, rightDistance; //Distance from the closest objects on the right and left

void setup()
{
  //Setting speed pins to output and changing their speed to maxSpeed
  pinMode(speedMotorA, OUTPUT);
  pinMode(speedMotorB, OUTPUT);
  digitalWrite(speedMotorA, maxSpeed);
  digitalWrite(speedMotorB, maxSpeed);
  //Setting all motor pins to output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  //Setting ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Setting LEDs to output
  pinMode(leftLED, OUTPUT);
  pinMode(rightLED, OUTPUT);
  //Making sure that the servo is at the initial position
  myservo.attach(servoPin); 
  myservo.write(90);
  delay(2000);
}

void loop()
{
  myservo.write(90);
  delay(100);
  distance = measure();
  if (distance<collisionDistance)
  {
    changePath();
  }
  forward();
  delay(100);
}

void changePath()
{
  stop();
  myservo.write(30);
  delay(2000);
  rightDistance = measure();
  delay(1000);
  myservo.write(150);
  delay(2000);
  leftDistance = measure();
  delay(1000);
  myservo.write(90);
  delay(100);
  compare();
}

void compare()
{
  if (leftDistance < rightDistance)
  {
    right();
    digitalWrite(rightLED, HIGH);
    delay(2000);
    digitalWrite(rightLED, LOW);
  }
  else
  {
    left();
    digitalWrite(leftLED, HIGH);
    delay(2000);
    digitalWrite(leftLED, LOW);
  }
}

void forward() //Function for going forward
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
}

void stop() //Function for stopping
{
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
}
void left() //Function for turning right
{
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  //These motors are reversed
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
}

void right() //Function for turning left
{
  //These motors are reversed
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW); 
}

int measure() //Function for measuring distance
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  
  cm = (duration/2) / 29.1;
  
  return cm; 
}
