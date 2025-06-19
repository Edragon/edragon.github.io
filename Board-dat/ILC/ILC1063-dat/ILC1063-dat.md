
# ILC1063-dat


[light-tuner-controller-sjt83-breakout](https://www.electrodragon.com/product/light-tuner-controller-sjt83-breakout/)



## board map 

![](2025-01-18-13-05-06.png)



## control 

Chip function simply based on mosfet output control, it is a pre-programmed chip.

| pin 1 | pin 8 | pin 6 | function                     |                                                                                         |
| ----- | ----- | ----- | ---------------------------- | --------------------------------------------------------------------------------------- |
| +     | +     | +     | stepless speed control       | Sudden change, single-button single-output stepless dimming without brightness memory   |
| -     | +     | +     | stepless speed control w/mem | Sudden change, single-button single-output stepless dimming with brightness memory      |
| +     | -     | -     | three phase control L-to-H   | LED three-stage dimming, sequence: low brightness-medium brightness-high brightness-OFF |
| -     | -     | -     | three phase control H-to-L   | LED three-stage dimming, sequence: high brightness-medium brightness-low brightness-OFF |



## SCH 

![](2025-01-18-13-11-05.png)

## demo video 

- https://www.youtube.com/watch?v=2B5snq0Ek3s


## SJT83-dat 

### features 

- ● 1 capacitive touch sensing button
- ● Operating voltage: 2.5V～5.5V
- ● Power consumption: VDD=5V without load
- Operating current 700uA, standby current 12uA
- ● Provides two modes: stepless dimming and three-stage dimming
- Provides stepless dimming mode with single-button dual-channel output
- ● With brightness memory function and gradual dimming effect
- ● Automatic adaptation function to changes in ambient temperature and humidity
- ● Super strong anti-radio and anti-EMC interference capabilities

### APP 

Applications:

Touch LED dimming desk lamp, touch LED dimming wall lamp, touch LED flashlight, metal shell touch dimming desk lamp, other

LED dimming lighting or touch products that require PWM output control.


## ref 

- [[SJT83-dat]] 

- [[ILC1063]]

- [[led-driver-dat]]