#include <AFMotor.h>
#include <Servo.h>

#define sensorA 2
#define sensorB 13
#define maxSpeed 130

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int stateA, stateB;

void setup()
{
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
}

void loop()
{
  stateA = digitalRead(sensorA); //left
  stateB = digitalRead(sensorB); //right

  if(stateA == HIGH && stateB == HIGH) // black line
  {
    moveStop();
  }
  else if(stateA == LOW && stateB == LOW) // Not on the black line
  {
    moveForward();
  }
  else if(stateA == LOW && stateB == HIGH) // Line on the right
  {
    moveRight();
    delay(100);
  }
  else if(stateA == HIGH && stateB == LOW)
  {
    moveLeft();
    delay(100);
  }
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
  motor2.setSpeed(maxSpeed);
}
void moveRight()
{
  motor1.run(FORWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(BACKWARD);
  motor2.setSpeed(maxSpeed);
}
void moveLeft()
{
  motor1.run(BACKWARD);
  motor1.setSpeed(maxSpeed);
  motor2.run(FORWARD);
  motor2.setSpeed(maxSpeed);
}
