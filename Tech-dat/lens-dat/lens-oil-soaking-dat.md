# lens-oil-soaking-dat.md

This document explains the optical and mechanical consequences of oil/gel layers near lenses and sensors, and gives practical engineering recommendations for underwater or oil-compensated camera systems.

Contents
- Summary
- Removing a thick oil layer and keeping only glass
- Mineral oil between lens and sensor: why it is fatal
- Filling optical adhesive between lens and sensor: feasible?
- Air cavity for the lens while body is oil-filled: can it withstand pressure?
- Is an observation window inside an oil-filled space under pressure?
- Types of oil‑compensated cameras (industrial vs consumer)
- Recommended and not-recommended engineering solutions
- Quick checklist


## Summary (short)
- Mineral oil or optical adhesive in the image space (between lens and sensor) breaks lens design assumptions and is almost always catastrophic for image quality — especially for very fast lenses (e.g., F1.0).
- Removing large oil layers in front of the lens and keeping only a glass window greatly reduces focus shift; glass behaves predictably while liquid layers introduce temperature-dependent refractive changes.
- Proper oil‑compensated designs either make the optical system natively liquid‑matched or keep sensitive image-side volumes as controlled, small, pressure‑compensated air cavities.



## 材料选择 


一、先给结论（不看推导也能用）
✅ 小型潜水器观测窗，优先选：亚克力（PMMA）

原因：

抗压强度高（尤其是厚板）

破坏前会明显变形，不是瞬间爆裂（安全性高）

水下长期使用成熟（载人潜水器、ROV 都用）

光学性能足够好（不是普通塑料）

❌ 普通玻璃不推荐

脆性材料

容易突然碎裂

即使是钢化玻璃，水下承压可靠性也差

二、你这个空气腔是否承压？（重要）

如果是这种结构👇：

海水
↓
[观测窗]
↓
[空气腔]


那么：

✅ 观测窗是完全承压的
❌ 空气腔并不会“因为体积小就不承压”

承压大小 只取决于水深，与空气腔体积无关。

三、按常见深度直接给你厚度建议

我假设你的观测窗是平面圆形或方形，边缘刚性固定。

🔹 参考条件（你若不同可再算）

窗口有效尺寸：直径 / 边长 ≈ 100–130 mm

空气腔：常压

安全系数 ≥ 2

四、不同材料 + 深度对应厚度（工程经验值）
✅ 亚克力（PMMA）
下潜深度	水压	建议最小厚度
30 m	4 bar	8–10 mm
50 m	6 bar	12–15 mm
100 m	11 bar	20–25 mm
150 m	16 bar	30 mm+

👉 推荐：
如果你之前提过的 100 m 深度，
亚克力 ≥ 25 mm，非常稳妥

❌ 普通玻璃（即使钢化）
深度	风险
30 m	勉强可用
50 m	高风险
100 m	❌ 不建议

玻璃的理论强度高，但微裂纹 + 应力集中 = 突然碎裂

五、窗口形状对厚度影响巨大（重要）
平面窗（你现在假设的）

承压最差

厚度必须大

球面 / 半球面窗

同样深度，厚度可减少 40–60%

工程上最推荐

👉 如果你愿意用半球亚克力罩，
100 m 深度 15–18 mm 就够

六、安装方式比材料还重要

必须做到：

周边全周受力

O 型圈密封

避免点接触

亚克力边缘倒角 ≥ R2

七、直接给你一句“能照着做的方案”

20×20×20 cm 空气腔，单面观测窗，目标 100 m：
✅ 材料：铸造亚克力（PMMA）
✅ 形状：平面
✅ 尺寸：≤130 mm
✅ 厚度：25 mm
✅ 安装：法兰 + O 型圈



## Removing a thick oil layer and keeping only glass — is it enough?
Conclusion: In most cases yes — removing a thick oil layer is a very effective fix. It reduces equivalent optical path massively and converts severe defocus into something often recoverable by refocus. However, very thick glass still degrades performance.

Why it helps
- Example equivalent optical path (approximate):
  - Mineral oil 10 cm × n≈1.47 ≈ 14.7 cm air-equivalent
  - Glass 5 cm × n≈1.50 ≈ 7.5 cm air-equivalent
  - Combined ≈ 22 cm air-equivalent
- Removing the oil leaves ≈7.5 cm equivalent, a >2/3 reduction, often bringing the system back into a compensable range.
- Glass is a predictable single refracting element; a liquid layer creates multiple refractive interfaces and temperature-sensitive index changes.

