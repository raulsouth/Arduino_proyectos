void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println();
  Serial.print("Modelo del Chip: ");
  Serial.println(ESP.getChipModel());
  Serial.print("Revisión del Chip: ");
  Serial.println(ESP.getChipRevision());
  Serial.print("Cantidad de núcleos: ");
  Serial.println(ESP.getChipCores());
}

void loop() {}