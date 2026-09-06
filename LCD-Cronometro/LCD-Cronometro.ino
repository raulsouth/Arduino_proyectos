//Cuenta regresiva simple que inicia con pulsador.

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int mininit = 2;
int minute;
int second;
bool condboton1;
int t = 500;//Lo que dura un segundo, para probar el programa se disminuye

//Pines para los botones
int boton1 = 2;
int boton2 = 3;
int boton3 = 4;

//Estados de los botones
int estadoboton1 = 0;
int estadoboton2 = 0;
int estadoboton3 = 0;

LiquidCrystal_I2C pantalla(0x27, 16,2);

void setup() {
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(boton3, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
 
  pantalla.begin(16,2);
  pantalla.clear();
  //pantalla.cursor();
  pantalla.backlight();
  pantalla.setCursor(0, 0);
  pantalla.print("Cronometro");
  delay(2000);
  pantalla.clear();

  pantalla.setCursor(1,0);
  pantalla.print(mininit);
  pantalla.setCursor(2,0);
  pantalla.print(":");
  pantalla.setCursor(3,0);
  pantalla.print("0");
  
  delay(2000);

  pantalla.clear();
  
  //delay(1000);

}

void loop() {
  minute = mininit;
  pantalla.setCursor(1,0);
  pantalla.print(mininit);
  pantalla.setCursor(2,0);
  pantalla.print(":");
  pantalla.setCursor(3,0);
  pantalla.print("0");

  estadoboton1 = digitalRead(boton1);
  estadoboton2 = digitalRead(boton2);
  
  if (estadoboton1 == 0) {
    minute--;
    second = 60;
    //bool condw = false;
    while (second > 0) {
      second--;
      pantalla.setCursor(1,0);
      pantalla.print(minute);
      pantalla.setCursor(2,0);
      pantalla.print(":");
      pantalla.setCursor(3,0);
      pantalla.print(second);
      delay(t);
      pantalla.clear();
      if (second == 0) {
        minute--;
        second = 60;
      }
      if (minute < 0) {
      second = 0;
      minute = 0;
      }
      
      }
      
  pantalla.clear();
  digitalWrite(13, HIGH);
  pantalla.setCursor(1, 0);
  pantalla.print("Tiempo!!");

  delay(2000);
  pantalla.clear();
          
  }
  
}