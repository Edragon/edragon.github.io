
# SPI-dat

- [[74HC125-dat]] == [[logic-level-shifter-dat]]


- [[RPI-HDK-dat]]

| pin  | active | function | note       |
| ---- | ------ | -------- | ---------- |
| CLK  |        |          | 3-wire SPI |
| MISO |        |          | 3-wire SPI |
| MOSI |        |          | 3-wire SPI |
| CS   | low    |          | 4-wire SPI |



For the SX1262, the NSS pin (chip select) is active low TTL.

Meaning:

- Idle (not selected): NSS = HIGH
- Active (selected): NSS = LOW
- Level logic: 3.3 V high, 0 V low (since SX1262 is a 3.3 V device — do not feed it 5 V).

From Semtech SX1262 datasheet:

- NSS is internally pulled high by default.
- Every SPI transaction starts when NSS goes low and ends when NSS goes high.
- All SPI data must be clocked while NSS is low.




## ref 

- [[interface-dat]] - [[ref-design-dat]]