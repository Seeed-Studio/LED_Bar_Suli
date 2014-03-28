/*
  Seeed_LED_Bar.h
  This is a Suly compatable Library
  
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

#ifndef __SEEED_LED_BAR_H__
#define __SEEED_LED_BAR_H__

#include <Suli.h>


#define BIT_Data    0x01
#define BIT_Clk     0x02

#define CMDMODE     0x0000  //Work on 8-bit mode
#define ON          0x00ff   //8-bit 1 data
#define SHUT        0x0000   //8-bit 0 data


void led_bar_init(PIN_T pinClk, PIN_T pinDta);


// set led single bit, a bit contrl a led
// such as, index_bits = 0x05, then led 0  and led 3 will on, the others will off
void led_bar_index_bit(unsigned int index_bits);


// set level, there level 0-10
// level 0 means all leds off while level 5 means 5led on and the other will off
void led_bar_set_level(int level);


// control a single led
// num - which led
// st - 1: on   0: off
void led_bar_single_led(int num, int st);


#endif