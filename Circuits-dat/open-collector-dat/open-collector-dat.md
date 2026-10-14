


# open-collector-dat



- [[open-drain-dat]] - [[push-pull-dat]] - [[circuits-dat]] - [[open-collector-dat]]




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






## ref 


