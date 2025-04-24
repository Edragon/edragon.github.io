
# ESP32-ADC-dat

## ESP32 ADC Input on IO33

### ✅ Can I Use IO33 for ADC Input?
**Yes**, IO33 can be used as an analog input pin on the ESP32.

---

### 📌 IO33 Technical Details
- **GPIO Number**: IO33  
- **ADC Unit**: ADC1  
- **ADC Channel**: `ADC1_CHANNEL_5`  
- **Voltage Input Range**: 
  - **Default**: 0.0V – 1.1V
  - **With Attenuation**:
    | Attenuation | Voltage Range |
    |-------------|----------------|
    | 0 dB        | 0.0 – 1.1 V     |
    | 2.5 dB      | 0.0 – ~1.5 V    |
    | 6 dB        | 0.0 – ~2.2 V    |
    | 11 dB       | 0.0 – ~3.3 V    |

---

### ⚠️ Important Notes
- Maximum safe input: **3.3V**  
- ADC1 is **safe for Wi-Fi use** (ADC2 is not stable when Wi-Fi is on)
- ADC readings may not be perfectly linear — consider calibration for precision

---

🧪 Example Code (Arduino)


    void setup() {
    analogReadResolution(12);          // Set ADC resolution (0–4095)
    analogSetAttenuation(ADC_11db);    // Set to read up to 3.3V
    Serial.begin(115200);
    }

    void loop() {
    int adcValue = analogRead(33);     // Read from GPIO33
    float voltage = adcValue * (3.3 / 4095.0); 
    Serial.println(voltage);
    delay(500);
    }

## ref 

- [[NWI1245-dat]]