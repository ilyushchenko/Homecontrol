// Node 1 - main

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h> // https://github.com/maniacbug/RF24

#define UnicueID 1  // Номер ноды

struct Package
{
  byte nodeID;
  int command;
  int value;
  unsigned long ID;
};

const uint64_t pipe1 = 0xAABBCCDD11LL; // Главный контроллер
const uint64_t pipe2 = 0xAABBCCDD22LL; // --
const uint64_t pipe3 = 0xAABBCCDD33LL; // --
const uint64_t pipe4 = 0xAABBCCDD44LL; // Окно
uint8_t pipe;
RF24 radio(7,8); // CE, CSN
Package tx_data; 
Package rx_data;
bool canSending = true;
byte countOfTrying = 0;
unsigned long lastSending;

void setup()
{
  Serial.begin(9600);
  
  radio.begin();  
  radio.setChannel(78);
  radio.setDataRate(RF24_2MBPS);     
  radio.setPALevel(RF24_PA_HIGH);
  radio.openWritingPipe(pipe1);
  radio.openReadingPipe(2,pipe2);
  radio.openReadingPipe(3,pipe3);
  radio.openReadingPipe(4,pipe4);
  radio.startListening();
}

void loop()   
{
  if(radio.available(&pipe))
  {
    switch(pipe)
    {
      case 2:
        Serial.println("Node Two");
        break;
      case 3:
        Serial.println("Node Three");
        break;
      case 4:
        Serial.println("Node Four");
        break;
      default:
        Serial.println("Unknown node");
        break;
    }
    radio.read(&rx_data, sizeof(rx_data));
    PirntPackage(rx_data);
    if(rx_data.ID == tx_data.ID)
    {
      canSending = true;
      Serial.println("The answer was received!");
    }
  }
  // Тестовая отправка данных
  if(Serial.available())
  {
    char ch = Serial.read() - '0';
    if(canSending)
    {
      tx_data.nodeID = ch;
      tx_data.command = 1;
      tx_data.value = 1;
      tx_data.ID = millis();
      PirntPackage(tx_data);
      canSending = false;
      countOfTrying = 0;
      lastSending = tx_data.ID + 50;
      Write();
    }
    else
    {
      Serial.println("Countdown on sending!");
    }
  }
  if(!canSending)                               // Проверка, пришел ли ответ.
  {
    if(countOfTrying < 5)
    {
      if(millis() > lastSending)
      {
        Serial.print("Attempt number ");
        countOfTrying++;
        Serial.println(countOfTrying);
        lastSending = millis() + 50;
        Write();
      }
    }
    else
    {
      Serial.println("The answer wasn't received!");
      canSending = true;
    }
  }
}

bool Write()
{
  radio.stopListening();
  bool result = radio.write(&tx_data, sizeof(tx_data));    
  radio.startListening();
  return result;
}

void PirntPackage(Package data)
{
  Serial.print("Sending to node: ");
  Serial.println(data.nodeID);
  Serial.print("Command: ");
  Serial.println(data.command);
  Serial.print("Value: ");
  Serial.println(data.value);
  Serial.print("ID: ");
  Serial.println(data.ID);
}
