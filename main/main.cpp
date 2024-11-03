#include <stdio.h>
#include "fingerID.hpp"
#include "screen.hpp"
#include "servo.cpp"
    

                  
/*
void servotask(void *arg)
{
    SERVO servo;  //创建舵机对象
    printf("舵机对象已创建\n");
    while (1)
    {
        servo.opendoor();
        printf("调用\n");
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}
*/

void IDtask(void *arg)
{
    IDENTIFIER identifier;      //创建指纹识别器对象    
    
    //identifier.Add_FR();
    while (1)
    {
        identifier.PS_GetRandomCode();
        #ifdef TEST
        printf("\nIDtask任务调用\n");
        #endif
        vTaskDelay(5000/portTICK_PERIOD_MS);
    }
}

extern "C" void app_main(void)
{
    printf("power on\n");
    //xTaskCreate(servotask, "servotask", 12 * 1024, NULL, 1, NULL);
    xTaskCreate(IDtask, "idtask", 12 * 1024, NULL, 1, NULL);
}
