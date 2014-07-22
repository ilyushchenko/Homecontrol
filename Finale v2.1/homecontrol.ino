#include "LiquidCrystal_I2C.h"
#include "utility/twi.h"
#include "Wire.h"

LiquidCrystal_I2C lcd(0x27,16,2);

int motorPin1       = 8;        // Pin мотора 1
int motorPin2       = 7;        // Pin мотора 2
int motorPin3       = 4;        // Pin мотора 3
int motorPin4       = 2;        // Pin мотора 4
int relay1          = 9;        // Реле1
int relay2          = 10;       // Реле2
int ButPin          = 11;       // Подключаем кнопку к выходу 11
int DispPin         = 12;       //Подсветка дисплея
int count           = 0;        // Количество секунд
int delay_count     = 0;        // Счетчик адержки
int lightValue      = 0;        // Начальное значение света
int curtainValue    = 1;        // Начальное значение занавески 1-закрыта 0-открыта
float openCloseValue  = 10752.0;     // Количесво шагов (1 оборот = 512 шагов)
int lookup[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

/*------------------------------------ Установка и настройка ------------------------------------*/
void setup(){ 
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);  
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  pinMode(DispPin, OUTPUT);
  pinMode(ButPin, INPUT);
  digitalWrite(relay1, LOW);
  digitalWrite(DispPin, HIGH);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);

  lcd.begin(16, 2);

  Serial.begin(9600);

  Wire.begin();
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.home();
  lcd.clear();
  lcd.print("Homecontrol v1.1");
  delay(3000);
  lcd.clear();
  delay(50);
  displayStat();
  delay(3000);
  digitalWrite(DispPin, LOW);
}

/*------------------------------------ Основной цикл --------------------------------------------*/
void loop() {
  if (digitalRead(ButPin) == HIGH){buttonAction();}
}

/*------------------------------------ Обработка кнопки -----------------------------------------*/
void buttonAction () {
  lightDisplay(1);
  count = 0;
  delay_count = 0;
  while(delay_count < 100) {
    if (digitalRead(ButPin) == HIGH)
    {
      count++;
      Serial.print("Counter: "); Serial.println(count);
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
      ligth();
    } else{
      Serial.println("Invert Zanaveska Value");
      curtain();
      motorClear();
    }
  }