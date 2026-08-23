
# rc-aircraft-dat


- basic - [[RC-kits-dat]] - [[landing-gear-dat]]

- [[quadcopter-dat]] - [[mobula8-dat]] - [[UAV-dat]] - [[DJI-quadcopter-dat]]

- [[radiomaster-dat]]




## 6in 

- [[DJI-flip-dat]]



## mode 

- 定高 Althold
- 悬停 Hover
- 返航 Return
- 降落 Land
- 绕卷 Circle
- 无头 Headless
- 自稳 Stabilization
- 有头 Head
- 失控返航 Out of control return
- 低电降落 Low power down





## types 

- 遥控扑翼机 Ornithopter [[Ornithopter-dat]]

- [[fixed-wing-dat]] - [[glider-dat]] - [[Aircraft-powered-hand-launched-dat]]

- [[helicopter-dat]]

- [[FPV-dat]] - [[FPV-size-dat]] 

- [[DJI-dat]] - [[DJI-flip-dat]]

- [[VTOL-dat]]

| 类型 | 推重比 | 续航 | 悬停能力 | 特点 |
| --- | --- | --- | --- | --- |
| 多旋翼（7寸） | 2-3:1 | 20 分钟 | ✅ 悬停 | 灵活易操作，续航短 |
| 固定翼（FPV） | 0.5:1 | 40-90 分钟 | ❌ 不能悬停（必须一直飞） | 续航长，需持续飞行 |
| 垂直起降固定翼 (VTOL) | 0.6:1 + 旋翼组 | 40-60 分钟 | ✅ 悬停+巡航 | 起飞悬停、巡航省电 |

> VTOL（垂直起降固定翼）：起飞用旋翼（悬停），巡航切固定翼模式（机翼升力省电）——这是航拍续航的最优解，也是 DJI 未来的方向。



## control channels channels 

### Channel 1: Aileron Action

Control theright-and-left lean of the aircraft.To level the slantwise aircraft,youmust make
thecontrol rod act inreverse direction.Otherwise,it will makethe aircraftoverturn.

### Channel 2: Elevator Action

Control the aerocraft to descend orascend.Pulling the control rod down will driveup the head,
and the aeroplane will ascend.Boosting it upwill make thehead downhill,and the aeroplane
willdescend.

### Channel 3: Throttle Operation

Control the power. Pulling the control rod down will minish down the power group, and boosting
the control rod up will increase thepower group.

### Channel 4: Rudder Action

Control the swerve of the aerocraft. Turning the control rod to left will make the head of the
aircraft turn left, and turning it to right will make the head turn right.

### Channel 5: LandingGear/GyroAction

This channel is for switch variable. It is a switch to control landing gear when used for airplane
state, but it will be a switch for gyroscope when used for helicopter.

### Channel 6: Screw-pitch/Flaperon Action

The angle adjustingof the flaperon isfor the airplane state,and the adjustingof themain
screw-pitch is forhelicopter state.




## concept 

### Differential-Thrust Aircraft (Differential Control)

“Differential” aircraft use the thrust difference between left and right propulsion units (usually motor + propeller) to control direction. This control method is called differential thrust.

#### What is a differential-thrust aircraft?
A differential-thrust aircraft does not rely on a conventional rudder to turn. Instead, it produces a yaw moment by creating a thrust difference between the left and right motors/propellers.

#### How it works
- Left thrust > Right thrust → aircraft yaws right  
- Right thrust > Left thrust → aircraft yaws left  
- Left thrust = Right thrust → aircraft flies straight

This is similar to the steering method used by twin-motor RC boats or differential-drive


## tech and concept 

- [[aerodynamic-dat]] - [[power-physics-dat]] - [[motion-dat]] - [[network-dat]] - [[physics-dat]]

- [[Center-of-Gravity-dat]] - [[Thrust-dat]] 



## ref 

- [[RC-dat]] - [[airplane]] - [[RC]]