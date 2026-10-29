


# antenna-yagi-dat

- [[antenna-yagi-dat]] - [[1.2ghz-dat]] - [[antenna-linear-dat]]

- [[conn-SMA-dat]] - [[conn-RP-sma-dat]] 

- [[antenna-radiator-dat]]

- [[frequency-dat]]

- [[video-analog-dat]]

- [[rf-dat]] - [[rf-exposure-dat]]


## build 


### build 2 

HFJ-1205Y 1200MHz用八木 (HFJ1205Y)

产品名称　HFJ-1205Y
频率范围　1260～1300MHz
增益/前后比(F/B)　约10dBi / 20dB以上
半功率波束宽度　E面61°、H面69°
耐输入功率　100W
阻抗/连接器　50Ω / N-J型
安装杆直径　22～62φ
迎风面积　0.02m2
抗风速　45m/sec
臂长/回转半径　454mm/380mm
质量（不含安装支架）　约250克

这台是参数当真的正规产品

① 增益 ↔ 波束宽度 是否自洽？
   D ≈ 41253 / (θE × θH) = 41253 / (61 × 69) = 9.8  →  9.9 dBi
   ⭐ 与标称 10 dBi 几乎完全吻合 ✅

② 带宽是否像正规八木？
   (1300 − 1260) / 1280 = 3.1%
   ⭐ 正好落在教科书的 2–3% 区间 ✅
        ↓
⭐ 两项都对得上 —— 这说明它的频段是真调谐范围、增益是真增益，不是标签。
   反例：市面上「1.2G 14dBi」很多同时标着 ±30° 甚至 60° 波束，
        这在物理上不可能（14dBi 对应约 45°）



### build 1 

6m波段3单元50MHz八木天线快装八木

便携式单波段八木天线，可放入后尾箱，快装设计拆装无需工具，适合野外架设或半固定使用

波段：6m单波段3单元，SWR≤1.5带宽大于600K，更多单元或独特需求可私聊定制。
耐受功率：SSB/CW/FT8=500W/300W/200W
主梁长度：2.2米
增益：5.6dbd（自由空间）/13.5dbi（10m高度）
净重：2kg
安装高度：3米以上

在业余无线电通信中，**天线本身并没有一个绝对固定的“最大通信距离”（如多少公里）**，因为 VHF/UHF 频段（6米波段 50MHz 属于 VHF 的低端）的传播受**地形、架设高度、传播模式、对端功率以及天气/电离层状态**影响极大。

不过，根据这款**6m波段3单元八木天线**的技术参数（主梁2.2米、增益约 5.6 dBd / 13.5 dBi、架设高度3米以上、功率耐受 200W~500W），在不同的传播环境下，它的典型通信距离大致可以分为以下几种场景：

#### 1. 地波常规直射视距通信（Local / Line-of-Sight）

* **通信距离**：**几十公里至 100 公里左右**。
* **特点**：VHF 频段（50MHz）具有较强的准直线性质（类似光线传播），主要受地球曲率和地平线限制。
* 如果你在野外山顶、空旷地带架设，由于天线有约 5.6 dBd 的定向增益，对准目标方向后，与几十公里外的另一个台站通联会非常清晰。
* 如果在平原低洼处或城市密集区，受建筑物和地形阻挡，距离可能会缩短到十几公里甚至几公里。



#### 2. 偶发 E 层传播（Es，Sporadic E，俗称“开")

* **通信距离**：**几百公里至 1500 ~ 2000 公里以上**。
* **特点**：6m波段（50MHz）被称为“神奇的6米波段”（The Magic Band）。在每年春夏之交（通常是5月到8月），电离层 E 层会出现高密度的电离云。利用 Es 层的反射，这个频段可以实现跨省、甚至跨国的远距离（DX）通联。
* 拥有 3 单元定向八木天线后，你可以通过旋转天线指向电离云的方向，清晰地听到并联络到平时根本无法到达的远方电台。

#### 3. 流星余迹散射、对流层信道（Tropospheric Scatter / Meteor Scatter）

* **通信距离**：**300 – 800 公里**。
* **特点**：利用对流层天气折射或流星划过大气层时产生的电离尾迹进行反射通信。配合高灵敏度的模式（如 FT8 弱信号模式，参数中提到 FT8 耐受 200W），这种八木天线能提供足够的增益来捕捉微弱的散射信号。

#### 总结

* **日常本地/中继/直连**：**10 ~ 80 公里**（取决于架设高度与地形）。
* **远距离 DX（遇上电离层开天 / Es季）**：**500 ~ 2000+ 公里**。

要想让这副便携八木发挥出标称的通信距离，架设时务必注意：**尽量选择开阔、地势较高的地方（如山顶、丘陵），并将主梁水平架设（垂直方向调整指向）**，配合对端合适的功率和天线，就能大幅拓展你的通联半径。




## yagi info 


### 1. Why the Frequency Range Is What It Is

