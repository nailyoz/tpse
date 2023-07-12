#include "bbb_regs.h"
#include "gpio.h"
#include "timer.h"
#include "animations.h"
#include "irq_handler.h"
#include "uart.h"

#define NUM_INTERRUPTS (128u)


#define REG_BIT_MASK (0x1F)

unsigned int getIntcMirClear(unsigned int iqrNum)
{
  unsigned int module = iqrNum >> 5;

  return SOC_AINTC_REGS + INTC_MIR_CLEAR(module);
}

void configureMirClear(unsigned int iqrNum)
{
  unsigned int mir_clear_addr = getIntcMirClear(iqrNum);
  HWREG(mir_clear_addr) |= 1 << (iqrNum & REG_BIT_MASK);
}

InterruptFunction fnRAMVectors[NUM_INTERRUPTS];

static void IntDefaultHandler(void)
{
  /* Go Back. Nothing to be done */
  ;
}

void AddIrq(unsigned char irqNum, InterruptFunction function)
{
  if (irqNum > 0)
  {
    fnRAMVectors[irqNum] = function;
  }
}

void ResetIrq(unsigned char irqNum)
{
  if (irqNum > 0)
  {
    fnRAMVectors[irqNum] = IntDefaultHandler;
  }
}

void IrqInit()
{
  for (int i = 0; i < NUM_INTERRUPTS; i++)
  {
    fnRAMVectors[i] = IntDefaultHandler;
  }
}

void printb(unsigned int num)
{
  for (int i = 32 - 1; i >= 0; i--)
  {
    if ((num >> i) & 1)
      uartPutC(UART0, '1');
    else
      uartPutC(UART0, '0');
  }
}

void IrqGlobalHandler(void)
{
  unsigned int irq_number = HWREG(BBB_INTC_SIR_IRQ) & 0x7f;
  // uartPutString(UART0, "IRQ:", 4);
  // printb(irq_number);
  // uartPutString(UART0, "\r\n", 2);
  fnRAMVectors[irq_number]();
  HWREG(BBB_INTC_CONTROL) = 0x1;
}