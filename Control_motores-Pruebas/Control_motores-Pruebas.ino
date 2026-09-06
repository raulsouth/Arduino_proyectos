
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 9;
int ENB = 10;
int velA;
int velB;

void setup() {
pinMode(13, OUTPUT);
digitalWrite(13, LOW);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  delay(3000);

}

void loop() {
  velA = 100;
  velB = 100;
  adelante();
  delay(2000);
  //velB = 75;
  //adelante();
  //delay(5000);
  //velB = 100;
  //adelante();
  //delay(2000);
  
  detener();
  delay(3000);
  

}

void adelante(){
  analogWrite(ENA, velA);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velB);
}

void detener(){
  //analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  //analogWrite(ENB, 0);
}
