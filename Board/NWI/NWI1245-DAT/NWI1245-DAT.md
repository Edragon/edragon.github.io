
# NWI1245 DAT

## Main functions:
- general load switching - [[high-side-driver-dat]]

- RS485 communication
- CAN communication 

## Used ESP32-DevKitC Pins

- CAN UART
  - IO23 = CAN0_TX
  - IO22 = CAN0_RX

- UART1
  - IO17 = TXD1 
  - IO16 = RXD1

- UART0 (default used by USB-TTL bridge chip)
  - TXD0 = TXD0
  - RXD0 = RXD0 

- IO33 = Power_ADC
- IO5 = LED

- general load switching 
  - IO12 = CTRL1
  - IO13 = STATUS1
  - IO19 = CTRL2
  - IO18 = STATUS2




## Schematic of peripherals

![](NWI1245-2112-28-2022.jpg)

## Dimension and pin definitions 
![](53-04-16-30-01-2023.png)
- back side selector for UARTs



## power supply
- [[DCDC1]]