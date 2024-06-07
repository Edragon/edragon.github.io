
# STH1074 DAT

https://www.electrodragon.com/product/water-turbidity-sensor/

Sensor default out analog value 0~4.5V
Digital output or amplified output by [[LM358-DAT]]

- [[micropython-dat]]

jumper select: 
- D: LM3528 channel 1 as comprator
  - digital threashold output, LED on
  - tuning on-board trim-pot for the threashold.
- D': LM3528 channel 1 as amplifier
  - you can use arduino analog read data, normal aroun 65x, block at 5-10


## note 

- few boards' LED may not work, but the rest functions work well


## ref 

- [[LM358-DAT]]

- [[STH1074]] - [[LM358]]

- [[water-sensor-dat]]
