int s1=1;
int s2=2;
int s3=3;
int s4=4;
int s5=5;
int s6=6;
int s7=7;
void setup(){
  Serial.begin(9600);
 pinMode(s1,INPUT);
 pinMode(s2,INPUT);
 pinMode(s3,INPUT);
 pinMode(s4,INPUT);
 pinMode(s5,INPUT);
 pinMode(s6,INPUT);
 pinMode(s7,INPUT);
}
void loop(){
 Serial.print(digitalRead(s1));
 Serial.print(digitalRead(s2));
 Serial.print(digitalRead(s3)); 
 Serial.print(digitalRead(s4)); 
 Serial.print(digitalRead(s5)); 
 Serial.print(digitalRead(s6)); 
 Serial.print(digitalRead(s7)); 
 Serial.print("\n");
 }
