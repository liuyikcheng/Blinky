#include "RCC.h"
#include "GPIO.h"

void gpioUnresetEnableClock(GPIO *port){
	int shift = (((int)port) - 0x40020000) / 0x400;

	RCC_reg->AHB1RSTR &= ~(1 << (shift));
	RCC_reg->AHB1ENR |= (1 << (shift));

//	RCC_reg->AHB1RSTR = 0xFFFFFFBF;
//	RCC_reg->AHB1ENR = 0x00100040;

}


