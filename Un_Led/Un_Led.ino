int Led1=7;  
int Tiempo=200;
void setup() {
  pinMode (Led1, OUTPUT);
  digitalWrite(Led1, LOW);
  delay(500);
}

void loop() {
  digitalWrite(Led1, HIGH);
  delay(Tiempo);
  digitalWrite(Led1, LOW);
  delay(Tiempo);
}
