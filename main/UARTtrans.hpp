#ifndef _UARTtrans_HPP
#define _UARTtrans_HPP
#pragma once

#include "driver/uart.h" 
#include <string.h>
#include "soc\gpio_num.h"

#define UART_NUM_ID UART_NUM_0
#define UART_NUM_ID_TX UART_PIN_NO_CHANGE
#define UART_NUM_ID_RX UART_PIN_NO_CHANGE
#define UART_NUM_SCREEN UART_NUM_1
#define UART_NUM_SCREEN_TX UART_PIN_NO_CHANGE
#define UART_NUM_SCREEN_RX UART_PIN_NO_CHANGE
#define UART_NUM_SERVO UART_NUM_0

//#define UART_NUM_SERVO_TX GPIO_NUM_14
//#define UART_NUM_SERVO_RX GPIO_NUM_14

#define UART_NUM_SERVO_TX UART_PIN_NO_CHANGE
#define UART_NUM_SERVO_RX UART_PIN_NO_CHANGE

void init_uart2id(void);
void init_uart2screen(void);
void init_uart2servo(void);

void IDUARTwrite(uint8_t data);

void servoUARTread(char *UARTdata);                      //接受舵机回值

#endif