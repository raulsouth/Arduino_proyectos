// Prueba de servomotor
#include <Servo.h>
Servo servo1;
Servo servo2;

int PINSERVO = 2;
int PULSOMIN = 450; // 0°   1 milisegundo
int PULSOMAX = 2550; // 180° 2 milisegundos

int PINSERVO2 = 9;
int PULSOMIN2 = 500;
int PULSOMAX2 = 2500;


void setup() {
  servo1.attach(PINSERVO, PULSOMIN, PULSOMAX);
  servo2.attach(PINSERVO2, PULSOMAX2, PULSOMIN2);


}

void loop() {
  //servo1.write(0);
  //delay(5000);
  //servo1.write(180);
  //delay(5000);

  //servo2.write(0);
  //delay(5000);
  servo2.write(180);
  delay(5000);
}
