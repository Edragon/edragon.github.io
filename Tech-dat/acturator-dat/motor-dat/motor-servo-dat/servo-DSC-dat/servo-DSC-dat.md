
# servo-DSC-dat



## working product 

- [[RadioMaster-dat]] - [[head-track-dat]]




## info 

**DSC** = **Direct Servo Control**

On [[RadioMaster-dat]] radios (TX16S, Boxer, Zorro, etc.), the **DSC port** is a **wired trainer / simulator control port**, not an audio port.

It outputs **RC control signals** directly from the radio.

---

### What the DSC Port Is Used For

- **RC flight simulators** (wired)
- **Trainer / student mode**
- **Direct control of external devices**
- Legacy wired systems

👉 It is the **replacement for older trainer ports**.

---

### Electrical Signal Type (Important)

Depending on firmware configuration ([[EdgeTX-dat]] / OpenTX), the DSC port can output:

- **PPM (Pulse Position Modulation)** – most common - [[PWM-dat]]
- Sometimes **PWM (single-channel test mode)**


## Physical Connector

- [[CONN-audio-dat]]

Most [[RadioMaster-dat]] transmitters use:

- **3.5 mm TRS jack**

- Tip = PPM signal (or DSC signal)
- Ring = +V (trainer power, often 3.3 V or 5 V)
- Sleeve= Ground

⚠️ Voltage on the Ring pin depends on model and settings.  
**Do NOT short Ring to Ground.**

    ┌──── Tip ──── PPM OUT
    │
    │ ┌── Ring ─── VCC (≈3.3–5 V)
    │ │
    │ │ ┌ Sleeve ─ GND
    ▼ ▼ ▼
    [ T | R | S ]


## ref 

- [[servo-dat]] - [[servo-DSC-dat]]