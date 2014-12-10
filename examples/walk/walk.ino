// Grove LED Bar - Walk Example
// This example will show you how to use setBits() function of this library.
// Set any combination of LEDs using 10 bits.
// This example walks through all 1024 (2^10) possible combinations.


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
  // 0 = 0x0 = all 10 LEDs turned off
  // 1023 = 0x3FF = all 10 LEDs lit up
  for (int i = 0; i <= 1023; i++)
  {
    bar.setBits(i);
    delay(50);
  }
}
