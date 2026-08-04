/*
 * ESP32 Dual MOSFET Motor Driver Demo — WiFi AP Web Control
 *
 * Controls two DC motors via MOSFET driver (IN1/IN2 per motor).
 * Uses PWM for speed control. Web interface over WiFi AP mode.
 *
 * Wiring (MOSFET driver → ESP32):
 *   Motor 1: IN1 → GPIO4   IN2 → GPIO5
 *   Motor 2: IN1 → GPIO14  IN2 → GPIO15
 *
 * Motor control logic:
 *   IN1  IN2  |  Motor
 *   HIGH LOW  |  Forward
 *   LOW  HIGH |  Reverse
 *   HIGH HIGH |  Brake (short)
 *   LOW  LOW  |  Coast (free)
 */

#include <WiFi.h>
#include <WebServer.h>

// ==================== WiFi AP Config ====================
#define AP_SSID      "ESP32-Motor"
#define AP_PASS      "12345678"
#define AP_CHANNEL   1
#define AP_MAX_CLI   4

WebServer server(80);

// ==================== Pin Definitions ====================
#define M1_IN1   4
#define M1_IN2   5
#define M2_IN1   14
#define M2_IN2   15

// ==================== PWM Parameters ====================
#define PWM_FREQ     5000        // 5 kHz
#define PWM_RES      8           // 8-bit (0-255)
// New ESP32 Core 3.x+ API: ledcAttach(pin, freq, res) + ledcWrite(pin, duty)
// No channel numbers needed — use pins directly.

// ==================== Dead-Time Protection ====================
// Prevents shoot-through (both MOSFETs on same bridge leg conducting)
// when switching direction. Adjust based on your MOSFET driver's
// turn-off delay (typical: 1-10 µs for gate drivers, up to 1 µs is safe).
#define DEAD_TIME_US  5           // microseconds

// Track previous direction: 1=forward, -1=reverse, 0=stop
int prevDirM1 = 0;
int prevDirM2 = 0;

// Currently active speeds (for web UI feedback)
int m1Speed = 0;
int m2Speed = 0;

// ==================== Motor Control with Dead-Time ====================

void motorWrite(int in1Pin, int in2Pin, int speed,
                int *prevDir, int *storeSpeed) {
  int newDir = (speed > 0) ? 1 : (speed < 0) ? -1 : 0;

  // Dead-time: if direction changed (forward↔reverse), insert break
  if (*prevDir != 0 && newDir != 0 && *prevDir != newDir) {
    ledcWrite(in1Pin, 0);
    ledcWrite(in2Pin, 0);
    delayMicroseconds(DEAD_TIME_US);
  }

  *prevDir = newDir;
  *storeSpeed = speed;

  if (speed > 0) {
    ledcWrite(in1Pin, speed);   // IN1 = PWM
    ledcWrite(in2Pin, 0);       // IN2 = LOW
  } else if (speed < 0) {
    ledcWrite(in1Pin, 0);       // IN1 = LOW
    ledcWrite(in2Pin, -speed);  // IN2 = PWM
  } else {
    ledcWrite(in1Pin, 0);       // IN1 = LOW (coast)
    ledcWrite(in2Pin, 0);       // IN2 = LOW
  }
}

void motorBrake(int in1Pin, int in2Pin, int *storeSpeed) {
  ledcWrite(in1Pin, 255);
  ledcWrite(in2Pin, 255);
  *storeSpeed = 0;
}

void motorCoast(int in1Pin, int in2Pin, int *storeSpeed) {
  ledcWrite(in1Pin, 0);
  ledcWrite(in2Pin, 0);
  *storeSpeed = 0;
}

// ==================== Web Handlers ====================

