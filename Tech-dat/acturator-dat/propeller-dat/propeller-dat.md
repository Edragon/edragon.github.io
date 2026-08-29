
# propeller-dat



- [[RC-kits-dat]]

- [[pump-dat]] - [[pump-jet-dat]] - [[propeller-dat]]


## propeller by apps 

- [[propeller-toy-boat-dat]] - [[propeller-dat]] - [[rc-boat-dat]] - [[acturator-dat]] 

- [[propeller-FPV-dat]] - [[propeller-dat]]



## propeller by function 

- [[propeller-tractor-dat]] - [[propeller-pusher-dat]] - [[propeller-dat]]


## propeller's specs

- [[propeller-KV-dat]] - [[propeller-disc-loading-dat]] - [[power-physics-dat]]

 


## 共轴双桨

DZP30共轴双桨无刷电机30克无反扭对转马达F3P 送双桨厂


## propeller options 

![](2025-09-13-13-55-01.png)

![](2025-09-13-13-56-08.png)



## Ground Effect

- When quad is close to surface → prop wash bounces air → airflow becomes turbulent  
- Creates unstable lift → drift or wobble sideways  

→ **PID Sensitivity**  
- Too high P/D gains → overreact in turbulence  
- Too low I gain → can't hold position → drift  

→ **Throttle Resolution**  
- Small throttle change indoors = big lift difference  
- Harder to keep steady near ground  



## prop wash 

### 📌 What is Prop Wash?

- Prop wash is the **turbulent/dirty air** created by a drone’s propellers.
- When the drone flies into this disturbed airflow, the flight controller struggles to stabilize, causing:
  - Wobbles
  - Vibrations
  - Shaky footage


### 🔍 Typical Signs
- Shaking after a quick throttle drop → sudden throttle punch.
- Jitter when coming out of sharp turns.
- Visible oscillations in blackbox logs.



## the number of the propeller

# Propeller Blade Count vs Flight Stability in FPV Drones

核心权衡：**效率 vs 推力密度 vs 尺寸限制**。

关键原理：更多叶 = 更多"桨面积"塞进更小直径 → 推力大但每片叶效率低（叶间气流干扰）。

### 物理规律对比

| 叶数     | 效率   | 推力 | 噪声 | 尺寸         |
| -------- | ------ | ---- | ---- | ------------ |
| **2 叶** | ✅ 最高 | 最低 | 小   | 需要大空间   |
| **3 叶** | 中     | 中   | 中   | 折中         |
| **4 叶** | 低     | 最高 | 大   | 塞得进小机身 |

### 各类桨叶详细对比

**2 叶桨（效率优先）**
- ✅ 每片叶独立工作，效率最高（省电续航长）；噪声小
- ❌ 同样直径下推力最小；需要大桨盘空间（机架要大）
- → 适用：固定翼、滑翔机、长航时、巡航机；户外速度、竞速
- → 例子：手抛机 8×4.5 二叶

**3 叶桨（均衡）**
- ✅ 推力比 2 叶 +30% 左右，直径不变；轴距限制下更紧凑；响应更细腻
- ❌ 效率比 2 叶低一点
- → 适用：绝大多数 5 寸穿越机、花飞、竞速、freestyle / cinewhoop
- → 例子：Mobula8（三叶）

**4 叶桨（推力密度优先）**
- ✅ 同样直径推力最大；极紧凑（圈圈机塞桨）
- ❌ 效率最低、噪声最大；更耗电、续航明显变短
- → 适用：TinyWhoop 圈圈机、需要最大推力的极小机、室内 FPV
- → 例子：Mobula7（四叶 40mm）

### 简单决策规则

- **固定翼/滑翔机（巡航）** → 2 叶（要效率、要续航，空间不受限）
- **穿越机（小轴距塞大桨）** → 3-4 叶（轴距限制，用叶数补推力）
- **竞速（求极速）** → 3 叶低螺距（加速快）
- **花飞（求暴力）** → 3-4 叶（需要瞬时推力）
- **TinyWhoop（极小机）** → 3-4 叶（小桨必须多叶才有推力）

### 关键决策逻辑

问题本质：你有多少空间（桨盘直径限制）？

- 空间大（固定翼/大机）→ 用 2 叶吃效率
- 空间小（穿越机轴距）→ 用 3-4 叶补推力

一句话公式：**推力需求 ÷ 可用桨盘直径 = 需要的叶数** —— 需求大、直径小 → 多叶；需求小、直径大 → 少叶。

### 你机队的具体选择

| 机型             | 桨叶 | 原因               |
| ---------------- | ---- | ------------------ |
| 手抛机（固定翼） | 2 叶 | 效率、续航、空间大 |
| Air65            | 3 叶 | 小机补推力         |
| Mobula8          | 3 叶 | 2 寸小桨           |
| Mobula7          | 4 叶 | 极小机最大推力     |
| 未来 5 寸        | 3 叶 | 花飞均衡           |

### 两个补充知识点

① 同尺寸下效率排序：2叶 > 3叶 > 4叶（同样直径）。但 4 叶可以用更小直径达到同样推力。

② 换叶数 = 换手感：
- 2叶 → 3叶：推力 +30%，响应更跟手，续航 -10%
- 3叶 → 2叶：更省电但手感"空"

### Indoor Recommendation
- **Best choice:** 3-blade or 4-blade props
- **Why:** 室内空间小 → 低速稳定与平滑控制更重要；4/5 叶"粘手"控制感更好，更易悬停与慢速移动；3 叶是稳定与效率的折中
- 👉 **室内练习/娱乐:** 用 **4-blade**（稳定与操控更好）
- 👉 **室内外混合:** 用 **3-blade**（性能均衡）

### 一句话总结

空间够用 2 叶吃效率（固定翼/巡航），空间受限用 3-4 叶补推力（穿越机/小机）。叶数 = 用"叶片数量"换"推力密度"——固定翼 2 叶、穿越机 3 叶、TinyWhoop 4 叶，就是这个逻辑。






## boat propeller

- [[rc-boat-dat]]

![](2025-12-04-00-15-42.png)


## ref 

- [[propeller]]

- [[SCU1059-dat]]

- [[FPV-dat]] 

- [[acturator]]