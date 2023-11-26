/* Includes ------------------------------------------------------------------------------------------------*/
#include "ht32.h"
#include "ht32_board.h"
#include "ht32_board_config.h"
#include "MPU6500.h"

/* Private constants ---------------------------------------------------------------------------------------*/
#define I2C_MASTER_ADDRESS     0x0A
#define I2C_SLAVE_ADDRESS      0x68
#define ClockSpeed             400000
// #define Read_Delay             0xFFFFF
#define Read_Delay             0xFFFFFF
#define MV_CURSOR_UP           "\033[2A"
#define FORMAT_RED             "\033[31m"
#define FORMAT_GREEN           "\033[32m"
#define FORMAT_BLUE            "\033[34m"
#define FORMAT_BOLD            "\033[1m"
#define FORMAT_RESET           "\033[0m"

/* Private function prototypes -----------------------------------------------------------------------------*/
void I2CMaster_Configuration(void);
void MPU6500_I2C_Write_OneByte(u8 reg_addr, u8 reg_value);
u8 MPU6500_I2C_Read_OneByte(u8 reg_addr);
u16 Get_HL_Value(u8 high_reg, u8 low_reg);
void Set_Acc_Scale_Select(u8 scale);
void Show_Acc_Scale_Select(void);
double Acc_Scale(u16 raw_value);

/* Private variables ---------------------------------------------------------------------------------------*/
u8 Device_ID;
u16 Acc_Raw_Value[3];

/* Global functions ----------------------------------------------------------------------------------------*/
u32 i;

/*********************************************************************************************************//**
  * @brief  Main program.
  * @retval None
  ***********************************************************************************************************/
int main(void)
{
    /* Initialize USART and I2C communication */
    RETARGET_Configuration();	
    I2CMaster_Configuration();
    printf("%s\n\n\rThis example demonstrates how to use I2C to communicate with MPU6500\n\r", FORMAT_RESET);

    /* Confirm connected I2C device */
    Device_ID = MPU6500_I2C_Read_OneByte(0x75);
    printf("I2C slave device ID: %02x\n\r", Device_ID); 
    while(!(Device_ID ==  0x70));
    printf("Accelometer MPU6500 is connected\n\r");

    /* Configure MPU6500 acceleration scale as 2G */
    Set_Acc_Scale_Select(mpu6500_scale_2G);
    Show_Acc_Scale_Select();

    printf("Live data from MPU6500:\n\r");
    while (1){
        /* Acquire X & Z acceleration and saved in memory */
        Acc_Raw_Value[0] = Get_HL_Value(AccXH_Reg , AccXL_Reg);
        Acc_Raw_Value[2] = Get_HL_Value(AccZH_Reg , AccZL_Reg);
        
        printf("Acc%s%s%c%s --> Raw_Value_DEC: %05d , Raw_Value_HEX: %04x , Acc_Scale: %f\t\n\r", FORMAT_BOLD, FORMAT_BLUE, Axis[0], FORMAT_RESET, Acc_Raw_Value[0], Acc_Raw_Value[0], Acc_Scale(Acc_Raw_Value[0]));
        printf("Acc%s%s%c%s --> Raw_Value_DEC: %05d , Raw_Value_HEX: %04x , Acc_Scale: %f\t\n\r", FORMAT_BOLD, FORMAT_RED, Axis[2], FORMAT_RESET, Acc_Raw_Value[2], Acc_Raw_Value[2], Acc_Scale(Acc_Raw_Value[2]));
        
        /* Wait for 1048575 CPU cycle and continue*/
        for(i=0 ; i<Read_Delay ; i++);

        /* Move cursor up 1 line */
        printf("%s\r", MV_CURSOR_UP);
        /* Move cursor up 2 line */
        // printf("%s%s\n\r", MV_CURSOR_UP, MV_CURSOR_UP);
    }
}

/*********************************************************************************************************//**
  * @brief  Configure the I2C.
  * @retval None
  ***********************************************************************************************************/
