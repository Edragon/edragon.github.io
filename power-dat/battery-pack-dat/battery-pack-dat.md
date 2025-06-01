
# battery-pack-dat

- in the pack including [[BMS-dat]]



- battery upgrade by [[battery-holder-dat]]

- battery upgrade by [[cable-dat]] (Series And Parallel Connection Cable)

- battery test by [[electronic-loader-dat]]

- check [[battery-discharge-dat]]

- battery isolation == rack (specially when have movement or vibration), Insulating Gasket


## 🔋 Common Lithium Battery Pack Combinations

| Configuration | Voltage (V)     | Capacity (Ah) | Description                           |
| ------------- | --------------- | ------------- | ------------------------------------- |
| 1S1P          | 3.7V            | 3Ah           | Single cell                           |
| 1S2P          | 3.7V            | 6Ah           | 2 cells in parallel                   |
| 2S1P          | 7.4V            | 3Ah           | 2 cells in series                     |
| 2S2P          | 7.4V            | 6Ah           | 4 cells total (2 series × 2 parallel) |
| **3S1P**      | **11.1V = 12V** | **3Ah**       | **Common for RC and drones**              |
| 3S2P          | 11.1V           | 6Ah           | 6 cells total                         |
| 4S1P          | 14.8V           | 3Ah           | Laptop batteries, power tools         |
| 4S2P          | 14.8V           | 6Ah           | Higher capacity variant               |
| 5S1P          | 18.5V           | 3Ah           | Electric tools                        |
| 5S2P          | 18.5V           | 6Ah           | Longer runtime tools                  |
| 6S1P          | 22.2V           | 3Ah           | Drones, high-power packs              |
| 6S2P          | 22.2V           | 6Ah           | More capacity, same voltage           |
| 7S1P          | 25.9V           | 3Ah           | E-bikes, mid-size packs               |
| 7S2P          | 25.9V           | 6Ah           | E-bikes, scooters                     |
| 10S1P         | 37V             | 3Ah           | Standard for e-bike packs             |
| 10S2P         | 37V             | 6Ah           | Common e-bike configuration           |
| 13S1P         | 48.1V           | 3Ah           | High-voltage e-bike pack              |
| **13S2P**     | **48.1V**       | **6Ah**       | **E-bikes, scooters**                 |
| 14S1P         | 51.8V           | 3Ah           | Some 52V e-bike packs                 |
| 14S2P         | 51.8V           | 6Ah           | Higher capacity                       |

## Simple 1S to 2S management Solutions 

![](2025-05-12-16-09-09.png)



## "Powerful" battery

### 1. Upgrade to Higher Cell Count (More Voltage)
- **Switch from 2S (7.4V) to 3S (11.1V) or 4S (14.8V)** for more motor RPM and torque.
- ✅ **Check compatibility** of your **ESC and motor** before upgrading.
  - If not rated for higher voltage, you risk burning them out.

**Pros:**
- Significant performance boost
- Higher speed and torque

**Cons:**
- Can overheat/damage components
- May require stronger drivetrain

---

### 2. Increase Battery Discharge Rate (C-Rating)
- **Higher C-rating = more current output**, improving throttle response and torque.

**Example:**
- 2S 5000mAh 20C → 5A × 20 = 100A max discharge
- 2S 5000mAh 50C → 5A × 50 = 250A max discharge

**Pros:**
- Better throttle response
- Handles load more effectively (climbing, off-road)

**Cons:**
- Higher cost
- May be slightly heavier

---

### 3. Increase Capacity (mAh)
- **Higher mAh = longer run-time** and **less voltage sag under load**

**Example:**
- Upgrade from 2200mAh to 5000mAh for more endurance





## ref 

- [[battery-dat]]