#!/usr/bin/env python3
"""
SX1278 LoRa SPI Demo for Raspberry Pi

This script demonstrates basic SPI communication with the SX1278 LoRa module.
It performs the following:
- Initializes GPIO and SPI interfaces.
- Resets and verifies the SX1278 module.
- Configures the module for LoRa mode at 433 MHz frequency.
- Sets the module to RX continuous mode to receive LoRa packets.
- Handles DIO0 interrupts for RX done events, reading and printing received data.

Pin mapping:
  LORA_CS     = GPIO8
  LORA_INT    = GPIO4 (DIO0)
  LORA_RESET  = GPIO17

Requirements: spidev, RPi.GPIO
Run with sudo for GPIO interrupts.
"""

import spidev
import time
import RPi.GPIO as GPIO

# =========================
# PIN DEFINITIONS (BCM)
# =========================
LORA_CS     = 8
LORA_INT    = 4
LORA_RESET  = 17

# =========================
# SPI CONFIG
# =========================
SPI_BUS    = 0
SPI_DEV    = 0          # ignored when no_cs=True
SPI_SPEED = 500000
SPI_MODE  = 0

# =========================
# SX1278 REGISTERS
# =========================
REG_OP_MODE        = 0x01
REG_VERSION        = 0x42
REG_IRQ_FLAGS      = 0x12
REG_DIO_MAPPING1   = 0x40
REG_FRF_MSB        = 0x06
REG_FRF_MID        = 0x07
REG_FRF_LSB        = 0x08
REG_FIFO           = 0x00
REG_FIFO_ADDR_PTR  = 0x0D
REG_RX_NB_BYTES    = 0x13
REG_FIFO_RX_CURRENT_ADDR = 0x10

# =========================
# GPIO SETUP
# =========================
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)

GPIO.setup(LORA_CS, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(LORA_RESET, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(LORA_INT, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

# =========================
# SPI SETUP
# =========================
spi = spidev.SpiDev()
spi.open(SPI_BUS, SPI_DEV)
spi.max_speed_hz = SPI_SPEED
spi.mode = SPI_MODE
spi.no_cs = True    # IMPORTANT: software CS

# =========================
# LOW LEVEL SPI
# =========================
def cs_low():
    GPIO.output(LORA_CS, GPIO.LOW)


def cs_high():
    GPIO.output(LORA_CS, GPIO.HIGH)


def read_reg(addr):
    cs_low()
    resp = spi.xfer2([addr & 0x7F, 0x00])
    cs_high()
    return resp[1]


def write_reg(addr, val):
    cs_low()
    spi.xfer2([addr | 0x80, val])
    cs_high()


# =========================
# SX1278 CONTROL
# =========================
def lora_reset():
    GPIO.output(LORA_RESET, GPIO.LOW)
    time.sleep(0.05)
    GPIO.output(LORA_RESET, GPIO.HIGH)
    time.sleep(0.1)


def lora_set_lora_mode():
    # Sleep + LoRa
    write_reg(REG_OP_MODE, 0x80)
    time.sleep(0.01)
    # Standby + LoRa
    write_reg(REG_OP_MODE, 0x81)
    time.sleep(0.01)


def lora_clear_irq():
    write_reg(REG_IRQ_FLAGS, 0xFF)


def lora_set_frequency(freq_hz):
    frf = int((freq_hz * (2**19)) / 32_000_000)
    msb = (frf >> 16) & 0xFF
    mid = (frf >> 8) & 0xFF
    lsb = frf & 0xFF
    write_reg(REG_FRF_MSB, msb)
    write_reg(REG_FRF_MID, mid)
    write_reg(REG_FRF_LSB, lsb)


def lora_set_rx_mode():
    write_reg(REG_OP_MODE, 0x85)  # RXCONTINUOUS + LoRa


# =========================
# INTERRUPT HANDLER
# =========================
def dio0_handler(channel):
    irq = read_reg(REG_IRQ_FLAGS)
    print(f"[DIO0] IRQ FLAGS = 0x{irq:02X}")

    if irq & 0x40:  # RX_DONE
        # Set FIFO pointer to current RX addr
        current_addr = read_reg(REG_FIFO_RX_CURRENT_ADDR)
        write_reg(REG_FIFO_ADDR_PTR, current_addr)

        # Read number of bytes
        nb_bytes = read_reg(REG_RX_NB_BYTES)

        # Read payload
        data = []
        for _ in range(nb_bytes):
            data.append(read_reg(REG_FIFO))

        print(f"Received {nb_bytes} bytes: {bytes(data)}")

    lora_clear_irq()


try:
    GPIO.add_event_detect(
        LORA_INT,
        GPIO.RISING,
        callback=dio0_handler
    )
    print("Interrupt detection enabled on GPIO4")
except RuntimeError as e:
    print(f"Warning: Failed to add edge detection: {e}")
    print("Note: GPIO interrupts may require running the script with sudo")


# =========================
# MAIN
# =========================
def main():
    print("SX1278 LoRa SPI Demo Start")

    lora_reset()

    version = read_reg(REG_VERSION)
    print(f"SX1278 VERSION = 0x{version:02X}")

    if version != 0x12:
        print("ERROR: SX1278 not detected")
        return

    print("SX1278 detected successfully")

    lora_set_lora_mode()
    lora_clear_irq()

    lora_set_frequency(433000000)
    lora_set_rx_mode()

    print("LoRa mode enabled, RX at 433 MHz")
    print("Waiting for packets (DIO0 interrupt or polling) (Ctrl+C to exit)")

    # Poll IRQ flags in case GPIO edge detection failed
    while True:
        irq = read_reg(REG_IRQ_FLAGS)
        if irq & 0x40:  # RX_DONE
            dio0_handler(LORA_INT)
        time.sleep(0.1)


# =========================
# CLEANUP
# =========================
try:
    main()
except KeyboardInterrupt:
    print("\nExit")
finally:
    spi.close()
    GPIO.cleanup()
