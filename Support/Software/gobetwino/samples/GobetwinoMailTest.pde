/*
 * Blink
 *
 * The basic Arduino example.  Turns on an LED on for one second,
 * then off for one second, and so on...  We use pin 13 because,
 * depending on your Arduino board, it has either a built-in LED
 * or a built-in resistor so that you need only an LED.
 *
 * http://www.arduino.cc/en/Tutorial/Blink
 */
int serInLen=25;
int ledPin = 13;                // LED connected to digital pin 13
char serInString[25];
void setup()                    // run once, when the sketch starts
{
  pinMode(ledPin, OUTPUT);  // sets the digital pin as output
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  readSerialString (serInString, 10000);
  if (serInString[0]=='b')  {
    serInString[0]=' ';
    blinkRed (); 
  }
}

void blinkRed() {
  int x;
  for(x= 1; x<=20; x++) {
    digitalWrite(ledPin, HIGH);   // sets the LED on
    delay(100);                  // waits for a second
    digitalWrite(ledPin, LOW);    // sets the LED off
    delay(100);                  // waits for a second  
  }
}
void readSerialString (char *strArray,long timeOut) {
   long startTime=millis();
   int i;

   while (!Serial.available()) {
      if (millis()-startTime >= timeOut) {
         return;
      }
   }
   while (Serial.available() && i < serInLen) {
      strArray[i] = Serial.read();
      i++;
   }
}
