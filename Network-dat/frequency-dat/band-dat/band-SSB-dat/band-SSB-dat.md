

# band-SSB-dat

- [[frequency-dat]] - [[oscillator-dat]] - [[Oscilloscope-dat]] - [[band-dat]] - [[SDR-dat]] - [[band-SSB-dat]] 

- [[band-dat]] - [[band-SSB-dat]] - [[DSP-dat]]


- [[radio-dat]]


**SSB** stands for **Single Sideband**, a type of amplitude modulation (AM) widely used in **SDR (Software Defined Radio)** and traditional radio communications for voice transmission. 

To understand what it means in an SDR context, it helps to break down how radio signals are structured and how software processing handles them.

### 1. The Core Concept (Why "Single Sideband"?)
Standard AM radio transmits a carrier wave plus *two* identical sidebands (upper and lower) that contain the actual audio information. This is inefficient because:
* **Wasted Power:** Most of the transmitter's energy goes into the carrier wave, which carries no audio data.
* **Wasted Bandwidth:** Both sidebands contain the exact same audio information, taking up twice as much radio spectrum as necessary.

SSB solves this by mathematically or electronically **suppressing the carrier** and **filtering out one of the sidebands**, leaving only one:
* **USB (Upper Sideband):** Transmits only the frequency spectrum *above* the carrier frequency. Commonly used on amateur radio bands above 10 MHz (e.g., 20m, 17m, 15m, 10m bands).
* **LSB (Lower Sideband):** Transmits only the frequency spectrum *below* the carrier frequency. Commonly used on amateur radio bands below 10 MHz (e.g., 80m, 40m bands).

### 2. How SSB Works in an SDR

In a traditional hardware radio, generating and receiving SSB requires precise, expensive analog crystal filters and mixers. In an **SDR**, SSB demodulation and generation are handled almost entirely in **digital signal processing (DSP)** software (like SDR#, GQRX, HDSDR, or GNU Radio).

When you tune an SDR to an SSB signal:
1. **Quadrature Sampling:** The SDR hardware captures a slice of the radio spectrum using an Analog-to-Digital Converter (ADC) and outputs I/Q (In-phase and Quadrature) data streams.
2. **Frequency Translation & Filtering:** The SDR software shifts the tuned frequency and applies a sharp digital bandpass filter (typically around 2.4 kHz wide for voice) to isolate either the upper or lower sideband.
3. **Reinserting the Carrier (BFO):** Because the original carrier was suppressed, raw SSB audio sounds like garbled "duck-quack" noises. The SDR software uses a **Beat Frequency Oscillator (BFO)**—a software oscillator—to mathematically reinsert a virtual carrier at the exact correct frequency so the audio becomes intelligible human speech.

### 3. Key Advantages in SDR
* **Efficiency:** Because all power goes into a single narrow band, SSB signals can travel much farther with less transmitter power compared to standard AM.
* **Narrow Bandwidth:** An SSB voice channel only takes up about 2.4 kHz to 3 kHz of spectrum space, allowing many more conversations to fit into crowded amateur radio bands.
* **Flexibility:** Because SDRs process signals in software, you can instantly switch between USB, LSB, or adjust filter widths with a click of a mouse, achieving a level of audio tuning precision that old analog radios struggled to match.



## ref 

