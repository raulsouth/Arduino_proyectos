
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned long tiempoAnterior = 0; //guarda el último momoento en el que 
                             // se actualizó el temporizador.
unsigned long tiempoObjetivo = 200000; //tiempo deseado en ms.
unsigned long tiempoRestante = tiempoObjetivo; //para la cuenta regresiva.

unsigned long minInit = tiempoObjetivo/1000;

//Pines para los botones.
int boton1 = 2;
int boton2 = 3; 

//Estado de los botones.
int estadoboton1 = 0;
int estadobotn2 = 0;

LiquidCrystal_I2C pantalla(0x27, 16, 2);

void setup() {
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);

  pantalla.begin(16,2);
  pantalla.clear();
  pantalla.backlight();
  pantalla.setCursor(0, 0);
  pantalla.print("Cronometro");
  delay(2000);
  pantalla.clear();

  pantalla.setCursor(1, 0);
  pantalla.print(minInit);
  pantalla.setCursor(2, 0);
  pantalla.print(":");
  pantalla.setCursor(3, 0);
  pantalla.print("0");
  delay(2000);
  pantalla.clear();


}

void loop() {
  unsigned long tiempoActual = millis();
  unsigned long second = tiempoActual/1000;
  
  pantalla.setCursor(0, 0);
  pantalla.print(second);


}
