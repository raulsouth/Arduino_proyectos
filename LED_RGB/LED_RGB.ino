int Rojo=11;
int Verde=10;
int Azul=9;
void setup() {
  // Definimos los pines como salida o entrada:
  pinMode (Rojo, OUTPUT);
  pinMode (Verde, OUTPUT);
  pinMode (Azul, OUTPUT);
  delay(1000);
  digitalWrite (Rojo, LOW);
  digitalWrite (Verde, LOW);
  digitalWrite (Azul, LOW);
  delay(1000);

}

void loop() {
  // Encendemos y apagamos los colores primarios y secundarios:
  /*
  //Rojo:
  digitalWrite(Rojo, HIGH);
  digitalWrite(Verde, LOW);
  digitalWrite(Azul, LOW);
  delay(1000);
  //Verde:
  digitalWrite(Rojo, LOW);
  digitalWrite(Verde, HIGH);
  digitalWrite(Azul, LOW);
  delay(1000);
  //Azul:
  digitalWrite(Rojo, LOW);
  digitalWrite(Verde, LOW);
  digitalWrite(Azul, HIGH);
  delay(1000);
*/
  //Amarillo:
  digitalWrite(Rojo, HIGH);
  digitalWrite(Verde, HIGH);
  digitalWrite(Azul, LOW);
  delay(1000);
  //Rojo
  digitalWrite(Rojo, HIGH);
  digitalWrite(Verde, LOW);
  digitalWrite(Azul, LOW);
  delay(1000);
  //Verde:
  digitalWrite(Rojo, LOW);
  digitalWrite(Verde, HIGH);
  digitalWrite(Azul, LOW);
  delay(1000);

}
