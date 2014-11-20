int i,j,k;
long int value=1;
int e;
int ep,ed,ei;
int switchm;
int c,kd,ki,kp;
void setup()
{
  Serial.begin(9600);
 pinMode(2,INPUT);
 pinMode(3,INPUT); 
 pinMode(4,INPUT);
 pinMode(5,INPUT);
 pinMode(6,INPUT); 
 pinMode(7,INPUT);
 //pinMode(8,INPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT); 
 pinMode(11,OUTPUT);
 pinMode(8,OUTPUT);
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
 
}
void cases()
 {
   
  switch(value)
   {
     case 10001000:
     e=0;
     break;
    case 10001100:
     e=1;
     break; 
     case 10000100:
     e=2;
     break;
     case 10000110:
     e=3;
     break;
     case 10000010:
     e=4;
     break;
     case 10000011:
     e=5;
     break;
     case 10000001:
     e=6;
     break;
     case 10000111:
     e=7;
     break;
     case 10001111:
     e=8;
     break;
     case 10011000:
     e=-1;
     break; 
     case 10010000:
     e=-2;
     break;
     case 10110000:
     e=-3;
     break;
     case 10100000:
     e=-4;
     break;
     case 11100000:
     e=-5;
     break;
     case 11000000:
     e=-6;
     break;
     case 11110000:
     e=-7;
     break;
     case 11111000:
     e=-8;
     break;
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
   digitalWrite(8,LOW);
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
  Serial.println(c);
  pid();
  if(switchm==1);
  {
  l = l + c;
  r = r - c;
  
  analogWrite(9,l);
  analogWrite(10,LOW);
  analogWrite(11,r);
  analogWrite(8,LOW);
  }
  
 
  
  
}
   
   
  
