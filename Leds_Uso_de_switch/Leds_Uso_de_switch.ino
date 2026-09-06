#include <SoftwareSerial.h>
//SoftwareSerial mySerial(0, 1);
int ledRojo = 9;
int ledVerde = 10;
char texto;

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  digitalWrite(ledRojo, HIGH);
  digitalWrite(ledVerde, HIGH);
  delay(200);
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledVerde, LOW);
  delay(200);

}

void loop() {
  if (Serial.available()>0){
    texto = Serial.read();
    switch(texto)
    {
      case 'r':
      digitalWrite(ledRojo, HIGH);
      break;
      case 'v':
      digitalWrite(ledVerde, HIGH);
      break;
    }
  }

}

