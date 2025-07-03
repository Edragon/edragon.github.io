

# DVA1007-DAT

[legacy wiki page](https://w.electrodragon.com/w/Loraduino)

[Loraduino Lora RF Wireless Dev. Board, Arduino Compatible](https://www.electrodragon.com/product/atmega328p-arduino-plus-lora-sx1278-board-loraduino/)


- 433MHZ version [[DVA1007-DAT]] - 915Mhz version [[DVA1008-DAT]]


### Board Map 

![](2023-11-06-16-04-30.png)

![](2023-11-06-16-06-22.png)

Pin Definitions 

| Function Pin | SPI | category | Arduino |
| ------------ | --- | -------- | ------- |
| Flash_CS     | CS  | D8       | Flash   |
| LED          |     | D7       | LED     |
| RF_CS        | CS  | D10      | SX1278  |
| RF_INT       |     | D2       | SX1278  |
| RF_RST       |     | D8       | SX1278  |
| Voltage-Dect |     | A7       |         |




### Pin Definitions

[[FT232-dat]] FT232 Programming Port 

- VBAT (optional)
- DTR
- TXD
- RXD
- +5V
- GND (CTS)
- -- (GND)



## demo code 

- arduino library **radiohead** - [[arduino-lib-dat]]
- [[spi-flash-dat]] - user lowpower lab flash arduino library 

## bootloader 

- arduino pro mini 3.3V/8M == [[arduino-dat]]

## Functions 

- [[memory-dat]] - [[low-power-dat]] - [[lora-dat]]

- [[battery-charger-dat]] - [[LDO-dat]]

Lora Modules - [[NWL1071-dat]] - [[NWL1072-dat]]

- [[spi-flash-dat]]
- must well initiated flash into low power mode to save power 
- 0xEF40 manufactuer ID for 16mbit

## bulk order 

Buck order price: 

- 16% discount for 100-499pcs order, 
- 20% for 500pcs+ order. Auto update price.

## coding config 

    const int csPin = 10;          // LoRa radio chip select
    const int resetPin = 8;       // LoRa radio reset
    const int irqPin = 2;         // change for your board; must be a hardware interrupt pin
    ...

    LoRa.setPins(csPin, resetPin, irqPin); // set CS, reset, IRQ pin

    if (!LoRa.begin(868E6)) {             // initialize ratio at 915 MHz
    Serial.println("LoRa init failed. Check your connections.");
    while (true);                       // if failed, do nothing
    }

    LoRa.setSignalBandwidth(125E3);
    LoRa.setSpreadingFactor(9);           // ranges from 6-12,default 7 see API docs
    LoRa.setCodingRate4(4/6);

    Serial.println("LoRa init succeeded.");

- from USB Lora Board to [[DVA1008-dat]] running at 868mhz 

 ![](2025-07-03-19-31-14.png)

 ![](2025-07-03-19-31-32.png)


## demo video 

- [low power test](https://x.com/electro_phoenix/status/1639160253811142656)


## ref 

- [[DVA1007]] - [[DVA1008]] - [[DVA1009]]

- [[radiohead-dat]] - [[lora-sdk-dat]]