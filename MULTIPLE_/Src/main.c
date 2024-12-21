#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN 	(1U<<2)

#define PIN5		(1U<<5)
#define PIN6		(1U<<6)
#define PIN7		(1U<<7)

#define PIN11		(1U<<11)
#define PIN12		(1U<<12)
#define PIN13		(1U<<13)


int main(void )
{
	RCC->AHB1ENR|=GPIOAEN;
	RCC->AHB1ENR|=GPIOCEN;

	GPIOA->MODER|=(1U<<10)|(1U<<12)|(1U<<13);
	GPIOA->MODER&=~(1U<<11)&~(1U<<13)&~(1U<<14);

	GPIOC->MODER&=~(1U<<22)&~(1U<<23)&~(1U<<24)&~(1U<<25)&~(1U<<26)&~(1U<<27);
	//GPIOC->MODER&=~(1U<<23)&~(1U<<25)&~(1U<<27);



	//uint8_t button_state_1=GPIOC->IDR & PIN13;
	//uint8_t button_state_2=GPIOC->IDR & PIN14;
	//uint8_t button_state_3=GPIOC->IDR & PIN15;
	while(1){
	if(GPIOC->IDR & (1U<<11))
	{
		GPIOA->ODR|=(1U<<5);
	}

	else if(GPIOC->IDR & (1U<<12))
	{
		GPIOA->ODR|=(1U<<6);
	}

	else if(GPIOC->IDR & (1U<<13))
	{
		GPIOA->ODR|=(1U<<7);
	}

	else
	{
		GPIOA->ODR&=~(1U<<5);
		GPIOA->ODR&=~(1U<<6);
		GPIOA->ODR&=~(1U<<7);
	}
}
}



