#ifndef ANIMATIONS_H
#define ANIMATIONS_H

typedef enum _state
{
  SEQ1 = 1,
  SEQ2,
  SEQ3,
  SEQ4,
} state;

#include "gpio.h"
#include "uart.h"
#include "timer.h"
#include "irq_handler.h"

void ledOff(gpioMod mod, ucPinNumber pin);
void ledOn(gpioMod mod, ucPinNumber pin);
void anim_1(unsigned int *op);
void anim_2(unsigned int *op);
void animOff(unsigned int *op);
#endif
