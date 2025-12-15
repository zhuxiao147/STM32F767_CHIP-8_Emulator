/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file            : usb_host.c
  * @version         : v1.0_Cube
  * @brief           : This file implements the USB Host
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

#include "usb_host.h"
#include "usbh_core.h"
#include "usbh_hid.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USB Host core handle declaration */
USBH_HandleTypeDef hUsbHostFS;
ApplicationTypeDef Appli_state = APPLICATION_IDLE;

/*
 * -- Insert your variables declaration here --
 */
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*
 * user callback declaration
 */
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id);

/*
 * -- Insert your external function declaration here --
 */
/* USER CODE BEGIN 1 */
void Scan_All_HID_Interfaces(USBH_HandleTypeDef *phost)
{
    USBH_CfgDescTypeDef *cfg = &phost->device.CfgDesc;

    printf("Total Interfaces: %d\r\n", cfg->bNumInterfaces);

    for (uint8_t i = 0; i < cfg->bNumInterfaces; i++)
    {
        USBH_InterfaceDescTypeDef *itf = &cfg->Itf_Desc[i];

        printf("IF #%d: Class=0x%02X Sub=0x%02X Proto=0x%02X\r\n",
               itf->bInterfaceNumber,
               itf->bInterfaceClass,
               itf->bInterfaceSubClass,
               itf->bInterfaceProtocol);
    }
}

int8_t Find_Mouse_Interface(USBH_HandleTypeDef *phost)
{
    USBH_CfgDescTypeDef *cfg = &phost->device.CfgDesc;

    for (uint8_t i = 0; i < cfg->bNumInterfaces; i++)
    {
        USBH_InterfaceDescTypeDef *itf = &cfg->Itf_Desc[i];

        if (itf->bInterfaceClass == USB_HID_CLASS &&
            itf->bInterfaceProtocol == 0x02) // 0x02 Ϊ���Э��
        {
            return itf->bInterfaceNumber;
        }
    }

    return -1;
}

/* USER CODE END 1 */

/**
  * Init USB host library, add supported class and start the library
  * @retval None
  */
void MX_USB_HOST_Init(void)
{
  /* USER CODE BEGIN USB_HOST_Init_PreTreatment */

  /* USER CODE END USB_HOST_Init_PreTreatment */

  /* Init host Library, add supported class and start the library. */
  if (USBH_Init(&hUsbHostFS, USBH_UserProcess, HOST_FS) != USBH_OK)
  {
    Error_Handler();
  }
  if (USBH_RegisterClass(&hUsbHostFS, USBH_HID_CLASS) != USBH_OK)
  {
    Error_Handler();
  }
  if (USBH_Start(&hUsbHostFS) != USBH_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USB_HOST_Init_PostTreatment */

  /* USER CODE END USB_HOST_Init_PostTreatment */
}

/*
 * user callback definition
 */
static void USBH_UserProcess  (USBH_HandleTypeDef *phost, uint8_t id)
{
  /* USER CODE BEGIN CALL_BACK_1 */
	
	int8_t mouse_if = Find_Mouse_Interface(phost);
  switch(id)
  {
  case HOST_USER_SELECT_CONFIGURATION:
  printf("USB device configuration selected\r\n");
  break;

  case HOST_USER_DISCONNECTION:
  printf("USB device disconnected\r\n");
  Appli_state = APPLICATION_DISCONNECT;
  break;

  case HOST_USER_CLASS_ACTIVE:
  Appli_state = APPLICATION_READY;
  printf("USB device ready\r\n");
  Scan_All_HID_Interfaces(phost);
  if (mouse_if >= 0)
  {
      printf("Select Mouse Interface: %d\r\n", mouse_if);
      USBH_SelectInterface(phost, mouse_if);
  }
  break;

  case HOST_USER_CONNECTION:
  printf("USB device connected\r\n");
  Appli_state = APPLICATION_START;
  break;

  default:
  break;
  }
  /* USER CODE END CALL_BACK_1 */
}

/**
  * @}
  */

/**
  * @}
  */

