# resistor-fusible-dat

- [[resistor-fusible-dat]] - [[resistor-dat]]




## type 

AC01-CS, AC03-CS, AC05-CS 涂覆型/陶瓷壳体 - [[resistor-fusible-dat]] - [[resistor-dat]]


你这个问题有现成标准件可以直接对上——不用自己猜封装，Vishay 的 AC 系列就是为这个用途设计的。

一、首选：Vishay AC01-CS（33Ω）
订购码（33Ω ±5%）：
AC01000003309JACCS
这是 Vishay 官方数据手册里给出的实际货号，直接可下单。拆解它的编码规则，你以后自己就能推：
AC01    = 系列（AC01-CS）
000     = 版本/引脚中性
0       = 中性
0330 9  = 阻值：330 × 10⁻¹ = 33 Ω
J       = ±5%
ACCS    = 包装/特殊标识
为什么它正好对上你的需求：

参数	值	对你的意义
P40 / P70	1.1 W / 1.0 W	正好是你要的 1W，115V 下 0.32W = 32% 占用
阻值范围	1 Ω – 100 Ω	33Ω 在区间内，22Ω/47Ω/100Ω 也都有
结构	线绕 + 不可燃硅水泥涂覆	就是你问的“粗糙表面”这一类，非铝壳
熔断	UL1412 认证（UL 文件 E362452）	认证件，不是自己标“熔断”
熔断表现	“fuses without a bang”，230VAC 直接加电时无火焰无爆炸中断	这是它跟普通电阻的本质区别
抗浪涌	新版手册 6 kV（R ≥ 22Ω），1.2/50 µs，IEC 61000-4-5；旧版手册标 2 kV（R ≥ 75Ω）	买前核对数据手册版本，见下面第 5 条
阻燃	涂覆层满足 UL 94 V-0	防火等级有据
温漂 / 工作温度	±200 ppm/K / −40…200 ℃	200℃ 说明它是真安全件设计
熔断时间	32 W 过载时 < 30 s	有明确数字，不是“看情况”
其他	AEC-Q200 合格；可选 WSZ 弯脚做 SMD	—


二、功率不够就上一档：AC03-CS
如果 RC 吸收那颗电阻算出来要 2W 以上（比如跨在 220V 接触器触点、动作频繁），换同一系列的大哥：
AC03-CS    P40 = 3 W，P70 = 2.7 W，阻值 4.7 – 100 Ω
AC05-CS    P40 = 5 W，P70 = 4.5 W，阻值 10 – 100 Ω
封装、涂覆、认证、熔断特性完全一致，只是热容更大。注意 P70（70℃ 环境可用功率）比 P40 低，选型要按 P70 算，不是按 P40。
三、欧洲另一家同等级：TE / Welwyn
如果你在得捷、贸泽上 Vishay 缺货，这两个是同级替代（同一份应用手册里的产品）：
EMC 系列    膜式（film），flameproof，功率 1–3 W 档
ULW 系列    线绕（wirewound），flameproof，2–10 W 档
TE 那份手册明确说它们是“UL Recognised，可省掉额外的保险丝”，三家思路一致：用涂覆/填充的陶瓷体把熔断电弧关在体内。
⚠️ 具体功率后缀（EMC1/EMC2/EMC3）各版本手册命名略有差异，下单前看该型号的 datasheet 首页功率表。
四、国产型号怎么选（这里最容易踩坑）

你想买的	实际型号	能用吗
熔断电阻 1W 33Ω	RXF 系列（丝印常带 F 或“熔断”）	✅ 可以，但必须问厂家要熔断曲线/熔断时间，没有这个参数就是普通电阻
水泥电阻	RX27（白色陶瓷壳，立式/卧式）	⚠️ 只是“阻燃外壳”，不具备熔断认证，做吸收电阻的 R 可以，做保险电阻不行
金属氧化膜	MOF / RSF / RJ	⚠️ 膜式、低电感、适合高频 DC snubber；但多数无熔断认证，AC 输入端用它不合规
铝壳	RX24	❌ 上次说过，热质量大、熔断慢、线绕电感大


