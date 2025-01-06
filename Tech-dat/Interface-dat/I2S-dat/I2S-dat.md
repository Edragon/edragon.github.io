
# I2S-dat 

An I2S (Interactive Two-Way Serial) interface is a type of serial communication protocol used for transferring data between devices. 

It is commonly used in computer networking, as well as in audio processing and digital electronics. 

I2S interfaces typically use a combination of fast and slow data transfer rates to make efficient use of communication bandwidth and minimize noise and errors. 

One of the key features of I2S interfaces is their ability to support full-duplex communication, which allows for the simultaneous transfer of data in both directions. 

This makes I2S a popular choice for high-speed data transfer applications.

## Pin 

| Name | default ESP32 | also Name    | func                               | RPI GPIO | RPI pin |
| ---- | ------------- | ------------ | ---------------------------------- | -------- | ------- |
| SCK  | 26            | BCLK         | Serial Data Clock / Bit clock line | G18      | PIN 12  |
| WS   | 25            | LRCK / LRC   | Serial Data-Word select line       | G19      | PIN 35  |
| SD   | 22            | SDIN / SDOUT | At least one multiplexed data line | G21      | PIN 40  |

I2S Circuit:

* Arduino/Genuino Zero, MKR family and Nano 33 IoT
* MAX08357:
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

## Common Microphone, Speaker Wiring 

![](2025-01-06-14-07-17.png)

soundrecorder - https://github.com/Edragon/esp32_SoundRecorder


![](2025-01-06-14-07-43.png)

music_player - https://github.com/Edragon/esp32_MusicPlayer



## Solution - control (slave module)

I2S Output Digital Microphone - [[INMP441-dat]] - [[ICS-43434-dat]] - [[SPH0645-dat]] - [[MSM261S4030H0R-dat]]

audio amplifer - [[MAX98357-dat]] - [[audio-dat]] - [[amplifier-dat]]

- [[PCM5122-dat]] - [[MPC1083-dat]] - [[I2S-dat]] - [[PCM5102-dat]] - [[AMP1006-dat]] - [[CS4344-dat]]

- [[ES9023-dat]] - [[MPC1111-dat]] - [[ES9018-dat]]
  
- [[WM8960-dat]] - [[WM8978-dat]]

- [[UDA1334-dat]] - [[AMP1013-dat]]

- [[bt-audio-dat]] - [[ESP32-DAC-dat]] - [[ADC-dat]] - [[DAC-dat]]

- [[PCM1808-dat]]

- [[software-i2s-dat]]


## Solution - control (master module)



## ref 

https://en.wikipedia.org/wiki/I%C2%B2S


- [[I2S]]

