//Control de dos leds mediante bluetooth.

#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int led1 = 9;
int led2 = 10;

void setup() {
  Serial.begin(9600);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  miBT.println("Listo");
  miBT.println("led1 y led2 apagados");
}

void loop() {

  if (miBT.available()) {

    // Leer los 4 valores analógicos separados por comas
    int x1 = Serial.parseInt();
    int y1 = Serial.parseInt();
    int x2 = Serial.parseInt();
    int y2 = Serial.parseInt();

    // Al encontrar el salto de línea '\n', descartamos el resto de buffer
    if (Serial.read() == '\n') {
      // Mapeo de intensidad (usando el Eje y del primer joystick)
      // El centro del joystick está cerca de 2048
      int intensidad = 0;

      if (y1 > 2200) { // Aumenta intensidad
        intensidad = map(y1, 2200, 4095, 0, 255);

        analogWrite(led1, intensidad);

      } else if (y1 < 1900) { // Disminuye intensidad
        intensidad = map(y1, 1900, 0, 255, 0);

        analogWrite(led1, intensidad);
      } else {  // Joystick en el centro
      analogWrite(led1, 0);
      digitalWrite(led1, LOW);

      }
    }
    
    
  }

    
  }   

