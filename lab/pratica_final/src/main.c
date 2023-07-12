#include "bbb_regs.h"
#include "soc_AM335x.h"
#include "hw_intc.h"
#include "hw_types.h"
#include "irq_handler.h"
#include "timer.h"
#include "gpio.h"
#include "wdt.h"
#include "uart.h"
#include "interface.h"
#include "led_animations.h"
#include "random.h"
#include "interface.h"

void gameSetup();

static bool player1 = 0;
static bool player2 = 0;
static bool player3 = 0;
static bool player4 = 0;

static bool terminado = 0;

void updateLeds()
{
	if (player1)
		ledOn(LED_VERDE_PLAYER1_MOD, LED_VERDE_PLAYER1_PIN);
	else
		ledOff(LED_VERDE_PLAYER1_MOD, LED_VERDE_PLAYER1_PIN);

	if (player2)
		ledOn(LED_VERDE_PLAYER2_MOD, LED_VERDE_PLAYER2_PIN);
	else
		ledOff(LED_VERDE_PLAYER2_MOD, LED_VERDE_PLAYER2_PIN);

	if (player3)
		ledOn(LED_VERDE_PLAYER3_MOD, LED_VERDE_PLAYER3_PIN);
	else
		ledOff(LED_VERDE_PLAYER3_MOD, LED_VERDE_PLAYER3_PIN);

	if (player4)
		ledOn(LED_VERDE_PLAYER4_MOD, LED_VERDE_PLAYER4_PIN);
	else
		ledOff(LED_VERDE_PLAYER4_MOD, LED_VERDE_PLAYER4_PIN);

	if (terminado)
		ledOn(LED_VERMELHO_MOD, LED_VERMELHO_PIN);
	else
		ledOff(LED_VERMELHO_MOD, LED_VERMELHO_PIN);

	uartPutString(UART0, "P1:", 3);
	uartPutC(UART0, player1 ? 'Y' : 'N');
	uartPutString(UART0, "\r\n", 2);

	uartPutString(UART0, "P2:", 3);
	uartPutC(UART0, player2 ? 'Y' : 'N');
	uartPutString(UART0, "\r\n", 2);

	uartPutString(UART0, "P3:", 3);
	uartPutC(UART0, player3 ? 'Y' : 'N');
	uartPutString(UART0, "\r\n", 2);

	uartPutString(UART0, "P4:", 3);
	uartPutC(UART0, player4 ? 'Y' : 'N');
	uartPutString(UART0, "\r\n", 2);

	uartPutString(UART0, "T1:", 3);
	uartPutC(UART0, terminado ? 'Y' : 'N');
	uartPutString(UART0, "\r\n", 2);
}

void reset()
{
	player1 = false;
	player2 = false;
	player3 = false;
	player4 = false;
	terminado = false;
	updateLeds();
	gameSetup();
}

void enablePlayer(unsigned int playerNumber)
{
	bool tempP1 = player1;
	bool tempP2 = player2;
	bool tempP3 = player3;
	bool tempP4 = player4;

	player1 = false;
	player2 = false;
	player3 = false;
	player4 = false;

	switch (playerNumber)
	{
	case 0:
		if (tempP1)
			player2 = true;
		else
			player1 = true;
		break;
	case 1:
		if (tempP2)
			player3 = true;
		else
			player2 = true;
		break;
	case 2:
		if (tempP3)
			player4 = true;
		else
			player3 = true;
		break;
	case 3:
		if (tempP4)
			player1 = true;
		else
			player4 = true;
		break;
	}
}

void getRandomPlayer()
{
	RandomAddEntropy(DMTimerCounterGet(SOC_DMTIMER_2_REGS));
	RandomSeed();
	unsigned int playerNumber = RandomNumber() % 4;

	enablePlayer(playerNumber);

	updateLeds();
}

void gameSetup()
{
	RandomAddEntropy(DMTimerCounterGet(SOC_DMTIMER_2_REGS));
	RandomSeed();
	unsigned int playerNumber = RandomNumber() % 4;

	enablePlayer(playerNumber);
	updateLeds();
	FinalizarJogoIrq(1000 * DURACAO_SEGUNDOS);
}

