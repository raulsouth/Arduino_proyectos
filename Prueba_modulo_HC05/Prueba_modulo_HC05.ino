#include <SoftwareSerial.h>

SoftwareSerial miBT(2, 3);   //Rx, Tx


void setup() {
  Serial.begin(9600);
  Serial.println("Listo");
  miBT.begin(38400);  //Velocidad de comunic. por defecto de para el módulo bluetooth

}

void loop() {
  if (miBT.available())   //Lee BT y envía a Arduino
  Serial.write(miBT.read());

  if (Serial.available())
  miBT.write(Serial.read());  //Lee Arduino y envía a BT

}
