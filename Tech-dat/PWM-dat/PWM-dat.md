# PWM-dat

- arduino code example  - [[arduino-fading.ino]]

## read RC signal 

- [[RC-link-dat]] - [[PPM-dat]]

Basic setup:

Connect the signal wire of each channel (e.g., throttle and elevator) to two digital pins on the Arduino (e.g., D2 and D3).

Use pulseIn() to read the high-pulse duration.

    int throttlePin = 2;
    int elevatorPin = 3;
    unsigned long throttlePWM;
    unsigned long elevatorPWM;

    void setup() {
        pinMode(throttlePin, INPUT);
        pinMode(elevatorPin, INPUT);
        Serial.begin(9600);
    }

    void loop() {
        throttlePWM = pulseIn(throttlePin, HIGH, 25000);  // Timeout to prevent lockup
        elevatorPWM = pulseIn(elevatorPin, HIGH, 25000);

        Serial.print("Throttle: ");
        Serial.print(throttlePWM);
        Serial.print(" us, Elevator: ");
        Serial.print(elevatorPWM);
        Serial.println(" us");

        delay(100);  // Limit output rate
    }

update into four channels, and add timeout to prevent lockup if a signal is lost.

    // Define pins for each RC channel
    int aileronPin = 2;   // Channel 1
    int elevatorPin = 3;  // Channel 2
    int throttlePin = 4;  // Channel 3
    int rudderPin = 5;    // Channel 4
    // Channel 5 is often unused or for gear/aux, skipping for this example
    int flapPitchPin = 6; // Channel 6

    // Variables to store PWM values
    unsigned long aileronPWM;
    unsigned long elevatorPWM;
    unsigned long throttlePWM;
    unsigned long rudderPWM;
    unsigned long flapPitchPWM;

    void setup() {
        pinMode(aileronPin, INPUT);
        pinMode(elevatorPin, INPUT);
        pinMode(throttlePin, INPUT);
        pinMode(rudderPin, INPUT);
        pinMode(flapPitchPin, INPUT);
        Serial.begin(9600);
    }

    void loop() {
        // Read PWM signal for each channel
        // Timeout of 25000 microseconds (25ms) to prevent lockup if a signal is lost
        aileronPWM = pulseIn(aileronPin, HIGH, 25000);
        elevatorPWM = pulseIn(elevatorPin, HIGH, 25000);
        throttlePWM = pulseIn(throttlePin, HIGH, 25000);
        rudderPWM = pulseIn(rudderPin, HIGH, 25000);
        flapPitchPWM = pulseIn(flapPitchPin, HIGH, 25000);

        // Print the values to the Serial Monitor
        Serial.print("Aileron: ");
        Serial.print(aileronPWM);
        Serial.print(" us, Elevator: ");
        Serial.print(elevatorPWM);
        Serial.print(" us, Throttle: ");
        Serial.print(throttlePWM);
        Serial.print(" us, Rudder: ");
        Serial.print(rudderPWM);
        Serial.print(" us, Flap/Pitch: ");
        Serial.print(flapPitchPWM);
        Serial.println(" us");

        delay(100);  // Limit output rate to make it readable
    }

Description:

- **throttlePWM**: Variable to store the duration (in microseconds) of the incoming PWM signal.
- **pulseIn()**: Arduino function that measures how long a pin stays at a specified level (HIGH or LOW).
- **throttlePin**: Digital pin receiving the PWM signal (e.g., from an RC receiver).
- **HIGH**: Measure the duration of the HIGH part of the PWM pulse.
- **25000**: Timeout value in microseconds (25 ms). If no pulse is detected within this time, the function returns 0.

## boards 

- [[SCU1063-dat]]

- [[SG3525-dat]]
