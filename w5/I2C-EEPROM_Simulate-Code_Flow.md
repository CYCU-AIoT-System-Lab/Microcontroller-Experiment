# I2C / EEPROM Simulate | Code Flow

This file is co-written by [belongtothenight](https://github.com/belongtothenight) and [bh1319](https://github.com/bh1319).

The following flow is written from the original state of the example.

## main.c

| No. |         File          |  Line   | Detail                                                                                                           |
| :-: | :-------------------: | :-----: | ---------------------------------------------------------------------------------------------------------------- |
|  1  |        main.c         |  29-32  | Include essential libraries.                                                                                     |
|  2  |        main.c         |   48    | Define EEPROM address for I2C transmission.                                                                      |
|  3  |        main.c         |  51-55  | Declare later used functions.                                                                                    |
|  4  |        main.c         |   58    | Declare 8 bits unsigned read only (constant) array of data to be sent by I2C protocol.                           |
|  5  |        main.c         |   59    | Declare 8 bits unsigned array "buffer" to receive data transmitted by I2C protocol.                              |
|  6  |        main.c         |  69-70  | Perform initial configuration of LEDs.                                                                           |
|  7  | ht32f5xxxx_board_01.c |   155   | Retrieve pre-defined GPIO ID. (Check [test_1.c](../c_template/readme.md) to see how it work.)                    |
|  8  | ht32f5xxxx_board_01.c |   156   | Retrieve pre-defined GPIO PIN.                                                                                   |
|  9  | ht32f5xxxx_board_01.c |   157   | Retrieve pre-defined AFIO GPIO mode.                                                                             |
| 10  | ht32f5xxxx_board_01.c |   158   | Retrieve pre-defined GPIO port.                                                                                  |
| 11  | ht32f5xxxx_board_01.c |   162   | Call clock configuration function.                                                                               |
| 12  | ht32f5xxxx_board_01.c |   443   | Disable all clocks in AHB.  (Check [test_2.c](../c_template/readme.md) to see how it work.)                      |
| 13  | ht32f5xxxx_board_01.c |   444   | Disable all GPIO ports available.                                                                                |
| 14  | ht32f5xxxx_board_01.c |   445   | Enable selected GPIO port.                                                                                       |
| 15  | ht32f5xxxx_board_01.c | 447-460 | Apply GPIO settings.                                                                                             |
| 16  | ht32f5xxxx_board_01.c |   461   | Enable AFIO clock in AHB.                                                                                        |
| 17  | ht32f5xxxx_board_01.c |   462   | Apply AHB clocks settings.                                                                                       |
| 18  | ht32f5xxxx_board_01.c |   165   | Call AFIO configuration function. ("AFIO_GPxConfig" defined in "ht32f52352_sk.h")                                |
| 19  | ht32f5xxxx_board_01.c |   168   | Turn off selected LED by modifying corresponding GPIO SRR.                                                       |
| 20  | ht32f5xxxx_board_01.c |   171   | Set GPIO pin pulling resistor by modifying either PUR or PDR correspondinly.                                     |
| 21  | ht32f5xxxx_board_01.c |   172   | Set GPIO pin driving current by modifying DRVR.                                                                  |
| 22  | ht32f5xxxx_board_01.c |   173   | Set GPIO pin direction by modifying DIRCR.                                                                       |
| 23  |        main.c         |   73    | Call function to configure GPIO and EXTI of button.                                                              |
| 24  | ht32f5xxxx_board_01.c | 230-233 | Retrieve pre-defined button linked GPIO ID, PIN, PINNum, PORT.                                                   |
| 25  | ht32f5xxxx_board_01.c |   237   | Enable selected GPIO with ID.                                                                                    |
| 26  | ht32f5xxxx_board_01.c |   240   | Call AFIO configuration function to set AFIO mode.                                                               |
| 27  | ht32f5xxxx_board_01.c |   241   | Set GPIO pin pull resistor as disabled.                                                                          |
| 28  | ht32f5xxxx_board_01.c |   242   | Set GPIO pin direction by modifying DIRCR.                                                                       |
| 29  | ht32f5xxxx_board_01.c |   243   | Enable GPIO pin.                                                                                                 |
| 30  | ht32f5xxxx_board_01.c |   245   | If the mode is not "GPIO" but "EXTI", continue.                                                                  |
| 31  | ht32f5xxxx_board_01.c |   251   | Declare pre-defined EXTI setting variable.                                                                       |
| 32  | ht32f5xxxx_board_01.c |   253   | Declare pre-defined CKCU setting variable.                                                                       |
| 33  | ht32f5xxxx_board_01.c |   256   | Enable EXTI clock in AHB.                                                                                        |
| 34  | ht32f5xxxx_board_01.c |   257   | Apply CKCU settings.                                                                                             |
| 35  | ht32f5xxxx_board_01.c |   260   | Connect EXTI channel to GPIO pin, which makes button triggered interrupt (external) possible, by modifying ESSR. |
| 36  | ht32f5xxxx_board_01.c | 263-266 | Set EXTI settings.                                                                                               |
| 37  | ht32f5xxxx_board_01.c |   262   | Apply EXTI settings to pre-defined variable/structure.                                                           |
| 38  | ht32f5xxxx_board_01.c |   270   | Configure GPIO to be connected with certain interrupt channel by modifying CR.                                   |
| 39  | ht32f5xxxx_board_01.c |   271   | Enable specified NVIC interrupt handler to handle EXTI event.                                                    |
| 40  |        main.c         |   75    | If the example is set to simulate EEPROM slave by itself, then continue.                                         |
| 41  |        main.c         |   77    | Call I2C slave configure function.                                                                               |
| 42  |        main.c         |   113   | Declare pre-defined CKCU setting variable.                                                                       |
| 43  |        main.c         |   114   | Enable AFIO clock in AHB.                                                                                        |
| 44  |        main.c         |   115   | Enablle I2C1 clock in AHB acting as EEPROM slave device.                                                         |
| 45  |        main.c         |   116   | Apply clock settings.                                                                                            |
| 46  |        main.c         | 120-121 | Configure AFIO mode of SDA and SCL line of I2C1 by modifying corresponding CFGR.                                 |
| 47  |        main.c         |   130   | Declare pre-defined I2C setting variable.                                                                        |
| 48  |        main.c         | 132-137 | Set I2C settings.                                                                                                |
| 49  |        main.c         |   138   | Apply I2C settings to CR, ADDR, SHPGR, SLPGR.                                                                    |
| 50  |        main.c         |   142   | Enable EEPROM interrupts by modifying IER.                                                                       |
| 51  |        main.c         |   145   | Enable NVIC to handle I2C interrupt.                                                                             |
| 52  |        main.c         |   148   | Enable I2C by modifying CR.                                                                                      |
| 53  |        main.c         |   80    | Call I2C master configure function.                                                                              |
| 54  |        main.c         |   158   | Declare pre-defined CKCU setting variable.                                                                       |
| 55  |        main.c         |   159   | Enable I2C clock in AHB.                                                                                         |
| 56  |        main.c         |   160   | Enable AFIO clock in AHB.                                                                                        |
| 57  |        main.c         |   161   | Apply CKCU setting.                                                                                              |
| 58  |        main.c         | 165-166 | Configure AFIO mode of SDA and SCL line of I2C1 by modifying corresponding CFGR.                                 |
| 59  |        main.c         |   174   | Declare pre-defined I2C setting variable.                                                                        |
| 60  |        main.c         | 176-181 | Set I2C settings.                                                                                                |
| 61  |        main.c         |   182   | Apply I2C settings to CR, ADDR, SHPGR, SLPGR.                                                                    |
| 62  |        main.c         |   186   | Enable EEPROM interrupts by modifying IER.                                                                       |
| 63  |        main.c         |   190   | Enable NVIC to handle I2C interrupt.                                                                             |
| 64  |        main.c         |   193   | Enable I2C settings.                                                                                             |
| 65  |        main.c         |   82    | Call function to execute I2C read write test to EEPROM.                                                          |
| 66  |        main.c         |   254   | Call I2C writing to buffer/EEPROM function. If succeed, continue; if fail, light up LED.                         |
| 67  |        main.c         | 228-235 | Use pre-defined I2C variable (in "ht32f5xxxx_01_it.c") to set settings for data transfer.                        |
| 68  |        main.c         |   238   | Configure I2C transmission by modifying CR, and TAR.                                                             |
| 69  |        main.c         |   240   | Wait till I2C master side transfer lock is removed. (Check I2C0_IRQHandler for further details.)                 |
| 70  |        main.c         |   241   | Wait till I2C master side status flag is not busy by reading SR.                                                 |
| 71  |        main.c         |   243   | Empty I2C master transfer buffer.                                                                                |
| 72  |        main.c         |   245   | Return the I2C master transfer status.                                                                           |
| 73  |        main.c         |   260   | Call I2C reading to buffer/EEPROM function. If succeed, continue; if fail, light up LED.                         |
| 74  |        main.c         | 202-209 | Use pre-defined I2C variable (in "ht32f5xxxx_01_it.c") to set settings for data transfer.                        |
| 75  |        main.c         |   212   | Send I2C transfer start signal by modifying CR and TAR.                                                          |
| 76  |        main.c         |   214   | Wait till I2C master side transfer lock is removed.                                                              |
| 77  |        main.c         |   215   | Wait till I2C master side status flag is not busy by reading SR.                                                 |
| 78  |        main.c         |   217   | Empty I2C master transfer buffer.                                                                                |
| 79  |        main.c         |   219   | Return I2C master transfer status.                                                                               |
| 80  |        main.c         |   100   | If read and write is finished without problem, light up LED.                                                     |

## Interrupt function I2C0_IRQHandler

| No. | File | Line | Detail |
| :-: | :--: | :--: | ------ |
|     |      |      |        |

## Interrupt function I2C1_IRQHandler

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
|  5  | SRR     |           |
|  6  | PUR     |           |
|  7  | PDR     |           |
|  8  | EXTI    |           |
|  9  | ESSR    |           |
| 10  | CR      |           |
| 11  | ADDR    |           |
| 12  | SHPGR   |           |
| 13  | SLPGR   |           |
| 14  | IER     |           |
| 15  | TAR     |           |
| 16  | SR      |           |
