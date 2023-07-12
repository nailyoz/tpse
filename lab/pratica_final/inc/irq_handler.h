#ifndef IRQ_HANDLER_H
#define IRQ_HANDLER_H

#include "hw_intc.h"
#include "hw_types.h"
#include "gpio.h"
#include "soc_AM335x.h"
#include "uart.h"

#define GPIOINT2A 32
#define GPIOINT1A 98
#define DEBOUNCING_TIME 0xFF
typedef void (*InterruptFunction)(void);

void AddIrq(unsigned char irqNum, InterruptFunction function);
void ResetIrq(unsigned char irqNum);


void InitIrq(void);
unsigned int getIntcMirClear(unsigned int iqrNum);
void configureMirClear(unsigned int iqrNum);
#endif
