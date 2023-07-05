#include "led.h"

void ledOn(int mod, int pin){
    gpioSetPinValue(mod, pin, HIGH);
}
void ledOff(int mod, int pin){
    gpioSetPinValue(mod, pin, LOW);

}

void ledBlink(int mod, int pin){
    ledOn(mod, pin, HIGH);
	Delay(500);
    ledOff(mod, pin, LOW);
    Delay(500);
}

void ledSnakes(){
    ledOn(GPIO1, 21);
	Delay(500);
    ledOff(GPIO1, 21);
	ledOn(GPIO1, 22);
	Delay(500);
    ledOff(GPIO1, 22);
	ledOn(GPIO1, 23);
	Delay(500);
    ledOff(GPIO1, 23);
	ledOn(GPIO1, 24);
	Delay(500);	
}