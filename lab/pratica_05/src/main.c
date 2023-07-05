/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include "uart.h"
#include "timer.h"
#include "watchdog.h"
#include "gpio.h"
#include "irq_handle.h"
#include "led.h"
/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	//bttn flags
	unsigned char botaoUm=0; 
	unsigned char botaoDois=0;

int main(void){
	disableWtd();
	//Module 01 led 1
	gpioInitModule(GPIO1);
	gpioPinMuxSetup(GPIO1, 21);
	gpioSetDirection(GPIO1, 21, OUTPUT);
	//led 2
	gpioPinMuxSetup(GPIO1, 22);
	gpioSetDirection(GPIO1, 22, OUTPUT);
	//led 3
	gpioPinMuxSetup(GPIO1, 23);
	gpioSetDirection(GPIO1, 23, OUTPUT);
	// led 4
	gpioPinMuxSetup(GPIO1, 24);
	gpioSetDirection(GPIO1, 24, OUTPUT);

	//Module 02 botao 1
	gpioInitModule(GPIO2);
	gpioPinMuxSetup(GPIO2, 18);
	//gpio02_1
	gpioSetDirection(GPIO2, 18, INPUT);
	// 02 2GPIO2_24 lcdpclk botao 2
	gpioPinMuxSetup(GPIO2, 28);
	gpioSetDirection(GPIO2, 28, INPUT);

	//IRQ
	setMirClear(GPIOINT2A);
	setIrqPin(2,18);
	setIrqPin(2,28);
	/*-----------------------------------------------------------------------------
	 *  initialize UART modules
	 *-----------------------------------------------------------------------------*/
	uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);
	
	/*-----------------------------------------------------------------------------
	 *  initialize TIMER modules
	 *-----------------------------------------------------------------------------*/
    DMTimerSetUp();

  	while(true){

		if(botaoUm==1){
			if(botaoDois==2){
				gpioSetPinValue(GPIO1, 21, HIGH);
				Delay(500);
				gpioSetPinValue(GPIO1, 22, HIGH);
				Delay(500);
				gpioSetPinValue(GPIO1, 23, HIGH);
				Delay(500);
				gpioSetPinValue(GPIO1, 24, HIGH);
				Delay(500);	
			}else{
				gpioSetPinValue(GPIO1, 21, HIGH);
				gpioSetPinValue(GPIO1, 22, HIGH);
				gpioSetPinValue(GPIO1, 23, HIGH);
				gpioSetPinValue(GPIO1, 24, HIGH);
				}
		}
		else{
			gpioSetPinValue(GPIO1, 21, LOW);
			gpioSetPinValue(GPIO1, 22, LOW);
			gpioSetPinValue(GPIO1, 23, LOW);
			gpioSetPinValue(GPIO1, 24, LOW);
		}
		Delay(500);
	}
	uartPutString(UART0,"OK...",5);

	return(0);
} /* ----------  end of function main  ---------- */


