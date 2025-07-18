
# radar-sensor-dat

- [[RCWL-sensor-dat]] - [[SMO1090-dat]]

**A radar sensor** uses radio waves to detect objects, measure their distance, speed, and direction. It works well in various weather and lighting conditions and is commonly used in automotive, industrial, and security applications.

**A lidar sensor** uses laser light to measure distances by emitting pulses and detecting their reflections. It creates high-resolution 3D maps of environments and is widely used in autonomous vehicles, robotics, and mapping. Lidar is more precise for shape and surface detection but can be affected by weather and lighting.


## radar sensor 

the coverage 

![](2025-07-18-16-32-53.png)

![](2025-07-18-16-33-15.png)



## FMCW Radar 

millimeter wave radar == 毫米波雷达

-频率：24G-24.25GHz
-扫频带宽：25OMHz(符合CE/FCC认证标准)
-调制方式：FMCW
-探测角度：±60°
-检测距离：存在&微动5m/运动7m(Typ.)
-距离分辨率：0.15m(Typ.)
-供电电压：3.3V(Typ.)
-外形尺寸：20×20mm
-环境温度：-40C~+85°℃
-数据格式：串口ASCII输出
-接口形式：默认2.54mm×5Pin


Here’s a comparison between RCWL and FMCW radar sensors:

RCWL (e.g., RCWL-0516) is a low-cost microwave motion sensor, typically using Doppler radar at 3.2GHz. It detects motion by measuring changes in reflected waves, but cannot measure distance or speed precisely. It’s mainly used for simple motion detection (e.g., lighting, alarms).

FMCW (Frequency Modulated Continuous Wave) millimeter wave radar (e.g., LD2402) operates at higher frequencies (24GHz). It emits a frequency-modulated signal and analyzes the frequency shift of the reflected wave to measure distance, speed, and even detect micro-movements. FMCW radars are more advanced, offering precise range and velocity detection, and are used in automotive, industrial, and security applications.

Summary:

RCWL: Simple, cheap, motion detection only, no distance/speed info.
FMCW: Advanced, precise, detects distance, speed, and micro-movements.



## ref 

- [[motion-sensor-dat]]