/*Prueba para la secuencia de 2 leds
  realizado para Arduino Uno.*/

int LED1 = 8;
int LED2 = 9;
void setup() {
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);

  apagarLed();
  delay(5000);

}

void loop() {
  encendidoApagado();
  encendidoApagado();
  delay(200);

  apagarLed();

  delay(1000);

  parpadearLed();
  parpadearLed();
  delay(200);
  apagarLed();
  delay(1000);

   
  parpadearLed1();
  delay(200);
  parpadearLed2();
  delay(200);

}

void encendidoApagado(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(1000);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(1000);
}

void apagarLed(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void parpadearLed(){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  delay(200);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  delay(200);
}

void parpadearLed1(){
  digitalWrite(LED1, LOW);
  delay(200);
  digitalWrite(LED1, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  delay(200);
}

void parpadearLed2(){
  digitalWrite(LED2, LOW);
  delay(200);
  digitalWrite(LED2, HIGH);
  delay(200);
  digitalWrite(LED2, LOW);
  delay(200);
}
