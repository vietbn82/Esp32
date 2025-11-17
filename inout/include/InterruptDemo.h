#pragma once
#include <Arduino.h>

#define LED_BUILTIN 2
#define BTN_BUILTIN 0

class InterruptDemo {
public:
    static volatile unsigned long myVar; // accessed in ISR
    void setup();
    void loop();
    static void IRAM_ATTR IRS();
};
