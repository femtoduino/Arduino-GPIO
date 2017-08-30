/**
 * @file Board.h
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2017, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 */

#ifndef BOARD_H
#define BOARD_H

/**
 * Board pin values are constructed from port control register
 * address (msb, bit 15..4) and pin bit position in control register
 * (lsb, bit 3..0). This allows the pin values to be written
 * directly in hexadecimal format.
 */
#if defined(ARDUINO_AVR_UNO)						\
 || defined(ARDUINO_AVR_DUEMILANOVE)					\
 || defined(ARDUINO_AVR_NANO)						\
 || defined(ARDUINO_AVR_MINI)						\
 || defined(ARDUINO_AVR_ETHERNET)					\
 || defined(ARDUINO_AVR_FIO)						\
 || defined(ARDUINO_AVR_BT)						\
 || defined(ARDUINO_AVR_LILYPAD)					\
 || defined(ARDUINO_AVR_PRO)						\
 || defined(ARDUINO_AVR_UNO_WIFI_DEV_ED)
namespace BOARD {
  enum pin_t {
    D0 = 0x290,
    D1 = 0x291,
    D2 = 0x292,
    D3 = 0x293,
    D4 = 0x294,
    D5 = 0x295,
    D6 = 0x296,
    D7 = 0x297,
    D8 = 0x230,
    D9 = 0x231,
    D10 = 0x232,
    D11 = 0x233,
    D12 = 0x234,
    D13 = 0x235,
    D14 = 0x260,
    D15 = 0x261,
    D16 = 0x262,
    D17 = 0x263,
    D18 = 0x264,
    D19 = 0x265,
    D20 = 0x266,
    D21 = 0x267
  };
};
#else
#error Board.h: board not supported
#endif
#endif