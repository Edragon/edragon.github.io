

# Vision-PNP-dat



- bottom vision 
- top vision 



## bottom vision 

- [[fab-footprint-dat]]

启用视觉

视觉算法：`二值` == [[vision-Binarization-dat]] - [[vision-dat]]

相机模式：`快速`

识别模式：`外形极性`

外形极性 -- 自动

自动识别

`反向二值化`

识别区域：`9.20mm`

碎片过滤：`0.00mm²`

二值化：`207`

`增强二值化`

`长宽过滤`

元件偏移：X：0.00Y:0.00R:0.00


### 识别区域（Inspection Window / ROI - Region of Interest）

它是什么：相机拍照后，软件只在画面的哪个框选范围内去寻找和计算 SOT23-3。

对抛料的影响：

视野框太小：如果取料偏移稍微大了一点点（例如吸嘴有点歪，或者飞达送料有点偏），SOT23-3 在相机画面里的位置就会稍微偏离中心。如果“识别区域”框得太小，元件超出了这个框，机器就“看不见”它，从而直接报错抛料。

背景干扰：如果框得太大，把飞达边缘的机械结构（金属反光条）也框进去了，会干扰二值化和边缘提取。

优化建议：

适当放大识别区域（ROI）的尺寸，确保即使元件在吸嘴上有轻微偏心，也能完全落在识别框内。

### 3. 长宽过滤（Size/Dimension Filter / Aspect Ratio）

* **它是什么**：设定元件在图像中的长和宽的允许范围（比如长 2.8mm~3.2mm，宽 1.4mm~1.8mm）。
* **对抛料的影响**：
* **公差窗口太窄**：由于不同批次的 SOT23-3 来料尺寸会有微小公差（热胀冷缩或供应商差异），或者相机拍摄时高度微调导致成像大小有几个像素的偏差。如果长宽过滤的上下限卡得太死（例如只允许正负 0.05mm），稍微大一点或小一点就会触发报错，导致**稳定抛料**。
* **方向搞反**：SOT23-3 是长方形的，长宽不对称。如果在设置时把长和宽的判定逻辑搞反了，或者角度旋转后长宽超限，也会引发抛料。


* **优化建议**：
* 测量当前批次真实的 SOT23-3 尺寸，将长宽过滤的公差适当放宽（例如设定在 $\pm 0.1mm$ 或 $\pm 10\%$ 左右），给来料误差留出余地。


### SOT23-3

在贴片机生产中，**SOT23-3**（一种常见的3引脚小形三极管/MOS管封装）由于体积小、引脚不对称（一侧2个引脚，另一侧1个引脚）、且封装本体容易反光，是视觉识别和“抛料（Reject）”的高频地带。

如果你遇到 SOT23-3 经常在视觉识别时抛料，通常是因为**视觉参数设置过于苛刻**（误把合格品当成不良品抛掉），或者**二值化/阈值没有把引脚和本体正确分离**。

以下是针对你提到的几个核心视觉参数的详细解析，以及它们如何导致抛料和对应的优化方法：



### 1. 二值化（Binarization）—— **最核心的根源**

* **它是什么**：决定机器如何把 SOT23-3 的“身体（本体）”和“引脚”从背景中分离出来的标准。
* **对抛料的影响**：
* **阈值过高/过低**：SOT23-3 的封装一般是黑色的，引脚是亮银色的。如果二值化阈值没调好，会导致**引脚变细、甚至直接“断开”消失**，或者**本体边缘严重锯齿化**。
* **反光干扰**：封装表面如果有反光（亮斑），会被二值化误认为是白色区域，导致机器算出的中心和角度发生严重偏移，超出容许公差而抛料。


* **优化建议**：
* 优先使用**动态自适应二值化**（如果软件支持），以抵抗光照不均。
* 调整阈值后，观察实时图像：确保**三个引脚的边缘清晰、完整、没有被吞噬**，且黑白对比分明。



