#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"

extern "C" void app_main(void)
{
    printf("开机了");
    init_uart2id();
    //while(1){
    char test[6] = "1234\n";
    while(1){
    uart_write_bytes(UART_NUM_ID, "1234", sizeof("1234"));//
    vTaskDelay(100);
    }
}
