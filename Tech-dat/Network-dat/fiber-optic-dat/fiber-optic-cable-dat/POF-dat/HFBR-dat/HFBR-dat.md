
# HFBR-dat

HFBR-4503Z

- [[HFBR-0500Z-Series-dat]]

- [[HFBR]] - [[POF]]

## Best Way to Use POF for 5V TTL Serial:

    TX Side (Microcontroller)
    --------------------------
    MCU TX ──► HFBR-1521 (Transmitter)
    GND ─────┬──────────────────────┐
    Vcc (5V) ──────────────────────►

    RX Side (Receiver)
    -------------------
    POF Fiber ──► HFBR-2521 (Receiver)
    Output ─────► MCU RX
    GND ─────────┴──────────────────


## ref 

- [[TOSlink-dat]]