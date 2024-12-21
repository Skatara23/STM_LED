#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOBEN		(1U<<1)

#define lcd_d0		(1U<<0)
#define lcd_d1		(1U<<1)
#define lcd_d2		(1U<<2)
#define lcd_d3		(1U<<3)
#define lcd_d4		(1U<<4)
#define lcd_d5		(1U<<5)
#define lcd_d6		(1U<<6)
#define lcd_d7		(1U<<7)


#define rs 			(1U<<1)		//on port 3 pin connection
#define rw			(1U<<2)
#define en			(1U<<3)

unsigned int i;

void lcd_cmd(unsigned char command)
{
	GPIOA->ODR=command;
	GPIOB->ODR&=~rs;			//RS =0 FOR COMMAND
	GPIOB->ODR&=~rw;			//
	GPIOB->ODR|=en;
	for(i=0; i<1000000; i++)
	{}
	GPIOB->ODR&=~en;


}
void lcd_data(unsigned char data)
{
	GPIOA->ODR=data;
	GPIOB->ODR|=rs;
	GPIOB->ODR&=~rw;
	GPIOB->ODR|=en;
	for(i=0; i<1000000; i++)
	{}
	GPIOB->ODR&=~en;//enable bit deactive

}
void lcd_init()
{
	lcd_cmd(0x38);      //8 bit 2 line
	lcd_cmd(0x01);		//clear display scrn
	lcd_cmd(0x0E);		// display on cursor on
	lcd_cmd(0x80);		//for 1st row
	lcd_cmd(0x06);		//entry mode
	lcd_cmd(0xC0);		// for 2nd row

}
void lcd_word(char *str)
{
	while(*str!='\0')
	{
		lcd_data(*str);
		str++;
	}
}
int main()
{
	RCC->AHB1ENR|=GPIOAEN;
	RCC->AHB1ENR|=GPIOBEN;

	GPIOA->MODER|=(1U<<0)|(1U<<2)|(1U<<4)|(1U<<6)|(1U<<8)|(1U<<10)|(1U<<12);

	GPIOA->MODER&=~(1U<<1)&~(1U<<3)&~(1U<<5)&~(1U<<7)&~(1U<<9)&~(1U<<11)&~(1U<<13);

	GPIOB-> MODER|=(1U<<2)|(1U<<4)|(1U<<6);
	GPIOB->MODER&=~(1U<<3)&~(1U<<5)&~(1U<<7);

	lcd_init();

	while(1)
	{
		lcd_cmd(0x01);
		lcd_cmd(0x80);
		lcd_word("welcome");
		lcd_cmd(0x01);
		lcd_cmd(0xC0);
		lcd_word("stm");
		for(i=0; i<1000; i++)
		{}
	}
}
