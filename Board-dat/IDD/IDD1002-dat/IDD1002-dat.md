# IDD1002-dat

- legacy wiki page - https://w.electrodragon.com/w/Category:LED_Drive


## Board Layout 
![](2024-04-08-16-54-17.png)

## CC Current calculation 

| output       | R1   | R2   | R3    | R4  | output current |
| ------------ | ---- | ---- | ----- | --- | -------------- |
| 0.142241 ohm | 0.5R | 0.5R | 0.33R | nc  | 700 mA         |

- [[circuit-resistor-dat]]


## Breakout board support up to

- [1W, 10W, 30W high power LEDs in our store](https://www.electrodragon.com/product/high-power-full-white-led-variable100w30w50w20w/)
- also can shortly or not [fully power 50W or 100W LEDs](https://www.electrodragon.com/product/high-power-full-white-led-variable100w30w50w20w/). 33V for 100W LEDs can work but not recommdedded for long term.
- [Tested 5 Meters LED white strips.](https://www.electrodragon.com/product/super-light-led-light-strips/)
- Pin Definition:
  - IN +: Positive power supply IN-: Power supply negative.
  - LED +: Connect the LED’s anode LED-:  Connect the LED’s cathode
  - PWM: Light Strengh control: dimming control signal (2.8V-6V turn on)
- PWM signal limit frequency: 20HZ-20KHZ, recommendations: 1KHZ or so
- Each purchase is for 2 pieces boards.


- [[led-driver-dat]]

- read more information on this page [[PT4115-dat]]


## ref 

- [[IDD1002]]