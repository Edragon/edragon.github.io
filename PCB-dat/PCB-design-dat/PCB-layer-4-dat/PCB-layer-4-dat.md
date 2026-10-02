
# PCB-layer-4-dat






- [[PCB-design-fanout-dat]] - [[PCB-design-dat]] - [[PCB-layer-4-dat]] - [[PCB-footprint-dat]] - [[QFN-dat]]



## tech 

- [[PCB-layer-4-dat]] - [[PCB-design-complex-dat]] - [[PCB-design-fanout-dat]] - [[PCB-design-routing-dat]] - [[PCB-design-dat]]

## build 

- [[PCB-layer-4-dat]] - [[MP9447-dat]]

- [[imx307-dat]]

- [[PCB-layer-4-dat]] - [[HI3516-dat]]



## HS signal in pure ground plane


简短的回答是：**从电气性能（阻抗和返回路径）的角度来看，这完全是可行的，而且在实际设计中经常会这样做；但从工程规范和风险管控的角度来看，它并不是最推荐的做法。**

如果一定要在内层地层中走少量高速信号，我们需要辩证地来看待它的利弊和适用条件：

### 1. 为什么说“可以这样做”？（积极的一面）
* **回流路径依然完整：** 只要地层没有被分割，高速信号在内层地层中穿行时，其**高频回流电流依然可以紧贴着上下（或同层周围）的参考地平面流动**，不会导致回流路径断裂或产生大的辐射环路。
* **阻抗可控：** 如果你通过计算控制好了线宽、介质厚度以及地平面的间距，使得单端阻抗（如 50Ω）或差分阻抗（如 100Ω）符合要求，信号的传输质量在理论上是有保障的。
* **数量少时的危害极低：** 如果只是 1 根或几根关键信号（比如某个必须跨区域的时钟或复位信号），由于它们对地平面的总体连续性破坏微乎其微，因此引发 EMI 或串扰的概率很低。


### 2. 为什么说“这并不是最推荐的做法”？（潜在风险）

* **破坏了地平面的“纯净性”（地弹与噪声耦合）：** 地平面（GND）不仅是信号的参考面，还是整个系统的 **0V 电位基准和屏蔽层**。如果直接在纯地层中“挖空”或布设信号线，信号线上的高频开关噪声（如数字跳变沿）会直接耦合进地平面，污染整个系统的地电位，进而影响周边的模拟电路或敏感芯片。
* **后期改板或维护的隐患：** 在 PCB 布局布线检查（DRC）或后期修改时，地层里藏有高速信号是非常隐蔽的。其他工程师（或未来的你）在后续对地平面进行调整、打孔或割切时，极其容易一不小心切断这根隐藏的高速信号，导致难以排查的故障。
* **过孔与回流转换的麻烦：** 高速信号如果要从表层切入内层地层，必然要打过孔（Via）。过孔会带来寄生电容和寄生电感，如果周围没有伴随足够的地过孔（Ground Via）来协助回流换层，信号质量会下降。


### 💡 最佳工程建议

在 4 层板设计中，如果你确实遇到了布线瓶颈，必须让少量高速信号走内层，请遵循以下原则：

1. **宁可走专属的内层信号区，也不要直接“沉入”纯地层：**
标准的 4 层板方案 A 中，第 3 层通常是电源/信号混合层。如果需要走高速线，尽量利用第 3 层，并确保它紧邻地平面。
2. **如果非要在地层走线，务必控制长度：**
让它仅仅作为短距离的“救急”跨越（比如几毫米到一两厘米），绝对不要长距离纵贯整个 PCB。
3. **严禁穿越敏感区域：**
这条高速信号绝不能从敏感的模拟电路、晶振（Crystal）下方，或者电源芯片的开关噪声源下方穿过。



## design 

关于你的经验：**顶层（Top Layer）和底层（Bottom Layer）用来走密集元器件的短距离连接，而内层用来走高速信号或稍长的布线**——这个直觉是非常准确且符合实际工程规范的。

对于标准的 **4层 PCB 叠层结构**（表层信号/元件层 - 地平面 - 电源/信号层 - 底层信号/元件层），以下为你总结更多核心规则与实用小贴士，帮助你进一步提升电路板的信号完整性（SI）和电磁兼容性（EMC）：

---

### 1. 地平面（GND Plane）的完整性：黄金法则

* **绝对不要分割地平面：** 在 4层板中，内层通常有一层是完整的地平面（例如 Layer 2）。**千万不要在这个地平面上随意切槽或走线**。如果把地平面割裂，高速信号的返回路径（Return Path）就会被迫绕远，从而产生巨大的电磁干扰（EMI）并导致信号反射。
* **跨分割线是大忌：** 任何高速信号（如时钟、USB、SPI、RF 等）的下方，绝对不能跨越地平面或电源平面的分割缝隙。

