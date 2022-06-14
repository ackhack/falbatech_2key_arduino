# FalbaTech 2Key Arduino
This Repository contains unoffical Arduino Files to run the 2 Key Keyboard from FalbaTech.


## Installation
 - Install the offical Arduino IDE from the [Website](https://www.arduino.cc/en/software)
 - Download the Code (if you don't know how, press the green Code Button and choose Download ZIP)
 - Open one of the .ino Files in the modes Folder with the IDE (default is Keyboard_min.h/rainbowColor/rainbowColor.ino)
 - Include the `FastLED` Library
 - In Tools, set the Board to `Arduino Micro`
 - Set the Port to your Keyboard
 - Set the Programmer to `AVRISP mkII`
 - While the Keyboard is connected, build and upload the Code (Ctrl+U)


 ## The Modes
 Every mode in the Keyboard.h folder will use the default Keyboard.h file. This file is slower but the standard for Arduinos. But you will need to include it.
 Every mode in the Keyboard_min.h folder will use my customized Keyboard_min.h file. It runs faster than the standard, as the code is optimized for this particular Arduino.
 Every mode in the macro folder will use the default Keyboard.h file. But the keys can be mapped to multiple inputs.

Every mode except the macros have the variables `LeftKey`, `RightKey` and `MiddleKey`. They map to the three buttons on the device, so the reported buttonpresses can be changed. Any normal character can be represented by putting them in '' (e.g. 'x' '1'), if you want any different characters like Tab or Esc, you need to represent them with Hex Values (e.g. 0xB1 = Esc) [info](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/).

### colorOnClick mode
The LEDs will turn on while their matching button is pressed. The Colors can be changed by `ColorLeft`, `ColorRight` and `Brightness`.
### rainbowColor mode
The LEDs will have a rainbow effect. To change the effect, the variables `GradientChange`, `Speed`, `Brightness` and `currColor` can be changed. While `currColor` only changes the starting Color.
### singleColor mode
The LEDs will show only a single Color. The Color can be changed by `Color` and `Brightness`.

## Macros
This mode uses the default Keyboard.h. In the macros folder, the variables `LeftKey`, `RightKey` and `MiddleKey` will be two dimensional arrays. The device supports up to 6 simultaneous keypresses. The first dimension array will be pressed one after another. The buttons in the second dimensonal arrays will be pressed simultaneous. So {{0x80, 0x61}, {0x80, 0x63}} will press Ctrl+A and then Ctrl+C. {{0x80, 0x76}} will press Ctrl+V. {{0xB1}} will press only Escape.

 ## More Info
 - The Project can also be used in the PlatformIO IDE, just copy the desired Mode into src/falbatech_2key.ino
 - The Single Color Mod is in theory the fastest, as it does not need to update the LEDs
 - The Board will be used as an Arduino Micro, you can use the Arduino Leonardo as well, but it does not allow the TX/RX LEDs to turn off
 - The Colors are represent as an integer value from 0 to 255
 - The Brightness is represent as an integer value from 0 to 255