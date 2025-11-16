#include <Arduino.h>

#define LED_PIN 18

const int freq = 5000;
const int resolution = 8; //0-16 bit
const int ledChannel = 0; // 0 -15

void setup() {
  // put your setup code here, to run once:
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(LED_PIN, ledChannel);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    ledcWrite(ledChannel, i);
    delay(20);
  }

  for(int i = 255; i >= 0; i--) {
    ledcWrite(ledChannel, i);
    delay(20);
  }
  delay(5000);

}
