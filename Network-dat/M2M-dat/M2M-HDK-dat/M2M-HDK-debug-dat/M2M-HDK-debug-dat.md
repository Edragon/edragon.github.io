

# M2M-HDK-debug-dat

- [[M2M-dat]] - [[M2M-HDK-dat]] - [[M2M-HDK-ref-dat]] - [[M2M-HDK-debug-dat]]



- [[power-dat]] 
    - power supply should be able to supply `VBAT/2A` sufficiently at peak, otherwise the module may not work properly.
    - During the device registering the `network`, the module costs up to `2A`
    - `board status LED`: netlight LED, power LED or other indicator should keep working

- [[USB-SDK-dat]] 
    - try `USB debug` with a USB cable, AT command port, GPS port, modem port, etc. to check if the module is working properly. Power supply should also be sufficent. 

- [[serial-dat]] 
    - if the board has on-board [[logic-level-shifter-dat]], try swap the TXD/RXD pin to try, **TXD/TXD and RXD/RXD** instead of TXD/RXD and RXD/TXD
    - set the on-board [[logic-level-shifter-dat]] `logic level jumper` to 5V or 3.3V according to the module's working voltage, or set to NC to try
    - use a [[serial-USB-debugger-dat]], like [[CH340-dat]] or [[CP2102-dat]], try 5V power supply, all of our boards test in this by default 





## ref 