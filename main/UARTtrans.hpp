#ifndef _UARTtrans_H
#define _UARTtrans_H
#pragma once

#include "driver/uart.h" 
#define UART_NUM_FPI UART_NUM_0 //fingerPrintIdentify的意思
#define UART_NUM_FPI_TX UART_PIN_NO_CHANGE
#define UART_NUM_FPI_RX UART_PIN_NO_CHANGE
#define UART_NUM_SCREEN UART_NUM_1
#define UART_NUM_SCREEN_TX UART_PIN_NO_CHANGE
#define UART_NUM_SCREEN_RX UART_PIN_NO_CHANGE
#define UART_NUM_SERVO UART_NUM_2
#define UART_NUM_SERVO_TX UART_PIN_NO_CHANGE
#define UART_NUM_SERVO_RX UART_PIN_NO_CHANGE



void init_uart2fri(void);
void init_uart2screen(void);
void init_uart2servo(void);

#endif