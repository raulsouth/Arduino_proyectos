//Control de motores dc para un vehículo de dos motores con uno de ellos para controlar la dirección y el otro sentido (adelante y atras)

#include <Arduino.h>
//#include <SoftwareSerial.h>

// Motor de atras

const int IN1 = 32;
const int IN2 = 33;

// Motor de adelante
const int IN3 = 25;
const int IN4 = 26;


// Variable para guardar el dato recibido desde el monitor serie o desde bluetooth
char dato;

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
  if (Serial.available()) {
    dato = Serial.read();
    if (dato == '1') {
      velB = 75;
      derecha();
    }
    else if (dato == '2') {
      velB = 75;
      izquierda();
    }

    else if (dato == '3') {
    detener_motorB();
    }
   
    
  }


  
  /*velA = 75;
  adelante();
  //Serial.println("Adelante");
  delay(1000);
  detener();
  //Serial.println("Detener");
  delay(1000);
*/
  

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

void detener_motorB(){
  analogWrite(ENB, 0);
  // Se programa los pines de dirección en bajo por seguridad
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

}

void derecha() {
  analogWrite(ENB, velB);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void izquierda() {
  analogWrite(ENB, velB);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


