int i = 0;
int x = 0;
int y = 1;


int ledPin1 = 2;
int ledPin2 = 3;
int ledPin3 = 4;
int ledPin4 = 5;
int ledPin5 = 6;
int ledPin6 = 7;
int ledPin7 = 8;
int ledPin8 = 9;
int ledPin9 = 10;
int incomingByte;



void setup()
{
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(ledPin4,OUTPUT);
  pinMode(ledPin5,OUTPUT);
  pinMode(ledPin6,OUTPUT);
  pinMode(ledPin7,OUTPUT);
  pinMode(ledPin8,OUTPUT);
  pinMode(ledPin9,OUTPUT);
  Serial.begin(9600);
  }

void off()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,LOW);
  digitalWrite(ledPin8,LOW);
  digitalWrite(ledPin9,LOW);
}

void one()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,LOW);
  digitalWrite(ledPin8,LOW);
  digitalWrite(ledPin9,HIGH);
}

void two()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}

void three()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}

void four()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,LOW);
  digitalWrite(ledPin9,HIGH);
}

void five()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,LOW);
}

void six()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,LOW);
  digitalWrite(ledPin8,LOW);
  digitalWrite(ledPin9,HIGH);
}
void seven()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,LOW);
  digitalWrite(ledPin4,LOW);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,LOW);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}
void eight()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}
void nine()
{
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2,LOW);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,HIGH);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}
void zero()
{
  digitalWrite(ledPin1,HIGH);
  digitalWrite(ledPin2,HIGH);
  digitalWrite(ledPin3,HIGH);
  digitalWrite(ledPin4,HIGH);
  digitalWrite(ledPin5,LOW);
  digitalWrite(ledPin6,HIGH);
  digitalWrite(ledPin7,HIGH);
  digitalWrite(ledPin8,HIGH);
  digitalWrite(ledPin9,HIGH);
}
void loop()
{
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    // if it's a capital H (ASCII 72), turn on the LED:
    if (incomingByte == 'H') {
      eight();
          }
    // if it's an L (ASCII 76) turn off the LED:
    if (incomingByte == 'L') {
      off();
    }
  } 
   /*zero();
   delay(10000);
   off();
   delay(1000);
   two();
   delay(1000);
   off();
   delay(1000);
   three();
   delay(1000);
   off();
   delay(1000);
   four();
   delay(1000);
   off();
   delay(1000);
   five();
   delay(1000);
   off();
   delay(1000);
   six();
   delay(1000);
   off();
   delay(1000);
   seven();
   delay(1000);
   off();
   delay(1000);
   eight();
   delay(1000);
   off();
   delay(1000);
   nine();
   delay(1000);
   off();
   delay(1000);
   zero();
   delay(1000);
   off();
   delay(1000);*/
         
}
