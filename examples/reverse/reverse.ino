// Grove LED Bar - Reverse Example
// This example will show you how to use setGreenToRed() function of this library.
// The function is used to reverse the orientation of the LED Bar.


#include <Suli.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Seeed_LED_Bar_Arduino.h"

// The 3rd parameter sets the initial orientation
// 0 = red to green, 1 = green to red
// You can always change it at runtime with the setGreenToRed() function
SeeedLedBar bar(A4, A5, 0);    // CLK, DTA, Orientation

void setup()
{

}

void loop()
{
  // Start as red to green
  // Walk through the 10 levels
  for (int i = 0; i <= 10; i++)
  {
    bar.setLevel(i);
    delay(200);
  }
  bar.setLevel(0);

  // Swich to green to red
  bar.setGreenToRed(1);

  // Walk through the 10 levels
  for (int i = 0; i <= 10; i++)
  {
    bar.setLevel(i);
    delay(200);
  }
  bar.setLevel(0);

  // Switch back to red to green
  bar.setGreenToRed(0);
  delay(200);

  // Walk through the levels
  // Each reverse keeps the previously set level
  for (int i = 1; i <= 10; i++)
  {
    bar.setLevel(i);
    delay(500);

    bar.setGreenToRed(1);
    delay(500);

    bar.setGreenToRed(0);
  }
  bar.setLevel(0);
}
