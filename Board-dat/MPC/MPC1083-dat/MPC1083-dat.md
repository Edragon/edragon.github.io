
# MPC1083-dat 

- legacy documentation - https://www.electrodragon.com/w/Sound_Card#Use_PCM5102_or_ES9023_w.2FRPI


## Hardware 

### Config Mode 

| Mod1 | Mod2  | Mode           |
| ---- | ----- | -------------- |
| GND  | VCC   | I2C  (default) |
| VCC  | *any* | SPI            |
| GND  | GND   | Hardware       |

I2C Address 

ADR1 = pull-up, ADR2 = pull-down 


| PIN                     | Symbol            | V2  | Description                                                                                                                     |
| ----------------------- | ----------------- | --- | ------------------------------------------------------------------------------------------------------------------------------- |
| 2,4                     | +5V               |     | +5V Supply Pin,connected to the main 5V supplyoftheRaspberry Pi                                                                 |
| 3                       | SDA1              |     | SDA Used for DAC and EEPROM                                                                                                     |
| 5                       | SCL1              |     | SCL Used for DAC and EEPROM                                                                                                     |
| 12                      | GPIO_18           | 18  | IIS_BCLK                                                                                                                        |
| 31                      | GPIO_6            | NC  | Mute function control pin                                                                                                       |
| 35                      | GPIO_19           | 19  | IIS_LRCLK                                                                                                                       |
| 37                      | GPIO_26           | 17  | Infrared receiver reserved port                                                                                                 |
| 40                      | GPIO_21           | 21  | IIS_DOUT                                                                                                                        |
| 27,28                   | ID SCL and ID SDA |     | Reserved for an ID EEPROM on the Raspberry Pi.Thesepinsare always reserved and should never be usedtoconnectexternal components |
| 6,9,14,20,25,30,34,3, 9 | GND               |     | Ground Pin, connected to the main system GroundoftheRaspberry Pi                                                                |


* The remaining pins are unused, You can use them for your other hardware boards.

## Software 

- Volumio - [[volumio-dat]]
- MoOde
- LibreELEC
- Max2play
- Raspbian - [[RPI-OS-dat]]
- OSMC

## ref 

- [[PCM5122-dat]] - [[TI-dat]]

- [[I2S-dat]] - [[I2C-dat]] - [[infrared-dat]] - [[eeprom-dat]] - [[memory-dat]]

- [[PCM1083]]