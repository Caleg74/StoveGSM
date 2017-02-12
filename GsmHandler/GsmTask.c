/*
 * GsmTask.c
 *
 *  Created on: Feb 12, 2017
 *      Author: gabri
 */
#include "GsmTask.h"
#include <ti/sysbios/knl/Task.h>
#include <ti/drivers/GPIO.h>
#include "Board.h"

#define TASKSTACKSIZE   512

char task0Stack[TASKSTACKSIZE];
Task_Struct task0Struct;


static void GsmTaskFxn(UArg arg0, UArg arg1);

//*****************************************************************************

static void GsmTaskFxn(UArg arg0, UArg arg1)
{
    while (1)
    {
        Task_sleep((UInt32)arg0);
        GPIO_toggle(EK_TM4C123GXL_LED_GREEN);
    }
}

//*****************************************************************************

void GsmTask_Start(void)
{
    Task_Params taskParams;

    /* Construct heartBeat Task  thread */
    Task_Params_init(&taskParams);
    taskParams.arg0 = 1000;
    taskParams.stackSize = TASKSTACKSIZE;
    taskParams.stack = &task0Stack;
    Task_construct(&task0Struct, (Task_FuncPtr)GsmTaskFxn, &taskParams, NULL);
}

//*****************************************************************************
