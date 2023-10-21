# TM / PWM | Code Flow

The following flow is written from the original state of the example.

## main.c

| No. |  File  |  Line   | Detail                                                                                                                                  |
| :-: | :----: | :-----: | --------------------------------------------------------------------------------------------------------------------------------------- |
|  1  | main.c |  29-31  | Include essential libraries.                                                                                                            |
|  2  | main.c |   47    | Declare a custum delay function.                                                                                                        |
|  3  | main.c |   56    | Call PWM initialization function.                                                                                                       |
|  4  | pwm.c  |  77-82  | Enable clock of GPTM0 and AFIO by modifying AHBCCR and APBCCR.                                                                          |
|  5  | pwm.c  |  85-96  | Enable AFIO of four PWM pins.                                                                                                           |
|  6  | pwm.c  | 105-112 | Set PWM settings by modifying CRR, PSCR, CNTCFR, REPR, and EVGR.                                                                        |
|  7  | pwm.c  |   113   | Enable CRR preload function by modifying CTR.                                                                                           |
|  8  | pwm.c  |   116   | Clear the TMUEV flag by modifying INTSR.                                                                                                |
|  9  | pwm.c  | 125-137 | Set settings for PWM output channels.                                                                                                   |
| 10  | pwm.c  | 139-153 | If a PWM channel is enabled, applied the set settings.                                                                                  |
| 11  | pwm.c  |   167   | Enable update event interrupt HTCFG_PWM_TM_IRQHandler.                                                                                  |
| 12  | main.c |  58-59  | Call function to update PWM duty cycle of individual channel.                                                                           |
| 13  | pwm.h  |   93    | A macro to call another function TM_SetCaptureCompare; therefore requiring 1 less parameter, by modifying CCR of corresponding channel. |
| 14  | main.c |   60    | Call function to enable PWM output.                                                                                                     |
| 15  | pwm.c  | 203-206 | If the state is enable, modify CTR to enable it.                                                                                        |
| 16  | pwm.c  | 207-224 | If the state is disable, modify CCR to turn PWM channel into idle duty.                                                                 |
| 17  | pwm.c  |   226   | Re-enabling TMUEV by modifying DICTR.                                                                                                   |
| 18  | main.c |   62    | Call delay function to delay 5000 core clock cycle.                                                                                     |
| 19  | main.c |  64-65  | Call function to update PWM duty cycle of individual channel.                                                                           |
| 20  | main.c |   67    | Call delay function to delay 5000 core clock cycle.                                                                                     |
| 21  | main.c |   69    | Disable PWM.                                                                                                                            |
| 22  | main.c |   71    | Call delay function to delay 5000 core clock cycle.                                                                                     |
| 23  | main.c |   73    | Set CCR value to change PWM frequency.                                                                                                  |
| 24  | main.c |  74-75  | Call function to update PWM duty cycle of individual channel.                                                                           |
| 25  | main.c |   76    | Enable PWM.                                                                                                                             |

## Interrupt function HTCFG_PWM_TM_IRQHandler

| No. | File  |  Line   | Detail                                                                     |
| :-: | :---: | :-----: | -------------------------------------------------------------------------- |
|  1  | pwm.c |   180   | Clear TM_INT_UEV flag.                                                     |
|  2  | pwm.c | 182-185 | If timer has been stoped before, set gIsTMStop as 2.                       |
|  3  | pwm.c | 186-193 | If the timer has been stopped twice, disable both timer and its interrupt. |

## Acronym Used

| No. | Acronym | Full Word                                    |
| :-: | ------- | -------------------------------------------- |
|  1  | PWM     | Pulse Width Modulation                       |
|  2  | AFIO    | Alternate Function Input/Output Control Unit |
|  3  | AHBCCR  | AHB Clock Control Register                   |
|  4  | APBCCR  | APB Clock Control Register                   |
|  5  | CCR     | Capture / Compare Register                   |
|  6  | PSCR    | Timer Prescaler Register                     |
|  7  | CNTCFR  | Timer Counter Configuration Register         |
|  8  | REPR    | Repetition Counter                           |
|  9  | EVGR    | Timer Event Generator Register               |
| 10  | CTR     | Timer Control Register                       |
| 11  | TMUEV   | Timer Update Event                           |
| 12  | INTSR   | Timer Interrupt Status Register              |
