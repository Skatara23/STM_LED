#include "stm32f4xx.h"
#define GPIOAEN 	(1U<<0)
#define PIN5    	(1U<<5)
#define Led_Pin  	PIN5

int main(void )
{
	RCC -> AHB1ENR|=GPIOAEN; 			//AHB1 enable register
	GPIOA-> MODER|=(1U<<10); 			// 10 set to 1 led on
	GPIOA ->MODER&=~(1U<<11);			//11 set to 0 led off


	unsigned int i;
	while(1){
			GPIOA->ODR^=Led_Pin;
			for(i=0; i=2000000; i++)
			{}
		}
}
