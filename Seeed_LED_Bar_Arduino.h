/*
  Seeed_LED_Bar_Arduino.h
  For Arduino Only
  This is a Suly compatible Library
  
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

#ifndef __SEEED_LED_BAR_ARDUINO_H__
#define __SEEED_LED_BAR_ARDUINO_H__

#include "Seeed_LED_Bar.h"

class SeeedLedBar{

public:

/*
 * Initialize, set pin number
 */
SeeedLedBar(int pinClk, int pinDta)         // CLK, DTA
{
    led_bar_init(pinClk, pinDta);
}
    
/*
 * set led single bit, a bit contrl a led
 * such as, index_bits = 0x05, then led 0  and led 3 will on, the others will off
 */
void indexBit(unsigned int index_bits)
{
    led_bar_index_bit(index_bits);
}

/*
 * set level, there level 0-10
 * level 0 means all leds off while level 5 means 5led on and the other will off
 */
 
void setLevel(int level)
{
    led_bar_set_level(level);
}

/*
 * control a single led
 * num - which led
 * st - 1: on   0: off
 */
void setSingled(int num, int st)
{
    led_bar_single_led(num, st);
}


};


#endif