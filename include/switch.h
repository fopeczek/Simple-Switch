#pragma once
#include "function_objects.h"

void nofun();

class Switch {
public:
	Switch() : m_pin(-1), m_analog_pin(false), m_event_on(nofun), m_event_off(nofun) {} // @suppress("Class members should be properly initialized")
	void update();
	void setupUsingDigitalPin(int pin);
	void setupUsingAnalogPin(int pin);
	void setupClickHandler(FunctionObject<void(void)> event_on);
	void setupHoldHandler(FunctionObject<void(void)> event_off);

private:
	int m_pin;
	bool m_analog_pin=false;

	FunctionObject<void(void)> m_event_on;
	FunctionObject<void(void)> m_event_off;
};

