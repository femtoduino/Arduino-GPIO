/**
 * @file Button.h
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

#ifndef BUTTON_H
#define BUTTON_H

#include "GPIO.h"

/**
 * Debounced input pin template class using GPIO. Internal pullup
 * resistor is used. The button/switch should be connected to ground.
 * @param[in] PIN board pin for input signal.
 */
template<BOARD::pin_t PIN>
class Button {
public:
  /**
   * Construct debounced input pin (Button) instance with given
   * template parameters. Initiate GPIO pins input mode with pullup
   * resistor.
   * @param[in] ms debouce time (Default 50 ms).
   */
  Button(uint16_t ms = 50) :
    DEBOUNCE(ms),
    m_timestamp(0),
    m_state(true)
  {
    m_pin.input().pullup();
  }

  /**
   * Return true(1) if button change was detected, otherwise false(0).
   * Rising or falling edge is determined by reading the debounced pin
   * state.
   * @return true(1) if button change was detected, otherwise false(0).
   */
  bool ischanged()
  {
    // Check debounce time has elapsed
    if (millis() - m_timestamp < DEBOUNCE) return (false);
    m_timestamp = millis();

    // Check for pin state change
    bool state = m_pin;
    if (state == m_state) return (false);
    m_state = state;
    return (true);
  }

  /**
   * Return debounced pin state.
   * @return state.
   */
  bool read()
  {
    return (m_state);
  }

  /**
   * Return debounced pin state. Shorthand for read().
   * @return bool.
   */
  operator bool()
    __attribute__((always_inline))
  {
    return (read());
  }

  /**
   * Return debounce timestamp.
   * @return timestamp.
   */
  uint16_t timestamp()
  {
    return (m_timestamp);
  }

  /** Debounce time in milli-seconds. */
  const uint16_t DEBOUNCE;

protected:
  /** Button pin. */
  GPIO<PIN> m_pin;

  /** Timestamp for latest pin read. */
  uint16_t m_timestamp;

  /** Latest pin read. */
  bool m_state;
};

#endif
