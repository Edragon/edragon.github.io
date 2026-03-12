

# RMT-dat 



## RMT vs. PWM: The Pulse Comparison 

### 1. PWM (Pulse Width Modulation) - "The Metronome"
- CHARACTERISTIC: Constant frequency. The "ON" time and "OFF" time stay 
  the same for every cycle unless you manually change them.
- ANALOGY: A heartbeat. Thump-thump, thump-thump.
- BEST FOR: Dimming LEDs, controlling Motor speed (DRV8701), or Servos.

### 2. RMT (Remote Control) - "The Drummer"
- CHARACTERISTIC: Variable pulse lengths. Every single pulse in a 
  sequence can have a different duration. 
- ANALOGY: Morse Code. Dot-Dash-Dot-Dot. 
- BEST FOR: Complex data (Infrared codes, Neopixel data packets).

### 3. THE DIFFERENCE IN CODE

| Feature         | PWM (LEDC)                      | RMT                            |
|-----------------|---------------------------------|--------------------------------|
| Pulse Pattern   | Repeating (Symmetrical)         | Unique (Custom Sequence)       |
| Data Storage    | 1 Duty Cycle Value              | A Buffer of many pulse lengths |
| Main Goal       | Power/Speed Control             | Information/Data Transfer      |



## info 

RMT is a hardware-based "Pulse Generator" and "Pulse Recorder." It uses a dedicated memory buffer to store a sequence of high/low durations and then "clocks" them out to a pin with nanosecond precision.

### 2. WHY IT EXISTS
Many digital devices (like WS2812B LEDs or IR Sensors) require signals timed 
down to the microsecond.
- Doing this with the CPU (using `delayMicroseconds`) is unreliable because 
  interrupts or Wi-Fi tasks can "jitter" the timing.
- RMT handles the timing in hardware, leaving the CPU free for other tasks.

### 3. THE ANALOGY: "The Music Box"
- THE CPU: The composer who writes the sheet music (the pulse sequence).
- RMT BUFFER: The sheet music itself.
- RMT PERIPHERAL: The music box mechanism that plays the notes at a 
  perfect, steady rhythm without the composer being present.

### 4. COMMON USE CASES
- ADDRESSABLE LEDS: Driving WS2812B (Neopixels) with perfect timing.
- IR REMOTES: Sending or receiving TV/AirCon remote codes (Sony, NEC, etc.).
- STEPPER MOTORS: Generating precise pulse trains for motor drivers.
- CUSTOM PROTOCOLS: Any 1-wire or bit-banged protocol that is timing-sensitive.

### 5. RMT vs. ISR vs. DMA
- ISR: Reacts to a signal (CPU is involved).
- DMA: Moves bulk data (CPU is bypassed).
- RMT: "Sculpts" a signal (Hardware handles the clock and timing).

### 6. KEY SPECIFICATIONS (ESP32)
- Channels: 8 channels (4 TX / 4 RX) on original ESP32.
- Resolution: Based on the APB clock (usually 12.5ns per "tick").
- Hardware Buffer: Small RAM dedicated to storing the pulse "on/off" pattern.