A Yagi–Uda array is a **parasitic array**: one driven dipole plus a reflector and a set of directors, all cut to a specific wavelength. Everything about it — element lengths, spacing, feedpoint impedance — is tuned to one centre frequency.

```
Yagi–Uda bandwidth is narrow: 2–3 % of the centre frequency in the basic form,
typically 2–5 %, and it DECREASES as gain increases.
→ hence the design is "ideal for fixed-frequency applications".
     — Wikipedia, "Yagi–Uda antenna"
```

Two consequences set the practical envelope:

| Limit | Cause |
| :--- | :--- |
| **Lower bound ≈ 30 MHz** | Element length scales with λ. A 28 MHz reflector is about **5 m**; an 8-element boom is about **17 m**. Below that it stops being a portable antenna and becomes civil engineering. |
| **Upper bound ≈ 3 GHz** | Element length shrinks with λ. At 5.8 GHz a driven element is only **24 mm**, so dimensional tolerance, element thickness and boom interaction dominate. At the same aperture, a **patch, helix or horn** delivers more gain with far less mechanical fuss. |

---

### 2. Physical Size by Band

Element length ≈ 0.47 λ (driven element); boom length estimated for **8 elements** at ~0.2 λ spacing.

| Band | Typical use | λ | Element length (~0.47 λ) | 8-element boom (~1.6 λ) |
| :--- | :--- | :--- | :--- | :--- |
| **28 MHz** (10 m) | Amateur — the classic monobander | 10.71 m | **5.04 m** | 17.1 m |
| **50 MHz** (6 m) | Amateur | 6.00 m | 2.82 m | 9.6 m |
| **144 MHz** (2 m) | ⭐ Amateur / satellites | 2.08 m | **979 mm** | 3.3 m |
| **430 MHz** (70 cm) | ⭐ Amateur / telemetry / video | 698 mm | 328 mm | 1.12 m |
| **470–700 MHz** | ⭐⭐ **UHF television** (the archetypal Yagi) | 513 mm | 241 mm | 821 mm |
| **868 / 915 MHz** | LoRa / long-range telemetry | 337 mm | 158 mm | 539 mm |
| **1.2–1.3 GHz** | ⭐ FPV video / 23 cm amateur | 240 mm | **113 mm** | 384 mm |
| **2.4 GHz** | WiFi long links / video | 122 mm | 58 mm | 196 mm |
| **5.8 GHz** | FPV / WiFi — rarely a Yagi | 52 mm | **24 mm** | 83 mm |
| **10 GHz** | Amateur / experimental — displaced by horns | 30 mm | 14 mm | 48 mm |

---

### 3. Bandwidth, Quantified

A Yagi centred at **1280 MHz** covers, depending on design class:

| Relative bandwidth | Coverage at 1280 MHz centre | Covers 1.2 G (1080–1280)? | Covers 1.3 G (1240–1300)? |
| :--- | :--- | :--- | :--- |
| **2 %** | 1254–1306 MHz | ❌ | barely |
| **3 %** | 1242–1318 MHz | ❌ | ✅ |
| **5 %** | 1216–1344 MHz | partial | ✅ |
| **10 %** | 1152–1408 MHz | partial | ✅ |
| **20 %** | 1024–1536 MHz | ✅ | ✅ |

For reference, a Yagi centred at **1080 MHz at 10 %** spans **972–1188 MHz** — it cannot reach 1240–1300 MHz at all.

> ⭐ **Rule of thumb: match the Yagi to one fixed centre frequency.** If you need to move across two bands, a Yagi is the wrong tool — see §5.

---

### 4. Where Yagis Are Actually Deployed

| Domain | Band | Notes |
| :--- | :--- | :--- |
| **Television reception** | UHF 470–860 MHz, VHF III 174–230 MHz | By unit count, the most numerous Yagi ever produced — 6–12 elements on every rooftop |
| **Amateur radio** | HF 14/21/28 MHz · 6 m · 2 m · 70 cm · 23 cm · 13 cm | The reference directional antenna; satellite work uses arrays with azimuth/elevation rotators |
| **Two-way radio / repeater links** | VHF 144–174, UHF 400–470 MHz | Directional coverage for repeaters; point-to-point links over terrain and buildings |
| **Long-range telemetry / LoRa** | 433 / 868 / 915 MHz | Farms, metering, UAV telemetry — a Yagi is the cheap way to add range |
| **FPV video** | 1.2 / 1.3 GHz (common), 2.4 GHz (some), 5.8 GHz (rare) | At 5.8 GHz the elements are only 24 mm and a patch of the same size beats it |
| **WiFi point-to-point** | 2.4 / 5.8 GHz | Products exist, but panels and grids dominate |
| **Cellular** | 800 / 900 / 1800 / 2100 MHz | Cell-edge coverage and microwave backhaul links |
| **Wireless microphone receivers** | UHF 470–900 MHz | Stage use: directional Yagi plus antenna distribution |
| **Amateur satellites** | 435 MHz · 1.26 GHz · 2.4 GHz | **Cross-Yagi** designs receive both LHCP and RHCP simultaneously |
| **RF surveying / direction finding** | Any of the above | Narrow beam makes a Yagi a natural bearing antenna |

