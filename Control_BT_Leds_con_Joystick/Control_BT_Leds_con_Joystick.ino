//Control de dos leds mediante bluetooth.

#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int led1 = 9;
int led2 = 10;

void setup() {
  Serial.begin(115200);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  analogWrite(led1, 5);//digitalWrite(led1, HIGH);
  analogWrite(led2, 255);//digitalWrite(led2, HIGH);
  delay(500);
  analogWrite(led1, 0);digitalWrite(led1, LOW);
  analogWrite(led2, 0);//digitalWrite(led2, LOW);
  miBT.println("Listo");
  miBT.println("led1 y led2 apagados");
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

    // Al encontrar el salto de línea '\n', descartamos el resto de buffer
    //if (miBT.read() == '\n') {

      // Opcional: Imprime en la PC los datos recibidos para verificar el joystick
      Serial.print("Recibido -> X1: "); Serial.print(x1);
      Serial.print(" | Y1: "); Serial.println(y1);
      // Mapeo de intensidad (usando el Eje y del primer joystick)
      // El centro del joystick está cerca de 2048




      int intensidady1 = 0;
      int intensidadx1 = 0;

      if (x1 > 2200) {
        intensidadx1 = map(x1, 2200, 4095, 0, 255);
        analogWrite(led2, intensidadx1);
      } else if (x1 < 1800) {
        intensidadx1 = map(x1, 1800, 0, 0, 255);
        analogWrite(led2, intensidadx1);
      } else if (1800 < x1 < 2200) {
        analogWrite(led2, 0);
        digitalWrite(led2, LOW);
      }

      
      if (y1 > 2200) {
        intensidady1 = map(y1, 2200, 4095, 0, 255);
        analogWrite(led1, intensidady1);
      } else if (y1 < 1800) {
        intensidady1 = map(y1, 1800, 0, 0, 255);
        analogWrite(led1, intensidady1);
      } else if (1800 < y1 < 2200) {
        analogWrite(led1, 0);
        digitalWrite(led1, LOW);
      }

      /*if (x1 > 2200 && y1 > 2200)  { // Aumenta intensidad
        intensidadx1 = map(x1, 2200, 4095, 0, 255);
        intensidady1 = map(y1, 2200, 4095, 0, 255);
        

        analogWrite(led2, intensidadx1); // indica x1
        analogWrite(led1, intensidady1); // indica y1
        
        
      } else if (x1 < 1800 && y1 < 1800) { // Disminuye intensidad
        intensidadx1 = map(x1, 1800, 0, 0, 255);
        intensidady1 = map(y1, 1800, 0, 0, 255);
        
        analogWrite(led2, intensidadx1);
        analogWrite(led1, intensidady1);
        
      } else {  // Joystick en el centro
      analogWrite(led1, 0);
      analogWrite(led2, 0);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      

      }*/
    }
    
    
  }

    
  //}   

