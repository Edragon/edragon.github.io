# signal-strength-test-dat





## WIFI 

## 🧭 1. Quick Method (Using Built-in Tools)

### Windows

1. Press `Win + R`, type `cmd`, and press Enter.
2. Run:
   ```bash
   netsh wlan show interfaces
   ```
3. Look for Signal — shown as a percentage (e.g. Signal : 85%).

| Signal % | Quality   |
|----------|-----------|
| 100–80%  | Excellent |
| 80–60%   | Good      |
| 60–40%   | Fair      |
| <40%     | Weak      |

---

### macOS

- Hold Option and click the Wi-Fi icon in the top bar.
- Find RSSI (Received Signal Strength Indicator).

| RSSI (dBm) | Quality   |
|------------|-----------|
| −30        | Excellent |
| −50        | Good      |
| −70        | Poor      |
| <−80       | Unusable  |

---

### Android

- Go to Settings → About Phone → Status → Wi-Fi Signal Strength,
- Or use an app like WiFi Analyzer to see dBm and channel info.

---

### iPhone

- Install Airport Utility.
- Enable “Wi-Fi Scanner” in Settings → Airport Utility.
- Open Airport Utility → Wi-Fi Scan → Start.
- View the RSSI values in dBm.

---

## 🧪 2. Advanced Tools

### Desktop Tools

- inSSIDer
- NetSpot
- Acrylic Wi-Fi Home
- WiFi Explorer

### Mobile Apps

- WiFi Analyzer (Android)
- Fing
- NetSpot
- Network Analyzer

> These display dBm, channel overlap, and throughput data.

---

## 📶 3. Physical Testing

- Walk around your space with the analyzer open.
- Observe how signal strength changes.
- Use a Wi-Fi heatmap to visualize strong and weak areas — helpful for router or mesh placement optimization.

---

## 📊 Signal Strength Reference

| Signal (dBm)   | Quality Description      | Expected Performance                |
|----------------|-------------------------|-------------------------------------|
| −30 to −50     | Excellent               | Maximum speed, stable connection    |
| −51 to −60     | Good                    | Fast, reliable                      |
| −61 to −70     | Fair                    | Usable, may slow down               |
| −71 to −80     | Weak                    | Lag, frequent drops                 |
| <−80           | Very Poor/Unusable      | Likely to disconnect                |



## ref 

- [[signal-dat]] - [[network-dat]]