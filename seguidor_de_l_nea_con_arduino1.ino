// C++ code
//
int izq_digital = 0;

int der_digital = 0;

int der_analogica = 0;

int izq_analogica = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  izq_digital = 0;
  der_digital = 0;
  izq_analogica = 0;
  der_analogica = 0;
}

void loop()
{
  izq_analogica = analogRead(A0);
  der_analogica = analogRead(A1);
  if (izq_analogica >= 75) {
    izq_digital = 1;
  } else {
    izq_digital = 0;
  }
  if (der_analogica >= 75) {
    der_digital = 1;
  } else {
    der_digital = 0;
  }
  Serial.print("sensor izq analogico: ");
  Serial.print(izq_analogica);
  Serial.print("; sensor der analogico: ");
  Serial.println(der_analogica);
  delay(1000); // Wait for 1000 millisecond(s)
  Serial.print("sensor izq digital: ");
  Serial.print(izq_digital);
  Serial.print("; sensor der digital: ");
  Serial.println(der_digital);
  delay(1000); // Wait for 1000 millisecond(s)
  if (izq_digital == 0 && der_digital == 0) {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("Adelante");
  }
  if (izq_digital == 0 && der_digital == 1) {
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    Serial.println("derecha");
  }
  if (izq_digital == 1 && der_digital == 0) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    Serial.println("izquierda");
  }
  if (izq_digital == 1 && der_digital == 1) {
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    Serial.println("detenerse");
  }
}