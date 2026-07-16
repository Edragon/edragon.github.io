

# fab-joining-dat

- [[glue-dat]] - [[fab-joining-dat]] - [[fab-product-dat]] 
  
- [[rivet-dat]]

- [[brazing-dat]] - [[metal-welding-dat]]


## summary 

| Method / Joint Type | Peak Tensile Strength | Primary Joining Mechanism | Best Suited For | Key Weakness |
| :--- | :--- | :--- | :--- | :--- |
| **Metal Welding** | **Absolute Maximum** ($\ge 400 \text{ MPa}$) | Co-melting & fusion of base metals | Structural steel, heavy machinery, high-pressure pipes | Extreme heat warping, difficult on dissimilar metals |
| **Brazing** | **Very High to Supreme** ($\ge 150 \text{ MPa}$) | Capillary action of high-temp filler | Dissimilar metals, copper pipes, radiator cores | Requires microscopic fit-up tolerances |
| **Riveting** | **Extremely High** ($\ge 150 \text{ MPa}$) | Mechanical interlocking & clamping | Aircraft fuselages, bridges, non-weldable alloys | Heavy, requires drilling, not naturally leak-proof |
| **Soldering** | **Moderate** ($\sim 50 \text{ MPa}$) | Capillary action of low-temp filler | Electronics, PCB assembly, copper plumbing | Weak mechanical load capacity |
| **Aviation Adhesives** | **High** ($\sim 45 \text{ MPa}$) | Advanced chemical cross-linking | Aerospace panels, modern automotive bodies | Demanding surface prep, long cure times |
| **AB Glue (Epoxy)** | **High (Structural)** ($\ge 30 \text{ MPa}$) | Chemical reaction polymerization | General rigid repairs, gap filling, hobbyist metal | Brittle, zero elasticity |
| **UV Glue** | **Extremely High** ($\ge 20 \text{ MPa}$) | Photo-initiated polymerization | Glass-to-metal, clear acrylics, rapid repairs | Requires UV light pathway to cure |
| **502 Glue (Super)** | **Very High** ($\sim 20 \text{ MPa}$) | Moisture-activated polymerization | Small, tight-fitting non-porous repairs | Poor impact resistance (shatters easily) |
| **B-7000** | **Medium** ($\sim 3 \text{ MPa}$) | Solvent evaporation (elastic polymer) | Phone screens, flexible joints, vibration damping | Low static load limit (creeps under weight) |
| **Hot Melt** | **Lowest** ($\sim 1 \text{ MPa}$) | Physical cooling solidification | Quick crafts, temporary holding, soft materials | Melts under mild heat, poor adhesion to metals |


## list 

* **Metal Welding: *The True Fusion Benchmark***
    * **Tensile Strength:** **Absolute Maximum.** Depending on the metal filler rod and base material (e.g., mild steel), welding easily achieves tensile strengths of **400 to 550+ MPa** ($58,000 \text{ to } 80,000+ \text{ psi}$).
    * **Behavior under load:** It does not merely stick two parts together; it melts them into a single, continuous piece of metal. The welded joint is chemically, molecularly, and physically integrated, often making the weld itself stronger than the surrounding base metal.
    * **Weakness:** Requires specialized machinery, intense heat, safety gear, and alters the properties of the material permanently (creates a Heat-Affected Zone).
  
* **Brazing (钎焊): *The High-Strength Capillary Cousin***
    * **How it works:** Similar to welding, but instead of melting the base metals, you heat them just below their melting point and introduce a filler metal (typically brass, bronze, or silver alloy) with a melting point above 450°C (840°F). Capillary action draws the liquid filler into the microscopic gap between the tight-fitting parts.
    * **Tensile Strength:** **Very High to Supreme.** Typically **100 to 350+ MPa** ($14,500 \text{ to } 50,000+ \text{ psi}$), depending on the clearance and filler alloy.
    * **Pros vs. Welding:** Can easily join dissimilar metals (e.g., copper to steel) and produces highly ductile, leak-proof joints with minimal thermal distortion.
    * **Cons:** Requires extremely tight tolerances (gaps of 0.05 to 0.1 mm) and pristine surface cleanliness.

* **Riveting (铆接): *The Mechanical Giant***
    * **How it works:** A mechanical fastening method where a metal pin (rivet) is inserted through pre-drilled holes in the overlapping sheets and then deformed (squeezed or hammered) on the other end to lock the plates together permanently.
    * **Tensile Strength:** **Extremely High.** Standard structural steel rivets hold shear and tensile strengths of **150 to 300+ MPa** ($21,000 \text{ to } 43,000+ \text{ psi}$).
    * **Pros vs. Welding:** Absolutely zero heat is introduced, meaning no thermal warping, no changes to the metal’s crystalline structure, and no risk of cracking. This is why aircraft wings and historical steel bridges (like the Golden Gate) are riveted rather than welded.
    * **Cons:** Adds physical weight, requires drilling holes (which can introduce stress concentration points), and is not naturally air- or water-tight without separate sealants.

* **Soldering (软钎焊): *The Precision Electrical Bond***
    * **How it works:** Similar to brazing, but the filler metal (lead-free tin alloys) melts at a much lower temperature—below 450°C (typically around 180°C to 250°C). 
    * **Tensile Strength:** **Low to Moderate.** Typically **30 to 80 MPa** ($4,300 \text{ to } 11,600 \text{ psi}$).
    * **Pros vs. Welding:** Very low heat, highly conductive, and easily reversible. Perfect for securing electrical components on PCBs and joining copper plumbing pipes.
    * **Cons:** Poor structural load capacity; cannot be relied upon to hold heavy weight or withstand severe mechanical stress.

