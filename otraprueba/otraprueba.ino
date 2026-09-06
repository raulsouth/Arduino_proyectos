double Led1;
double Led2;
double Tiempo1;
double Tiempo2;

void fnc_dynamic_digitalWrite(int _pin, int _e){
	pinMode(_pin,OUTPUT);
	digitalWrite(_pin,_e);
}

void setup()
{


	Led1 = 7;
	Led2 = 8;
	Tiempo1 = 500;
	Tiempo2 = 100;
	delay(500);
	fnc_dynamic_digitalWrite(Led1, LOW);
	fnc_dynamic_digitalWrite(Led2, LOW);
	delay(1000);

}


void loop()
{

  	fnc_dynamic_digitalWrite(Led1, HIGH);
  	fnc_dynamic_digitalWrite(Led2, HIGH);
  	delay(Tiempo1);
  	fnc_dynamic_digitalWrite(Led1, LOW);
  	fnc_dynamic_digitalWrite(Led2, LOW);
  	delay(Tiempo1);
  	fnc_dynamic_digitalWrite(Led1, HIGH);
  	delay(Tiempo2);
  	fnc_dynamic_digitalWrite(Led1, LOW);
  	delay(Tiempo1);
  	fnc_dynamic_digitalWrite(Led2, HIGH);
  	delay(Tiempo2);
  	fnc_dynamic_digitalWrite(Led2, LOW);
  	delay(Tiempo1);
  	for (int count = 0; count < 4; count++) {
  		fnc_dynamic_digitalWrite(Led1, HIGH);
  		delay(Tiempo2);
  		fnc_dynamic_digitalWrite(Led1, LOW);
  		fnc_dynamic_digitalWrite(Led2, HIGH);
  		delay(Tiempo2);
  		fnc_dynamic_digitalWrite(Led2, LOW);
  	}
  	delay(Tiempo1);

}