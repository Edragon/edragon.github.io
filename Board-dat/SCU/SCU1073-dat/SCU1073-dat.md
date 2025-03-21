# SCU1073-dat

## Features

- level safety protection

## Danger!

The water level monitoring feet are not resistant to high pressure and there is no risk when placed in the water normally.
Do not directly contact the water level monitoring pin with high-voltage circuit parts such as the atomizer sheet.

## Pin definitions

Vws = Withstand voltage value (V)

| Pin No. | Pin name | Vws | Function description               |
| ------- | -------- | --- | ---------------------------------- |
| 1       | R        | -   | Oscillating resistance (note1)     |
| 2       | R        | -   | Supply voltage monitoring resistor |
| 3       | GND      | -   | Power ground                       |
| 4       | GND      | -   | Power ground                       |
| 5       | VIN      | -   | Input                              |
| 6       | LED      | -   | indicator light                    |
| 7       | VDD      | 5   | power supply                       |
| 8       | N/F      | 5   | Water level monitoring (note2)     |

- note1 = main source of deviation, resistor accuracy is 1%
- note2 = be careful not to come into contact with high-pressure parts

## Design Note

- Note: The resistor in series between pin 1 and pin 2 can be used for frequency adjustment. Since the layout of the PCB may cause overall frequency deviation, the frequency can be modified to the operating frequency of 108KHz by modifying its resistance value.
- Since the chip operating frequency requires high precision, the stability and consistency of the input voltage must be ensured.
- Changes in the power supply voltage will cause changes in the chip's operating frequency, thereby affecting the working effect of the atomizer.
- The frequency error of the chip mainly comes from the oscillation resistor, so try to use a resistor with a precision of 1% to reduce the frequency deviation.
- And when laying out the board, the oscillation resistors should be laid out strictly according to the anti-interference drawing method. The resistors should be placed as close to the pins of the chip as possible to reduce the resistance brought by the PCB board and the frequency changes caused by environmental interference.

## ref

- [[SCU1073]]
