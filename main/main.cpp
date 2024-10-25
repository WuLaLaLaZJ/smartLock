#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"

extern "C" void app_main(void)
{
    printf("开机了");
    init_uart2id();
    ESP_ERROR_CHECK(uart_write_bytes(UART_NUM_ID, "你好你好你好\n\n", sizeof("你好你好你好\n\n")));//这里能否运行是个问号
    vTaskDelay(100);
}
