# EXTI / GPIO_Interrupt | Code Flow

The following flow is written from the original state of the example.

## main.c

| No. |  File  |  Line   | Detail                                                                                                         |
| :-: | :----: | :-----: | -------------------------------------------------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include essential libraries.                                                                                   |
|  2  | main.c |  47-49  | Declare function prototypes.                                                                                   |
|  3  | main.c |   52    | Declare volatile unsigned 32 bit variable guKeyState to store state of whether it's pressed.                   |
|  4  | main.c |   61    | Call on-board LED initialization function.                                                                     |
|  5  | main.c |   63    | Call custom defined EXTI configure function.                                                                   |
|  6  | main.c |  90-96  | Configure necessary clock for EXTI and clear configuration struct created here.                                |
|  7  | main.c |   99    | Set AFIO mode of used GPIO pin.                                                                                |
|  8  | main.c |   102   | Set used GPIO pin as input mode.                                                                               |
|  9  | main.c |   105   | Set used GPIO pin as no pulling mode.                                                                          |
| 10  | main.c |   108   | Set AFIO as one of the EXTI trigger by setting ESSR.                                                           |
| 11  | main.c | 110-112 | Configure EXTI channel to cope with AFIO triggering and clear configuration struct created here.               |
| 12  | main.c |   125   | Initialize EXTI with configuring EXTICR.                                                                       |
| 13  | main.c |   126   | Enable EXTI under control of NVIC.                                                                             |
| 14  | main.c |  65-68  | Enter endless while loop to detect any key press.                                                              |
| 15  | main.c |  77-81  | If key is detected being pressed, set its state into unpressed and toggle previously initialized on-board LED. |

The interrupt functions is an important concept in RTOS. The CPU will prioritize process tasks triggered by EXTI which is controlled with NVIC.

## Interrupt function EXTI0_1_IRQHandler

| No. |        File        | Line | Detail                                                                                  |
| :-: | :----------------: | :--: | --------------------------------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c | 123  | If hardware circuitry detects either positive and negative edge on EXTI line, continue. |
|  2  | ht32f5xxxx_01_it.c | 125  | Clear flag set by hardware circuitry for next auto detection.                           |
|  3  | ht32f5xxxx_01_it.c | 126  | Set key state as being triggered to perform corresponding action in software.           |

## Interrupt function EXTI4_15_IRQHandler

In the default scenario, EXTI4_15_IRQHandler will be triggered based on configuration set in file ```ht32_board_config.h```.

| No. |        File        | Line | Detail                                                                                  |
| :-: | :----------------: | :--: | --------------------------------------------------------------------------------------- |
|  1  | ht32f5xxxx_01_it.c | 137  | If hardware circuitry detects either positive and negative edge on EXTI line, continue. |
|  2  | ht32f5xxxx_01_it.c | 139  | Clear flag set by hardware circuitry for next auto detection.                           |
|  3  | ht32f5xxxx_01_it.c | 140  | Set key state as being triggered to perform corresponding action in software.           |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | EXTI    | External Interrupt/Event Controller          |
|  2  | AFIO    | Alternate Function Input/Output Control Unit |
|  3  | GPIO    | General Purpose I/O                          |
|  4  | ESSR    | EXTI Source Selection Register               |
|  5  | EXTICR  | EXTI Interrupt Control Register              |
|  6  | RTOS    | Real Timer Operation System                  |
|  7  | NVIC    | Nested Vectored Interrupt Controller         |
