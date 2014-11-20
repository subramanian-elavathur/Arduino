int i = 0;
int x = 0;
int y = 1;


int ledPin1 = 11;
int ledPin2 = 10;
int ledPin3 = 9;
int ledPin4 = 6;
int ledLevel = 0;

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
     ledLevel = ledLevel + 1;
     x = x+1;
     
   if(y==1)analogWrite(ledPin1, ledLevel);
   if(y==2)analogWrite(ledPin2, ledLevel);
   if(y==3)analogWrite(ledPin3, ledLevel);
   if(y==4)analogWrite(ledPin4, ledLevel);
   delay(1);}
       if(x>=255){
       ledLevel = ledLevel - 1;
       x=x+1;
       if(y==1)analogWrite(ledPin1, ledLevel);
   if(y==2)analogWrite(ledPin2, ledLevel);
   if(y==3)analogWrite(ledPin3, ledLevel);
   if(y==4)analogWrite(ledPin4, ledLevel);
      
       if(ledLevel==0){
       x=0;
       y=y+1;
       if(y>4){y=1;}
       }
       }
   }
  
  
   
  
}
