#include <SoftwareSerial.h>
SoftwareSerial mySerial(0, 1);//RX, TX

char texto_bt;
//Motor A int
int ENA = 10;
int IN1 = 5;
int IN2 = 4;
//Motor B int
int IN3 = 6;
int IN4 = 7;
int ENB = 11;
//Velocidad Estandar
int velMA = 200;
int velMB = 200;

int speakerPin = 2;
int numTones = 10;
int tone[] = {261, 277, 294, 311, 330, 370, 392, 415, 440, 466, 494};
//mid C C# D D# E F F# G G# A

void setup(){
  Serial.begin(9600);//nicia protocolo de comunicación, llamamos a la librería Serial (no es nec. usar #include)
  pinMode(IN1, OUTPUT);//hacia Entrada 1 IN1
  pinMode(IN2, OUTPUT);//hacia Entrada 2 IN2
  pinMode(IN3, OUTPUT);//hacia Entrada 3 IN3
  pinMode(IN4, OUTPUT);//hacia Entrada 4 IN4
  pinMode(ENA, OUTPUT);//hacia Enable 1 y 2 ENA
  pinMode(ENB, OUTPUT);//hacia Enable 3 y 4 ENB
  //pinMode(A0, OUTPUT);
  //pindMode(A1 OUTPUT);
  //pinMode(A2, OUTPUT);
  //pinmode(A3, OUTPUT);
}
void loop(){
if(Serial.available()[]>0){
switch (Serial.read())//Motor gira en un sentido
}
case '1':
Adelante();
break;
case '2';
Atras();
break;
case '3':
Derecha();
break;
case '4':
Izquierda();
break;
case '5':
Stop();
break;

  
  
  
void adelante()
{
  digitalWrite(IN1, HIGH);//Gira motor en + (el motor se coloca rotado)
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velMA);//Velocidad Motor derecha
  digitalWrite(IN3, HIGH);//Gira motor en -
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velMB);//Velocidad Motor izquierda
  digitalWrite(A0; HIGH);//Luz delantero encendido
  digitalWrite(A1, HIGH);
  digitalWrite(A3, LOW);
  digitalWrite(A4, LOW);
  for (int i = 0; i < numTones; i++){
  tone(speakerPin, tones[i]);
  delay(500);}
  noTone(peakerPin);
}
  
  void Atras()
{
   digitalWrite(IN1, LOW);
   digitalWrite(IN2, HIGH);
   analogWrite(ENA, velMA);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   analogWrite(ENM, velMB);
   digitalWrite(A2, HIGH);
   digitalWrite(A3, HIGH);
   digitalWrite(A0, LOW);
   digitalWrite(A1, LOW);
 }
  
 voir Izquierda()
{
   digitalWrite(IN1,LOW);
   digitalWrite(IN2, HIGH);
   analogWrite(ENA, velMA);
   digitalWrite(IN3, HIGH);
   digitalWrite(IN4, LOW);
   analogWrite(ENB, velMB);
   digitalWrite(A0, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A3, HIGH);
}
  void Derecha()
{
   digitalWrite(IN1, HIGH);
   digitalWrite(IN2, LOW);
   analogWrite(ENA, velMA);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, HIGH);
   analogWrite(ENB, velMB);
   digitalWrite(A0, HIGH);
   digitalWrite(A2, HIGH);
   digitalWrite(A1, HIGH);
   digitalWrite(A3, HIGH);  
}
  void Stop()
{
   digitalWrite(IN1,LOW);
   digitalWrite(IN2, LOW);
   //analogWrite(ENA, velMA);
   digitalWrite(IN3, LOW);
   digitalWrite(IN4, LOW);
   //analogWrite(ENB, velMB);
   digitalWrite(A0, LOW);
   digitalWrite(A2, LOW);
   digitalWrite(A1, LOW);
   digitalWrite(A3, LOW);    
}

  