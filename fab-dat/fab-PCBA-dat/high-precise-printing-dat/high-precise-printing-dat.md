
# high-precise-printing-dat

- [[solder-bridging-dat]]

## 1. Stencil Thickness
- **Recommended**: 0.10 mm (4 mil) stainless steel
- Sometimes 0.12 mm (5 mil) can work, but **risk of bridging increases**
- Thinner stencil (4 mil) improves paste release for fine pitch

## 2. Aperture Design
- **Aperture width: ~0.20–0.22 mm** for SSOP16 etc (slightly smaller than 0.25–0.30 mm pad width)
- Length: ~1.3–1.5 mm (same as pad length, or 10–20% reduction to reduce paste volume)
- **Aperture reduction (shrinkage): ~90% of pad size is typical** (to avoid solder bridging)

## 3. Aperture Shape
- Rectangular with rounded corners
- Optionally “home-plate” shape to pull solder toward pad center

## 4. Fabrication Tolerances
- Laser-cut stainless steel stencil
- Electro-polished finish for smoother walls → better paste release
- Registration accuracy: ±12.5 µm typical

## 5. Paste Type
- Use Type 4 (20–38 µm) or Type 5 (15–25 µm) solder paste
- Finer powder improves print definition at 0.635 mm pitch

- [[solder-paste-dat]]

## 6. Aspect Ratio Rules

- Aperture width / stencil thickness ≥ 1.5
- Area ratio (aperture area / aperture wall area) ≥ 0.66
  → With 0.20 mm × 1.4 mm aperture and 0.10 mm stencil → Area ratio ≈ 0.71 ✅ (good)