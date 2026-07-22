

# motor-driver-mosfet-dat

- [[motor-driver-mosfet-dat]] - [[motor-driver-dat]] - [[motor-driver-design-dat]] - [[motor-driver-dead-time-protection-dat]] - [[ELRS-TX-setup-motor-dual-dat]]

- [[ESP32-dat]]

### Smart MCU Safety Firewall Architecture

Introducing a microcontroller unit (MCU)—such as an **Arduino Nano, ESP32-S3, RP2040, or STM32**—is an excellent way to use your existing MOSFET driver board without any risk of burning it. 

By placing an MCU between your ELRS receiver and your MOSFET board, the MCU acts as a **smart safety firewall**. It intercepts the incoming radio signals, strips out any dangerous channel conflicts, inserts a mandatory **"dead-time" delay**, and outputs pristine, un-shortable control signals to your `IN1/IN2` board.

---

### 1. System Architecture

In this setup, you change your ELRS receiver back to its default **CRSF protocol** output (serial data), rather than converting it to individual physical PWM pins. The MCU reads the digital data stream directly over a serial port.

```text
 ┌───────────────┐  CRSF Serial Data  ┌───────────┐  Safe Interlocked PWM  ┌──────────────┐
 │ ELRS Receiver │───────────────────►│    MCU    │───────────────────────►│ MOSFET Board │
 └───────────────┘   (TX pin to RX)   └───────────┘     (IN1/IN2 Pins)     └──────────────┘
```

### 2. The 3 Safety Tasks the MCU Code Performs

To ensure your MOSFET driver never burns again, your MCU code must execute three specific safety algorithms:

#### A. Software Mutual Exclusion (Interlocking)
The code must contain a strict constraint that makes it physically impossible for both pins to be high at the same time.
*   **The Rule:** If `IN1` is greater than 0, `IN2` is strictly forced to 0.

#### B. Dead-Time Insertion (The MOSFET Life-Saver)
MOSFETs do not turn off instantly; they take a fraction of a microsecond to completely discharge their gate capacitance. If you turn on `IN2` at the exact same microsecond you turn off `IN1`, they will still overlap and cause a short circuit.
*   **The Rule:** When changing motor directions from forward to reverse, the MCU must turn both pins to 0V, pause/delay for a brief safety window (e.g., 10 to 50 microseconds), and only then turn the opposite pin on.

#### C. Startup and Failsafe Protection
When an MCU boots up, its I/O pins can float randomly for a few milliseconds, which can trigger the driver board.
*   **The Rule:** The very first lines in your `setup()` code must explicitly declare your output pins as `OUTPUT` and write them immediately to `LOW` (0V). Furthermore, if the MCU stops receiving CRSF data packets from the ELRS receiver for more than 100ms, it must automatically execute an emergency shutdown loop to kill power to all pins.

### 3. Example Safety Code Structure (Arduino / C++ Concept)

Here is a conceptual example of how to implement the interlocking and dead-time logic inside the MCU's motor control function:

```cpp
// Define physical pins connected to your MOSFET board
const int MOTOR_A_IN1 = 5; 
const int MOTOR_A_IN2 = 6;

// Track the previous state to know when a direction switch happens
int lastDirection = 0; // 0 = stopped, 1 = forward, 2 = backward
const int DEAD_TIME_US = 50; // 50 microseconds of safety dead-time

void driveMotorA(int targetSpeed) {
  // targetSpeed ranges from -255 (Full Reverse) to +255 (Full Forward)
  
  if (targetSpeed == 0) {
    analogWrite(MOTOR_A_IN1, 0);
    analogWrite(MOTOR_A_IN2, 0);
    lastDirection = 0;
  }
  else if (targetSpeed > 0) { // Forward commanded
    // If we were previously going backward, enforce a dead-time pause
    if (lastDirection == 2) {
      analogWrite(MOTOR_A_IN2, 0);
      delayMicroseconds(DEAD_TIME_US); 
    }
    analogWrite(MOTOR_A_IN2, 0);       // 100% Guaranteed exclusion: IN2 is OFF
    analogWrite(MOTOR_A_IN1, targetSpeed); // Apply PWM speed to IN1
    lastDirection = 1;
  }
  else if (targetSpeed < 0) { // Backward commanded
    // If we were previously going forward, enforce a dead-time pause
    if (lastDirection == 1) {
      analogWrite(MOTOR_A_IN1, 0);
      delayMicroseconds(DEAD_TIME_US);
    }
    analogWrite(MOTOR_A_IN1, 0);       // 100% Guaranteed exclusion: IN1 is OFF
    analogWrite(MOTOR_A_IN2, abs(targetSpeed)); // Apply PWM speed to IN2
    lastDirection = 2;
  }
}
```

### 4. Hardware Bonus: Keep it Simple on Your Remote

Because the MCU runs the safety logic and handles the motor math, you can delete all the complex mixing, weights, offsets, and multipliers from your RadioMaster Pocket. You can set your remote back to a standard, clean setup where your sticks naturally rest at 1500 (center). The MCU reads that central "1500" value over the serial line, understands it means "Stop", and smoothly handles the translation to your MOSFET board with zero risk of smoke!


## ref 