国产替代的底线：只要它敢在规格书上写“熔断时间/熔断电流”并给出测试条件，才等价于 UL1412 件；只写“阻燃”“耐高温”的不算。
五、下单前必须核的五项（附具体查法）
① 手册版本 → 抗浪涌 2 kV 还是 6 kV
同一颗 AC01-CS，我查到两份手册：旧版写 “2 kV (R ≥ 75 Ω)”，新版写 “6 kV (R ≥ 22 Ω)”。如果你选了 33Ω，旧版标准下不满足 75Ω 门槛。所以：要么拿新版手册确认，要么保守选 ≥75Ω（但 75Ω 在 115V 下功耗 0.73W，1W 件只剩 27% 余量，见上轮表格）。
→ 宽压输入 + 33Ω 这个组合，务必向供应商索取当前版本 datasheet 并确认 surge 等级。
② 熔断规格 → 熔断时间 vs 故障电流
AC01-CS 给的是“32 W 过载时 < 30 s”。你要确认这个时间与后级整流桥/电容的失效时间匹配：保险件的职责是先断，不能等后级炸完才断。
③ 涂覆厚度/爬电距离 → AC 侧安全件
220V 输入直接串的电阻属于安全件，引脚间距与涂覆必须满足你的安规距离（基本绝缘 2.0 mm 量级，加强绝缘另算）。铝壳件贴散热片反而更难做。
④ 电感 → 决定它能不能用在高频 snubber
AC01-CS 是线绕，几十 nH~几 µH 量级。用在 50/60 Hz 触点消弧没问题；如果 snubber 要处理的是开关电源的高频振铃（几百 kHz），线绕就不合适，得换膜式或贴片多颗并联。
⑤ 阻值 E24 系列
手册注明阻值取 E24 的 ±5% 档，特殊值可定制。所以 33Ω、47Ω、100Ω 都是标准值，27Ω/39Ω 也有；但别指望“36Ω”这种非 E24 值现货。
六、按用途给最终清单
① AC 输入保险电阻，33Ω / 1W，100–240V 宽压
   → Vishay AC01000003309JACCS（AC01-CS 33Ω ±5%）

② 触点 RC 吸收的 R，100Ω / 1W，220V 触点
   → Vishay AC01-CS 100Ω ±5%（同系列，编码里电阻段为 101 + 乘数 0）
   → 能量更大时换 AC03-CS 100Ω（P70 = 2.7W）

③ DC 侧高频 snubber 的 R（几百 kHz）
   → 不要线绕：选厚膜贴片多颗并联，或膜式无感件
   → 例：1206/2512 厚膜 2–4 颗串联分压 + 并联降电感

④ 连续耗散 > 5W 的泄放/制动
   → 才轮到铝壳 RX24 + 散热片
七、一句话总结
选 Vishay AC01-CS（33Ω 直接报货号 AC01000003309JACCS），它就是“线绕 + 不可燃硅水泥涂覆 + UL1412 熔断认证”这三件事同时具备的现货标准件。 国产替代只在能提供熔断曲线时才等价，否则宁可多花几毛钱买认证件。
要不要我把这套选型结论（含 AC01/AC03/AC05 对照表、编码规则、五项核对清单）记进 chip.md？下次再问到保险电阻/吸收电阻直接查表，不用重新调研。


## selection 

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

---

## Vishay Standard Parts

Vishay's AC series is specifically designed for this application, so an existing standard part can be selected directly.

### 1. Preferred Part: Vishay AC01-CS, 33 Ω

Ordering code for 33 Ω, ±5%:

```text
AC01000003309JACCS
```

This is a Vishay standard part-number format and can be ordered directly.

#### Ordering-Code Breakdown

