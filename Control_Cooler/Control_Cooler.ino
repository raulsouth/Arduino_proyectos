#include <SoftwareSerial.h>
int PWM = 9;
int vel = 255;

//Motor A
int IN1 = 






void setup() {
  Serial.begin(9600);
  pinMode(PWM, OUTPUT);

}

void loop() {
  analogWrite(PWM, vel);
  Serial.println("Motor on");
  delay(2000);
  analogWrite(PWM, 0);
  Serial.println("Motor off");
  delay(2000);

}
