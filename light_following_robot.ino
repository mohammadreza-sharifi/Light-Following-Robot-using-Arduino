//**define ldr pins**//
int middle_ldr = 4;
int right_ldr = 5;
int left_ldr = 6;
//////////////////////

boolean light1;//digital value from middle ldr
boolean light2;//digital value from right ldr
boolean light3;//digital value from left ldr

//**define driver pins**//
int ENA = A0;
int ENB = A1;

int IN1 = 9;
int IN2 = 10;
int IN3 = 11;
int IN4 = 12;
//////////////////////////
int mspeed1 = 0;
int mspeed2 = 0;



void setup() {
//set pinmode for ldr pins
pinMode(right_ldr,INPUT);
pinMode(middle_ldr,INPUT);
pinMode(left_ldr,INPUT);

//set pinmode for driver pins
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

}

void loop() {
  light1 = digitalRead(middle_ldr);
  light2 = digitalRead(right_ldr);
  light3 = digitalRead(left_ldr);

  if(light1 == LOW && light2 == HIGH && light3 == HIGH){
    forward();
  }
  else if(light1 == HIGH && light2 == LOW && light3 == HIGH){
    right();
  }
  else if(light1 == HIGH && light2 == HIGH && light3 == LOW){
    left();
  }
  else{
    stopfcn();
  }

}


void forward(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  mspeed1 = 200;
  mspeed2 = 200;
  analogWrite(ENA,mspeed1);
  analogWrite(ENB,mspeed2);
}

void right(){
  digitalWrite(IN1,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  mspeed1 = 100;
  mspeed2 = 0;
  analogWrite(ENA,mspeed1);
  analogWrite(ENB,mspeed2);
}

void left(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  mspeed1 = 0;
  mspeed2 = 100;
  analogWrite(ENA,mspeed1);
  analogWrite(ENB,mspeed2);
}

void stopfcn(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN4,LOW);
  mspeed1 = 0;
  mspeed2 = 0;
  analogWrite(ENA,mspeed1);
  analogWrite(ENB,mspeed2);
}
