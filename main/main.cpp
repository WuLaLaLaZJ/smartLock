#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"
#include "servo.cpp"

void task_1(void *arg)
{
    while (1)
    {
        
    }
}

extern "C" void app_main(void)
{
    /*现在都是测试*/
    printf("power on\n");
    IDENTIFIER identifier();     //创建指纹识别器对象
    SERVO servo();          //创建舵机对象
    xTaskCreate(task_1, "task_123", 12 * 1024, NULL, 1, NULL);
}
