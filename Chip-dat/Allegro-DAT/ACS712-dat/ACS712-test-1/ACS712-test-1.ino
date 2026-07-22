/*
 * ACS712 Current Sensor Demo for ESP32 + WiFi AP Web Monitor
 *
 * Wiring (ADC1 pins only — GPIO19/21 are digital, they DON'T work!):
 *   ACS712 VCC  -> 5V supply
 *   ACS712 GND  -> GND
 *   ACS712 OUT  -> GPIO34  (ADC1_CH6)
 *
 *   Optional: VCC sense via voltage divider -> GPIO35 (ADC1_CH7)
 *   (to measure actual 5V supply for better accuracy)
 *
 * Variants (select SENSITIVITY below):
 *   ACS712-05B: ±5A  -> 0.185 V/A
 *   ACS712-20A: ±20A -> 0.100 V/A  (default)
 *   ACS712-30A: ±30A -> 0.066 V/A
 *
 * Note: ESP32 ADC input max is ~3.3V. If ACS712 output exceeds
 * 3.3V at your max current, add a voltage divider before the ADC pin.
 *
 * IMPORTANT: Only these GPIOs support analogRead on ESP32:
 *   ADC1 (recommended, WiFi-safe): GPIO32-39
 *   ADC2 (conflicts with WiFi):      GPIO0,2,4,12-15,25-27
 * GPIO19 and GPIO21 are digital-only pins — they CANNOT do ADC!
 */

#include <WiFi.h>
#include <WebServer.h>

// ==================== WiFi AP Config ====================
#define AP_SSID     "ACS712-Monitor"
#define AP_PASS     "12345678"        // min 8 characters
#define AP_CHANNEL  1
#define AP_MAX_CLI  4

WebServer server(80);

// ==================== Pin Definitions ====================
// WARNING: Only ADC1 (GPIO32-39) or ADC2 (GPIO0,2,4,12-15,25-27) pins work!
// GPIO19 and GPIO21 are digital-only — they CANNOT read analog values.
#define ACS712_PIN     34          // GPIO34 (ADC1_CH6) = ACS712 analog output
#define VCC_SENSE_PIN  35          // GPIO35 (ADC1_CH7) = VCC sense (voltage divider)

// ==================== ACS712 Parameters ====================
#define SENSITIVITY    0.100       // V/A (100 mV/A for ±20A)
#define VCC_DIVIDER    2.0         // Voltage divider ratio on VCC sense pin
                                   // (e.g., 2 if using 1:1 divider: 5V -> 2.5V)
                                   // Set to 1.0 if directly measuring <3.3V

// ==================== ESP32 ADC Parameters ====================
#define ADC_RES        4095.0      // 12-bit ADC (0-4095)
#define ADC_VREF       6         // ESP32 ADC reference voltage (with 11dB atten)

// ==================== Sensor Readings ====================
float vccMeasured = 5.0;
float current    = 0.0;
float sensorVoltage = 0.0;
int   adcValue   = 0;

// ==================== Read Sensors ====================
void readSensors() {
  // --- Read actual VCC from GPIO21 (voltage divider) ---
  int vccRaw = analogRead(VCC_SENSE_PIN);
  vccMeasured = (vccRaw / ADC_RES) * ADC_VREF * VCC_DIVIDER;
  if (vccMeasured < 3.0 || vccMeasured > 6.0) vccMeasured = 5.0;

  // --- Read ACS712 output from GPIO19 ---
  adcValue = analogRead(ACS712_PIN);
  sensorVoltage = (adcValue / ADC_RES) * ADC_VREF;

  float offsetVoltage = vccMeasured / 2.0;
  current = (sensorVoltage - offsetVoltage) / SENSITIVITY;
}

// ==================== JSON API ====================
void handleAPI() {
  readSensors();
  String json = "{";
  json += "\"current\":"    + String(current, 3) + ",";
  json += "\"voltage\":"    + String(sensorVoltage, 3) + ",";
  json += "\"vcc\":"        + String(vccMeasured, 2) + ",";
  json += "\"adc\":"        + String(adcValue);
  json += "}";
  server.send(200, "application/json", json);
}

