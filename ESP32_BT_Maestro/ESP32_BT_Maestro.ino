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
  // strlen(pin) cuenta automáticamente cuántos caracteres tiene el PIN
  SerialBT.setPin(pin, strlen(pin));

  Serial.println("Intentando conectar con el HC-05 (CLASE)...");

  // Conexión usando parámetros de seguridad específicos del ESP32
  // ESP_SPP_SEC_NONE permite que se maneje la autenticación por pin tradicional

  // Conexión por dirección MAC
  bool conectado = SerialBT.connect(address, ESP_SPP_SEC_NONE, ESP_SPP_ROLE_MASTER);

  // Configuración de led indicador del ESP32; indica se hay conexión bluetooth
  pinMode(led1, OUTPUT);
  // Encendemos y apagamos el led. Para asegurarnos de que está bien conectado
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW); // Podríamos colocar solo esta parte del código para iniciar el led apagado

  if(conectado) {
    Serial.println("¡Conectado exitosamente!");
    digitalWrite(led1, HIGH); // Encendemos un led para indicar conexión exitosa
  } else {
    Serial.println("Error de conexión. Reintentando...");
    while(!SerialBT.connected()) {
      // Reintento forzado con los parámetros de seguridad
      SerialBT.connect(address, ESP_SPP_SEC_NONE, ESP_SPP_ROLE_MASTER);
      delay(5000);
      digitalWrite(led1, LOW);
    }
    Serial.println("\n¡Conectado tras reintento!");
    digitalWrite(led1, HIGH);
  }
  
  delay(500);

  

 



}

void loop() {
  // Control del led indicador y reconexión
  if (SerialBT.connected()) {
    digitalWrite(led1, HIGH); // Si hay conexión, led1 encendido
  } else {
    digitalWrite(led1, LOW); // Sino hay conexión, led1 apagado

    // Intendo de reconexión automática en segundo plano
    Serial.println("Conexión perdida. Intentando reconectar...");
    SerialBT.connect(address);
    delay(3000);
  }
char letra;

    if (Serial.available()) { // Desde el monitor serial del ESP32 enviamos un caracter que
    //si es el correcto se enviará luego por Bluetooth al Arduino.
      letra = Serial.read();
      SerialBT.write(letra);
      if (letra == '1') {
        SerialBT.write('1');
        Serial.println("Enviado 1 para encender led1");
      }
      if (letra == '2') {
        SerialBT.write('2');
        Serial.println("Enviado 2 para apagar led1");
      }
    }



/*
  // Envío de caracter para control de un led del Arduino
  //SerialBT.write('\n');
  SerialBT.write('1');
  Serial.println("Enviado 1 para encender led1");
  delay(2000);
  //SerialBT.write('\n');
  SerialBT.write('2');
  Serial.println("Enviado 2 para apagar led1");
  delay(2000);
 */

  


  

}

