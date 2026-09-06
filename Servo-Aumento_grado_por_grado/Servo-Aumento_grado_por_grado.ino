// Prueba de servomotor
#include <Servo.h>
Servo servo1;

int PINSERVO = 2;
int PULSOMIN = 450; // 0°   1 milisegundo
int PULSOMAX = 2550; // 180° 2 milisegundos
int grados;


void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);


}

void loop() {
  for (grados = 0; grados < 180; grados = grados + 10) {
    servo1.write(grados);
    delay(1000);

  }

  
}
