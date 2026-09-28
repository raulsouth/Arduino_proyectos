#include <SoftwareSerial.h>
int led1 = 8;
int led2 = 12;
int t = 500;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  Serial.println("Listo");
}

void loop() {
  /*Serial.println("parpadeo");
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(t);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(t);*/

  if (Serial.available()){
    char dato = Serial.read();
    if (dato == '1') {
      digitalWrite(led1, HIGH);
      Serial.println("led 1 encendido");
    
    }
    if (dato == '2') {
      digitalWrite(led1, LOW);
      Serial.println("led 1 apagado");
    }
  }

}
