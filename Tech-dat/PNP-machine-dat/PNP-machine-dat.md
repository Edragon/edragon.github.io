
# PNP-machine-dat

- opensource options [[openpnp-dat]] - [[PixiePlacer-dat]]

- commerlized options [[lumenpnp-dat]]

- relevant knowledge [[PCB-dat]] - [[EDA-dat]]

- [[pnp-machine-software-dat]] - [[serial-dat]]

- compoennts [[nozzle-dat]] - [[feeder-dat]]

## BOM overview 


## mechnical parts

- [[XYZ-dat]] - [[feeder-dat]]



## electronics parts 

- [[Pick-and-place-dat]]


## Basic Knowledge ⚡⚡


### Single Board
A single board is the physical entity consisting of a PCB and the components placed on it. The software supports placing components on both sides of the board, referred to as the top and bottom.

单板是由 PCB 及其上的元件组成的物理实体。软件支持将元件放置在电路板的两面，分别称为顶部和底部。

### CSV Coordinate File
We need to export a coordinate file from the PCB and then import it into the software. This file must be in CSV format. Currently, AD, KiCad, LCEDA (EasyEDA), and Allegro are supported. You can also submit your software format for adaptation.

我们需要从 PCB 导出坐标文件，然后将其导入到软件中。此文件必须为 CSV 格式。目前，支持 AD、KiCad、LCEDA (EasyEDA) 和 Allegro。您也可以提交您的软件格式以进行适配。

### Panelization
Panelization refers to assembling multiple PCBs together. For more details on how to use panelization, click here.

拼板是指将多个 PCB 组装在一起。有关如何使用拼板的更多详细信息，请单击此处。

### PCB Origin
When using EDA tools to design PCB files, it is necessary to specify an origin point. This point should be located within the PCB frame.

使用 EDA 工具设计 PCB 文件时，需要指定一个原点。此点应位于 PCB 框架内。

