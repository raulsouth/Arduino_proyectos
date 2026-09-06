

int IN1 = 8;
int IN2 = 9;
int IN3 = 10; 
int IN4 = 11;
int demora = 20; //Demora entre pasos; no debe ser menor a 10 ms.

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  for (int i = 0; i < 512; i++){  // 512 * 4 = 2048 pasos.
  digitalWrite(IN1, HIGH); // Paso 1
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
  delay(demora);

  digitalWrite(IN1, LOW); // Paso 2
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
  delay(demora);

  digitalWrite(IN1, LOW); // Paso 3
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
  delay(demora);

  digitalWrite(IN1, LOW); // Paso 4
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);  
  delay(demora);

  }

  digitalWrite(IN1, LOW); // Detiene por 5 s.
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);  
  delay(5000);

}

