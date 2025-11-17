#include <Arduino.h>

#define LED_BUILTIN 2
#define BTN_BUILTIN 0
class DelayDemo
{
public:
    void setup()
    {
        pinMode(LED_BUILTIN, OUTPUT);
        pinMode(BTN_BUILTIN, INPUT_PULLUP);
    }

    void loop()
    {
        static bool lastBtnState = HIGH;
        if (digitalRead(BTN_BUILTIN) == LOW)
        {
            if (lastBtnState == HIGH)
            {
                digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
                delay(200); // Debounce delay
            }
            lastBtnState = LOW;
        }
        else
        {
            lastBtnState = HIGH;
        }
    }
};