# I2C / EEPROM Simulate | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

## main.c

| No. |         File          | Line  | Detail                                                                                        |
| :-: | :-------------------: | :---: | --------------------------------------------------------------------------------------------- |
|  1  |        main.c         | 29-32 | Include essential libraries.                                                                  |
|  2  |        main.c         |  48   | Define EEPROM address for I2C transmission.                                                   |
|  3  |        main.c         | 51-55 | Declare later used functions.                                                                 |
|  4  |        main.c         |  58   | Declare 8 bits unsigned read only (constant) array of data to be sent by I2C protocol.        |
|  5  |        main.c         |  59   | Declare 8 bits unsigned array "buffer" to receive data transmitted by I2C protocol.           |
|  6  |        main.c         | 69-70 | Perform initial configuration of LEDs.                                                        |
|  7  | ht32f5xxxx_board_01.c |  155  | Retrieve pre-defined GPIO ID. (Check [test_1.c](../c_template/readme.md) to see how it work.) |
|  8  | ht32f5xxxx_board_01.c |  156  | Retrieve pre-defined GPIO PIN.                                                                |
|  9  | ht32f5xxxx_board_01.c |  157  | Retrieve pre-defined AFIO GPIO mode.                                                          |
| 10  | ht32f5xxxx_board_01.c |  158  | Retrieve pre-defined GPIO port.                                                               |


## Interrupt function HTCFG_BUZZER_IRQHandler

| No. | File | Line | Detail |
| :-: | :--: | :--: | ------ |
|     |      |      |        |


## Acronym Used

| No. | Acronym | Full Word |
| :-: | ------- | --------- |
|  1  | EEPROM  |           |
|  2  | I2C     |           |
|  3  | GPIO    |           |
|  4  | AFIO    |           |

