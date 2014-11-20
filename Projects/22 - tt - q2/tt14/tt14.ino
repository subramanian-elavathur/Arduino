void setup()
{
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

int but_stat = 0;

boolean refresh(){
   if(analogRead(A0)>500){
      but_stat = 1;
      return true; 
   }
   else{
      but_stat = 0;
      return false; 
   }
}

void loop_up(){
  for(int i=0; i<=255; i++){
     if(refresh()){reset();break;}
     analogWrite(3,i);
     analogWrite(5,i);
     analogWrite(6,i);
     analogWrite(9,i);
     analogWrite(10,i);
     analogWrite(11,i);
     delay(5);
  }
 
}

void loop_down(){
   for(int i=255; i>=0; i--){
     if(refresh()){reset();break;}
     analogWrite(3,i);
     analogWrite(5,i);
     analogWrite(6,i);
     analogWrite(9,i);
     analogWrite(10,i);
     analogWrite(11,i);
     delay(5);
  }
}

void reset(){
   digitalWrite(3,LOW);
   digitalWrite(6,LOW);
   digitalWrite(5,LOW);
   digitalWrite(9,LOW);
   digitalWrite(10,LOW);
   digitalWrite(11,LOW);
   refresh(); 
}

void loop()
{
 if(!refresh()){
     loop_up(); 
     delay(50);
     loop_down();
     delay(50);
  }
  else{}
}

