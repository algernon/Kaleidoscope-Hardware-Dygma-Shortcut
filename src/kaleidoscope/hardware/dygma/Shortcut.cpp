/* -*- mode: c++ -*-
 * Kaleidoscope-Hardware-Dygma-Shortcut -- Shortcut hardware support for Kaleidoscope
 * Copyright (C) 2017-2018  Keyboard.io, Inc
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef ARDUINO_AVR_SHORTCUT

#include <Kaleidoscope.h>
#include <avr/wdt.h>

#include "shortcut/Light_WS2812/light_ws2812.h"

namespace kaleidoscope {
namespace hardware {
namespace dygma {

ATMEGA_KEYBOARD_DATA(Shortcut);
constexpr int8_t Shortcut::led_count;

void Shortcut::syncLeds(void) {
  ws2812_sendarray((uint8_t *)leds, sizeof(cRGB) * led_count);
}

void Shortcut::setCrgbAt(uint8_t i, cRGB crgb) {
  leds[led_count - i - 1] = crgb;
}

cRGB Shortcut::getCrgbAt(uint8_t i) {
  return leds[led_count - i - 1];
}

}
}
}

HARDWARE_IMPLEMENTATION KeyboardHardware;
kaleidoscope::hardware::dygma::Shortcut &Shortcut = KeyboardHardware;

#endif
