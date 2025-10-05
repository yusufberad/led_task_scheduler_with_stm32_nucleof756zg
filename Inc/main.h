/*
 * main.h
 *
 *  Created on: Oct 4, 2025
 *      Author: YudufBera
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Stack calculations */

#define MAX_TASKS 					5

#define SIZE_TASK_STACK				1024U
#define SIZE_SCHED_STACK			1024U


#define SRAM_START					0x20010000U
#define SRAM_SIZE					( (240) * (1024) )
#define SRAM_END					( (SRAM_START) + (SRAM_SIZE) )



#define T1_STACK_START				(SRAM_END)
#define T2_STACK_START				( (SRAM_END) - (SIZE_TASK_STACK) )
#define T3_STACK_START				( (SRAM_END) - (2 * SIZE_TASK_STACK) )
#define T4_STACK_START				( (SRAM_END) - (3 * SIZE_TASK_STACK) )
#define IDLE_STACK_START				( (SRAM_END) - (4 * SIZE_TASK_STACK) )
#define SCHED_STACK_START			( (SRAM_END) - (5 * SIZE_TASK_STACK) )


#define TICK_HZ 					1000U
#define HSI_CLOCK					16000000U
#define SYSTICK_TIM_CLK				HSI_CLOCK

#define TASK_READY_STATE			0x00
#define TASK_BLOCKED_STATE			0xFF

#define INTERRUPT_DISABLE() do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK, R0"); } while(0)
#define INTERRUPT_ENABLE() do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK, R0"); } while(0)

#endif /* MAIN_H_ */
