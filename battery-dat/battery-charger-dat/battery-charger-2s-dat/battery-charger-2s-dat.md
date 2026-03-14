

# battery-charger-2s-dat

- [[battery-2s-dat]] - [[battery-protector-2s-dat]] - [[battery-charger-2s-dat]]

- [[battery-charger-dat]]

- [[IP2326-dat]]




## 2S-lithium-battery-charger-dat



- [[tp-dat]]


`Removable Battery Pack with two different connectors` (or a "breakout" harness). This is a common strategy in hobbyist electronics, but it requires a very specific connector setup to ensure you don't accidentally short the batteries.

For this to work, the batteries cannot be permanently wired in series inside the pack. Instead, you bring out all 4 wires (2 from each battery) to your ports.

The Charging Port (Parallel)

You wire the two positives together and the two negatives together to a single plug.

Warning: If you plug this into a charger while the "Series Port" is also connected to something, you will cause a short. You must physically unplug the battery from the scooter before charging.

The System Port (Series)

This port only becomes "Series" when you plug it into the scooter. The scooter's connector acts as the "bridge" that links the Negative of Battery A to the Positive of Battery B.


## IF the 2S pack battery does NOT have the BMS board 

These chargers are designed to charge 2S packs with balanced charging and proper voltage/current control.

🔧 Example:

IMAX B6 or similar smart chargers

Connect via the main power plug and balance plug (JST-XH, for example)


## IF the 2S pack battery has the BMS board 

== BMS (Battery Management System) + DC Power Supply


- need 2S BMS == 2S 锂电池保护板（BMS）

Example setup:

Use an 8.4V Li-ion charger (e.g., 8.4V/1A wall charger)

The BMS will:

- Protect against overcharge
- Balance the cells (if it's a balancing BMS)




## ref 

- [[battery-dat]]


## options

### 1. The USB-C "Boost" Solution: IP2326
This is arguably the best modern chip for 2S DIY projects. It takes a standard **5V USB input** and "boosts" it to 8.4V.

* **Input:** 4.5V – 5.5V (USB Standard).
* **Charging Current:** Up to 15W (~1.5A–2A).
* **Key Advantage:** It features **integrated cell balancing**. Most simple chargers ignore the middle tap, but the IP2326 monitors both cells to ensure they stay equal.
* **Best For:** Your Rover V2 or any device you want to charge with a phone charger.



---

### 2. The High-Voltage "Buck" Solution: TP5100
A very popular, robust switching buck (step-down) charger. It is more efficient than the older TP4056 and handles much higher power.

* **Input:** 5V – 18V (Note: You need at least **9V–12V** input to charge a 2S pack).
* **Charging Current:** Programmable up to **2A**.
* **Key Advantage:** Very simple peripheral circuit (few external components). You can switch between 1S and 2S mode by shorting the "SET" pins.
* **Best For:** Your scooter project if you plan on using a dedicated 12V power brick.



---

### 3. The Professional "Power Path" Solution: BQ24133
A high-end synchronous switched-mode charger from Texas Instruments.

* **Input:** 4.5V – 17V.
* **Charging Current:** Up to **2.5A**.
* **Key Advantage:** **Dynamic Power Management.** It can power your system (the Rover's motors/sensors) and charge the battery at the same time. If the motor draws too much current, it automatically reduces the charging current to prevent the power supply from crashing.
* **Best For:** Professional-grade robotics where the system must stay "on" while plugged in.

---

### Summary Comparison Table

- [[IP2326-dat]] - [[TP5100-dat]] - [[BQ24133-dat]]

- [[injoinic-dat]] - [[TP-dat]] - [[TI-battery-dat]]

| Feature            | **IP2326**          | **TP5100**         | **BQ24133**            |
| :----------------- | :------------------ | :----------------- | :--------------------- |
| **Input Source**   | 5V USB (Boost)      | 9V-18V DC (Buck)   | 5V-17V DC (Buck)       |
| **Max Current**    | ~2A                 | 2A                 | 2.5A                   |
| **Cell Balancing** | **Yes (Internal)**  | No                 | No (Requires external) |
| **Complexity**     | Medium              | Low                | High                   |
| **Ideal Use Case** | USB-C Powered Rover | High-power Scooter | Always-on Robotics     |

---

### Critical Design Tip: The "Balance" Requirement
Since you are building a **scooter**, safety is paramount. 
* If you use the **TP5100** or **BQ24133**, they do *not* balance the cells. You **must** pair them with a 2S BMS (like the HY2120 mentioned earlier) that has a balancing function.
* If you use the **IP2326**, it handles balancing internally, making the PCB design much safer for the batteries.



## ref 

