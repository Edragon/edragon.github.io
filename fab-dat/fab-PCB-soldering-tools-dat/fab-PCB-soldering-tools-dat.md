# soldering-dat

- [[PSO1043-dat]] - [[PSO1038-dat]]

- [[PCB-cleaner-dat]]

- [[solder-paste-dat]] - [[fab-PCBA-dat]]

- [[soldering-tools-dat]]

- [[fab-PCB-soldering-dat]]


## soldering skills 





### soldering chip with pads underneath, such as QFN, BGA, LGA, etc.

- [[allwinner-dat]]

T113 soldering note: 务必先焊接除T113以外的元器件，烧录51单片机固件，按下面的说明，测量3.3V、1.5V、0.9V全部正常再焊T113，否则若EA3036的FB虚焊将会直接烧坏T113。

T113 soldering note (English): Be sure to solder all components except T113 first, program the 51 MCU firmware, and follow the instructions below to measure 3.3V, 1.5V, and 0.9V to ensure they are all normal before soldering T113. Otherwise, if the FB pin of EA3036 is poorly soldered, T113 may be directly damaged.



### FPC soldering 

- [[FPC-dat]]

### alternative temperature-sensitive items soldering


> No special solder paste is needed; the key point is not to heat the FPC connector directly—apply heat from the back side of the PCB.
> 
> **Explanation:**
> When soldering temperature-sensitive components like FPC (Flexible Printed Circuit) connectors, you generally do not need to use any special type of solder paste. The most important thing is to avoid applying hot air or direct heat to the FPC connector itself, as it can be easily damaged by high temperatures. 
> Instead, use a hot air gun or soldering tool to heat the solder joints from the back side of the PCB. This approach helps protect the delicate connector and ensures a reliable solder joint.



## tips 

焊接注意事项

1. 确保焊接的部位干燥干净无油污无氧化；

2. 选择60W或更大功率的电烙铁，保证温度足够高，烙铁头可选尖头或马蹄头等以便传热和焊接（软包电池需要200W起的电烙铁，大单体需要500W起的电烙铁)

3. 先加热被焊接部位 (烙铁头紧贴焊接部位几秒钟）再同时快速送锡至焊点，焊接完成；

4. 注意：焊接过程烙铁不要离开金属表面，保持加热趁热焊接，锡丝尽量连续不断。

## ref 

- [[desoldering-dat]]

- [[welding-dat]] - [[spot-welding-dat]] - [[PTC-dat]]

- [[ICT-testing]]

- [[soldering]]