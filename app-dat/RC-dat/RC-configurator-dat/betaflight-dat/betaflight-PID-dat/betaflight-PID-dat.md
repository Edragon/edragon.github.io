
# PID-dat

- [[betaflight-PID-fliter-dat]]

- [[betaflight-rateprofile-dat]]


## works 

![](2025-09-15-03-20-15.png)

![](2025-09-15-03-21-05.png)

![](2025-09-15-03-21-23.png)

- suspension == spring + damper

![](2025-09-15-03-23-18.png)

## mobula8 for example 

default profile 

| value      | Proportional | Integral | D Max | Derivative | Feedforward |
| ---------- | ------------ | -------- | ----- | ---------- | ----------- |
| Basic/Acro |              |          |       |            |             |
| ROLL       | 53           | 95       | 46    | 43         | 143         |
| PITCH      | 56           | 100      | 52    | 48         | 149         |
| YAW        | 53           | 95       | 00    | 0          | 143         |


tuned profile 

| value      | Proportional | Integral | D Max | Derivative | Feedforward |
| ---------- | ------------ | -------- | ----- | ---------- | ----------- |
| Basic/Acro |              |          |       |            |             |
| ROLL       | 48           | 100      | 41    | 43         | 143         |
| PITCH      | 41           | 105      | 48    | 48         | 149         |
| YAW        | 53           | 95       | 00    | 0          | 143         |


## slider 



| set                                  | value |                                              |
| ------------------------------------ | ----- | -------------------------------------------- |
| Damping: D Gains                     | 1.4   |                                              |
| Tracking: P & I Gains                | 1     |                                              |
| Stick Response: FF Gains             | 0     |                                              |
| Dynamic Damping: D Max               | 0     | starting from 0                              |
| Drift - Wobble: /Gains               | 0     |                                              |
| Pitch Damping: Pitch:Roll D          |       |                                              |
| Pitch Tracking: Pitch:Roll P, I & FF |       |                                              |
| Master Multiplier:                   | 1.6   | Indoor: keep lower to avoid twitchy behavior |

![](2025-09-15-03-31-37.png)

use PIDtoolbox to find the best value

![](2025-09-15-03-32-43.png)


### Master Multiplier

- hear motor sound and feel the response

- Start to gradually increase your Master Slider from ~0.5
- Pay attention to motor temperature, the sound of the motors, and propwash handling




### Throttle and Motor Settings in betaflight

| set                   | value | expalination                                                                            |
| --------------------- | ----- | --------------------------------------------------------------------------------------- |
| Throttle Boost        | 5     | Increases throttle response when you make quick stick movements.                        |
| Motor Output Limit    | 100   | Limits the maximum power sent to the motors (as a percentage).                          |
| Dynamic Idle          | 35    | Sets a minimum motor RPM (as a percentage of throttle) when the throttle is at zero.    |
| Vbat Sag Compensation | 100%  | Compensates for voltage drop (“sag”) as the battery drains.                             |
| Thrust Linearization  | 40%   | Adjusts throttle curve to make thrust output more linear (proportional) to stick input. |


#### dynamic idle

- 2" == 30

![](2025-09-15-03-29-48.png)



### Angle/Horizon

| set         | Strength | Transition |
| ----------- | -------- | ---------- |
| Angle       | 50       |            |
| Horizon     | 75       | 75         |
| Angle Limit | 60       |            |

optimized for indoor fly 

| set         | Strength | Transition |
| ----------- | -------- | ---------- |
| Angle       | 32       |            |
| Horizon     | 50       | 75         |
| Angle Limit | 45       |            |

- angle mode == can not full roll or flip 
- Angle == less respone 
- Angle Limit == less speed and angle, but inability to fly in wind





### slider screenshort 

![](2025-09-03-14-41-34.png)


![](2025-09-03-14-45-29.png)



CAUTioN: Current sllder positlons may cause flyaways, motor damage or unsafe craft behaviour. Please proceed with cautlon.

Note: Slider access and range is restricted because you are not in expert mode. Basic mode should be suitable for most builds and beginners.

Note: Slider(s) are disabled because current values are outside the Basic Mode adjustment range. Switch to Expert Mode to make changes


## PID controller settings 

- Feedforward transition
- Acro Trainer Angle Limit
- Throttle Boost
- Dynamic Idle Value [* 100 RPM]
- Absolute Control
- I Term Rotation
- Vbat PID Compensation
- Integrated Yaw
- I Term Relax
  - RP - Axes
  - Setpoint - Type
  - 5 - Cutoff - [[indoor-fly-dat]]

A feature that reduces (relaxes) the effect of the I-term (integral) in the PID controller during fast stick movements, helping to avoid overshoot and improve flight feel.

- D Min
- Anti Gravity
  - [x] Permanently enable Anti Gravity
  - [x] Smooth [x] support - Mode
  - 10 - Gain - [[indoor-fly-dat]]

A feature that temporarily boosts the I-term (integral) of the PID controller during rapid throttle changes to help maintain stable flight and prevent sudden altitude drops or surges.

## ref 

- [[PID]] - [[tech]]

- [damping tuning on meteor75](https://www.youtube.com/watch?v=CsD5sV7xOPc)

- [Betaflight 4.5 PID Tuning](https://www.youtube.com/watch?v=1oYoVE4xu1U)