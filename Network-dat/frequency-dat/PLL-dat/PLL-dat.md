
# PLL-dat

HMC830LP6GE - Fractional-N PLL with Integrated VCO 25 - 3000 MHz

The HMC830LP6GE is a low noise, wide band, Fractional-N Phase-Locked-Loop (PLL) that features an integrated
Voltage Controlled Oscillator (VCO) with a fundamental frequency of 1500 MHz - 3000 MHz, and an integrated VCO
Output Divider (divide by 1/2/4/6.../60/62), that together allow the HMC830LP6GE to generate frequencies from
25 MHz to 3000 MHz. 




A **Phase-Locked Loop (PLL)** is an **electronic control system** that automatically **locks the phase and frequency** of a generated signal to a reference signal.

---

## Core Purpose
- Generate a **stable frequency**
- Synchronize signals
- Multiply or divide frequencies
- Reduce clock jitter

---

## Main Blocks of a PLL

1. **Phase Detector (PD)**  
   Compares the phase of the reference signal and feedback signal

2. **Loop Filter (LF)**  
   Smooths the phase error signal

3. **Voltage-Controlled Oscillator (VCO)**  
   Adjusts output frequency based on control voltage

4. **Feedback Divider (optional)**  
   Scales output frequency for comparison

---

## How It Works (Simple)

    Reference Clock → Phase Detector → Loop Filter → VCO → Output
    ↑__________________________|


- If output phase ≠ reference phase → correction applied
- Loop continues until **phase lock** is achieved

---

## Key Characteristics
- **Lock Range**: frequencies the PLL can stay locked
- **Capture Range**: frequencies it can initially lock onto
- **Jitter**: short-term timing variations

---

## Common Applications
- Clock generation in CPUs & MCUs
- Frequency synthesis (RF systems)
- Data recovery (USB, Ethernet)
- Motor control and communication systems

---

## In One Line
> **PLL keeps an oscillator perfectly synchronized with a reference signal**