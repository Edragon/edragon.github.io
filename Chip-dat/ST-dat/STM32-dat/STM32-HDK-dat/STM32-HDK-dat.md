
# STM32-HDK-dat

- [[STM32F103-dat]]

- [[STM32F030-dat]] - [[STM32F042-dat]]

- [[STM32F401-dat]]

- [[STM32G030-dat]]

- [[STM32-lora-dat]]

## download 

NRST - DTR#, BOOT0 - RST# 

![](2025-06-23-18-00-49.png)


## power supply and download via USB 

![](2025-06-23-18-01-31.png)

## 🔧 Boot Configuration

To enter system bootloader mode (UART download mode), set the BOOT pins as follows:

| BOOT0 | BOOT1 | Mode                           |
|-------|-------|--------------------------------|
| 1     | 0     | **System Memory (USART1 boot)** |
| 0     | x     | Flash memory (normal startup)  |

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



## ref 

- [[STM32-dat]]

- [[STM32-SDK-dat]]