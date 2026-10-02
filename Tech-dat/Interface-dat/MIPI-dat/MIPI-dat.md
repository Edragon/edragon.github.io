
# MIPI-dat


- [[PCB-design-complex-dat]] - [[DDR-dat]] - [[MIPI-dat]]

## build 

- [[IMX415-dat]] - [[IMX307-dat]] - [[sony-dat]] - [[MIPI-dat]]




## info 

- [[HDMI-dat]] - [[camera-CSI-dat]] - [[interface-dat]] - [[MIPI-dat]] - [[video-dat]]

- [[camera-CSI-dat]] - [[MIPI-CSI-dat]] - [[MIPI-DSI-dat]]



## design and fab  

### MIPI 跨板 

- [[IMX307-dat]] - [[MIPI-dat]] - [[HI3516-dat]] - [[CONN-FPC-dat]]

IMX307 参数：1/2.8"、1920×1080、2.9µm 像素、STARVIS、最高 60fps、MIPI CSI-2 2-lane/4-lane、RAW10/12，2-lane 1080p60 约 594Mbps/lane

为什么跨板是难点：
- MIPI 是 Gbps 级差分信号，必须 100Ω 差分阻抗
- lane 内等长 skew <5mil，lane 间 <20mil
- 过孔即阻抗突变，要极少过孔、无 stub、参考平面完整
- 跨板 = 连接器寄生参数 + 阻抗突变 → 眼图劣化 → 花屏、噪点、偶发丢帧

连接方式排序（从优到劣）：

1. 传感器与 SoC 放同一块板 ← 最优，直接消灭这个问题
2. 阻抗控制 FPC（100Ω 差分、短、直、少折）← 可以接受，推荐
3. 板对板连接器（BTB，0.35/0.5mm） ← 注意：不是所有 BTB 都支持 Gbps 差分，必须选高速型号，且成本高（¥5-20/对）
4. 焊接堆叠（board-on-board）← 便宜但不可返修，且共面度要求高

建议：如果两块板必须分开，MIPI 一定走阻抗控制 FPC，不要走普通排针/BTB。并且 FPC 要短（<50mm 最好），做阻抗仿真。



## concept 

- [[MIPI-CSI-dat]] - [[MIPI-DSI-dat]]

MIPI CSI (Camera Serial Interface) and MIPI DSI (Display Serial Interface) are standardized high-speed interfaces developed by the MIPI Alliance to facilitate efficient communication between components in electronic devices.

### MIPI CSI (Camera Serial Interface):

MIPI CSI is a widely used high-speed protocol for transmitting still and video images from image sensors to application processors. It defines an interface between a camera and a host processor, enabling efficient image data transfer in mobile and embedded systems. The latest version, CSI-2 v3.0, was released in September 2019. 
RESHINE DISPLAY

### MIPI DSI (Display Serial Interface):

MIPI DSI defines a high-speed serial interface between a host processor and a display module. It enables manufacturers to integrate displays to achieve high performance, low power, and low electromagnetic interference (EMI) while reducing pin count and maintaining compatibility across different vendors. 
MIPI

Both MIPI CSI and DSI are critical in modern device design, facilitating efficient communication between cameras, displays, and processors, thereby enhancing the performance and integration of multimedia functionalities in electronic devices.

For more detailed information, you can refer to the MIPI Alliance specifications:

MIPI CSI-2: https://mipi.org/specifications/csi-2
MIPI DSI: https://www.mipi.org/specifications/dsi


## supported devices 

- [[ESP32-P4-dat]] - [[RPI-dat]]