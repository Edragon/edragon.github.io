
# ESP32-PDM-dat



There's this project that does PDM: https://github.com/karawin/Ka-Radio32. It tells to connect a speaker to GPIO 25 for PDM/internal DAC, but I think that would way exceed the 12 mA of max output current.

I found a 40xx/74xx logic buffer circuit for PDM sound somewhere (lost the link...), and a mention that a MOSFET would be a good idea. Somewhere else I found adding a 100 uF / 47 uF capacitor between output and speaker should do the trick.

There's this video:https://www.youtube.com/watch?v=oCmfpJNDPn8 that shows an ESP32 with audio out over PDM

This shows something about how to use PDM: https://github.com/earlephilhower/ESP8266Audio/issues/138 (and also notes that for a long time, PDM hasn't worked)

This project also mentions PDM: https://github.com/MrBuddyCasino/ESP32_MP3_Decoder. The source seems based on Ka-Radio32 - or probably the other way around.