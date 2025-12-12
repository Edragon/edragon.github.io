
# STH1054-dat 

- MQ-3 Alcohol Ethanol Gas Sensor Detector Module

- [legacy wiki page](https://w.electrodragon.com/w/MQ_series)
- [product link](https://www.electrodragon.com/product/mq-3-alcohol-ethanol-gas-sensor-module/)


## Application 

It is used for on-site detection of motor vehicle drivers and other people who are strictly prohibited from operating under the influence of alcohol. It is also used for the detection of ethanol vapor in other places.

## Features : 

Specs: 
1. Size: 32mm X22mm X27mm length X width X height
2. Main chips: LM393, ZYMQ-3 gas sensor
3. Working voltage: DC 5 volts

Features:
1. With signal output indication.
2. Dual signal output (analog output and TTL level output)
3. The TTL output valid signal is low level. (The signal light lights up when the output is low, and can be directly connected to the microcontroller)
4. The analog output voltage is 0~5V. The higher the concentration, the higher the voltage.
5. It has high sensitivity and good selectivity to ethanol vapor.
6. Has long service life and reliable stability
7. Fast response recovery characteristics

## Instructions for use
- MQ-2 sensor module is most sensitive to environmental alcohol gas.
- When the module in the alcohol-free gas impact or alcohol gas concentration does not exceed the threshold value, the digital interface DO port outputs a high level, the analog interfaces A0 basic voltage is 0V. When the alcohol gas exceeds the threshold value is set, the module digital interface D0 Output low, the analog interface A0 output voltage as the influence of the gas is slowly increased;
- The small board digital output D0 can be connected directly with the MCU, which detect high or low TTL,  by doing this, environmental alcohol gas can be detected;
- Small board digital output DO can directly drive our relay module, in this way, this can be composed of an alcohol gas switch;
- Small board digital output DO can directly drive our active buzzer module, this can be can be composed of an alcohol gas alarm;
- Small board analog output AO connected to the AD module from store, through the AD converter, you can get the precise value of the environment alcohol gas concentration;
- Note: MQ3 sensor housing in dark blue or orange clor, we send color in randomly.

## ref 

- [[STH1054-dat]] - [[sensor-gas-dat]]
- datasheet [[File_MQ-3.pdf]]


- [[STH1054]]