### Fiducials (MARK Points)
Fiducials, also known as MARK points, are small markers on the PCB or panel that help the machine automatically and accurately locate the PCB or panel. MARK points are typically small circular pads with a large keep-out area and no solder paste applied. [MARK Point Settings](#) - [[mark-point-dat]]

基准点，也称为 MARK 点，是 PCB 或面板上的小标记，可帮助机器自动准确地定位 PCB 或面板。MARK 点通常是带有大隔离区且未涂覆焊锡膏的小圆形焊盘。[MARK 点设置](#)

### Components
Components are specific parts placed on the board. They are typically synonymous with manufacturer part numbers. Two components with different values are considered different components. For example, a 10k 0603 resistor and a 22k 0603 resistor are different components. Each part is assigned a package.

元件是放置在电路板上的特定零件。它们通常与制造商的零件编号同义。具有不同值的两个元件被认为是不同的元件。例如，10k 0603 电阻和 22k 0603 电阻是不同的元件。每个零件都分配有一个封装。

### Package
A package describes the physical attributes of a component, such as length, width, and occupied space. Many components share the same package. Examples include 0603 resistors, 0603 capacitors, SOIC-8, and TQFP-32. In the software, packages serve two main purposes:
1. Specify the nozzle type to use.
2. Define dimensions for visual synthesis of large components.

封装描述了元件的物理属性，例如长度、宽度和占用空间。许多元件共享相同的封装。示例包括 0603 电阻器、0603 电容器、SOIC-8 和 TQFP-32。在软件中，封装有两个主要目的：
1. 指定要使用的吸嘴类型。
2. 定义用于大型元件视觉合成的尺寸。

### Crosshairs
Crosshairs are overlays, such as a cross or other shapes, on the camera window to help you see the center of the image.

十字线是相机窗口上的叠加层，例如十字或其他形状，可帮助您查看图像的中心。

### Bottom Vision
Bottom vision refers to the upward-facing camera that uses computer vision to automatically inspect components before placement. This inspection improves placement accuracy.

底部视觉是指向上看的相机，它使用计算机视觉自动检查元件，然后再进行放置。此检查提高了放置精度。

### Top Vision
Top vision refers to the downward-facing camera mounted on the head (on the left side of the head). It is used to identify fiducials and visually locate components on feeders.

顶部视觉是指安装在头部（在头部的左侧）的向下看的相机。它用于识别基准点并在视觉上定位供料器上的元件。

### Feeders (Feeder)
Feeders, also known as feeders, are hardware that supplies components. This machine supports automatic feeders, cut tape feeders, visual loose components, and tray feeders. You can also build other types of feeders yourself.

供料器，也称为送料器，是提供元件的硬件。该机器支持自动供料器、剪切带供料器、视觉散装元件和托盘供料器。您也可以自己构建其他类型的供料器。

### Head
The head is the part of the machine that can move in the X and Y directions. It carries the nozzle and the top vision camera.

头部是机器的一部分，可以在 X 和 Y 方向上移动。它携带吸嘴和顶部视觉相机。

### Nozzles (N1 and N2)
N1 and N2 nozzles are parts of the machine that can descend to pick up components. The nozzle is the part that physically contacts the component to pick it up. The head can carry nozzles, and the nozzle tip contacts the component. A machine can have any number of nozzles.

N1 和 N2 吸嘴是机器的一部分，可以下降以拾取元件。吸嘴是物理接触元件以拾取它的部分。头部可以携带吸嘴，吸嘴尖端接触元件。一台机器可以有任意数量的吸嘴。

### Nozzle
Different component sizes correspond to different nozzle models. You can specify the nozzle model for a component through its package. [Nozzle Model and Package Mapping](#)

不同的元件尺寸对应于不同的吸嘴型号。您可以通过元件的封装指定吸嘴型号。[吸嘴型号和封装映射](#)

### Z Height
Z height usually refers to the distance from the nozzle to the target. You can determine this by moving the nozzle close to and contacting the target, then observing the Z value in the bottom-right status bar and entering it. Alternatively, click the software's "Get Nozzle Position" icon. Note that this value must be negative.

Z 高度通常是指从吸嘴到目标的距离。您可以通过将吸嘴移动到靠近并接触目标，然后观察右下角状态栏中的 Z 值并输入它来确定这一点。或者，单击软件的“获取吸嘴位置”图标。请注意，此值必须为负数。

### Component Thickness
The height of components can be obtained using calipers or datasheets.

元件的高度可以使用卡尺或数据表获得。

### PCB Origin
When designing a PCB, you need to specify a PCB origin. This origin is also the relative reference zero point for exporting CSV coordinates. Remembering this point is essential for PCB positioning.

在设计 PCB 时，您需要指定一个 PCB 原点。此原点也是导出 CSV 坐标的相对参考零点。记住这一点对于 PCB 定位至关重要。

### Mechanical Origin
This is the mechanical reference point for the entire machine. All machine coordinates are based on this point, so do not change its position. The machine's origin is the cylinder next to the bottom camera. The machine automatically calibrates this point's position after each startup.

这是整台机器的机械参考点。所有机器坐标都基于此点，因此请勿更改其位置。机器的原点是底部相机旁边的圆柱体。机器每次启动后都会自动校准此点的位置。

### Nozzle Diameter
This refers to the physical diameter of the nozzle. Both inner and outer diameters can be used.

这是指吸嘴的物理直径。可以使用内径和外径。

### Nozzle Recognition Range
This refers to the maximum allowable deviation of the nozzle from the center of the crosshairs. This value should not be too large, as it may cause recognition errors.

这是指吸嘴与十字线中心的最大允许偏差。此值不应太大，否则可能会导致识别错误。

### Coordinate System
This pick-and-place machine uses a right-hand coordinate system, which is also used in physics, mathematics, 3D graphics, and many CAD software packages. For a more formal definition of this coordinate system, refer to Wikipedia.

该贴片机使用右手坐标系，该坐标系也用于物理学、数学、3D 图形和许多 CAD 软件包中。有关此坐标系的更正式定义，请参阅 Wikipedia。

In this coordinate system, we stand above the machine and look down at it:
- **X-axis**: Moves left and right. Left is negative.
- **Y-axis**: Moves forward and backward. Backward is positive.
- **Z-axis**: Moves up and down. Up is positive.
- **C-axis (Rotation Axis)**: Rotates clockwise and counterclockwise. Counterclockwise is positive.

在这个坐标系中，我们站在机器上方并向下看：
- **X 轴**：左右移动。左为负。
- **Y 轴**：前后移动。后为正。
- **Z 轴**：上下移动。上为正。
- **C 轴（旋转轴）**：顺时针和逆时针旋转。逆时针为正。



## ref 

- [[pnp-machine]]