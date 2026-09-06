void setup() {
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  Serial.println("Leds encendidos");
  delay(500);
  //digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.println("Leds apagados");
  delay(500);
  

}
