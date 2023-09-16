# CKCU / Clock_Configuration | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

| No. |        File        |  Line   | Detail                                                                                                                                             |
| :-: | :----------------: | :-----: | -------------------------------------------------------------------------------------------------------------------------------------------------- |
|  1  |       main.c       |  29-31  | Include essential libraries.                                                                                                                       |
|  2  |       main.c       |   46    | Define parameter "DELAY_TIME" for 0d131071 units.                                                                                                  |
|  3  |       main.c       |  49-55  | Declare later used functions.                                                                                                                      |
|  4  |       main.c       |   58    | Declare private "CKCU_ClocksTypeDef" type variable "ClockFreq" defined in "ht32f5xxxx_ckcu.h".                                                     |
|  5  |       main.c       |   59    | Declare private "CKCU_PLLInitTypeDef" type variable "PLLInit" defined in "ht32f5xxxx_ckcu.h".                                                      |
|  6  |       main.c       |  83-93  | Based on defined board in "ht32_board_config.h", execute function correspondingly. In this case, 8MHz.                                             |
|  7  |       main.c       |   132   | Declare private variable "ClockStatus" type "ErrStatus" defined in "ht32f5xxxx_01.h".                                                              |
|  8  |       main.c       |   135   | Reset system clock.                                                                                                                                |
|  9  |       main.c       |   138   | Activate high speed external crystal oscillator, HSE.                                                                                              |
| 10  |       main.c       |   141   | Wait till HSE is ready or timeout.                                                                                                                 |
| 11  |       main.c       |   143   | If HSE error, into infinite loop. If HSE success, continue.                                                                                        |
| 12  |       main.c       | 146-148 | Assign PLL configurations to parameter "PLLInit".                                                                                                  |
| 13  |       main.c       |   149   | Configure PLL with parameter "PLLInit".                                                                                                            |
| 14  |       main.c       |   151   | Enable CKCU PLL.                                                                                                                                   |
| 15  | ht32f5xxxx_ckcu.c  |   259   | Check parameters.                                                                                                                                  |
| 16  | ht32f5xxxx_ckcu.c  |   261   | Write value to GCCR.                                                                                                                               |
| 17  |       main.c       |   154   | Wait till PLL is ready.                                                                                                                            |
| 18  | ht32f5xxxx_ckcu.c  |   315   | Check the parameters.                                                                                                                              |
| 19  | ht32f5xxxx_ckcu.c  |   317   | Compare PLL ready flag (memory) and PLL register value in GCSR. If they are both 1, PLL is "SET". If not, it's "RESET".                            |
| 20  |       main.c       |   157   | Configure FLASH wait state. (flash memory)                                                                                                         |
| 21  | ht32f5xxxx_flash.c |   146   | Check the parameters.                                                                                                                              |
| 22  | ht32f5xxxx_flash.c |   151   | Backup CFCR value.                                                                                                                                 |
| 23  | ht32f5xxxx_flash.c |   154   | Disable Pre-fetch (load chunk data to cache) function and Branch Cache.                                                                            |
| 24  | ht32f5xxxx_flash.c |   156   | Since current HCLK is 8MHz, adjust wait state accordingly. Refer to user manual P44.                                                               |
| 25  | ht32f5xxxx_flash.c |   158   | Use restore CFCR with previously backuped data. (enable pre-fetch function and branch cache)                                                       |
| 26  |       main.c       |   160   | Set CKCU prescaler.                                                                                                                                |
| 27  |       main.c       |   163   | Set PLL as system clock.                                                                                                                           |
| 28  | ht32f5xxxx_ckcu.c  |   422   | Set maximum value to count down from to wait for new clock source is applied.                                                                      |
| 29  | ht32f5xxxx_ckcu.c  |   424   | Write new setting to GCCR.                                                                                                                         |
| 30  | ht32f5xxxx_ckcu.c  | 427-435 | Wait till new clock source is applied, or time-out.                                                                                                |
| 31  |       main.c       | 165-168 | If new clock source failed to apply, enter infinite loop.                                                                                          |
| 32  |       main.c       |   96    | Retrieve current clock source setting.                                                                                                             |
| 33  | ht32f5xxxx_ckcu.c  |   546   | Retrieve current clock source from CKST.                                                                                                           |
| 34  | ht32f5xxxx_ckcu.c  | 547-549 | If PLL clock is used based on configuration settings, retrieve its frequency.                                                                      |
| 35  | ht32f5xxxx_ckcu.c  | 551-575 | Retrieve system clock frequency based on different clock source.                                                                                   |
| 36  | ht32f5xxxx_ckcu.c  | 578-579 | Retrieve HCLK frequency.                                                                                                                           |
| 37  | ht32f5xxxx_ckcu.c  | 582-592 | Retrieve ADC frequency.                                                                                                                            |
| 38  |       main.c       |   99    | Enable CKCU CKM.                                                                                                                                   |
| 39  | ht32f5xxxx_ckcu.c  |   727   | Check the parameters.                                                                                                                              |
| 40  | ht32f5xxxx_ckcu.c  |   729   | Enable CKM by writing to GCCR.                                                                                                                     |
| 41  |       main.c       |   100   | Enable clock interrupt (NMI exception) once monitered HSE failed.                                                                                  |
| 42  | ht32f5xxxx_ckcu.c  |   802   | Read GCIR.                                                                                                                                         |
| 43  | ht32f5xxxx_ckcu.c  | 805-806 | Check the parameters.                                                                                                                              |
| 44  | ht32f5xxxx_ckcu.c  | 808-819 | Set clock interrupt enable or disable.                                                                                                             |
| 45  |       main.c       |   102   | Configure the debug output clock.                                                                                                                  |
| 46  |       main.c       |   404   | Declare private "CKCU_CKOUTInitTypeDef" type variable "CKOUTInit" defined in "ht32f5xxxx_ckcu.h".                                                  |
| 47  |       main.c       |   406   | Declare private "CKCU_PeripClockConfig_TypeDef" type variable "CKCUClock" defined in "ht32f5xxxx_ckcu.h", and disable all AHB clock control items. |
| 48  |       main.c       |   407   | Enable clock of AFIO by setting AHB settings.                                                                                                      |
| 49  |       main.c       |   408   | Write AHB settings to registers.                                                                                                                   |
| 50  |       main.c       |   410   | Set pin PA9 as AFIO mode 15, which is the debug output clock functionality. Attach oscilloscope to this pin will measure clock signal.             |
| 51  |       main.c       |   411   | Set the AHB prescaler to be "div16". Which is 0.5MHz clock signal based on current setting. (verified with experiment)                             |
| 52  |       main.c       |   412   | Write above settings in "CKOUTInit" to register.                                                                                                   |
| 53  |       main.c       | 105-107 | Use HT32F series unique functions to initialize LED1 to LED3.                                                                                      |
| 54  |       main.c       | 109-122 | Infinitely looping through toggling individual LEDs with delay in between.                                                                         |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | PLL     | Phase Lock Loop                              |
|  2  | GCCR    | Global Clock Control Register                |
|  3  | GCSR    | Global Clock Status Register                 |
|  4  | CFCR    | Flash Cache & Pre-fetch Control Register     |
|  5  | HCLK    | High Speed Clock                             |
|  6  | CKST    | Clock Source Status Register                 |
|  7  | CKM     | clock monitor                                |
|  8  | GCIR    | Global Clock Interrupt Register              |
|  9  | AHB     | ARM-designed high-performance bus            |
| 10  | AFIO    | Alternate Function Input/Output Control Unit |
