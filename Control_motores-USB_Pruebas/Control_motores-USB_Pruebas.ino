//Prueba de control de motores de corriente continua usando
//el puerto serie

#include "SoftwareSerial.h"
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 10;
int ENB = 11;
int velA;
int velB;
int dato;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.println("Motores listos");

  delay(3000);

}

void loop() {
  adelante();
  if (Serial.available()) {
    dato = Serial.read();
    if (dato == '1'){
      velA = 75;
      velB = 75;
      //adelante();
    }
    if (dato == '2') {
      velA = 100;
      velB = 100;
    }
    if (dato == '0') {
      velA = 0;
      velB = 0;
      Serial.println("Motores detenidos");
      //detener();
    }

  }

}

void adelante(){
  analogWrite(ENA, velA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velB);
}

void detener(){
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
