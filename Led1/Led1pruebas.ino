void setup()
{
  	pinMode(7, OUTPUT);
	pinMode(8, OUTPUT);

	digitalWrite(7, LOW);
	digitalWrite(8, LOW);
	delay(1000);

}


void loop()
{

  	while (false) {
  		digitalWrite(7, HIGH);
  		digitalWrite(8, HIGH);
  		delay(1000);
  		digitalWrite(7, LOW);
  		digitalWrite(8, LOW);
  		delay(1000);
  		digitalWrite(7, HIGH);
  		delay(500);
  		digitalWrite(7, LOW);
  		delay(1000);
  		digitalWrite(8, HIGH);
  		delay(500);
  		digitalWrite(8, LOW);
  		delay(1000);
  	}

}