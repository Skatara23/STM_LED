#include"stm32f4xx.h"

#define GPIOAEN 	(1U<<0)
#define GPIOBEN		(1U<<0)

#define PIN5		(1U<<5)
#define PIN3		(1U<<3)

#define led5 		PIN5
#define led3		PIN3

int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN|GPIOBEN;
	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);

	GPIOB->MODER|=(1U<<6);
	GPIOB->MODER&=~(1U<<7);

	unsigned int i;

	while(1)
	{
		GPIOA->ODR^=PIN5;
		for(i=0; i<2000000; i++)
		{}

		GPIOB->ODR^=PIN3;
		for(i=0; i<2000000; i++)
		{}

	}

}
