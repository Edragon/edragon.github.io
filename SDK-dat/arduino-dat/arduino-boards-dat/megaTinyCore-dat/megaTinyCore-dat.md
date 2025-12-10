
# megaTinyCore-dat 

- [[tinyavr-dat]]

- [[programmer-dat]] hardware - [[UPDI-dat]]

## megaTinyCore

DxCore - megaTinyCore
- by Spence Konde
- https://github.com/SpenceKonde/megaTinyCore
- https://github.com/SpenceKonde/megaTinyCore/blob/master/Installation.md
- https://github.com/SpenceKonde/DxCore
- https://github.com/SpenceKonde/DxCore/blob/master/Installation.md
- http://drazzy.com/package_drazzy.com_index.json
- AVR128


## supported boards 

- [] ATtiny3227/3217/1627/1617/1607/827/817/807/427/417
- [] ATtiny3226/3216/1626/1616/1606/826/816/806/426/416/406
- [] ATtiny3224/1624/1614/1604/824/814/804/424/414/404/214/204
- [] ATtiny412/402/212/202
- [] Official Microchip Board
- [] ATtiny3217/1617/1607/817/807/417 w/0ptiboot
- [] ATtiny3227/1627/827/427 w/0ptiboot
- [] ATtiny3216/1616/1606/816/806/416/406 w/0ptiboot
- [] ATtiny3226/1626/826/426 w/0ptiboot
- [] ATtiny1614/1604/814/804/414/404 w/0ptiboot
- [] ATtiny3224/1624/824/424 w/0ptiboot
- [] ATtiny412/402/212/202 w/Optiboot
- [] Official Microchip Board w/Optiboot

upload using programmer 

## e.g. attiny 202 

for board -- [[ILE1073-dat]]

https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/ATtiny_x02.md


- jtag2UPDI 
- burnbootloader 

attachlnterrupt Mode: *On allpins, with new implementation.*

BOD Mode when Active/Sleeping (burn bootloader req'd): *Disabled/Disabled*

BOD Voltage Level (burn bootloader req'd): "1.8V (5 MHz or less)"

UART for Bootloader (burn bootloader req'd): "TX:2 (PA1), RX:3 (PA2)*Chip: "ATtiny202""

Clock (burn bootloader usually req'd see docs): *"8 MHz internal*

Bootloader entry on.. 'Default (Always enter bootloader 8 second delay - unless UPDI fused as reset, then.millis0/micros0 

Timer: Enabled (default timer)*

printf0: "Default (doesn't print floats, 1.4k flash use)"

PWM pins (advanced, see core documentation): *PA1-3,7 (default)UPDI/Reset Pin and: *UPDl, (default optiboot for 8 sec. after allresets)*

Startup Time (burn bootloader req'd): "8ms"

Wire (Wire.h/I2C) Library mode: *Master or Slave (saves flash and RAM)"


## e.g. attiny 1604

![](53-54-16-15-12-2022.png)

- flash bootloader first
- upload sketch by programmer secondly 




- attachlnterrupt Mode: "On all pins, with new implementation."BOD Mode when Active/Sleeping (burn bootloader req'd): Disabled/Disabled*BOD Voltage Level (burn bootloader req'd): "1.8V (5 MHz or less)*UART for Bootloader (burn bootloader req'd): "TX:0 (PA6), RX:1 (PA7)*Chip: "ATtiny412"
- Clock (burn bootloader usually req'd see docs): *20 MHz internal
- Bootloader entry on... 'Default (Always enter bootloader 8 second delay - unless UPDI fused as reset, then...millis0/micros0 Timer: “ Enabled (default timer) *
- printfO: “Default (doesn't print floats, 1.4k flash use)
- PWM pins (advanced, see core documentation): *PA1-3,7 (default)"
- UPDI/Reset Pin and: *"UPDl, (default optiboot for 8 sec. after all resets)"
- Startup Time (burn bootloader req'd): "8ms"
- Wire (Wire.h/I2C) Library mode: *Master or Slave (saves flash and RAM)"