# GPIO / InputOutput | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/GPIO/InputOutput".
2. Execute "_CreateProject.bat".
3. Launch 52352 project.
4. The steps in "Modify GPIO project" is not necessarily needed. It's to help people understand what they are working with.

## Homework 2-2

Objective: Configure two buttons, one turns on LED, another turns off LED.

Hint:

1. Use pin PC14, PC15 to connect to JP13.
2. Each button in key board matrix is connect with both terminal to their corresponding numbered pin in JP24.
3. Use pin PD1, PB12 to connect to JP24 input section.
4. JP24 output section connect to 3V3 and GND.

Steps:

1. No code change is needed.
2. Connect ESK32-30501 development board to ESK300 evaluation board. (without power)
   1. VCC to 3V3.
   2. GND to GND.
   3. PC14, PC15 to JP13.
   4. PB12 to JP24-0.
   5. PD1 to JP24-1.
   6. GND to JP24-5.
   7. 3V3 to JP24-4.
3. After powering on, pressing key0/4 should turn LED off; pressing key1/5 should turn LED on.

Result: <https://youtu.be/K46_xkXOUrc>

## Homework 2-3

Objective: Make LED lights flash using the delay function.

Hint:

1. Use pin PC14, PC15, PB0, PB1, PB2, PB3, PB4, PB5 to attach with LED0~7.
2. Add the delay function and modify the main function.
3. Draw the wiring diagram and explain how to turn the LEDs on.

Steps:

1. Configure 8 GPIO output pins in function "GPIO_OUT_Configuration".
2. Configure corresponding CKCU in function "CKCU_Configuration".
3. In "main" function, comment out function "GPIO_IN_Configuration".
4. Add delay function.
5. Add delay function declaration.
6. Modify function "GPIO_MainRoutine".
7. Compile and make sure no error exists.
8. Connect ESK32-30501 development board to ESK300 evaluation board. (without power)
   1. VCC to 3V3.
   2. GND to GND.
   3. PC14, PC15, PB0, PB1, PB2, PB3, PB4, PB5 to LED0~7.
9. Connect ESK32-30501 development board to computer and load compiled code onto it.

Result: <https://youtu.be/s0h11k8fy1w>

## Homework 2-4

Objective: LED flickers when the button connected with PA0 is pressed.

Hint:

1. Use pin PC14, PC15, PB0, PB1, PB2, PB3, PB4, PB5 to attach with LED0~7.
2. Use pin PD1 to connect with JP24-0.

Result: <https://youtu.be/FwJsIexCTwQ>

## Bonus

Objective: Control the RGB LED to illuminate repeatedly in the sequence of blue, green, red, blue-green, blue-red, green-red, white.

Hint:

1. Use pin PA0, PA1, PC2 to attach with JP17-BGR.

Result: <https://youtu.be/_08Xz7Kt_68>