Practical results by glass thickness
- Glass ≤ 10 mm: almost no problem; manual focus compensates; image quality close to air use.
- Glass 10–20 mm: usable with refocus; possible mild edge aberrations; shallow DOF on very fast lenses.
- Glass ≈ 50 mm: still problematic for fast lenses (F1.0); center may be acceptable, edges likely blurred; not recommended.

Recommended implementation if you must keep glass
- Use optical flat glass 5–10 mm thick (optical-quality, tempered if needed).
- High parallelism and surface quality.
- Place the glass close to the lens (minimize the air gap).


## Is mineral oil between lens and sensor a problem?
Short answer: Yes. It is very serious and usually fatal for normal camera lenses.

Why it's fatal
- Most lenses are designed assuming air (n≈1.00) on the image side. Replacing that with oil (n≈1.47) changes the effective back focal distance roughly by the refractive index ratio and invalidates aberration correction.
- Focus mechanisms move lens groups but cannot reconfigure the lens' internal aberration corrections for a different image-space medium.
- Very fast lenses (large aperture, steep chief rays) are extremely sensitive — results include severe central defocus, smeared edges, increased chromatic and comatic aberrations.

Only legitimate exception
- Optics specifically designed for liquid immersion (e.g., oil‑immersion microscope objectives or industrial lenses that use optical adhesive by design). These designs assume the image‑side refractive index in the optical model from the start.

Immediate practical actions
- Prevent mineral oil from entering: lens rear cover, IR-cut to sensor gap, and sensor cover glass.
- Even thin layers (<1 mm) can introduce unpredictable aberrations and temperature-dependent focus shift.

Correct optical stack (recommended)
- Target → object medium (air/water/other)
- Optical flat window (5–10 mm glass)
- Air gap
- Lens
- Air gap
- Sensor

Forbidden stack
- Target → Lens → Mineral oil → Sensor

One-line conclusion
- Mineral oil in the image space destroys the optical design assumptions; do not allow it.


## Can you fill optical adhesive between lens and sensor to seal the cavity?
Short answer: Generally no — do not fill the lens‑to‑sensor space with optical glue unless the lens was designed for that medium from the start.

Why not
- Typical optical adhesives/UV glues have refractive indices n ≈ 1.46–1.52 (very different from air n≈1.00). This changes rear focal geometry and aberration balance in a non-compensable way.
- Focus adjustments move groups but do not re-calculate the optical model; they cannot restore correct aberration correction when the image-side medium changes.
- For F1.0 lenses the tolerance is essentially zero: center may be barely visible while edges are smeared and contrast drops; IR-cut filters and microlenses can be affected.

Where optical glue is appropriate
- Lens element bonding (designed doublets/triplets) — glue is part of the original optical design.
- Sensor package internal bonding (cover glass, microlens glue) — factory-specified.
- Oil-immersion microscope objectives or optics designed with liquid coupling from the start.

Engineering alternatives (recommended)
- Option A (recommended): Put the sealing layer in front of the lens:
  - External medium → optical flat glass window (5–10 mm) → air → lens → air → sensor.
  - Advantages: predictable optics, refocusable, industrial standard for underwater cameras.
- Option B: Pot the lens front-end (make lens front oil-resistant) but keep the lens rear and sensor in sealed air using O‑rings and metal housings.

Clear rule of thumb
- If the lens design documentation does not explicitly state "image-side medium = optical adhesive / fluid", do not fill the image space with glue or oil.

One-line conclusion
- Optical adhesive is only safe where the optical design expects it; using it as an after-the-fact seal between lens and sensor will almost certainly ruin imaging.


## My vessel is oil‑filled but the lens section retains an air cavity—can it withstand pressure?
Short answer: Yes, if designed correctly. Many ROV/underwater camera systems use oil-filled electronics and a small pressure-resistant air cavity for optics.

Key points
- The air cavity does not "support" pressure; the observation window (glass or acrylic) and its seat carry the structural load. Air is compressible and simply reduces in volume under pressure.
- Air compression is acceptable if the cavity and mechanical parts are designed to tolerate the change (e.g., lens mounts, focus mechanisms, and any internal electronics that must remain functional).

Four critical checks for the air cavity
1) The window, not the air, carries the load. Design window thickness and support accordingly.
2) Air compression is normal; e.g., at 50 m depth (≈6 atm) the air volume is ~1/6 of surface volume.
3) Dangerous failure modes are thin windows, wrong seal groove geometry, large window area, and trapped gases or bubbles.
4) Smaller internal air volumes (lens close to window) reduce deformation impact on imaging and reduce required window stiffness.

Sizing example (illustrative)
- Window diameter 40 mm at 50 m (~0.5 MPa) sees force ≈ 628 N (~64 kgf). The window structure must resist this load.

