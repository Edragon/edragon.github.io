
# NWI1199 DAT

- [[LAN8720-DAT]]


![](42-44-18-24-04-2023.png)

| ESP32   | func        | Ethernet          | Note |
| ------- | ----------- | ----------------- | ---- |
| GPIO 17 | PHY_POWER   | Osc_PWR (PHY_pwr) |      |
| GPIO 22 | EMAC_TXD1   | TX1               |      |
| GPIO 19 | EMAC_TXD0   | TX0               |      |
| GPIO 21 | EMAC_TX_EN  | TX_EN             |      |
| GPIO 26 | EMAC_RXD1   | RX1               |      |
| GPIO 25 | EMAC_RXD0   | RX0               |      |
| GPIO 27 | EMAC_RX_DV  | CRS               |      |
| GPIO 00 | EMAC_TX_CLK | nINT/REFCLK       |      |
| GPIO 23 | SMI_MDC     | MDC               |      |
| GPIO 18 | SMI_MDIO    | MDIO              |      |
| GND     |             | GND               |      |
| 3V3     |             | VCC               |      |


### IO 17 -- Osc_PWR (PHY_pwr)
3-way jumper
- NC (Not connect)
- connect
2-way jumper
- Add pull down 4.7K

### IO0 -- CLK 
2-way jumper (left)
- 4k7 pull up
2-way jumper (right)
- connect

### Crystal 
- active 50MHz


## ref 
- https://sautter.com/blog/ethernet-on-esp32-using-lan8720/