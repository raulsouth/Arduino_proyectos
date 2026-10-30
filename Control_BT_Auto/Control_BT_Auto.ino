//Control de motores para un vehículo de dos motores con uno de ellos
//para controlar la tracción (avanzar o retroceder) y el otro
//para controlar la dirección (derecha o izquierda)
//El eje Y del Joystick regulara la tracción y el eje X controlará
//la dirección
#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int led1 = 9;
int led2 = 10;

// Motor de atras (tracción)
int ENA = 9;
int IN1 = 4;
int IN2 = 5;

// Motor delantero (dirección)
int ENB = 10;
int IN3 = 6;
int IN4 = 7;

// Variables para controlar la velocidad de cada motor
int velA;
int velB;

void setup() {
  Serial.begin(115200);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
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

  // Prueba si funcionan los leds
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  // Envío de mensaje al Maestro
  miBT.println("Listo");
  miBT.println("Vehículo listo");
  delay(3000);
}

void loop() {

  if (miBT.available() > 0) {
    //Serial.println("Esperando dato");

    // Leer los 4 valores analógicos separados por comas
    int x1 = miBT.parseInt();
    int y1 = miBT.parseInt();
    //int x2 = miBT.parseInt();
    //int y2 = miBT.parseInt();

    // Limpieza rápida del buffer serial
    while (miBT.available() > 0) {
    miBT.read();
    }
    
      // Opcional: Imprime en la PC los datos recibidos para verificar el joystick
      // Serial.print("Recibido -> X1: "); Serial.print(x1);
      // Serial.print(" | Y1: "); Serial.println(y1);
      
      
      // Mapeo de intensidad (usando el Eje y del primer joystick)
      // El centro del joystick está cerca de 2048
      // Control del motor B con el eje x
      if (x1 > 2200) {
        velB = map(x1, 2200, 4095, 0, 50);
        derecha();
        delay(200);
        detenerB();
      } else if (x1 < 1800) {
        velB = map(x1, 1800, 0, 0, 50);
        izquierda();
        delay(200);
        detenerB();
      } else if (1800 < x1 < 2200) {
        detenerB();
      }

      // Control del motor A con el eje y
      if (y1 > 2200) {
        velA = map(y1, 2200, 4095, 0, 50);
        adelante();
      } else if (y1 < 1800) {
        velA = map(y1, 1800, 0, 0, 50);
        atras();
      } else if (1800 < y1 < 2200) {
        detenerA();
      }
  }
    
    
    
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