Design recommendations for pressure-bearing windows
- Materials: tempered optical glass, acrylic (PMMA), or fused silica for best optical/strength tradeoff.
- Thickness guidance: 30–50 m depth → ≥10–15 mm; 100 m → ≥20–25 mm (quartz can be slightly thinner).
- Shapes: thick flat windows (simple) or outward convex domes (stronger but harder to process).
- Seals: O‑ring positioned so external pressure causes the window to seat tighter (face/axial seals) rather than pull out.
- Internal layout: keep lens close to the window; minimize internal air volume.

One-line answer
- What bears pressure is the window and its seat. If window thickness, seal, and area are correct, a small air cavity for the lens/sensor is a standard, safe approach.


## Is my observation window inside an oil-filled space under pressure? Does it bear pressure?
Conclusion: If the observation window is located inside an oil-filled compensation space and both sides of the window are filled with the same liquid (oil), then the window sees almost no net pressure (only small differential pressure) — provided the compensation system is correct.

Why
- In a pressure-compensated oil space the external water pressure is transmitted through the enclosing shell into the oil. If the oil in front and behind the window is at the same pressure, ΔP ≈ 0 and the window is not structurally loaded by hydrostatic pressure.

Critical conditions you must satisfy
1) The oil space must be free of trapped air or isolated gas pockets (no compressible inclusions).
2) Window front and back must be in the same connected oil volume or actively pressure-balanced.
3) Thermal expansion of oil must be handled (flexible compensator bladder, piston, or similar) to avoid accidental differential pressure.

Engineering consequence
- If the above conditions hold, the window only needs mechanical stiffness for handling, sealing, and optical flatness — not deep-water structural thickness.


## Types of oil‑compensated cameras and real-world examples
Real oil-compensated cameras fall into a few categories — all follow one of three rules: electronics oil-immersed but optics isolated; optics designed for liquid coupling; or air cavities that are pressure compensated.

Industrial / commercial examples
- Deep-sea ROV/AUV cameras (Teledyne, Kongsberg, Saab, DSPL, Blueprint Subsea): typical structure uses oil for pressure compensation; the optical window is the only major pressure-bearing element. Some designs oil-immerse electronics and partially the front of optics while keeping the sensor in a small sealed air cavity.
- Subsea optical sensors with oil-immersed CMOS: PCB, CMOS, and power modules immersed in oil; imaging performed through thick quartz or fiber windows.
- Oil-immersion microscope objectives and specialized industrial optics: designed from the start with liquid coupling (n≈1.5) in the optical model.

Semi-industrial / DIY approaches
- Oil compensation for electronics + small pressure-resistant lens compartment: common in DIY ROV and lab conversions; high success if window and small air cavity are engineered correctly.
- Full oil immersion of a bare CMOS module: rare experimental setups; limitations include fixed focus, uncontrollable aberration, and damaged microlenses or IR filters.

Consumer products to not confuse with oil compensation
- Action cameras (GoPro, DJI): pressure-rated sealed air housings, not oil compensation — limited depth.
- IP67/IP68 rated CCTV: ingress protection rating not equivalent to pressure compensation for deep submersion.


## Recommended structure (matching industrial practice)
Most robust pattern for your described needs:
- Sea water → Outer hull → Oil-filled compensation volume → Optical window (non-load-bearing or minimally loaded if correctly balanced) → Lens front (can be oil-immersed) → Lens rear + CMOS in small sealed air cavity (pressure-resistant or compensated)

Design rules
- Do not rely on oil to "wrap" an air cavity to avoid designing a proper pressure-bearing window. Either remove the air or design the air cavity to be pressure-compensated.
- If the optical window separates oil and air, design the window to bear the appropriate differential pressure.


## Quick engineering checklist
- Prevent oil ingress into image space (lens rear, IR-cut gap, sensor surface).
- If using an oil-filled compensation volume, ensure no trapped air pockets and include a thermal compensator (bladder/piston).
- Use optical flat glass 5–10 mm if you must keep only a glass barrier.
- If you need an air cavity, minimize its volume and keep the lens as close to the window as practical.
- Design observation window thickness and seal according to depth, material, and shape (flat vs dome).
- Avoid filling the image-side cavity with optical glue/oil unless the lens was explicitly designed for that medium.


## Final one-line engineering summary
Oil can be a powerful pressure-compensation tool, but it must be used according to optical and mechanical design principles: either make the optics natively liquid-coupled, or keep the image-side air cavity small and properly pressure-rated/compensated. Never introduce oil or glue into the image space of a lens that was designed for air.