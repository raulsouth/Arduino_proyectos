void setup() {
  Serial.begin(9600);

  for (int i = 2; i >= 2 & i <= 13; i++ ){
    pinMode(i, OUTPUT);
  }
  

}

void loop() {
  for (int i = 2; i >= 2 & i <=13; i++){
    Serial.println("Pin "+String(i));
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
    delay(100);

  }
  delay(200);
  

}
