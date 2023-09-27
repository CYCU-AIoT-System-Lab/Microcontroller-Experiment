/*
 * Coded by belongtothenight 20230927
 *
 * Referenced code structure used in Holtek HT32 Firmware Library
 *
 * This example is to show how to use pre-defined data structure 
 * to set/reset or enable/disable functionality of microcontrollers.
 * */

#include <stdio.h>

typedef union
{
	struct
	{
		unsigned long PA   :1;
		unsigned long PB   :1;
		unsigned long I2C0 :1;
		unsigned long I2C1 :1;
		// more ...
	} Bit;
} CKCU_TypeDef;

int main(){
	printf("Initialize user-defined data type.\n");
	CKCU_TypeDef CKCU_Clock = {{0}};
	printf("PA  : %d\n", CKCU_Clock.Bit.PA);
	printf("PB  : %d\n", CKCU_Clock.Bit.PB);
	printf("I2C0: %d\n", CKCU_Clock.Bit.I2C0);
	printf("I2C1: %d\n", CKCU_Clock.Bit.I2C1);

	printf("Set/enable PA.\n");
	CKCU_Clock.Bit.PA = 1;
	printf("PA  : %d\n", CKCU_Clock.Bit.PA);
	printf("PB  : %d\n", CKCU_Clock.Bit.PB);
	printf("I2C0: %d\n", CKCU_Clock.Bit.I2C0);
	printf("I2C1: %d\n", CKCU_Clock.Bit.I2C1);

	return 0;
}
