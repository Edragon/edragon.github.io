
# ams-osram-dat


## AS7341 

- datasheet == [[AS7341-DS000504.pdf]]

ams AS7341 – 11-Channel Spectral Color Sensor

AS7341 is an 11-channel multi-spectral sensor for color detection and spectral analysis applications. 

The spectral response is defined in the wavelengths from approximately 350nm to 1000nm. 

6 channels can be processed in parallel by independent ADCs while the other channels are accessible via a multiplexer. 

8 optical channels cover the visible spectrum, one channel can be used to measure near infra-red light and one channel is a photo diode without filter (“clear”). 

The device also integrates a dedicated channel to detect 50Hz or 60Hz ambient light flicker. 

The flicker detection engine can also buffer data for calculating other flicker frequencies externally. 

The NIR channel in combination with the other VIS channel may provide information of surrounding ambient light conditions (light source detection). 

The device can also be synchronized to external signals via pin GPIO.

![](2025-07-13-02-31-41.png)





## TSL2584


ams TSL2584TSV Ambient Light Sensor

The TSL2584TSV is a very high sensitivity light-to-digital converter that transforms light intensity into a digital signal output with a fast mode I²C interface. The device combines one broadband photodiode (visible plus infrared), one infrared-responding photodiode, and a photopic infrared-blocking filter on a single CMOS integrated circuit. 

Two integrating analog-to-digital converters (ADCs) convert the photodiode currents into a digital output that represents the irradiance measured on each channel. This digital output can be input to a microprocessor where illuminance (ambient light level) in lux is derived using an empirical formula to approximate the human eye response. The TSL2584TSV supports a traditional level style interrupt that remains asserted until the firmware clears it.


## ref 

- [[sensor-light-dat]]