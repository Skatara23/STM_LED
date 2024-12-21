#include "stm32f4xx.h"

void SystemInit(void);
void initTIM2(void);
void initTIM3(void);
void initGPIO(void);

int main(void)
{
    SystemInit();

    initGPIO();
    initTIM2();
    initTIM3();

    while (1)
    {
        // Toggle PA0 (LED connected to TIM2_CH1)
        GPIOA->ODR ^= GPIO_ODR_OD0; // Toggle PA0

        // Toggle PB1 (LED connected to TIM3_CH4)
        GPIOB->ODR ^= GPIO_ODR_OD1; // Toggle PB1

        // Wait for 500 ms (half-period)
        for (volatile int i = 0; i < 500000; ++i)
        {
            // Add some delay, depends on your system clock and optimization settings
        }
    }
}

void SystemInit(void)
{
    // Set up the system.
    // Reset the RCC clock configuration to the default reset state.
    RCC->CR |= RCC_CR_HSION;                    // Enable HSI
    RCC->CFGR &= ~RCC_CFGR_SW;                  // Reset SW bits
    RCC->CR &= ~RCC_CR_PLLON;                   // Disable PLL
    while ((RCC->CR & RCC_CR_PLLRDY) != 0) {}  // Wait until PLL is disabled
    RCC->CR &= ~RCC_CR_HSEON;                   // Disable HSE
    while ((RCC->CR & RCC_CR_HSERDY) != 0) {}  // Wait until HSE is disabled
    RCC->CR &= ~RCC_CR_CSSON;                   // Disable CSS
    RCC->PLLCFGR = 0x24003010;                  // Reset PLLCFGR register
    RCC->CR &= ~RCC_CR_HSEBYP;                  // Reset HSEBYP bit
    RCC->CIR = 0x00000000;                      // Disable all interrupts and clear pending bits
}

void initTIM2(void)
{
    // Enable TIM2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Configure TIM2
    TIM2->CR1 &= ~TIM_CR1_CEN;  // Disable TIM2
    TIM2->PSC = 83;             // Prescaler, so the timer counts every 1 us (84 MHz / (83 + 1) = 1 MHz)
    TIM2->ARR = 8399;           // Auto-reload value, gives a period of 8.4 ms (1 MHz * (8399 + 1) = 8.4 ms)
    TIM2->CCMR1 = 0x60;         // PWM mode 1 on channel 1
    TIM2->CCMR1 |= TIM_CCMR1_OC1PE;  // Enable preload register on channel 1
    TIM2->CCER |= TIM_CCER_CC1E;     // Enable capture/compare channel 1
    TIM2->CR1 |= TIM_CR1_ARPE;       // Enable auto-reload preload
    TIM2->CR1 |= TIM_CR1_CEN;        // Enable TIM2
}

void initTIM3(void)
{
    // Enable TIM3 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

    // Configure TIM3
    TIM3->CR1 &= ~TIM_CR1_CEN;  // Disable TIM3
    TIM3->PSC = 83;             // Prescaler, so the timer counts every 1 us (84 MHz / (83 + 1) = 1 MHz)
    TIM3->ARR = 8399;           // Auto-reload value, gives a period of 8.4 ms (1 MHz * (8399 + 1) = 8.4 ms)

    // Configure for 50% duty cycle (half the period)
    TIM3->CCR4 = 4199;  // Half of the auto-reload value

    TIM3->CCMR2 = 0x60;         // PWM mode 1 on channel 4
    TIM3->CCMR2 |= TIM_CCMR2_OC4PE;  // Enable preload register on channel 4
    TIM3->CCER |= TIM_CCER_CC4E;     // Enable capture/compare channel 4
    TIM3->CR1 |= TIM_CR1_ARPE;       // Enable auto-reload preload
    TIM3->CR1 |= TIM_CR1_CEN;        // Enable TIM3
}

void initGPIO(void)
{
    // Enable GPIOA and GPIOB clock
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN;

    // Configure PA0 (TIM2_CH1) and PB1 (TIM3_CH4) as alternate function
    GPIOA->MODER &= ~GPIO_MODER_MODER0;  // Clear mode bits for PA0
    GPIOA->MODER |= GPIO_MODER_MODER0_1; // Set mode bits to alternate function for PA0

    GPIOB->MODER &= ~GPIO_MODER_MODER1;  // Clear mode bits for PB1
    GPIOB->MODER |= GPIO_MODER_MODER1_1; // Set mode bits to alternate function for PB1

    // Configure alternate function for PA0 (TIM2_CH1) and PB1 (TIM3_CH4)
    GPIOA->AFR[0] &= ~GPIO_AFRL_AFSEL0;   // Clear alternate function bits for PA0
    GPIOA->AFR[0] |= GPIO_AFRL_AFSEL0_1;  // Set alternate function bits for PA0

    GPIOB->AFR[0] &= ~GPIO_AFRL_AFSEL1;   // Clear alternate function bits for PB1
    GPIOB->AFR[0] |= GPIO_AFRL_AFSEL1_1;  // Set alternate function bits for PB1
}
