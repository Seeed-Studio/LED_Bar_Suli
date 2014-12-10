// Grove LED Bar - Level Example
// This example will show you how to use setLevel() function of this library.
// The setLevel() function illuminates the given number of LEDs from either side.

// Syntax setLevel(level)
// 0  = all LEDs off
// 5  = 5 LEDs on
// 10 = all LEDs on


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
  // Walk through the levels
  for (int i = 0; i <= 10; i++)
  {
    bar.setLevel(i);
    delay(100);
  }
}
