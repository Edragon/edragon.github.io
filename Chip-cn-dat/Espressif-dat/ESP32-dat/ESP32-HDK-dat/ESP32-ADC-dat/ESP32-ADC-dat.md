
# ESP32-ADC-dat




## 1. ADC Channels on ESP32

The ESP32 has **two ADCs**:

| ADC   | Channels    | Default GPIOs                       |
|-------|------------|------------------------------------|
| ADC1  | 8 channels (0–7)  | GPIO32–39                        |
| ADC2  | 10 channels (0–9) | GPIO0, 2, 4, 12–15, 25–27, 32–33 |

---

## 2. Recommended Pins for ADC

- **ADC1 pins are preferred**, because ADC2 is shared with Wi-Fi and can cause conflicts if Wi-Fi is active.  

### ADC1 Pins

| Channel  | GPIO |
|----------|------|
| ADC1_CH0 | GPIO36 |
| ADC1_CH1 | GPIO37 |
| ADC1_CH2 | GPIO38 |
| ADC1_CH3 | GPIO39 |
| ADC1_CH4 | GPIO32 |
| ADC1_CH5 | GPIO33 |
| ADC1_CH6 | GPIO34 |
| ADC1_CH7 | GPIO35 |

> ✅ Safe to use for analog input while Wi-Fi is active.

---

## 3. Notes / Caveats

1. **ADC2 pins (GPIO0, 2, 4, 12–15, 25–27, 32–33)**  
   - Using these while Wi-Fi is active may cause conflicts.

2. **Voltage Range**  
   - ADC input: 0–3.3V (default)  
   - Exceeding 3.3V may damage the pin.

3. **Resolution**  
   - Default resolution: 12-bit (0–4095)  
   - Configurable via `analogReadResolution()` in Arduino.

4. **Input Impedance**  
   - ESP32 ADCs have relatively high impedance  
   - For high-impedance sensors, use a buffer/op-amp for accuracy.





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