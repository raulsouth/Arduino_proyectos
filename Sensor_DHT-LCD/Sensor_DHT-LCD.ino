//Programa para medir la temperatura y la humedad de un ambiente
//que se muestra en una pantalla lcd 16x2 I2C.
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int SENSOR = 8;
float TEMPERATURA;
float HUMEDAD;


DHT dht (SENSOR, DHT11);


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando jeje");
  dht.begin();

  delay(3000);
  lcd.clear();

}

void loop() {
  TEMPERATURA = dht.readTemperature();
  HUMEDAD = dht.readHumidity();

  //Serial.println(TEMPERATURA);
  //Serial.println(HUMEDAD);
  delay(1000);
  lcd.clear();

  if (TEMPERATURA > 20 && HUMEDAD > 60){
    Serial.println("T: mas de 20");
    Serial.println("H: mas de 60");
    lcd.setCursor(0,0);
    lcd.print("T: mas de 20");
    lcd.setCursor(0,1);
    lcd.print("H: mas de 60");
    //lcd.clear();

  }
  else {
    Serial.println("Temp: "+String(TEMPERATURA)+"°C");
    Serial.println("H: "+String(HUMEDAD)+"%");

    lcd.setCursor(0,0);
    lcd.print("Temp: "+ String(TEMPERATURA)+"*C");
    //lcd.setCursor(9, 0);
    //lcd.print(TEMPERATURA);

    lcd.setCursor(0,1);
    lcd.print("Humedad: "+ String(HUMEDAD)+"%");
    //lcd.setCursor(9, 1);
    //lcd.print(HUMEDAD);
  
}

 
  

}