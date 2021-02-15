#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>

#define trigPin A4
#define echoPin A5
#define maxDistance 350
#define maxSpeed 160
#define collisionDistance 30
NewPing sonar(trigPin, echoPin, maxDistance);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
Servo myservo;

int leftDistance, rightDistance;
int dist = 0;

void setup()
{
  myservo.attach(10);
  myservo.write(90);
  delay(1000);
  Serial.begin(9600);
}

void loop()
{
  myservo.write(90);
  delay(100);
  dist = readSensor();
  if(dist < collisionDistance)
  {
    changePath();
  }
  moveForward();
  delay(100);
}

void changePath()
{
  moveStop();
  myservo.write(30);
  delay(500);
  rightDistance = readSensor();
  delay(500);
  myservo.write(150);
  delay(700);
  leftDistance = readSensor();
  delay(500);
  myservo.write(90);
  delay(100);
  comparison();
}

void comparison()
{
  if (leftDistance < rightDistance)
  {
    turnRight();
  }
  else
  {
    turnLeft();
  }
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

//movement
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
  motor2.setSpeed(maxSpeed+10); //due to imbalance of motors
}

void turnLeft()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(FORWARD);
  motor2.setSpeed(maxSpeed);
  delay(300);
}

void turnRight()
{
  motor1.run(FORWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(BACKWARD);
  motor2.setSpeed(maxSpeed);
  delay(300);
}
