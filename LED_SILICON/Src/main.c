#include "stm32f4xx.h"

//declare and define for led pin5 on port

#define GPIOAEN 	(1U<<0)
#define GPIOCEN 	(1U<<2)

#define led1		(1U<<5)
#define button		(1U<<13)

//#define led1 	PIN5
//#define button PIN13
int main()
{

	// ENABLE THE CLOCK ACCESS TO GPIOA AND GPIOC PORT*/
	RCC -> AHB1ENR|=GPIOAEN;		// clock enbale for port a
	RCC -> AHB1ENR |=GPIOCEN;

	GPIOA -> MODER |=(1U<<10); 		//10 set to 1 , led on
	GPIOA -> MODER &= ~(1U<<11); 	//11 set to 0	, led off

	GPIOC -> MODER &= ~(1U<<26);
	GPIOC -> MODER &= ~(1U<<27);

	//unsigned int i;
	int count =0;
	while(1)
	{
		/*GPIOA -> ODR^=led_pin;	// led as an output register
		for( int i=0; i<1000000; i++)	// delay for 1 sec
		{}*/

		/*GPIOA -> BSRR =(1U<<5) ; 		// led is on
		for(i=0; i<1000000; i++);
		{}
		GPIOA ->BSRR = (1U<<21);
		for(i=0; i<1000000; i++)
		{}*/

		/* using if else condition for checking button state*/
		if(GPIOC -> IDR & button )  // if(GPIOC -> IDR & (1U<<13);
		{
			count++;
			//GPIOA -> ODR |=led1;		// LED IS ON
			while(GPIOC -> IDR & button);
		}

		if(count ==1)
		{
			GPIOA -> ODR |=(1U<<5);
		}

		if(count == 3)
		{
			GPIOA -> ODR &= ~(1U<<5);
			count =0;
		}
	}
}
