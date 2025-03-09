//
// Created by hhw on 2025/2/22.
//

#ifndef _LED_H
#define _LED_H

typedef enum{
    LED0 = 0,
    LED1 = 1,
    LED2 = 2,
    LED3 = 3
}LED_INDEX; 

extern void LED_Init (LED_INDEX LED);
extern void LED_On (LED_INDEX LED);
extern void LED_Off (LED_INDEX LED);
extern void LED_Toggle (LED_INDEX LED);


#endif
