#include "DHT.h"
#define DHTPIN 15
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(16,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(18,OUTPUT);
  dht.begin();
}

void loop() 
{
  int a=analogRead(13);
  Serial.println("The LDR value is ");
  Serial.println(a);
   if(a>=3000)
  {
    digitalWrite(16,HIGH);
  delay(1000);
  }
  else
  {
    digitalWrite(16,LOW);
  delay(1000);
  }
 
  delay(2000);
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) 
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.println(F("%"));
  Serial.print(F("Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  Serial.print(F("Temperature: "));
  Serial.print(f);
  Serial.println(F("°F"));
  if(t>=35)
  {
    digitalWrite(17,LOW);
    Serial.println("The fan is ON");
  }
  else
  {
    digitalWrite(17,HIGH);
    Serial.println("The fan is OFF");
  }
  delay(1000);
  Serial.print(F("Heat index: "));
  Serial.print(hic);
  Serial.println(F("°C "));
  Serial.print(F("Heat index: "));
  Serial.print(hif);
  Serial.println(F("°F"));
  
  if(hic>=35)
  {
    digitalWrite(18,LOW);
    Serial.println("The fan is ON");
  }
  else
  {
    digitalWrite(18,HIGH);
    Serial.println("The fan is OFF");
  }
  delay(1000);
}
  
