#ifndef LED_H
#define LED_H

#include "gpio.h"
#include "timer.h"

void ledBlink(int mod, int pin);
void ledOn(int mod, int pin);
void ledOff(int mod, int pin);
void ledSnakes();

tBoolean flagGPIO= true;

#endif