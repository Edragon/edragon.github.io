

# svc1039 dat

- env setup [[megaTinyCore]]



## pin definitions 

main function 
- Current sensor = Analog 1 
- Input voltage sensor = Analog 2
- relay = PA4 D0

genernal usage 
- Buttons = Analog 0 
- led = PA5 D1
- UPDI = PA0


OLED 
- PB0 - SCL
- PB1 - SDA

UART 
- PB3 = RXD
- PB2 = TXD



## define in arduino 

#define relay 1
#define led 0 