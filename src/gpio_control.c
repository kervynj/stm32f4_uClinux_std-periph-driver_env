#include <stm32f4xx_conf.h>
#include <stm32f4xx.h>
#include <gpio_control.h>
#include <stm32f4xx_gpio.h>
#include "stm32f4xx_rcc.h"
#include <stdio.h>
#define USE_FULL_ASSERT

int main(int argc, char *argv[])
{	
	int i =0;

	for (i=0; i<argc; i++)
	{
		printf("argv[%d]: %s\n", i, argv[i]);
	}

	int pin; 
	sscanf(argv[1], "%d", &pin);
	uint16_t gpioPin = 1 << pin;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	printf("setting pin %d to mode %s\n", pin, argv[2]);

	if (1)
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
		printf("setting pin %d (GPIO_PIN=%d) to mode %s", pin, gpioPin, argv[2]);
	}
	else
	{
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	}

	/* GPIOA Clocks enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStructure.GPIO_Pin = gpioPin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP ;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOA, gpioPin);	
	return 0;
}

