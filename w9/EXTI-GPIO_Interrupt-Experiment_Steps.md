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
   3. GND to JP24-0.
   4. B12 to JP24-4.
3. After powered on and loaded with modified code, your program should only be triggered once the button JP24-0-4 is pressed.

</details>

Result: <https://youtu.be/IBAPzCThSmw>

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
   3. GND to JP24-0.
   4. B12 to JP24-4.
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

Result: <https://youtu.be/J5rq6M999nU>

## Homework 9-3 Bonus

Objective: Use EXTI to control SG90 based on HW7-4.

Hint:

1. Keep all of the wire connection in HW9-2 and add new ones to control SG90.
2. Implement button interrupt to rotate the servo motor to 0, 90, and 180 degrees angle.
3. PWM_CH0(甲班)/PWM_CH1(乙班).

Result: <https://youtu.be/H4Aaaw6TtZY>
