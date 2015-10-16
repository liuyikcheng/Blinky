#include "GPIO.h"
#include "stm32f4xx_hal_rcc.h"

void configurePin(int direction, int pinNumber, GPIO_TypeDef *port){
	GPIO_InitTypeDef gpio;

	__HAL_RCC_GPIOG_CLK_ENABLE();
	gpio.Pin = pinNumber;
	gpio.Mode = direction;
	gpio.Speed = GPIO_SPEED_MEDIUM;
	HAL_GPIO_Init(port, &gpio);
}


void writeOne(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_SET);
}

void writeZero(int pinNumber, GPIO_TypeDef *port){
	HAL_GPIO_WritePin(port, pinNumber, GPIO_PIN_RESET);
}
