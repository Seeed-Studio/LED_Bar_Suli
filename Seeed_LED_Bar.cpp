/*
  Seeed_LED_Bar.cpp
  This is a Suli compatable Library

  2014 Copyright (c) Seeed Technology Inc.  All right reserved.

  Loovee
  2013-3-26

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "Seeed_LED_Bar.h"


IO_T __pinClk;
IO_T __pinDta;

bool __greenToRed = 0;     // ascending or decending
unsigned int __state = 0;  // persist state so individual leds can be toggled

void led_bar_init(PIN_T pinClk, PIN_T pinDta bool greenToRed)
{
  suli_pin_init(&__pinClk, pinClk);
  suli_pin_dir(&__pinClk, HAL_PIN_OUTPUT);

  suli_pin_init(&__pinDta, pinDta);
  suli_pin_dir(&__pinDta, HAL_PIN_OUTPUT);
}

void latchData()
{
  suli_pin_write(&__pinDta, LOW);
  suli_delay_us(10);

  for (unsigned char i = 0; i < 4; i++)
  {
    suli_pin_write(&__pinDta, HIGH);
    suli_pin_write(&__pinDta, LOW);
  }
}

void send16bitData(unsigned int data)
{
  for (unsigned char i = 0; i < 16; i++)
  {
    unsigned int state = data & 0x8000 ? HIGH : LOW;
    suli_pin_write(&__pinDta, state);

    state = suli_pin_read(&__pinClk) ? LOW : HIGH;
    suli_pin_write(&__pinClk, state);

    data <<= 1;
  }
}

// Change the orientation
// Green to red, or red to green
void led_bar_set_green_to_red(bool greenToRed)
{
  __greenToRed = greenToRed;

  led_bar_set_bits(__state);
}

// Set level (0-10)
// Level 0 means all leds off
// Level 10 means all leds on
void led_bar_set_level(unsigned char level)
{
  level = max(0, min(10, level));

  // Set level number of bits from the left to 1
  __state = ~(~0 << level);

  led_bar_set_bits(__state);
}

// Set a single led
// led (1-10)
// state (0=off, 1=on)
void led_bar_set_led(unsigned char led, bool state)
{
  led = max(1, min(10, led));

  // Zero based index 0-9 for bitwise operations
  led--;

  // Bitwise OR or bitwise AND
  __state = state ? (__state | (0x01<<led)) : (__state & ~(0x01<<led));

  led_bar_set_bits(__state);
}

// Toggle a single led
// led (1-10)
void led_bar_toggle_led(unsigned char led)
{
  led = max(1, min(10, led));

  // Zero based index 0-9 for bitwise operations
  led--;

  // Bitwise XOR the leds current value
  __state ^= (0x01<<led);

  led_bar_set_bits(__state);
}

// Set the current state, one bit for each led
// 0    = 0x0   = 0b000000000000000 = all leds off
// 5    = 0x05  = 0b000000000000101 = leds 1 and 3 on, all others off
// 341  = 0x155 = 0b000000101010101 = leds 1,3,5,7,9 on, 2,4,6,8,10 off
// 1023 = 0x3ff = 0b000001111111111 = all leds on
//                       |        |
//                       10       1
void led_bar_set_bits(unsigned int bits)
{
  send16bitData(CMDMODE);

  for (unsigned char i=0; i<10; i++)
  {
    if (__greenToRed)
    {
      // Bitwise AND the 10th bit (0x200) and left shift to cycle through all bits
      send16bitData((bits << i) & 0x200 ? ON : SHUT);
    }
    else
    {
      // Bitwise AND the 1st bit (0x01) and right shift to cycle through all bits
      send16bitData((bits >> i) & 0x01 ? ON : SHUT);
    }
  }

  // Two extra empty bits for padding the command to the correct length
  send16bitData(0x00);
  send16bitData(0x00);

  latchData();
}


// Return the current state
unsigned int led_bar_get_bits()
{
  return __state;
}
