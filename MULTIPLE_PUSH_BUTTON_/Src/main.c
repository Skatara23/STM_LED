#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)
#define GPIOBEN		(1U<<1)

#define PIN5		(1U<<5)
#define PIN13		(1U<<13)
#define PIN7		(1<<7)
#define PIN10		(1<<10)

int main(void)
{
	RCC->AHB1ENR|=GPIOAEN;
	RCC->AHB1ENR|=GPIOCEN|GPIOBEN;

	GPIOA->MODER|=(1U<<10);
	GPIOA->MODER&=~(1U<<11);

	GPIOC->MODER&=~(1U<<26);
	GPIOC->MODER&=~(1U<<27);

	GPIOB->MODER&=~(1U<<10);
	GPIOB->MODER&=~(1U<<11);

	GPIOB->MODER|=(1<<20);
	GPIOB->MODER&=~(1<<21);

	GPIOB->MODER|=(1U<<14);
	GPIOB->MODER&=~(1U<<15);
	while(1)
	{
		if(GPIOC->IDR & (1U<<13))
		{

			//GPIOA->BSRR=(1<<21)
			GPIOA->ODR|=(1U<<5);
		}
		else
		{
			//GPIOA->BSRR=(1<<5);
			GPIOA->ODR&=~(1<<5);
		}

		if(GPIOB->IDR  & (1U<<5))
		{
			GPIOB->ODR|=(1U<<7);
		}

		/*else if ((GPIOC->IDR & (1<<13)) && (GPIOB->IDR  & (1<<5)))
		{
			GPIOB->ODR|=(1<<10);
		}*/


		else
		{
			GPIOB->ODR&=~(1U<<7);
		}

		if((GPIOC->IDR & (1U<<13)) && (GPIOB->IDR  & (1U<<5)))
		{
						GPIOB->ODR|=(1U<<10);

		}
		else
		{
			GPIOB->ODR&=~(1<<10);
		}


	}
}



