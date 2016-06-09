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
	int a = 0;
	configurePin(GPIO_MODE_OUTPUT, PIN_14, PORTG);
	configurePin(GPIO_MODE_OUTPUT, PIN_13, PORTG);
	configureInputPin(PIN_0, PORTA, GPIO_PULL_DOWN);
//	configurePin(GPIO_OUTPUT, GPIO_PIN_13, GPIOB);
//	configurePin(GPIO_OUTPUT, GPIO_PIN_5, GPIOC);
	while(1){
	if(((PORTA->IDR)&1) == 0){
		writeOne(PIN_13, GPIOG);
		writeOne(PIN_14, GPIOG);
//	writeOne(GPIO_PIN_13, GPIOB);
//	writeOne(PIN_5, GPIOC);
		delay(500000);
		writeZero(PIN_14, GPIOG);
		writeZero(PIN_13, GPIOG);
//	writeZero(GPIO_PIN_13, GPIOB);
//	writeZero(PIN_5, GPIOC);
		delay(500000);
	}
	}


}