// ==================== Web Page ====================
void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>ACS712 Monitor</title>
  <style>
    * { margin:0; padding:0; box-sizing:border-box; }
    body {
      font-family: -apple-system, 'Segoe UI', Roboto, sans-serif;
      background: #0f172a; min-height:100vh;
      display:flex; align-items:center; justify-content:center;
      padding:20px;
    }
    .card {
      background: #1e293b; border-radius:24px;
      padding:40px; width:100%; max-width:480px;
      box-shadow: 0 25px 50px -12px rgba(0,0,0,0.5);
    }
    h1 {
      text-align:center; color:#38bdf8; font-size:28px;
      margin-bottom:32px; letter-spacing:1px;
    }
    .reading { margin-bottom:28px; }
    .label { color:#94a3b8; font-size:14px; margin-bottom:4px; }
    .value {
      color:#f1f5f9; font-size:48px; font-weight:700;
      font-variant-numeric:tabular-nums;
    }
    .unit { color:#64748b; font-size:20px; margin-left:6px; }
    .sub {
      display:flex; justify-content:space-between; margin-top:24px;
      padding-top:24px; border-top:1px solid #334155;
    }
    .sub-item { text-align:center; }
    .sub-item .label { font-size:12px; }
    .sub-item .value { font-size:20px; }
    .badge {
      display:inline-block; background:#0ea5e9; color:#fff;
      padding:4px 14px; border-radius:30px; font-size:12px;
      margin-top:24px;
    }
    .footer {
      text-align:center; color:#475569; font-size:12px;
      margin-top:24px;
    }
  </style>
</head>
<body>
  <div class="card">
    <h1>⚡ ACS712</h1>
    <div class="reading">
      <div class="label">Current</div>
      <div class="value" id="cur">0.000<span class="unit">A</span></div>
    </div>
    <div class="reading">
      <div class="label">Sensor Output</div>
      <div class="value" id="vout">0.000<span class="unit">V</span></div>
    </div>
    <div class="sub">
      <div class="sub-item">
        <div class="label">VCC</div>
        <div class="value" id="vcc">5.00<span class="unit">V</span></div>
      </div>
      <div class="sub-item">
        <div class="label">ADC Raw</div>
        <div class="value" id="adc">0</div>
      </div>
    </div>
    <div style="text-align:center">
      <span class="badge" id="status">● Connected</span>
    </div>
    <div class="footer">Auto-refresh every 500ms</div>
  </div>
  <script>
    async function fetchData() {
      try {
        const r = await fetch('/api');
        const d = await r.json();
        document.getElementById('cur').innerHTML = d.current.toFixed(3) + '<span class="unit">A</span>';
        document.getElementById('vout').innerHTML = d.voltage.toFixed(3) + '<span class="unit">V</span>';
        document.getElementById('vcc').innerHTML = d.vcc.toFixed(2) + '<span class="unit">V</span>';
        document.getElementById('adc').textContent = d.adc;
        document.getElementById('status').textContent = '● Connected';
        document.getElementById('status').style.background = '#22c55e';
      } catch(e) {
        document.getElementById('status').textContent = '● Disconnected';
        document.getElementById('status').style.background = '#ef4444';
      }
    }
    setInterval(fetchData, 500);
    fetchData();
  </script>
</body>
</html>
)rawliteral";
  server.send(200, "text/html", html);
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);

  // --- ADC ---
  analogReadResolution(12);
  analogSetPinAttenuation(ACS712_PIN, ADC_11db);
  analogSetPinAttenuation(VCC_SENSE_PIN, ADC_11db);

  // --- WiFi AP ---
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASS, AP_CHANNEL, 0, AP_MAX_CLI);
  IPAddress ip = WiFi.softAPIP();

  Serial.println("ACS712 + WiFi AP Monitor");
  Serial.println("------------------------");
  Serial.print("AP SSID: ");   Serial.println(AP_SSID);
  Serial.print("AP IP:   ");   Serial.println(ip);
  Serial.print("ADC1 pin (ACS712): GPIO");  Serial.println(ACS712_PIN);
  Serial.print("ADC1 pin (VCC):    GPIO");  Serial.println(VCC_SENSE_PIN);
  Serial.print("Connect and open http://"); Serial.print(ip); Serial.println("/");

  // --- Web Server ---
  server.on("/",        handleRoot);
  server.on("/api",     handleAPI);
  server.begin();
}

// ==================== Loop ====================
void loop() {
  server.handleClient();

  // Serial output every 500ms
  static unsigned long lastPrint = 0;
  if (millis() - lastPrint >= 500) {
    lastPrint = millis();
    readSensors();
    Serial.print("I="); Serial.print(current, 3); Serial.print("A");
    Serial.print("  Vout="); Serial.print(sensorVoltage, 3); Serial.print("V");
    Serial.print("  VCC="); Serial.print(vccMeasured, 2); Serial.print("V");
    Serial.print("  ADC="); Serial.println(adcValue);
  }
}