### 2. 碎片过滤（Blob Filter / Noise Removal）

* **它是什么**：过滤掉图像中面积过小、不符合规则的噪点（如灰尘、锡渣、反光斑点）。
* **对抛料的影响**：
* **过滤阈值设得太大**：SOT23-3 有一个引脚是单出来的，另外两个引脚在一起。如果“最小面积（Min Area）”设置得过高，机器可能会把较小或稍微有点模糊的引脚误认为是个“噪点”或“碎片”直接过滤掉。引脚一旦被过滤，机器就会认为该元件残缺不全，直接**抛料**。


* **优化建议**：
* 适当**调低碎片过滤的最小面积限制**，确保哪怕引脚因为图像模糊显得有点小，也不会被当成垃圾切掉。



### 4. 识别区域（Inspection Window / ROI - Region of Interest）

* **它是什么**：相机拍照后，软件只在画面的哪个框选范围内去寻找和计算 SOT23-3。
* **对抛料的影响**：
* **视野框太小**：如果取料偏移稍微大了一点点（例如吸嘴有点歪，或者飞达送料有点偏），SOT23-3 在相机画面里的位置就会稍微偏离中心。如果“识别区域”框得太小，元件超出了这个框，机器就“看不见”它，从而直接报错抛料。
* **背景干扰**：如果框得太大，把飞达边缘的机械结构（金属反光条）也框进去了，会干扰二值化和边缘提取。


* **优化建议**：
* 适当放大识别区域（ROI）的尺寸，确保即使元件在吸嘴上有轻微偏心，也能完全落在识别框内。



---

### 💡 排查与优化 SOT23-3 抛料的实际步骤：

1. **看抛料时的报错日志**：机器报错是“视觉识别失败（Vision Fail）”、“尺寸超差（Size Out of Range）”还是“引脚缺失（Missing Pin）”？
2. **抓取失败图像（Image Logging）**：打开贴片机的视觉调试界面，查看被抛弃的那颗 SOT23-3 的**抓拍原图和二值化后的处理图**。
3. **对症下药**：
* 如果二值化后引脚断了/残缺 $\rightarrow$ **调二值化阈值 / 增强对比度**。
* 如果尺寸报错 $\rightarrow$ **放宽长宽过滤（Size Filter）**。
* 如果偶尔偏心就抛料 $\rightarrow$ **放大识别区域 / 检查机械吸嘴和飞达抓取**。



### methods 


识别模式


### Placement Machine Vision Recognition Modes Comparison Table

| Recognition Mode                           | Polarized?                    | Component Type                    | Examples                                                 | Judgment Method                                                                                                 | Rejection Risk           | Misplacement Risk                                | Core Characteristics & Applicable Scenarios                                                                               |
| ------------------------------------------ | ----------------------------- | --------------------------------- | -------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------- | ------------------------ | ------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------------- |
| **Standard**                               | Yes (Strict)                  | Standard & Symmetrical Components | Chip Resistors (0402, 0603), Capacitors, Symmetrical ICs | Checks overall dimensions, angle, pitch, and standard symmetry simultaneously against the master library model. | **Medium**               | **Low**                                          | Standard mode for stable incoming materials with consistent physical presentation.                                        |
| **Length/Width Direction (Non-Polarized)** | No (Checks aspect ratio only) | Asymmetric Small Components       | **SOT23-3**, SOD-323, Diodes                             | Ignores directional asymmetry; only verifies length, width boundaries, and center offsets.                      | **Low**                  | **Very Low** (Requires fixed feeder orientation) | **Most recommended for SOT23-3**. Eliminates high rejection rates caused by reflections or shadows on pin configurations. |
| **Outline Polarity**                       | Yes (Extremely Strict)        | Polarized ICs & Transistors       | Tantalum Capacitors, Diodes, QFP ICs with Pin 1 markers  | Scans for specific asymmetric body cuts, polarity dots, or asymmetrical pin counts (e.g., 2 vs 1).              | **High**                 | **Very Low**                                     | Prone to false rejections from surface oxidation, scratches, or uneven lighting.                                          |
| **No Direction**                           | No                            | Fully Symmetric / Non-Polarized   | MLCCs, Chip Resistors, Round Pads                        | Completely bypasses orientation checks; picks and places immediately based on center coordinates.               | **Very Low**             | **High**                                         | Fast processing, but will cause electrical failures if accidentally used on polarized or asymmetric components.           |
| **Large Component (Out of Field of View)** | No                            | Oversized ICs                     | Large QFP, BGA, Connectors                               | Uses multi-field-of-view image stitching to capture and stitch parts larger than a single camera frame.         | **High** (if misapplied) | **High**                                         | Designed specifically for large fine-pitch integrated circuits; incompatible with small chips like SOT23-3.               |


