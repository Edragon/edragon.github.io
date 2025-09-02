
# betaflight-configurator-dat

- [[FPV-dat]] - [[mobula8-dat]]

- [[radiomaster-dat]]


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


## ports 


## Configuration


### System configuration
Note: Make sure your FC is able to operate at these speeds! Check CPU and cycletime stability. Changing this may require PID re-tuning. TIP: Disable Accelerometer and other sensors to gain more performance.

8.00 kHzGyro update frequency
1.00 kHz PID loop frequency
Accelerometer
Barometer (if supported)
Magnetometer (if supported)


### Dshot Beacon Configuration

Beacon Tone
RX_LOSTBeeps when TX is turned off or signal lost (repeat until TX is okay)
RX_SETBeeps when aux channel is set for beep



- ESC/Motor Features == ONE SHOT 125

- gyro update frequency == 2kHz

- PID loop frequency == 1kHz

- accelerometer == ON

- telemetry == ON

- reiceiver == Serial-based receiver


## presents 

ExpressLRS250Hz



## failsafe 

- console - failsafe mode - no pulse 

## PID 

- keep all default 

## receiver 

## Modes 

- ARM == AUX 1 
- angle == AUX 2 
- Horizon == AUX 2 
- Air Mode == AUX 1, air mode only in arco mode 
- beeper - also in AUX 1 

Arco mode is very stable, good for beginners


## motors 

- mixer 

### ✅ Recommended ESC/Motor Protocol for Mobula8
- **DSHOT600** → most common, reliable, and default for Mobula8.

### ⚡ Alternatives (if you have issues)
- **DSHOT300** → safer fallback if you experience desyncs or motor twitching.  
- **DSHOT1200** → possible on some boards, but not necessary (no real benefit on Mobula8).  

test 
- [x] DSHOT 300
- [x] DSHOT 600

### settings 

DSHOT300 -- ESC/Motor protocol

[] - MOTOR_STOP Don't spin the motors when armed 
[] - ESC_SENSOR Use KISS/BLHeli_32 ESC telemetry over a separate wlre
[x] - Bidirectional Dshot (requires supported ESC firmware)
12 - Motor poles (number of magnets on the motor bell)
0 - Dynamic Idle Value [* 100 RPM]
8% - Motor Idle ( %, static)

EX1103 - KV11000 == Standard tiny whoop motors like EX1103 11000KV have 6 poles / 3-phase, but some high-torque variations may use 12 poles.

## reset 

The following problems with your configuration were detected:

o there Is no motor output protocol selected.
 Please select a motor output protocol appropriate for your ESCs in 'EsC/Motor Features' on the 'Motors' tab.
Cautlon: Selecting a motor output protocolthat is notsupported by your ESCs can lead to the EsCssplnnlng up as soon as a battery ls connected.For this reason,
always make sure to remove the props before connectlng a battery for the first tlme after changlng the motor output protocol.


o the accelerometer Is enabled but It Is not callbrated.
If you plan to use the accelerometer, please follow the instructions for 'Calibrate Accelerometer' on the 'Setup' tab. If any function that requires the accelerometer (auto
level modes, GPS rescue, .) is enabled, arming of the craft will be disabled until the accelerometer has been calibrated.
If you are not planning on using the accelerometer it is recommended that you disable it in 'System configuration' on the 'Configuration' tab.
You need to fix these problems before attemptlng to fly your craft.



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