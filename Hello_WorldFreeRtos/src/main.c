/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "FreeRTOS.h"   // must include
#include "task.h"

// function protoype
void v1_task_handler(void *param);
void v2_task_handler(void *param);

TaskHandle_t xTaskHandle1=NULL;
TaskHandle_t xTaskHandle2=NULL;

int main(void)
{
	// The current configuration uses the PLL and sets the system clock to its max frequency 180 MHz
	// The current task does not demand such a high clock frequency hence the PLL is turned off and the clock source used is HSI which is the default source and has 16 MHz frequency
	// 1. De-init the clock settings
	RCC_DeInit();

	//2. changes are required to be done with the SystemCoreClock in the RTOSConfig file
	// the RCC_DeInit() resets the clock config to its default configuration and the HSI is the default clock source
	SystemCoreClockUpdate(); // updates the variable in the RTOSConfig file to HSI

	//3. Create the tasks with the help of taskcreate API
	xTaskCreate(v1_task_handler,"Task-1",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle1);//task 1

	xTaskCreate(v2_task_handler,"Task-2",configMINIMAL_STACK_SIZE,NULL,2,&xTaskHandle2);//task 2

	//4. The tasks are created and then are scheduled
	vTaskStartScheduler(); // control goes to the tasks and is never returned , hence the below infinite loop is never executed

	for(;;);
}

void v1_task_handler(void *param)
{
	while(1); // since the task is always running
}

void v2_task_handler(void *param)
{
	while(1);
}
