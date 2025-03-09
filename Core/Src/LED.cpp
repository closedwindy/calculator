//
// Created by hhw on 2025/2/22.
//

#include "LED.h"
#include "stm32f1xx_hal.h"
#define LEDn  4



#define LED0_PIN            GPIO_PIN_0
#define LED0_GPIO_Port      GPIOA
#define LED0_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

#define LED1_PIN            GPIO_PIN_1
#define LED1_GPIO_Port      GPIOA
#define LED1_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

#define LED2_PIN            GPIO_PIN_2
#define LED2_GPIO_Port      GPIOA
#define LED2_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()

#define LED3_PIN            GPIO_PIN_3
#define LED3_GPIO_Port      GPIOA
#define LED3_GPIO_CLK_ENABLE()   __HAL_RCC_GPIOA_CLK_ENABLE()



GPIO_TypeDef *GPIO_PORT[LEDn] ={
LED0_GPIO_Port,
LED1_GPIO_Port,
LED2_GPIO_Port,
LED3_GPIO_Port,


};



const uint16_t GPIO_Pin[LEDn] ={
        LED0_PIN,
        LED1_PIN,
        LED2_PIN,
        LED3_PIN,
};

#define  LEDx_GPIO_CLK_ENABLE(__INDEX__)do{ \
if((__INDEX__)==0)                          \
LED0_GPIO_CLK_ENABLE();                      \
else if((__INDEX__)==1)                     \
LED1_GPIO_CLK_ENABLE();\
if((__INDEX__)==2)                          \
LED2_GPIO_CLK_ENABLE();\
if((__INDEX__)==3)                    \
LED3_GPIO_CLK_ENABLE();                                            \
                                \
}while(0)



void LED_Init(LED_INDEX LED) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    LEDx_GPIO_CLK_ENABLE(LED);
    GPIO_InitStruct.Pin = GPIO_Pin[LED];
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
    HAL_GPIO_Init(GPIO_PORT[LED],&GPIO_InitStruct);
    HAL_GPIO_WritePin(GPIO_PORT[LED], GPIO_Pin[LED], GPIO_PIN_RESET);
}



void  LED_On(LED_INDEX LED)
{
HAL_GPIO_WritePin(GPIO_PORT[LED],GPIO_Pin[LED],GPIO_PIN_SET);
}

void LED_Off(LED_INDEX LED)
{
    HAL_GPIO_WritePin(GPIO_PORT[LED],GPIO_Pin[LED],GPIO_PIN_RESET);
}

void LED_Toggle (LED_INDEX LED)
{
    HAL_GPIO_TogglePin(GPIO_PORT[LED],GPIO_Pin[LED]);
}

