#include "stm32f7xx_hal.h"
#include "stdio.h"

/* 外部句柄（CubeMX 生成） */
//extern SDRAM_HandleTypeDef hsdram1;

/* SDRAM Mode Register definition */
//#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
//#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
//#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
//#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)

//#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
//#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)

//#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
//#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)

//#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)

//#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
//#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)



// void BSP_SDRAM_Init(void)
// {
//     FMC_SDRAM_CommandTypeDef command;
//     uint32_t mode_reg;
//     uint32_t refresh_rate;

//     /* Step 1: Clock enable command */
//     command.CommandMode            = FMC_SDRAM_CMD_CLK_ENABLE;
//     command.CommandTarget          = FMC_SDRAM_CMD_TARGET_BANK1;
//     command.AutoRefreshNumber      = 1;
//     command.ModeRegisterDefinition = 0;

//     HAL_SDRAM_SendCommand(&hsdram1, &command, HAL_MAX_DELAY);
//     HAL_Delay(1);   // >100us

//     /* Step 2: Precharge all */
//     command.CommandMode = FMC_SDRAM_CMD_PALL;
//     HAL_SDRAM_SendCommand(&hsdram1, &command, HAL_MAX_DELAY);

//     /* Step 3: Auto refresh */
//     command.CommandMode       = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
//     command.AutoRefreshNumber = 8;
//     HAL_SDRAM_SendCommand(&hsdram1, &command, HAL_MAX_DELAY);

//     /* Step 4: Load mode register */
//     mode_reg =
//         SDRAM_MODEREG_BURST_LENGTH_1 |
//         SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL |
//         SDRAM_MODEREG_CAS_LATENCY_3 |
//         SDRAM_MODEREG_OPERATING_MODE_STANDARD |
//         SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

//     command.CommandMode            = FMC_SDRAM_CMD_LOAD_MODE;
//     command.ModeRegisterDefinition = mode_reg;

//     HAL_SDRAM_SendCommand(&hsdram1, &command, HAL_MAX_DELAY);

//     /* Step 5: Set refresh rate */
//     /*
//      * Refresh rate = (SDRAM refresh period / number of rows) * FMC clock - 20
//      * 64ms / 8192 = 7.81us
//      * FMC clock = 108MHz → 7.81us * 108MHz ≈ 843
//      */
//     refresh_rate = 843;
//     HAL_SDRAM_ProgramRefreshRate(&hsdram1, refresh_rate);

// }
