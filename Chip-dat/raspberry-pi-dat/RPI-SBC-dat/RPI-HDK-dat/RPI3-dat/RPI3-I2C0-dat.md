
# RPI3-I2C0-dat.md

# Raspberry Pi 3 — ID_SD / ID_SC for I²C?

## ✔ Yes, they are an I²C bus
- `ID_SD` = I2C data  
- `ID_SC` = I2C clock  
- This bus is known as **I2C bus 0** (I2C0).

## ⚠ Important limitations


1. **Reserved for HAT identification**
   - On official Raspberry Pi boards, I2C0 on ID_SD/ID_SC is used exclusively to read the **HAT EEPROM**.
   - The OS may lock or restrict this bus.

2. **3.3V only**
   - Same voltage rules as other Pi GPIO pins.

3. **Limited functionality**
   - SDA/SCL pull-ups are weak (1.8–3.3 kΩ typical on HATs).
   - Designed for short traces and tiny EEPROMs, not general sensors.

## ✔ How to enable as general I²C (optional)
> Not recommended, but possible.

Edit `/boot/config.txt`:   dtparam=i2c_vc=on


Then you can access it as:
- `/dev/i2c-0`  (I2C0)

## ✔ Recommended method
Use the **main I²C bus**:

- SDA = **GPIO 2**  
- SCL = **GPIO 3**  
- Bus = `/dev/i2c-1`

This is the standard I²C bus for all sensors, modules, etc.


## ref 

- [[RPI3-dat]]

