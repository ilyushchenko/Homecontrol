/*------------------------------------ Шторы ---------------------------------------------------------*/
void curtain() {
  if (curtainValue)
  {
    for(int i=0; i<=openCloseValue; i++) {
      int x = i % 64;
      if(!x){
        lcd.clear();
        lcd.print("Progress:");
        lcd.print(i/openCloseValue*100);
        lcd.print("%");
      }
      Motor(motorPin1, motorPin2, motorPin3, motorPin4, 0);
    }
  } else { 
    for(int i=0; i<=openCloseValue; i++) {
      int x = i % 64;
      if(!x){
        lcd.clear();
        lcd.print("Progress:");
        lcd.print(i/openCloseValue*100);
        lcd.print("%");
      }
      Motor(motorPin4, motorPin3, motorPin2, motorPin1, 0); 
    }
  }
  delay(1000);
  curtainValue = !curtainValue;
  displayStat();

}

void Motor(int pin_1, int pin_2, int pin_3, int pin_4, int speedMotor){
  for(int j = 0; j <= 7; j++) {
    digitalWrite(pin_1, bitRead(lookup[j], 0));
    digitalWrite(pin_2, bitRead(lookup[j], 1));
    digitalWrite(pin_3, bitRead(lookup[j], 2));
    digitalWrite(pin_4, bitRead(lookup[j], 3));
    delay(speedMotor + 1);
  }
}
void motorClear () {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  lightDisplay(0);
}