void setupGpio()
{
	gpioInitModule(GPIO1);
	gpioInitModule(GPIO2);

	gpioPinMuxSetup(LED_VERMELHO_MOD, LED_VERMELHO_PIN);
	gpioPinMuxSetup(LED_VERDE_PLAYER1_MOD, LED_VERDE_PLAYER1_PIN);
	gpioPinMuxSetup(LED_VERDE_PLAYER2_MOD, LED_VERDE_PLAYER2_PIN);
	gpioPinMuxSetup(LED_VERDE_PLAYER3_MOD, LED_VERDE_PLAYER3_PIN);
	gpioPinMuxSetup(LED_VERDE_PLAYER4_MOD, LED_VERDE_PLAYER4_PIN);

	gpioPinMuxSetup(BOTAO_PLAYER1_MOD, BOTAO_PLAYER1_PIN);
	gpioPinMuxSetup(BOTAO_PLAYER2_MOD, BOTAO_PLAYER2_PIN);
	gpioPinMuxSetup(BOTAO_PLAYER3_MOD, BOTAO_PLAYER3_PIN);
	gpioPinMuxSetup(BOTAO_PLAYER4_MOD, BOTAO_PLAYER4_PIN);
	gpioPinMuxSetup(BOTAO_RESET_MOD, BOTAO_RESET_PIN);

	gpioSetDirection(LED_VERMELHO_MOD, LED_VERMELHO_PIN, OUTPUT);
	gpioSetDirection(LED_VERDE_PLAYER1_MOD, LED_VERDE_PLAYER1_PIN, OUTPUT);
	gpioSetDirection(LED_VERDE_PLAYER2_MOD, LED_VERDE_PLAYER2_PIN, OUTPUT);
	gpioSetDirection(LED_VERDE_PLAYER3_MOD, LED_VERDE_PLAYER3_PIN, OUTPUT);
	gpioSetDirection(LED_VERDE_PLAYER4_MOD, LED_VERDE_PLAYER4_PIN, OUTPUT);

	gpioSetDirection(BOTAO_PLAYER1_MOD, BOTAO_PLAYER1_PIN, INPUT);
	gpioSetDirection(BOTAO_PLAYER2_MOD, BOTAO_PLAYER2_PIN, INPUT);
	gpioSetDirection(BOTAO_PLAYER3_MOD, BOTAO_PLAYER3_PIN, INPUT);
	gpioSetDirection(BOTAO_PLAYER4_MOD, BOTAO_PLAYER4_PIN, INPUT);
	gpioSetDirection(BOTAO_RESET_MOD, BOTAO_RESET_PIN, INPUT);

	// IRQ
	configureMirClear(GPIOINT2A);
	configureIrqGpio(BOTAO_PLAYER1_MOD, BOTAO_PLAYER1_PIN);
	configureIrqGpio(BOTAO_PLAYER2_MOD, BOTAO_PLAYER2_PIN);
	configureIrqGpio(BOTAO_PLAYER3_MOD, BOTAO_PLAYER3_PIN);
	configureIrqGpio(BOTAO_PLAYER4_MOD, BOTAO_PLAYER4_PIN);
	configureIrqGpio(BOTAO_RESET_MOD, BOTAO_RESET_PIN);
}

void gpio2Handle(void)
{
	if (checkIrqGpioPin(BOTAO_PLAYER1_MOD, BOTAO_PLAYER1_PIN))
	{
		if (!terminado && player1)
			getRandomPlayer();
		clearIrqGpio(BOTAO_PLAYER1_MOD, BOTAO_PLAYER1_PIN);
	}
	else if (checkIrqGpioPin(BOTAO_PLAYER2_MOD, BOTAO_PLAYER2_PIN))
	{
		if (!terminado && player2)
			getRandomPlayer();
		clearIrqGpio(BOTAO_PLAYER2_MOD, BOTAO_PLAYER2_PIN);
	}
	else if (checkIrqGpioPin(BOTAO_PLAYER3_MOD, BOTAO_PLAYER3_PIN))
	{
		if (!terminado && player3)
			getRandomPlayer();
		clearIrqGpio(BOTAO_PLAYER3_MOD, BOTAO_PLAYER3_PIN);
	}
	else if (checkIrqGpioPin(BOTAO_PLAYER4_MOD, BOTAO_PLAYER4_PIN))
	{
		if (!terminado && player4)
			getRandomPlayer();
		clearIrqGpio(BOTAO_PLAYER4_MOD, BOTAO_PLAYER4_PIN);
	}
	else if (checkIrqGpioPin(BOTAO_RESET_MOD, BOTAO_RESET_PIN))
	{
		if (terminado)
		{
			reset();
		}
		clearIrqGpio(BOTAO_RESET_MOD, BOTAO_RESET_PIN);
	}
	updateLeds();
}

void tempoFinal()
{
	uartPutString(UART0, "SISTEMA RESET___\r\n", 18);
	terminado = true;
	updateLeds();
	timerFinish();
}

int main(void)
{
	watchdogTimerDisable();
	uartPutString(UART0, "SISTEMA WDT_____\r\n", 18);

	uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);
	uartPutString(UART0, "SISTEMA UART____\r\n", 18);

	DMTimerSetUp();
	uartPutString(UART0, "SISTEMA TIMER___\r\n", 18);

	setupGpio();
	uartPutString(UART0, "SISTEMA GPIO____\r\n", 18);

	// IRQs
	AddIrq(TINT7, timerIrqHandler);
	AddIrq(TINT4, tempoFinal);
	AddIrq(GPIOINT2A, gpio2Handle);

	reset();

	uartPutString(UART0, "SISTEMA INICIADO\r\n", 18);

	while (1)
		;

	return (0);
}