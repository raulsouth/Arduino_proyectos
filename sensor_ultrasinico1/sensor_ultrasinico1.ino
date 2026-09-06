#include <SoftwareSerial.h>

// Prueba se sensor ultrasónico HCSR04

//Variables
int triggerEmisor = A0;//Sensor emisor
int echoReceptor = A2;//Sensor receptor
int tiempoEntrada;
int distanciaEntrada;
int LED = 9;


void setup()
{
  pinMode(triggerEmisor, OUTPUT);
  pinMode(echoReceptor, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  sensorUltrasonidos();
  if (distanciaEntrada <=100 && distanciaEntrada >= 0)//Entre 0 y 100cm
  {
  //Serial.println("esta en entre 0 y 100");
  digitalWrite(LED, HIGH);
  delay(distanciaEntrada * 10);//LED encendido distancia*10mseg
  digitalWrite(LED, LOW);
  }
  


}


void sensorUltrasonidos()
{
  digitalWrite(triggerEmisor, LOW);//Para estabilizar
  delay(10);
  
  digitalWrite(triggerEmisor, HIGH);//Envío de pulso ultrasónico
  delayMicroseconds(10);//Emisión por 10 microsegundos
  digitalWrite(triggerEmisor, LOW);
  tiempoEntrada = pulseIn(echoReceptor, HIGH);//Tiempo transcurrido desde el emisor hasta el receptor
  delay(25);

  distanciaEntrada = (0.017 * tiempoEntrada);//(tiempoEntrada/58.2);//Fórmula para calcular la distancia en cm
  
  Serial.println("La distancia es");
  Serial.println(distanciaEntrada);
  delay(200);
}