
# PCB-fix-dat


## app fixing 

- [[PCB-fix-dat]] - [[X12-dat]]





## FIX scenario 

compare 1 - [[X12-dat]] - [[PCB-fix-dat]] - [[FPV-fix-dat]]



broken - [[inductor-dat]] - [[capacitor-dat]]

![](2026-09-16-21-35-46.png)

broken 2 

![](2026-09-17-03-33-13.png)

- [[FC-AIO-dat]] - [[ESC-dat]] - [[X12-dat]] - [[test-point-dat]] == pin 4 (VCC) and 5 

- [[PCB-thermal-error-dat]] - [[VTX-dat]] == 75C



## tools 

- [[multimeter-dat]]


## issue detect 

important step 

analysis issues - [[PCB-defect-problem-analysis-dat]]

software check - [[betaflight-dat]] - [[PCB-fix-dat]]  - [[betaflight-motors-dat]]


by visual 

**Bright light + magnifier / phone macro lens**
• What to look for: trace cracks, lifted pads, solder-bridge shorts
• Tip: shine light at a low angle — cracks will reflect

**Backside inspection**
• What to look for: board-layer cracks (impact damage)
• Tip: hold against a strong light — light passes through abnormally at cracks

**Oblique viewing**
• What to look for: cold joints / poor soldering
• Tip: a good joint is a smooth cone; a bad joint looks dull and has a crack ring

**Alcohol test**
• What to look for: hairline cracks
• Tip: apply alcohol — cracks will show up

**Comparison method**
• What to look for: compare against a known-good board of the same model
• Tip: differences in resistance readings and appearance

by tools == multimeter 

- [[mosfet-dat]] == short/thermal 

- [[motor-brushless-dat]] - resistance

- [[power-BEC-dat]] - power-supply

- [[VBAT-dat]] - resistance-range - resistance

- [[ESC-dat]] - thermal/power-supply

- [[MCU-dat]] - power-supply

- [[chip-dat]] - [[power-dat]]




## other concern and methods 

- [[software-dat]] - [[SDK-dat]]


- [[PCB-fix-dat]] - [[PCB-error-dat]] - [[circuits-short-dat]]



- [[PCB-mechanical-error-dat]] - [[fab-mechanics-dat]] - [[PCB-fix-dat]] - 

- [[PCB-signal-error-dat]] - [[signal-dat]] - [[PCB-fix-dat]]

- [[PCB-thermal-error-dat]] - [[PCB-fix-dat]] - [[thermal-dat]]


## workflow

1. 目视（放大镜找裂纹/烧痕）
2. 酒精蒸发法找发热元件 ⭐️
3. 通断测试查走线
4. 按压测试查虚焊
5. 可疑焊点热风枪补焊 → 复测

extra workflow

- examine the output of the power tree from [[dcdc-down-dat]] - [[LDO-dat]] 





## difficulties 

- [[BGA-dat]] 




## edit 

- [[PCB-cutter-dat]]

### mess editing 

- also suitable for single trace editing 
- Use a drill to make non-through holes to break PCB traces
- fast for large batch fixing 



## ref 

- [[PCB-dat]] - [[circuits-dat]]

