#include "UARTtrans.hpp"

static const int RX_BUF_SIZE = 1024;  //串口接收缓冲区大小

const uart_config_t uart2fri_config = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT
};

const uart_config_t uart2screen_config = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT
};

const uart_config_t uart2servo_config = {
    .baud_rate = 115200,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .source_clk = UART_SCLK_DEFAULT
};

void init_uart2fri(void)            //配置连接到指纹识别器的UART
{
    uart_param_config(UART_NUM_FPI, &uart2fri_config);
    uart_set_pin(UART_NUM_FPI, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_FPI, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
}

void init_uart2screen(void)         //配置连接到串口屏的UART
{
    uart_param_config(UART_NUM_SCREEN, &uart2screen_config);
    uart_set_pin(UART_NUM_SCREEN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_SCREEN, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
}

void init_uart2servo(void)         //配置连接到舵机的UART
{
    uart_param_config(UART_NUM_SERVO, &uart2servo_config);
    uart_set_pin(UART_NUM_SERVO, UART_NUM_SERVO_TX, UART_NUM_SERVO_RX, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_SERVO, RX_BUF_SIZE * 2, 0, 0, NULL, 0);
}

void strConnect(char *sourceChar, char *char1 = NULL, char *char2 = NULL, char *char3 = NULL, char *char4 = NULL)
{
    char returnChar[16];
    if(char1 != NULL)       strcat(sourceChar, char1);
    else if (char2 != NULL) strcat(sourceChar, char2);
    else if (char3 != NULL) strcat(sourceChar, char3);
    else if (char4 != NULL) strcat(sourceChar, char4);
    strcpy(sourceChar, returnChar);
}

void servoUARTread(char *UARTdata)
{
    size_t bufferLenth;
    ESP_ERROR_CHECK(uart_get_buffered_data_len(UART_NUM_SERVO, &bufferLenth));
    ESP_ERROR_CHECK(uart_read_bytes(UART_NUM_SERVO, UARTdata, bufferLenth, 100));
    ESP_ERROR_CHECK(uart_flush(UART_NUM_SERVO));
}