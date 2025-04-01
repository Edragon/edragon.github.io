# NRF24L01-dat

https://w.electrodragon.com/w/Category:NRF24#NRF24L01_with_STC_C51_MCU

## Feature of NRF24L01:

- 2.4Ghz worldwide free open ISM band
- High working speed up to 2Mbps, high efficient GFSK modulation, can transfer audio or video.
- 125 channels for multiple communication or jumping channels communication.
- Embedded CRC error-check and point to mutiple point communication control
- operation voltage at 3.0-3.6V (3V3)
- External 2.4Ghz antenna, compact size 18mm * 30mm
- Module can set address by software, only output data when device receive right address, can directly connect to any MCU, and easy to programmer.
- 2.54 pins space, compatible with normal module interface, easy to replace.
- 51, AVR reference code is available, simply copy and modify
- Transfer distance can reach 1000 meters @ 250 Kbps (normally can reach 0.8KM)

## Variations

*   **NRF24L01:** The original, basic version.
*   **NRF24L01+ (Plus):** Improved version with lower current consumption and better sensitivity.
*   **NRF24L01-TW / NRF24L01B:**  Appears to be the same as NRF24L01, but with +7dBm transmit power.
*   **Long Range Versions (+20dBm):** Offers significantly extended range due to the higher transmit power. Example: [[NWL1050-dat]].

## boards 

[[arduino-dat]] integrated 
- [[DVA1002-dat]]

Genuine Chip
- [[NWL1053-dat]]

Long range version == +20 DBm 
- [[NWL1050-dat]]
  
NRF24L01-TW version == NRF24L01B == Power at +7Db
- [[NWL1032-dat]] 

cost-effective cheap version == 24L01
- [[NWL1010-dat]] 

- [[RF-dat]]


## SCH 

with STM32 

![](2024-01-13-17-39-29.png)

with arduino 

![](2024-09-05-17-24-52.png)

## demo code 

- http://electrodragon.com/?p=1134

## ref 

- [legacy wiki page](https://w.electrodragon.com/w/Category:NRF24)

[[A7105-dat]]: - [[NWL1058-dat]]