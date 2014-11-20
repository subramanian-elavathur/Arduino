#include <Servo.h> 
int A = 8;
int B = 9;
int C = 2;
int D = 3;
int E = 4;
int F = 5;
int G = 6;
Servo myservo; 
int pos = 0;
int pin = 7;
boolean pinc = HIGH;
int pins = 13;
boolean pinsc = HIGH;
int green = 10;
int red = 11;
int blue = 12;
int x=0;
int y[4]={6,1,9,3};
int z=0;
int b;

void clr()
{
  //Clears the LED
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);

}


void one()
{
  //Displays 1
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void two()
{
  //Displays 2
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}

void three()
{
  //Displays 3
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void four()
{
  //Displays 4
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void five()
{
  //Displays 5
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void six()
{
  //Displays 6
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}

void seven()
{
  //Displays 7
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void eight()
{
  //Displays 8
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void nine()
{
  //Displays 9
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void zero()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void hc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}

void ac()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void pc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
}
void yc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void bc()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void ic()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void rc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void tc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void dc()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void nc()
{
  //Displays 0
  digitalWrite(D, LOW);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}
void kc()
{
  //Displays 0
  hc();
}
void uc()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
}
void ec()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
}
void vc()
{
  //Displays 0
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
}


void setup()
{
  //Setup our pins
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(pin, INPUT);
  pinMode(pins, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  myservo.attach(1);
}

void leddisp(){
 hc();
  delay(1000);
  clr();
  delay(1000);
  ac();
  delay(1000);
  clr();
  delay(1000);
  pc();
  delay(1000);
  clr();
  delay(1000);
  pc();
  delay(1000);
  clr();
  delay(1000);
  yc();
  delay(1000);
  clr();
  delay(1000);
  bc();
  delay(1000);
  clr();
  delay(1000);
  ic();
  delay(1000);
  clr();
  delay(1000);
  rc();
  delay(1000);
  clr();
  delay(1000);
  tc();
  delay(1000);
  clr();
  delay(1000);
  hc();
  delay(1000);
  clr();
  delay(1000);
 dc();
  delay(1000);
  clr();
  delay(1000); 
 ac();
  delay(1000);
  clr();
  delay(1000); 
 yc();
  delay(1000);
  clr();
  delay(1000); 
 ac();
  delay(1000);
  clr();
  delay(1000); 
 nc();
  delay(1000);
  clr();
  delay(1000); 
 kc();
  delay(1000);
  clr();
  delay(1000); 
 uc();
  delay(1000);
  clr();
  delay(1000); 
 rc();
  delay(1000);
  clr();
  delay(1000); 
 dc();
  delay(1000);
  clr();
  delay(1000); 
 ec();
  delay(1000);
  clr();
  delay(1000); 
 vc();
  delay(1000);
  clr();
  delay(1000);  
}

void loop()
{
  
  myservo.write(pos);
  pinc = digitalRead(pin);
  if(pinc==LOW){
  x=x+1;
  if(x>9)x=0;  
  }
  delay(150);  
  switch(x){
  case 0:zero();break;delay(2000);
  case 1:one();break;delay(2000);
  case 2:two();break;delay(2000);
  case 3:three();break;delay(2000);
  case 4:four();break;delay(2000);
  case 5:five();break;delay(2000);
  case 6:six();break;delay(2000);
  case 7:seven();break;delay(2000);
  case 8:eight();break;delay(2000);
  case 9:nine();break;delay(2000);
  }
  pinsc = digitalRead(pins);
  if(pinsc==LOW){
  if(x==y[z]){digitalWrite(green,HIGH);digitalWrite(red,LOW);z=z+1;delay(1000);digitalWrite(green,LOW);if(z==4){for(b=0;b<=50;b++){digitalWrite(blue,HIGH);delay(20);
  digitalWrite(blue,LOW);delay(20);}for(pos = 0; pos < 180; pos += 1){myservo.write(pos);delay(3);}for(b=0;b<=75;b++){digitalWrite(blue,HIGH);delay(20);digitalWrite(blue,LOW);
  delay(20);}for(pos = 180; pos>=1; pos-=1){myservo.write(pos); delay(3);}z=0;leddisp();}}
  else{digitalWrite(green,LOW);digitalWrite(red,HIGH);z=0;delay(1000);digitalWrite(red,LOW);}
  }
  
}

