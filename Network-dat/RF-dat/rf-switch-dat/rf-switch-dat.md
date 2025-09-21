
# rf-switch-dat

Here's a complete wiring diagram for using the SX1262 with DIO2 controlling RF switch (TX/RX EN) and all required connections, assuming:

You're using a single-pin RF switch like the SKY66420-11 (or similar).

You're interfacing it with a microcontroller (MCU), such as ESP32 or STM32.

You are not using DIO3 or DIO1 for FEM control.

SPI interface is used between the MCU and the SX1262.