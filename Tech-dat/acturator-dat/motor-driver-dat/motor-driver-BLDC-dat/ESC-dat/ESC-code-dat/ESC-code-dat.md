

# ESC-code-dat

- [[PWM-dat]]

code 1 

    #include <Servo.h>

    #define ESC_PIN 9          // ESC signal wire (PWM-capable pin)
    #define MIN_PULSE 1000     // microseconds - stop / full reverse
    #define MAX_PULSE 2000     // microseconds - full throttle

    Servo esc;

    void setup() {
    Serial.begin(9600);
    esc.attach(ESC_PIN, MIN_PULSE, MAX_PULSE);

    // --- ESC ARMING SEQUENCE (only required for many ESCs) ---
    esc.writeMicroseconds(MIN_PULSE);   // send minimum signal
    delay(2000);                        // let ESC initialize
    Serial.println("ESC ready. Arming...");
    }

    void loop() {
    // Ramp throttle up, then back down
    for (int pulse = MIN_PULSE; pulse <= MAX_PULSE; pulse += 10) {
        esc.writeMicroseconds(pulse);
        delay(20);
    }
    for (int pulse = MAX_PULSE; pulse >= MIN_PULSE; pulse -= 10) {
        esc.writeMicroseconds(pulse);
        delay(20);
    }
    delay(2000);
    }
