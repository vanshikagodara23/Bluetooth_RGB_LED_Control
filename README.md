# Bluetooth RGB LED Control

Control an RGB LED from a phone using an HC-05 Bluetooth module and an Arduino. Send a single letter from any Bluetooth serial terminal app to change the colour.

## Commands

| Send | Colour |
|---|---|
| `R` | Red |
| `G` | Green |
| `B` | Blue |
| `Y` | Yellow |
| `W` | White |
| `C` | Cyan |
| `M` | Magenta |
| `P` | Pink |
| `A` | Orange |
| `V` | Violet |
| `L` | Lime |
| `T` | Turquoise |
| `S` | Sky Blue |
| `F` | Rainbow effect |
| `O` | LED off |

Lowercase letters work too.

## Components

- Arduino Uno (or compatible)
- HC-05 Bluetooth module
- RGB LED (common cathode) + 3 resistors (220 Ω)
- Jumper wires, breadboard

## Wiring

| Part | Pin | Arduino pin |
|---|---|---|
| HC-05 | TX | 10 (Arduino RX) |
| HC-05 | RX | 11 (Arduino TX) |
| HC-05 | VCC / GND | 5V / GND |
| RGB LED | Red | 3 |
| RGB LED | Green | 5 |
| RGB LED | Blue | 6 |

Tip: use a voltage divider on the HC-05 RX pin, because it works at 3.3V logic.

## How to run

1. Open `Bluetooth_RGB_LED_Control.ino` in the Arduino IDE and upload it.
2. Pair your phone with the HC-05 (default PIN `1234` or `0000`).
3. Open a Bluetooth serial terminal app, connect to the HC-05 and send the letters above.
