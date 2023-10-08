
# Flash Download Tool

- download from - https://www.espressif.com.cn/en/support/download/other-tools

## NWI1139 

SPI = 40Mhz 
SPI Mode = DOUT
for CH340, speed up to 1 500 000 = 1.5M

![](11-51-17-17-04-2023.png)


## NWI1126 

### ESP32-C3 Factory Mode 

- Chip = ESP32-C3
- Mode = Factory
- LoadMode = UART


![](32-02-18-06-02-2023.png)

setup
- Flash Frequency: 40M or 80M 
- SPI Mode: QIO or DIO 


![](56-04-18-06-02-2023.png)

wiring with USB-TTL cable 
- Red = 5V+ Power Supply = pin1 = +5V or VCC
- Green - TXD
- White - RXD
- GND - Ground


![](36-05-18-06-02-2023.png)



### ESP32-C3 Enter into Flash Mode

- Connect wiring first 
- Hold down IO9 
- Press EN or RST button to restart the module, and enter into flash mode 
