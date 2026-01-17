#!/usr/bin/env python3
"""
SX1278 SPI Demo - Raspberry Pi 3
Pin mapping:
  LORA_CS     = GPIO8
  LORA_INT    = GPIO4 (DIO0)
  LORA_RESET  = GPIO17
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

# =========================
# INTERRUPT HANDLER
# =========================
def dio0_handler(channel):
    irq = read_reg(REG_IRQ_FLAGS)
    print(f"[DIO0] IRQ FLAGS = 0x{irq:02X}")
    lora_clear_irq()

try:
    GPIO.add_event_detect(
        LORA_INT,
        GPIO.RISING,
        callback=dio0_handler,
        bouncetime=10
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

    print("LoRa mode enabled")
    print("Waiting for DIO0 interrupt (Ctrl+C to exit)")

    while True:
        time.sleep(1)

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
