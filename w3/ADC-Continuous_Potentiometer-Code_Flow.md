# ADC / Continuous Potemtiometer | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

## main.c

| No. |      File       |  Line   | Detail                                                                                                                                                                  |
| :-: | :-------------: | :-----: | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
|  1  |     main.c      |  29-31  | Include essential libraries.                                                                                                                                            |
|  2  |     main.c      |   47    | Declare later used functions.                                                                                                                                           |
|  3  |     main.c      |   50    | Declare variable in "volatile bool" type, for variable value updating.                                                                                                  |
|  4  |     main.c      |   51    | Declare variable to store potentiometer measured value.                                                                                                                 |
|  5  |     main.c      |   60    | Configure USART COM with laptop to display in Tera Term.                                                                                                                |
|  6  | ht32_retarget.c |   125   | Declare "USART_InitTypeDef" type variable "USART_InitStructure" defined in "ht32f5xxxx_usart.h".                                                                        |
|  7  | ht32_retarget.c | 126-130 | If baudrate is previously defined, use defined setting. If not, set new setting.                                                                                        |
|  8  | ht32_retarget.c | 131-134 | Set USART word-length, stop-bits, parity, and mode.                                                                                                                     |
|  9  | ht32_retarget.c | 136-151 | If USART COM port is previously defined, apply above setting. If not, initiate new COM port and apply above setting.                                                    |
| 10  | ht32_retarget.c | 154-161 | CKCU debug related stuff.                                                                                                                                               |
| 11  |     main.c      |   62    | Configure ADC settings.                                                                                                                                                 |
| 12  |     main.c      |   86    | Declare structure variable defined in "ht32f5xxxx_ckcu.h" for storing AHB settings and close all of them.                                                               |
| 13  |     main.c      |   87    | Set AFIO on in AHB.                                                                                                                                                     |
| 14  |     main.c      |   88    | Set ADC0 on in AHB.                                                                                                                                                     |
| 15  |     main.c      |   89    | Apply settings to register.                                                                                                                                             |
| 16  |     main.c      |   93    | Configure PA6 AFIO mode as ADC0.                                                                                                                                        |
| 17  |     main.c      |   97    | Set ADC prescaler as (CK_AHB / 64).                                                                                                                                     |
| 18  |     main.c      |   100   | Set ADC0 as continuous mode, with sequence length as 1.                                                                                                                 |
| 19  |     main.c      | 104-108 | Set ADC0 as minimum sampling time by modifying ADCSTR.                                                                                                                  |
| 20  |     main.c      |   111   | Configure ADC0 to receive input with channel 6.                                                                                                                         |
| 21  |     main.c      |   114   | Set ADC to be triggered with software by modifying ADCTCR.                                                                                                              |
| 22  |     main.c      |   118   | Set ADC0 EOC interrupt by modifying ADCIER.                                                                                                                             |
| 23  |     main.c      |   121   | Set ADC internal interrupt function "HTCFG_ADC_IRQHandler" defined in "ht32fxxxx_01_it.c".                                                                              |
| 24  |     main.c      |   65    | Enable ADC0 by modifying ADCCR.                                                                                                                                         |
| 25  |     main.c      |   68    | Use software trigger to start ADC conversion by modifying ADCTSR.                                                                                                       |
| 26  |     main.c      |   74    | Whenever ADC reaches EOC, print measured value. The flag parameter is updated with previously mentioned function "HTCFG_ADC_IRQHandler" defined in "ht32fxxxx_01_it.c". |

## Interrupt function HTCFG_ADC_IRQHandler

| No. |        File        |  Line   | Detail                                                                |
| :-: | :----------------: | :-----: | --------------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c | 120-121 | Access main.c declared variables.                                     |
|  2  | ht32f5xxxx_01_it.c |   123   | Clear the ALC interrupt pending bits.                                 |
|  3  | ht32f5xxxx_01_it.c |   124   | Retrieve measured potentiometer level from ADC data storing register. |
|  4  | ht32f5xxxx_01_it.c |   125   | Set EOC flag to indicate it's EOC.                                    |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | ADC     | analog to digital converter                  |
|  2  | USART   | universal asynchronous receive-transmitter   |
|  3  | COM     | communication                                |
|  4  | CKCU    | clock control unit                           |
|  5  | AHB     | ARM-designed high-performance bus            |
|  6  | AFIO    | Alternate Function Input/Output Control Unit |
|  7  | ADCSTR  | ADC Input Sampling Time Register             |
|  8  | ADCTCR  | ADC Trigger Control Register                 |
|  9  | EOC     | end of conversion                            |
| 10  | ADCIER  | ADC Interrupt Enable Register                |
| 11  | ADCCR   | ADC Conversion Control Register              |
| 12  | ADCTSR  | ADC Trigger Source Register                  |
| 13  | ALC     |                                              |
