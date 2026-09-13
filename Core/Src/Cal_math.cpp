//
// Created by hhw on 2025/3/9.
//

#include "Cal_math.h"

void CAL_ADD(int num1, int num2)
{
    int result = 0;
    result=num1+num2;
    oled_show(result);
}

void  CAL_SUB(int num1, int num2)
{
    int result = 0;
    result=num1-num2;
    oled_show(result);
}

void  CAL_MUL(int num1, int num2)
{
    int result = 0;
    result=num1*num2;
    oled_show(result);
}

void  CAL_DIV(int num1, int num2)
{
    int result = 0;
    result=num1/num2;
    oled_show(result);
}









