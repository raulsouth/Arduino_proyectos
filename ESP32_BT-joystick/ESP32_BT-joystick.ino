//Control de leds desde un ESP32 hacia un Arduino esclavo mediante conexión bluetooth

#include <Arduino.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error El bluetooth no está activo! Por favor ejecute make menuconfig para activarlo.
#endif

const int led1 = 2;
//#include <SoftwareSerial.h>
String device_name = "ESP32-BT-Raul";
BluetoothSerial SerialBT;

// Dirección MAC del HC-05 / HC-06
uint8_t address[6] = {0x00, 0x22, 0x12, 0x01, 0x20, 0x3D}; // La dirección MAC es 0022:12:01203D
//String name = "CLASE"; // Nombre del modulo HC-05
const char *pin = "numero"; // Pin de emparejamiento del HC-05






void setup() {
  Serial.begin(115200);

  // Inicia el Bluetooth del ESP32 en modo maestro
  SerialBT.begin(device_name, true);
  Serial.println("Intentando conectar al Arduino...");

  // Configurar el PIN personalizado
  SerialBT.setPin(pin, 6);

  Serial.println("Intentando conectar con el HC-05 (CLASE)...");

  // Conexión usando parámetros de seguridad específicos del ESP32
  // ESP_SPP_SEC_NONE permite que se maneje la autenticación por pin tradicional

  // Conexión por dirección MAC
  bool conectado = SerialBT.connect(address, ESP_SPP_SEC_NONE, ESP_SPP_ROLE_MASTER);

  // Configuración de led indicador del ESP32
  pinMode(led1, OUTPUT);
  // Encendemos y apagamos el led
  digitalWrite(led1, HIGH);
  delay(200);
  digitalWrite(led1, LOW);

  if(conectado) {
    Serial.println("¡Conectado exitosamente!");
    digitalWrite(led1, HIGH); // Encendemos un led para indicar conexión exitosa
  } else {
    Serial.println("Error de conexión. Reintentando...");
    digitalWrite(led1, LOW);
    while(!SerialBT.connected()) {
      // Reintento forzado con los parámetros de seguridad
      SerialBT.connect(address, ESP_SPP_SEC_NONE, ESP_SPP_ROLE_MASTER);
      delay(5000);
    }
    Serial.println("\n¡Conectado tras reintento!");
  }
  
  delay(500);

  

 



}

void loop() {
  
  // Envío de caracter para control de un led del Arduino
  //SerialBT.write('\n');
  SerialBT.write('1');
  Serial.println("Enviado 1 para encender led1");
  delay(2000);
  //SerialBT.write('\n');
  SerialBT.write('2');
  Serial.println("Enviado 2 para apagar led1");
  delay(2000);
 

  


  

}

