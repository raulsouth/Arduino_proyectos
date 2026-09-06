int LDR = 0;  // Pin analógico A0
long intensidadLuz = 0;  // Variable donde se almacena lo que lee el pin analógico
int led1 = 9;
int led2 = 10;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  intensidadLuz = analogRead(LDR);
  Serial.print("La intensidad es: ");
  Serial.println(intensidadLuz);

  int conversion = intensidadLuz * 255/1000;
  
  if (conversion > 255) {
  conversion = 255;
  Serial.println("El conversión corregida es:" + String(conversion));

}
  int PWM = 255 - conversion;
  analogWrite(led1, conversion);
  Serial.println("La conversión es: " + String(conversion));
  Serial.println("PWM: " + String (PWM));
  analogWrite(led1, PWM);
  delay(1000);

  
  

}
