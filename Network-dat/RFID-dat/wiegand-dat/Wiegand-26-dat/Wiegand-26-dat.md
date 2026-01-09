
# Wiegand-26-dat

- [[wiegand-dat]] [[Wiegand-26-dat]] - [[Wiegand-34-dat]] - [[Wiegand-37-dat]]

**Wiegand-26** is a **widely used RFID access-control data format**, not a wireless protocol.  
It defines **how card data is encoded into 26 bits** and **transmitted from a reader to a controller**.

> Correct name: **Wiegand-26**  
> Common misspelling: *Wigan-26*

---

## What Does Wiegand-26 Do?
It specifies the **bit structure and wiring method** used to send an RFID card’s ID from:
- **RFID reader → Access controller**

It does **NOT** define:
- RF frequency (125 kHz / 13.56 MHz)
- Card chip type
- Encryption method

---

## Wiegand-26 Bit Structure
Total: **26 bits**

| Bit Position | Purpose                     |
| ------------ | --------------------------- |
| Bit 1        | Even parity (first 12 bits) |
| Bits 2–9     | Facility Code (8 bits)      |
| Bits 10–25   | Card Number (16 bits)       |
| Bit 26       | Odd parity (last 12 bits)   |

### Capacity
- Facility codes: **0–255**
- Card numbers: **0–65,535**

---

## Electrical Interface
- **Two data lines**:
  - `DATA0` → pulse = logic 0
  - `DATA1` → pulse = logic 1
- **Plus**:
  - GND
  - Power (usually 5–12 V)

No clock line — timing is pulse-based.

---

## Typical Use Cases
- Door access control
- Time & attendance systems
- Parking gates
- Elevators

Very common in:
- 125 kHz proximity cards
- Low-cost access systems

---

## Advantages
- Simple
- Very widely supported
- Easy to integrate with controllers

---

## Limitations ❌
- No encryption
- Card ID is transmitted in plain form
- Vulnerable to cloning
- Short cable length (typically < 150 m)

---

## Comparison with Other Formats
| Format     | Bits         | Security | Notes              |
| ---------- | ------------ | -------- | ------------------ |
| Wiegand-26 | 26           | Low      | Most common legacy |
| Wiegand-34 | 34           | Low      | Larger card ID     |
| Wiegand-37 | 37           | Low      | Used by HID        |
| OSDP       | Packet-based | High     | Encrypted, RS-485  |

---

## Important Note
**Wiegand-26 is a data format, not RFID itself.**  
You can have:
- 125 kHz + Wiegand-26  
- 13.56 MHz + Wiegand-26  

They are independent layers.