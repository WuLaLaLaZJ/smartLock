#ifndef _servo_HPP
#define _servo_HPP
#pragma once

#include <stdint.h>

class servo
{
private:
    uint8_t servoNum;
public:
    servo(/* args */);  //构造函数
    ~servo();           //析构函数
};

servo::servo(/* args */)
{
}

servo::~servo()
{
}


#endif