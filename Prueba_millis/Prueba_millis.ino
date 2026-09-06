void setup() {
  Serial.begin(9600);
  Serial.println(millis());
  pinMode(8, OUTPUT);
  digitalWrite(8, 1);
  digitalWrite(8, 0);
  Serial.println(millis());



}

void loop() {
  

}
