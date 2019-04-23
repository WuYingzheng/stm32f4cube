#include "stm32f4xx.h"
#include "usbd_storage.h"
#include "uart_log.h"
#include "string.h"

#define STORAGE_LUN_NBR                 1  
#define STORAGE_BLK_NBR                 128  
#define STORAGE_BLK_SIZ                 512
#define STORAGE_CAPACITY                STORAGE_BLK_NBR * STORAGE_BLK_SIZ


// 注意如果这边是定义一个二维数组，比如uint8_t MEMBUF[STORAGE_BLK_NBR][STORAGE_BLK_SIZ];
// MEMBUF, 那么引用这个地址超过了一维地址的长度，就会产生hard_fault(), e.g.
// memcpy(dest,MEMBUF+1*STORAGE_BLK_SIZ, STORAGE_BLK_SIZ), 但编译的时候可以通过
// ？？？所以比较疑惑，不应该是线性连续地址吗？难道是源码会检查地址？
volatile uint8_t MEMBUF[STORAGE_BLK_NBR*STORAGE_BLK_SIZ];

/* USB Mass storage Standard Inquiry Data */
const int8_t  STORAGE_Inquirydata_FS[] = {/* 36 */
  
  /* LUN 0 */
  0x00,        
  0x80,        
  0x02,        
  0x02,
  (STANDARD_INQUIRY_DATA_LEN - 5),
  0x00,
  0x00,    
  0x00,
  'S', 'T', 'M', ' ', ' ', ' ', ' ', ' ', /* Manufacturer : 8 bytes */
  'P', 'r', 'o', 'd', 'u', 'c', 't', ' ', /* Product      : 16 Bytes */
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  '0', '.', '0' ,'1',                     /* Version      : 4 Bytes */
};


extern USBD_HandleTypeDef hUsbDeviceFS;

FLASH_EraseInitTypeDef EraseInitStruct;
uint32_t SectorError=0;

static int8_t STORAGE_Init_FS (uint8_t lun);
static int8_t STORAGE_GetCapacity_FS (uint8_t lun, 
                           uint32_t *block_num, 
                           uint16_t *block_size);
static int8_t  STORAGE_IsReady_FS (uint8_t lun);
static int8_t  STORAGE_IsWriteProtected_FS (uint8_t lun);
static int8_t STORAGE_Read_FS (uint8_t lun, 
                        uint8_t *buf, 
                        uint32_t blk_addr,
                        uint16_t blk_len);
static int8_t STORAGE_Write_FS (uint8_t lun, 
                        uint8_t *buf, 
                        uint32_t blk_addr,
                        uint16_t blk_len);
static int8_t STORAGE_GetMaxLun_FS (void);


/* USER CODE END PRIVATE_FUNCTIONS_DECLARATION */
  
USBD_StorageTypeDef USBD_DISK_fops =
{
  STORAGE_Init_FS,
  STORAGE_GetCapacity_FS,
  STORAGE_IsReady_FS,
  STORAGE_IsWriteProtected_FS,
  STORAGE_Read_FS,
  STORAGE_Write_FS,
  STORAGE_GetMaxLun_FS,
  (int8_t *)STORAGE_Inquirydata_FS,
};

/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : STORAGE_Init_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t STORAGE_Init_FS (uint8_t lun)
{
  printf("STORAGE Init FS\r\n");  
  return (USBD_OK);
}

/*******************************************************************************
* Function Name  : STORAGE_GetCapacity_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t STORAGE_GetCapacity_FS (uint8_t lun, uint32_t *block_num, uint16_t *block_size)
{
  printf("STORAGE GetCapacity FS: lun is %d\r\n",lun); 
  /* USER CODE BEGIN 3 */   
  *block_num  = STORAGE_BLK_NBR;
  *block_size = STORAGE_BLK_SIZ;
  return (USBD_OK);
}

/*******************************************************************************
* Function Name  : STORAGE_IsReady_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t  STORAGE_IsReady_FS (uint8_t lun)
{
  //printf("STORAGE IsReady: lun is %d\r\n",lun);
  return (USBD_OK);
}

/*******************************************************************************
* Function Name  : STORAGE_IsWriteProtected_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t  STORAGE_IsWriteProtected_FS (uint8_t lun)
{
  printf("STORAGE IsReady: lun is %d\r\n",lun);
  return (USBD_OK);
}

/*******************************************************************************
* Function Name  : STORAGE_Read_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t STORAGE_Read_FS (uint8_t lun, 
                        uint8_t *buf, 
                        uint32_t blk_addr,                       
                        uint16_t blk_len)
{
  uint32_t i;
  printf("STORAGE Read FS: lun %d, blk_addr %d,blk_len %d\r\n",lun,blk_addr,blk_len);
    switch(lun)
    {
      case 0:
        memcpy(buf,(void *)(MEMBUF+STORAGE_BLK_SIZ * blk_addr), blk_len*STORAGE_BLK_SIZ);
        break;
      default:
        return (USBD_FAIL);
    }
    
  return (USBD_OK);
   
}

/*******************************************************************************
* Function Name  : STORAGE_Write_FS
* Description    :
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t STORAGE_Write_FS (uint8_t lun, 
                         uint8_t *buf, 
                         uint32_t blk_addr,
                         uint16_t blk_len)
{
  uint8_t i = 0;
       
    uint16_t j = 0;
    
    printf("STORAGE Write FS: lun %d, blk_addr %d,blk_len %d\r\n",lun,blk_addr,blk_len);
    switch(lun)
    {
      case 0:
        memcpy((void *)(MEMBUF+STORAGE_BLK_SIZ*blk_addr), buf,blk_len*STORAGE_BLK_SIZ);
        break;
      default:
        return (USBD_FAIL);
    } 
  return (USBD_OK);
}

/*******************************************************************************
* Function Name  : STORAGE_GetMaxLun_FS
* Description    : 
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/
int8_t STORAGE_GetMaxLun_FS (void)
{
  /* USER CODE BEGIN 8 */ 
  return (STORAGE_LUN_NBR - 1);
  /* USER CODE END 8 */ 
}
