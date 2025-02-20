
# BMP280-dat

- DS = [[BST-BMP280-DS001-11.pdf]]

The I2C address for the BMP280 sensor is 0x76 by default. However, it can also be set to 0x77 depending on the connection (if the SDO pin is tied to VCC or GND).


## footprint 

The sensor housing is an 8-pin metal-lid LGA 2.0 × 2.5× 0.95 mm3 package. 

![](2025-01-10-17-03-30.png)

## wiring 


| Arduino                             | [[STH1060-dat]] | BMP280 / BME280                        |
| ----------------------------------- | --------------- | -------------------------------------- |
| 3.3V                                | yes             | VCC                                    |
| GND                                 | yes             | GND                                    |
| SDA                                 | yes             | SDA                                    |
| SCL                                 | yes             | SCL                                    |
| some BMP280/BME280 modules          |                 | break out the CSB and SDO pins as well |
| 5V                                  | no need         | CSB (enables the I2C interface)        |
| GND                                 | no need         | SDO (I2C Address 0x76)                 |
| 5V                                  | no need         | SDO (I2C Address 0x77)                 |
| other pins can be left unconnected. |                 |                                        |

- default I2C address  == 0x76 


## code 

- library - BMx280MI




## ref 

- [[I2C-dat]]