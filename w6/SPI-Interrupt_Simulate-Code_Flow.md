# I2C / EEPROM Simulate | Code Flow

The following flow is written from the original state of the example.

## main.c

| No. |  File  |  Line   | Detail                                                                                      |
| :-: | :----: | :-----: | ------------------------------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include essential libraries.                                                                |
|  2  | main.c |   47    | Create type to handle buffer content comparing result.                                      |
|  3  | main.c |   50    | Define SPI buffer to be $4\times8=32$ bits long.                                            |
|  4  | main.c |  53-56  | Declare functions.                                                                          |
|  5  | main.c |  59-63  | Define variables used for this example.                                                     |
|  6  | main.c |  73-74  | Initialize LED1 & 2 on board.                                                               |
|  7  | main.c |   76    | Call SPI configuration function.                                                            |
|  8  | main.c |   93    | Declare type defined in "ht32f5xxxx_spi.h" to hold SPI settings.                            |
|  9  | main.c |   95    | Declare type defined in "ht32f5xxxx_ckcu.h" to hold AHB settings.                           |
| 10  | main.c | 97-100  | Set clock of master, slave, AFIO as on.                                                     |
| 11  | main.c |   101   | Apply settings by modifying AHBCCR and APBCCR.                                              |
| 12  | main.c |   104   | Set SPI master SEL to high to turn it into idle mode by modifying PUR/PDR.                  |
| 13  | main.c | 107-110 | Configure AFIO settings of SPI master (SPI0) by modifying GPxCFGR.                          |
| 14  | main.c | 113-116 | Configure AFIO settings of SPI slave (SPI1) by modifying GPxCFGR.                           |
| 15  | main.c | 119-129 | Set SPI master side settings.                                                               |
| 16  | main.c |   130   | Apply settings by modifying CR1, FCR, and CPR.                                              |
| 17  | main.c |   133   | Modify SPI master settings to SPI slave side settings.                                      |
| 18  | main.c |   134   | Apply settings by modifying CR1, FCR, and CPR.                                              |
| 19  | main.c |   145   | Set SPI master interrupt priority as 1. (0 is the highest configurable option)              |
| 20  | main.c |   146   | Enable SPI master IRQHandler function.                                                      |
| 21  | main.c |   149   | Set SPI slave interrupt priority as 0. (0 is the highest configurable option)               |
| 22  | main.c |   150   | Enable SPI slave IRQHandler function.                                                       |
| 23  | main.c |   153   | Enable SPI slave peripheral my modifying CR0.                                               |
| 24  | main.c |   155   | Enable SPI master peripheral my modifying CR0.                                              |
| 25  | main.c |   78    | Call SPI transmission loopback function to check status. (variables updated by IRQHandlers) |
| 26  | main.c |   165   | Wait till IRQHandlers makes sure all data are transmitted.                                  |
| 27  | main.c | 168-177 | If data in both master and slave buffer are the same, turn LED1 on; if not; turn LED2 on.   |
| 28  | main.c | 188-199 | Compare every element in buffer and return corresponding result back.                       |

## Interrupt function HTCFG_SPI_MASTER_IRQHandler

| No. |        File        |  Line   | Detail                                                                    |
| :-: | :----------------: | :-----: | ------------------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c |   127   | Check if SPI master Rx have received data by reading SR.                  |
|  2  | ht32f5xxxx_01_it.c |   128   | If there is data in buffer, store it in memory.                           |
|  3  | ht32f5xxxx_01_it.c |   133   | Check if SPI master Tx buffer is empty by reading SR.                     |
|  4  | ht32f5xxxx_01_it.c | 135-144 | Send data one by one until nothing left, then disable SPI TXBE interrupt. |

## Interrupt function HTCFG_SPI_SLAVE_IRQHandler

| No. |        File        |  Line   | Detail                                                                    |
| :-: | :----------------: | :-----: | ------------------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c |   154   | Check if SPI master Rx have received data by reading SR.                  |
|  2  | ht32f5xxxx_01_it.c |   157   | If there is data in buffer, store it in memory.                           |
|  3  | ht32f5xxxx_01_it.c |   160   | Check if SPI master Tx buffer is empty by reading SR.                     |
|  4  | ht32f5xxxx_01_it.c | 162-171 | Send data one by one until nothing left, then disable SPI TXBE interrupt. |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | SPI     | Serial Peripheral Interface                  |
|  2  | CKCU    | Clock Control Unit                           |
|  3  | AHB     | ARM-designed High-performance Bus            |
|  4  | APB     | Advanced Peripheral Bus                      |
|  5  | SPI SEL | SPI select                                   |
|  6  | AFIO    | Alternate Function Input/Output Control Unit |
|  7  | AHBCCR  | AHB Clock Control Register                   |
|  8  | APBCCR  | APB Clock Control Register                   |
|  9  | PUR     | Pull Up Register                             |
| 10  | PDR     | Pull Down Register                           |
| 11  | CFGR    | Flash Cache & Pre-fetch Control Register     |
| 12  | CR1     | Control Register 0                           |
| 13  | FCR     | FIFO Control Register                        |
| 14  | CPR     | Clock Prescaler Register                     |
| 15  | IRQ     | Interrupt Request                            |
| 16  | CR0     | Control Register 0                           |
| 17  | SR      | Status Register                              |
| 18  | TXBE    | Tx Buffer Empty                              |
| 19  | FIFO    | First In First Out (data structure)          |
