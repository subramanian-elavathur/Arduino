int i = 0;
int x = 250;
int y = 180;
int z = 100;
int w = 50;
int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int ledPin4 = 13;
int ledLevel1 = 200;
int ledLevel2 = 150;
int ledLevel3 = 100;
int ledLevel4 = 50;

void setup()
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
}


void loop()
{
   for(i=0;i<=10000;i++){  
      if(x>=0 && x<255){
      ledLevel1 = ledLevel1 + 1;
      x = x+1;
      analogWrite(ledPin1, ledLevel1); delay(1);}
      
      if(y>=0 && y<255){
      ledLevel2 = ledLevel2 + 1;
      y = y+1;
      analogWrite(ledPin2, ledLevel2); delay(1);}
      
      if(z>=0 && z<255){
      ledLevel3 = ledLevel3 + 1;
      z = z+1;
      analogWrite(ledPin3, ledLevel3); delay(1);}
      
      if(w>=0 && w<255){
      ledLevel4 = ledLevel4 + 1;
      w = w+1;
      analogWrite(ledPin4, ledLevel4); delay(1);}
      
      
      
      
      
      
      if(x>=255){
      ledLevel1 = ledLevel1 - 1;
      x=x+1;
      analogWrite(ledPin1, ledLevel1);
      delay(1);
      if(ledLevel1==0){x=0;}}
      
      if(y>=255){
      ledLevel2 = ledLevel2 - 1;
      y=y+1;
      analogWrite(ledPin2, ledLevel2);
      delay(1);
      if(ledLevel2==0){y=0;}}
      
      if(z>=255){
      ledLevel3 = ledLevel3 - 1;
      z=z+1;
      analogWrite(ledPin3, ledLevel3);
      delay(1);
      if(ledLevel3==0){z=0;}}
      
      if(w>=255){
      ledLevel4 = ledLevel4 - 1;
      w=w+1;
      analogWrite(ledPin4, ledLevel4);
      delay(10);
      if(ledLevel4==0){w=0;}}
   
 
 
}}
