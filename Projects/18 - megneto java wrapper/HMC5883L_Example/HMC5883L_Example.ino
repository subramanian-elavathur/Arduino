
#include <Wire.h>
#include <HMC5883L.h>

HMC5883L compass;
int error = 0;
const int buttonPin = 4; 
int buttonState = 0; 
int led1 = 2;
int led2 = 3;


void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT); 
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT); 
  Wire.begin();
  compass = HMC5883L();
  error = compass.SetScale(1.3);
  if(error != 0);
    //Serial.println(compass.GetErrorText(error));
  error = compass.SetMeasurementMode(Measurement_Continuous);
  if(error != 0);
    //Serial.println(compass.GetErrorText(error));
}

void loop()
{
  buttonState = digitalRead(buttonPin);
   
  MagnetometerScaled scaled = compass.ReadScaledAxis();
  
  float heading = atan2(scaled.YAxis, scaled.XAxis);  
 
  float declinationAngle = 0.0457;
  heading += declinationAngle;
  
  if(heading < 0)
    heading += 2*PI;
    
  if(heading > 2*PI)
    heading -= 2*PI;
   
  float headingDegrees = heading * 180/M_PI; 

  Output(buttonState,headingDegrees);

}

void Output(int bs,float hd)
{
  if(bs==HIGH)
   {
     Serial.print("{\"status\":\"on\", ");
     digitalWrite(led1,HIGH);
     digitalWrite(led2,HIGH);  
  }
  else{
     Serial.print("{\"status\":\"off\", ");
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);  
     }
     Serial.print("\"h\":\"");
     Serial.print(hd);
     Serial.println("\"}");
}
