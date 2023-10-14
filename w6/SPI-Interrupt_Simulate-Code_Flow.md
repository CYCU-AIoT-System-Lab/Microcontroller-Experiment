# I2C / EEPROM Simulate | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

## main.c

| No. |  File  |  Line   | Detail                                                                     |
| :-: | :----: | :-----: | -------------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include essential libraries.                                               |
|  2  | main.c |   47    | Create type to handle buffer content comparing result.                     |
|  3  | main.c |   50    | Define SPI buffer to be $4\times8=32$ bits long.                           |
|  4  | main.c |  53-56  | Declare functions.                                                         |
|  5  | main.c |  59-63  | Define variables used for this example.                                    |
|  6  | main.c |  73-74  | Initialize LED1 & 2 on board.                                              |
|  7  | main.c |   76    | Call SPI configuration function.                                           |
|  8  | main.c |   93    | Declare type defined in "ht32f5xxxx_spi.h" to hold SPI settings.           |
|  9  | main.c |   95    | Declare type defined in "ht32f5xxxx_ckcu.h" to hold AHB settings.          |
| 10  | main.c | 97-100  | Set clock of master, slave, AFIO as on.                                    |
| 11  | main.c |   101   | Apply settings by modifying AHBCCR and APBCCR.                             |
| 12  | main.c |   104   | Set SPI master SEL to high to turn it into idle mode by modifying PUR/PDR. |
| 13  | main.c | 107-110 | Configure AFIO settings of SPI master (SPI0) by modifying GPxCFGR.         |
| 14  | main.c | 113-116 | Configure AFIO settings of SPI slave (SPI1) by modifying GPxCFGR.          |
| 15  | main.c | 119-129 | Set SPI master side settings.                                              |
| 16  | main.c |   130   | Apply settings by modifying CR1, FCR, and CPR.                             |
| 17  | main.c |   133   | Modify SPI master settings to SPI slave side settings.                     |
| 18  | main.c |   134   | Apply settings by modifying CR1, FCR, and CPR.                             |
| 19  | main.c |         |                                                                            |

## Interrupt function I2C0_IRQHandler

| No. | File | Line | Detail |
| :-: | :--: | :--: | ------ |

## Interrupt function I2C1_IRQHandler

| No. | File | Line | Detail |
| :-: | :--: | :--: | ------ |

## Acronym Used

| No. | Acronym | Full Word                   |
| :-: | ------- | --------------------------- |
|  1  | SPI     | Serial Peripheral Interface |
|  2  | CKCU    |                             |
|  3  | AHB     |                             |
|  4  | SPI SEL | SPI select                  |
|  5  | AFIO    |                             |
|  6  | AHBCCR  |                             |
|  7  | APBCCR  |                             |
|  8  | PUR     |                             |
|  9  | PDR     |                             |
| 10  | GPxCFGR |                             |
| 11  | CR1     |                             |
| 12  | FCR     |                             |
| 13  | CPR     |                             |
