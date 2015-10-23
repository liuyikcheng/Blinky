#include "GPIO.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNumber, GPIO_TypeDef *port){
	GPIO_InitTypeDef gpio;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	int *ptr = (int*)0x40021800;
	int *ptrB = (int*)0x40020400;
	int *ptrC = (int*)0x40020800;

	ptr[0] = 0x14000000;				// MODE.pin14 = output
	ptr[1] = 0;							// OTYPE.pin14 = push-pull
	ptr[2] = 0x20000000;                // OSPEED.pin14 = high speed

	ptrB[0] = 0x04000000;
	ptrB[1] = 0;
	ptrB[2] = 0x08000000;

	ptrC[0] = 0x00000400;
	ptrC[1] = 0;
	ptrC[2] = 0x00000800;
//	gpio.Pin = pinNumber;
//	gpio.Mode = direction;
//	gpio.Speed = GPIO_SPEED_MEDIUM;

//	HAL_GPIO_Init(port, &gpio);
}


void writeOne(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_SET);
}

void writeZero(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_RESET);
}
