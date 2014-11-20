void setup()
{
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void lightup(int x){
   digitalWrite(x,HIGH);
  digitalWrite(x+1,HIGH); 
  digitalWrite(x-1,LOW);
  digitalWrite(x-2,LOW); 
  
  if(x == 6){    
  digitalWrite(12,LOW);
  digitalWrite(13,LOW); 
  }
  int y = analogRead(A0);
  if(y<300){reset();}
  delay(1500);
}

void reset(){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    
    /*case 0: lightup(6);break;
        case 1: lightup(8);break;
        case 2: lightup(10);break;
        case 3: lightup(12);break;*/
}

void loop()
{
    reset();
    int x = analogRead(A0);
    Serial.print(x);
    Serial.print("\n");
    int j=0;
    for(;;){
      for(int i=6; i<=13; i++){
         analogWrite(i,j);       
      }    
      j++;
    }
}

