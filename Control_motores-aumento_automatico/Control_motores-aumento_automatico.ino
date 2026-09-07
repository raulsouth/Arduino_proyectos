// Control de la velocidad de motores cambiando los valores de variables.
#include "SoftwareSerial.h"
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 10;
int ENB = 11;
int velA;
int velB;

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

  delay(3000);

}

void loop() {
  //velA = 50;
  //velB = 100;
  //Aumento de la velocidad automáticamente desde un un valor bajo hasta el máximo.
  for (velA = 75 , velB = 75; velA <= 100 , velB <= 100; velA = velA + 5 , velB = velB + 5) {
    Serial.println("Velocidad A: " + String(velA));
    Serial.println("Velocidad B: " + String(velB));
    adelante();
    delay(200);
  }
  detener();
  delay(3000);
  

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
