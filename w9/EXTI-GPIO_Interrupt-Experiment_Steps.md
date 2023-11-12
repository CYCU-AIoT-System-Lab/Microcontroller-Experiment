# EXTI / GPIO_Interrupt | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/EXTI/GPIO_Interrupt".
2. Execute "_CreateProject.bat".
3. Launch 52352 project.

## Homework 9-1

Objective: Trigger interrupts, which display on Tera Term and toggles LED, by pressing the button.

Hint:

1. Use key "F12" to locate specified pins and connect them.
2. Add the required functions.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. GND to JP24-4.
   4. B12 to JP24-0.
3. After powered on and loaded with modified code, your program should only be triggered once the button JP24-0-4 is pressed.

</details>

Result: <>

## Homework 9-2

Objective: Toggle LED1~3 accordingly when corresponding buttons are pressed.

Hint:

1. Modify code.
2. Connect wires with following requirement.
   1. A11(甲班)/C11(乙班) to JP24-5.
   2. A10(甲班)/C10(乙班) to JP24-6.
   3. PIN LED1 to JP13-7.
   4. PIN LED2 to JP13-6.
   5. PIN LED3 to JP13-5.
3. After powered on and loaded with modified code, your program should:
   1. Toggle JP13-7 when button JP24-0-4 is pressed and display on Tera Term.
   2. Toggle JP13-6 when button JP24-0-5 is pressed and display on Tera Term.
   3. Toggle JP13-5 when button JP24-0-6 is pressed and display on Tera Term.

<details><summary>Experiment Steps: (Click to see more)</summary>

1. Modify code.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. GND to JP24-4.
   4. B12 to JP24-0.
   5. A11(甲班)/C11(乙班) to JP24-5.
   6. A10(甲班)/C10(乙班) to JP24-6.
   7. C14 to JP13-7.
   8. C15 to JP13-6.
   9. C1 to JP13-5.
3. After powered on and loaded with modified code, your program should:
   1. Toggle JP13-7 when button JP24-0-4 is pressed and display on Tera Term.
   2. Toggle JP13-6 when button JP24-0-5 is pressed and display on Tera Term.
   3. Toggle JP13-5 when button JP24-0-6 is pressed and display on Tera Term.

</details>

Result: <>

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
2. Connect ```CH1```(甲班)/```CH3```(乙班) to servo motor SG90.
3. Use pin "A1, A2, A3"(甲班)/"B1, B2, B3"(乙班) to take GPIO input.
4. Refer to week 2 example ```GPIO/InputOutput```.

Result: <https://youtu.be/7Mu6fSOrbyc>
