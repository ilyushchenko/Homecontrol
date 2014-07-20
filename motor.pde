int lookup[8] = {
B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

void setup(){
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop(){
  for(int i=0; i<=512; i++) unStepMotor(8,7,4,2,0);
  delay(1000);
  for(int j=0; j<=512; j++) unStepMotor(2,4,7,8,0);
  delay(1000);
}

void unStepMotor(int pin_1, int pin_2,int pin_3,int pin_4,int speedMotor){
  for(int i = 0; i <= 7; i++) {
    digitalWrite(pin_1,bitRead(lookup[i], 0));
    digitalWrite(pin_2,bitRead(lookup[i], 1));
    digitalWrite(pin_3,bitRead(lookup[i], 2));
    digitalWrite(pin_4,bitRead(lookup[i], 3));
    delay(speedMotor + 1);
  }
}