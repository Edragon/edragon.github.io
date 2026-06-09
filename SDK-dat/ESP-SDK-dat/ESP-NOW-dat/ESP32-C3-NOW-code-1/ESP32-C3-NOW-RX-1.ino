#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

// --- Pin Allocations ---
// Motor A (Left)
const int M1_PWM = 6;
const int M1_DIR = 7;

// Motor B (Right)
const int M2_PWM = 9;
const int M2_DIR = 10;

// --- PWM Properties ---
const int PWM_FREQ = 5000;      // 5kHz keeps the motor humming quiet
const int PWM_RES  = 8;         // 8-bit resolution (0-255)

// --- ESP-NOW Payload Structure ---
// Must match the transmitter's struct exactly
typedef struct struct_message {
    int16_t throttle;  // -255 to 255 (Forward / Reverse)
    int16_t steering;  // -255 to 255 (Left / Right)
} struct_message;

struct_message incomingData;

// --- Motor Control Helper Function ---
void driveMotors(int16_t throttle, int16_t steering) {
    // Simple differential drive mixing
    int16_t leftSpeed  = throttle + steering;
    int16_t rightSpeed = throttle - steering;

    // Constrain to valid 8-bit PWM bounds
    leftSpeed  = constrain(leftSpeed, -255, 255);
    rightSpeed = constrain(rightSpeed, -255, 255);

    // Control Motor A (Left)
    if (leftSpeed >= 0) {
        digitalWrite(M1_DIR, LOW);
        analogWrite(M1_PWM, leftSpeed);
    } else {
        digitalWrite(M1_DIR, HIGH);
        analogWrite(M1_PWM, 255 + leftSpeed); // Invert PWM for inverted logic direction pins
    }

    // Control Motor B (Right)
    if (rightSpeed >= 0) {
        digitalWrite(M2_DIR, LOW);
        analogWrite(M2_PWM, rightSpeed);
    } else {
        digitalWrite(M2_DIR, HIGH);
        analogWrite(M2_PWM, 255 + rightSpeed);
    }
}

// --- ESP-NOW Callback Execution ---
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingDataRaw, int len) {
    memcpy(&incomingData, incomingDataRaw, sizeof(incomingData));
    
    // Pass the received control parameters straight to the motor driver
    driveMotors(incomingData.throttle, incomingData.steering);
}

void setup() {
    Serial.begin(115200);

    // Initialize Motor Pins
    pinMode(M1_PWM, OUTPUT);
    pinMode(M1_DIR, OUTPUT);
    pinMode(M2_PWM, OUTPUT);
    pinMode(M2_DIR, OUTPUT);

    // Set up PWM properties for analogWrite
    analogWriteFrequency(M1_PWM, PWM_FREQ);
    analogWriteResolution(M1_RES);
    analogWriteFrequency(M2_PWM, PWM_FREQ);
    analogWriteResolution(PWM_RES);

    // Initialize Wi-Fi in Station Mode
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    // 1. Force Long Range (LR) Mode Protocol for hardware-level reliability
    esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_LR);

    // 2. Maximize internal TX Power to 21dBm
    esp_wifi_set_max_tx_power(84);

    // Initialize ESP-NOW Protocol
    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    // Register the Receive Callback
    esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
    
    Serial.println("Receiver Ready. Waiting for packet data...");
}

void loop() {
    // Keep loop non-blocking. ESP-NOW relies entirely on hardware interrupts.
}