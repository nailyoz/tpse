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
    if (irqCode == 32){
        GPIO1_Irq();
	}
    HWREG(INTC_CONTROL) = 0x1000;
}

//GPIO MODULE 1 interruptions
void GPIO2_Irq(void){
	if(gpioCheckValue(GPIO1,18)){
			HWREG(GPIO_IRQSTATUS_SET_0) = 1 << 18;
			    ledOn(GPIO1, 21);
				ledOn(GPIO1, 22);
				ledOn(GPIO1, 23);
				ledOn(GPIO1, 24);
	
	}
	if(gpioCheckValue(GPIO1, 28) && gpioCheckValue(GPIO1,18) ){
		ledSnake();
	}
	else{
		ledOff(GPIO1, 21);
		ledOff(GPIO1, 22);
		ledOff(GPIO1, 23);
		ledOff(GPIO1, 24);
	}
}