| Code segment | Meaning |
|---|---|
| `AC01` | AC01-CS series |
| `000` | Revision/lead configuration |
| `0` | Neutral lead configuration |
| `03309` | Resistance value: 330 × 10⁻¹ = 33 Ω |
| `J` | Tolerance: ±5% |
| `ACCS` | Packaging/special identification |

#### Why AC01-CS Matches This Application

| Specification | Value | Application Relevance |
|---|---|---|
| P40 / P70 rating | 1.1 W / 1.0 W | Suitable as a 1 W class fusible resistor; 0.32 W at 115 V AC uses only 32% of the rating |
| Resistance range | 1 Ω to 100 Ω | Includes 33 Ω and other common values |
| Construction | Wirewound with non-flammable silicone cement coating | Not an aluminium-housed resistor; has the rough/coated surface described previously |
| Fusible certification | UL 1412, UL file E362452 | Certified fusible resistor rather than a normally rated resistor |
| Fusible behavior | “Fuses without a bang” | Safe interruption at 230 V AC, without flame or explosive interruption |
| Surge rating | Current revision: 6 kV for R ≥ 22 Ω, 1.2/50 µs, IEC 61000-4-5 | Confirm the latest datasheet before ordering |
| Older datasheet | 2 kV for R ≥ 75 Ω | A 33 Ω value may not meet the older revision's stated threshold |
| Flame rating | UL 94 V-0 coating | Certified flame-retardant coating |
| Temperature coefficient / operating temperature | ±200 ppm/K / −40°C to 200°C | Designed as a safety component rather than a normal general-purpose resistor |
| Fusing time | Less than 30 seconds at 32 W overload | Provides a defined overload criterion |
| Additional qualification | AEC-Q200; WSZ bent-lead option available for SMD use | Automotive qualification and optional lead configuration |

---

### 2. Higher-Power AC Series Parts

If the RC absorption resistor requires more than approximately 2 W, use a larger member of the same Vishay family:

| Series | P40 Rating | P70 Rating | Resistance Range |
|---|---:|---:|---:|
| AC03-CS | 3 W | 2.7 W | 4.7 Ω to 100 Ω |
| AC05-CS | 5 W | 4.5 W | 10 Ω to 100 Ω |

The coating, certifications, and fusible characteristics remain similar, but the thermal capacity is higher.

> **Important:** P70 is the derated power at a 70°C ambient temperature and is lower than P40. Use P70 for conservative sizing.

---

### 3. European Alternatives: TE / Welwyn

If Vishay AC01-CS is unavailable, the following TE/Welwyn families are suitable alternatives:

| Series | Construction | Power Range |
|---|---|---:|
| EMC | Flameproof film | 1–3 W |
| ULW | Flameproof wirewound | 2–10 W |

TE documentation identifies these parts as UL-recognized and indicates that a separate fuse may not be required in suitable applications.

Both Vishay and TE use an insulating coating or ceramic filling to contain the fusible interruption and suppress arcing.

> **Note:** EMC and ULW suffixes vary between datasheet revisions. Always verify the power rating shown on the first page of the exact datasheet before ordering.

---

### 4. Chinese Replacement Options

| Desired Application | Typical Model | Suitability |
|---|---|---|
| 1 W, 33 Ω fusible resistor | RXF series, marked with `F` or “fusible” | **Suitable, but only if** the manufacturer provides the fusing curve or fusing time/current data |
| Flame-retardant cement resistor | RX27, white ceramic package | **Not suitable as a protective fusible resistor**; may be used as an absorption resistor because of its flame-retardant body |
| Metal-oxide resistor | MOF / RSF / RJ | Low inductance and suitable for high-frequency DC snubbers, but most models lack fusible certification |
| Aluminium-housed resistor | RX24 | **Not recommended**; slow fusing, high thermal mass, and significant wirewound inductance |

#### Domestic Replacement Rule

A replacement is equivalent to a UL 1412 fusible resistor only when its datasheet specifies:

