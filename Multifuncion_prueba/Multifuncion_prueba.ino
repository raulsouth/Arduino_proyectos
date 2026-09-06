#include <SoftwareSerial.h>
int led1 = 8;
int led2 = 9;
char caracter;
SoftwareSerial myBT (2, 3);

void setup() {
  myBT.begin(38400);
  myBT.println("Hay conexion");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  delay(100);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

void loop() {
  if (myBT.available()) {
    caracter = myBT.read();
  }
  if (caracter == 'p'){
    parpadeo();
  }

  if (myBT.available()) {
    caracter = myBT.read();
  }
  if (caracter == 'l'){
    mensaje1();
  }

}


void parpadeo(){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(200);
}

void mensaje1(){
  myBT.println(caracter);
  delay(1000);
}
