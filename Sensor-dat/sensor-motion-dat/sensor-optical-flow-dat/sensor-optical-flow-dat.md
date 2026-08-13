
# sensor-optical-flow-dat

Optical flow sensor (e.g. PMW3901 module) → helps with drift correction indoors.

- [[PMW3901-dat]]


### Working Mechanism

**1. Horizontal Translation Calculation: Optical Flow Algorithm**

- **Principle:** a bottom monocular or stereo camera films the ground at a very high frame rate (e.g., 60–120 FPS).
- **Computation:** the flight-controller chip extracts feature points from the image (e.g., ground texture, carpet patterns, grass grains) and compares the **pixel displacement** of feature points between two consecutive frames.
- **Feedback:** if the whole image shifts left, the drone is drifting right; the FC immediately adjusts motor speeds in the opposite direction to pull the drone back — achieving "rock-steady" horizontal hovering.

---

### VIO and Optical Flow Sensor

**VIO mainly relies on camera sensor(s), while Optical Flow is an algorithm/front-end technique VIO commonly uses to process camera images, or serves as an auxiliary data source.**

They operate at different levels:

---

### 1. Hardware Level: Relies on "Camera Sensors"

VIO's hardware foundation is clear: **Camera + IMU**.

- **Camera Sensor:** provides a continuous image sequence (typically 30–120 FPS grayscale/color images).
- **IMU (Inertial Sensor):** provides high-frequency angular velocity and acceleration data (typically 200–1000 Hz).

---

### 2. Software Level: Optical Flow Is One of VIO's Image-Processing Algorithms

VIO's algorithmic front end must solve a core problem: **how do we know how much the camera moved from one frame to the next?**

To find the relative motion between two images, VIO typically uses one of two approaches:

- **Sparse optical flow (e.g., Lucas-Kanade / LK):**
  - First extract corners/feature points in the first image.
  - Use the **optical flow algorithm** to track those points' pixel positions in the next image (no complex descriptor computation needed — extremely fast).
  - Representative systems: **VINS-Mono**, **ROVIO**.

- **Feature matching (e.g., ORB / SIFT):**
  - Extract feature points in both images and compute descriptors, then find correspondences via brute-force or KNN matching.
  - Representative systems: **ORB-SLAM3**.

Therefore, **Optical Flow is an efficient algorithmic tool VIO uses to process images captured by "camera sensors."**

---

### 3. Additional Distinction: Standalone "Flow Sensor / Optical Flow Sensor"

The "optical flow sensor modules" commonly seen in industry or on drones (e.g., PX4Flow, or the modules on the bottom of ordinary robot vacuums):

- They are **small hardware modules integrating a micro lens, a CMOS image chip, and a dedicated optical-flow compute chip**.
- They only output 2D velocity vectors ($v_x, v_y$), and typically depend heavily on an additional range-finding module (e.g., IR/ToF) to determine the height scale factor.
- **VIO systems don't depend on such flow modules** — VIO directly uses the drone/device's main or auxiliary **camera** and runs the full 3D VIO algorithm on the main controller chip or VPU/NPU.

- [[vision-VIO-2D-dat]] == [[sensor-optical-flow-dat]]






## ref 

- [[sensor-optical-flow]] - [[sensor-motion]] - [[sensor]]