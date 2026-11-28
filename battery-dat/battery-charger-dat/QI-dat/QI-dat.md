
# QI-dat


- [[power-wireless-dat]] - [[qi-dat]] 

## board 

- [[OPM1168-dat]] - [[OPM1167-dat]]





## 🔋 What is Qi Wireless Charging?


**Qi** (pronounced *"chee"*) is a **wireless power transfer standard** developed by the **Wireless Power Consortium (WPC)**.  
It allows devices such as smartphones, earbuds, and wearables to charge **without cables**, using **inductive power transfer**.

---

## ⚙️ How It Works
Qi charging uses **electromagnetic induction** between two coils:
- **Transmitter coil (Tx)** – in the charging pad/base.  
- **Receiver coil (Rx)** – inside the device (e.g., phone or earbuds).

### Process:
1. The charger creates an **alternating magnetic field**.  
2. The receiver coil in the device converts it into **electrical energy**.  
3. This energy is used to **charge the battery**.

---

## ⚡ Technical Details

| Parameter          | Typical Value | Notes                             |
| ------------------ | ------------- | --------------------------------- |
| **Frequency**      | 110–205 kHz   | For inductive power transfer      |
| **Voltage Output** | 5V / 9V / 12V | Depending on power profile        |
| **Power Levels**   | 5W, 10W, 15W  | Standard Qi power levels          |
| **Efficiency**     | ~70–85%       | Depends on alignment and distance |
| **Distance**       | ≤ 5 mm        | Coil-to-coil gap must be small    |

---

## 🧩 Qi Power Profiles
| Profile                                 | Power      | Usage                                 |
| --------------------------------------- | ---------- | ------------------------------------- |
| **Baseline Power Profile (BPP)**        | Up to 5W   | Universal compatibility               |
| **Extended Power Profile (EPP)**        | Up to 15W  | Fast wireless charging                |
| **Future Qi2 (Magnetic Power Profile)** | Up to 15W+ | Magnetic alignment, higher efficiency |

---

`Qi2.2 (Qi2 25W)`: Formalized in 2025, this update keeps the same magnetic alignment while boosting speeds up to 25W on supported phones.   

## 🧲 Qi2 Standard (2023–2025)

The **Qi2** update introduces:
- **Magnetic Power Profile (MPP)** — based on Apple’s **MagSafe** design.  
- **Automatic alignment** via magnets for higher efficiency.  
- **15W fast charging** standardized for all brands.  
- **Backward compatibility** with older Qi devices.

---

## ✅ Advantages
- No physical cable wear or connector damage.  
- Water/dust sealing possible (no exposed port).  
- Universal compatibility across many brands.

---

## ⚠️ Limitations
- Slower than wired fast charging.  
- Requires precise coil alignment.  
- Generates more heat.  
- Charging distance is short (<5 mm).

---

## 📱 Common Qi-Compatible Devices
- Most modern **Android** phones (Samsung, Xiaomi, Huawei, etc.)  
- **Apple iPhones** (iPhone 8 and later)  
- **Wireless earbuds** with Qi charging cases  
- **Smartwatches** (select models)

---

## 🧠 Tip
For best performance:
- Use **Qi-certified** chargers.  
- Avoid **metal cases** or **thick covers** (>3 mm).  
- Center the device properly on the pad.  
- Keep the pad **cool and dust-free**.

---

## 🔌 Example Setup
```text
[Wall Adapter] → [Qi Charger Base (Tx Coil)] ⇄ (Inductive Field) ⇄ [Phone (Rx Coil → Battery)]

```
## ref 

- [[wireless-charge-dat]] - [[TI-power-dat]]