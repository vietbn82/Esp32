#include <Arduino.h>

#define LED_PIN 5
#define BUTTON_PIN 4

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  digitalWrite(LED_PIN, LOW);
}

void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("HIGH");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("LOW");
  }
}
