

# svc1039 dat

- env setup [[megaTinyCore]]

- https://www.electrodragon.com/product/vac-current-sensing-module-0-5a-ct-sensor/

## pin definitions 

main function 
- Current sensor = 9
- Input voltage sensor = 10
- relay = PA4 D0

genernal usage 
- Buttons = 8
- led = PA5 D1 1
- UPDI = PA0 

PA1 = 8 = BTN
PA2 = 9 = CS
PA3 = 10 = VS

OLED 
- PB0 - SCL
- PB1 - SDA

UART 
- PB3 = RXD
- PB2 = TXD



## define in arduino 

#define relay 1
#define led 0 

## Library
- [[arduino-OLED]]