int motorPin1     = 8;        // Pin мотора 1
int motorPin2     = 7;        // Pin мотора 2
int motorPin3     = 4;        // Pin мотора 3
int motorPin4     = 2;        // Pin мотора 4
int relay1        = 9;       // Реле1
int relay2        = 10;        // Реле2
int ButPin        = 11;       // Подключаем кнопку к выходу 10
int count         = 0;        // Количество секунд
int delay_count   = 0;        // Счетчик адержки
int lightValue    = 0;        // Начальное значение света
int curtainValue  = 0;        // Начальное значение занавески
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};


/*------------------------------------ Установка и настройка ------------------------------------*/
void setup(){ 
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);  
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  pinMode(ButPin, INPUT);
  Serial.begin(9600);
}

/*------------------------------------ Основной цикл --------------------------------------------*/
void loop() {
  if (digitalRead(ButPin) == HIGH){svitchRelayLight ();}
  check();
}

/*------------------------------------ Реле -----------------------------------------------------*/
void svitchRelayLight () {
  count = 0;
  delay_count = 0;
  while(delay_count < 100) {
    if (digitalRead(ButPin) == HIGH)
    {
      count++;
      Serial.print("Counter: "); Serial.print(count); Serial.println("************");
    } else {
      delay_count++;
      Serial.print("Timeout: "); Serial.println(delay_count);
    }
  }
  Serial.println("Done!");
  action(count);
}

void action(int count) {
  if (count <= 50)
  {
    lightValue = !lightValue;
    Serial.println("Invert Ligth Value");
  }else{
    Serial.println("Invert Zanaveska Value");
    curtain();
    
  }
}

/*------------------------------------ Проверка состояния -------------------------------------------*/
void check() {
  if (lightValue)
  {
    digitalWrite(relay1, HIGH);
  } else {
    digitalWrite(relay1, LOW);
  }
}

/*------------------------------------ Шторы ---------------------------------------------------------*/
void curtain() {
  if (curtainValue)
  {
    for(int i=0; i<=512; i++) { unStepMotor(motorPin1, motorPin2, motorPin3, motorPin4, 0); } 
  } else { for(int i=0; i<=512; i++) { unStepMotor(motorPin4, motorPin3, motorPin2, motorPin1, 0); }}
  delay(1000);
  curtainValue = !curtainValue;
}


void unStepMotor(int pin_1, int pin_2, int pin_3, int pin_4, int speedMotor){
  for(int i = 0; i <= 7; i++) {
    digitalWrite(pin_1, bitRead(lookup[i], 0));
    digitalWrite(pin_2, bitRead(lookup[i], 1));
    digitalWrite(pin_3, bitRead(lookup[i], 2));
    digitalWrite(pin_4, bitRead(lookup[i], 3));
    delay(speedMotor + 1);
  }
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);

}