#ifndef _servo_HPP
#define _servo_HPP
#pragma once

#include <stdint.h>
#include "UARTtrans.hpp"

class SERVO
{
private:
    char servoID[4] = "000";                                                //舵机编号，默认为000
    char servoCommand[16];                                                  //待发送的舵机指令
    char servoRetrun[16];                                                   //应当接收到的舵机回传
    char resetPos[5] = "0500";
    char openPos[5] = "2000";

public:
    bool servo_init(void);
    bool opendoor();
    void setServoID(char out_servoID);
    SERVO(char *out_servoID);                                               //构造函数
    ~SERVO();                                                               //析构函数
};

#endif