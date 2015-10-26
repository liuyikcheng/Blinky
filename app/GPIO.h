#ifndef __GPIO_H__
#define __GPIO_H__

#include "stm32f4xx_hal_gpio.h"

#define GPIO_OUTPUT		GPIO_MODE_OUTPUT_PP
#define GPIO_INPUT		GPIO_MODE_INPUT_PP

typedef struct GPIO_t GPIO;
struct GPIO_t{
	uint32_t MODER;
	uint32_t OTYPER;
	uint32_t OSPEED;
	uint32_t PUPDR;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t LCKR;
	uint32_t AFRL;
	uint32_t AFRH;

};

typedef struct RCC_t RCC_REG;
struct RCC_t{
	uint32_t CR;
	uint32_t PLLCFGR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t AHB1RSTR;
	uint32_t AHB2RSTR;
	uint32_t AHB3RSTR;
	uint32_t Reserved1;
	uint32_t APB1RSTR;
	uint32_t APB2RSTR;
	uint32_t Reserved2;
	uint32_t Reserved3;
	uint32_t AHB1ENR;
};

#define CLK_ENABLE

#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4		4
#define PIN_5		5
#define PIN_6		6
#define PIN_7		7
#define PIN_8		8
#define PIN_9		9
#define PIN_10		10
#define PIN_11		11
#define PIN_12		12
#define PIN_13		13
#define PIN_14		14
#define PIN_15		15

#define GPIO_MODE_INTPUT		0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALTFUNC		2
#define GPIO_MODE_ANALOG		3

#define GPIO_LOW_SPEED			0
#define GPIO_MEDIUM_SPEED		1
#define GPIO_HIGH_SPEED			2
#define GPIO_VERY_HIGH_SPEED	3

#define GPIOG_BASE_ADDRESS	0x40021800
#define GPIOB_BASE_ADDRESS	0x40020400
#define GPIOC_BASE_ADDRESS	0x40020800

#define PORTG	((GPIO *)GPIOG_BASE_ADDRESS)
#define PORTB	((GPIO *)GPIOB_BASE_ADDRESS)
#define PORTC	((GPIO *)GPIOC_BASE_ADDRESS)

#define RCC_REG_RESET_ADDRESS		0x40023810

#define RCC_REG_RESET	((int *)RCC_REG_RESET_ADDRESS)

void configurePin(int mode, int pinNumber, GPIO *port);
void gpioUnresetEnableClock(GPIO *port);

void writeOne(int pinNumber, GPIO_TypeDef *port);
void writeZero(int pinNumber, GPIO_TypeDef *port);

#endif // __GPIO_H__
