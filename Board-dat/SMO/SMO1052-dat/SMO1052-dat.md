# SMO1052-dat

## Info

[product url - Vibration Shake Sensing Module, LM393 SW18020P](https://www.electrodragon.com/product/vibration-sensor-sw-18010p/)



This module uses a normally-open, high-sensitivity vibration switch (SW-18010P). At rest the switch is open (OFF). When subject to an impact or sufficient acceleration/centrifugal force, the internal contact momentarily closes (ON); when the force is removed the switch returns to the open (OFF) state.

Typical uses: vibration-triggered alarms, smart vehicles, educational electronic blocks, and general vibration sensing. The sensor board includes an M3 mounting hole for easy fixing and orientation. It uses an LM393 comparator for a clean, conditioned signal with good drive capability (over 15 mA). Sensitivity is adjustable via the on-board precision potentiometer.

Schematic

![](2026-02-11-00-14-11.png)

Operation and behavior

- When the product is not vibrating the vibration switch is open; the module output is HIGH and the green indicator LED is off.
- When vibration occurs, the switch momentarily closes and the output goes LOW; the green indicator LED turns on.
- The output can be connected directly to a microcontroller input. The MCU can monitor the pin state to detect vibration and trigger alarms or other logic.

Quick test procedure

1. Connect VCC and GND (observe correct polarity). The power LED should light.
2. Place the module on a flat surface. Rotate the blue potentiometer until the switch indicator LED lights, then slightly turn the pot back so the LED is off.
3. Tap the surface to produce vibration — the switch indicator LED should light while vibration is detected and turn off when vibration stops.

This demonstrates that vibration triggers the module and lights the indicator.

Caution

- Wire the module correctly — do not reverse VCC and GND, as this can damage components.
- The trigger pulses produced by the sensor on small vibrations are very short and usually cannot directly drive a relay. Although some sources claim direct relay connection works, practical results are often unreliable. Use a driver or latch circuit if you need to switch higher currents or drive a relay.

### Board Map, Dimension, Pins, chip info, Use Guide, Setup Jumper, etc.



## Applications, category, tags, etc. 

## Demo Code and Video

## ref 

[Documentation: Reference schematic please refer to this post.](http://blog.electrodragon.com/analog-and-digital-sense-of-sensors-lm393-the-voltage-comparator/)

- [[SMO1052]] 

- legacy wiki page



