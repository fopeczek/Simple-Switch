#include "Arduino.h"
#include "switch.h"

void Switch::update() {

	bool read;
	if(m_analog_pin) {
		int i_read=analogRead(m_pin);
		read=i_read>511;
	} else {
		read=digitalRead(m_pin);
	}
}

void Switch::setupUsingDigitalPin(int pin) {
	m_pin = pin;
	pinMode(pin,INPUT);
	m_analog_pin = false;
}

void Switch::setupUsingAnalogPin(int pin) {
	m_pin = pin;
	pinMode(pin,INPUT);
	m_analog_pin = true;
}

void Switch::setupTurnOnHandler(FunctionObject<void(void)> event_on) {
	m_event_on = event_on;
}

void Switch::setupTurnOffHandler(FunctionObject<void(void)> event_off) {
	m_event_off = event_off;
}

void nofun() {}
