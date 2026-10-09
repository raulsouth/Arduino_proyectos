//Control de motores dc para un vehículo de dos motores con uno de ellos para controlar la dirección y el otro sentido (adelante y atras)

#include <Arduino.h>
//#include <SoftwareSerial.h>

const int ENA = 32;
const int IN1 = 23;
const int IN2 = 25;
const int IN3 = 26;
const int IN4 = 27;
const int ENB = 14;
int velA;
int velB;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

    

}

void loop() {

  

  
  velA = 75;
  adelante();
  //Serial.println("Adelante");
  delay(1000);
  detener();
  //Serial.println("Detener");
  delay(1000);

  
}

void adelante() {
  analogWrite(ENA, velA);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}

void detener() {
  
  analogWrite(ENA, 0);

  // Se programa los pines de dirección en bajo por seguridad
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
