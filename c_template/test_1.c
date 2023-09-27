/*
 * Coded by belongtothenight 20230927
 *
 * Referenced code structure used in Holtek HT32 Firmware Library
 *
 * This example is to show how to acquire pre-defined values from 
 * library in order to use library correctly and not messing up 
 * low-level settings.
 * */

#include <stdio.h>

// Pre-defined demonstration
#define LEDn 3
const int LED1 = 0x0A;
const int LED2 = 0x0B;
const int LED3 = 0x0C;

// Library provided interface demonstration
const int LED_GPIO[LEDn] = {LED1, LED2, LED3};

// Custom code to access provided interface
int main() {
	int LEDid = LED_GPIO[1];
	printf("Acquiring LED pre-defined index: %d\n", LEDid);
	return 0;
}
