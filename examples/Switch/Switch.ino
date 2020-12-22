#include "switch.h"
#include "Arduino.h"

int pin = 2;

Switch on_off;

void On(int par) {
	Serial.print("On par ");
	Serial.print(par);
	Serial.print("!\n");
}

void Off(){
	Serial.print ("Off\n");
}


void setup()
{
	int par = 123;
	on_off.setupUsingDigitalPin(pin);
	on_off.setupClickHandler( [pax=par](){ On(pax);} );
	on_off.setupHoldHandler(Off);
	Serial.begin(9600);
}

void loop()
{
	on_off.update();
}

