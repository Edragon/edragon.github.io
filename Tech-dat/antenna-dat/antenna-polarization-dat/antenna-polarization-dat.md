

# antenna-polarization-dat



by - [[antenna-polarization-dat]] - [[antenna-type-dat]]




- [[antenna-dat]] Polarization == - [[antenna-RHCP-dat]] - [[antenna-linear-dat]] - [[antenna-polarization-dat]]

- [[antenna-diversity-dat]]

## polarization mismatch 

🔬 Basic principle

Antenna polarization comes in two types:
- Linear: ordinary "rod/vertical" antennas (your stock VR03 antenna is one) - [[antenna-linear-dat]]
- Circular: mushroom, disc, Cloverleaf types (your maple-leaf disc) - [[antenna-RHCP-dat]]

Matching rules:

| TX (VTX) polarization | VRX (goggles antenna) polarization | Result                     | Loss   |
| --------------------- | --------------------------------- | -------------------------- | ------ |
| Linear                | Linear (aligned)                  | ✅ Best                     | 0dB    |
| Linear                | Circular                          | ⚠️ Power cut in half       | -3dB   |
| Circular              | Circular (same handedness)        | ✅ Good (and pose-tolerant) | 0dB    |
| Circular              | Circular (opposite handedness)    | ❌ Disaster                 | -20dB+ |

🎯 Your case is most likely

X111 VTX antenna = Linear (rod)
Stock VR03 antenna = Linear → matched ✅ best performance
Maple-leaf disc antenna = Circular → mismatch -3dB ❌ so it feels worse


-3dB = signal power cut in half → your feeling matches physics exactly, it's not an illusion ✅





## apps 

- [[antenna-FPV-dat]] - [[antenna-location-dat]] 




## ref 