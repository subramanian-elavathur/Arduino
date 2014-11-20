int i,a,b,c,d,f,g;
long int j=1;
int s1=1;
int s2=2;
int s3=3;
int s4=4;
int s5=5;
int s6=6;
int s7=7;

int p=40.355,in=0,di=0,er=40,e=0,ep=40,ei=40,ed=40;
void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);
 pinMode(s1,INPUT);
 pinMode(s2,INPUT);
 pinMode(s3,INPUT);
 pinMode(s4,INPUT);
 pinMode(s5,INPUT);
 pinMode(s6,INPUT);
 pinMode(s7,INPUT);
}
void loop()
{
  j=1;
  int l=200,r=200;
  a=digitalRead(s1);
  b=digitalRead(s2);
  c=digitalRead(s3);
  d=digitalRead(s4);
  e=digitalRead(s5);
  f=digitalRead(s6);
  g=digitalRead(s7);
  int x[]={a,b,c,d,e,f,g };
  for(i=0;i<=6;i++)
  {
    j=j*10+x[i];  
  }
  if(a==0&&f==0)
  {
    digitalWrite(13,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
  }
  else
  {
  switch (j)
  {
  case 11100011:
    e=0;
    break;
  case 11100001:
    e=1;
    break;
  case 11110001:
    e=2;
    break;
  case 11111000:
    e=3;
    break;
  case 11111100:
    e=4;
    break; 
  case 11111110:
    e=5;
    break;
  case 11111111:
    e=6;
    break;  
  case 11000111:
    e=-1;
    break;
  case 10001111:
    e=-2;
    break;
  case 10011111:
    e=-3;
    break;
  case 10111111:
    e=-4;
    break;
  case 111111111:
    e=-5;
    break;
  case 10000111:
    e=-6;
    break;
    default:
    e=ep;
    break;
 
  } 

  ei=ei+e;
  ed=(e-ep);
  er=e*p+ei*in+ep*di;
  ep=e;
  Serial.println(er);

 
  if(er>0)
  {
    l=l+er;
    r=r-er;
  }
  else if(er<0)
  {
    r=r-er;
    l=l+er;
  }
  if(r>250)
  r=250;
  if(l>250)
  l=250;
  
  switch(e)
  {
  case 0:
    analogWrite(13,150);
    analogWrite(10,150);
    break;
  case 1:
  case 2:
  case 3:
  case 4:
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    analogWrite(13,l);
    analogWrite(10,r);
    break;
  case 5:
  case 6:
    digitalWrite(9,HIGH);
    digitalWrite(11,LOW);
    analogWrite(13,l);
    analogWrite(10,r);
    break;
  case -1:
  case -2:
  case -3:
  case -4:
    digitalWrite(9,LOW);
    digitalWrite(11,LOW);
    analogWrite(13,l);
    analogWrite(10,r);
    break;
  case -5:
  case -6:
    digitalWrite(9,LOW);
    digitalWrite(11,HIGH);
    analogWrite(13,l);
    analogWrite(10,r);
 
  }
  Serial.print("r=");
Serial.println(r);
 Serial.println(l);
}


}