void I2CMaster_Configuration(void)
{
    {   /* Configure clock */
        CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};
        CKCUClock.Bit.I2C0 = 1;
        CKCUClock.Bit.AFIO = 1;
        CKCUClock.Bit.PB   = 1;
        CKCU_PeripClockConfig(CKCUClock, ENABLE);
    }

    /* Configure AFIO */
    AFIO_GPxConfig(GPIO_PB, AFIO_PIN_0, AFIO_MODE_7);
    AFIO_GPxConfig(GPIO_PB, AFIO_PIN_1, AFIO_MODE_7);

    /* Configure GPIO */
    GPIO_PullResistorConfig(HT_GPIOB, GPIO_PIN_0, GPIO_PR_UP);
    GPIO_PullResistorConfig(HT_GPIOB, GPIO_PIN_1, GPIO_PR_UP);
    
    {   /* Configure I2C */
        I2C_InitTypeDef  I2C_InitStructure;
        I2C_InitStructure.I2C_GeneralCall = DISABLE;
        I2C_InitStructure.I2C_AddressingMode = I2C_ADDRESSING_7BIT;
        I2C_InitStructure.I2C_Acknowledge = DISABLE;
        I2C_InitStructure.I2C_OwnAddress = I2C_MASTER_ADDRESS;
        I2C_InitStructure.I2C_Speed = ClockSpeed;
        I2C_InitStructure.I2C_SpeedOffset = 0;
        I2C_Init(HT_I2C0, &I2C_InitStructure);
    }
  
    /* Enable I2C */
    I2C_Cmd(HT_I2C0, ENABLE);
}

/*********************************************************************************************************//**
  * @brief  Read a byte of data from MPU6500 with I2C.
  * @param  reg_addr: register address.
  * @retval receive_data: data received from MPU6500.
  ***********************************************************************************************************/
u8 MPU6500_I2C_Read_OneByte(u8 reg_addr)
{
    u8 receive_data = 0;
    
    /* Wait till idle */
    while (I2C_ReadRegister(HT_I2C0, I2C_REGISTER_SR)&0x80000);
    /* Send ACK to start transmission */
    I2C_AckCmd(HT_I2C0, ENABLE);
    /* Config I2C target address and writing mode */
    I2C_TargetAddressConfig(HT_I2C0, I2C_SLAVE_ADDRESS, I2C_MASTER_WRITE);
    /* Wait till START signal is sent */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_SEND_START));
    /* Wait till I2C Tx changed into master transmitter mode */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_TRANSMITTER_MODE));
    /* Wait till I2C Tx register is empty */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_TX_EMPTY));
    /* Send register address */
    I2C_SendData(HT_I2C0, reg_addr); 
    /* Config I2C target address and writing mode */
    I2C_TargetAddressConfig(HT_I2C0, I2C_SLAVE_ADDRESS, I2C_MASTER_READ);
    /* Wait till START signal is sent */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_SEND_START));
    /* Wait till I2C Rx changed into master receiver mode */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_RECEIVER_MODE));
    /* Disable I2C ACK signal */
    I2C_AckCmd(HT_I2C0, DISABLE);
    /* Wait till I2C Rx register is filled */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_RX_NOT_EMPTY));
    /* Retrieve data from register to memory */
    receive_data = I2C_ReceiveData(HT_I2C0);
    /* I2C send STOP signal */
    I2C_GenerateSTOP(HT_I2C0);
    return receive_data;
}

/*********************************************************************************************************//**
  * @brief  Write a byte of data to MPU6500 with I2C.
  * @param  reg_addr: register address.
  * @param  register_value: data to be written to MPU6500.
  * @retval None
  ***********************************************************************************************************/
void MPU6500_I2C_Write_OneByte(u8 reg_addr, u8 register_value)
{
    /* Wait till idle */
    while (I2C_ReadRegister(HT_I2C0, I2C_REGISTER_SR)&0x80000);
    /* Send ACK to start transmission */
    I2C_AckCmd(HT_I2C0, ENABLE);
    /* Send I2C START & I2C slave address for write */
    I2C_TargetAddressConfig(HT_I2C0, I2C_SLAVE_ADDRESS, I2C_MASTER_WRITE);
    /* Check on Master Transmitter STA condition and clear it */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_SEND_START));
    /* Check on Master Transmitter ADRS condition and clear it */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_TRANSMITTER_MODE));
    /* Check on Master Transmitter TXDE condition */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_TX_EMPTY));
    /* Send register address */
    I2C_SendData(HT_I2C0, reg_addr); 
    /* Wait till Rx data register is empty */
    while (!I2C_CheckStatus(HT_I2C0, I2C_MASTER_TX_EMPTY));
    /* Transmit data */
    I2C_SendData(HT_I2C0, register_value); 
    /* Send STOP to end transmission */
    I2C_GenerateSTOP(HT_I2C0);
}

