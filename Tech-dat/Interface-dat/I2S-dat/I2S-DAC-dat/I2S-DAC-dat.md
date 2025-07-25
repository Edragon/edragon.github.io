
# I2S-DAC-dat

I2S DAC Decoder speaker 

- [[PCM5122-dat]] - [[MPC1083-dat]] 

- [[PCM5102-dat]] - [[AMP1006-dat]] 

- [[MAX98357-dat]] 

- [[UDA1334-dat]] - [[AMP1013-dat]] - [[NXP-dat]]

## Pin 

| Name | default ESP32 | also Name    | func                               | RPI GPIO | RPI pin |
| ---- | ------------- | ------------ | ---------------------------------- | -------- | ------- |
| SCK  | 26            | BCLK         | Serial Data Clock / Bit clock line | G18      | PIN 12  |
| WS   | 25            | LRCK / LRC   | Serial Data-Word select line       | G19      | PIN 35  |
| SD   | 22            | SDIN / SDOUT | At least one multiplexed data line | G21      | PIN 40  |

I2S Circuit:

* Arduino/Genuino Zero, MKR family and Nano 33 IoT
* MAX98357:
  * GND connected GND
  * VIN connected 5V
  * LRC connected to pin 0 (Zero) or 3 (MKR), A2 (Nano) or 25 (ESP32)
  * BCLK connected to pin 1 (Zero) or 2 (MKR), A3 (Nano) or 5 (ESP32)
  * DIN connected to pin 9 (Zero) or A6 (MKR), 4 (Nano) or 26 (ESP32)
 
 DAC Circuit:
 * ESP32 or ESP32-S2
 * Audio amplifier
   - Note:
     - ESP32 has DAC on GPIO pins 25 and 26.
     - ESP32-S2 has DAC on GPIO pins 17 and 18.
  - Connect speaker(s) or headphones.

- [[MAX98357-dat]]