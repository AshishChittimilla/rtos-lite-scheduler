
#include "stm32f4xx.h"
#include "scheduler.h"
#include <string.h>

void LED_Task(void) {
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5); // Toggle onboard LED
}

void UART_Task(void) {
    const char msg[] = "Hello from UART_Task!\r\n";
    HAL_UART_Transmit(&huart2, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
}
