int i,j,k;
long int value=1;
int e;
int ep=0,ed,ei;
int switchm;
int c,kd=0,ki=0,kp=10;
void setup()
{
  Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(3,INPUT); 
 pinMode(4,INPUT);
 pinMode(5,INPUT);
 pinMode(6,INPUT); 
 pinMode(7,INPUT);
 pinMode(8,INPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT); 
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
}

void getvalue()
{
  int array[7];
  value=1;
  for(i=2;i<9;i++)
  {
   array[i]=digitalRead(i);
   value=(value*10)+array[i];
  }
  Serial.println(value);
 
}
void cases()
 {
   
  switch(value)
   {
     case 11100011:
     e=0;
     break;
     case 11100111:
     e=1;
     break; 
     case 11000111:
     e=2;
     break;
     case 11001111:
     e=3;
     break;
     case 10001111:
     e=4;
     break;
     case 10011111:
     e=5;
     break;
     case 10111111:
     e=6;
     break;
     case 11110011:
     e=-1;
     break; 
     case 11110001:
     e=-2;
     break;
     case 11111001:
     e=-3;
     break;
     case 11111000:
     e=-4;
     break;
     case 11111100:
     e=-5;
     break;
     case 11111110:
     e=-6;
     default:
      e = ep; 
   }
 }
 
 void pid()
 {
   ed = e - ep;
   ei = ei + e;
   ep = e;
   
   c = kp*ep + kd*ed + ki*ei;
   
   if(c>255)
   {
     c = 255;
   }
   if(c<-255)
   {
     c= -255;
   }
   
 }
 
 void forward()
 {
   digitalWrite(12,LOW);
   digitalWrite(9,HIGH);
   digitalWrite(10,HIGH);
   digitalWrite(11,HIGH);
 }
 
 /*void left()
 {
   digitalWrite(9,HIGH);
   digitalWrite(7,LOW);
   digitalWrite(6,LOW);
   digitalWrite(5,LOW);
 }
  void right()
 {
   digitalWrite(9,LOW);
   digitalWrite(7,LOW);
   digitalWrite(6,HIGH);
   digitalWrite(5,LOW);
 } 
 
  void backward()
 {
   digitalWrite(9,LOW);
   digitalWrite(7,HIGH);
   digitalWrite(6,LOW);
   digitalWrite(5,HIGH);
 } */
 
 
 
   
   
void loop()
{
  int l = 200;
  int r =200;
  getvalue();
  
  Serial.println(value);
  cases();
  pid();
  Serial.println(c);
  Serial.println(e);
  pid();
  //if(switchm==1);
  //{
  l = l - c;
  r = r + c;
  
  
  //}
  delay(100);
 
  
  
}
   
   
  
