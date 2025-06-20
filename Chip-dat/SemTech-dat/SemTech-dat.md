
# SemTech-dat

- [[LR1121-dat]]

- [[SX1302-dat]] == [[lora-gateway-dat]]

https://www.semtech.com/products/wireless-rf

- [[SX1262-dat]] == [[Lora-front-end-dat]]

| Feature                   | SX1262                                 | SX1302                                    |
| ------------------------- | -------------------------------------- | ----------------------------------------- |
| **Type**                  | LoRa Transceiver (RF front-end)        | LoRa Baseband Gateway Chip                |
| **Application**           | End devices (nodes, sensors, modules)  | Gateways (concentrators, base stations)   |
| **Frequency Bands**       | 150–960 MHz (sub-GHz ISM bands)        | 400–510 MHz, 862–1020 MHz                 |
| **Modulation**            | LoRa, (G)FSK, (G)MSK, BPSK             | LoRa, FSK                                 |
| **Transmit Power**        | Up to +22 dBm                          | N/A (no RF front-end, baseband only)      |
| **Receive Sensitivity**   | Down to -148 dBm (LoRa)                | N/A (handled by external RF front-end)    |
| **Channels**              | Single channel                         | 8 LoRa channels + 2 FSK channels          |
| **LoRa Spreading Factor** | SF5 to SF12                            | SF5 to SF12                               |
| **Data Rate**             | Up to 62.5 kbps (LoRa)                 | Up to 500 kbps (aggregate, multi-channel) |
| **Current Consumption**   | 4.2 mA RX, 28 mA TX @ +14 dBm          | <16 mA (core), <70 mA (full gateway)      |
| **Package**               | QFN 24                                 | QFN 68                                    |
| **Key Features**          | Low power, integrated TCXO, small size | Multi-channel, high capacity, low power   |
| **Typical Use**           | IoT sensors, remote controls, trackers | LoRaWAN gateways, network infrastructure  |




## ref 

- [[meshtastic-dat]] - [[opensource-dat]]

- [[lora-dat]] 