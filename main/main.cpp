#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"
#include "servo.cpp"
    
//IDENTIFIER identifier();      //创建指纹识别器对象
                  

void task_1(void *arg)
{
    SERVO servo;  //创建舵机对象
    printf("对象已创建\n");
    while (1)
    {
        servo.opendoor();
        printf("调用\n");
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}

extern "C" void app_main(void)
{
    /*现在都是测试*/
    printf("power on\n");
    xTaskCreate(task_1, "task_123", 12 * 1024, NULL, 1, NULL);
}
