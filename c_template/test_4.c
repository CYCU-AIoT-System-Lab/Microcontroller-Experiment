/* Coded by belongtothenight 20230930
 *
 * Referenced code structure used in Holtek HT32 Firmware Library
 *
 * This example is to show how definitions in ht32_board_config.h works.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return a pre-defined value
#define HT_GPIOA				0x1A
#define HTCFG_I2C_MASTER_PORT	(HT_GPIOA)

// Define a custom macro which take an argument and returns a value
#define ONE					    0x01
#define TIMES_FIVE(s)           (s*0x05)

// Define a macro with standard library function
#define STR					    "ABCDEFGH"
#define STRLEN(a)               strlen(a)

// Define a macro with standard library function with custum computation
#define GEN_RAND				rand() % 10

// Define a macro to perform basic math operation
#define CUBE(a)					(a*a*a)

/* STRCAT2(a, b) is using same kind of syntax, but can't be
 * simpily replicated here due to the nature of c.
 */

int main() {
	printf("1. HT_GPIOA: %d\r\n", HTCFG_I2C_MASTER_PORT);
	printf("2. %d * 5 = %d\r\n", ONE, TIMES_FIVE(ONE));
	printf("3. %s -STRLEN-> %ld\r\n", STR, STRLEN(STR));
	printf("4. Random number: %d\r\n", GEN_RAND);
	printf("5. %d cubed = %d\r\n", HT_GPIOA, CUBE(HT_GPIOA));
	printf("\r\n");
	return 0;
}

/* Reference sources:
 * 1. https://flaviocopes.com/c-return-string/
 * 2. https://www.youtube.com/watch?v=033DXBYql8w
 * */
