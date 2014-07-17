int motorPin1     = 1;        // Pin мотора 1
int motorPin2     = 2;        // Pin мотора 2
int motorPin3     = 3;        // Pin мотора 3
int motorPin4     = 4;        // Pin мотора 4
int relay1        = 8;        // Реле1
int relay2        = 9;        // Реле2
int ButPin        = 10;       // Подключаем кнопку к выходу 10
int LedPin        = 12;       // Подключаем светодиод к порту 13
int count         = 0;        // Количество секунд
int delay_count   = 0;        // Счетчик адержки
int lightValue    = 0;        // Начальное значение света
int testValue     = 0;        // Тестовое значение
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
  Serial.println("Start processing!");
  if (count <= 50)
  {
    lightValue = !lightValue;
    Serial.println("Invert Ligth Value");
  }else{
    testValue = !testValue;
    Serial.println("Invert Zanaveska Value");
  }
}

/*------------------------------------ Проверка состояния -------------------------------------------*/
void check() {
  if (lightValue)
  {
    digitalWrite(LedPin, HIGH);
    digitalWrite(relay1, LOW);
  } else {
    digitalWrite(LedPin, LOW);
    digitalWrite(relay1, HIGH);
  }

    if (testValue)
  {
    digitalWrite(relay2, LOW);
  } else {
    digitalWrite(relay2, HIGH);
  }
}

/*------------------------------------ Шторы ---------------------------------------------------------*/