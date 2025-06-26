# Lora-SDK-dat

## stm32 code

![](2025-06-23-18-46-43.png)

Path: The files in LR_driversrc are the LoRa drivers. These drivers are downloaded from Semtech and only modified to adapt to the STM32F103 HAL library; no other changes have been made.

The sx126xhal.c file is used for direct data interaction and control with the LoRa module. In theory, to port to a new IC, you only need to modify this part.

Path: The UserConfig.c file in LR_driver is a common file generated when adapting the IC driver. It includes some configurations such as SPI, dio1 pins, etc. Modify it as needed during porting.

- Core: Core files extracted from the SDK for easier modification
- Driver: User-written peripheral driver files
- LR_driver: LoRa (LLCC68, SX1262 shared) RF driver files, currently downloaded from Semtech's official website
- Main: Main function file and configuration files
- Project: Project files, including target binary files
- queue: This file is a queue SPI interface. Add the path and include it to use. The demo is used for UART data processing
- SDK: CMSIS and HAL libraries, only the used libraries are included. Add other peripheral libraries as needed
- Readme.txt: Project description file




## code

- info for EE22, EE32, EE2 == https://github.com/Edragon/lora
- lora2 designs == https://github.com/Edragon/Lora2
- https://github.com/Edragon/alios-asr-lora
- E:\Git-category\git-lora

## ref

- [[lora-dat]]