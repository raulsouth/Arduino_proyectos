#include <Arduino.h>
#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Raul";
BluetoothSerial SerialBT;
char DATO;
int led1 = 2;
void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  pinMode(led1, OUTPUT);

  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  

}

void loop() {
  if (SerialBT.available()){
    DATO = SerialBT.read();
    if (DATO == 'W'){
      digitalWrite(led1, HIGH);
      SerialBT.println("led1 on");
    }
    if (DATO == 'S'){
      digitalWrite(led1, LOW);
      SerialBT.println("led2 off");
    }
  }

}
