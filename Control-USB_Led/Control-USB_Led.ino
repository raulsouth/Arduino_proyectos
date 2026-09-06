
#include <SoftwareSerial.h>
char dato;
int led1 = 8;
int led2 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial.println("Listo");
  delay(1000);

}

void loop() {
  if (Serial.available()) {
    dato = Serial.read();
    if (dato == '1') {
      digitalWrite(led1, HIGH);
      Serial.println("Led encendido");
    }
    if (dato == '2') {
      digitalWrite(led1, LOW);
      Serial.println("Led apagado");
    }
  }

}
