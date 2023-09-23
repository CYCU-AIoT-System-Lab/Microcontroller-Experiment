# TM / Continuous Potemtiometer | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

## main.c

| No. |     File     |  Line   | Detail                                                                              |
| :-: | :----------: | :-----: | ----------------------------------------------------------------------------------- |
|  1  |    main.c    |  29-33  | Include essential libraries.                                                        |
|  2  |    main.c    |  49-51  | Declare later used functions.                                                       |
|  3  |    main.c    |  54-60  | Declare array for storing music.                                                    |
|  4  |    main.c    |   69    | Execute first buzzer function.                                                      |
|  5  |    main.c    |   88    | Initialize buzzer.                                                                  |
|  6  | buzzer_pwm.c |   99    | Set all functionality in AHB off.                                                   |
|  7  | buzzer_pwm.c |   100   | Set AFIO in AHB on.                                                                 |
|  8  | buzzer_pwm.c |   101   | Set MCTM0 in AHB on.                                                                |
|  9  | buzzer_pwm.c |   102   | Apply AHB settings.                                                                 |
| 10  | buzzer_pwm.c |   106   | Configure PB0 as MCTM0 functionality.                                               |
| 11  | buzzer_pwm.c |   108   | ??? error ???                                                                       |
| 12  | buzzer_pwm.c |   116   | Declare struct to hold timer settings.                                              |
| 13  | buzzer_pwm.c | 118-122 | Set timer settings.                                                                 |
| 14  | buzzer_pwm.c |   123   | Apply timer settings to CRR, PSCR, CNTCFR, REPR, EVGR.                              |
| 15  | buzzer_pwm.c |   126   | Clear update event interrupt flag.                                                  |
| 16  | buzzer_pwm.c |   135   | Declare struct to hold timer output settings.                                       |
| 17  | buzzer_pwm.c | 137-147 | Set timer output settings.                                                          |
| 18  | buzzer_pwm.c |   148   | Apply timer output settings to CHCTR, CHPOLR, CHBPKCFR.                             |
| 19  | buzzer_pwm.c | 150-153 | If MCTM is used, enable it.                                                         |
| 20  | buzzer_pwm.c |   156   | Enable timer interrupt.                                                             |
| 21  |    main.c    |   90    | Start buzzing with given parameters.                                                |
| 22  | buzzer_pwm.c |   169   | Same as No. 11.                                                                     |
| 23  | buzzer_pwm.c |   170   | Calculate CCR comparing value.                                                      |
| 24  | buzzer_pwm.c | 172-175 | Calculate variables used in interrupt function "HTCFG_BUZZER_IRQHandler".           |
| 25  | buzzer_pwm.c |   177   | Configure CRR value.                                                                |
| 26  | buzzer_pwm.c |   178   | Configure CH0CCR value.                                                             |
| 27  | buzzer_pwm.c |   180   | Configure DICTR to enable interrupt source.                                         |
| 28  | buzzer_pwm.c |   181   | Configure CHCTR to enable TMx channel 1.                                            |
| 29  | buzzer_pwm.c |   182   | Configure CTR to enable TMx counter.                                                |
| 30  |    main.c    |   90    | Wait till interrupt function to reach the end of beeping times than continue.       |
| 31  |    main.c    |   71    | Execute second buzzer function. Same as No. 5~30.                                   |
| 32  |    main.c    |   77    | Execute buzzer function to play notes coded in array.                               |
| 33  |    main.c    | 114-118 | Run No. 21~29 to play each and every element in array until all of them are played. |

## Interrupt function HTCFG_BUZZER_IRQHandler

| No. |     File     |  Line   | Detail                                                                 |
| :-: | :----------: | :-----: | ---------------------------------------------------------------------- |
|  1  | buzzer_pwm.c |   200   | Clear flag in INTSR.                                                   |
|  2  | buzzer_pwm.c |   202   | If still need to beep/silent(one beep cycle), continue.                |
|  3  | buzzer_pwm.c |   204   | Everytime it enters, counter minus 1.                                  |
|  4  | buzzer_pwm.c | 205-208 | If it's inactive time, disable the TMx output channel by modify CHCTR. |
|  5  | buzzer_pwm.c |   210   | If a beep cycle finishes, continue.                                    |
|  6  | buzzer_pwm.c |   212   | Restore beep cycle count variable.                                     |
|  7  | buzzer_pwm.c |   213   | Enable the TMx output channel by modify CHCTR.                         |
|  8  | buzzer_pwm.c |   215   | Since a beep cycle is finished, decrease beeping time counter by one.  |
|  9  | buzzer_pwm.c | 218-221 | If finished all set beeps, disable TMx counter by modify CTR.          |

## Acronym Used

| No. | Acronym  | Full Word                                    |
| :-: | -------- | -------------------------------------------- |
|  1  | AHB      | ARM-designed high-performance bus            |
|  2  | AFIO     | Alternate Function Input/Output Control Unit |
|  3  | MCTM     | Motor Control Timer                          |
|  4  | CRR      | Timer Counter Reload Register                |
|  5  | PSCR     | Timer Prescaler Register                     |
|  6  | CNTCFR   | Timer Counter Configuration Register         |
|  7  | REPR     | Timer Repetition Register                    |
|  8  | EVGR     | Timer Event Generator Register               |
|  9  | CHCTR    | Channel Control Register                     |
| 10  | CHPOLR   | Channel Polarity Configuration Register      |
| 11  | CHBPKCFR | Channel Break Configuration Register         |
| 12  | CTR      | Timer Control Register                       |
| 13  | INTSR    | Timer Interrupt Status Register              |
