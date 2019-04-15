#include "stdio.h"
#include "menu.h"

//pFunction JumpToApplication;
uint32_t JumpAddress;
uint32_t FlashProtection = 0;
uint8_t aFileName[108];


static void SerialDownload(void);
static void SerialUpload(void);


void Main_Menu(void)
{
  uint8_t key = 0;

  printf("\r\n======================================================================");
  printf("\r\n=              (C) COPYRIGHT 2016 STMicroelectronics                 =");
  printf("\r\n=                                                                    =");
  printf("\r\n=          STM32F4xx In-Application Programming Application          =");
  printf("\r\n=                                                                    =");
  printf("\r\n=                       By MCD Application Team                      =");
  printf("\r\n======================================================================");
  printf("\r\n\r\n");


  while (1)
  {

    // Test if any sector of Flash memory where user application will be loaded is write protected 
    FlashProtection = FLASH_If_GetWriteProtectionStatus();
    
    printf("\r\n=================== Main Menu ============================\r\n\n");
    printf("  Download image to the internal Flash ----------------- 1\r\n\n");
    printf("  Upload image from the internal Flash ----------------- 2\r\n\n");
    printf("  Execute the loaded application ----------------------- 3\r\n\n");

    if(FlashProtection != FLASHIF_PROTECTION_NONE)
    {
      printf((uint8_t *)"  Disable the write protection ------------------------- 4\r\n\n");
    }
    else
    {
      printf((uint8_t *)"  Enable the write protection -------------------------- 4\r\n\n");
    }
    printf((uint8_t *)"==========================================================\r\n\n");

    // Clean the input path 
    __HAL_UART_FLUSH_DRREGISTER(&uartHandle);
	

    // Receive key 
    HAL_UART_Receive(&uartHandle, &key, 1, 0xffffffff);

    switch (key){
    case '1' :
      // Download user application in the Flash
      SerialDownload();
      break;
    case '2' :
      // Upload user application from the Flash 
      SerialUpload();
      break;
    case '3' :
      printf("Start program execution......\r\n\n");
      // execute the new program 
      //JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
      // Jump to user application 
      //JumpToApplication = (pFunction) JumpAddress;
      // Initialize user application's Stack Pointer 
      //__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
      //JumpToApplication();
      break;
    case '4' :
      if (FlashProtection != FLASHIF_PROTECTION_NONE)
      {
        // Disable the write protection 
        if (FLASH_If_WriteProtectionConfig(OB_WRPSTATE_DISABLE) == HAL_OK)
        {
          printf("Write Protection disabled...\r\n");
          printf("System will now restart...\r\n");
          // Launch the option byte loading 
          HAL_FLASH_OB_Launch();
          // Ulock the flash 
          HAL_FLASH_Unlock();
        }
        else
        {
          printf("Error: Flash write un-protection failed...\r\n");
        }
      }
      else
      {
        if (FLASH_If_WriteProtectionConfig(OB_WRPSTATE_ENABLE) == HAL_OK)
        {
          printf("Write Protection enabled...\r\n");
          printf("System will now restart...\r\n");
          // Launch the option byte loading 
          HAL_FLASH_OB_Launch();
        }
        else
        {
          printf("Error: Flash write protection failed...\r\n");
        }
      }
      break;
    default:
	    printf("Invalid Number ! ==> The number should be either 1, 2, 3 or 4\r");
	break;
    }
  }

}

void SerialUpload(void)
{
  uint8_t status = 0;

  printf("\n\n\rSelect Receive File\n\r");

  HAL_UART_Receive(&uartHandle, &status, 1, 0xffffffff);
  if ( status == CRC16){
    // Transmit the flash image through ymodem protocol 
    status = Ymodem_Transmit((uint8_t*)APPLICATION_ADDRESS, (const uint8_t*)"UploadedFlashImage.bin", USER_FLASH_SIZE);

    if (status != 0)
    {
      printf("\n\rError Occurred while Transmitting File\n\r");
    }
    else{
      printf("\n\rFile uploaded successfully \n\r");
    }
  }
}

void SerialDownload(void)
{
    
  uint8_t number[11] = {0};
  uint32_t size = 0;
  COM_StatusTypeDef result;


  printf("Waiting for the file to be sent ... (press 'a' to abort)\n\r");
  result = Ymodem_Receive( &size );
  if (result == COM_OK)
  {
    printf((uint8_t *)"\n\n\r Programming Completed Successfully!\n\r--------------------------------\r\n Name: ");
    printf(aFileName);
    UTIL1_Num32sToStr(number,sizeof(number), size);
    printf("\n\r Size: ");
    printf(number);
    printf(" Bytes\r\n");
    printf("-------------------\n");
  }
  else if (result == COM_LIMIT)
  {
    printf((uint8_t *)"\n\n\rThe image size is higher than the allowed space memory!\n\r");
  }
  else if (result == COM_DATA)
  {
    printf((uint8_t *)"\n\n\rVerification failed!\n\r");
  }
  else if (result == COM_ABORT)
  {
    printf((uint8_t *)"\r\n\nAborted by user.\n\r");
  }
  else
  {
    printf((uint8_t *)"\n\rFailed to receive the file!\n\r");
  }

}