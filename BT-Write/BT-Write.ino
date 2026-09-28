//Control de dos leds mediante bluetooth.

#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int DATO;// = 0;
int led1 = 8;
int led2 = 9;

void setup() {
  Serial.begin(9600);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  
}

void loop() {
  miBT.write(60);
  //miBT.write("\n");
  delay(1000);

  
  }   

