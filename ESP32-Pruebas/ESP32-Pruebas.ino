int led = 2;
int time1 = 200;
void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

}

void loop() {
  Serial.println("Led parpadeando");
  digitalWrite(led, HIGH);
  delay(time1);
  digitalWrite(led, LOW);
  delay(time1);

}
