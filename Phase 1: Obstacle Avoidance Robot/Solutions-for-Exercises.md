# Solutions for exercises

<The solutions are going to be released the week after the asynchronous material release>

## Exercise01: Tinkercad

```c
#define motorPin1 11
#define motorPin2 10
#define motorSpeedPin  9

int motorSpeed;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  while(Serial.available()>0){
  motorSpeed = Serial.parseInt();
  }
  analogWrite(motorSpeedPin, motorSpeed);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  
}
```

## Exercise01: Physical components

```c
#include <AFMotor.h>

int motorSpeed;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  while(Serial.available()>0){
    motorSpeed = Serial.parseInt();
  }
  motor1.run(FORWARD);
  motor1.setSpeed(motorSpeed);
  motor2.run(FORWARD);
  motor2.setSpeed(motorSpeed);
}
```

## Exercise02: Tinkercad

```c
#include <Servo.h> 
int servoPin = 9; 
Servo myservo;

void setup() { 
   myservo.attach(servoPin); 
   myservo.write(90);
   delay(2000);
}
void loop(){ 
   myservo.write(0); 
   delay(2000);
   myservo.write(180); 
   delay(2000);
   myservo.write(90); 
   delay(4000);
}
```

## Exercise02: Physical components

<Same code, but provide an explanation>

## Exercise03: Tinkercad

```c
//Defining motor
#define motorPin1 11
#define motorPin2 10
#define motorSpeedPin  9

//Defining ultrasonic sensor
#define trigPin 2
#define echoPin 7

int motorSpeed;
long duration, cm, distance;

void setup()
{
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
  digitalWrite(motorSpeedPin, HIGH);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop()
{
  distance = measure();
  if (distance<50)
  {
    digitalWrite(motorPin1, LOW);
  	digitalWrite(motorPin2, LOW);
  }
  else
  {
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
  }
}

//Function for measuring distance
int measure()
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
```
