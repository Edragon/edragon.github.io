
# I2C Dat 

// I2C device found at address 0x40  !  // INA219, INA226

for [[IOD1001-dat]]

//I2C device found at address 0x3C  ! // OLED = 0x78

//I2C device found at address 0x75  ! // IP5306

//I2C device found at address 0x76  ! // BME280


// I2C device found at address 0x1F  ! // KX023
// I2C device found at address 0x38  ! // AHT20




## Boards 

- [[MPC1029-dat]]

- [[AHT20-dat]] - [[KX023-1025-dat]]

- [[INA226-dat]] - [[OLED-dat]]

- [[NBL1107-dat]]


## Set custom I2C 

    Wire.begin(I2C_SDA, I2C_SCL);


## code library 

the most easy to use library for ESP
- https://github.com/ThingPulse/esp8266-oled-ssd1306


## circuits 

- common pullup resistors 1K/4.7K/10K
![](2024-07-10-01-21-40.png)

## ref 

- https://randomnerdtutorials.com/esp32-i2c-communication-arduino-ide/#1





- [[arduino-dat]]

- [[I2C-scan-dat.ino]]