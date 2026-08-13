
# sensor-proximity-dat






## board 

- [[SMO1085-dat]]




## sensor proximity 




**2. 垂直高度控制：测距传感器（TOF / 红外 / 超声波）**

* **原理**：光流只能算出“相对像素移动”，无法得知机身与地面的绝对距离（同样移动 10 像素，在 1 米高度和 10 米高度对应的实际位移截然不同）。
* **协作**：底部的红外/TOF（飞行时间）测距传感器或超声波模块会向下发射信号并接收反射波，精准测出当前离地高度（通常为 0.1–10 米内）。
* **反馈**：测距数据用于给光流算法提供**高度比例尺（Scale）**，同时协助气压计实现精确的垂直定高与降落缓冲。

- [[sensor-lidar-dat]] - [[sensor-pir-dat]] - [[sensor-ultrasonic-dat]] - [[sensor-TOF-dat]] - [[sensor-infrared-dat]]

- [[sensor-radar-dat]] - [[sensor-radar-Millimeter-wave-dat]] - [[sensor-RCWL-dat]]

- [[sensor-camera-dat]]

- [[angle-encoder-dat]]

- [[sensor-optical-flow-dat]]




## ref 

- [[sensor-motion-dat]]