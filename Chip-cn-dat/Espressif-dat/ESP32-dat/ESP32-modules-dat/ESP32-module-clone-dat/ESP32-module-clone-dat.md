
# ESP32-module-clone-dat

all RSSI test run in 3 meters wifi connection distance, same environment.


## stock board 

test code [[I2C-dat]] is not running properly for [[ESP32-S3-dat]]

- [[NWI1249-dat]] - [[NWI1243-dat]]



## XXSR series External antenna U version RSSI test

![](2025-10-23-16-27-17.png)

## XXSR69 series RSSI test

![](2025-10-23-14-02-44.png)

### middle == ESP32-D0WD-V3 (revision v3.1)

![](2025-10-23-15-54-18.png)

- 49 Dbm

### right == ESP32-D0WD-V3 (revision v3.1)

```
Connected to ESP32 on COM31:
Chip type:          ESP32-D0WD-V3 (revision v3.1)
Features:           Wi-Fi, BT, Dual Core + LP Core, 240MHz, Vref calibration in eFuse, Coding Scheme None   
Crystal frequency:  40MHz
MAC:                20:e7:c8:9f:30:3c

Stub flasher running.

Warning: ESP32 has no chip ID. Reading MAC address instead.
MAC:                20:e7:c8:9f:30:3c

Hard resetting via RTS pin...
```

![](2025-10-23-15-55-06.png)

- 52 ~ 53 Dbm

### left == unreadable == defective unit == can not upload code 

```
Connected to ESP32 on COM31:

A fatal error occurred: Invalid head of packet (0x65): Possible serial noise or corruption.
```

![](2025-10-23-15-53-29.png)



### close look 

![](2025-10-23-15-10-36.png)

## other more old versions 

X1 

![](2025-10-23-15-55-39.png)

![](2025-10-23-15-55-51.png)

- 58 Dbm 

![](2025-10-23-15-58-04.png)



X2 

![](2025-10-23-15-56-16.png)

![](2025-10-23-16-00-34.png)

- 93 ~ 96 Dbm 

add external antenna 

![](2025-10-23-16-36-54.png)

- 48 ~ 53 Dbm 

![](2025-10-23-16-40-49.png)

- 44 - 50 Dbm



## ref 


- test code [[arduino-dat]]

- [[NWI1100-dat]] - [[esp32-modules-dat]]

- [[signal-dat]] - [[RSSI-dat]]

- [[oled-dat]]


- [[esptool-dat]]

- [[ESP32-chip-dat]]

