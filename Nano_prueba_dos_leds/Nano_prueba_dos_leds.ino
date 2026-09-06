#include <SoftwareSerial.h>
int led1 = 10;
int led2 = 11;
int t = 200;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);


}

void loop() {
  Serial.println(led1);
  Serial.println(led2);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(t);
  Serial.println();
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(t);

}
