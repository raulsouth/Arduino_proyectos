#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
char DATO;// = 0;
int LedVerde = 9;
int LedRojo = 8;

void setup() {
  Serial.begin(9600);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(LedVerde, OUTPUT);
  pinMode(LedRojo, OUTPUT);
}

void loop() {

  if (miBT.available()) {
    
    DATO = miBT.read();
    if (DATO =='1'){
       //Para encender y apagar con un mismo número:
    digitalWrite(LedVerde, !digitalRead(LedVerde));  //El signo ! invierte el valor leido
    //digitalWrite(LedVerde, HIGH);
    Serial.println("Led verde Encendido");
    }
    if (DATO == '2'){
    digitalWrite(LedVerde, LOW);
    Serial.println("Led verde Apagado");}
    if (DATO == '3'){
    digitalWrite(LedRojo, !digitalRead(LedRojo));
    Serial.println("Led rojo encendido");}
    if (DATO == '4'){
    digitalWrite(LedRojo, LOW);
    Serial.println("Led rojo apagado");}
    if (DATO == '5'){
    parpadearLedVerde();
    delay(100);
    parpadearLedVerde();
    Serial.println("Led verde parpadea");
    }
    if (DATO == '6'){
    parpadearLedRojo();
    delay(100);
    parpadearLedRojo();
    Serial.println("Led rojo parpadea");
    }
  }    

}
void parpadearLedVerde(){
  digitalWrite(LedVerde, HIGH);
  delay(200);
  digitalWrite(LedVerde, LOW);
}
void parpadearLedRojo(){
  digitalWrite(LedRojo, HIGH);
  delay(200);
  digitalWrite(LedRojo, LOW);
}


