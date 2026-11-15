


# capacitor-y-dat

- [[capacitor-dat]] - [[capacitor-x2-dat]] - [[capacitor-y-dat]] - [[capacitor-x-y-dat]] - [[acdc-dat]]

## CY1 / CY2 on an AC-DC (SMPS) board: these are Y capacitors

On the PCB of an AC-DC power supply (switching power supply), components marked **CY1**, **CY2** (or C11, C12 and so on — the reference prefix is usually just `C`) are **Y capacitors**.

They are a class of safety capacitor, and they play a critical role in EMI / EMC suppression in the power circuit.

### 1. What is a Y capacitor?

A Y capacitor is typically a **ceramic capacitor**, and they usually come in pairs (most are blue or yellow disc-shaped ceramic plates). They are connected across specific points in the circuit:

- One end connects to the high-voltage AC mains side (for example **L (live)** or **N (neutral)**).
- The other end connects to **earth (PE / protective earth)**, or to the board's **isolated ground** (secondary low-voltage ground / across the boundary between hot ground and cold ground).

Because they sit directly between the high-voltage side and earth (or the low-voltage side), human safety depends on them. They must therefore have very high insulation and withstand-voltage performance, and must carry the safety approvals of the relevant countries (UL, VDE, CSA, etc.).

### 2. What CY1 and CY2 actually do in a power supply

In a switching power supply, CY1 and CY2 are usually connected between the high-voltage input (primary side) **and** the output (secondary side) — bridging the transformer isolation barrier — or from the input to earth. Their core functions are:

- **Suppressing common-mode noise:** while running, the internal high-frequency switching devices generate very high-frequency electromagnetic noise (EMI). If that noise escapes through the mains or radiates into space, it interferes with other electronic equipment. The Y capacitor provides a **return path** (bypass) for this high-frequency noise, so the interference is shunted back to earth or back around the loop, reducing emissions.
- **Bleeding off ESD and lightning surge energy:** it helps absorb and discharge transient high voltages that occasionally appear in the circuit (lightning-induced surges, static, etc.), protecting the sensitive ICs downstream.

### 3. Why are there usually two (CY1 and CY2)?

At the AC input (L and N), when going to earth or across the isolation barrier, Y capacitors are normally used **symmetrically as a pair**:

- One from live (L) to earth.
- One from neutral (N) to earth.
- This symmetric arrangement balances the impedance to earth, which suppresses symmetric common-mode noise more effectively.

### 4. Notes for repair and replacement

If you are troubleshooting a power-supply fault (for example the blown fuse or leakage mentioned earlier):

- **Never substitute an ordinary capacitor:** if CY1 or CY2 has failed (for example shorted through), you must **not** replace it with an ordinary ceramic capacitor or one with an insufficient voltage rating. You must use a dedicated capacitor bearing the **Y1 or Y2 safety approval mark**.
- **What happens if a Y capacitor shorts?** Once a Y capacitor breaks down and shorts, at best the SMPS output goes abnormal and EMI exceeds limits; at worst it couples the high-voltage AC directly onto the low-voltage output or the enclosure, creating a serious **electric-shock hazard** or destroying the downstream equipment.


二、 为什么有时候电路板上只有单个 CY1？
Y电容原本通常是成对出现的（比如对称地接在 L 对地、N 对地，或者初级地对次级地），用以平衡共模干扰。如果某些电源的 PCB 上只有单个 CY1，通常是由以下原因决定的：

双绝缘（Class II）设备无保护地（PE）：

像手机充电器、小型适配器这类设备，插头通常是两脚的（没有地线），内部也没有真实的“大地”。

此时的 Y 电容（通常被称为跨界/跨隔离带电容，常标为 CY1）并不是接在 L/N 对地，而是跨接在初级高压侧（热地）与次级低压侧（冷地）之间。它的作用是给高频开关噪声提供一条回流路径。为了满足 EMI 辐射标准，一颗经过精确计算容值的 Y 电容就已经足够。

EMI 辐射测试已经达标（成本与漏电流优化）：

每一个 Y 电容都会让微量的 50Hz/60Hz 市电电流通过并流向另一侧（即接触电流或泄漏电流）。安规对设备的漏电流有严格上限。

如果电路设计合理，通过优化变压器屏蔽层、合理配置共模电感和 X 电容，单颗 CY1 产生的噪声抑制效果就已经能让产品顺利通过 FCC / CE 的 EMI 认证，设计师就不会再盲目增加第二颗 Y 电容，从而节省成本并降低漏电流。

PCB 空间受限：

在一些极度紧凑的微型充电器（如氮化镓快充）中，空间极其有限。跨接在初次级之间的安规距离（Creepage / Clearance）要求非常严格，能容纳一颗高质量的 Y 电容（CY1）已经是极限，无法布局对称的两颗。

## ref 

