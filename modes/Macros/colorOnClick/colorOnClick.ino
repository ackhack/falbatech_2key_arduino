#include "Keyboard.h"
#include "FastLED.h"

// Color Settings
const int ColorLeft = 0;
const int ColorRight = 0;
const uint8_t Brightness = 200;

// Macro Bindings (https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/)
const int LeftKey[][2] = {{0x80, 0x61}, {0x80, 0x63}}; // Ctrl+A, Ctrl+C
const int RightKey[][2] = {{0x80, 0x76}};              // Ctrl+V
const int MiddleKey[][2] = {{0xB1}};                   // Esc

// Pin To Key Mappings
const int keyLeftPin = 2;
const int keyRightPin = 3;
const int keyMiddlePin = 16;

CRGB leds[2];
bool leftKeyPressed = false;
bool rightKeyPressed = false;
bool middleKeyPressed = false;

void setup()
{
    // Dev LEDs off
    TXLED0;
    RXLED0;

    // Safety wait
    delay(3000);

    // Initialize FastLED
    FastLED.addLeds<WS2811, 6, GRB>(leds, 2).setCorrection(TypicalLEDStrip);
    leds[0] = CRGB::Black;
    leds[1] = CRGB::Black;
    FastLED.show();

    // Initialize Pins
    pinMode(keyLeftPin, INPUT_PULLUP);
    pinMode(keyRightPin, INPUT_PULLUP);
    pinMode(keyMiddlePin, INPUT_PULLUP);

    Keyboard.begin();
}

void loop()
{
    proccessButtons();
}

void proccessButtons()
{
    if (digitalRead(keyLeftPin) == 0)
    {
        if (!leftKeyPressed)
        {
            leftKeyPressed = true;
            for (uint8_t i = 0; i < sizeof(LeftKey) / sizeof(LeftKey[0]); i++)
            {
                for (uint8_t j = 0; j < sizeof(LeftKey[i]) / sizeof(LeftKey[i][0]); j++)
                {
                    Keyboard.press(LeftKey[i][j]);
                }
                for (uint8_t j = 0; j < sizeof(LeftKey[i]) / sizeof(LeftKey[i][0]); j++)
                {
                    Keyboard.release(LeftKey[i][j]);
                }
            }
        }
        leds[0] = ColorFromPalette(RainbowColors_p, ColorLeft, Brightness, LINEARBLEND);
        FastLED.show();
    }
    else
    {
        leftKeyPressed = false;
        leds[0] = CRGB::Black;
        FastLED.show();
    }

    if (digitalRead(keyRightPin) == 0)
    {
        if (!rightKeyPressed)
        {
            rightKeyPressed = true;
            for (uint8_t i = 0; i < sizeof(RightKey) / sizeof(RightKey[0]); i++)
            {
                for (uint8_t j = 0; j < sizeof(RightKey[i]) / sizeof(RightKey[i][0]); j++)
                {
                    Keyboard.press(RightKey[i][j]);
                }
                for (uint8_t j = 0; j < sizeof(RightKey[i]) / sizeof(RightKey[i][0]); j++)
                {
                    Keyboard.release(RightKey[i][j]);
                }
            }
        }
        leds[1] = ColorFromPalette(RainbowColors_p, ColorRight, Brightness, LINEARBLEND);
        FastLED.show();
    }
    else
    {
        rightKeyPressed = false;
        leds[1] = CRGB::Black;
        FastLED.show();
    }

    if (digitalRead(keyMiddlePin) == 0)
    {
        if (!middleKeyPressed)
        {
            middleKeyPressed = true;
            for (uint8_t i = 0; i < sizeof(MiddleKey) / sizeof(MiddleKey[0]); i++)
            {
                for (uint8_t j = 0; j < sizeof(MiddleKey[i]) / sizeof(MiddleKey[i][0]); j++)
                {
                    Keyboard.press(MiddleKey[i][j]);
                }
                for (uint8_t j = 0; j < sizeof(MiddleKey[i]) / sizeof(MiddleKey[i][0]); j++)
                {
                    Keyboard.release(MiddleKey[i][j]);
                }
            }
        }
    }
    else
    {
        middleKeyPressed = false;
    }
}