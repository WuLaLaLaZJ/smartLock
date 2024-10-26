#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"

void task_1(void *arg)
{
    while (1)
    {
        uart_write_bytes(UART_NUM_ID, "this task1调度\n", sizeof("this task1调度\n"));
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}

void task_2(void *arg)
{
    while (1)
    {
        uart_write_bytes(UART_NUM_ID, "this task2调度\n", sizeof("this task2调度\n"));
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

extern "C" void app_main(void)
{
    /*现在都是测试*/
    printf("开机了");
    init_uart2id();
    xTaskCreatePinnedToCore(task_1, "task_123", 12 * 1024, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(task_2, "task_456", 12 * 1024, NULL, 2, NULL, 1);
}
