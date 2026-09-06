
// Motor A 
int ENA = 10; 
int IN1 = 4; 
int IN2 = 5; 
// Motor B 
int ENB = 11; 
int IN3 = 6; 
int IN4 = 7;
//Velocidad Estandar 
//int velMA = 255;
//int velMB = 255;


void setup() {
  pinMode (ENA, OUTPUT); 
  pinMode (ENB, OUTPUT); 
  pinMode (IN1, OUTPUT); 
  pinMode (IN2, OUTPUT); 
  pinMode (IN3, OUTPUT); 
  pinMode (IN4, OUTPUT); 

}

void loop() {
   Adelante();
   delay(1000);
   Detener();
   delay(5000);
   Derecha();
   delay(1000);
   Detener();
   delay(1000);


}



void Adelante()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
//analogWrite(ENA,velMA);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
//analogWrite(ENB,velMB);
Serial.println("Adelante");
  
}

void Atras()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
//analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
//nalogWrite(ENB,velMB);
Serial.println("Atras");  
  
}

void Izquierda()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,HIGH);
//analogWrite(ENA,velMA);

digitalWrite(IN3,HIGH);
digitalWrite(IN4,LOW);
//analogWrite(ENB,velMB);
Serial.println("Izquierda");

  
}

void Derecha()
{
digitalWrite(IN1,HIGH);
digitalWrite(IN2,LOW);
//analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,HIGH);
//analogWrite(ENB,velMB);
Serial.println("Derecha");
  
 
}

void Detener()
{
digitalWrite(IN1,LOW);
digitalWrite(IN2,LOW);
//analogWrite(ENA,velMA);

digitalWrite(IN3,LOW);
digitalWrite(IN4,LOW);
//analogWrite(ENB,velMB);
Serial.println("Detener");
 
}
