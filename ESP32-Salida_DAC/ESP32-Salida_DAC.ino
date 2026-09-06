//Efecto respiración
//Uso de la salida DAC para controlar le intensidad de un led.
//Usando el conversor digital analógico controlamos la cantidad de 
//energía que se envíaa un led para tener un efecto similar al de
//la salida PWM.

void setup() {
Serial.begin(9600);
  

}

void loop() {
  for(int i = 100; i < 255; i++){
    Serial.print("Sube -->");
    Serial.println(i);
    dacWrite(25, i);
    delay(10);
  }

  delay(50);

  for(int i = 255; i > 100; i--){
    Serial.print("Baja -->");
    Serial.println(i);
    dacWrite(25, i);
    delay(10);
  }

}