---

### 5. When NOT to Use a Yagi

| Requirement | Better choice | Why |
| :--- | :--- | :--- |
| **Above ~3 GHz with high gain** | Patch, helix, horn (waveguide) | Element tolerance becomes critical; better gain per unit volume |
| **Wideband coverage** | ⭐ **LPDA (log-periodic dipole array)** | Inherently broadband — 2:1 or more, e.g. one 800 MHz–3 GHz antenna |
| **Circular polarization** | Helix, cross-Yagi, cloverleaf/Skew-planar | A plain Yagi is linear; receiving CP with LP costs ~3 dB before anything else |
| **Omnidirectional** | Whip, dipole, circular omni | A Yagi is directional by construction |
| **Very compact installation** | Patch | Same gain in a flat, mountable form factor |


## 1280mhz 

### 1. First: 1.2 G and 1.3 G Are Not the Same Band

| Common label               | Typical coverage  | Notes                                              |
| :------------------------- | :---------------- | :------------------------------------------------- |
| **1.2 GHz**                | ~1080–1280 MHz    | Older FPV band; some "1.2 G" products stop at 1280 |
| **1.3 GHz**                | ~1240–1300 MHz    | Overlaps the top of 1.2 G but extends higher       |
| **1.2 / 1.3 GHz combined** | **1100–1300 MHz** | ⭐ What you actually want if you may use either     |

FPV channel sets commonly span **1080 / 1120 / 1160 / 1200 / 1240 / 1258 / 1280 / 1320 / 1360 MHz**.
A Yagi is a **narrowband** antenna (roughly 8–12 % relative bandwidth), so:

```
Center 1280 MHz Yagi  → covers ≈ 1150–1400 MHz   ✅ spans both 1.2 G and 1.3 G
Center 1080 MHz Yagi  → covers ≈  970–1190 MHz   ❌ misses 1240–1300 entirely
```

⭐ **Rule: buy a Yagi centred at 1280 MHz or explicitly rated 1100–1300 MHz.**
Never buy on the "1.2 G" label alone.

---

### 2. Search Keywords

#### 2.1 Chinese (Taobao / 1688 / Xianyu)

```
1.2G 图传 八木天线
1.3G 八木 图传
1280MHz 八木天线
1.2G 定向天线 图传 高增益
FPV 1.2G 八木 12dBi
1180-1300MHz 八木
模拟图传 1.3G 天线
Matek VRX-1G3 天线
TrueRC 1.2G / Circular Wireless 1.2G
```

#### 2.2 English (AliExpress / Amazon / RCDrone / eBay)

```
1.2 1.3 GHz 13dBi YAGI
1280MHz Yagi antenna
FPV 1.3G directional antenna high gain
Yagi 1100-1300MHz SMA
Matek VRX-1G3 antenna
1.2GHz long range FPV antenna yagi
```

#### 2.3 If nothing suitable shows up

Step down to a **patch** — far easier to buy at this band:

```
1.2G 图传 定向天线
1.2GHz patch antenna
```

---

### 3. ⚠️ Six Things to Verify Before Paying

| #     | Item                          | How to judge                                                                                                                                                                                                                                                                                         |
| :---- | :---------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **①** | ⭐⭐ **Actual frequency range** | Ignore the "1.2 G" label; read the **Frequency Range** field.<br>✅ **1100–1300 MHz**<br>⚠️ Chinese "1.2 G 14 dBi" products are frequently rated only **1180–1280 MHz** and documented as "performance degrades outside this range" → **they cannot cover 1240–1300 MHz**                              |
| **②** | ⭐ **Polarization must match** | A Yagi is **linearly polarized**. The airborne 1.2 G antenna is also linear (whip/dipole) → **both must share the same orientation, normally both vertical**.<br>❌ This is the opposite of the 5.8 GHz circular-polarization (RHCP) convention. Mixing the two rules destroys the link (20 dB+ loss) |
| **③** | **Connector**                 | 1.2 G VTX/VRX hardware (e.g. Matek VRX-1G3) is usually **SMA**, not RP-SMA                                                                                                                                                                                                                           |
| **④** | **Gain vs beamwidth**         | 13–14 dBi ≈ **±20–25°** beam. Requires a tripod, elevation and precise aiming. For free-flying, stay at 8–10 dBi or use an antenna tracker                                                                                                                                                           |
| **⑤** | **Element count**             | 8 / 12 / 16 elements: more elements → higher gain, narrower beam, longer boom                                                                                                                                                                                                                        |
| **⑥** | **Waterproofing**             | Most Yagis are bare metal. For outdoor permanent use, add heat-shrink or a waterproof housing                                                                                                                                                                                                        |




## ref 