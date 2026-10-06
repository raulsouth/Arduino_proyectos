#include <Arduino.h>
#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to enable it
#endif

#include "esp_bt_main.h"
#include "esp_bt_device.h"
#include "esp_gap_bt_api.h"

String device_name = "ESP32-BT-Raul_pin";
BluetoothSerial SerialBT;
int DATO;
int led1 = 26;

void setup() {
  Serial.begin(115200);

  // Inicializa el dispositivo con un nombre
  SerialBT.begin(device_name);

  // Configuración del PIN estático (ejemplo: "1234")
  esp_bt_pin_code_t pin_code;
  pin_code[0] = '4';
  pin_code[1] = '3';
  pin_code[2] = '2';
  pin_code[3] = '1';

  // Asigna un PIN de 4 dígitos
  esp_bt_gap_set_pin(ESP_BT_PIN_TYPE_FIXED, 4, pin_code);


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
      SerialBT.println("led1 on");
    }
    if (DATO == '2'){
      digitalWrite(led1, LOW);
      SerialBT.println("led2 off");
    }
  }

}
