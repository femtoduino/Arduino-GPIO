# Arduino-GPIO
The Arduino GPIO library has been developed to allow high performance
digital pin access. Most access functions are compiled to a single
instruction and execute in 1-2 clock cycles. The library functions are
more than 10 times faster than the Arduino digital pin functions. In
some cases as much as 100 times faster.

Additional support classes are available for Debounced Button, Shift
Register Input/Output, and Software Serial. These also demonstrate how
the GPIO template class may be used to construct additional libraries.

This library supports boards based on SAM3X8E, ATmega168, ATmega328P,
ATmega32U4, ATmega1280, ATmega2560, ATtinyX4 and ATtinyX5.

Version: 1.10

## Classes

* [AVR Board Configuration, BOARD](./src/Hardware/AVR/Board.h)
* [AVR General Purpose Input/Output, GPIO](./src/Hardware/AVR/GPIO.h)
* [SAM Board Configuration, BOARD](./src/Hardware/SAM/Board.h)
* [SAM General Purpose Input/Output, GPIO](./src/Hardware/SAM/GPIO.h)
* [Debounced Input Pin, Button](./src/Button.h)
* [Shift Register Parallel Input, SRPI](./src/SRPI.h)
* [Shift Register Parallel Input/Output, SRPIO](./src/SRPIO.h)
* [Shift Register Parallel Output, SRPO](./src/SRPO.h)
* [Software Serial, Software::Serial](./src/Software/Serial.h)

## Example Sketches

* [Benchmark](./examples/Benchmark)
* [Blink](./examples/Blink)
* [Button](./examples/Button)
* [Pulse](./examples/Pulse)
* [ShiftIn](./examples/ShiftIn)
* [ShiftInOut](./examples/ShiftInOut)
* [ShiftOut](./examples/ShiftOut)
* [SoftwareSerial](./examples/SoftwareSerial)

## Benchmarks

Wiring | us | GPIO | us | Xn (Uno/Mega)
------ |---------------|------|----|--------------
digitalRead | 3.75/6.19 | var = pin | 0.0625 | 60/99
digitalWrite | 4.25/6.94 | pin = val | 0.125 | 34/56
shiftIn | 85/147 | srpi >> var | 5 | 17/29
shiftOut | 103/160 | srpo << val | 8 | 13/20

## Usage

* [1-Wire Bus Manager and Device Driver Support](https://github.com/mikaelpatel/Arduino-OWI)
* [Digital Humidity and Temperature Sensors](https://github.com/mikaelpatel/Arduino-DHT)
* [I2C Bus Manager and Device Driver Support](https://github.com/mikaelpatel/Arduino-TWI)
* [Real-Time Clock Interface](https://github.com/mikaelpatel/Arduino-RTC)
* [Serial Peripheral Interface Bus Manager and Device Driver Support, SPI](https://github.com/mikaelpatel/Arduino-SPI)
* [External Memory Storage](https://github.com/mikaelpatel/Arduino-Storage)