unsigned long tiempoactual = 0;
int second = 0;
int minute = 0;
int hour = 0;

void setup() {
  Serial.begin(9600);
  

}

void loop() {
  if (millis() >= tiempoactual + 1000){
    tiempoactual = millis();
    
    second++;
    if (second == 60){
      second = 0;
      minute++;
  }

  if (minute == 60){
    minute = 0;
    hour++;
  }

  if (hour == 24){
    hour = 0;
  }

  Serial.print(hour);
  Serial.print(":");

  Serial.print(minute);
  Serial.print(":");

  Serial.println(second);



    
  }

  

  

}
