/* Ankita Shukla 
   210550354003
 Q1- Create 3 realtime tasks each with the periodcity T1=1000ms, 
   T2=2000ms, T3=5000ms. Also create two additional task T4 and T5 where T4
   sends integer data to T5 using Messsage Queues.
*/

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

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




void tfour_task(void *data)
{
    int integer = 70;
    while(1)
    {
        printf(" task4 started \n");
        
        
        printf(" task4 ended \n");
        xQueueSend(intmq,&integer, 0);
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}


void tfive_task(void *data)
{
    int buff;
    
    while(1)
    {
        printf("task5 started \n");
        xQueueReceive(intmq,&buff, 0);
        printf("Integer from task4 is: %d\n",buff);
    
        printf(" task5 ended \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);
      
      
    }
   
}



void app_main(void)
{
    xTaskCreate(tone_task, "tone_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(ttwo_task, "ttwo_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(tthree_task, "tthree_tsk", 2048, NULL, 6, NULL);
    xTaskCreate(tfour_task, "tfour_tsk", 2048, NULL, 5, NULL);
    xTaskCreate(tfive_task, "tfive_tsk", 2048, NULL, 3, NULL);
    intmq = xQueueCreate(3, sizeof(int));
   
}

