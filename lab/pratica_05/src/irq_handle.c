#include "irq_handle.h"

//setting MirClear
unsigned int getModMirClear(unsigned int irqCode){
    unsigned int module = irqCode >> 5;
    
    return SOC_AINTC_REGS + INTC_MIR_CLEAR(module);
}

void setMirClear(unsigned int irqCode){
    unsigned int mir_clear = getModMirClear(irqCode);
    HWREG(mir_clear) |= 1 << (irqCode & REG_BIT_MASK);
}


void setIrqPin(gpioMod mod, ucPinNumber pin){
	if (gpioCheckValidPortPin(mod, pin)){
		switch (mod){
		case GPIO0:
			return; 
			break;
		case GPIO1:
			HWREG(SOC_GPIO_1_REGS + GPIO_IRQSTATUS_SET_0) |= 1 << pin;
			HWREG(SOC_GPIO_1_REGS + GPIO_RISINGDETECT) |= 1 << pin;
			break;
		case GPIO2:
			HWREG(SOC_GPIO_2_REGS + GPIO_IRQSTATUS_SET_0) |= 1 << pin;
			HWREG(SOC_GPIO_2_REGS + GPIO_RISINGDETECT) |= 1 << pin;
			break;
		default:
			break;
		}
	}
}


void irqHandler(void){
    unsigned int irqCode = HWREG(INTC_SIR_IRQ) & 0x7f;
    if (irqCode == 98){
        gpioIrq();
	}
    HWREG(INTC_CONTROL) = 0x1;
}

//interruptions
void gpioIrq(void){
	HWREG(GPIO1_IRQSTATUS_0) = 1 << 28;
}