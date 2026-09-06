int Rojo=11;
int Verde=10;
int Azul=9;

void PrenderRojo(brillo){
  

}


void setup() {
  // Definimos los pines como salida o entrada:
  pinMode (Rojo, OUTPUT);
  pinMode (Verde, OUTPUT);
  pinMode (Azul, OUTPUT);
  delay(1000);
  analogWrite (Rojo, 0);
  analogWrite (Verde, 0);
  analogWrite (Azul, 0);
  delay(1000);

}

void loop() {
  // Encendemos y apagamos los colores primarios y secundarios:
  
  /*//Rojo:
  analogWrite(Rojo, 255);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
  delay(1000);
  //Verde:
  analogWrite(Rojo, 0);
  analogWrite(Verde, 255);
  analogWrite(Azul, 0);
  delay(1000);
  //Azul:
  analogWrite(Rojo, 0);
  analogWrite(Verde, 0);
  analogWrite(Azul, 255);
  delay(1000);

/*
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
*/  
//Rojo :
  analogWrite(Rojo, 255);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
  delay(1000);
  analogWrite(Rojo, 100);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
  delay(1000);
  analogWrite(Rojo, 50);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
  delay(1000);
  analogWrite(Rojo, 25);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
  delay(1000);
  ApagarTodos();
  delay(1000);
  PrenderTodos();
  delay(1000);

}

void ApagarTodos(){
  analogWrite(Rojo, 0);
  analogWrite(Verde, 0);
  analogWrite(Azul, 0);
}

void PrenderTodos(){
  analogWrite(Rojo, 255);
  analogWrite(Verde, 255);
  analogWrite(Azul, 255);
}

