#include <Wire.h>
#include <ADXL345.h>

ADXL325;

int ch1 = 0;
int ch2 = 0;
int ch3 = 0;
int ch4 = 0;
int ch5 = 0;
int ch6 = 0;
int ch7 = 0;
int ch8 =0;
int ch9 =0;
int ch10 =0;
int ch11 =0;
int ch12 =0;
int ch13 =0;
//ch for brain aci accelerometer
int acx=0;
int acy=0;
int acz=0;
//i here is the 3 axes output from the accelerometer

void setup(){
  
  pinMode(ch1,INPUT);
  pinMode(ch2,INPUT);
  pinMode(ch3,INPUT);
  pinMode(ch4,INPUT);
  pinMode(ch5,INPUT);
  pinMode(ch6,INPUT);
  pinMode(ch7,INPUT);
  pinMode(ch8,INPUT);
  pinMode(ch9,INPUT);
  pinMode(ch10,INPUT);
  pinMode(ch11,INPUT);
  pinMode(ch12,INPUT);
  pinMode(ch13,INPUT);
  Serial.begin(9600);
//initializing the I2C protol
Wire.begin();
Serial.print("I2C initialization sucess");
// constructing accelerometer instance - all 3 axes;
 ADXL345 = acc345();
 // no sensitivity check for G - default standard initialize
 Serial.println("Setting measurement mode to continous.");
  error = acc345.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(acc345.GetErrorText(error));
  
}


void loop(){
int i=1;
int z[12];
  for(i=0;i<13>i++){    // create the array to store 13 lead magnetic data from the Brain.
    char y = "ch"+i;
  int z[i-1] = analogRead(y);  
  }
 //get scaled data from acc345
 ADXL345Scaled scaled = compass.ReadScaledAxis();
 // export the brain wave sensor array to MATLAB to plot the graphs then begin calibration on the sensor.
 //add exportr library.
}
