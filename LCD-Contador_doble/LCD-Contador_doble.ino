#include <Wire.h>
#include <LiquidCrystal_I2C.h>

long num1 = 0;
long num2 = 0;
//Pines para los botones
int botonA1 = 2;
int botonB1 = 3;
int botonA2 = 4;
int botonB2 = 5;
int botonreset = 6;
//Estados de los botones
int estadobotonA1 = 0;
int estadobotonB1 = 0;
int estadobotonA2 = 0;
int estadobotonB2 = 0;



LiquidCrystal_I2C pantalla(0x27, 16,2);


void setup() {
  pinMode(botonA1, INPUT_PULLUP);
  pinMode(botonB1, INPUT_PULLUP);
  pinMode(botonA2, INPUT_PULLUP);
  pinMode(botonB2, INPUT_PULLUP);
  pinMode(botonreset, INPUT_PULLUP);




  pantalla.begin(16,2);
  pantalla.clear();
  //pantalla.cursor();
  pantalla.backlight();
  pantalla.setCursor(0, 0);
  pantalla.print("Contador");
  delay(2000);
  pantalla.clear();
  
  delay(1000);

}

void loop() {
  pantalla.setCursor(0,0);
  pantalla.print("Equipo1");
  pantalla.setCursor(9, 0);
  pantalla.print("Equipo2");
  pantalla.setCursor(2, 1);
  pantalla.print(num1);
  pantalla.setCursor(11, 1);
  pantalla.print(num2);

  estadobotonA1 = digitalRead(botonA1);
  estadobotonB1 = digitalRead(botonB1);
  estadobotonA2 = digitalRead(botonA2);
  estadobotonB2 = digitalRead(botonB2);
  if (estadobotonA1 == LOW) {
  num1++;
  delay(100);
  }
  if (estadobotonB1 == LOW) {
  num1--;
  delay(100);
  }

  if (estadobotonA2 == LOW) {
  num2++;
  delay(100);
  }
  if (estadobotonB2 == LOW) {
  num2--;
  delay(100);
  }
  
  //Condición de límite; los números no  pueden bajar de 0
  if (num1 < 0) {
    num1 = 0;
  }
  if (num2 < 0) {
    num2 = 0;
  }

  delay(200);
  pantalla.clear();


  //Volver a cero el contador
  int estadobotonreset = digitalRead(botonreset);
  if (estadobotonreset == LOW) {
  num1 = 0;
  num2 = 0;
  }

  

}
