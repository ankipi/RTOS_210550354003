/* Ankita Shukla 
   210550354003
 Q2- Create 3 realtime tasks each with the periodcity T1=1000ms, T2=2000ms, T3=5000ms. Also create use oneshot software timer to trigger a callback function from T3 after 10000ms.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

QueueHandle_t intmq;
void tone_task(void *data)
{
    while(1)
    {
        printf(" task1 started \n");
        //...............//
        printf(" task1 ended \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void ttwo_task(void *data)
{
    while(1)
    {
        printf(" task2 started \n");
        //...............//
        printf(" task2 ended \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void tthree_task(void *data)
{
    while(1)
    {
        printf(" task3 started \n");
        //...............//
        printf(" task3 ended \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}

void *const timer_id;
TimerHandle_t timer_handle;
void task3(void *params)

{
    timer_handle = xTimerCreate("timer",(10000
 /portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)

{
    printf("Callback\n");
}




