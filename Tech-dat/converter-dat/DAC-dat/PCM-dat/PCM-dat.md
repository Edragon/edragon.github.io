


# PCM-dat

- [[PCM-dat]] - [[I2S-dat]] - [[DAC-dat]] - [[DSP-dat]] - [[audio-dat]] - [[digital-dat]]


**PCM (Pulse-Code Modulation)** is the standard way to represent analog sound as **uncompressed digital data**. Whenever a device converts a real-world analog audio wave into digital numbers—or sends raw digital audio between chips on a circuit board—it almost always uses PCM.

### How It Works

An analog sound wave is a smooth, continuous voltage. To turn it into PCM, an **ADC (Analog-to-Digital Converter)** does two things thousands of times per second:

1. **Sampling (Time):** It measures the height (voltage) of the sound wave at fixed intervals.
* **Voice calls (Bluetooth HFP):** Usually sampled at **8 kHz** (narrowband) or **16 kHz** (wideband/HD voice).
* **CD / Music:** Sampled at **44.1 kHz** or **48 kHz**.


2. **Quantization (Amplitude):** It rounds each measurement to the nearest whole number based on **bit depth** (how many bits store each sample).
* **16-bit** (standard for voice and CDs) gives 65,536 possible volume steps per sample.
* **24-bit** (studio audio) gives over 16.7 million steps.



To play it back, a **DAC (Digital-to-Analog Converter)** reads that stream of numbers and reconstructs the smooth analog voltage wave.

---

### What "PCM Interface" Means on a Bluetooth / Microcontroller Board

When a datasheet (like the Bluetooth modules we just looked at) says a board has a **"PCM interface"** (or **I²S**, which is the most common stereo version of PCM), it means the chip exposes **raw digital audio pins** instead of—or in addition to—analog speaker/mic pins.

A typical hardware PCM bus uses **4 wires**:

* **BCLK (Bit Clock):** Ticks once for every single bit of data sent.
* **SYNC / LRCLK (Frame Sync / Left-Right Clock):** Pulses once per audio sample to mark where each sample starts (or switches between Left and Right channels in stereo).
* **DOUT / TX (Data Out):** Carries the outgoing digital audio bits (e.g., incoming phone call audio leaving the Bluetooth chip).
* **DIN / RX (Data In):** Carries incoming digital audio bits (e.g., outgoing voice audio entering the Bluetooth chip).

### Why Engineers Use PCM Instead of Analog Line-In/Out

* **Zero analog noise:** Digital signals don't pick up ground-loop hum, RF interference, or hiss between chips.
* **No extra conversions:** If you're connecting a Bluetooth module to a microcontroller (like an ESP32) or a DSP, sending PCM directly avoids converting Digital → Analog → Digital again.
* **Easy level control:** Volume, mixing, and echo cancellation happen cleanly in software math rather than with resistors and amplifiers.




## ref 