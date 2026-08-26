

# Loitering-dat


- [[Loitering-dat]] - [[aerodynamic-dat]] - [[position-hold-dat]]


- [[stall-dat]] - [[wing-loading-dat]] - [[weight-dat]] - [[gravity-dat]]



## endrurance 

In aviation engineering, **fixed-wing aircraft cannot achieve true zero-airspeed physical hovering** (unless utilizing vertical takeoff/thrust-vectoring or tilt-rotor technology, which relies on rotorcraft or pure thrust principles for hovering). 

Therefore, for the requirement of **long-duration, low-speed loitering or "pseudo-hovering"**, the most suitable fixed-wing structural configurations and engineering optimization strategies focus on two core goals: **maximizing the lift-to-drag ratio** and **minimizing stall speed**.

---

### 1. Most Suitable Aircraft Structural Configurations for Loitering

The **High Aspect Ratio, Low Wing Loading "Glider / Solar Unmanned Aerial Vehicle (UAV)" Configuration** is the most aerodynamic and efficient structure for prolonged loitering.

*   **Representative Examples**: High-Altitude Long-Endurance (HALE) UAVs like *Helios* and *Zephyr*, as well as high-performance dual-seat/single-seat gliders.
*   **Structural Characteristics**:
    *   **Ultra-High Aspect Ratio Wings**: Extremely long and narrow wings (similar to an albatross's wings), with aspect ratios typically exceeding 20, and reaching up to 30–40. This design **minimizes induced drag**—the primary component of drag at high angles of attack during loitering.
    *   **Extremely Low Wing Loading**: Constructed with ultra-lightweight carbon-fiber composites, keeping the ratio of aircraft weight to total wing area very low (typically below 10–20 kg/m²). Lower wing loading reduces the stall speed ($V_{stall}$) required to maintain lift.

---

### 2. Engineering Optimization Strategies

To enable a fixed-wing aircraft to perform tight, energy-efficient loitering at near-hover speeds, a combination of aerodynamic, propulsion, and control optimizations is implemented:

#### Aerodynamic & Airfoil Optimizations
*   **High-Lift Airfoils**: Utilizing airfoils with significant camber and large leading-edge radii (such as Selig or Eppler series designed for low-speed gliding). These maintain attached boundary layers and provide a high maximum lift coefficient ($C_L$) at minimal airspeeds.
*   **Full-Span High-Lift Devices**:
    *   Deploying **Fowler Flaps** or **Slats** to increase overall wing area and camber during loitering, reducing stall speed to the absolute lower limit.
    *   **Flaperon Systems**: Combining flap and aileron functions across the trailing edge to ensure sufficient roll control during low-speed, tight-radius turns.
*   **Winglets / Closed-Wings**: Suppressing wingtip vortices to lower induced drag during steep banked turns.

#### Propulsion & Thrust Vectoring Optimizations
*   **Large-Diameter, Low-RPM Propellers**: Driven by electric motors, large-diameter propellers yield maximum propulsive efficiency at low airspeeds, allowing level flight with minimal power draw.
*   **Upper-Surface Blowing (Coandă Effect)**: Directing propeller slipstream over the upper surface of the wing and trailing-edge flaps. This artificially boosts airflow velocity over the airfoils, generating sufficient lift even when the aircraft's groundspeed approaches zero (commonly used in STOL designs like the An-72 and C-17).

#### Structural & Flight Control Optimizations
*   **Canard or Three-Lifting-Surface Layout**: Positioning a forward lifting surface in front of the main wing causes the canard to stall first during low-speed high-angle-of-attack maneuvers. This inherently prevents deep stalls while enhancing overall trimmed lift efficiency.
*   **Automated Loiter Control Algorithms**: Utilizing flight controllers to maintain an optimal bank angle for constant-radius loitering or "figure-8" patterns, dynamically re-trimming against wind vector changes to minimize energy loss.

---

### Summary Comparison

| Objective Focus | Recommended Engineering Layout | Key Technical Features | Loiter / Flight Performance |
| :--- | :--- | :--- | :--- |
| **Ultra-Long Endurance / Point Surveillance** | **High Aspect Ratio, Low Wing-Loading High-Wing** (e.g., Solar UAVs) | Narrow wings, carbon-fiber light-weighting, high-lift airfoils | Maintains continuous loitering at minimal airspeeds (30–50 km/h) with extremely low power consumption. |
| **Ultra-Low Speed / "Pseudo-Hovering"** | **Short Takeoff & Landing (STOL) + Upper-Surface Blowing** | Fowler flaps, propeller slipstream blowing, high-torque electric propulsion | Achieves near-zero groundspeed "pseudo-hovering" when flying into headwind. |






## loitering 

让一架动力手抛机实现“空中低速盘旋”，其最低飞行速度（即**失速速度 Stall Speed** 或安全盘旋临界速度）取决于**机翼载荷（Wing Loading）**、**机身重量**以及**翼展面积**。

在实际的航模与无人机设计中，根据机型定位不同，极限低速可以达到以下量级：

### 1. 不同类型动力手抛机的最低速度参考

* **微型超轻量级（Micro / Ultralight，如 UMX 级或自制轻型 EPP 泡沫机）：**
* **起飞重量：** 100g – 250g 左右。
* **最低盘旋速度：** 可以做到 **15 km/h – 20 km/h**（约 **4 m/s – 5.5 m/s**）。
* 这种极轻的飞机由于翼载荷极低，几乎像大号纸飞机一样飘，能在很小的半径内慢速盘旋。


* **常规 FPV 远航/公园机（Standard Park Flyer / FPV Wing，如主流泡沫固定翼）：**
* **起飞重量：** 600g – 1.5kg 左右。
* **最低盘旋速度：** 通常在 **25 km/h – 35 km/h**（约 **7 m/s – 10 m/s**）。
* 如果速度低于这个区间，机翼产生的升力不足以平衡重力，就会发生失速（Stall），表现为一边机翼突然下坠（Tip stall）并螺旋下栽。


* **极端情况 —— “类垂直悬停”（Prop Hang / 3D Mode）：**
* 如果你的动力手抛机推重比（TWR）大于 1.0，并且配合飞控开启了前文提到的 **Auto Hover（自动悬停）**：
* **理论最低水平速度：** 可以降到 **0 km/h（完全原地静止或倒退）**。
* 但此时它不再靠机翼提供升力，而是靠螺旋桨的暴力风扇效应把飞机“挂”在空中。



---

### 2. 决定最低盘旋速度的核心物理因素

如果你想让自己的动力手抛机飞得**尽可能慢、盘旋半径尽可能小**，在设计和调整时需要关注以下几点：

1. **极低的翼载荷（Wing Loading）：**
* 公式决定一切：重量越轻、机翼面积越大，翼载荷就越低，失速速度就呈平方根级别下降。采用大展弦比、宽弦长的平直翼或带上反角的机翼最利于低速。


2. **气动布局与增升装置：**
* 如果机翼后缘带有 **Flaps（襟翼）** 或是大面积的 **Flaperon（升降副翼联动）**，在低速盘旋时向下偏转一点角度，可以显著增大翼型弯度、提高升力系数，从而把最低安全盘旋速度再往下压 10%–20% 左右。


3. **盘旋时的迎角与失速风险：**
* 固定翼在盘旋（Bank）时，由于倾斜角的存在，垂直向上的分力减小，**有效失速速度会比平飞时更高**。因此在低速盘旋时，如果盲目死拉升降舵试图锁死高度，反而极易导致外侧机翼失速坠机。



### 总结

对于一台常见的、带有动力的手抛固定翼航模而言，在**安全、可控、不失速**的前提下，纯靠机翼升力实现的极限低速盘旋大体在 **20 km/h 到 30 km/h** 之间。如果追求极致的慢速，必须大幅减轻机电设备重量并极大地增加翅膀面积。



## ref 

