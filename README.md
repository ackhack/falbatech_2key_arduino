# FalbaTech 2Key Arduino
This Repository contains unoffical Arduino Files to run the 2 Key Keyboard from FalbaTech.

## Installation
 - Install the offical Arduino IDE from the [Website](https://www.arduino.cc/en/software) or the [PlatformIO IDE](https://marketplace.visualstudio.com/items?itemName=platformio.platformio-ide) Extension for VS Code
 - If you use the offical Arduino IDE, install the FastLED Library, PlatformIO IDE does this automatically
 - Copy the Content of any Mode in the modes Folder into the src/falbatech_2key.ino File (default is singleColor)
 - Edited the `Color` or `Key To Char` Settings as desired
 - While the Keyboard is connected, build and upload the Code (Arduino IDE: Ctrl+U || PlatformIO IDE: Ctrl+Alt+U)

 ## More Info
 - The Keyboard runs at a 1000 Hz Polling Rate as close as it can get, you can remove the delay(1) in the loop Funtion to speed it up
 - The Single Color Mod is in theory the fastest, as it does not need to update the LEDs
 - The Board will be used as an Arduino Micro, you can use the Arduino Leonardo as well, but it does not allow the TX/RX LEDs to turn off
 - The Colors are represent as an integer value from 0 to 255, the most common ones are in the CRGB struct
 - The Brightness is represent as an integer value from 0 to 255