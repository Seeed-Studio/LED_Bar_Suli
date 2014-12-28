// Grove LED Bar - Set Level Example


#include <Suli.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include "Seeed_LED_Bar_Arduino.h"

// The 3rd parameter sets the initial orientation
// 0 = red to green, 1 = green to red
SeeedLedBar bar(A4, A5, 0);    // CLK, DTA, Orientation

int level = 0;

void setup()
{

}

void loop()
{
  bar.setLevel(level++);

  level = level>10 ? 0 : level;

  delay(100);
}
