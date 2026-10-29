//Control de dos leds mediante bluetooth.
//Se conectará un joystick de dos ejes para hacer pruebas
//Según la posición del los ejes x e y cambiará el brillo de los leds

#include <SoftwareSerial.h>

SoftwareSerial miBT(2,3);   //Rx, Tx
int led1 = 9;
int led2 = 10;

void setup() {
  Serial.begin(115200);
  miBT.begin(38400);  //Velocidad de comunic. por defecto para el módulo bluetooth
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // Prueba si funcionan los leds
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  // Envío de mensaje al Maestro
  miBT.println("Listo");
  miBT.println("led1 y led2 apagados");
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
      
      int intensidady1 = 0;
      int intensidadx1 = 0;
      // Mapeo de intensidad (usando el Eje y del primer joystick)
      // El centro del joystick está cerca de 2048
      // Control del led2 con el eje x
      if (x1 > 2200) {
        intensidadx1 = map(x1, 2200, 4095, 20, 255);
        analogWrite(led2, intensidadx1);
      } else if (x1 < 1800) {
        intensidadx1 = map(x1, 1800, 0, 20, 0);
        analogWrite(led2, intensidadx1);
      } else if (1800 < x1 < 2200) {
        analogWrite(led2, 20);
        //digitalWrite(led2, LOW);
      }

      // Control del led1 con el eje y
      if (y1 > 2200) {
        intensidady1 = map(y1, 2200, 4095, 0, 255);
        analogWrite(led1, intensidady1);
      } else if (y1 < 1800) {
        intensidady1 = map(y1, 1800, 0, 0, 255);
        analogWrite(led1, intensidady1);
      } else if (1800 < y1 < 2200) {
        analogWrite(led1, 0);
        digitalWrite(led1, LOW);// Por seguridad enviamos LOW
      }
  }
    
    
    
}  

