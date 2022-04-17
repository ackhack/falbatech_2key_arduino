#include "Keyboard.h"
#include "FastLED.h"

// Color Settings
const int Color = 0;
const uint8_t Brightness = 200;

// Macro Bindings (https://www.arduino.cc/en/Reference/KeyboardModifiers)
const int LeftKey[][2] = {{0x80, 0x61}, {0x80, 0x63}}; //Ctrl+A, Ctrl+C
const int RightKey[][2] = {{0x80, 0x76}}; //Ctrl+V
const int MiddleKey[][2] = {{0xB1}}; //Esc

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
    FastLED.setBrightness(Brightness);
    FillLEDsFromPaletteColors();
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
    delay(1);
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
    }
    else
    {
        leftKeyPressed = false;
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
    }
    else
    {
        rightKeyPressed = false;
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

void FillLEDsFromPaletteColors()
{
    for (int i = 0; i < 2; i++)
    {
        leds[i] = ColorFromPalette(RainbowColors_p, Color, Brightness, LINEARBLEND);
    }
}
