int LedPin = 12;        //  Подключаем светодиод к порту 13
int ButPin = 10;        //  Подключаем кнопку к выходу 10
int LedVal = LOW;       //  устанавливаем начальное состояние светодиода
int count = 0;          //  Количество секунд
int delay_count = 0;      //  Счетчик адержки
int lightValue = 0;

void setup(){
  Serial.begin(9600);
  pinMode(ButPin, INPUT);
}

void loop() {
  if (digitalRead(ButPin) == HIGH){
    svitchRelayLight ();
  }
  check();
}

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
    Serial.println("Invert Zanaveska Value");
  }
}

void check() {
  if (lightValue)
  {
    digitalWrite(LedPin, HIGH);
  } else {
    digitalWrite(LedPin, LOW);
  }
}
