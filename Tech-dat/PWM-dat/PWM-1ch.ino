// Define pins for each RC channel
int aileronPin = 2;   // Channel 1

const int ENA = 5; // PWM for speed for Motor 1
const int IN1 = 0; // Direction for Motor 1 (IN2_Motor1 is inverted in hardware)

long aileronControl;

long readAileronControlSignal() {
    unsigned long rawPWM = pulseIn(aileronPin, HIGH, 25000);
    if (rawPWM == 0) { // Timeout or no signal
        return 50; // Mid-point for 0-100 scale (1500us equivalent)
    }
    long constrainedPWM = constrain(rawPWM, 1000, 2000);
    return map(constrainedPWM, 1000, 2000, 0, 100);
}



void setup() {
    pinMode(aileronPin, INPUT);

    Serial.begin(9600);
}

void loop() {
    // Read mapped control signals from each channel
    aileronControl = readAileronControlSignal();

    // Print the mapped control signal values to the Serial Monitor
    Serial.print("Aileron: ");
    Serial.print(aileronControl);
    Serial.println(); // Newline for better readability

    delay(100);  // Limit output rate
}