#### 标准

纠正45度以内的旋转偏差,适用于有极性元件或者无极性的接近正方形的元件

—— **中规中矩，容易因微小误差抛料**

* **对抛料的影响**：**中等抛料率**。
* **原因**：标准模式会同时校验尺寸、角度和基本的对称性。如果来料稍微有一点变形，或者相机光源有轻微波动，标准模式下的容错率较低，容易触发误判。
* **优化方法**：如果必须用标准模式，应在视觉参数中**增大角度容差（Angle Tolerance）**和**尺寸公差**。


#### 长宽方向(无极性) 

纠正90度以内的旋转偏差,适用于无极性长方形元件例如电阻,通过元件的长宽边确定元件的方向,对于无极性元件启用可降低震动导致元件错误的垂直90度概率

- [[STO23-3-dat]]

—— **推荐（降抛料效果最好）**

* **对抛料的影响**：**大幅降低抛料率**。
* **原因**：SOT23-3 经常抛料的一个主要原因是机器在视觉抓取时，对它的“外形极性”或“单双脚朝向”进行了极其严苛的判定。只要单引脚那一侧有一点点反光或阴影，机器就会判定极性错误或形态不符而抛料。“无极性”模式**忽略了严格的极性/方向校验**，只核对元件的外形尺寸、长宽比例和中心偏移。
* **注意事项**：因为不检测极性，必须确保物理飞达（Feeder）上的料带方向是完全正确的（即入料方向一致），否则机器会把方向放反的元件贴到板子上。


#### 外形极性

纠正任意角度旋转,适用于能通过标准或者外形区分方向的元件,例如梯形元件,带箭头标志的元件,部分贴片电解电容



—— **抛料的“重灾区”**

* **对抛料的影响**：**极易导致高频抛料**。
* **原因**：SOT23-3 靠“一侧2个脚、一侧1个脚”或本体微小的方向标志来判定极性。外形极性模式会死死盯着这个特征。在实际生产中，封装表面的微小划痕、引脚氧化带来的反光不均，都会导致机器“认不出”极性，从而无情抛料。
* **建议**：除非该元件方向极其敏感且来料极度稳定，**尽量避免在 SOT23-3 上开启此选项**。

#### 无方向

不纠正元件的旋转,强制元件为0度,适用于圆形元件

—— **极少抛料，但有贴错风险**

* **对抛料的影响**：**几乎不会因为视觉问题抛料**。
* **原因**：机器完全不管元件是怎么旋转的，只要抓到了就按既定坐标贴。
* **风险**：SOT23-3 是三极管/MOS管，引脚功能各不相同（如基极、发射极、集电极）。如果开启无方向且没有配合好送料方向，会导致元件被 180 度反向贴装，造成短路或电路不工作。





#### 大元件(超出视野)

通过多次拍摄,识别元件对角实现超出相机视野范围的元件识别,适用于QFP,BGA之类矩形对称元件




## top vision 



## ref 

- [[vision-pnp]] - [[vision]] - [[tech]]