void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html lang="zh-CN">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1.0">
<title>Motor Controller</title>
<style>
*{margin:0;padding:0;box-sizing:border-box}
body{font-family:-apple-system,'Segoe UI',Roboto,sans-serif;background:#0f172a;color:#f1f5f9;min-height:100vh;display:flex;align-items:center;justify-content:center;padding:16px}
.card{background:#1e293b;border-radius:24px;padding:32px;width:100%;max-width:520px;box-shadow:0 25px 50px -12px rgba(0,0,0,.5)}
h1{text-align:center;color:#38bdf8;font-size:24px;margin-bottom:24px}
.motor-block{background:#334155;border-radius:16px;padding:20px;margin-bottom:16px}
.motor-header{display:flex;justify-content:space-between;align-items:center;margin-bottom:12px}
.motor-title{font-size:16px;font-weight:600;color:#94a3b8}
.motor-speed{font-size:28px;font-weight:700;font-variant-numeric:tabular-nums}
.speed-val{color:#38bdf8}
.slider{width:100%;-webkit-appearance:none;height:6px;border-radius:3px;background:#475569;outline:none;margin:8px 0}
.slider::-webkit-slider-thumb{-webkit-appearance:none;width:22px;height:22px;border-radius:50%;background:#0ea5e9;cursor:pointer}
.slider::-moz-range-thumb{width:22px;height:22px;border-radius:50%;background:#0ea5e9;cursor:pointer;border:none}
.labels{display:flex;justify-content:space-between;font-size:12px;color:#64748b;margin-bottom:8px}
.btns{display:flex;gap:8px;margin-top:8px}
.btn{flex:1;padding:10px;border:none;border-radius:10px;font-size:14px;font-weight:600;cursor:pointer;transition:opacity .2s}
.btn:active{opacity:.7}
.btn-stop{background:#64748b;color:#fff}
.btn-brake{background:#ef4444;color:#fff}
.btn-both{display:block;width:100%;padding:14px;border:none;border-radius:12px;font-size:16px;font-weight:700;cursor:pointer;margin-top:8px}
.btn-stop-all{background:#64748b;color:#fff}
.btn-brake-all{background:#ef4444;color:#fff}
.status{text-align:center;margin-top:16px;font-size:13px;color:#64748b}
.dot{display:inline-block;width:8px;height:8px;border-radius:50%;margin-right:6px}
.dot.on{background:#22c55e}
.dot.off{background:#ef4444}
</style>
</head>
<body>
<div class="card">
  <h1>🔧 Motor Controller</h1>

  <div class="motor-block">
    <div class="motor-header">
      <span class="motor-title">Motor 1 <span style="color:#64748b;font-size:12px">(GPIO4/5)</span></span>
      <span class="motor-speed"><span class="speed-val" id="s1">0</span></span>
    </div>
    <input type="range" class="slider" id="sl1" min="-255" max="255" value="0">
    <div class="labels"><span>◀ Reverse</span><span>Stop</span><span>Forward ▶</span></div>
    <div class="btns">
      <button class="btn btn-stop" onclick="fetch('/motor?m1=0').then(r=>r.json()).then(d=>document.getElementById('s1').textContent=d.m1)">Coast</button>
      <button class="btn btn-brake" onclick="fetch('/motor?m1=-999').then(r=>r.json()).then(d=>document.getElementById('s1').textContent=d.m1)">Brake</button>
    </div>
  </div>

  <div class="motor-block">
    <div class="motor-header">
      <span class="motor-title">Motor 2 <span style="color:#64748b;font-size:12px">(GPIO14/15)</span></span>
      <span class="motor-speed"><span class="speed-val" id="s2">0</span></span>
    </div>
    <input type="range" class="slider" id="sl2" min="-255" max="255" value="0">
    <div class="labels"><span>◀ Reverse</span><span>Stop</span><span>Forward ▶</span></div>
    <div class="btns">
      <button class="btn btn-stop" onclick="fetch('/motor?m2=0').then(r=>r.json()).then(d=>document.getElementById('s2').textContent=d.m2)">Coast</button>
      <button class="btn btn-brake" onclick="fetch('/motor?m2=-999').then(r=>r.json()).then(d=>document.getElementById('s2').textContent=d.m2)">Brake</button>
    </div>
  </div>

  <button class="btn btn-stop-all btn-both" onclick="fetch('/motor?m1=0&m2=0').then(r=>r.json()).then(d=>{document.getElementById('s1').textContent=d.m1;document.getElementById('s2').textContent=d.m2})">⏹ Coast Both</button>
  <button class="btn btn-brake-all btn-both" onclick="fetch('/motor?m1=-999&m2=-999').then(r=>r.json()).then(d=>{document.getElementById('s1').textContent=d.m1;document.getElementById('s2').textContent=d.m2})">⛔ Brake Both</button>

  <div class="status"><span class="dot on" id="dot"></span><span id="ip">connected</span></div>
</div>

<script>
let up1=false,up2=false;
const s1=document.getElementById('s1'),s2=document.getElementById('s2');
const sl1=document.getElementById('sl1'),sl2=document.getElementById('sl2');
sl1.addEventListener('input',function(){if(!up1){let v=parseInt(this.value);v=v<-255?-255:v>255?255:v;fetch('/motor?m1='+v).then(r=>r.json()).then(d=>s1.textContent=d.m1)}else up1=false});
sl2.addEventListener('input',function(){if(!up2){let v=parseInt(this.value);v=v<-255?-255:v>255?255:v;fetch('/motor?m2='+v).then(r=>r.json()).then(d=>s2.textContent=d.m2)}else up2=false});
async function poll(){
  try{
    const r=await fetch('/status');
    const d=await r.json();
    s1.textContent=d.m1;s2.textContent=d.m2;
    up1=true;sl1.value=d.m1;
    up2=true;sl2.value=d.m2;
    document.getElementById('dot').className='dot on';
  }catch(e){document.getElementById('dot').className='dot off'}
}
setInterval(poll,500);poll();
</script>
</body>
</html>
)rawliteral";
  server.send(200, "text/html", html);
}

void handleStatus() {
  String json = "{\"m1\":" + String(m1Speed) + ",\"m2\":" + String(m2Speed) + "}";
  server.send(200, "application/json", json);
}

void handleMotor() {
  bool changed = false;

  // Motor 1: ?m1=<speed>  (-999 = brake)
  if (server.hasArg("m1")) {
    int s = server.arg("m1").toInt();
    if (s == -999) {
      motorBrake(M1_IN1, M1_IN2, &m1Speed);
      prevDirM1 = 0;
    } else {
      s = constrain(s, -255, 255);
      motorWrite(M1_IN1, M1_IN2, s, &prevDirM1, &m1Speed);
    }
    changed = true;
  }

  // Motor 2: ?m2=<speed>  (-999 = brake)
  if (server.hasArg("m2")) {
    int s = server.arg("m2").toInt();
    if (s == -999) {
      motorBrake(M2_IN1, M2_IN2, &m2Speed);
      prevDirM2 = 0;
    } else {
      s = constrain(s, -255, 255);
      motorWrite(M2_IN1, M2_IN2, s, &prevDirM2, &m2Speed);
    }
    changed = true;
  }

  if (changed) {
    String json = "{\"m1\":" + String(m1Speed) + ",\"m2\":" + String(m2Speed) + "}";
    server.send(200, "application/json", json);
  } else {
    server.send(400, "text/plain", "Bad request. Use ?m1=<speed>&m2=<speed>");
  }
}

// ==================== Setup ====================
void setup() {
  Serial.begin(115200);
  delay(500);

  // --- PWM (ESP32 Core 3.x+ API) ---
  ledcAttach(M1_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M1_IN2, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN1, PWM_FREQ, PWM_RES);
  ledcAttach(M2_IN2, PWM_FREQ, PWM_RES);
  motorCoast(M1_IN1, M1_IN2, &m1Speed);
  motorCoast(M2_IN1, M2_IN2, &m2Speed);

  // --- WiFi AP ---
  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASS, AP_CHANNEL, 0, AP_MAX_CLI);
  IPAddress ip = WiFi.softAPIP();

  // --- Web Server ---
  server.on("/",         handleRoot);
  server.on("/status",   handleStatus);
  server.on("/motor",    handleMotor);
  server.begin();

  Serial.println("ESP32 Dual MOSFET Motor Driver — WiFi AP");
  Serial.println("----------------------------------------");
  Serial.println("Serial commands: m1 <spd>, m2 <spd>, both <spd>, stop, brake");
  Serial.print("AP SSID: "); Serial.println(AP_SSID);
  Serial.print("AP PASS: "); Serial.println(AP_PASS);
  Serial.print("Web UI:  http://");
  Serial.println(ip);
}

// ==================== Loop ====================
void loop() {
  server.handleClient();

  // --- Serial commands ---
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd.startsWith("m1 ")) {
      int s = constrain(cmd.substring(3).toInt(), -255, 255);
      motorWrite(M1_IN1, M1_IN2, s, &prevDirM1, &m1Speed);
      Serial.print("Motor 1: "); Serial.println(m1Speed);
    }
    else if (cmd.startsWith("m2 ")) {
      int s = constrain(cmd.substring(3).toInt(), -255, 255);
      motorWrite(M2_IN1, M2_IN2, s, &prevDirM2, &m2Speed);
      Serial.print("Motor 2: "); Serial.println(m2Speed);
    }
    else if (cmd.startsWith("both ")) {
      int s = constrain(cmd.substring(5).toInt(), -255, 255);
      motorWrite(M1_IN1, M1_IN2, s, &prevDirM1, &m1Speed);
      motorWrite(M2_IN1, M2_IN2, s, &prevDirM2, &m2Speed);
      Serial.print("Both: "); Serial.println(m1Speed);
    }
    else if (cmd == "stop") {
      motorCoast(M1_IN1, M1_IN2, &m1Speed);
      motorCoast(M2_IN1, M2_IN2, &m2Speed);
      prevDirM1 = 0; prevDirM2 = 0;
      Serial.println("Coast");
    }
    else if (cmd == "brake") {
      motorBrake(M1_IN1, M1_IN2, &m1Speed);
      motorBrake(M2_IN1, M2_IN2, &m2Speed);
      prevDirM1 = 0; prevDirM2 = 0;
      Serial.println("Brake");
    }
    else {
      Serial.println("Commands: m1 <spd>, m2 <spd>, both <spd>, stop, brake");
    }
  }
}
