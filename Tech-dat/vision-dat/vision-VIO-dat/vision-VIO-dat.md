

# vision-VIO-dat

- [[vision-downward-dat]] - [[position-hold-dat]] - [[vision-VIO-dat]] - [[vision-dat]]

- [[altitude-hold-dat]] - [[vision-VIO-dat]] - [[sensor-optical-flow-dat]]

- [[vision-VIO-3D-dat]] 

- [[sensor-camera-dat]] - [[vision-VIO-dat]] - [[vision-vio-downward-dat]] - [[camera-vision-dat]]




## what is VIO == 视觉里程计 VIO（Visual-Inertial Odometry）


**Visual-Inertial Odometry (VIO) is an algorithm (a software / estimation framework)**, not a specific piece of hardware.

It fuses **"visual data" (camera) with "inertial measurement data" (IMU)** at the software level to compute and estimate the device's motion trajectory and attitude in real time.

---

## What VIO Is Made Of

Although VIO itself is an algorithm, running it requires specific hardware to host it:

- **Algorithm (VIO itself):** e.g., Kalman-filter-based (EKF/MSCKF) or graph-optimization-based nonlinear optimization (e.g., OKVIS, VINS-Mono).
- **Hardware foundation (dependency):**
  - **Camera:** provides low-frequency (e.g., 30–120 Hz) image feature-point data.
  - **IMU (Inertial Measurement Unit):** provides high-frequency (e.g., 200–1000 Hz) angular-velocity and acceleration data.
  - **Compute chip:** e.g., embedded CPU, VPU (vision processor), or NPU (neural-network processor) used to run the VIO algorithm.

---

## Why Combine Vision (V) and Inertial (I)?

Vision and IMU have physical characteristics that happen to be **complementary** — VIO's job is to fuse them:

| Sensor Type | Advantage Alone | Disadvantage Alone | Effect After VIO Fusion |
| --- | --- | --- | --- |
| **Camera (Visual)** | Accurate over the long term, no accumulated drift error. | Low refresh rate (30–60Hz); images blur during fast motion or violent shaking; loses scale (can't sense absolute physical distance). | **Complementary:** vision corrects IMU's long-term drift and provides an absolute physical-size reference. |
| **IMU (Inertial)** | High refresh rate (hundreds–thousands of Hz); highly sensitive to fast motion and rapid rotation; unaffected by lighting. | Integration drift over time (integrated quadratic error accumulation); data degrades after a few seconds. | **Complementary:** IMU fills the gaps between camera frames and maintains attitude during rapid direction changes or image blur. |

---

## Typical Application Scenarios

Any device that achieves centimeter-level self-localization and motion tracking without relying on GPS/GNSS almost certainly runs a VIO algorithm internally:

- **Drones (e.g., DJI drones):** high-precision hover and navigation in GPS-denied environments like indoors or under bridges.
- **AR/VR headsets (e.g., Apple Vision Pro, Meta Quest):** tracking the spatial position and attitude of the user's head (6DoF tracking).
- **Robot vacuums / embodied-intelligence robots:** indoor mapping and autonomous path planning (VIO typically serves as the front end of a V-SLAM system).


## ref

