
# PWM-dat

- arduino code example  - [[arduino-fading.ino]]



## read RC signal 

- [[RC-link-dat]]

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



## boards 

- [[SCU1063-dat]]

- [[SG3525-dat]]
