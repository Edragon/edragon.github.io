
# open-drain-open-collector-dat

# Open-Drain vs Open-Collector

Both are output types that **can pull LOW but cannot drive HIGH**.  
A pull-up resistor is required to generate the HIGH level.

---

# 1️⃣ Open-Collector (OC)

- Uses an **NPN bipolar transistor**
- Can **pull output LOW**
- Cannot **drive output HIGH** → needs external pull-up resistor

## How it works
- Transistor ON → output pulled to GND → **LOW**
- Transistor OFF → output floats → pull-up resistor → **HIGH**

## Common uses
- I²C
- Interrupt lines
- Wired-OR / wired-AND logic
- Level shifting (pull-up to different voltage)

---

# 2️⃣ Open-Drain (OD)

- Same behavior as open-collector
- Uses an **NMOS FET** instead of an NPN transistor

## How it works
- FET ON → output pulled LOW
- FET OFF → pull-up resistor → HIGH

## Common uses
- Modern low-voltage ICs
- I²C bus
- Shared interrupt lines

---

# 3️⃣ Why use open-drain / open-collector?

Because multiple devices can safely share one wire:

- Any device can pull the line LOW  
- No device ever drives HIGH → **no short-circuit conflict**

This enables **wired-AND / wired-OR logic**.

---

# 4️⃣ Comparison Table

| Feature | Open-Collector | Open-Drain |
|--------|----------------|------------|
| Device type | NPN transistor | NMOS FET |
| Pulls LOW? | ✔️ Yes | ✔️ Yes |
| Drives HIGH? | ❌ No | ❌ No |
| Needs pull-up resistor? | ✔️ Yes | ✔️ Yes |
| Common in | Older TTL/CMOS | Modern ICs |
| Functional behavior | Same | Same |

---

# 5️⃣ Key Point

**Open-drain and open-collector behave the same.**  
The name only depends on the type of transistor used.

## ref 

- [[circuits-dat]]