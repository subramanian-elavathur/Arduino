int serInLen = 25;
char serInString[25];
int pId =0;
int result;

void setup() 
{ 
  Serial.begin(9600); 
  Serial.println("#S|SPXL|[]#");        // start EXCEL
  readSerialString(serInString, 5000);  // wait  5  seconds (max) for answer from Gobetwino (=porcess ID)
  pId= atoi(serInString);               // convert result to integer 
  sendPotValues();                       // send some data to Excell
} 
 
void loop() 
{ 
   //analogValue= random(0,1023);
   //logData(analogValue);
   //delay(5000); 
} 

void sendPotValues() 
{
   char buffer[5];
   int potValue1;
   int potValue2;
   
   for (int i=1; i<=15; i++){
     //Read the two pot values - could be any sensor value or whatever
     potValue1=analogRead(1);
     potValue2=analogRead(2);
  
    //Send the values as though it was typed into Excell, using the SENDK command
    // This is the total line that is send: #S,SENDK,[pId; potValue1 {TAB} potValue2 {DOWN} {LEFT} ]#
     Serial.print("#S|SENDK|[");
     Serial.print(itoa((pId), buffer, 10));
     Serial.print("&");
     Serial.print(itoa((potValue1), buffer, 10));
     Serial.print(" {TAB} ");
     Serial.print(itoa((potValue2), buffer, 10));
     Serial.print(" {DOWN} ");
     Serial.print(" {LEFT} ");
     Serial.println("]#");
     // wait up to 1000 ms for answer from Gobetwino, answer will be in serInString, answer is 0 if all is OK
     readSerialString(serInString, 1000);
     //Deal with answer here - omitted in this example
     delay(2000);
  }    
  // Now we have sent the 2 pot values 15 times, so save and close the XL sheet.
 Serial.print("#S|SENDK|[");
 Serial.print(itoa((pId), buffer, 10));
 Serial.print("& ");
 Serial.print("%Fg%Fa");  //=   ALT f   ALT g  = save and exit in danish Excell
 Serial.println("]#");
 // Wait 2 seconds for the save to finish
 delay(2000);
 // wait up to 1000 ms for answer from Gobetwino, answer will be in serInString, answer is 0 if all is OK
 readSerialString(serInString, 1000);
 // Next e-mail the XL sheet to someone
 Serial.println("#S|MXL|[]#");
 // wait up to 1000 ms for answer from Gobetwino, answer will be in serInString, answer is 0 if all is OK
 readSerialString(serInString, 1000);
} 

//read a string from the serial and store it in an array
//you must supply the array variable - will return if timeOut ms passes before the sting is read so you should
//check the contents of the char array before making any assumptions.
void readSerialString (char *strArray,long timeOut) 
{
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

