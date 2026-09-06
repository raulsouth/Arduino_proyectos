#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int DATO;// = 0;


void setup() {
  Serial.begin(9600);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {

  if (miBT.available()) {
    
    DATO = miBT.read();
    if (DATO == '1'){
      digitalWrite(8, HIGH);
    
    }
    if (DATO == '2'){
      digitalWrite(8, LOW);
    }
  }
    
  }   

