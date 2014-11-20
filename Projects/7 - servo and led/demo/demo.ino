#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
int ledPin1=8;
int ledPin2=7;
int pos = 180;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(9);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);   
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);    // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(5);
    digitalWrite(ledPin2,HIGH);
    digitalWrite(ledPin1,LOW);    // waits 15ms for the servo to reach the position 
  } 
} 
