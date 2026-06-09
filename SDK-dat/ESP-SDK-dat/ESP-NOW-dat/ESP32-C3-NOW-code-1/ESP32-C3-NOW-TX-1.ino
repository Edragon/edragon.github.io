#include <esp_now.h>
#include <WiFi.h>
#include <esp_wifi.h>

// REPLACE WITH YOUR ESP32-C3 MAC ADDRESS
uint8_t broadcastAddress[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

// Joystick Analog Input Pins
const int PIN_THROTTLE = 1; 
const int PIN_STEERING = 2;

typedef struct struct_message {
    int16_t throttle;
    int16_t steering;
} struct_message;

struct_message outgoingData;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    // Optional transmission debugging over serial
}

void setup() {
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    // Force matching Long Range Mode and Max Power on the S3 side
    esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_LR);
    esp_wifi_set_max_tx_power(84);

    if (esp_now_init() != ESP_OK) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_register_send_cb(OnDataSent);
    
    // Register Peer Car
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 1;  // Bound cleanly to fixed Channel 1 
    peerInfo.encrypt = false;
    
    if (esp_now_add_peer(&peerInfo) != ESP_OK){
        Serial.println("Failed to add peer");
        return;
    }
}

void loop() {
    // Read your remote joysticks (Maps standard 12-bit ADC 0-4095 down to signed -255 to 255)
    int16_t rawThrottle = analogRead(PIN_THROTTLE);
    int16_t rawSteering = analogRead(PIN_STEERING);

    outgoingData.throttle = map(rawThrottle, 0, 4095, -255, 255);
    outgoingData.steering = map(rawSteering, 0, 4095, -255, 255);

    // Tiny deadzone filter to prevent motor creep at center stick
    if(abs(outgoingData.throttle) < 15) outgoingData.throttle = 0;
    if(abs(outgoingData.steering) < 15) outgoingData.steering = 0;

    // Transmit control packet over the LR link layer
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *) &outgoingData, sizeof(outgoingData));
    
    delay(20); // 50Hz refresh rate is standard for smooth responsive driving
}