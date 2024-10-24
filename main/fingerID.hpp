#ifndef _fingerID_HPP
#define _fingerID_HPP
#pragma once

#include <stdint.h>
#include "UARTtrans.hpp"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#define PACKHEAD 0xEF01 //通信包头
#define COMMANDSIGN 0x01 //命令包标识

class IDENTIFIER
{
    private:
    char32_t command = 5; 
    uint32_t IDaddr = 0XFFFFFFFF;
    uint16_t packLength;

    public:
    bool ID_init();
    void transCommand(uint8_t command);
    IDENTIFIER();
    ~IDENTIFIER();
};

#endif