* **Aviation-Grade Structural Adhesives (航空级结构胶): *The Chemical Weld***
    * **How it works:** Specialized, high-performance polyurethanes, modified epoxies, or acrylics. They are engineered to chemically bite into the surface molecules of metals and composites.
    * **Tensile Strength:** **Very High (for Adhesives).** **35 to 55+ MPa** ($5,000 \text{ to } 8,000+ \text{ psi}$).
    * **Pros vs. Welding:** Distributes stress uniformly across the entire bonded surface area rather than focusing it at a single weld seam or rivet point. It also dampens acoustics, prevents galvanic corrosion between dissimilar metals (like carbon fiber to aluminum), and is widely used in modern hypercars and commercial jets.
    * **Cons:** Demanding surface preparation is required, and it requires hours to cure.



## metal joining 

在金属连接工艺中，**熔焊（Welding）**、**硬钎焊（Brazing）**和**软钎焊（Soldering）**是三种最核心的工艺。

它们最根本的区别可以总结为两点：**“母材（被连接的金属）熔不熔化”** 以及 **“工作温度是多少”**。



---

### 1. 核心概念拆解

#### 1. 熔焊 (Metal Welding) —— “彻底融为一体”
* **原理**：通过极高的温度，将**两块母材的接触面直接熔化**，同时通常会加入熔化的焊条/焊丝，让它们在液态下混合。冷却后，两块金属在原子层面上融合成了一个整体。
* **温度**：极高，通常在 **1000°C 至 3000°C 以上**（必须达到母材的熔点）。
* **特点**：
    * **强度最高**：接头强度等同于、甚至超过母材本身。
    * **永久变形**：由于局部高温，金属容易发生热变形或产生内应力。
    * **无法拆卸**：一旦焊接，除非破坏金属本身，否则无法分离。
    * **适用场景**：钢结构、造船、汽车车架、压力容器等重工业。

#### 2. 钎焊 / 硬钎焊 (Brazing) —— “强力胶水渗透”
* **原理**：**母材完全不熔化**。将母材加热到低于其熔点、但高于钎料熔点的温度。把熔点较低的“钎料”（如铜合金、银合金）熔化，利用**毛细管作用**让液态钎料自动吸入两块母材之间极小的缝隙中，冷却后实现连接。
* **温度**：中高，定义在 **450°C 以上**（通常在 600°C 至 900°C 之间），但必须低于母材熔点。
* **特点**：
    * **异种金属连接**：可以完美连接两种完全不同的金属（如铜和铁、硬质合金和钢）。
    * **变形极小**：因为不需要熔化母材，整体受热均匀，精密零件不易变形。
    * **接头美观**：焊缝极其平整、光滑。
    * **适用场景**：自行车车架、冰箱空调的铜管连接、高档刀具镶齿、航空精密零部件。

#### 3. 软钎焊 / 锡焊 (Soldering) —— “精密导电连接”
* **原理**：与硬钎焊（Brazing）的原理完全相同（**母材不熔化**，靠毛细管作用填充缝隙），唯一的区别在于**使用的焊料熔点较低**，最常用的焊料是锡基合金（俗称焊锡）。
* **温度**：较低，定义在 **450°C 以下**（通常在 180°C 至 300°C 之间）。
* **特点**：
    * **热影响极小**：极低的温度不会损坏敏感的电子元器件。
    * **导电性极佳**：主要用于建立电气连接，而不是为了承受重载。
    * **易于拆卸**：用烙铁重新加热即可熔化焊锡，轻松拆卸和维修。
    * **适用场景**：电子电路板（PCB）组装、芯片焊接、精细珠宝加工、铜管管道连接（水管）。

---

### 2. 核心区别直观对比表

| 特性 | 熔焊 (Welding) | 钎焊 / 硬钎焊 (Brazing) | 软钎焊 / 锡焊 (Soldering) |
| :--- | :--- | :--- | :--- |
| **母材是否熔化** | **是** (完全熔化) | **否** (保持固体状态) | **否** (保持固体状态) |
| **工作温度** | **极高** (高于母材熔点，>1000°C) | **中高** (高于450°C，低于母材熔点) | **较低** (低于450°C，通常180°C - 300°C) |
| **常用填充材料** | 钢、铝、不锈钢等焊条/焊丝 | 铜合金、银合金、铝硅合金等 | 锡铅合金、无铅锡银铜合金 (焊锡) |
| **接头强度** | **极高** (等同或超过母材) | **高** (可承受相当大的压力/拉力) | **低** (主要用于导电或密封，不承重) |
| **装配间隙要求**| 无严格要求，可填大缝 | **极严格** (通常要求 0.05 - 0.1 mm) | **严格** (依靠毛细管吸入) |
| **热变形程度** | **严重** (局部高温易变形) | **微小** (整体或局部中温，变形小) | **极微** (不损坏电子元件) |
| **主要应用** | 重工业、建筑、管道、钢结构 | 暖通铜管、刀具、异种金属连接 | 电子电路板、电器维修、精密仪器 |

---

> **💡 一句话总结记忆法：**
> * **熔焊**：把两块金属的边缘直接烧化捏成一坨，力大砖飞，强度最高。
> * **硬钎焊**：用高温把“硬铜/银”熔成液体，吸进两块不熔化的金属缝里，适合精密异种金属连接。
> * **软钎焊**：用低温烙铁把“锡”熔化，把电子元件粘在电路板上，主打导电和好拆卸。


## ref 

