/*
 * led.c
 *
 *  Created on: Oct 4, 2025
 *      Author: YudufBera
 */



#include<stdint.h>
#include "led.h"



void delay(uint32_t count)
{
  for(uint32_t i = 0 ; i < count ; i++);
}

void led_init_all(void)
{

	uint32_t *pRccAhb1enr = (uint32_t*)0x40023830;
	*pRccAhb1enr |= (1 << 1);   // GPIOBEN = 1
	uint32_t *pGpiobModeReg = (uint32_t*)0x40020400;

    // Set PB0, PB7, PB14 as output (01)
    *pGpiobModeReg &= ~((3 << (2 * LED_GREEN)) |
                        (3 << (2 * LED_BLUE))  |
                        (3 << (2 * LED_RED)));

    *pGpiobModeReg |=  ((1 << (2 * LED_GREEN)) |
                        (1 << (2 * LED_BLUE))  |
                        (1 << (2 * LED_RED)));

//#if 0
//	//configure the outputtype
//	*pGpioOpTypeReg |= ( 1 << (2 * LED_GREEN));
//	*pGpioOpTypeReg |= ( 1 << (2 * LED_ORANGE));
//	*pGpioOpTypeReg |= ( 1 << (2 * LED_RED));
//	*pGpioOpTypeReg |= ( 1 << (2 * LED_BLUE));
//#endif

    led_off(LED_GREEN);
    led_off(LED_RED);
    led_off(LED_BLUE);



}

void led_on(uint8_t led_no)
{
    uint32_t *pGpiobOdr = (uint32_t*)0x40020414; // ODR
    *pGpiobOdr |= (1 << led_no);
}

void led_off(uint8_t led_no)
{
    uint32_t *pGpiobOdr = (uint32_t*)0x40020414; // ODR
    *pGpiobOdr &= ~(1 << led_no);
}
