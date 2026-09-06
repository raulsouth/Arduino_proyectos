#include <SoftwareSerial.h>


SoftwareSerial miBT(2, 3); //Rx, Tx: Los pines donde van los cables Rx y Tx invertidos del módulo bluetooth
//Declaramos una variable
char DATO;


// Motor A 
int ENA = 10; 
int IN1 = 4; 
int IN2 = 5; 
// Motor B 
int ENB = 11; 
int IN3 = 6; 
int IN4 = 7;
//Velocidad Estandar 
int velMA = 255;
int velMB = 255;

void setup() { 

Serial.begin(9600) ; 
miBT.begin(38400); //Velocidad de comunic. por defecto para el módulo bluetooth 
// Declaramos todos los pines digitales como salidas 
pinMode (ENA, OUTPUT); 
pinMode (ENB, OUTPUT); 
pinMode (IN1, OUTPUT); 
pinMode (IN2, OUTPUT); 
pinMode (IN3, OUTPUT); 
pinMode (IN4, OUTPUT);

Adelante();
delay(1000);
Detener();
} 

void loop() {

//Para comprobar que funcionan los motores
/*Adelante();
delay(5000);
Atras();
delay(5000);
Derecha();
delay(5000);
Izquierda();
delay(5000);
Detener();
delay(2000);
*/

if (miBT.available()){

  DATO = miBT.read();
  if (DATO == 'W'){
    Adelante();
  }
  if (DATO == 'S'){
    Atras();
  }
  if (DATO == 'D'){
    Derecha();
  }
  if (DATO == 'A'){
    Izquierda();
  }
  if (DATO == 'X'){
    Detener();
  }
  }
}//Final void Loop()



void Adelante()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
analogWrite(ENB,velMB);
Serial.println("Adelante");
  
}

void Atras()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
analogWrite(ENA,velMA);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
analogWrite(ENB,velMB);
Serial.println("Atras");  
  
}

void Izquierda()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
analogWrite(ENA,velMA);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
analogWrite(ENB,velMB);
Serial.println("Izquierda");

  
}

void Derecha()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
analogWrite(ENB,velMB);
Serial.println("Derecha");
  
 
}

void Detener()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
analogWrite(ENB,velMB);
Serial.println("Detener");
 
}
