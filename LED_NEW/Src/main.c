#include "stm32f4xx.h"

#define GPIOAEN 	(1U<<0)

#define RS 		(1U<<8)
#define EN 		(1U<<9)

void lcd_command(uint8_t cmd)
{
	// 0. Clear GPIOA
	GPIOA -> ODR = 0;
	GPIOA -> ODR |= cmd;
	// 1. Set RS and EN pin to 0
	GPIOA -> ODR &= ~RS; // RS pin is LOW
	//GPIOA -> ODR &= ~EN; // EN pin is LOW
	// 2. Load the data on Data Pins

	// 3. Generate a Rising Edge on EN Pin
	GPIOA -> ODR |= EN; // EN pin is HIGH
	for(int i=0; i<20000; i++)	{}
	// 4. End the Rising Edge
	GPIOA -> ODR &= ~EN; // EN pin is LOW
	for(int i=0; i<20000; i++)	{}
}

void lcd_data(uint8_t data)
{
	// 0. Clear GPIOA
	GPIOA -> ODR = 0;
	// 1. Set RS pin to 1 and EN pin to 0
	GPIOA -> ODR |= RS; // RS pin is HIGH
	//GPIOA -> ODR &= ~EN; // EN pin is LOW
	// 2. Load the data on Data Pins
	GPIOA -> ODR |= data;
	// 3. Generate a Rising Edge on EN Pin
	GPIOA -> ODR |= EN; // EN pin is HIGH
	for(int i=0; i<50000; i++)	{}
	// 4. End the Rising Edge
	GPIOA -> ODR &= ~EN; // EN pin is LOW
	for(int i=0; i<50000; i++)	{}
}

void lcd_init()
{
	lcd_command(0x38); 		// 38 -> 8 bit 2 row 16 char mode

	// 3. lcd cursor (solid / blink / off)
	lcd_command(0x0C);

	// 4. lcd display direction (Left -> Right / Right -> Left)
	lcd_command(0x06);

	// 5. lcd clear garbage
	lcd_command(0x01);
	// 6. lcd set new start point
	lcd_command(0x80);
}

void lcd_print(char *str)
{
	while (*str!= '\0')
	{
		lcd_data(*str);
		str++;
	}
}

int main(void)
{
	RCC -> AHB1ENR |= GPIOAEN; 			//GPIOA is ENABLED

	GPIOA->MODER=0;
	GPIOA -> MODER |= (1<<0)|(1<<2)|(1<<4)|(1<<6)|(1<<8)|(1<<10)|(1<<12)|(1<<14)|(1<<16)|(1<<18);// OUTPUT

	lcd_init();

	while (1)
	{
		lcd_command(0x84);
		lcd_print("SUMIT");
		for(int i=0; i<1000; i++)	{}

		lcd_command(0xC4);
		lcd_print("SHARMA");
		for(int i=0; i<1000; i++)	{}

		lcd_command(0x01); 			// clear all display
		for(int i=0; i<1000; i++)	{}
	}
}