/*********************************************************************************************************//**
  * @brief  Configure the MPU6500 acceleration scale.
  * @param  scale: acceleration scale.
  * @retval None
  ***********************************************************************************************************/
void Set_Acc_Scale_Select(u8 scale)
{
    u8 scale_data;
    
    scale_data = (MPU6500_I2C_Read_OneByte(Acc_Config_Reg) & 0xE7) | scale;
    MPU6500_I2C_Write_OneByte(Acc_Config_Reg, scale_data); 
}

/*********************************************************************************************************//**
  * @brief  Show the MPU6500 acceleration scale.
  * @retval None
  ***********************************************************************************************************/
void Show_Acc_Scale_Select(void)
{
    u8 scale;
    
    scale = MPU6500_I2C_Read_OneByte(Acc_Config_Reg) & 0x18;
    
    switch(scale)
    {
        case mpu6500_scale_2G:
            printf("Selected Acc Scale: +-2G\n\r");
            break;
        case mpu6500_scale_4G:
            printf("Selected Acc Scale: +-4G\n\r");
            break;
        case mpu6500_scale_8G:
            printf("Selected Acc Scale: +-8G\n\r");
            break;
        case mpu6500_scale_16G:
            printf("Selected Acc Scale: +-16G\n\r");
            break;
        default:
            printf("Selected Acc Scale: error\n\r");
            printf("Please check set value\n\r");
            while (1);
            break;
    }
}

/*********************************************************************************************************//**
  * @brief  Get the high and low value from MPU6500 and combine them.
  * @param  high_reg: high register address.
  * @param  low_reg: low register address.
  * @retval value: combined value.
  ***********************************************************************************************************/
u16 Get_HL_Value(u8 high_reg, u8 low_reg)
{
    u8 h_Value, l_Value;
    
    h_Value = MPU6500_I2C_Read_OneByte(high_reg);
    l_Value = MPU6500_I2C_Read_OneByte(low_reg);
    
    /* h_value left 8 bits or l_value = (h_value+l_value)*/
    return (((u16)h_Value << 8) | l_Value);
}

/*********************************************************************************************************//**
  * @brief  Calculate the acceleration value.
  * @param  raw_value: raw value from MPU6500.
  * @retval Converted acceleration value.
  ***********************************************************************************************************/
double Acc_Scale(u16 raw_value)
{
    u8 scale;
    double per_digit;
    
    scale = MPU6500_I2C_Read_OneByte(Acc_Config_Reg) & 0x18;
    switch(scale)
    {
        case mpu6500_scale_2G:
            per_digit = 2.0/0x8000;
            break;
        case mpu6500_scale_4G:
            per_digit = 4.0/0x8000;
            break;
        case mpu6500_scale_8G:
            per_digit = 8.0/0x8000;
            break;
        case mpu6500_scale_16G:
            per_digit = 16.0/0x8000;
            break;
        default:
            break;
    }
    return ((signed short)raw_value * per_digit);
}

#if (HT32_LIB_DEBUG == 1)
/*********************************************************************************************************//**
  * @brief  Report both the error name of the source file and the source line number.
  * @param  filename: pointer to the source file name.
  * @param  uline: error line source number.
  * @retval None
  ***********************************************************************************************************/
void assert_error(u8* filename, u32 uline)
{
  /*
     This function is called by IP library that the invalid parameters has been passed to the library API.
     Debug message can be added here.
     Example: printf("Parameter Error: file %s on line %d\n\r", filename, uline);
  */

  while (1)
  {
  }
}
#endif


/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
