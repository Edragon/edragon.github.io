
# RV1103-dat

1.1 Overview
RV1103 is a highly integrated vision processor SoC for IPC, especially for AI related applications.

It is based on a single-core ARM Cortex-A7 32-bit core which integrates NEON and FPU.

There is a 32KB I-cache and 32KB D-cache and 128KB unified L2 cache.

The build-in NPU supports INT4/INT8/INT16 hybrid operation and computing power is up to 0.5TOPs. In addition, with its strong compatibility, network models based on a series of
frameworks such as TensorFlow/MXNet/PyTorch/Caffe can be easily converted.

RV1103 introduces a totally new generation hardware-based maximum 4-Megapixel ISP (image signal processor). It implements a lot of algorithm accelerators, such as HDR, 3A,
LSC, 3DNR, 2DNR, sharpening, dehaze, gamma correction and so on. Cooperating with two MIPI CSI (or LVDS), users can build a system that receives video data from 2 camera
sensors simultaneous.

The video encoder embedded in RV1103 supports H.265/H.264 encoding. It also supports multi-stream encoding. With the help of this feature, the video from the camera can be
encoded with higher resolution and stored in local memory and transferred to another lower resolution video to cloud storage at the same time. To accelerate video processing,
an intelligent video engine with 22 calculation units is also embedded.

RV1103 has a build-in 16-bit DRAM DDR2 capable of sustaining demanding memory bandwidths. It also integrated build-in POR, audio codec and MAC PHY.


## ref 

- [[Rockchip RV1103 Datasheet V1.1-20220427.pdf]]

- luckfox pico SCH - [[Luckfox-Pico-SCH.pdf]]