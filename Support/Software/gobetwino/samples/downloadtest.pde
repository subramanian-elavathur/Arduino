int serInLen=25;
int ledPin = 13;                // LED connected to digital pin 13
char serInString[25];
bool fileOk=false;

void setup()                    // run once, when the sketch starts
{
  pinMode(ledPin, OUTPUT);  // sets the digital pin as output
  Serial.begin(9600);
  delay(3000);
  
   // Ask Gobetwino to run the PNG PING commando to check that the web server is responding before downloading a file
  Serial.println("#S|PNG|[]#");       
  // Wait for the answer from Gobetwino  
  readSerialString (serInString, 10000);  
  // check return code from DLFIL command from Gobetwino, if it is 0 the the server responded to the ping
  if (serInString[0]=='0')  {            
    // Ask Gobetwino to run the DLBLINK command - downloading a file
    Serial.println("#S|DLBLINK|[]#");       
    // Wait for the answer from Gobetwino  
    readSerialString (serInString, 10000);  
     // check return code from DLFIL command from Gobetwino, if it is 0 the file is downloaded
    if (serInString[0]=='0')  {            
       fileOk=true;
    } 
  }
}

void loop()     // run over and over again
  
{
  char buffer[5];
  int nrOfBlinks=0;
  int lineNr=0;
  // If the file was downloaded, Send the RDBLINK command asking Gobetwino to read line nr. 1 - 3 from 
  // the file and blink LED the number of times read from each line
   if (fileOk) {
     for(lineNr=1;lineNr<=3;lineNr++) {
      Serial.print("#S|RDBLINK|[");
      Serial.print(itoa((lineNr), buffer, 10));
      Serial.println("]#");
      // Wait for answer from Gobetwino and convert the returned answer to an integer, and call the blink function
      // An error check for a negative return code should be done here, but is ommited to keep the example as simple as posible
      readSerialString (serInString, 10000);
      nrOfBlinks=atoi(serInString);
      blink (nrOfBlinks); 
      delay(5000);
    }
  }
}

void blink(int times) {
  // Blink the LED on pin 13 the number of times indicated by the times parameter
  int x;
  for(x= 1; x<=times; x++) {
    digitalWrite(ledPin, HIGH);   
    delay(200);                  
    digitalWrite(ledPin, LOW);    
    delay(200);                   
  }
}

void readSerialString (char *strArray,long timeOut) {
  // Wait up to timeOut miliseconds for data to arrive at the serial port, then read the data and put it in the char array strArray
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
