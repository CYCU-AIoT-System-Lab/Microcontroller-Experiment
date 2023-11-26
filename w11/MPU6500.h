/* Include */
#include "ht32.h"
#include "ht32_board.h"

/* MPU6500 Register */

#define Acc_Config_Reg 0x1C

#define AccXH_Reg 0x3B
#define AccXL_Reg 0x3C
#define AccYH_Reg 0x3D
#define AccYL_Reg 0x3E
#define AccZH_Reg 0x3F
#define AccZL_Reg 0x40

#define GyroXH_Reg 0x43
#define GyroXL_Reg 0x44
#define GyroYH_Reg 0x45
#define GyroYL_Reg 0x46
#define GyroZH_Reg 0x47
#define GyroZL_Reg 0x48

/* Constant */
u8 Axis[3] = {'X', 'Y', 'Z'};

typedef enum
{
    mpu6500_scale_16G  = 0x18,
    mpu6500_scale_8G   = 0x10,
    mpu6500_scale_4G   = 0x08,
    mpu6500_scale_2G   = 0x00,
} MPU6500_Acc_Scale;