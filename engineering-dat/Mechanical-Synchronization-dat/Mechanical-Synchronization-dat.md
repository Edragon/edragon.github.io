
# Mechanical-Synchronization-dat





✅ 方案 2：链条连接（⭐⭐⭐⭐）
前轴 ──[链轮]====链条====[链轮]── 后轴


适合：

扭矩大

越野车

缺点：

噪音

重

要润滑




✅ 方案 1：前后轴机械联动（最佳）

- [[belt-dat]]

Motor → 前轴 ==== 同步带 / 链条 ==== 后轴


✔ 前后绝对同步
✔ 一个电机即可
✔ 不需要编码器

这是最干净、最可靠的解法。

四、如果你暂时不能改结构（补救方案）
⚠️ 方案 2：前后轴机械联动 + 保留双电机（次优）
Motor A → 前轴
Motor B → 后轴
前轴 ==== 同步带 ==== 后轴


注意事项（很重要）：

同步带必须 略有弹性

电机必须 同型号

PWM 必须完全一致

不要用硬齿轮

👉 这是“互相容忍”，不是“真正同步”



## Synchronous Belt Drive / Chain Drive Coupling (⭐⭐⭐⭐⭐)

This method mechanically links the **front axle and rear axle** so they rotate at exactly the same speed, achieving true synchronization **without encoders or software control**. It is the most reliable solution for **geared DC motors** in small RC cars.

---

## 1. Principle of Operation

The front and rear wheel shafts are rigidly connected using a **timing belt** or **chain**, so that rotation of one shaft forces the other to rotate at the same angular speed.

Front Axle ──[Pulley/Sprocket]====Belt/Chain====[Pulley/Sprocket]── Rear Axle

Synchronization is guaranteed by physics rather than electronics.

---

## 2. Synchronous Belt Drive (Recommended)

### 2.1 Description
A toothed timing belt meshes with toothed pulleys on both axles, preventing slip and maintaining a fixed speed ratio (typically 1:1).

### 2.2 Common Belt Types
| Belt Type | Pitch | Typical Use Case |
|---------|------|------------------|
| GT2     | 2 mm | Lightweight, small robots |
| HTD 3M  | 3 mm | RC cars, moderate torque |
| HTD 5M  | 5 mm | Larger wheels, higher torque |

### 2.3 Advantages
- No slip (positive engagement)
- Quiet operation
- Low vibration
- Tolerant to small alignment errors
- Easy DIY implementation

### 2.4 Disadvantages
- Limited torque compared to chain
- Belt tension must be maintained

### 2.5 Design Notes
- Belt width: **6–10 mm** for small RC vehicles
- Pulley ratio: **1:1** for synchronization
- Include a **belt tensioner** or slotted mounting holes

---

## 3. Chain Drive Coupling

### 3.1 Description
A metal chain engages with sprockets on both axles, commonly used in high-load or off-road applications.

### 3.2 Common Chain Types
| Chain Type | Pitch | Typical Use Case |
|----------|------|------------------|
| 25H      | 6.35 mm | Small off-road vehicles |
| 06B     | 9.525 mm | Heavy-duty DIY builds |

### 3.3 Advantages
- Very high torque capacity
- Extremely durable
- No elastic deformation

### 3.4 Disadvantages
- Noisy
- Heavier than belts
- Requires lubrication
- Higher precision required in alignment

---

## 4. Structural Requirements (Critical)

### 4.1 Rigid Axle-to-Wheel Connection
Wheels **must not slip** on the axle.

Recommended shaft types:
- D-shaft
- Hex shaft
- Keyed shaft

Avoid:
- Friction-fit wheels
- Soft rubber hubs without locking

---

### 4.2 Tensioning Mechanism (Mandatory)

A belt or chain must always include a way to adjust tension:
- Slotted motor mount
- Idler pulley / idler sprocket
- Eccentric tension wheel

Without tensioning, wear and temperature changes will cause failure.

---

## 5. Motor Configuration Recommendation

### Best Practice
- **Use a single geared motor** to drive one axle
- Mechanically link the second axle via belt or chain

Motor → Gearbox → Front Axle ==== Belt/Chain ==== Rear Axle

### Why Not Two Motors?
- Motors fight each other
- Increased current draw
- Gearbox wear
- Reduced efficiency

---

## 6. When to Choose Which

| Scenario | Recommended Method |
|--------|-------------------|
| Small RC car / indoor | Synchronous belt |
| Outdoor / off-road | Chain drive |
| Quiet operation | Synchronous belt |
| Maximum torque | Chain drive |

---

## 7. Summary

- Mechanical coupling guarantees **perfect synchronization**
- No encoders or control algorithms required
- Synchronous belt drive is the best balance of simplicity, noise, and reliability
- Chain drive is suitable for extreme torque or harsh environments