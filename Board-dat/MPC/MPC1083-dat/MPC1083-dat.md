
# MPC1083-dat 

- legacy documentation - https://www.electrodragon.com/w/Sound_Card#Use_PCM5102_or_ES9023_w.2FRPI


## Hardware 

### Config Mode 

| Mod1 | Mod2 | Mode           |
| ---- | ---- | -------------- |
| GND  | VCC  | I2C  (default) |
| VCC  | any  | SPI            |
| GND  | GND  | Hardware       |

I2C Address = 0x4D 



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

### mode and address select

MOD1 - GND, MOD2 - VCC = I2C
MOD1 - VCC, MOD2 - any   = SPI
MOD1 - GND, MOD2 - GND = Hardware

| mod1 | add2 | add1 | mod2 | note          |
| ---- | ---- | ---- | ---- | ------------- |
| GND  | GND  | VCC  | VCC  | I2C address = |


## Software 

- Volumio - [[volumio-dat]]
- MoOde
- LibreELEC
- Max2play
- Raspbian - [[RPI-OS-dat]] - [[PCM5122-RPI-dat]]
- OSMC

### aplay test 

aplay -l

    pi@raspberrypi:~ $ aplay -l
    **** List of PLAYBACK Hardware Devices ****
    xcb_connection_has_error() returned true
    card 0: vc4hdmi [vc4-hdmi], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
    Subdevices: 1/1
    Subdevice #0: subdevice #0
    card 1: Headphones [bcm2835 Headphones], device 0: bcm2835 Headphones [bcm2835 Headphones]
    Subdevices: 8/8
    Subdevice #0: subdevice #0
    Subdevice #1: subdevice #1
    Subdevice #2: subdevice #2
    Subdevice #3: subdevice #3
    Subdevice #4: subdevice #4
    Subdevice #5: subdevice #5
    Subdevice #6: subdevice #6
    Subdevice #7: subdevice #7
    card 2: BossDAC [BossDAC], device 0: Boss DAC HiFi pcm512x-hifi-0 [Boss DAC HiFi pcm512x-hifi-0]
    Subdevices: 1/1
    Subdevice #0: subdevice #0

download a test mp3 here. [[test.mp3]]


## demo video 

- x  - https://x.com/electro_phoenix/status/1871071433797046460
- yt - https://www.youtube.com/shorts/psUuKwltYpI
- tg - https://t.me/electrodragon4/305

## ref 

- [[PCM5122-dat]] - [[TI-dat]] - [[RPI-OS-dat]] - [[PCM5122-RPI-dat]]

- [[I2S-dat]] - [[I2C-dat]] - [[infrared-dat]] - [[eeprom-dat]] - [[memory-dat]]

- [[MPC1111-dat]]

- [[MPC1083]]