

# 27mhz-dat

- [[27mhz-dat]] - [[frequency-dat]] - [[frequency-rc-dat]]

The use of the 27 MHz frequency in RC boats comes down to two main factors: **the physics of how radio waves interact with water** and **manufacturing costs**. 

While modern hobby-grade RC cars and drones have almost entirely moved to the 2.4 GHz band, water presents a unique physical barrier that makes the older, lower 27 MHz frequency highly advantageous for boats and submarines.

---

## The Physics of Water and Radio Waves

Radio waves are electromagnetic radiation, and their frequency dictates their wavelength. 
* **27 MHz** has a very long wavelength of about **11 meters**.
* **2.4 GHz** (used in modern Wi-Fi and most drones) has a very short wavelength of about **12.5 centimeters**.

Water—especially conductive water with impurities—is excellent at absorbing and reflecting high-frequency radio waves. In fact, 2.4 GHz is the exact same frequency your microwave oven uses to heat the water molecules in your food. 

Because of this, 2.4 GHz signals cannot penetrate water effectively. If a 2.4 GHz wave hits the surface of a lake, it largely bounces off or gets instantly absorbed. If an RC boat using 2.4 GHz takes on a heavy splash, flips over, or dips its receiver antenna below the water line, the signal drops to zero immediately. 

The much longer waves of 27 MHz can easily "punch through" water splashes and wave crests. More importantly, 27 MHz can actually penetrate several feet of fresh water. For RC submarines, lower frequencies (like 27 MHz, 40 MHz, or 75 MHz) are strictly mandatory, as a 2.4 GHz signal will fail if the submarine dives more than an inch below the surface.

> **Key insight:** The longer the wavelength, the better it ignores small obstacles like water droplets and wave crests. 

---

## Cost and Legacy

Beyond physics, 27 MHz is heavily used in "toy-grade" RC boats for economic reasons:

1.  **Unlicensed Band:** 27 MHz is part of the ISM (Industrial, Scientific, and Medical) and Citizen's Band (CB) spectrum. It has been free for consumer use globally for decades.
2.  **Extremely Cheap Electronics:** The basic analog AM or FM crystal components required to build a 27 MHz transmitter and receiver cost literal pennies to manufacture. 
3.  **Simplicity:** Toy manufacturers already have massive supply chains built around 27 MHz boards, making it the easiest plug-and-play solution for cheap aquatic toys.

## 27 MHz vs. 2.4 GHz in RC Boats

| Feature               | 27 MHz                                   | 2.4 GHz                            |
| :-------------------- | :--------------------------------------- | :--------------------------------- |
| **Water Penetration** | Excellent (can reach submarines)         | Non-existent (bounces or absorbs)  |
| **Splash Resistance** | Unaffected by surface splashes           | Splashes can cause signal drops    |
| **Antenna Length**    | Requires a long, external wire           | Very short (often hidden inside)   |
| **Interference**      | High (easy to cross signals with others) | Zero (digitally bound to receiver) |
| **Response Time**     | Noticeable analog lag                    | Instant digital response           |

Today, high-end hobby RC boats actually *do* use 2.4 GHz, but they require a specific design workaround: the receiver antenna must be routed through a plastic tube that sticks straight up, ensuring the tip remains strictly above the water line at all times.