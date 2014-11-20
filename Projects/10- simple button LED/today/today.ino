int switchPin = 8;
int ledPin = 12;
boolean currentButton = LOW;

void setup()
{
  pinMode(switchPin,INPUT);
  pinMode(ledPin,OUTPUT);
  }


void loop()
{
  currentButton = digitalRead(switchPin);
  digitalWrite(ledPin, currentButton);
  
}
