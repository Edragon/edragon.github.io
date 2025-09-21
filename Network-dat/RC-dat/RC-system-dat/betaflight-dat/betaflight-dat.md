
# betaflight-dat

- [[FPV-dat]] - [[mobula8-dat]]

- [[radiomaster-dat]] - [[rc-controller-dat]]



- [[betaflight-presents-dat]]  - [[betaflight-configuration-dat]] 

- [[betaflight-receiver-dat]] - [[betaflight-modes-dat]] - [[betaflight-motors-dat]] - [[betaflight-modes-dat]]

- [[betaflight-OSD-dat]] - [[betaflight-video-transmitter-dat]] - [[betaflight-blackbox-dat]]

- [[betaflight-PID-dat]] - [[betaflight-rateprofile-dat]] - [[indoor-fly-dat]]



## betaflight supports 

| model                   | supported | from               |
| ----------------------- | --------- | ------------------ |
| [[Mobula8-dat]] / 7 / 6 | yes       | [[happymodel-dat]] |
| [[aquila16-dat]]        | no        | [[betaFPV-dat]]    |
| [[Meteor65-Pro-dat]]    | yes       | [[betaFPV-dat]]    |




## betaflight features 

- RC smoothing - [[indoor-fly-dat]]
- crash recovery - [[betaflight-configuration-dat]]

## betaflight HDK features 

- [[GPS-dat]] 

- [[optic-flow-dat]] sensor 




## CLI 

    # version
    # Betaflight / STM32F411 (S411) 4.4.2 Jun  1 2023 / 02:20:34 (23d066d08) MSP API: 1.45

    # config: YES
    # board: manufacturer_id: HAMO, board_name: CRAZYBEEF4SX1280


board == CRAZY BEE F4SX1280


## flash 

- CRAZYBEEF4SX1280 - [[CRAZYBEEF4SX1280-dat]]
- 4.5.2 [19-Mar-2025]

- Radio Protocol == CRSF
- Other Options ==  xAcro Trainer / xGPS / xLED Strip / xOSD (Analog) / xOSD (Digital) / xPin 10 / xVTX
- Telemetry Protocol == Automatically Included
- Motor Protocol == DSHOT

## SETUP 

- THE MOST IMPORTANT STEP: CALIBRATE ACCELEROMETER
- **NO NOT CALIBRATE ON A TABLE**, PUT THE WHOOP ON THE FLOOR, MAKE SURE IT IS LEVEL
- AFTER CALIBRATION, TURN ON MOTORS OR HOLD BY FINGERS, RECHECK
- IF NEEDED, REPEAT CALIBRATION PROCESS UNTIL SATISFIED


## ports 


## failsafe 

- console - failsafe mode - no pulse 

## PID 

- keep all factory default 



### after reset 

The following problems with your configuration were detected:

o there Is no motor output protocol selected.

- Please select a motor output protocol appropriate for your ESCs in 'EsC/Motor Features' on the 'Motors' tab.
- Caution: Selecting a motor output protocol that is not supported by your ESCs can lead to the ESC spinning up as soon as a battery is connected. For this reason, always make sure to remove the props before connecting a battery for the first time after changing the motor output protocol.

?? ed but It Is not callbrated.

- If you plan to use the accelerometer, please follow the instructions for 'Calibrate Accelerometer' on the 'Setup' tab. If any function that requires the accelerometer (auto
- level modes, GPS rescue, .) is enabled, arming of the craft will be disabled until the accelerometer has been calibrated.
- If you are not planning on using the accelerometer it is recommended that you disable it in 'System configuration' on the 'Configuration' tab.
- You need to fix these problems before attempting to fly your craft.



## error log 

    status
    MCU F411 Clock=108MHz (PLLP-HSE), Vref=3.31V, Core temp=71degC
    Stack size: 2048, Stack address: 0x2001fff0
    Configuration: CONFIGURED, size: 3630, max available: 16384
    Devices detected: SPI:1, I2C:0
    Gyros detected: gyro 1 locked dma
    GYRO=ICM42688P, ACC=ICM42688P
    OSD: MAX7456 (30 x 13)
    BUILD KEY: ec13320be6dfb3454403e841b0669684 (4.4.2)
    System Uptime: 50 seconds, Current Time: 2025-09-02T09:08:26.240+00:00
    CPU:22%, cycle time: 124, GYRO rate: 8064, RX rate: 249, System rate: 9
    Voltage: 731 * 0.01V (2S battery - OK)
    I2C Errors: 0
    Arming disable flags: BADRX ANGLE CLI ARMSWITCH

Arming disable flags: BADRX ANGLE CLI ARMSWITCH 

- BADRX is the most common cause when telemetry works but motors don’t spin.
- ANGLE prevents arming if FC is not level — always flat on table for first arm.
- Don’t arm with props attached until confirmed on table.


Arming disable flags: THROTTLE CLI MSP






## black box 

Outboard serial logging device

You can log to an external logging device (such as an OpenLager) by using a serial port. Configure the port on the Ports tab.



## betaflight-dat.md

Betaflight is an open-source firmware for drones and other unmanned aerial vehicles (UAVs). It is designed to provide advanced flight control capabilities, making it popular among hobbyists and enthusiasts in the drone community. Betaflight is known for its flexibility, configurability, and support for a wide range of hardware platforms.





## ref 

- [[RC-configurator-dat]] - [[betaflight]] - [[RC]]