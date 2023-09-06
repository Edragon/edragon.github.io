
# USB TTL Dat 

- Green = TX
- White = Rx
- Red = VCC
- Black = GND

![](32-40-17-24-07-2023.png)


## Product links 

- PL2303 - https://www.electrodragon.com/product/pl2303ta-usb-ttl-usb-serial-cable-win-88-1-compatible/

## Use case 

for ESP32 or ESP8266 : TXD -> RXD, RXD -> TXD, 5V -> 5V, GND -> GND. setup IO0 to GND to enter into programming mode 


### troubleshooting checklist
reverse TX RX in case wrong wiring of communication


software [[com-monitor-dat]]

other interface 
- [[RS485-DAT]] - [[RS232-dat]] - [[I2C-dat]]