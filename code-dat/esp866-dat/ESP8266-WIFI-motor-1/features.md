# ESP8266 WiFi Motor Chassis Features

## 1. Directional Control (9-Way)
- **8 Directions**: Full support for Forward, Backward, Left, Right, and all four diagonal directions (Forward-Left, Forward-Right, Backward-Left, Backward-Right).
- **Dedicated Stop**: Immediate halt on button release and a centralized "OFF" emergency stop button.

## 2. Advanced Motor Driving
- **Differential Steering**: Implements $Base \pm Offset$ logic for smooth, proportional turning during diagonal movement and pivot rotation.
- **Stall Protection**: Enforces a `minSpeed` floor (100 PWM) to ensure motors maintain torque at low speeds.
- **PWM Optimization**: Optimized for high-frequency (20kHz) PWM modulation for smooth speed control.

## 3. Safety & Reliability
- **Software Watchdog**: A hardware-safe timeout system stops the motors if no command is received within **500ms**, preventing runaway cars in case of WiFi disconnect.
- **Active Heartbeat**: The client browser sends a "keep-alive" signal every **200ms** while any button is held, ensuring seamless motion through minor signal jitters.
- **Interface Sanity**: Prevents "ghost" presses with event `preventDefault()` and stops motors automatically if the browser window loses focus (`blur` event).

## 4. Power Management
- **Battery Compensation**: Selectable modes for **2S (7.4V)** and **3S (11.1V)** battery packs.
- **Voltage Scaling**: Automatically reduces PWM duty cycle in 3S mode (scaling factor $\approx 0.66$) to match 2S speed levels and protect motors from over-voltage.

## 5. Web Interface & Connectivity
- **Standalone Hotspot**: Creates its own WiFi Access Point (`MotorAP`) for direct control without an external router.
- **Responsive Web UI**: A mobile-first controller interface with large touch-friendly buttons and a real-time speed slider.
- **Low Latency**: Lightweight HTTP GET handlers for near-instant control responses.

## 6. Technical Specifications (Default)
- **Controller**: ESP8266
- **Motor Pins**: 
  - Left (M1): Pins 4, 5
  - Right (M2): Pins 0, 2
- **Default Speed**: 200/255
- **Safety Window**: 500ms
