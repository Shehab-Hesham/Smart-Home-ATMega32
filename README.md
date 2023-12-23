# Smart-Home-ATMega32
Automated smart home using keypad inputs for passwords and control commands through UART.

User 1's Password = 21
User 1's Password = 222
Admin's Password = 123

There are 5 LEDs, 1 Dimmer, 1 Door (Servo Motor), 1 ADC Temperature Sensor, an Air Conditioner (DC Motor), LCD, Keypad, and UART Terminal.
One can enter the system in one of two modes: Admin or User, depending on the entered password on the keypad.

Once logged in, one can control the above mentioned devices as follows using UART inputs:

Door: Enter 'H' to open, enter 'I' to close. (Admin mode only)

LED 1: Enter '1' to turn on, enter 'C' to turn off.
LED 2: Enter '2' to turn on, enter 'D' to turn off.
LED 3: Enter '3' to turn on, enter 'E' to turn off.
LED 4: Enter '4' to turn on, enter 'F' to turn off.
LED 5: Enter '5' to turn on, enter 'G' to turn off.

Light Dimmer: Enter '6' to turn off. Enter '7' to turn on (25% Light). Enter '8' to turn on (50% Light). Enter '9' to turn on (75% Light). Enter 'A' to turn on (100% Light).

One can log out by entering '0'.
