
# CC-CCW-control-dat

🚀 Bidirectional (CW/CCW) Motor Control using GPIO and MOSFETs

This guide explains how to use **GPIO** pins to control the **direction** of a DC motor using a MOSFET-based circuit, starting from your current schematic.

---

## ✅ Option 1: Use an H-Bridge (Recommended)

Use **4 MOSFETs** or an **H-bridge IC** like:

- L298N
- DRV8871
- BTS7960

### Logic Table:
| IN1 | IN2 | Motor Direction |
|-----|-----|-----------------|
|  1  |  0  | CW              |
|  0  |  1  | CCW             |
|  0  |  0  | Coast (OFF)     |
|  1  |  1  | Brake (Stop)    |

---

## ✅ Option 2: Use Two MOSFETs (Discrete H-Bridge Half)

Use two N-channel MOSFETs:

```
        +Vbat
          |
        Motor
          |
        A ---------> MOSFET1 --------> GND  (CTRL1 = CW)
        |
        B ---------> MOSFET2 --------> GND  (CTRL2 = CCW)
```

### Control Logic:
| CTRL1 (CW) | CTRL2 (CCW) | Motor State |
|------------|-------------|-------------|
| HIGH       | LOW         | Spin CW     |
| LOW        | HIGH        | Spin CCW    |
| LOW        | LOW         | OFF         |
| HIGH       | HIGH        | 🚫 Avoid! (Short) |


## ref 

- [[motor-driver-dat]]