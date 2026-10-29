//Control de leds desde un ESP32 hacia un Arduino esclavo mediante conexión bluetooth
//Se usa un joystick de dos ejes. Se hará pruebas para contolar el brillo de los leds

#include <Arduino.h>
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error El bluetooth no está activo! Por favor ejecute make menuconfig para activarlo.
#endif
// Pin del led indicadod de conexión
const int led1 = 2;
//#include <SoftwareSerial.h>
// Nombre del dispositivo Bluetooth
String device_name = "ESP32-BT-Raul";
BluetoothSerial SerialBT;


// Pines para los Joysticks (pines ADC1 en el ESP32)
const int PIN_X1 = 34; // Joystick 1 - Eje X
const int PIN_Y1 = 35; // Joystick 1 - Eje Y
//const int PIN_X2 = 32; // Joystick 2 - Eje X
//const int PIN_Y2 = 33; // Joystick 2 - Eje Y

// Dirección MAC del HC-05 / HC-06
uint8_t address[6] = {0x00, 0x22, 0x12, 0x01, 0x20, 0x3D}; // La dirección MAC es 0022:12:01203D
//String name = "CLASE"; // Nombre del modulo HC-05
const char *pin = "numero"; // Pin de emparejamiento del HC-05

unsigned long ultimoEnvio = 0;
const int intervaloEnvio = 50; // Envía datos cada 50ms (20veces por segundo)

void setup() {
  Serial.begin(115200);

  // Inicia el Bluetooth del ESP32 en modo maestro
  SerialBT.begin(device_name, true);
  Serial.println("Intentando conectar al Arduino...");

  // Configurar el PIN personalizado
  SerialBT.setPin(pin, strlen(pin)); // strlen(pin) cuenta automáticamente el número de caracteres del pin


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
  if (SerialBT.connected()) {
    digitalWrite(led1, HIGH); // Si hay conexión se enciende el led

    
    // Leer valores dactuales (Rango original: 0 a 4095)
    int x1 = analogRead(PIN_X1);
    int y1 = analogRead(PIN_Y1);
    //int x2 = analogRead(PIN_X2);
    //int y2 = analogRead(PIN_Y2);
    Serial.println(x1);

    // Enviar datos de manera empaquetada periódicamente sin bloquear el loop
    if (millis() - ultimoEnvio >= intervaloEnvio) {
      ultimoEnvio = millis();

      // Construye la cadena de texto: "X1,Y,X2,Y2" terminado en un salto de línea
      SerialBT.print(x1);   SerialBT.print(",");
      SerialBT.println(y1);   //SerialBT.print(",");
      //SerialBT.print(x2);   SerialBT.print(",");
      //SerialBT.println(y2);
      
    }

  } else {
    digitalWrite(led1, LOW); // Si no hay conexión se apaga el led
    // Intento de reconexión automática en segundo plano
    Serial.println("Conexión perdida. Iintentando reconectar...");
    SerialBT.connect(address);
    delay(3000); // Esperar 3 segundos antes de volver a verificar en el próximo ciclo
  }
  
   

}

