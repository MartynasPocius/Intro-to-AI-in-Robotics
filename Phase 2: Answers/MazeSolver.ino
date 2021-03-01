#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

#define echoPin A5
#define trigPin A4
#define sensorA 2
#define sensorB 13

#define maxDistance 350
#define maxSpeed 140

NewPing sonar(trigPin, echoPin, maxDistance);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

Servo myservo;

const int distMin = 7;
const int distMax = 17;

int stateA, stateB;
int dist = 0;

void setup()
{
  myservo.attach(10);
  myservo.write(180);
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);

  Serial.begin(9600);
  
}

void loop()
{
  stateA = digitalRead(sensorA); //Left
  stateB = digitalRead(sensorB); //Right
  dist = readSensor();

  if(stateA == HIGH || stateB == HIGH)
  {
    if(dist > distMin && dist < distMax)
    {
      moveForward();
    }
    if(dist < distMin && dist > 0)
    {
      moveRight();
      delay(30);
      moveForward();
    }
    if(dist>=distMax)
    {
      moveLeft();
      delay(30);
      moveForward();
    }
  }
  if (stateA == LOW && stateB == LOW) // obstacle
  {
    moveStop();
    delay(300);
    moveRight();
    delay(300);
  }

  Serial.println(dist);
}
int readSensor()
{
  delay(70);   
  unsigned int uS = sonar.ping();
  int cm = uS/US_ROUNDTRIP_CM;
  if (cm == 0)
  {
    cm = 300;
  }
  return cm;
}
void moveStop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
void moveForward()
{
  motor1.run(FORWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(FORWARD);
  motor2.setSpeed(maxSpeed-10);
  delay(30);
}
void moveRight()
{
  motor1.run(FORWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(BACKWARD);
  motor2.setSpeed(maxSpeed);
  delay(30);
}
void moveLeft()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(FORWARD);
  motor2.setSpeed(maxSpeed);
  delay(30);
}
