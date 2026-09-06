int num1 = 2;
int num2 = 3;

void setup() {
  

}

void loop() {
 for (num1 = 0; condition; inc-expression) {
 parpadeo();
 delay(1000);
 }
wil

}

void parpadeo() {
  Serial.println("Parpadea led1");
  digitalWrite(led1, HIGH);
  delay(t1);
  digitalWrite(led1, LOW);
  delay(t1);
  digitalWrite(led1, HIGH);
  delay(t1);
  digitalWrite(led1, LOW);
  delay(t1);
}