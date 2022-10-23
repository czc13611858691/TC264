#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "timers.h"
#include "Ifx_Console.h"
#include "IfxStm.h"
#include "AsclinShellInterface.h"

void vApplicationIdleHook(void)
{
    AsclinShellInterface_run();
}

static void usart1Out_task(void *arg)
{
    (void)arg;

    while (1)
    {
        vTaskDelay(1000);
        Ifx_Console_print("freertos 1s task\r\n");
    }
}

static void usart2Out_task(void *arg)
{
    (void)arg;

    while (1)
    {
        vTaskDelay(2000);
        Ifx_Console_print("\tfreertos 2s task\r\n");
    }
}


void FreertosApp_Init(void)
{
    xTaskCreate(usart1Out_task, "task1Test", 512, (void *)666, 4, NULL);
    xTaskCreate(usart2Out_task, "task2Test", 512, (void *)666, 4, NULL);

    vTaskStartScheduler();
}