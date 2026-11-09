//Control de led mediante bluetooth.

#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int DATO;// = 0;
int led = 8;

void setup() {
  Serial.begin(9600);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  miBT.println("Listo");
  miBT.println("led apagado");
  miBT.println("Usa los numeros: 1, 2");
}

void loop() {

  if (miBT.available()) {
    
    DATO = miBT.read();
    if (DATO == '1'){
      digitalWrite(led, HIGH);
      miBT.println("led on");
    }
    if (DATO == '2'){
      digitalWrite(led, LOW);
      miBT.println("led off");
    }
  }

  }   

