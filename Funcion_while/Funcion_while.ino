//La funcionwhile() ejecuta intrucciones mientras la condición sea verdadera.
int ledRojo = 9;
int ledVerde = 10;

void parpadeoRojo(){
  analogWrite(ledRojo, 255);
  delay(200);
  analogWrite(ledRojo, 0);
  delay(200);
}
void parpadeoVerde(){
  analogWrite(ledVerde, 255);
  delay(200);
  analogWrite(ledVerde, 0);
  delay(200);
}

void setup() {
  Serial.begin(9600);
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  analogWrite(ledRojo, 0);
  analogWrite(ledVerde, 0);
  int x = -1;
  delay(200);

  while(x < 2){       //Mientras la condición se cumpla en (), se va a ejecutar la intrucción en {}.
    Serial.println("Dentro del while");
    parpadeoRojo();
    Serial.print("El valor de x es: ");
    Serial.println(x);
    delay(100);
    x++;
    delay(200);


  }
  Serial.println("Fuera del while");  //Si la función while es falsa pasa esta parte del código.
  parpadeoVerde();
  analogWrite(ledVerde, 255);
  Serial.print("El valor de x es: ");
  Serial.println(x);
  delay(1000);
  analogWrite(ledRojo, 0);


}

void loop() {
  // put your main code here, to run repeatedly:

}
