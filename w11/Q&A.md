# Q&A

## 1. UART Connection Speed (Baud Rate)

Q: Can two device with different baud rate (ex, 9600/115200) communicate?
A: No, needs to be the same.

## 2. Control High Power (High Voltage/Current)

Q: How can I control a fan with MCU?
A: Use either GPIO or PWM signal to control some kind of switch, like ```Relay``` or ```MOSFET```. These switches takes input current from DC power supply and export to your fan or any other high power device.

## 3. How to find compatible device to connect.

Q: I want to connect to a smoke sensor. How?
A: Find it's communication protocol (UART, SPI, I2C...) with their datasheet. You can search them online. Be sure to check it's power requirement like voltage and current.
