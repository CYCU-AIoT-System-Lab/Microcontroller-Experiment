# I2C / I2C_MPU6500 | Experiment Steps

## Preparation

1. Download project from i-learning or duplicate a local I2C project and modify its code with ```./main.c```, ```./MPU6500.h```, ```./ht32f5xxxx_01_it.c```, and ```./ht32_board_config.h```.
2. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/I2C/I2C_MPU6500".
3. Launch 52352 project.

## Homework 11-1

Objective: Display Y axis data besides X and Z.

Hint: Modify code in while loop, main function.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code.
   1. Retrieve Y axis acceleration data from register.
   2. Print out Y axis value.
   3. Change cursor move up string.
2. Connect circuit.
   1. VDD to VCC.
   2. GND to GND.
   3. SCL to SCL.
   4. SDA to SDA.

</details>

Result: <https://youtu.be/Pkrd-i2eFxs>
