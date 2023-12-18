# Q&A

## 1. UART Connection Speed (Baud Rate)

Q: Can two device with different baud rate (ex, 9600/115200) communicate?  
A: No, needs to be the same.

## 2. Control High Power (High Voltage/Current)

Q: How can I control a fan with MCU?  
A: Use either GPIO or PWM signal to control some kind of switch, like ```Relay``` or ```MOSFET```. These switches takes input current from DC power supply and export to your fan or any other high power device.

## 3. How to find compatible device to connect

Q: I want to connect to a smoke sensor. How?  
A: Find it's communication protocol (UART, SPI, I2C...) with their datasheet. You can search them online. Be sure to check it's power requirement like voltage and current.

## 4. How to use another USART for Bluetooth comm?

Q: How can I use a Bluetooth module (USART/UART protocol) at the same time with displaying debugging info on Tera Term?  
A: Refer to settings in ```./example/USART/Interrupt```, and use USART0 instead of USART1 for Bluetooth module communication. (With specified PIN in datasheet)

## 5. How can I add additional C and H file into project?

Q: I want to include additional libraries downloaded from the Internet, how?
A: In Keil uVision 5, go to "Options for target"/"C/C++(AC6)"/"Include Paths"/"...", and type in the directory your files located.

## 6. How to get started to a project?

Q: I have no clue on how to start working on my project, how?
A: The following are steps we generally take to work on new project:

1. Determine required functionalities, like temperature sensing, distance measuring, ....
2. Determine (search for) module used to fulfill required functionalities. (ex: temperature->DS18B20 module)
3. Find corresponding communication protocol (Datasheet). (ex: DS18B20->1 Wire Bus)
4. Check whether your MCU support the required protocol. (1 Wire Bus can be implemented with UART)
5. Check required PIN is available.
6. Go to corresponding protocol/functionality example to look for library function usage. (ex: UART->example/USART/Interrupt)
7. Adjust its settings based on datasheet's requirement.
8. Confirm each individual sensor can operate correctly with example code and adjusted settings.
9. Merge different example code and continue to test step by step.

How to use those commonly used protocol is available in each week's content.  
How to merge projects together is available in experiment 8.

## Additional Sources

1. Phase array (sonar scanner). <https://www.youtube.com/watch?v=z4uxC7ISd-c>
