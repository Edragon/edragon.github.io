
# rocker-switch-dat

- [[KCD4-dat]]

## 6P 3-Position Rocker Switch Overview == K4D 

### 🧩 Terminology

- **Rocker Switch**: A type of switch that rocks back and forth like a seesaw. Pressing one side causes the other to rise.
- **6P (6 Pin)**: The switch has 6 terminals (pins) for wiring.
- **3-Position**: The switch has three selectable states, typically:
  - **ON - OFF - ON**
  - **Position 1 - Center (OFF) - Position 2**
  - Or used for **Forward - Stop - Reverse** in motor control applications.

---

### ⚙️ Wiring Diagram (ON - OFF - ON Type)


   ┌────────┬────────┬────────┐
   │ Pin 1  │ Pin 3  │ Pin 5  │ ← Common / Input
   ├────────┼────────┼────────┤
   │ Pin 2  │ Pin 4  │ Pin 6  │ ← Output (depends on position)
   └────────┴────────┴────────┘

- Position 1 (Left):    Pin1 → Pin2, Pin3 → Pin4 connected  
- Center (OFF):         All pins disconnected  
- Position 2 (Right):   Pin1 → Pin6, Pin3 → Pin4 connected  

![](2025-06-07-14-04-21.png)

## Hacked KCD4 switch to switch directions 

![](2025-06-07-14-04-44.png)

![](2025-06-07-14-04-58.png)

### 🧠 Switch Pin Layout (Bottom View)

```
   ┌────---───┬────---───┬───---────┐
   │ Pin 1 M1 │ Pin 3 V+ │ Pin 5 M2 │  
   ├────---───┼───---────┼───---────┤
   │ Pin 2 M2 │ Pin 4 V- │ Pin 6 M1 │
   └────---───┴───---────┴───---────┘

Motor:     [ Pin 1 ]——Motor——[ Pin 2 ]
Power:     [ Pin 3 = +V ]    [ Pin 4 = –V ]
Bridges:   Pin1 = Pin6, Pin2 = Pin5 (internal)
```

---

### 🚦 Switch Behavior

| Switch Position | Internal Connection | Motor Polarity       | Motor Direction       |
| --------------- | ------------------- | -------------------- | --------------------- |
| Position 1      | Pin 3 → Pin 1 (+)   |                      |                       |
|                 | Pin 4 → Pin 2 (–)   | + to Motor A, – to B | **Clockwise (CW)**    |
| Center (OFF)    | No connection       | Motor disconnected   | **Stopped**           |
| Position 2      | Pin 3 → Pin 2 (+)   |                      |                       |
|                 | Pin 4 → Pin 1 (–)   | + to Motor B, – to A | **Counter-Clockwise** |

---

### ✅ Summary

This switch setup allows you to:
- Toggle a **DC motor forward/reverse**
- Stop the motor in the **center OFF** position
- Use only **6 pins**, no extra relays or logic



## ref 

- [[rocker-switch]]