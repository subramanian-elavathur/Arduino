int gr = 11;
int rd = 12;
int ppts = A1;
int auds = A2;
int flexSensorPin = A0;
int x=0,ppt,aud,flex,bg1=0,bg2=0;


void setup(){
pinMode(gr,OUTPUT);
pinMode(rd,OUTPUT);
pinMode(ppts,INPUT);
pinMode(auds,INPUT);
Serial.begin(9600);
}

void scheck(){
    if(digitalRead(ppts)==1){ppt=1;}
    if(digitalRead(auds)==1){aud=1;}
    if(digitalRead(ppts)==0){ppt=0;}
    if(digitalRead(auds)==0){aud=0;}
}

void flexread(){
  int flexSensorReading = analogRead(flexSensorPin); 
  int flex = map(flexSensorReading, 280, 430, 0, 100);
  if(flex>50){digitalWrite(gr,LOW);
            digitalWrite(rd,HIGH); x=0;}
  if(flex<=50){digitalWrite(rd,LOW);
            digitalWrite(gr,HIGH); x=1;}
  }
  
  void pptrun(){    
    if(x==1&&bg1==1&&aud==0){Serial.println("#S|SENDK|[0&{DOWN}]#");delay(375);}
    if(x==1&&bg1==1&&aud==1){Serial.println("#S|SENDK|[0&{UP}]#");delay(375);} 
    if(x==1&&bg1==0){Serial.println("#S|ASD|[]#");bg1=1;delay(500);}
  }
  
  void audrun(){
    if(x==1&&bg2==1&&aud==0){Serial.println("#S|SENDK|[1&{DOWN}]#");delay(225);}
    if(x==1&&bg2==1&&aud==1){Serial.println("#S|SENDK|[1&{UP}]#");delay(225);}
    if(x==1&&bg2==0){Serial.println("#S|ASDF|[]#");bg2=1;delay(100);}
  }
  

void loop(){
  scheck();
  flexread();
    if(ppt==1){pptrun();}
    if(ppt==0){audrun();}
    delay(10);
  }

