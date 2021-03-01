//16582903=1
//16615543=2
//16599223=3
//16591063=4
//16623703=5
//16607383=6
//16586983=7
//16619623=8
//16603303=9
//16580863=stop
//16593103=0

#include <IRremote.h>
#define motorPin1 11
#define motorPin2 10
#define motorSpeedPin  9
#define irPin 5


IRrecv irrecv(irPin);
decode_results results;
String motorSpeed;
int value;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(irPin, INPUT);
  
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorSpeedPin, OUTPUT);
}

void loop()
{
  for(int i=1; i<=3; i++)
  {
	if (irrecv.decode(&results))
  	{
   	  motorSpeed = String(converter())+motorSpeed;
      irrecv.resume(); 
  	}
  }
  Serial.println(motorSpeed.toInt());
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  analogWrite(motorSpeedPin, motorSpeed.toInt());
  if(results.value == 16580863)
  {
  	analogWrite(motorSpeedPin, 0);
    motorSpeed="";
  }
}
int converter()
{
  switch (results.value)
    {
   	  case 16582903:
      	value = 1;
      	break;
      case 16615543:
      	value = 2;
      	break;
      case 16599223:
      	value = 3;
      	break;
      case 16591063:
      	value = 4;
      	break;
      case 16623703:
      	value = 5;
        break;
      case 16607383:
      	value = 6;
      	break;
      case 16586983:
      	value = 7;
      	break;
      case 16619623:
      	value = 8;
      	break;
      case 16603303:
      	value = 9;
      	break;
      case 16593103:
      	value = 0;
      	break;
    }
}