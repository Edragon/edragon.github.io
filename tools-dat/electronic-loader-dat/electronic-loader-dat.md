
# electronic-loader-dat

## How to Test a 18650 Battery Capacity Using an Electronic Load

### ✅ What You Need:
- Electronic Load (DC electronic load, programmable preferred)
- Fully charged 18650 battery
- Battery holder or safe terminal connectors
- Multimeter (optional, for voltage verification)
- Logging software or notebook (if needed)

---

### ⚡ Step-by-Step Instructions

#### 1. Fully Charge the Battery
- Use a proper lithium-ion charger.
- Ensure the voltage reaches **4.2V** before testing.

#### 2. Connect the Battery
- Insert the battery into a **18650 holder**.
- Connect **positive (+)** to the load's positive terminal.
- Connect **negative (−)** to the load's negative terminal.
- Double-check for correct polarity.

#### 3. Configure the Electronic Load
- **Mode**: Constant Current (CC)
- **Discharge Current**: e.g., **1.0 A**
- **Cut-off Voltage**: e.g., **3.0 V** (to protect the cell)

> ⚠️ Don't go below 2.5V to avoid damaging the battery.

#### 4. Start the Discharge Test
- Turn on the load.
- The battery will begin discharging at the set current.
- The load will stop automatically at the cut-off voltage.

#### 5. Read the Results
- Check the screen of the electronic load.
- Look for:
  - **Capacity (mAh)**
  - **Energy (Wh)**
  - **Total time**

> Example output:  
> `Capacity: 2600 mAh`  
> `Energy: 9.5 Wh`  

---

### 📌 Notes & Tips

Test at room temperature (around 25°C) for accuracy.

If the load doesn’t show capacity:
  
    Capacity (mAh) = Current (A) × Time (h) × 1000

    0.5A for 1 hour == 0.5 x 1A = 500mAh

    0.5A for 1.2 hour = 600 mAh

