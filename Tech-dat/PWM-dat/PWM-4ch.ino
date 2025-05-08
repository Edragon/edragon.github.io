    // Define pins for each RC channel
    int aileronPin = 2;   // Channel 1
    int elevatorPin = 3;  // Channel 2
    int throttlePin = 4;  // Channel 3
    int rudderPin = 5;    // Channel 4

    // Variables to store PWM values
    unsigned long aileronPWM;
    unsigned long elevatorPWM;
    unsigned long throttlePWM;
    unsigned long rudderPWM;

    void setup() {
        pinMode(aileronPin, INPUT);
        pinMode(elevatorPin, INPUT);
        pinMode(throttlePin, INPUT);
        pinMode(rudderPin, INPUT);

        Serial.begin(9600);
    }

    void loop() {
        // Read PWM signal for each channel
        // Timeout of 25000 microseconds (25ms) to prevent lockup if a signal is lost
        aileronPWM = pulseIn(aileronPin, HIGH, 25000);
        elevatorPWM = pulseIn(elevatorPin, HIGH, 25000);
        throttlePWM = pulseIn(throttlePin, HIGH, 25000);
        rudderPWM = pulseIn(rudderPin, HIGH, 25000);

        // Print the values to the Serial Monitor
        Serial.print("Aileron: ");
        Serial.print(aileronPWM);
        Serial.print(" us, Elevator: ");
        Serial.print(elevatorPWM);
        Serial.print(" us, Throttle: ");
        Serial.print(throttlePWM);
        Serial.print(" us, Rudder: ");
        Serial.print(rudderPWM);
        Serial.print(" us");


        delay(100);  // Limit output rate to make it readable
    }