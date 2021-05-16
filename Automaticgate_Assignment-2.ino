#include<Servo.h>
int trig=8;
int echo=9;
int dt=1000;
Servo gate;



void setup() 
  {
  
	pinMode(trig,OUTPUT);
	pinMode(echo,INPUT);
	Serial.begin(9600);
	gate.attach(11);
	}

void loop()
{
  
 if (calc_dis()<100)
 {
 
  gate.write(90);
  Serial.println("The Gate is OPENED");
  delay(1000);
 
  } 

  else
   {
    gate.write(0);
    Serial.println("The Gate is closed");
    delay(1000);
   }
  
}

int calc_dis()
{
  int duration,distance;
  digitalWrite(trig,HIGH);
  delay(dt);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance = (duration/2) / 29.1;
  Serial.print("The vehicle is at: ");
  Serial.println(distance);
  delay(1000);
  return distance;
}
