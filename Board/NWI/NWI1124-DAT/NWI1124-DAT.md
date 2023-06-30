

# NWI1124 DAT




## Pin Definitions 

#### Setup Explantion V2
![](02-30-17-13-03-2023.png)

![](16-30-17-13-03-2023.png)


### Output Signal Setup 


![](06-58-16-27-02-2023.png)

based on above image, top pin 1 to bottom pin 5: 

#### Set both **RED** box jumpers for WS2812 output

- pin 4 to IO2 for WS2812 data
- pin 3 to GND
- Output pins from top to bottom (blue marked box pin 3-5)
  - WS2812_GND
  - WS2812_DAT (5V Logic)
  - WS2812_VCC (can be set to 5V or VIN)

#### Set both **GREEN** box jumpers for WRGB output

  - pin 4 to Green channel of RGBW
  - pin 3 to Red   channel of RGBW
  - you will get white box setup (from pin1 to pin5) from top to bottom
  - White / Blue / Red / Green / Voltage Supply

### Power Supply Setup 

![](01-04-17-27-02-2023.png)

Green Box: 

- Set the input power supply for board. 
- choose 5V if input power is 5V, bypass the on board DC/DC converter
- Choose ~27V if input power is higher than 5V

Red Box: 

- Set to up to ~27V for RGBW LED Strips
- Set to 5V for WS2812 LED Strips



## Accessories 
- Reserved pins for our RF-LINK EDRF2 module here. (one channel trigger IO0 Low)
- https://www.electrodragon.com/product/rf-switch-receiver-433315mhz-wdecoder/

## Demos 
- https://www.youtube.com/watch?v=_kBS72xQPqQ


## ref 
- [[nwi1124]]
- old wiki link: https://www.electrodragon.com/w/ESP_Light

- [[NWI1124-DAT]] - [[NWI1125-DAT]] - [[NWI1126-DAT]]