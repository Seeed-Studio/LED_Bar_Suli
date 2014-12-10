// Grove LED Bar - Random Example
// This example will show you how to use setBits() function of this library.
// Set any combination of LEDs using 10 bits.


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
  // Display a random value between 0 (all LEDs off) and 1023 (all LEDs on)
  bar.setBits(random(1024));
  delay(50);
}
