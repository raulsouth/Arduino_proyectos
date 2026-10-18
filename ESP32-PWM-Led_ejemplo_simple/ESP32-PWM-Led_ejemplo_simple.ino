
const int led1 = 12;

void setup() {
  pinMode(led1, OUTPUT);
  // Configuramos el pin para PWM
  // Parámetros: LedcAttachChannel(pin, frecuencia_Hz, resolution_bits, canal).
  // Usamos una frecuenciai estándar de 5000Hz y una resolución de 12 bits.
  ledcAttachChannel(led1, 5000, 12, 0);

}

void loop() {
  // Como la resolución es de 12 bits, 2^12 = 4096, 
  // entonces el PWM puede tener valores dessde 0 a 4095.
  // Aumentamos el brillo de 0 a 4095
  for (int brillo = 0; brillo <= 4045; brillo++) {
    ledcWrite(led1, brillo);
    delay(1);
  }

  // Disminuimos el brillo de 4095 a 0
  for (int brillo = 4095; brillo >= 0; brillo--) {
    ledcWrite(led1, brillo);
    delay(1);
  }

  

}
