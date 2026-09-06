#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);

int led1 = 7;
int led2 = 8;
//int boton = 2;
char estado;//Variable en caracter para el teclado

void setup() {

  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  Serial.println("Presione una tecla");

}

void loop() {
//parpadearLed1();
delay(1000);
  if (mySerial.available()>0){ //Pregunta si hay datos para leer, si es cierto es >0
    estado = Serial.read(); //El dato se guarda en la variable estado
    switch(estado)
      {
    case 'a':
    parpadearLed1();
    break;
    case 'b':
    parpadearLed2();
    break;
      }

 }
   

}

void parpadearLed1(){
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  Serial.println("Parpadea Led1");
}

void parpadearLed2(){
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  Serial.println("Parpadea Led2");
}