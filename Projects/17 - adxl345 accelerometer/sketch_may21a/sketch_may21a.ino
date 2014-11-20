#include <ADXL345.h>

#include <Wire.h>


ADXL345 accel;

int statusPin = 2;

void setup(){
  Serial.begin(8600);
  Wire.begin();
  pinMode(statusPin,OUTPUT);
  accel=ADXL345();
  if(accel.EnsureConnected())
  {
    Serial.println("connected to adxl345");
    digitalWrite(statusPin,HIGH);
  }
  else
  { 
    Serial.println("I am Dead");
    digitalWrite(statusPin, LOW);
  }
}

void loop(){}

