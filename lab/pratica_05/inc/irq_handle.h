#ifndef IRQ_HANDLE_H
#define IRQ_HANDLE_H


#include "hw_types.h"
#include "gpio.h"
#include "soc_AM335x.h"
#include "uart.h"
#include "bbb_regs.h"

#define REG_BIT_MASK (0x1f)
#define GPIOINT2A  (32)

int getModMirClear(unsigned int irqCode);
void setMirClear(unsigned int irqCode);

void setIrqPin(gpioMod mod, ucPinNumber pin);
void ISR_Handler(void);
void gpioIrq(void);

#endif