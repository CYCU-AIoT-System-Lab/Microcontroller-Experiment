# ADC / Continuous Potemtiometer | Experiment Steps

## Preparation

1. Go to "~/HT32_STD_5xxxx_FWLib_V1.5.1_7084/example/ADC/Continuous_Potentiometer".
2. Execute "_CreateProject.bat".
3. Launch 52352 project.

## Homework 3-1

Objective: Use potentiometer to display measured voltage.

Hint:

1. Use pin A6 to connect to JP16.
2. Reference formula in slide p. 16 ADC specifications.

<details><summary>Experiment Steps:</summary>

1. Modify printing value in "main" function by above mentioned formula to display voltage value.
2. Connect ESK32-30501 dev-board to ESK300 eval-board. (without power)
   1. VDD to 3V3.
   2. GND to GND.
   3. PA6 to JP16.
3. After powering on and loading with modified code, turn the potentiometer on ESK300 eval-board. Tera Term should display current voltage value live.

</details>

Result: <https://youtu.be/q40l9CMwMS4>

## Homework 3-2

Objective: High voltage indicator. Measuring potentiometer level, turn red light of RBG LED on if larger than 2000. Turn green light on otherwise.

Hint:

1. Use pin A6 to connect to JP16.
2. Use pin C14/15 to connect to JP17.

Result: <https://youtu.be/K4dNRj2S0x4>