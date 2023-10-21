# TM / PWM | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/TM/PWM".
2. Execute "_CreateProject.bat".
3. Launch 52352 project.

## Homework 7-1

Objective: Observe output signal with oscilloscope and explain the code.

Hint:

1. Use key "F12" to locate specified pins and connect them.
2. Increase the default delay time for result observation.
3. Connect PWM ```CH0 & CH1```(甲班)/```CH2 & CH3```(乙班) to the oscilloscope.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code. (乙班)
   1. Lines 58, 64, 74: ```PWM_CH0``` :arrow_right: ```PWM_CH2```
   2. Lines 59, 65, 75: ```PWM_CH1``` :arrow_right: ```PWM_CH3```
2. Connect ```CH0 & CH1```(甲班)/```CH2 & CH3```(乙班) to oscilloscope.
3. After powered on and loaded with modified code, oscilloscope should display two PWM signals.

</details>

Result: <https://youtu.be/36aacR8vptQ>

## Homework 7-2

Objective: Modify code and connect ```CH0```(甲班)/```CH2```(乙班) to oscilloscope, and use ```CH1```(甲班)/```CH3```(乙班) to control SG90.

Hint:

1. Connect ```CH0```(甲班)/```CH2```(乙班) to oscilloscope.
2. Connect ```CH1```(甲班)/```CH3```(乙班) to servo motor SG90, and rotate it to 0, 45, 90, 135, and 180 degrees angle.
3. Edit code in files: ```main.c``` & ```PWM.h```.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code.
   1. pwm.h
      1. Adjust ```HTCFG_PWM_TM_PRESCALER``` to make $\cfrac{48MHz}{50\times HTCFG\_PWM\_TM\_PRESCALER}\leq65536$.
      2. Adjust ```HTCFG_PWM_FREQ_HZ``` to 50.
      3. Add new macro ```PWM_DUTY_0``` ~ ```PWM_DUTY100``` according to PPT.
   2. main.c
      1. Modify code to switch to different ```PWM_DUTY``` one by one.
2. Connect wires.
   1. ```CH0```(甲班)/```CH2```(乙班) :arrow_right: oscilloscope.
   2. ```CH1```(甲班)/```CH3```(乙班) :arrow_right: servo motor SG90 orange wire.
   3. 5V :arrow_right: servo motor SG90 red wire.
   4. GND :arrow_right: servo motor SG90 brown wire.
3. After powered on and loaded with modified code, signal with different duty cycle should appear on oscilloscope and SG90 should rotate accordingly.

</details>

Result: <https://youtu.be/L8faNfCOW4A>

## Homework 7-3

Objective: Use laptop keyboard (Tera Term) input Duty Cycle to control SG90.

Hint:

1. Connect ```CH0```(甲班)/```CH2```(乙班) to oscilloscope.
2. Connect ```CH1```(甲班)/```CH3```(乙班) to servo motor SG90, and use user input to rotate it to 0, 45, 90, 135, and 180 degrees angle.
3. Edit code.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code.
   1. Add code on PPT to your main.c.
2. Connect wires.
   1. ```CH0```(甲班)/```CH2```(乙班) :arrow_right: oscilloscope.
   2. ```CH1```(甲班)/```CH3```(乙班) :arrow_right: servo motor SG90 orange wire.
   3. 5V :arrow_right: servo motor SG90 red wire.
   4. GND :arrow_right: servo motor SG90 brown wire.
3. After powered on and loaded with modified code, you should be able to use input from Tera Term to control the rotation of SG90.

</details>

Result: <https://youtu.be/97nUNzzfz-c>

## Homework 7-4 Bonus

Objective: Use three buttons to control SG90 to rotate to 0, 90, and 180 degrees.

Hint:

1. Connect ```CH0```(甲班)/```CH2```(乙班) to oscilloscope.
2. Connect ```CH1```(甲班)/```CH3```(乙班) to servo motor SG90, and use user input to rotate it to 0, 90, and 180 degrees angle.
3. Refer to week 2 example ```GPIO/InputOutput```.

Result: <https://youtu.be/7Mu6fSOrbyc>
