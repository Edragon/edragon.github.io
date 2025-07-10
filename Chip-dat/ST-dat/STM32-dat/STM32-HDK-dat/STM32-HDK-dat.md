# STM32-HDK-dat

- [[STM32F103-dat]]

- [[STM32F030-dat]] - [[STM32F042-dat]]

- [[STM32F401-dat]]

- [[STM32G030-dat]]

- [[STM32-lora-dat]]




## peripherals 

- [[auto-serial-dat]] - [[type-c-hdk-dat]]

- [[USB-sys-dat]]

## Pin Definitions 

### USB Pins (STM32F103C8T6)

| Function | Pin  | Description               |
| -------- | ---- | ------------------------- |
| USB_DM   | PA11 | USB Data Minus            |
| USB_DP   | PA12 | USB Data Plus             |
| USB_ID   | PA10 | USB OTG ID (if using OTG) |
| VBUS     | PA9  | USB Bus Power Detection   |

**Notes:**
- PA11 and PA12 are the primary USB differential pair
- External pull-up resistor (1.5kΩ) on DP (PA12) required for USB device mode
- VBUS sensing on PA9 is optional for self-powered devices

## 🔧 Boot Configuration

To enter system bootloader mode (UART download mode), set the BOOT pins as follows:

| BOOT0 | BOOT1 | Mode                            |
| ----- | ----- | ------------------------------- |
| 1     | 0     | **System Memory (USART1 boot)** |
| 0     | x     | Flash memory (normal startup)   |

**Set:**
- `BOOT0 = 1` (connect to 3.3V)
- `BOOT1 = 0` (connect to GND; often fixed on board)

## 🔌 Flashing Procedure

1. Set BOOT0 to HIGH (3.3V), BOOT1 to LOW (GND)
2. Connect USB-TTL:
   - TX → PA10
   - RX → PA9
   - GND → GND
3. Press the RESET button on the STM32 board
4. Open STM32CubeProgrammer or run `stm32flash`
5. Flash firmware over UART1

stm32flash -w firmware.bin -v -g 0x0 /dev/ttyUSB0


## hardware programmer 

- [[ST-Link-dat]]


## Apps 

- [[Lora-HDK-dat]]

## ref 

- [[STM32-dat]]

- [[STM32-SDK-dat]]