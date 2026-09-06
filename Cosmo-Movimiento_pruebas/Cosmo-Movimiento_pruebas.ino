
int motorIzPWM = 6;
int motorIzDir = 7;
int motorDePWM = 8;
int motorDeDir = 9;

void setup() {
  pinMode(motorIzPWM, OUTPUT);
  pinMode(motorIzDir, OUTPUT);
  pinMode(motorDePWM, OUTPUT);
  pinMode(motorDeDir, OUTPUT);

}

void loop() {
  //Prueba adelante
  digitalWrite(motorIzDir, HIGH);
  digitalWrite(motorDeDir, HIGH);
  analogWrite(motorIzPWM, 200);
  analogWrite(motorDePWM, 200);
  delay(5000);
  analogWrite(motorIzPWM, 0);
  analogWrite(motorDePWM, 0);
  delay(5000);
  


}
