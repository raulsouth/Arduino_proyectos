//Control de motores dc para un vehículo de dos motores con uno de ellos para controlar la dirección y el otro sentido (adelante y atras)

#include <Arduino.h>
#include "BluetoothSerial.h"
//#include <SoftwareSerial.h>
String device_name = "ESP32-BT-Raul";
BluetoothSerial SerialBT;

// Motor de atras
const int ENA = 25;
const int IN1 = 26; //23
const int IN2 = 27;

// Motor de adelante
const int IN3 = 14;
const int IN4 = 12;
const int ENB = 13;

// Variables para controlar la velocidad de cada motor
int velA;
int velB;

// Variable para guardar el dato recibido desde el monitor serie o desde bluetooth
char dato;

void setup() {
  Serial.begin(115200);
  SerialBT.begin(device_name);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(500);

  // Hacer un movimiento muy corto hacia adelante y hacia atras con motor A
  velA = 75;
  adelante();
  delay(100);
  detenerA();
  delay(500);
  atras();
  delay(100);
  detenerA();
  delay(1000);

  // mover la dirección delantera 
  velB = 75;
  derecha();
  delay(100);
  detenerB();
  delay(500);
  izquierda();
  delay(100);
  detenerB();

  // Cambiar las variables a valores cero
  velA = 0;
  velB = 0; 

  delay(2000);

}

void loop() {
 

  if (SerialBT.available()) {
    dato = SerialBT.read();

    // Motor B delantero
    if (dato == 'd') {
      velB = 75;
      derecha();
      delay(200);
      detenerB();
    }
    else if (dato == 'a') {
      velB = 75;
      izquierda();
      delay(200);
      detenerB();
    }

    else if (dato == 'z') {
    detenerB();
    }

    // Motor A trasero
    else if (dato == 'w') {
      velA = 60;
      adelante();
    }
    else if (dato == 's') {
      velA = 60;
      atras();
    }
    else if (dato == 'x') {
      detenerA();
    }
   
    
  }




  // Prueba de motor A para ir hacia adelante un momento y detenerse
  /*velA = 75;
  adelante();
  //Serial.println("Adelante");
  delay(1000);
  detenerA();
  //Serial.println("Detener");
  delay(2000);

  // Prueba de motor B
  /*velB = 75;
  derecha();
  delay(500);
  detenerB();
  delay(5000);
*/
  // Prueba de motor A hacia atras
  /*velA = 75;
  atras();
  delay(1000);
  detenerA();
  delay(2000);
*/
  

  

}



// Funciones:
void adelante() {
  analogWrite(ENA, velA);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

}

void atras() {
  analogWrite(ENA, velA);
  //digitalWrite(ENA, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  SerialBT.println("atras");

}

void detenerA() {
  
  analogWrite(ENA, 0);
  // Se programa los pines de dirección en bajo por seguridad
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void detenerB(){
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


