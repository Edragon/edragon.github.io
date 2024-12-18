

# RPI-CM-dat

- [[RPI-dat]]

[COMPUTE MODULE OPERATING INSTRUCTIONS](https://www.farnell.com/datasheets/1830506.pdf)

- [[README-CM-dat]]

## CM3 

The Raspberry Pi Compute Module is a small, powerful, and customizable single-board computer designed for embedded applications. It is based on the same architecture as the Raspberry Pi boards but in a more compact form factor. The Compute Module provides a more flexible and modular approach compared to the standard Raspberry Pi boards.

Here are some key features of the Raspberry Pi Compute Module:

- Broadcom BCM2835 processor with ARM Cortex-A7 CPU
- 512MB/1GB RAM options
- 4GB eMMC flash memory (optional)
- 200-pin SODIMM connector for easy integration
- HDMI and USB interfaces via breakout board
- Camera and display interfaces
- Support for industrial temperature range (-20°C to +70°C)
- Support for various operating systems, including Linux and Windows 10 IoT Core

To learn more about the Raspberry Pi Compute Module, you can visit the official Raspberry Pi website:

- Compute Module: https://www.raspberrypi.org/products/compute-module-3-plus/
- Compute Module Datasheet: https://datasheets.raspberrypi.org/compute/CM3Plus/CM3Plus-datasheet.pdf
- If you are looking for code examples and projects related to the Raspberry Pi Compute Module, you can explore the Raspberry Pi GitHub repository: Raspberry Pi GitHub: https://github.com/raspberrypi


![](2023-10-27-16-45-37.png)

CM3+: https://datasheets.raspberrypi.com/cm/cm3-plus-datasheet.pdf

## CM4 

CM4 exposes GPIO Bank 0, which covers GPIOs 0 to 27. Naming is identical between 2711 and CM4.
Bank 1 (GPIOs 28 to 45) is largely used by ethernet functions and wireless LAN.
Bank 2 (GPIOs 46 to 57) is used for eMMC/SD card.

CM4 also has GPIOs 44&45 from Bank 1 exposed for the I2C bus normally connected to the camera or DSI displays. See CM4 datasheet section 2.9 "I2C (SDA0 SCL0)"


default UARTs: https://forums.raspberrypi.com/viewtopic.php?t=345086



## Specs 

![](2023-10-27-16-47-11.png)

## Names 

- CM4001008

![](2023-10-27-16-47-35.png)

![](2023-10-27-16-46-54.png)



## hardware 

- [[BCM2711-dat]]

- [[EMMC-dat]] - [[WIFI-dat]] - [[PHY-dat]] - [[ethernet-dat]]

- Connector - 【 DF40HC (3.0)-100DS-0.4V(51)】

- [[RMP-RPI-CM4-dat]]

### Pins 

- [[RPI-CM4-gpio-dat]]


## Features 

- on module CPU BCM2711 

### On module storage EMMC 

- flash into [[RPI-OS-dat]]

### On module wifi 

## ref 

- [[RPI-CM4-expansion-board-dat]]

- datasheet [[cm4-datasheet.pdf]]

- [[RPI-CM4]]

- https://www.raspberrypi.com/products/compute-module-4/?variant=raspberry-pi-cm4001000

- [[kicad-dat]]

- [[DF40-dat]]


## design ref 

footprint 

- https://github.com/Kedarius/RPi-CM4-Kicad

- https://gitlab.com/m10cube/m10

- https://github.com/ShawnHymel/rpi-cm4-carrier-template


https://elinux.org/RPi_BCM2711_GPIOs