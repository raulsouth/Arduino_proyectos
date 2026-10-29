#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); // RX (Pin 2) -> TX del HC-05, TX (Pin 3) -> RX del HC-05

void setup() {
  Serial.begin(115200); // Monitor Serie de la PC
  BT.begin(38400);      // Baudios del HC-05
  Serial.println("--- MODO ECO ACTIVADO ---");
}

void loop() {
  // Si entra un byte por el Bluetooth, mándalo idéntico a la PC
  if (BT.available()) {
    Serial.write(BT.read());
  }
}
