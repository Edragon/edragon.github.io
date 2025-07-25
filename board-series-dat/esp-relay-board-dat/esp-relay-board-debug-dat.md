
# esp-relay-board-debug-dat.md

Board keep flashing 

- [[esptool-dat]]

1. run a flash clean to fully clean the flash memory for correct new firmware

    esptool erase_flash

2. make sure well pressed IO0 pin to enter boot mode 

3. check serial output for debugging info