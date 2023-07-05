#include "irq_handle.h"
#include "led.h"
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
		case 0:
			return; 
			break;
		case 1:
			HWREG(SOC_GPIO_1_REGS + GPIO1_IRQSTATUS_SET_0) |= 1 << pin;
			HWREG(SOC_GPIO_1_REGS + GPIO1_RISINGDETECT) |= 1 << pin;
			break;
		case 2:
			HWREG(SOC_GPIO_2_REGS + GPIO_IRQSTATUS_SET_0) |= 1 << pin;
			HWREG(SOC_GPIO_2_REGS + GPIO_RISINGDETECT) |= 1 << pin;
			break;
		default:
			break;
		}
	}
}

void irq_handler(void){
    unsigned int irqCode = HWREG(INTC_SIR_IRQ) & 0x7f;
    if (irqCode == 98){
        GPIO1_Irq();
	}
    HWREG(INTC_CONTROL) = 0x1000;
	flagGPIO = true;
}

//GPIO MODULE 1 interruptions
void GPIO1_Irq(void){
	HWREG(GPIO1_IRQSTATUS_SET_0) = 1 << 28;
	ledSnakes();
}