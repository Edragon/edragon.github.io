
# radiohead-dat

https://github.com/epsilonrt/RadioHead

    RH_RF95 rf95 (27, 6); // CS and DIO0 

    // CE 16 CS 15
    RH_NRF24 nrf24(16, 15);

    // DVA1002
    RH_NRF24 nrf24(7, 10);


nrf24_client 

    init OK

    Sending to nrf24_server
    No reply, is nrf24_server running?
    Sending to nrf24_server
    No reply, is nrf24_server running?




## RF95 


### config 

// Defaults after init are 434.0MHz, 13dBm, Bw = 125 kHz, Cr = 4/5, Sf = 128chips/symbol, CRC on

    rf95.setFrequency(868.0);
    rf95.setTxPower(22, true);
    // rf95.setModemConfig(RH_RF95::Bw125Cr46Sf9);
    rf95.spiWrite(RH_RF95_REG_1D_MODEM_CONFIG1, 0x72); // Bw125kHz, Cr4/6, Explicit Header
    rf95.spiWrite(RH_RF95_REG_1E_MODEM_CONFIG2, 0x94); // SF9, CRC off, RxTimeoutMsb=0


### config 2 

https://github.com/meshtastic/RadioHead/blob/master/RH_RF95.cpp


    // rf95.setModemConfig(RH_RF95::Bw125Cr46Sf9);
    rf95.setSignalBandwidth(RH_RF95_BW_125KHZ);
    rf95.setCodingRate4(RH_RF95_CODING_RATE_4_6);
    rf95.setSpreadingFactor(RH_RF95_SPREADING_FACTOR_512CPS);



### Explicit Header

Explicit Header in the context of LoRa (as used by the RadioHead library and the RF95 chip) refers to a packet format where the header information—such as payload length, coding rate, and CRC presence—is included in each transmitted packet.

Explicit Header mode: The packet contains a header with metadata (payload length, coding rate, CRC on/off). This allows the receiver to dynamically adapt to different packet configurations.

Implicit Header mode: The header is omitted; both sender and receiver must be pre-configured with the same settings, as the packet does not carry this information.

### RxTimeoutMsb=0

RxTimeoutMsb=0 refers to a setting in the RF95 LoRa modem configuration register (specifically, RH_RF95_REG_1E_MODEM_CONFIG2). The "RxTimeout" parameter controls how long the receiver will wait for a valid preamble before timing out.

RxTimeoutMsb is the most significant byte of the receive timeout value.
Setting RxTimeoutMsb=0 means the timeout is set to its minimum value (effectively disabled or very short), so the receiver will not wait long for a packet before giving up.


- [[Lora-SDK-dat]]

E:\Git-category\Git-Arduino\arduino-main2\libraries\RadioHead


- [[Dva1007-dat]]