int LDR = 0;  // Pin analógico A0
int intensidadLuz = 0;  // Variable donde se almacena lo que lee el pin analógico
int led1 = 9;
int led2 = 10;
void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  intensidadLuz = analogRead(LDR);
  Serial.println(intensidadLuz);
  delay(200);
  if (intensidadLuz > 500) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  }
  else {
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  }
  

}
