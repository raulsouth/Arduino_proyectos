int color= 0;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT); // rojo
  pinMode(9, OUTPUT); // verde
  pinMode(10, OUTPUT);// azul

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  

}

void loop() {
Serial.println(color);


color++;
delay(1000);
  if (color > 4) {
    color = 0;
    delay(1000);

  }

  if (color == 0) {
    digitalWrite(8, LOW); //apagados
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    
  }
  if (color == 1) {
    digitalWrite(8, HIGH);  //rojo
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
  if (color == 2) {
    digitalWrite(8, LOW);  //verde
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  if (color == 3) {
    digitalWrite(8, LOW);  //azul
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  }
  if (color == 4) {
    digitalWrite(8, HIGH);  //blanco
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
  }

  




}
