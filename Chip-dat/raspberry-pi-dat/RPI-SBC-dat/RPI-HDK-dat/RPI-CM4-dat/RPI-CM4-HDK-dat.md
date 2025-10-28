
# RPI-CM4-HDK-dat.md


run_PG - GLOBAL_EN

- A button between pins 13-14 can be used to wake up compute module from power down
- If compute modules is awake RUN_PG will be high so the button doesn't do anything
- If the compute module is asleep then RUN_PG will be at 0v and so pull global enable low

- [[74xx-dat]] == 74LVC1G07SE-7

## nRPIBOOT 

Force RPIBOOT = Jumper Pins 1-2 == GND 


## EEPROM_WP 

EEPROM write protect = Jumper Pins 3-4 == GND 



## run_PG

- **`RUN_PG`** = Run / Power Good control pin.
- Works like the `RUN` pin on regular Raspberry Pis.

---

## ⚙️ Behavior Table

| Pin State            | Meaning                 | Effect                                                    |
| -------------------- | ----------------------- | --------------------------------------------------------- |
| **High (default)**   | System running normally | CM4 operates normally                                     |
| **Low (pulled low)** | Reset request           | Forces a **hard reset** (CPU/GPU stop, power rails reset) |
| **Released High**    | Release from reset      | CM4 reboots and starts boot sequence                      |


## GLOBAL_EN

## ref 

- [[RPI-CM4-dat]]