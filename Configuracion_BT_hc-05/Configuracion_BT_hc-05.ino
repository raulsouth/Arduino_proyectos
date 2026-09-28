#include <SoftwareSerial.h>

SoftwareSerial miBT(2, 3); //RX, TX (de la placa Arduino)
                           //Rx va con TX del módulo
                           //TX va con RX del módulo

void setup() {
  Serial.begin(9600);
  Serial.println("Listo"); //Para comprobar si el puerto serial funciona
  miBT.begin(38400);

}

void loop() {
  if (miBT.available())   //Lee BT y envía a Arduino.
  Serial.write(miBT.read());

  if (Serial.available())
  miBT.write(Serial.read());   //Lee Arduino y envía a BT.
}
