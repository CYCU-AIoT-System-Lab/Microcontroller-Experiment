# TM / PWM Buzzer | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/TM/PWM_Buzzer".
2. Execute "_CreateProject.bat".
3. Launch 52352 project.

## Homework 4-1

Objective: Use timer to control buzzer and display in Tera Term.

Hint:

1. Use pin A10(甲班)/B0(乙班)

<details><summary>Experiment Steps:</summary>

1. Modify code.
   1. Configure USART communication.
   2. Print value in register to Tera Term.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. A10(甲班)/B0(乙班) to JP9.
3. After powered on and loaded with modified code, Tera Term should display what is "printf" in code and play sound with buzzer.

</details>

Result: <https://youtu.be/jCMfqXhKw2I>

## Homework 4-2

Objective: Play a part of "Little Bee Song"(甲班)/"For Alice"(乙班).

Hint:

1. Use pin A10(甲班)/B0(乙班)
2. Look for numbered musical notation of "Little Bee Song"(甲班)/"For Alice"(乙班).
3. Find the corresponding scale frequency.
4. Edit gBee_Scale.

<details><summary>Experiment Steps:</summary>

1. Modify code.
   1. Edit array "gBee_Scale".
   2. Remove unnecessary code.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. A10(甲班)/B0(乙班) to JP9.
3. After powered on and loaded with modified code, the buzzer should play the song you coded.

</details>

Result: <https://youtu.be/g1pHioxOzoQ>

## Homework 4-3

Objective: Play "Little Bee Song"(甲班)/"For Alice"(乙班) faster.

Hint:

1. Use pin A10(甲班)/B0(乙班).
2. Edit "Buzzer_PlayTable" function.

<details><summary>Experiment Steps:</summary>

1. Modify code.
   1. Edit "Buzzer_PlayTable" delay parameter.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. A10(甲班)/B0(乙班) to JP9.
3. After powered on and loaded with modified code, the buzzer should play the song you coded faster.

</details>

Result: <https://youtu.be/9lugvTlxR5s>