
# UDA1334-dat

Low power audio DAC with PLL

https://www.nxp.com/docs/en/data-sheet/UDA1334ATS.pdf

| UDA1334A board pin | Pyboard V1.1 pin | Pyboard D pin | ESP32 pin | Pico Pin | Teensy 4.1 pin |
|--------------------|------------------|---------------|-----------|----------|-----------------|
| 3V0                | 3V3              | 3V3           | 3V3       | 3V3      | 3.3V            |
| GND                | GND              | GND           | GND       | GND      | GND             |
| BCLK               | Y6               | Y6            | 32        | 16       | 4               |
| WSEL               | Y5               | Y5            | 25        | 17       | 3               |
| DIN                | Y8               | Y8            | 33        | 18       | 2               |


## ref 

https://github.com/miketeachman/micropython-i2s-examples