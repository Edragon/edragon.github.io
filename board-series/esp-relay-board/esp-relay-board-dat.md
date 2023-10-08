# esp relay board dat

legacy wiki page:

- https://w.electrodragon.com/w/ESP_Relay_Board_Hardware
- https://w.electrodragon.com/w/ESP_Board_Setup
- https://www.electrodragon.com/w/ESP_Relay_Board


## board Versions and Links

| Board                                                                                                       | Description                                   | Wiki Link                                     | Usage                           |
| ----------------------------------------------------------------------------------------------------------- | --------------------------------------------- | --------------------------------------------- | ------------------------------- |
| [Wifi IoT Relay Board](https://www.electrodragon.com/product/wifi-iot-relay-board-based-esp8266/)           | General version SPST                          | [[NWI1072-DAT]]                               | AC Mains Power ON/OFF           |
| [ESP Relay Board IL](https://www.electrodragon.com/product/esp-relay-board-il-inductive-load/)              | Optimize for inductive load                   | [[NWI1139-dat]]                               | AC Mains Power ON/OFF           |
| [Wifi IoT Relay Board VDC](https://www.electrodragon.com/product/wifi-iot-relay-board-vdc-based-esp8266/)   | DC Power Supply, DC (or AC) ON/OFF            | [[NWI1115-dat]]                               |                                 |
| [Wifi IoT Relay Board SPDT](https://www.electrodragon.com/product/wifi-iot-relay-board-spdt-based-esp8266/) | Output free (not from input), DC or AC On/OFF | [[NWI1119-DAT]] - [[NWI1118-dat]] (obseleted) | support common-on or common-off |
| [ESP LED Strip Board Control](https://www.electrodragon.com/product/esp-led-strip-board/)                   | for LED strips                                | [[NWI1126-dat]] - [[NWI1124-dat]]             |                                 |



### What is the difference of this version (SPST) and SPDT version:

The output of the relay of SPST is the same as directly AC main input voltage, for powering up connected domestic home appliance in purpose. So the relay only control AC main power on and off
The output of the relay of SPDT is not connected with AC main input voltge, the relay on this one can switch any other circuits you connected in, can be other AC or DC power, please refer to specification on relay.

## Demo Collections 

- [[NWI1072-dat]] drive domestic home appliances - [demo](https://www.youtube.com/watch?v=Tznk1umc20M&ab_channel=ChowHe) 