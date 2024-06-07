
# STH1049-dat

https://www.electrodragon.com/product/water-drop-rain-sensor/




## usage 

Usage
- Connected to 5V power supply power lights,
    - When no water droplets, DO output is high and the switch indicator lights off,
    - dropping on a drop of water, DO output is low, the switch indicator lights on,
- Brush off the the above water droplets, has returned to output to high state.
- AO analog output can be connected to the MCU AD port to detect the size of the drops in the above rainfall.
- DO TTL digital outputs can also be connected to the MCU detects whether there is rain.
- 开关指示 = Switch Indicator
- 电源指示 = Power Indicator

## change log 

- Version V1.1 
- Change the power LDO, may have better stability, move the antenna connectors to the top to fit into case desgin.
- Version V1.2 
- Add extra logic leveled UART pins 5V and 3v3 for arduino or raspberry pi such devices. 



## ref 
- schematic refer to [[LM393-dat]]