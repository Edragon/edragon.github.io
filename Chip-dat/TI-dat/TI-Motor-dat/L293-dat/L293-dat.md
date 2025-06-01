
# L293-dat

## Info 
 
chip info, [datasheet](https://www.ti.com/lit/ds/symlink/l293.pdf), etc.

The L293D is a 16-pin motor driver IC, also known as a quad half-H driver, capable of controlling two DC motors or a single stepper motor, offering bidirectional drive currents of up to 600mA per channel at voltages from 4.5V to 36V. 

![](2025-03-25-15-46-12.png)

## App. 

- [[SDR1064-dat]] - [[nodemcu-dat]]

- [[SDR1060-dat]] - [[arduino-ide-dat]]


## 🔌 L293 vs L293D: Key Differences

| Feature                     | **L293**              | **L293D**                          |
| --------------------------- | --------------------- | ---------------------------------- |
| **Internal Flyback Diodes** | ❌ No                  | ✅ Yes (built-in protection diodes) |
| **Maximum Output Current**  | Up to 1 A (peak 2 A)  | Up to 600 mA (peak 1.2 A)          |
| **Cost**                    | Slightly cheaper      | Slightly more expensive            |
| **Protection**              | Needs external diodes | Protected against back EMF         |



## demo code 

- single DC motor control [[afMotor-1.ino]]

### simple demo code 

    // Pin definitions
    const int ENA = 9;
    const int IN1 = 8;
    const int IN2 = 7;

    void setup() {
        pinMode(ENA, OUTPUT);
        pinMode(IN1, OUTPUT);
        pinMode(IN2, OUTPUT);
    }

    void loop() {
        // Forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 200);  // PWM speed (0~255)
        delay(2000);

        // Stop
        analogWrite(ENA, 0);
        delay(1000);

        // Backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENA, 200);
        delay(2000);

        // Stop
        analogWrite(ENA, 0);
        delay(1000);
    }

### simple demo code with inverter 



    const int ENA = 9;  // PWM for speed
    const int IN1 = 8;  // Direction (IN2 is inverted in hardware)

    void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    }

    void loop() {
    // Forward
    digitalWrite(IN1, HIGH);  // IN2 becomes LOW due to inverter
    analogWrite(ENA, 200);    // Set speed
    delay(2000);

    // Stop
    analogWrite(ENA, 0);
    delay(1000);

    // Backward
    digitalWrite(IN1, LOW);   // IN2 becomes HIGH due to inverter
    analogWrite(ENA, 200);    // Set speed
    delay(2000);

    // Stop
    analogWrite(ENA, 0);
    delay(1000);
    }



## ref 

- [[SDR1064-dat]] - [[motor-driver-dat]]
 
- [[74LVC2G04-dat]] - [[logic-inverter-dat]] - [[logic-gate-dat]]

- [[L293]] - [[TI-motor]]
 

