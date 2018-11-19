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

#pragma once

#ifdef ARDUINO_AVR_SHORTCUT

#include <Arduino.h>
#define HARDWARE_IMPLEMENTATION kaleidoscope::hardware::dygma::Shortcut
#include "Kaleidoscope-HIDAdaptor-KeyboardioHID.h"

#include "kaleidoscope/macro_helpers.h"

typedef struct {
  uint8_t g;
  uint8_t r;
  uint8_t b;
} cRGB;

#define CRGB(r, g, b) (cRGB){g, r, b}

#include "kaleidoscope/hardware/ATMegaKeyboard.h"

namespace kaleidoscope {
namespace hardware {
namespace dygma {

class Shortcut: public kaleidoscope::hardware::ATMegaKeyboard {
  friend class ATMegaKeyboard;
 public:
  Shortcut(void) {}

  ATMEGA_KEYBOARD_CONFIG(
    ROW_PIN_LIST({PIN_D4, PIN_D5, PIN_E2, PIN_E6}),
    COL_PIN_LIST({PIN_F6, PIN_F7, PIN_B4, PIN_B5, PIN_B6, PIN_D7, PIN_C6, PIN_C7, PIN_D3, PIN_D2, PIN_D1, PIN_D0, PIN_B7, PIN_B3})
  );

  void syncLeds(void);
  void setCrgbAt(uint8_t i, cRGB crgb);
  void setCrgbAt(byte row, byte col, cRGB crgb) {}
  cRGB getCrgbAt(uint8_t i);

  static constexpr int8_t led_count = 2;

 private:
  cRGB leds[led_count];
};

#define KEYMAP(                                                                                 \
                     r0c2                                               ,r0c9                   \
              ,r0c1       ,r0c3 ,r0c4                       ,r0cb ,r0ca       ,r0c8             \
        ,r0c0       ,r1c2                                               ,r1c9       ,r0c7       \
  ,r2c0       ,r1c1       ,r1c3 ,r1c4                       ,r1cb ,r1ca       ,r1c8       ,r2c7 \
        ,r1c0       ,r2c2                                               ,r2c9       ,r1c7       \
              ,r2c1       ,r2c3                                   ,r2ca       ,r2c8             \
                                                                                                \
                                 ,r0c6                     ,r0cd                                \
                           ,r1c6       ,r3c6         ,r3cd       ,r1cd                          \
                                 ,r2c6                     ,r2cd                                \
                                                                                                \
                          ,r2c5                                  ,r2cc                          \
                    ,r3c5        ,r1c5                     ,r1cc       ,r3cc                    \
                          ,r0c5                                  ,r0cc                          \
 )                                                                                              \
 {                                                                                              \
   {r0c0, r0c1, r0c2, r0c3, r0c4, r0c5, r0c6, r0c7, r0c8, r0c9, r0ca, r0cb, r0cc, r0cd},        \
   {r1c0, r1c1, r1c2, r1c3, r1c4, r1c5, r1c6, r1c7, r1c8, r1c9, r1ca, r1cb, r1cc, r1cd},        \
   {r2c0, r2c1, r2c2, r2c3,  XXX, r2c5, r2c6, r2c7, r2c8, r2c9, r2ca,  XXX, r2cc, r2cd},        \
   { XXX,  XXX,  XXX,  XXX,  XXX, r3c5, r3c6,  XXX,  XXX,  XXX,  XXX,  XXX, r3cc, r3cd}         \
 }

#define KEYMAP_STACKED(                                                                  \
                     r0c2                                                                \
              ,r0c1       ,r0c3 ,r0c4                                                    \
        ,r0c0       ,r1c2                                                                \
  ,r2c0       ,r1c1       ,r1c3 ,r1c4                                                    \
        ,r1c0       ,r2c2                                                                \
              ,r2c1       ,r2c3                                                          \
                                                                                         \
                                 ,r0c6                                                   \
                           ,r1c6       ,r3c6                                             \
                                 ,r2c6                                                   \
                                                                                         \
                          ,r2c5                                                          \
                    ,r3c5        ,r1c5                                                   \
                          ,r0c5                                                          \
                                                                                         \
                                                                                         \
                     ,r0c9                                                               \
         ,r0cb ,r0ca       ,r0c8                                                         \
                     ,r1c9       ,r0c7                                                   \
         ,r1cb ,r1ca       ,r1c8       ,r2c7                                             \
                     ,r2c9       ,r1c7                                                   \
               ,r2ca       ,r2c8                                                         \
                                                                                         \
        ,r0cd                                                                            \
  ,r3cd       ,r1cd                                                                      \
        ,r2cd                                                                            \
                                                                                         \
              ,r2cc                                                                      \
        ,r1cc       ,r3cc                                                                \
              ,r0cc                                                                      \
 )                                                                                       \
 {                                                                                       \
   {r0c0, r0c1, r0c2, r0c3, r0c4, r0c5, r0c6, r0c7, r0c8, r0c9, r0ca, r0cb, r0cc, r0cd}, \
   {r1c0, r1c1, r1c2, r1c3, r1c4, r1c5, r1c6, r1c7, r1c8, r1c9, r1ca, r1cb, r1cc, r1cd}, \
   {r2c0, r2c1, r2c2, r2c3,  XXX, r2c5, r2c6, r2c7, r2c8, r2c9, r2ca,  XXX, r2cc, r2cd}, \
   { XXX,  XXX,  XXX,  XXX,  XXX, r3c5, r3c6,  XXX,  XXX,  XXX,  XXX,  XXX, r3cc, r3cd}  \
 }

}
}
}

#include "kaleidoscope/hardware/key_indexes.h"

extern kaleidoscope::hardware::dygma::Shortcut &Shortcut;

#endif
