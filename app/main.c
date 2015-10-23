#include "stm32f4xx.h"
#include "stm32f4xx_hal_gpio.h"
#include "GPIO.h"

void delay(uint32_t delayCount){
	while(delayCount != 0){
		delayCount--;
	}
}

int main(void)
{
	configurePin(GPIO_OUTPUT, GPIO_PIN_14, GPIOG);
	configurePin(GPIO_OUTPUT, GPIO_PIN_13, GPIOG);
	configurePin(GPIO_OUTPUT, GPIO_PIN_13, GPIOB);
	configurePin(GPIO_OUTPUT, GPIO_PIN_5, GPIOC);
	while(1){
	writeOne(GPIO_PIN_14, GPIOG);
	writeOne(GPIO_PIN_13, GPIOG);
	writeOne(GPIO_PIN_13, GPIOB);
	writeOne(GPIO_PIN_5, GPIOC);
	delay(500000);
	writeZero(GPIO_PIN_14, GPIOG);
	writeZero(GPIO_PIN_13, GPIOG);
	writeZero(GPIO_PIN_13, GPIOB);
	writeZero(GPIO_PIN_5, GPIOC);
	delay(500000);
	}


}
