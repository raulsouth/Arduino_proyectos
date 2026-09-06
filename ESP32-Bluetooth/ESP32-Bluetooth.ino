#include <Arduino.h>
#include "BluetoothSerial.h"

String device_name = "ESP32-BT-Raul";
BluetoothSerial SerialBT;
int DATO;
int led1 = 26;
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
    if (DATO == '1'){
      digitalWrite(led1, HIGH);
    }
    if (DATO == '2'){
      digitalWrite(led1, LOW);
    }
  }

}
