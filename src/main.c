
#include "stm32f4xx.h"
#include "scheduler.h"

extern void LED_Task(void);
extern void UART_Task(void);

volatile uint32_t sysTick_ms = 0;

void SysTick_Handler(void) {
    sysTick_ms++;
}

int main(void) {
    HAL_Init();
    SystemCoreClockUpdate();
    SysTick_Config(SystemCoreClock / 1000); // 1 ms tick

    // Initialize peripherals (LED, UART, etc.)

    Scheduler_Init(1);
    Scheduler_AddTask(LED_Task, 1000);
    Scheduler_AddTask(UART_Task, 2000);

    while (1) {
        Scheduler_Run(sysTick_ms);
    }
}
