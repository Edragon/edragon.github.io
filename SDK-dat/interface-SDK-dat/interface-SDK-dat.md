
# interface-SDK-dat

- [[interface-dat]]

## python on RPI 

- [[RPI-sdk-dat]] - [[python-dat]] - [[python-env-dat]]

### I2C scan 

- [[py-rpi-i2c-scan-dat]] - [[LM75-dat]]

output 

    root@raspberrypi:~# python py-rpi-i2c-scan.py 
    ============================================================
    Raspberry Pi I2C Address Scanner
    ============================================================
    I2C Scanner initialized on bus 1
    Scanning I2C bus for devices...
        0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    00:          -- -- -- -- -- -- -- -- -- -- -- -- -- 
    10: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    20: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    30: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    40: -- -- -- -- -- -- -- -- 48 -- -- -- -- -- -- -- 
    50: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    60: -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 
    70: -- -- -- -- -- -- -- --                         

    Found 1 device(s):
    ------------------------------------------------------------
    Address: 0x48 ( 72) - ADS1115/ADS1015 ADC or TMP102 Temperature Sensor

    Scan complete!

    Note: Make sure I2C is enabled in raspi-config
    Install required library: 
    
        pip install smbus2





## ref 

- [[SDK-dat]]