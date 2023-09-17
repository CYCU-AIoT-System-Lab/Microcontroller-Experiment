# GPIO / InputOutput | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

| No. |  File  |  Line   | Detail                                                                       |
| :-: | :----: | :-----: | ---------------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include ht32 library and board settings.                                     |
|  2  | main.c |  46-49  | Declare used functions.                                                      |
|  3  | main.c |   52    | Declare type "FlagStatus" variable "TmpStatus" defined in "ht32f5xxxx_01.h". |
|  4  | main.c |   82    | Perform system clock (AHB) related configuration.                            |
|  5  | main.c |   103   | Set all clocks in AHB off.                                                   |
|  6  | main.c | 105-109 | Set used clocks in AHB on.                                                   |
|  7  | main.c |   110   | Apply set AHB settings.                                                      |
|  8  | main.c |   85    | Perform GPIO configuration for input usage.                                  |
|  9  | main.c | 121-122 | Set AFIO of used pins.                                                       |
| 10  | main.c | 125-126 | Set GPIO direction of used pins.                                             |
| 11  | main.c | 129-130 | Set GPIO pulling direction of used pins.                                     |
| 12  | main.c | 132-133 | Enable GPIO.                                                                 |
| 13  | main.c |   88    | Perform GPIO configuration for output usage.                                 |
| 14  | main.c | 144-145 | Set AFIO of used pins.                                                       |
| 15  | main.c | 148-149 | Set GPIO direction of used pins.                                             |
| 16  | main.c |   93    | Infinitely looping the set GPIO main routine.                                |
| 17  | main.c |   159   | Read PB12 state as SET/high or RESET/low.                                    |
| 18  | main.c |   160   | Write the state of PB12 to PC14.                                             |
| 19  | main.c |   163   | Read PD1 state as SET/high or RESET/low.                                     |
| 20  | main.c |   164   | Write the state of PD1 to PC15.                                              |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | AHB     | ARM-designed high-performance bus            |
|  2  | GPIO    | General Purpose I/O (GPIO)                   |
|  3  | AFIO    | Alternate Function Input/Output Control Unit |
