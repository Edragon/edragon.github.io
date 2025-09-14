
# PID-dat

- [[betaflight-PID-fliter-dat]]

- [[betaflight-rateprofile-dat]]

## mobula8 

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

| set                                  | value |                                              |
| ------------------------------------ | ----- | -------------------------------------------- |
| Damping: D Gains                     | 1.4   |                                              |
| Tracking: P & I Gains                | 1     |                                              |
| Stick Response: FF Gains             | 1     |                                              |
| Dynamic Damping: D Max               | 0     |                                              |
| Drift - Wobble: /Gains               |       |                                              |
| Pitch Damping: Pitch:Roll D          |       |                                              |
| Pitch Tracking: Pitch:Roll P, I & FF |       |                                              |
| Master Multiplier:                   | 1.6   | Indoor: keep lower to avoid twitchy behavior |



### Throttle and Motor Settings in betaflight

| set                   | value | expalination                                                                            |
| --------------------- | ----- | --------------------------------------------------------------------------------------- |
| Throttle Boost        | 5     | Increases throttle response when you make quick stick movements.                        |
| Motor Output Limit    | 100   | Limits the maximum power sent to the motors (as a percentage).                          |
| Dynamic Idle          | 35    | Sets a minimum motor RPM (as a percentage of throttle) when the throttle is at zero.    |
| Vbat Sag Compensation | 100%  | Compensates for voltage drop (“sag”) as the battery drains.                             |
| Thrust Linearization  | 40%   | Adjusts throttle curve to make thrust output more linear (proportional) to stick input. |



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

### screenshort 

![](2025-09-03-14-41-34.png)


![](2025-09-03-14-45-29.png)



CAUTioN: Current sllder positlons may cause flyaways, motor damage or unsafe craft behaviour. Please proceed with cautlon.

Note: Slider access and range is restricted because you are not in expert mode. Basic mode should be suitable for most builds and beginners.

Note: Slider(s) are disabled because current values are outside the Basic Mode adjustment range. Switch to Expert Mode to make changes



## ref 

- [[PID]] - [[tech]]