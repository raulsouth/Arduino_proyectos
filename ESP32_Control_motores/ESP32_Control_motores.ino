//Control de motores dc para un vehículo de dos motores con uno de ellos para controlar la dirección y el otro sentido (adelante y atras)

#include <Arduino.h>
//#include <SoftwareSerial.h>

// Motor de atras
const int ENA = 32;
const int IN1 = 23;
const int IN2 = 25;

// Motor de adelante
const int IN3 = 26;
const int IN4 = 27;
const int ENB = 14;

// Variables para controlar la velocidad de cada motor
int velA;
int velB;

// Variable para guardar el dato recibido desde el monitor serie o desde bluetooth
char dato;

void setup() {
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  delay(500);

  // Hacer un movimiento muy corto hacia adelante con motor A
  velA = 75;
  adelante();
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
 

  if (Serial.available()) {
    dato = Serial.read();

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

    else if (dato == 'x') {
    detenerB();
    }

    // Motor A trasero
    if (dato == 'w') {
      velA = 60;
      adelante();
    }
    else if (dato == 'z') {
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
*/
  // Prueba de motor B
  /*velB = 75;
  derecha();
  delay(500);
  detenerB();
  delay(5000);
*/

  

}

void adelante() {
  analogWrite(ENA, velA);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

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


