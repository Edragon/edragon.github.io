

# battery-charger-2s-dat

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

