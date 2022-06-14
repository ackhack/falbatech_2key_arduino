# FalbaTech 2Key Arduino
This Repository contains unoffical Arduino Files to run the 2 Key Keyboard from FalbaTech.

## Installation
 - Install the offical Arduino IDE from the [Website](https://www.arduino.cc/en/software)
 - Open one of the .ino Files in the modes Folder with the IDE
 - Include the `Keyboard` and `FastLED` Libraries
 - In Tools, set the Board to `Arduino Micro`
 - Set the Port to your Keyboard
 - Set the Programmer to `AVRISP mkII`
 - Edited the `Color` or `Key To Char` Settings as desired
 - While the Keyboard is connected, build and upload the Code (Ctrl+U)

 ## More Info
 - The Project can also be used in the PlatformIO IDE, just copy the desired Mode into src/falbatech_2key.ino
 - The Single Color Mod is in theory the fastest, as it does not need to update the LEDs
 - The Board will be used as an Arduino Micro, you can use the Arduino Leonardo as well, but it does not allow the TX/RX LEDs to turn off
 - The Colors are represent as an integer value from 0 to 255
 - The Brightness is represent as an integer value from 0 to 255