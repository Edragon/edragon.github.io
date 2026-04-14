

# PCF85063-dat

## SCH 

INT and wakeup 

- [[PCF85063-dat]] - [[NXP-dat]]

https://www.nxp.com/docs/en/data-sheet/PCF85063A.pdf

Tiny Real-Time Clock/Calendar with Alarm Function and I2C-Bus

![](2025-09-04-21-44-26.png)

- RTC alarms can be used to wake up the Compute module
- NB an Alarm triggering while already awake will cause a reset 
- This can be used as a watchdog reset 

The above circuit generates a pulse for GLOBAL_EN when nRTC_INT goes low

GLOBAL_EN needs to be pulse low for >1mS


## SCH 

![](2026-04-14-19-44-12.png)

## ref 