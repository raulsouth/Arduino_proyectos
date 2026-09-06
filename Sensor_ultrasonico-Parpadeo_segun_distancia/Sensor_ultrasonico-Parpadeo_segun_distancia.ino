//Uso del sensor ultrasónico hc-sr04
//para indicar la cercanía de un cuerpo
//medialnte la velocidad de parpadeo
//de un led.

#include <SoftwareSerial.h>
int triggerEmisor = 12;
int echoReceptor = 11;
int tiempoEntrada;
float dist;
int led = 9;
void setup() {
  pinMode(triggerEmisor, OUTPUT);
  pinMode(echoReceptor, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  digitalWrite(led, LOW);
  

}

void loop() {
  digitalWrite(triggerEmisor, LOW);
  delay(10);

  digitalWrite(triggerEmisor, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerEmisor, LOW);
  tiempoEntrada = pulseIn(echoReceptor, HIGH);
  delay(25);

  dist = (0.017 * tiempoEntrada);
  Serial.print("distancia: ");
  Serial.println(dist);
  //delay(200);

if (dist < 100){
  float tiempo = dist*2;// / 100;
  digitalWrite(led, HIGH);
  delay(tiempo);
  digitalWrite(led, LOW);
  delay(tiempo);
  Serial.println(tiempo);

}
digitalWrite(led, LOW);
  delay(200);

  if (dist < 0){
    digitalWrite(led, LOW);
  }

  

}
