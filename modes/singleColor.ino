#include "Keyboard.h"
#include "FastLED.h"

// Color Settings
const int Color = 0;
const uint8_t Brightness = 200;

// Key To Char Bindings
const char LeftKey = 'z';
const char RightKey = 'x';
const int MiddleKey = 0xB1;

// Pin To Key Mappings
const int keyLeftPin = 2;
const int keyRightPin = 3;
const int keyMiddlePin = 16;

CRGB leds[2];

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
        Keyboard.press(LeftKey);
    }
    else
    {
        Keyboard.release(LeftKey);
    }
    if (digitalRead(keyRightPin) == 0)
    {
        Keyboard.press(RightKey);
    }
    else
    {
        Keyboard.release(RightKey);
    }
    if (digitalRead(keyMiddlePin) == 0)
    {
        Keyboard.press(MiddleKey);
    }
    else
    {
        Keyboard.release(MiddleKey);
    }
}

void FillLEDsFromPaletteColors()
{
    for (int i = 0; i < 2; i++)
    {
        leds[i] = ColorFromPalette(RainbowColors_p, Color, Brightness, LINEARBLEND);
    }
}