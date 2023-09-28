 /* Coded by belongtothenight 20230928
  *
  * Referenced code structure used in Holtek HT32 Firmware Library
  *
  * This example is to show how to use "->" (arrow operator) to
  * modify pre-defined object with object pointer.
  * */

#include <stdio.h>

typedef struct
{
	int CR;
	int IER;
	int ADDR;
	int SR;
	// more ...
} HT_I2C_TypeDef;

HT_I2C_TypeDef I2C_TypeDef = {0x0};

int main() {
	printf("Create pointer object to point to created object\n");
	HT_I2C_TypeDef *I2C_Init = &I2C_TypeDef;
	printf("I2C_TypeDef.CR   = %d\n", I2C_Init->CR);
	printf("I2C_TypeDef.IER  = %d\n", I2C_Init->IER);
	printf("I2C_TypeDef.ADDR = %d\n", I2C_Init->ADDR);
	printf("I2C_TypeDef.SR   = %d\n", I2C_Init->SR);

	printf("Assign value to pointer object\n");
	I2C_Init->CR = 0xA;
	printf("I2C_TypeDef.CR   = %d\n", I2C_Init->CR);
	printf("I2C_TypeDef.IER  = %d\n", I2C_Init->IER);
	printf("I2C_TypeDef.ADDR = %d\n", I2C_Init->ADDR);
	printf("I2C_TypeDef.SR   = %d\n", I2C_Init->SR);
	return 0;
}
