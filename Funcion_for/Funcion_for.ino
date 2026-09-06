int ledRojo=9;
int ledVerde=10;

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
  Serial.println("Configurando");
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  delay(1000);
  analogWrite(ledRojo, 0);
  analogWrite(ledVerde, 0);
  delay(1000);


  for(int x = 0; x < 3 ; x++){
    Serial.println("Dentro del for");
    Serial.print("El valor de x cambió a: ");
    Serial.println(x);
    parpadeoRojo();
    delay(1000);


  }
    Serial.println("Fuera del for");//Cuando ya no se cumple lo que 
    //está dentro del for pasa a esta parte del código.
    delay(500);
    parpadeoVerde();
    analogWrite(ledRojo, 0);//Se apaga ledRojo al salir del for.
    analogWrite(ledVerde, 255);//Se enciende ledVerde al salir del for.


}

void loop() {
  /*analogWrite(ledRojo, 255);
  analogWrite(ledVerde, 255);
  delay(1000);
  analogWrite(ledRojo, 100);
  analogWrite(ledVerde, 100);
  delay(1000);
  analogWrite(ledRojo, 50);
  analogWrite(ledVerde, 50);
  delay(1000);
  analogWrite(ledRojo, 25);
  analogWrite(ledVerde, 25);
  delay(1000);
  */
}
