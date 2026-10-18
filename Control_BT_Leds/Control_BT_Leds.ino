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
  miBT.println("Listo");
  miBT.println("led1 y led2 apagados");
  miBT.println("Usa los numeros: 1, 2, 3, 4");
}

void loop() {

  if (miBT.available()) {
    
    DATO = miBT.read();
    if (DATO == '1'){
      digitalWrite(led1, HIGH);
      miBT.println("led1 on");
    }
    if (DATO == '2'){
      digitalWrite(led1, LOW);
      miBT.println("led1 off");
    }

    if (DATO == '3'){
      digitalWrite(led2, HIGH);
      miBT.println("led2 on");
    }
    if (DATO == '4'){
      digitalWrite(led2, LOW);
      miBT.println("led2 off");
    }
  }

    
  }   

