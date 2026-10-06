//Control de brillo de led usando los pines PWM del ESP32

#include <Arduino.h>

int led1 = 26;
int brillo = 0;
// Características del PWM
const int frecuencia = 1000;
//const int canal = 0; no es nedesario para ESP32 nuevos
const int resolution = 10;

void setup() {
  // Inicializamos las características del PWM
  //ledcSetup(canal, frecuencia, resolution);
  // Definimos que el pin led1 sacara el voltaje
  ledcAttach(led1, frecuencia, resolution);

  // Encendemos y apagamos el led1 para ver si esta conectado.
  ledcWrite(led1, 255);
  delay(1000);
  ledcWrite(led1, 0);
  delay(1000);

}

void loop() {
  // Incrementamos el brillo de 0 a 255
  for (brillo = 0; brillo <= 255; brillo += 1) {
    ledcWrite(led1, brillo); // Encendemos el led con la intensidad del brillo
    delay(10);
  }

  // Decrementamos el brillo de 255 a 0
  for (brillo = 255; brillo >= 0; brillo -= 1) {
    ledcWrite(led1, brillo); // Encendemos el led con la intensidad del brillo
    delay(10);
  }
  

}
