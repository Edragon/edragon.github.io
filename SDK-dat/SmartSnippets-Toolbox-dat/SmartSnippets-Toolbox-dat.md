# SmartSnippets-Toolbox-dat


![](2025-09-24-15-42-27.png)


4. Click "Open" to enter the configuration interface. Select the "Board Setup" menu, and configure the serial port and SPI FLASH pins in the programming tool according to the schematic (if using I2C EEPROM, select the I2C pins).

![](2025-09-24-15-43-19.png)

Click "Board Setup" and configure according to the steps below.

![](2025-09-24-15-45-11.png)

Click "SPI Flash/EEPROM" and configure according to the steps below.

![](2025-09-24-15-46-23.png)

7. After the board connects successfully, click "Erase" to erase the Flash once.

![](2025-09-24-15-47-04.png)

Next, import the hex firmware to be programmed. Click "Browse", then select the path of the firmware to be programmed, select it, and click "Open".

![](2025-09-24-15-47-33.png)

After programming is complete, power cycle the development board. Open the nRF Connect APP to scan for the device, and you should be able to find it.

![](2025-09-24-15-47-59.png)


## ref 

- [[renesas-dat]]

- [[SDK-dat]]