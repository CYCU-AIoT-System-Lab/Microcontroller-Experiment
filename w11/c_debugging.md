# How to debug Embedded C

## Undeclared Variable

Compiler output:

```c
../main.c(48): error: use of undeclared identifier 'Device_ID'
    Device_ID = MPU6500_I2C_Read_OneByte(0x75);
    ^
../main.c(49): error: use of undeclared identifier 'Device_ID'
    printf("I2C slave device ID: %02x\n\r", Device_ID); 
                                            ^
../main.c(50): error: use of undeclared identifier 'Device_ID'
    while(!(Device_ID ==  0x70));
            ^
3 errors generated.
compiling main.c...
".\HT32\52352\Obj\HT32.axf" - 3 Error(s), 0 Warning(s).
```

Human readable words:

1. In ```main.c``` line 48, undeclared variable 'Device_ID'.
2. In ```main.c``` line 49, undeclared variable 'Device_ID'.
3. In ```main.c``` line 50, undeclared variable 'Device_ID'.

Solution:

```c
/* Private variables ---------------------------------------------------------------------------------------*/
u8 Device_ID; //<----
u16 Acc_Raw_Value[3];
```

## Accessing Invalid Array Element

Compiler output:

```c
../main.c(64): warning: array index 2 is past the end of the array (which contains 2 elements) [-Warray-bounds]
        printf("Acc%s%s%c%s --> Raw_Value_DEC: %05d , Raw_Value_HEX: %04x , Acc_Scale: %f\t\n\r", FORMAT_BOLD, FORMAT_RED, Axis[2], FORMAT_RESET, Acc_Raw_Value[2], Acc_Raw_Value[2], Acc_Scale(Acc_Raw_Value[2]));
                                                                                                                           ^    ~
../MPU6500.h(25): note: array 'Axis' declared here
u8 Axis[2] = {'X', 'Y'};
^
1 warning generated.
compiling main.c...
linking...
Program Size: Code=6232 RO-data=320 RW-data=8 ZI-data=528  
FromELF: creating hex file...
After Build - User command #1: fromelf --bin -o ".\HT32\52352\Obj\HT32.axf.bin" ".\HT32\52352\Obj\HT32.axf"
".\HT32\52352\Obj\HT32.axf" - 0 Error(s), 1 Warning(s).
```

Human readable words:

1. In ```main.c``` line 64, your code is accessing array ```Axis``` index 2 which doesn't exist for this array.
2. This array ```Axis``` is declared in ```MPU6500.h``` line 25, which only contains maximum 2 elements.

Solution:

```c
/* Constant */
u8 Axis[3] = {'X', 'Y', 'Z'}; //<---
        ^                ^
```
