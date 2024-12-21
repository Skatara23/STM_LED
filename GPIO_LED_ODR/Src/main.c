#include "stm32f4xx.h"

//#define GPIOAEN		(1U<<0)
//#define PIN5		(1U<<5)
//#define led5		PIN5

int main(void )
{
	RCC->AHB1ENR|=(1U<<0);
	GPIOA->MODER|=(1U<<0);
	GPIOA->MODER&=~(1U<<1);

	GPIOA ->MODER |=(1U<<12);


	while(1)
	{
		unsigned int i;
		GPIOA->ODR^=(1<<0);
		for(i=0; i<2000000; i++)
		{}

		GPIOA ->ODR^=(1U<<6);
		for(i=0; i<1000000; i++)
		{}
}
}
