#include "servo.hpp"

SERVO::SERVO(char *out_servoID)
{
    strcpy(servoID, out_servoID);
    servo_init();
}

SERVO::~SERVO()
{
}

/*******************************************************************************
****函数功能: 初始化舵机
****入口参数: 无
****出口参数: true: 设置成功 false: 设置失败
****函数备注: 无
********************************************************************************/

bool SERVO::servo_init()
{
    init_uart2servo();

    char servoCommand[16];
    strConnect(servoCommand, "#", servoID, "PID!");                                        // 拼凑出一个获取舵机ID的指令
    ESP_ERROR_CHECK(uart_write_bytes(UART_NUM_SERVO, servoCommand, strlen(servoCommand))); // 发送，然后读取串口
    size_t bufferLenth;
    char UARTdata[64];
    servoUARTread(UARTdata);
    char servoRetrun[16];
    strConnect(servoRetrun, "#", servoID, "!"); // 拼凑出舵机“应该”有的返回值
    char *isOK = NULL;                          // 串口读到的信息里有“应该”有的返回值吗？
    isOK = strstr(UARTdata, servoRetrun);
    if (isOK != NULL)
    {
        isOK = NULL;
        strcpy(UARTdata, "\0");
        strcpy(servoRetrun, "\0");
        strConnect(servoCommand, "#", servoID, "PMOD!"); // 舵机读取工作模式指令
        ESP_ERROR_CHECK(uart_write_bytes(UART_NUM_SERVO, servoCommand, strlen(servoCommand)));
        servoUARTread(UARTdata);
        strConnect(servoRetrun, "#", servoID, "PMOD1!");
        isOK = strstr(UARTdata, servoRetrun);
        if (isOK != NULL)
        {
            strcpy(UARTdata, "\0");
            strConnect(servoCommand, "#", servoID, "PMOD1!");
            ESP_ERROR_CHECK(uart_write_bytes(UART_NUM_SERVO, servoCommand, strlen(servoCommand)));
        }
        return true;
    }else{
        return false;
    }
    
}

bool SERVO::opendoor()
{
    char servoCommand[7];
    uart_write_bytes(UART_NUM_SERVO, servoCommand, strlen(servoCommand));
}