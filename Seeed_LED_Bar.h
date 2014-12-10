/*
  Seeed_LED_Bar.h
  This is a Suli compatible Library

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

#define CMDMODE     0x00  // Work on 8-bit mode
#define ON          0xff  // 8-bit 1 data
#define SHUT        0x00  // 8-bit 0 data


void led_bar_init(PIN_T pinClk, PIN_T pinDta, bool greenToRed);


// Change the orientation
// Green to red, or red to green
void led_bar_set_green_to_red(bool greenToRed);


// Set level (0-10)
// Level 0 means all leds off
// Level 10 means all leds on
void led_bar_set_level(unsigned char level);


// Set a single led
// led (1-10)
// state (0=off, 1=on)
void led_bar_set_led(unsigned char led, bool state);


// Toggle a single led
// led (1-10)
void led_bar_toggle_led(unsigned char led);


// Set the current state, one bit for each led
// 0    = 0x0   = 0b000000000000000 = all leds off
// 5    = 0x05  = 0b000000000000101 = leds 1 and 3 on, all others off
// 341  = 0x155 = 0b000000101010101 = leds 1,3,5,7,9 on, 2,4,6,8,10 off
// 1023 = 0x3ff = 0b000001111111111 = all leds on
//                       |        |
//                       10       1
void led_bar_set_bits(unsigned int bits);


// Return the current state
unsigned int led_bar_get_bits();


#endif