
# PMIC-dat

- [[ever-analog-dat]] - [[EA3036-dat]] - [[EA3059-dat]]

- [[x-powers-dat]] - [[AXP2101-dat]] - [[AXP853T-dat]] - [[PMIC-dat]]


- [[AXP2101-dat]] - [[power-dat]] 

- [[PMIC-dat]] - [[power-dat]] - [[AVDD-dat]] - [[VBAT-dat]] - [[VBUS-dat]] - [[VRTC-dat]] - [[vbackup-dat]] - [[VSYS-dat]]



- [[battery-1s-charger-dat]] 

- [[charge-pump-dat]] - [[MPPT-dat]] - [[power-dat]]

- [[LDO-dat]]


## chips 

- [[injoinic-dat]]

- [[ETA-solutions-dat]]

- [[ismartware-dat]]



## tech 

- [[battery-charger-dat]] - [[battery-1s-dat]]

## apps 

- [[power-bank-dat]] - [[power-UPS-dat]]





## Alternatives to AXP2101 PMIC

Several Power Management ICs (PMICs) offer a similar "all-in-one" approach to the **AXP2101**, integrating multi-channel voltage regulation (DCDCs and LDOs) with battery charging and fuel gauging.

### 1. Within the AXP Series (X-Powers)



If you are already working within the AXP ecosystem (commonly used in ESP32-S3 and development boards), these are the closest siblings:

* **AXP192**: The predecessor to the AXP2101. It is widely used in devices. While it has fewer channels, it is well-documented and has extensive community library support.
* **AXP2102**: A variant often used in similar applications, sometimes with slight differences in the power-up sequence or specific LDO voltage ranges.
* **AXP216**: Targeted at higher-power applications; it offers more current output on certain rails than the AXP2101.

### 2. Industry Standard Alternatives

- [[NPM1300-dat]]

These chips are widely used across the industry for portable IoT, wearables, and multi-core SoC power management:

| Chip | Key Strengths | Best Use Case |
| :--- | :--- | :--- |
| **Nordic nPM1300** | Ultra-high efficiency; very accurate fuel gauge; 2x Buck + 2x LDO. | **nRF52/nRF53** or ultra-low-power BLE projects. |
| **Analog MAX77658** | Uses SIMO (Single-Inductor Multiple-Output) to save board space. | **Hearables** (earbuds) and tiny wearables. |
| **Maxim MAX20360** | Integrated haptic driver and ultra-low quiescent current. | **Smartwatches** and medical sensors. |
| **Active-Semi ACT81458** | High integration with 3 DCDCs and multiple LDOs. | Multi-core processors and **industrial IoT**. |



### 3. Comparison: AXP2101 vs. nPM1300
| Feature | AXP2101 | Nordic nPM1300 |
| :--- | :--- | :--- |
| **Charging Current** | Up to 1.5A | Up to 800mA |
| **DCDC Channels** | 4 (up to 2A) | 2 (up to 200mA) |
| **LDO Channels** | 11 | 2 (50mA/100mA) |
| **Main Advantage** | High channel count for complex systems | USB-C compatibility & power efficiency |

### Selection Advice
* **Stick with AXP2101 if:** You need many power rails (e.g., for a camera, screen, and SD card on one board) or are working with ESP32-based hardware where libraries are already available.
* **Switch to nPM1300 if:** You are prioritizing battery life above all else and only need a few power rails for a low-power microcontroller.
* **Consider MAX77658 or ACT81458 if:** You need specialized features like haptic feedback or are designing for a more complex SoC environment that requires higher current on certain rails.

## ref 

