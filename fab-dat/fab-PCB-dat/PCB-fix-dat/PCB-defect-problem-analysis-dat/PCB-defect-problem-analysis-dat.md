

# PCB-defect-problem-analysis-dat


## senario 1 

[[PCB-defect-problem-analysis-dat]] == [[flight-controller-dat]] - [[FC-AIO-dat]] - [[X12-dat]]


### no boot sound 

**电调设置了静音**
• 说明: BLHeli 里有 "Beacon/Silent" 设置项，可关闭启动音

**Beacon 寻机音**
• 有无: 手动触发
• 说明: 也是通过电机发声（DShot Beacon）

**电调初始化音**
• 有无: ✅ 有（默认）
• 说明: ⭐️ BLHeli 上电驱动电机发出的"哔哔哔"声

上电 → 电调上电自检 → 通过电机发"哔-哔-哔"（2S 通常 2-3 声）+ 启动音


### armed but no motor spin


### VTX channel can receive, but no video output from camera

camera keep black screen 





## ref





