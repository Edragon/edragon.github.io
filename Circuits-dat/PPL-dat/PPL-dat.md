
# PPL-dat

## chip 

- CD4046B == CMOS Micropower Phase-Locked Loop (PLL) with VCO


## info 

A **PLL** is a control system that **locks the phase of its output signal to the phase of an input signal**, commonly used in frequency synthesis, modulation, demodulation, and timing applications.


## 2. Key Features
- **CMOS technology** → low power consumption, high noise immunity
- **Micropower** → suitable for battery-powered circuits
- **Phase Comparator** → detects phase differences between input and feedback
- **Voltage-Controlled Oscillator (VCO)** → generates an output frequency that is controlled by an input voltage
- **Lock Detection** → indicates when PLL is phase-locked


## 3. Block Diagram


    ┌────────────┐
    IN ──►│ Phase Comp │─────► Charge Pump / Filter ──► VCO ──► OUT
    └────────────┘
    ▲
    │
    └────────── Feedback


## 4. Internal Components
1. **Phase Comparator I & II**
   - Compares input signal phase with VCO feedback
   - Generates an error signal proportional to the phase difference

2. **Voltage-Controlled Oscillator (VCO)**
   - Produces output frequency based on control voltage
   - Frequency range can be set by external resistors and capacitors

3. **Low-Pass Filter (External)**
   - Smooths the phase comparator output to control VCO

4. **Lock Detector**
   - Indicates when input and VCO are phase-synchronized

---

## 5. Applications
- Frequency synthesis (e.g., FM/AM transmitters and receivers)
- Frequency demodulation
- Clock generation and synchronization
- Tone decoding
- Phase modulation/demodulation