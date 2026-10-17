


# vision-Binarization-dat

- [[vision-Binarization-dat]] - [[vision-dat]] - [[vision-pnp-dat]]



在图像处理和机器视觉中，**反向二值化**和**增强二值化**是针对不同场景对基础二值化进行的优化和扩展。



## 1. 反向二值化（Inverse Binarization）

**反向二值化**是标准二值化的“镜像”翻转。

* **标准二值化（Binary）**：
* 像素亮度 **＞ 阈值** $\rightarrow$ 变成 **白色（255）**
* 像素亮度 **≤ 阈值** $\rightarrow$ 变成 **黑色（0）**
* *结果*：目标物体如果是亮的，就会变成白色。


* **反向二值化（Binary Inv）**：
* 像素亮度 **＞ 阈值** $\rightarrow$ 变成 **黑色（0）**
* 像素亮度 **≤ 阈值** $\rightarrow$ 变成 **白色（255）**
* *结果*：目标物体如果是暗的（例如浅色背景上的深色印记、深色引脚），经过反向二值化后，**暗的目标会变成白色（前景）**，而亮背景会变成黑色（背景）。



**实际应用场景**：
大多数视觉软件（如 OpenCV、Halcon）在进行连通域分析（Blob Analysis）时，默认只对“白色区域（前景）”进行计算和测量。如果你的目标本身颜色较深，使用反向二值化可以直接把深色目标转为白色，方便系统抓取和计算。

---

## 2. 增强二值化（Enhanced Binarization / 预处理复合二值化）

“增强二值化”通常不是指某一个单一的固定算法，而是指“图像增强（Contrast Enhancement） + 二值化”的组合拳，或者是利用具备对比度增强特性的自适应算法（如 Sauvola、Niblack 算法）。

在真实工业现场中，由于反光、污渍或光照不均，直接二值化往往会产生大量噪声或导致目标残缺。增强二值化通过以下步骤解决该问题：

* **第一步：对比度增强与滤波**
* 在二值化之前，先通过直方图均衡化（如 CLAHE 局部对比度增强）或高斯滤波，把图像中模糊的边缘“拉开”，压制背景噪声。


* **第二步：动态/局部增强二值化**
* 采用高级算法（例如局部自适应阈值），根据像素周边的明暗动态调整阈值，使得原本因光线暗淡而看不清的边缘也能被清晰勾勒出来。



**实际应用场景**：

* **金属表面字符识别（OCR）**：如在反光严重的芯片表面或激光雕刻的金属零件上读取字号，原始图像对比度极低，必须通过增强二值化把字迹从复杂的金属纹理中“抠”出来。
* **微小缺陷检测**：PCB板上细微的划痕或污染。


## What is a Binarization Vision Algorithm?

Binarization is one of the most fundamental and core algorithms in computer vision and image processing.

Simply put, binarization is the process of converting a grayscale image (which contains 256 levels of brightness, ranging from black to white) into a pure binary image consisting of only two extreme colors: "black" and "white."

In a binary image:

Pixel values typically have only two choices: 0 (representing black/background) and 255 (representing white/foreground, or vice versa).

It works by setting one or more thresholds, turning any pixel with a value greater than the threshold into white (or 1), and pixels less than or equal to the threshold into black (or 0).

## 1. Why Do We Need Binarization?

In machine vision (such as placement machine recognition, barcode scanning, and industrial inspection), raw images contain a lot of colors, shades, and shadow details. These "unnecessary details" can interfere with computer processing. Binarization offers huge advantages:

Drastically reduces data volume: Compresses the image from 8 bits per pixel (256 grayscale levels) to 1 bit per pixel (black and white), significantly boosting processing speed.

Highlights core features: Filters out background noise, making object contours, boundaries, and shapes extremely sharp, which simplifies subsequent edge detection, geometric measurements, or OCR (Optical Character Recognition).

## 2. Three Common Types of Binarization Algorithms

Depending on how the threshold is determined, binarization is generally divided into:

### ① Global Fixed Thresholding

原理 (Principle): Uses the same fixed threshold for the entire image. For example, if the threshold is set to 128, any pixel above 128 becomes white, and those below or equal become black.

Applicable Scenarios: High-quality industrial environments with very uniform lighting and high contrast between the background and the target.

Representative Algorithm: Otsu’s Method (Maximum Inter-Class Variance). It automatically calculates an optimal global threshold and is widely used on automated production lines.

### ② Local Adaptive Thresholding

原理 (Principle): Since lighting can vary across different regions of the same image (e.g., bright on the left, dark on the right), adaptive algorithms calculate the average brightness of the neighborhood around each pixel to serve as that specific pixel's custom threshold.

Applicable Scenarios: Scenes with uneven lighting or shadow interference (such as handwritten character recognition or complex, reflective metal surface inspection).

### ③ Dual-Threshold / Multi-Thresholding

原理 (Principle): Sets a lower and an upper limit, keeping only the pixels that fall between these two values while filtering out the rest.

## 3. Practical Applications in Placement Machines (Pick-and-Place) / Industrial Vision

Binarization is everywhere in the vision systems of the placement machines we discussed earlier:

Component Positioning and Alignment: After the camera captures an image of the pins or the body of a component, it typically undergoes binarization first to cleanly separate the chip pins from the background. This allows the algorithm to extremely quickly calculate the pin center coordinates and rotation angle.

MARK Point Recognition: Circular or cross-shaped MARK points on a PCB board exhibit extremely sharp black-and-white contrast after binarization, allowing the machine to instantly and precisely capture their center position.



## ref 

