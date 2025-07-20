
# software-I2S-dat.md

Software I2S Delta-Sigma DAC

https://github.com/earlephilhower/ESP8266Audio

                                2N3904 (NPN)
                                +---------+
                                |         |     +-|
                                | E  B  C |    / S|
                                +-|--|--|-+    | P|
                                |  |  +------+ E|
                                |  |         | A|
    ESP8266-GND ------------------+  |  +------+ K| 
                                    |  |      | E|
    ESP8266-I2SOUT (Rx) -----/\/\/\--+  |      \ R|
    or ESP32 DOUT pin                   |       +-|
                                        |
    USB 5V -----------------------------+

    You may also want to add a 220uF cap from USB5V to GND just to help filter out any voltage droop during high volume playback.
