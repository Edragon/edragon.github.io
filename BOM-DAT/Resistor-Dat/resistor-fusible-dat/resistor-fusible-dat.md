# resistor-fusible-dat

- [[resistor-fusible-dat]] - [[resistor-dat]]


- **33 Ω is the preferred value**
- **100 Ω is the upper limit**, but it runs hot
- **270 Ω is unsuitable**
- Selection should be based on **normal operating losses**, **inrush surge**, and **fault behavior**, not only current limiting

---

## 1. Normal-Operating Power

For a 5 V, 1 A output:

$$
P_{out} = 5\text{ V} \times 1\text{ A} = 5\text{ W}
$$

Assuming an 80% converter efficiency:

$$
P_{input} = \frac{5\text{ W}}{0.8} \approx 6.25\text{ W}
$$

Approximate AC input currents are:

| Input Voltage | Approximate RMS Current |
| ------------- | ----------------------: |
| 230 V AC      |                   49 mA |
| 115 V AC      |                   99 mA |


| R    | 230V 功耗 | 115V 功耗 | 115V 压降 | 1W    电阻占用率 |
| ---- | --------- | --------- | --------- | ---------------- |
| 10Ω  | 0.02 W    | 0.10 W    | 1.0 V     | 10%              |
| 22Ω  | 0.05 W    | 0.21 W    | 2.2 V     | 21%              |
| 33Ω  | 0.08 W    | 0.32 W    | 3.3 V     | 32% ✅            |
| 47Ω  | 0.11 W    | 0.46 W    | 4.6 V     | 46%              |
| 68Ω  | 0.17 W    | 0.66 W    | 6.7 V     | 66%              |
| 100Ω | 0.24 W    | 0.98 W    | 9.9 V     | 98% ⚠️            |
| 270Ω | 0.66 W    | 2.64 W    | 26.7 V    | 264% ❌           |



### Resistor Power Dissipation

The resistor sees approximately the AC input current:

- **270 Ω at 115 V AC:** approximately 2.64 W
- **100 Ω at 115 V AC:** approximately 1 W
- **33 Ω at 115 V AC:** approximately 0.32 W

### Conclusions

- **270 Ω:** Too hot at 115 V AC; a 1 W resistor may fail within seconds
- **100 Ω:** Dissipates almost 1 W continuously at 115 V AC; no useful power margin
- **33 Ω:** Dissipates approximately 0.32 W at 115 V AC, using only 32% of a 1 W rating

---

## 2. Purpose of a Fusible Resistor

A fusible resistor is **not primarily used to set normal operating current**.

According to Vishay ACxx-CS application guidance, it has three main functions:

1. Suppress line transients together with a MOV
2. Limit startup surge current and protect the bridge rectifier
3. Open safely during a fault, such as a failed bridge rectifier or capacitor

The resistance must therefore meet two requirements:

- Limit inrush current
- Remain cool during normal operation

### Approximate Inrush Current

Using a 311 V peak voltage:

| Resistance | Approximate Peak Inrush |
| ---------- | ----------------------: |
| 33 Ω       |                   9.4 A |
| 100 Ω      |                   3.1 A |
| 270 Ω      |                   1.2 A |

The **9.4 A surge for 33 Ω** lasts only microseconds and is generally acceptable for a suitably rated bridge rectifier and fusible resistor.

---

## 3. Vishay Selection Guidelines

### Resistance Limit

> “Ohmic values ≤ 100 Ω are used. This allows high current to pass through and enhances fusing in the event of a fault. 22 Ω and 47 Ω are the most commonly used values.”

Important points:

- 270 Ω exceeds the 100 Ω recommended upper limit
- 22 Ω or 47 Ω are typical choices
- Resistance below 22 Ω may not provide the required 6 kV surge-handling capability

### Surge Voltage Capability

> “Maximum surge voltage handling capability: 6 kV for R ≥ 22 Ω, according to IEC 61000-4-5.”

---

## 4. Recommended Options

| Input Range                               | Recommended Resistor        | Notes                                         |
| ----------------------------------------- | --------------------------- | --------------------------------------------- |
| 100–240 V AC, wide input                  | 33 Ω / 1 W fusible resistor | Suitable for 115 V AC operating margin        |
| 220 V AC only                             | 22 Ω / 1 W fusible resistor | Lower loss; 6 kV surge rating is retained     |
| High surge or high-efficiency requirement | 5D-9 NTC + fuse             | Separates surge limiting and safety functions |

The 33 Ω, 1 W resistor is suitable for 115 V AC operation because it dissipates approximately 0.32 W continuously.

However, the resistor must be specifically rated for:

- Fusible operation
- Flame retardancy
- The required surge pulse energy
- The applicable safety standard

Suitable example families include:

- Vishay AC01-CS, 33 Ω, 1 W
- TE/Welwyn EMC2 or ULW
- RXF fusible resistors
- Fusible, flame-retardant metal-oxide resistors

> **Warning:** A normal metal-film resistor is not a substitute for a fusible resistor. It may change resistance or char instead of opening cleanly.

Even a flame-retardant resistor can ignite nearby material if it experiences a prolonged overload that is insufficient to melt it quickly.

---

## 5. Required Checks

### 1. Input Voltage Range

- **220 V AC only:** 22 Ω may be suitable
- **100–240 V AC:** Use 33 Ω and verify operation at 115 V AC

### 2. Input Capacitor Size

Inrush energy is approximately:

$$
E = \frac{1}{2}CV^2
$$

Examples:

- 22 µF, 400 V:

  $$
  E \approx 1.8\text{ J}
  $$

- 47 µF, 400 V:

  $$
  E \approx 3.8\text{ J}
  $$

The selected resistor must have a pulse-energy rating above the actual inrush energy. A 1 W power rating alone does not determine surge capability.

### 3. MOV Placement

The recommended sequence is:

```text
AC line
  ↓
Fusible resistor
  ↓
MOV
  ↓
Bridge rectifier
  ↓
Bulk capacitor
```

This arrangement allows an MOV fault to place the full transient voltage across the fusible resistor, causing it to open safely.

---

## Next Information Needed

Provide the following values for an accurate final component check:

- Minimum and maximum AC input voltage
- Input capacitor capacitance
- Maximum operating ambient temperature
- Expected surge category
- Fuse type and fuse rating
- Bridge rectifier surge-current rating
