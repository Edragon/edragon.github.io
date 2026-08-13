
# DJI-neo-dat.md


- [[DJI-neo-dat]] - [[DJI-dat]] - [[DJI-quadcopter-dat]]

- [[vision-dat]] - [[vision-FPV-dat]] - [[position-hold-dat]] - [[DJI-neo-dat]] - [[DJI-dat]] - [[DJI-quadcopter-dat]]






## vision 


- [[location-dat]] - [[IMU-dat]] - [[sensor-barometer-dat]] - [[sensor-motion-dat]]


DJI Neo 作为一款主打轻量掌上起降和跟随拍摄的无人机，其定位系统与传感器配置以**满足基础稳定悬停与近距离视觉跟踪**为主，并未配备高级的多向避障传感器。

---

### **1. 定位与导航系统**

* **GNSS 多卫星定位系统**
* **支持系统**：GPS + 北斗（BeiDou） + 伽利略（Galileo）。
* **作用**：主要用于室外环境下的绝对位置定位、自动返航（RTH）以及维持高空悬停稳定。


* **下方视觉与红外定位系统（Downward Sensing System）**
* **硬件组成**：底部搭载单目视觉摄像头与红外测距模块。
* **精确测距范围**：0.5 米至 10 米。
* **作用**：
* 提供无 GPS 信号（如室内）时的定高与精准悬停能力。
* 实现掌上起降（Palm Launch / Landing）的智能识别与贴合操控。


### **2. 姿态与控制传感器**

* **IMU（惯性测量单元）**
* **组成**：三轴加速度计 + 三轴陀螺仪。
* **作用**：实时监测机身的角度变化、倾斜与运动速度，是飞行控制和姿态平稳的基础。


* **气压计（Barometer）**
* **作用**：辅助测量气压变化，用于无人机在飞行过程中的垂直高度粗略测量与保持。

### **3. 影像与智能跟踪传感器**

* **主摄 CMOS 传感器**
* **规格**：1/2 英寸图像传感器。
* **作用**：除了常规拍摄（4K/30fps 视频与 1200 万像素照片）外，它也是 **AI 人像跟随与智能拍摄（QuickShots）** 的核心视觉数据来源，结合算法实现自动跟踪目标。


* **云台传感器**
* **规格**：单轴机械云台（俯仰轴控制）。
* **作用**：监测并控制镜头的上下俯仰角度，配合 EIS 电子增稳算法（超强增稳/地平校正）保持画面稳定。




## hack 

### motor

- [[motor-FPV-dat]] - [[DJI-neo-dat]]

DJI NEO mod with 1103 motors, 11000KV, includes one set of props, no errors, full set 400 RMB, mail-in mod. Motors only: 4 for 300 RMB.

DJI NEO mod with 1103 motors, 9800KV.

Reduces prop wash, almost no sudden spinouts.

Price shown is for one pack of Qianfeng D51 props.

4 original Happymodel EX1103 11000KV brushless motors: 230 RMB.

Mail-in mod set: 4 motors + props + 150 RMB labor, total 388 RMB shipped.

After mod: 50% more power, max speed 78.6 km/h (with tailwind). Hover time with stock battery: 11m17s (stock motors: 13m10s). Mod uses more power.

Freestyle flight with stock battery: 7m11s,





## ref 


