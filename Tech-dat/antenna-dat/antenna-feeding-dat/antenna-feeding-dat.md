


# antenna-feeding-dat

- [[antenna-dat]] - [[antenna-feeding-dat]]


- [[antenna-dipole-dat]]

In RF and antenna engineering, **feeding** and a **center-fed dipole** are foundational concepts for understanding how antennas radiate and receive electromagnetic waves.

---

## What Is Feeding?

**Feeding** is the process of transferring high-frequency electromagnetic energy from a transmitter (or a transmission line such as a microstrip line, coaxial cable, or twin-lead) into an antenna's radiating element—or, conversely, extracting RF signals induced on the antenna and delivering them to a receiver.

Feeding has two core objectives:

1. **Energy Transfer and Excitation**: Establishing alternating or surface currents on the radiator so time-varying electromagnetic fields detach and radiate into space.
2. **Impedance Matching**: Aligning the source or transmission line impedance with the antenna's input impedance ($Z_{\text{in}}$) at the feed point to minimize signal reflection and maximize radiation efficiency.

Common feeding approaches include:

* **Direct (galvanic) feeding**: Connecting a coaxial cable, twin-lead, or microstrip trace directly across a gap or onto the radiating conductor.
* **Coupled (non-contact) feeding**: Using aperture/slot coupling, probe coupling, or inductive coupling—common in microstrip patch antennas—without direct physical connection to the main patch.
* **Feed-point placement**: Options such as **center-fed**, **off-center-fed**, and **end-fed** directly alter the input impedance and current distribution along the antenna.

---

## What Is a Center-Fed Dipole?

A **dipole antenna** typically consists of two collinear conductor arms separated by a small feed gap. When the signal source or transmission line is connected across **that center gap**, you get a **center-fed dipole**.

### Key Characteristics and Principles

* **Symmetry and Current Distribution**: Both arms are usually equal in length (often a total length of a half-wavelength $\lambda/2$, or roughly $\lambda/4$ per arm). At resonance, standing-wave current peaks at the **center feed point (current antinode)** and tapers down to zero at the **outer ends (current nodes)**.
* **Practical Input Impedance**: A half-wave center-fed dipole in ideal free space has a resonant input impedance of about $73\,\Omega$ (resistive part around $73.1\,\Omega$, near-zero reactance), which is relatively close to standard $50\,\Omega$ or $75\,\Omega$ RF systems and straightforward to match.
* **Radiation Pattern**: It provides roughly omnidirectional radiation in the plane perpendicular to the dipole axis (the H-plane / azimuth plane) and a classic figure-eight (doughnut-shaped) pattern in planes containing the axis (the E-plane), with a null along the axis itself.
* **Balance and Common-Mode Currents**: A center-fed dipole is inherently a **balanced** structure with symmetric voltages relative to ground. Feeding it directly with an **unbalanced** coaxial line can induce common-mode currents on the outer shield ("feed-line radiation"), so engineers commonly add a **balun** or choke at the feed point to suppress common-mode currents.

---

## Quick Comparison

| Aspect               | Feeding                                                             | Center-Fed Dipole                                                             |
| -------------------- | ------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| **Essence**          | Energy coupling and interface mechanism between line and antenna    | Specific symmetric two-arm wire antenna fed at the center                     |
| **Primary Focus**    | Feed method, impedance matching, common-mode suppression, feed loss | Arm/total length, resonant frequency, current distribution, radiation pattern |
| **Typical Contexts** | Microstrip feed, coax feed, waveguide slot feed                     | Half-wave dipole, folded/broadband dipole reference                           |



## ref 