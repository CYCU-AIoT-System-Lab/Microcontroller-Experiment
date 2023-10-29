# TM / PWM | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/TM/".
2. Duplicate project folder "PWM_Buzzer" as "PWM_with_ADC".
3. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/TM/PWM_with_ADC".
4. Launch 52352 project.

## Homework 8-1

Objective:  Change the behavior of buzzer when gPotentiometerLevel>2000.

Hint:

1. Ensure both "/TM/PWM_with_ADC" and "/ADC/Continuous_Potentiometer" projects are working.
2. Add the required functions and files from "/ADC/Continuous_Potentiometer" to "/TM/PWM_with_ADC".
3. Use ```A6```(甲班)/```A7```(乙班) for ADC, ```A10```(甲班)/```B0```(乙班) for Buzzer.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code. (follows instruction in PPT)
2. Connect ```A6```(甲班)/```A7```(乙班) to JP16, ```A10```(甲班)/```B0```(乙班) to JP9.
3. After powered on and loaded with modified code, beeping pattern of buzzer should change when gPotentiometerLevel crosses 2000.

</details>

Result: <https://youtu.be/OQTJE1XG47o>

## Homework 8-2

Objective: Make buzzer play all the note in P26 with the control of variable resistor.

Hint:

1. Modify main.c as shown in P27 in PPT.
2. Finish the code in while loop and execute it.
3. Use ```A6```(甲班)/```A7```(乙班) for ADC, ```A10```(甲班)/```B0```(乙班) for Buzzer.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code. (follows instruction in PPT)
2. After powered on and loaded with modified code, the beeping frequency should change whenever gPotentiometerLevel changes over 113.

</details>

Result: <https://youtu.be/m9Z_blktml4>
