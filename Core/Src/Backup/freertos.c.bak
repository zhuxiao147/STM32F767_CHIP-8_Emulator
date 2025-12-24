/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "hid_report_parser.h"
#include "app_init.h"
#include "lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
osThreadId tinyUSBTaskHandle;
const osThreadAttr_t tinyUSBTask_attributes = {
  .name = "tinyUSBTask",
  .stack_size = 2048,
  .priority = (osPriority_t) osPriorityNormal,
};

osThreadId gameTaskHandle;
const osThreadAttr_t gameTask_attributes = {
  .name = "gameTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityAboveNormal,
};
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

void Game_Task(void *argument);
void TinyUSB_Task(void *argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */

  tinyUSBTaskHandle = osThreadNew(TinyUSB_Task, NULL, &tinyUSBTask_attributes);
  gameTaskHandle = osThreadNew(Game_Task, NULL, &gameTask_attributes);
  //osThreadDef(xboxTask, Xbox_Task, osPriorityNormal, 0, 1024);
  //osThreadCreate(osThread(xboxTask), NULL);

  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for (;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
void Game_Task(void *argument)
{
    uint8_t keyupflag = 0;
    uint8_t tmpstr[32];
    hid_input_event_t event;
    LCD_Display_Dir(1);
    LCD_ShowString(10,40,260,32,32,(uint8_t*)"Apollo STM32F7"); 
		memset(tmpstr, 0, 32);
    while (1)
    {
        if (xQueueReceive(HIDInputEventQueue, &event, portMAX_DELAY) == pdTRUE)
        {
            if (event.type == HID_EVT_KEYBOARD)
            {
                keyupflag = 1;
                for (int i = 0; i < 6; i++)
                {
                    if (event.keyboard.keycode[i] != 0)
                    {   
                        keyupflag = 0;
                        if (event.keyboard.modifier & HID_KEYBOARD_MODIFIER_SHIFT)
                        {
                            LCD_Clear(WHITE);
														sprintf((char*)tmpstr,"word :%c",keymap_shift[event.keyboard.keycode[i]]);
                            LCD_ShowString(10,40,260,32,32,(uint8_t*)tmpstr); 
                            printf("Game_Task HID_EVT_KEYBOARD %c\n", keymap_shift[event.keyboard.keycode[i]]);
                        }
                        else
                        {
                            LCD_Clear(WHITE);
                            sprintf((char*)tmpstr,"word :%c",keymap[event.keyboard.keycode[i]]);
                            LCD_ShowString(10,40,260,32,32,(uint8_t*)tmpstr); 
                            printf("Game_Task HID_EVT_KEYBOARD %c\n", keymap[event.keyboard.keycode[i]]);
                        }
                    }
                }
                if (keyupflag)
                {
                  printf("Game_Task KEY UP\n");
                }
            }
            else if (event.type == HID_EVT_MOUSE)
            {
                printf("Game_Task HID_EVT_MOUSE x:%d y:%d wheel:%d buttons:%d\n", event.mouse.x, event.mouse.y, event.mouse.wheel, event.mouse.buttons);
            }
        }
    }
}

void TinyUSB_Task(void *argument)
{
    board_init();

    tusb_rhport_init_t host_init = {
    .role = TUSB_ROLE_HOST,
    .speed = TUSB_SPEED_AUTO
    };
    tusb_init(BOARD_TUH_RHPORT, &host_init);
    while (1)
    {
        tuh_task();
        osDelay(1);
    }
}

/* USER CODE END Application */

