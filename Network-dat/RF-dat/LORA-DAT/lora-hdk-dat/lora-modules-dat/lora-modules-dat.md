# lora-modules-dat

- [[lora-chip-dat]] - [[lora-modules-dat]]

- [[LLCC68-dat]] - [[NWL1103-dat]]

- [[LR1121-dat]]



- [[SX1262-dat]] - global 

- [[SX1268-dat]] - regional



classic SX127x: 

- [[SX1276-dat]] - [[NWL1072-dat]] - [[NWL1077-dat]] == 868 / 915 mhz 

- [[SX1278-dat]] - [[NWL1071-dat]]  - [[NWL1074-dat]] - [[NWL1075-dat]] == 433 / 470 mhz 

- [[NWL1071-dat]] == hole antenna CONN

- [[SX1278-IPEX-dat]] == IPEX-CONN

- [[NWL1074-dat]] == hole antenna CONN

- [[serial-dat]] output = [[NWL1079-dat]] - [[NWL1081-dat]] 



## compare 

dimension == 17 x 16 x 3.2

| SX1268-L | SX1278-L | SX1278-R | SX1268-R |
| -------- | -------- | -------- | -------- |
| ANT      | ANT      | GND      | GND      |
| GND      | GND      | NSS      | NSS      |
| 3.3V     | 3.3V     | MOSI     | MOSI     |
| RESET    | RESET    | MISO     | MISO     |
| TXEN     | D0       | SCK      | SCK      |
| D1       | D1       | D5       | RXEN     |
| D2       | D2       | D4       | BUSY     |
| D3       | D3       | GND      | GND      |



## questions [[SX1268-dat]] vs [[SX1278-IPEX-dat]]

- Q: Can the drivers for [[SX1268-dat]] and [[SX1278-IPEX-dat]] be used interchangeably?
- A: The drivers are different; [[SX1268-dat]] uses SX1268 chip driver, [[SX1278-IPEX-dat]] uses SX1278 chip driver.

- Q: Is there a difference in pin driving between [[SX1268-dat]] and Ra-01 module?
- A: Yes, the Ra-01 module uses DIO0 for interrupt indication, while [[SX1268-dat]] uses DIO1 combined with busy.

- Q: Is [[SX1268-dat]] a transparent transmission module? Does it support relay?
- A: [[SX1268-dat]] is an RF module; relay needs to be implemented by yourself on the microcontroller, through MCU driver for data transparent transmission.

- Q: Does [[SX1268-dat]] require pin control for transmit/receive, or automatic switching?
- A: By default, automatic switching through program; if pin control is needed, hardware customization is required.

- Q: Can the transmit power of [[SX1268-dat]] be adjusted?
- A: It can be set by manipulating registers.

- Q: What is the reset method for [[SX1268-dat]]?
- A: Give the module's reset pin a high-low level.

- Q: Can [[SX1268-dat]] communicate with other LoRa modules?
- A: As long as the frequency band and LoRa parameters match, communication is possible.

- Q: Does [[SX1268-dat]] support standard LoRaWAN?
- A: Yes, but you need to port the relevant LoRaWAN protocol code yourself; we have LoRaWAN module Ra-08, which can be used directly.




## module make 

- [[HopeRF-dat]] - [[AIT-dat]]



## ref 



[AIT lora legacy page ](https://w.electrodragon.com/w/AIT_LORA_MOD)

- [[lora-modules]] - [[lora]]