---

### 2. 推荐的 4 层板叠层方案

根据设计侧重点，常见的叠层主要有两种：

* **方案 A（最常见）：信号 - 地 - 电源 - 信号**
* *Top 层：* 元件 + 密集布线。
* *第 2 层：* **完整地平面（GND）**。这是最关键的一层，为 Top 层和 Bottom 层的信号提供紧密的参考平面。
* *第 3 层：* 电源平面（VCC）或混合布线。若布线，需注意避开电源噪声。
* *Bottom 层：* 元件 + 辅助布线。


* **方案 B（高速/低 EMI 优化）：信号 - 地 - 信号 - 地**
* *Top 层：* 信号 + 元件。
* *第 2 层：* 完整地平面（GND）。
* *第 3 层：* 关键高速/敏感信号布线层（紧邻地平面，参考好）。
* *Bottom 层：* 电源或次要布线层。这种方案的 EMI 性能通常比方案 A 更好。



---

### 3. 高速信号与长距离布线技巧

* **内层走线并非万能：** 内层虽然安全、不易被刮伤，但前提是必须有连续的参考平面（地或电源）伴随其左右。如果没有良好的参考平面，内层长距离走线的串扰和衰减反而会更严重。
* **阻抗控制（Controlled Impedance）：** 如果你需要做 50 欧姆单端或 100 欧姆差分阻抗控制，走线宽度需要根据介质厚度（Pre-preg 厚度）来计算。通常表层（Top/Bottom）走线较细，内层阻抗计算要结合叠层厚度向 PCB 厂家索取参数。

---

### 4. 电源与去耦电容布局

* **低阻抗电源：** 如果使用内层做电源平面（VCC），尽量用大面积的铜皮（Copper Pour）铺满，而不是用细线去连。
* **去耦电容就近打孔：** 所有的去耦电容（如 0.1µF、10µF）必须**紧挨着芯片的电源引脚**放置。电容的接地端不要拉长线，建议直接在焊盘旁打个过孔（Via）直通内层的 GND 平面，以减小回路电感。

---

### 5. 制造与焊接小贴士

* **热风焊盘（Thermal Relief）：** 连到内层大面积铜皮（地或电源）的焊盘，一定要设置成**热风焊盘（十字花焊盘）**。如果直接设为全连接（Solid Connection），内层的铜皮散热太快，会导致手焊或回流焊时温度不够，造成虚焊。
* **铜箔平衡（Copper Balancing）：** PCB 表面的铜皮分布要尽量均匀。如果一面铜多、一面铜少，板子在高温压合或回流焊时容易发生**翘曲（Warpage）**。



## specs 

- inner layer == 0.5 oz 


## lamination 

The typical lamination order for a 4-layer PCB is:

- Top Layer: Signal layer
- Inner Layer 1: Power plane (e.g., VCC or GND)
- Inner Layer 2: Ground plane (e.g., GND or VCC)
- Bottom Layer: Signal layer

### lamination order 

"4-layer PCB stack-up:

- Top Layer: Signal
- Inner Layer 1: Power (VCC)
- Inner Layer 2: Ground (GND)
- Bottom Layer: Signal

Please follow this lamination order for manufacturing."

### 🔄 Typical 4-Layer Stackup (Example)

| Layer | Purpose                     |
|-------|-----------------------------|
| L1    | Signal (High-speed / Logic) |
| L2    | Ground Plane                |
| L3    | Power Plane (3.3V, etc.)    |
| L4    | Signal (Slower or routing)  |

This stackup helps with:
- Good **signal integrity** (especially PCIe or USB lines)
- **Controlled impedance** for high-speed routing
- **Noise reduction** and **EMI compliance**

---

## ⚙️ Why Use 4 Layers?

| Reason                        | Explanation                                 |
|-------------------------------|---------------------------------------------|
| Signal integrity              | PCIe and USB need impedance control         |
| Power distribution            | Separate plane ensures clean power          |
| Ground return path            | Reduces EMI / crosstalk                     |
| Compact routing               | Easier routing in tight Mini PCIe space     |

---

## 🔧 Considerations

- Use **controlled impedance** (50Ω for USB, 85Ω diff for PCIe)
- Ensure **gold fingers** are ENIG plated and follow **Mini PCIe spec**
- Route high-speed signals on **L1 and L4**, with ground under them
- Place components only on the **top layer**, per Mini PCIe mechanical spec
- Follow PCI-SIG or Mini PCIe spec for **connector layout** and **keep-outs**





## ref 

- [[PCB-dat]]

- [[sensor-Camera-dat]]

- [[c]]