- Fusing time
- Fusing current
- Test conditions
- Repeatable test results

A resistor described only as “flameproof” or “high-temperature resistant” is not necessarily fusible and is not an equivalent safety component.

---

### 5. Five Checks Before Ordering

#### 1. Verify the Datasheet Revision

Different AC01-CS datasheet revisions may state different surge ratings:

- Older revision: 2 kV for R ≥ 75 Ω
- Current revision: 6 kV for R ≥ 22 Ω

For a 100–240 V wide-input application with 33 Ω, obtain the latest datasheet from the supplier and confirm the surge rating.

As a more conservative choice, R ≥ 75 Ω may comply with the older datasheet. However, at 115 V AC it dissipates approximately 0.73 W, leaving only 27% margin for a 1 W resistor.

#### 2. Verify the Fusing Characteristics

The AC01-CS datasheet specifies interruption in less than 30 seconds under a 32 W overload.

Confirm that this fusing time is compatible with the expected failure behavior of the downstream rectifier and capacitor. The protective resistor must open before downstream components fail, not after they have already been damaged.

#### 3. Check Creepage, Clearance, and Coating

When used directly on the AC input, the resistor is a safety component. Its:

- Lead spacing
- Terminal clearance
- Creepage distance
- Insulation coating

must satisfy the applicable basic and reinforced insulation requirements.

An approximate basic-insulation clearance is 2 mm, but the final requirement depends on the applicable safety standard and working voltage.

#### 4. Check Inductance

AC01-CS is wirewound and may have an inductance of tens of nanohenries to several microhenries.

- Suitable for 50/60 Hz contact suppression
- Less suitable for high-frequency ringing in switching-power supplies
- For MHz-class or several-hundred-kHz snubbers, use a low-inductance film resistor or thin/thick-film SMD resistors

#### 5. Verify the Resistance Series

AC01-CS is generally available in ±5% E24 values. Typical values include:

- 33 Ω
- 47 Ω
- 100 Ω
- 27 Ω
- 39 Ω

Non-standard values such as 36 Ω may require a custom order and should not be assumed to be in stock.

---

### 6. Recommended Parts by Application

#### AC Input Fusible Resistor

For a 100–240 V AC wide-input supply:

```text
33 Ω / 1 W fusible resistor
Vishay AC01000003309JACCS
AC01-CS, 33 Ω, ±5%
```

#### RC Snubber Resistor Across a Contact

For a 220 V AC contact:

```text
Vishay AC01-CS, 100 Ω, ±5%
```

For higher stored energy, use:

```text
Vishay AC03-CS, 100 Ω
P70 rating: 2.7 W
```

#### DC High-Frequency Snubber Resistor

For switching frequencies in the hundreds-of-kHz range:

- Do not use a wirewound resistor
- Use low-inductance thick-film SMD resistors
- Use 1206 or 2512 packages in series for voltage sharing
- Use multiple resistors in series and/or parallel to reduce inductance and increase pulse capability

Example:

```text
2–4 × 1206/2512 thick-film resistors
Connected in series for voltage rating
Connected in parallel for pulse-current sharing, if required
```

#### Continuous Dissipation Above 5 W

For high-power dumping or braking applications:

- Use an aluminium-housed resistor such as RX24
- Mount it on a suitable heat sink
- Verify both continuous power dissipation and pulse-energy capability

---

## Summary

For a 33 Ω AC input fusible resistor, use:

```text
Vishay AC01000003309JACCS
AC01-CS, 33 Ω, ±5%, 1 W class
```

This combination provides:

- Wirewound construction
- A non-flammable silicone-cement coating
- UL 1412 fusible-resistor certification
- Standard 33 Ω availability

A domestic replacement is acceptable only when it provides confirmed fusing curves or fusing time/current specifications. A product that is merely marked “flame-retardant” or “high-temperature resistant” is not a verified equivalent.
