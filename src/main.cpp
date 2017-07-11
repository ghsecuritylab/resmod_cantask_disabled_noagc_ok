/******************************************************************************
 |
 | 	FILENAME:  main.cpp
 |
 |	Copyright 2016 Adara Systems Ltd. as an unpublished work.
 |	All Rights Reserved.
 |
 |	The information contained herein is confidential property of Adara Systems
 |	Ltd. The use, copying, transfer or disclosure of such information is
 |	prohibited except by express written agreement with Adara Systems Ltd.
 |
 |  	DESCRIPTION:
 |
 |  	PUBLIC FUNCTIONS:
 |
 |
 |  	NOTES:
 |
 |  	AUTHOR(S):  Roque
 |	    DATE:		Oct 31, 2016
 |
 ******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include <FreeRTOS.h>
#include <task.h>
#include <segger/SEGGER_SYSVIEW.h>
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern unsigned int _HeapCCM_Begin;
extern unsigned int _HeapCCM_Limit;

// Sample pragmas to cope with warnings. Please note the related line at
// the end of this function, used to pop the compiler diagnostics status.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wreturn-type"

int
main(int argc, char* argv[])
{
	/* initialize rtos */
	/* define the heap regions for the rtos */
	HeapRegion_t xhregions[] =
	{
		{NULL, 0},
		{NULL, 0}
	};
	xhregions[0].pucStartAddress = (uint8_t *)&_HeapCCM_Begin;
	xhregions[0].xSizeInBytes = (size_t)((size_t)&_HeapCCM_Limit -
								(size_t)&_HeapCCM_Begin);
	vPortDefineHeapRegions(xhregions);

	/* perform support lib initialization */
	/* segger debug utils init */
	SEGGER_SYSVIEW_Conf();

	/* start the rtos */
	vTaskStartScheduler();

	/* should never return, do something that makes sense */
	while (1)
	{
	}
}

#pragma GCC diagnostic pop

// ----------------------------------------------------------------------------
