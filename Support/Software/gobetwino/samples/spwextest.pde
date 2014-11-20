int serInLen = 25;
char serInString[25];
int pId =0;
int analogValue=0;
int result;

void setup() 
{ 
  Serial.begin(9600); 
  Serial.println("#S|BACKUP|[]#");
  readSerialString(serInString,3000);
  delay(4000);

} 
 
void loop() 
{ 

} 




//read a string from the serial and store it in an array
//you must supply the array variable - return if timeOut ms passes before the sting is read
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
