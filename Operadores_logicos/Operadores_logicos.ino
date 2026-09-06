void setup() {
  Serial.begin(9600);
  int led1 = 9;
  int led2 = 10;
  int x = 5;
  int y = 2;
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(100);
if (x > 0 && x < 10) {
  digitalWrite(led1, HIGH);
    
}

}

void loop() {
  

}



if(condición){
  instrucciones si es verdadero;

}
else{
  instrucciones si es falso;
}


if(condición){
  instrucciones si esta condición es verdadera;
}
else if{
  instrucciones se esta condición es verdadera;
}
else{
  instrucciones si ninguna condición es verdadera;
}



