# RS422-dat

## Wiring

![](19-25-15-08-08-2023.png)


The following wiring should be correct for RS422 to RS422 

| RS422 pin | RS422 alias | target alias |target | 
| --------- | ----------- | ------------ |------ | 
| Y         | TXD+        | RXD-         |A      | 
| A         | RXD-        | TXD+         |Y      | 
| Z         | TXD-        | RXD+         |B      | 
| B         | RXD+        | TXD-         |Z      | 

this probably wrong or not P2P type 

- Y = TXD+ --- B = RXD+
- Z = TXD- --- A = RXD-
- B = RXD+ --- Y = TXD+
- A = RXD- --- Z = TXD-

| RS422 pin | RS422 alias | target alias |target | 
| --------- | ----------- | ------------ |------ | 
| Y         | TXD+        | RXD+         |B      | 
| Z         | TXD-        | RXD-         |A      | 
| B         | RXD+        | TXD+         |Y      | 
| A         | RXD-        | TXD-         |Z      | 


## Use with arduino

## Demo video 

- please refer to ESP32-ISO board 



## push pull resistor for fail-safe biasing

**Only needed** if the bus can become *idle* (tri-state) and needs *fail-safe biasing*.

---

# 1. Point-to-Point RS-422
**No pull-ups needed.**

- MAX490 outputs are **push-pull** (active drivers)
- They actively drive both HIGH and LOW
- A/B will not float

---

# 2. RS-485-Style Multi-Drop Bus (Tri-state Idle)
If your system has:

- multiple receivers  
- drivers that may **disable** (tri-state)  
- moments where *no one is driving the line*  

→ Then you **must add bias resistors**.

### Typical fail-safe bias network:
- **A → Pull-up 680–1kΩ**
- **B → Pull-down 680–1kΩ**
- **120Ω termination across A–B**

This ensures the bus stays in a known “mark” state.

---

# 3. Driver Always Enabled
**No bias resistors required.**

MAX490 will drive the line at all times → never floating.

---

# 4. Receiver Inputs Only
**Usually no pull-ups needed.**

- MAX490 receiver includes **internal fail-safe**
- Output goes HIGH if inputs:
  - are open,
  - shorted,
  - or idle.

---

# Summary Table

| Scenario | Need Pull-up/Down? | Reason |
|---------|---------------------|--------|
| Point-to-point RS-422 | ❌ No | Push-pull driver |
| Multi-drop RS-485-like bus | ✔️ Yes | Bus can float when idle |
| Driver always enabled | ❌ No | Never tri-states |
| Receiver-only use | ❌ No | Internal fail-safe exists |


## ref

https://en.wikipedia.org/wiki/RS-422
https://www.omega.com/en-us/resources/rs422-rs485-rs232

- [[DPR1097-dat]] - [[MAX490-dat]]

- [[RS422]] - [[DPR1097]]

- [[push-pull-driver]] - [[open-drain-open-collector-dat]] - [[circuits-dat]]


