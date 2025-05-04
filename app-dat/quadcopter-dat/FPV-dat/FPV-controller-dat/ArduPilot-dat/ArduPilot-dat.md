
# ArduPilot-dat


## Radio Control Systems


- [Radio Control Systems](https://ardupilot.org/rover/docs/common-rc-systems.html)

Compatible RC Protocols

ArduPilot autopilots are compatible with the following receiver output protocols:

PPM-Sum receivers - [[PPM-dat]]

SBus receivers - [[SBUS-dat]]

Fast SBus (from DJI HDL video/RC systems)

i-BUS receivers

FPort Receivers

Spektrum SRXL2,DSM, DSM2, and DSM-X Satellite receivers

Multiplex SRXL version 1 and version 2 receivers

CRSF receivers (including ExpressLRS systems) - [[ELRS-dat]] - [[CRSF-dat]]

mLRS (with telemetry) (MAVLink)

Graupner SUM-D

IRC Ghost

DroneCAN peripherals can decode these RC protocols on a peripheral and pass to the autopilot

MAVLink connected RC (not to be confused with MAVLink RC Overrides used for CS joystick control of RC functions)

Parallel PWM outputs encoded to PPM-Sum using an external encoder (see below, not supported on many autopilots now)


## protocol converter 

![](2025-05-04-16-11-57.png)


## ref 

- [[ardupilot-dat]] - [[FPV]]