#include "LiquidCrystal_I2C.h"
#include "utility/twi.h"
#include "Wire.h"

uint8_t   block1[8] = {B10000, B10000, B10000, B10000, B10000, B10000, B10000, B10000 };
uint8_t   block2[8] = {B11000, B11000, B11000, B11000, B11000, B11000, B11000, B11000 };
uint8_t   block3[8] = {B11100, B11100, B11100, B11100, B11100, B11100, B11100, B11100 };
uint8_t   block4[8] = {B11110, B11110, B11110, B11110, B11110, B11110, B11110, B11110 };
uint8_t   block5[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111 };

LiquidCrystal_I2C lcd(0x27,16,2);

void void setup()
{ 
  Serial.begin(9600);
  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.begin(16, 2);
  lcd.createChar(0, block1);
  lcd.createChar(1, block2);
  lcd.createChar(2, block3);
  lcd.createChar(3, block4);
  lcd.createChar(4, block5);
}

void void loop()
{
  
}