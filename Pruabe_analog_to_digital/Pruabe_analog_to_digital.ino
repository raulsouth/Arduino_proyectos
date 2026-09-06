#include <LCDI2C_Generic.h>
#include <LCDI2C_Katakana.h>
#include <LCDI2C_Katakana_Symbols.h>
#include <LCDI2C_Katakana_Vietnamese.h>
#include <LCDI2C_Latin.h>
#include <LCDI2C_Latin_Symbols.h>
#include <LCDI2C_Latin_Vietnamese.h>
#include <LCDI2C_Multilingual.h>
#include <LCDI2C_Russian.h>
#include <LCDI2C_RussianLatin.h>
#include <LCDI2C_RussianLatin_Symbols.h>
#include <LCDI2C_RussianLatin_Vietnamese.h>
#include <LCDI2C_Russian_Symbols.h>
#include <LCDI2C_Russian_Vietnamese.h>
#include <LCDI2C_Symbols.h>
#include <LCDI2C_Vietnamese.h>

#include <LiquidCrystal.h>

#include <LiquidCrystal_

int led1 = A0;
int led2 = A1;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  //digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(500);
  //digitalWrite(led1, LOW);
  //digitalWrite(led2, LOW);
  //delay(500);

}

