#include "InterruptDemo.h"

volatile unsigned long InterruptDemo::myVar = 0; // storage definition

void InterruptDemo::setup()
{
    Serial.begin(9600);
    Serial.println("I'm Interrupt.cpp");
    myVar = millis();
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(BTN_BUILTIN, INPUT_PULLUP);
    attachInterrupt(BTN_BUILTIN, IRS, FALLING);
}

void InterruptDemo::loop()
{
    // no-op
}

void IRAM_ATTR InterruptDemo::IRS()
{
    unsigned long currentTime = millis();
    if (currentTime - myVar > 200)
    {
        digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
        myVar = currentTime;
    }
}