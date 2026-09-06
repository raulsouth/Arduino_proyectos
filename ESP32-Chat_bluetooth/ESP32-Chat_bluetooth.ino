#include <Arduino.h>
#include "BluetoothSerial.h"

// Crea el objeto Bluetooth
BluetoothSerial SerialBT;

// Nombre que aparecerá en tu teléfono
String nombreBluetooth = "ESP32_Chat"; 

void setup() {
  // Inicia la comunicación serial para el Monitor Serie de la PC
  Serial.begin(115200);
  
  // Inicia el Bluetooth del ESP32
  SerialBT.begin(nombreBluetooth);
  
  Serial.println("Dispositivo iniciado. Ya puedes vincular el Bluetooth.");
}

void loop() {
  // --- De Smartphone a ESP32 ---
  if (SerialBT.available()) {
    // Lee el mensaje del teléfono y lo muestra en el Monitor Serie de la PC
    Serial.write(SerialBT.read());
  }

  // --- De ESP32 a Smartphone ---
  if (Serial.available()) {
    // Lee lo que escribes en el Monitor Serie y lo envía al teléfono
    SerialBT.write(Serial.read());
  }
}