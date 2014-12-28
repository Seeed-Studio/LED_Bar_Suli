// Grove LED Bar - Control Single LED Example
// This example will show you how to use the setLed() function of this library.
// There are 10 LEDs in the Grove LED Bar.
// Use this method to set a single LED.

// Syntax setLed(led, state)
// led (1-10)
// state (0=off, 1=on)


#include <Suli.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Seeed_LED_Bar_Arduino.h"

SeeedLedBar bar(A4, A5, 0);    // CLK, DTA, Orientation

void setup()
{

}

void loop()
{
  // Set LED 3 on
  bar.setLed(3, 1);
  delay(500);

  // Set LED 5 on
  bar.setLed(5, 1);
  delay(500);

  // Set LED 7 on
  bar.setLed(7, 1);
  delay(500);

  // Set LED 3 off
  bar.setLed(3, 0);
  delay(500);

  // Set LED 5 off
  bar.setLed(5, 0);
  delay(500);

  // Set LED 7 off
  bar.setLed(7, 0);
  delay(500);

  // Turn all LEDs on
  for (int i = 1; i <= 10; i++)
  {
    bar.setLed(i, 1);
    delay(500);
  }

  // Turn all LEDs off
  for (int i = 1; i <= 10; i++)
  {
    bar.setLed(i, 0);
    delay(500);
  }
}
