#pragma once
#include "function_objects.h"

void tmpfun();

class Switch {
public:
	Switch() : m_pin(-1), m_analog_pin(false), m_event_on(tmpfun), m_event_off(tmpfun) {} // @suppress("Class members should be properly initialized")
	void update();
	void setupUsingDigitalPin(int pin);
	void setupUsingAnalogPin(int pin);
	void setupTurnOnHandler(FunctionObject<void(void)> event_on);
	void setupTurnOffHandler(FunctionObject<void(void)> event_off);

private:
	int m_pin;
	bool m_analog_pin=false;

	bool m_last_read;

	FunctionObject<void(void)> m_event_on;
	FunctionObject<void(void)> m_event_off;
};


