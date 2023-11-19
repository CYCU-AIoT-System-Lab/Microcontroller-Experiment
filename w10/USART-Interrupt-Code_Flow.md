# USART / Interrupt | Code Flow

The following flow is written from the original state of the example.

## main.c

| No. |  File  |  Line   | Detail                                                                 |
| :-: | :----: | :-----: | ---------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include essential libraries.                                           |
|  2  | main.c |  47-49  | Declare function prototypes.                                           |
|  3  | main.c |  52-62  | Declare variables.                                                     |
|  4  | main.c |  71-72  | Initialize two on-board LEDs.                                          |
|  5  | main.c |   74    | Assign array pointer to declared u8 array.                             |
|  6  | main.c |   76    | Call USART configuration function.                                     |
|  7  | main.c | 98-102  | Open clocks for UART and AFIO.                                         |
|  8  | main.c |   106   | Pull-up USART Rx PIN to prepare receiving data.                        |
|  9  | main.c | 109-110 | Select UART AFIO mode for both Rx and Tx PINs.                         |
| 10  | main.c | 124-130 | Set USART settings for this example by modifying USRCR and USRDLR.     |
| 11  | main.c |   134   | Assign IRQHandler function to NVIC.                                    |
| 12  | main.c |   137   | Enable external interrupt of USART Rx by modifying USRIER.             |
| 13  | main.c | 140-141 | Enable USART Tx and Rx functions by modifying USRCR.                   |
| 14  | main.c |   78    | Call Tx test function.                                                 |
| 15  | main.c |   150   | Set Tx finished flag as false.                                         |
| 16  | main.c |   151   | Set pointer to u8 string.                                              |
| 17  | main.c |   152   | Get the size of string without the "\0" at the end of string.          |
| 18  | main.c |   153   | Initialize USART Tx side with USRIER.                                  |
| 19  | main.c |   155   | Wait until the entire string is sent.                                  |
| 20  | main.c |   156   | Wait until the interrupt handler function update transmit finish flag. |
| 21  | main.c |  80-83  | Infinitely call USART Rx test function.                                |
| 22  | main.c |   169   | Wait for 5 characters received.                                        |
| 23  | main.c |   174   | Get a copy of current received data length.                            |
| 24  | main.c | 175-178 | Loop through Rx buffers and assign characters to Tx buffers.           |
| 25  | main.c |   181   | Set Tx finished flag to false.                                         |
| 26  | main.c |   182   | Set array pointer to Tx buffer.                                        |
| 27  | main.c |   183   | Store copied length to global variable.                                |
| 28  | main.c |   184   | Re-initiate USART Tx.                                                  |


## Interrupt function EXTI0_1_IRQHandler

| No. |        File        |  Line   | Detail                                                           |
| :-: | :----------------: | :-----: | ---------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c | 122-126 | Get global variables defined in main.c                           |
|  2  | ht32f5xxxx_01_it.c | 129-132 | Define LED macro for debugging USART transmission.               |
|  3  | ht32f5xxxx_01_it.c |   141   | Check if USART Rx has received data.                             |
|  4  | ht32f5xxxx_01_it.c |   144   | Store USART Rx received character to global buffer with pointer. |
|  5  | ht32f5xxxx_01_it.c | 156-157 | Check if USART Tx has no data to send.                           |
|  6  | ht32f5xxxx_01_it.c |   160   | Check if global buffer is not empty.                             |
|  7  | ht32f5xxxx_01_it.c |   162   | Send a character with global buffer pointer.                     |
|  8  | ht32f5xxxx_01_it.c |   163   | Decrease buffer length by 1.                                     |
|  9  | ht32f5xxxx_01_it.c |   164   | Check if the entire global Tx buffer is emptied.                 |
| 10  | ht32f5xxxx_01_it.c |   166   | Disable USART Tx empty interrupt.                                |
| 11  | ht32f5xxxx_01_it.c | 172-173 | Check if USART Tx transmit is complete.                          |
| 12  | ht32f5xxxx_01_it.c |   175   | Disable USART Tx transmit complete interrupt.                    |
| 13  | ht32f5xxxx_01_it.c |   176   | Update transmittion finished flag.                               |

## Acronym Used

| No. | Acronym | Full Word                                               |
| :-: | ------- | ------------------------------------------------------- |
|  1  | USART   | Universal Synchronous Asynchronous Receiver Transmitter |
|  2  | UART    | Universal Asynchronous Receiver Transmitter             |
|  3  | NVIC    | Nested Vectored Interrupt Controller                    |
|  4  | USRCR   | USART Control Register                                  |
|  5  | USRDLR  | USART Divider Latch Register                            |
|  6  | USRIER  | USART Interrupt Enable Register                         |
