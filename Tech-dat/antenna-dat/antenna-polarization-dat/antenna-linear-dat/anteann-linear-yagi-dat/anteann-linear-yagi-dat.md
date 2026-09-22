

# anteann-linear-yagi-dat


A **Linearly Polarized Yagi Antenna** (commonly known simply as a **Yagi-Uda antenna** or **Yagi antenna**) is a classic, highly directional antenna that transmits and receives radio waves with **linear polarization** (either horizontal or vertical). 

It is one of the most widely used directional antennas for VHF and UHF frequencies.

---

### 1. Structure and Working Principle
A traditional Yagi antenna consists of a central boom holding multiple parallel, straight metal rod elements:
* **Driven Element**: Typically a half-wave dipole connected directly to the transmitter or receiver feedline.
* **Reflector**: A single, slightly longer parasitic element placed behind the driven element to block and redirect energy forward.
* **Directors**: Several shorter parasitic elements placed in front of the driven element to focus the radio wave beam tightly in one direction (end-fire array).

Because all active and passive elements are straight linear rods, the electric field they radiate vibrates in a single plane, resulting in **linear polarization**.

### 2. Key Characteristics
* **High Directivity and Gain**: By adding more directors, a Yagi antenna can achieve significant gain (often ranging from 10 to over 20 dBi), concentrating its energy into a narrow beam.
* **Polarization Specifics**: It can be mounted horizontally or vertically depending on the communication standard:
  * **Horizontal Polarization**: Commonly used for traditional TV broadcasting, FM radio, and long-distance amateur radio links.
  * **Vertical Polarization**: Often used for mobile communications, base stations, and handheld VHF/UHF radios.
* **Strict Alignment Requirement**: Because it uses linear polarization, the transmitting and receiving Yagi antennas must be rotated to match the exact same polarization plane (both horizontal or both vertical). A 90-degree mismatch will result in severe signal loss.

### 3. Comparison: Yagi vs. Circularly Polarized Antennas (like Mushroom/Helix)
* **Yagi (Linear)**: Highly efficient for point-to-point fixed links where both ends are static and properly aligned. However, if a drone or mobile device rolls or changes angle, signal strength drops sharply due to polarization mismatch.
* **Mushroom / Helix (Circular)**: Better suited for scenarios involving movement, rotation, or heavy multi-path reflections (like FPV drones or satellite tracking), because circular polarization cares less about the rotational angle of the antenna.


## ref 

