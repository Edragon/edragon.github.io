
# camera-depth-dat


 # What is a Depth Camera?

A **depth camera** (also known as a 3D camera) is a device that perceives the distance of objects in its field of view, essentially adding a "Z-axis" to the traditional 2D image. While a standard camera captures color and brightness (RGB), a depth camera captures a **depth map**, where each pixel represents the physical distance from the lens to the object.

---

## How it Works
Unlike our eyes, which use biological stereo vision, depth cameras typically use one of three primary technologies to "see" distance:

### 1. Structured Light
The camera projects a known pattern of invisible infrared light (like a grid of dots) onto a scene. When the pattern hits an object, it deforms. The camera analyzes these deformations to calculate the depth of the surface.
* **Example:** FaceID on iPhones.



### 2. Time-of-Flight (ToF)
The sensor emits a tiny pulse of infrared light and measures exactly how long it takes for that light to bounce off an object and return to the sensor. Since the speed of light is constant, the camera can calculate the distance with extreme precision.
* **Example:** LiDAR in autonomous cars and high-end iPads.



### 3. Stereo Vision
This mimics human sight by using two separate lenses placed a small distance apart. By comparing the slight shift in position of objects between the two images (disparity), the camera calculates depth.
* **Example:** The human eye or specialized robotics kits.

---

## Key Applications

- [[robotic-dat]] - [[camera-depth-dat]]

* **Biometrics:** Facial recognition that can't be fooled by a 2D photograph.
* **Robotics:** Allowing a "Rover" or robot to navigate a room without crashing into furniture by understanding the 3D layout.
* **Augmented Reality (AR):** Enabling digital objects to sit "behind" a real-world couch or stay anchored to a floor.
* **Industrial Automation:** Used in factories to measure the volume of boxes or for robotic arms to pick up specific parts.

## Why it Matters
For anyone working with electronics or CAD design, depth cameras are the bridge between the digital and physical worlds. They allow a machine to not just "see" a picture, but to understand the **geometry** of its environment.



## ref 

