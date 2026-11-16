


# M620-dat

- [[M620-dat]] - [[bafang-dat]]


- [[VESC-dat]] - [[ESC-dat]] - [[M620-dat]] - [[bafang-dat]]

**VESC based INNOTRACE M620 Simple motor controller** 是由海外开源电动交通与电机控制极客（如开发者 TPEHAK 等活跃在 Endless Sphere 和 VESC 社区的爱好者）专门为**八方 M620（Bafang M620 / G510 Ultra）中置电动机**量身定制并开源的一款**高性能、基于 VESC 生态的替代控制器**。

简单来说，它是针对热门电助力山地车（eMTB）八方 M620 电机开发的一种**第三方改装电机控制器**。其核心特点和背景包括：

1. **VESC 开源生态驱动**：
该控制器基于著名的 **VESC（Vedder Electronic Speed Controller）** 架构。这意味着它可以使用功能强大的 **VESC Tool** 进行精细的参数配置（如电流限制、电压、磁编码器校准、FOC 磁场定向控制等），拥有极高的可玩性、线性的油门/力矩响应和极佳的效率。
2. **专为八方 M620（G510）设计**：
八方 M620 是业内非常暴力的一款中置电机（常用于高性能 DIY 电动山地车/胖胎车）。原厂控制器在功率解锁、自定义调参或极限压榨性能方面有限。而 INNOTRACE 系列控制器（包括后期的这个简化版 / Simple Controller）可以直接塞进 M620 的电机壳体内部，替代原厂控制器。
3. **“Simple” 简化版的特点**：
* **硬件开源与低成本**：项目在社区完全开源（包含 KiCAD 原理图、Gerber 生产文件、BOM 清单等）。用户可以直接把生产文件提交给 PCB 打样厂（如 JLCPCB）制作，自己通过钢网和加热台焊接，大幅降低了硬件成本。
* **紧凑的 4 层板设计**：相比复杂的早期版本，Simple 版本进一步优化了空间和成本，完美适配 M620 内部狭窄的安装公差。
* **支持 CAN 总线**：能够很好地适配支持 CAN 通信的八方 M620 系统及相关外设（如仪表、力矩传感器等）。


4. **发烧友的性能利器**：
通过 VESC 固件的加持，改装该控制器的 M620 电机可以解锁更高的电压、更大的电流（支持极高的功率输出，甚至能把原本的电单车变成功率达数千瓦的“暴力机车”），并且发热控制、温控保护以及平顺性都比原厂或一些粗暴破解的固件更科学。

总结而言，它不是一个商业成品官方配件，而是**面向硬核电单车（e-bike）DIY 玩家的开源高性能 VESC 电机控制器硬件方案**，旨在让八方 M620 电机发挥出更强、更可定制化的性能。



## hack 

VESC / 控制器
- VESC 版 INNOTRACE M620 简易电机控制器 — 老帖出现新回复，M620 中置机的 VESC 方案值得继续看，尤其是参数与散热实测。· Motor + Controller Technology ·
  https://endless-sphere.com/sphere/threads/vesc-based-innotrace-m620-simple-motor-controller.131062/
- VESC 版 INNOTRACE M560/M600 简易控制器 — 与 M620 属同一系列，M560、M600 两个版本更轻量。· Motor + Controller Technology ·
  https://endless-sphere.com/sphere/threads/vesc-based-innotrace-m560-m600-simple-motor-controller.131503/

  


## ref 