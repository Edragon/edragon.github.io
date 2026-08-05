#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ===== WiFi 配置 =====
const char* ssid = "motor_control";
const char* password = "electrodragon";

// ===== GPIO 定义 =====
const int PWM1_PIN = 5;    // PWM 控制速度 IO5
const int PWM2_PIN = 4;    // PWM 控制速度 IO4

const int DIR_PIN1 = 2;   // 方向引脚1 IO2
const int DIR_PIN2 = 0;   // 方向引脚2 IO0


// ===== Web Server =====
ESP8266WebServer server(80);

// ===== HTML Web 控制界面 =====
const char html_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html><html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>ESP8266 Motor Control</title>
<style>
body {
  font-family: Arial, sans-serif;
  max-width: 600px;
  margin: 0 auto;
  padding: 20px;
  background-color: #f0f0f0;
}
h2 {
  text-align: center;
  color: #333;
}
.control-panel {
  background: white;
  padding: 20px;
  border-radius: 10px;
  box-shadow: 0 2px 10px rgba(0,0,0,0.1);
}
.section {
  margin-bottom: 25px;
}
.section-title {
  font-weight: bold;
  margin-bottom: 10px;
  font-size: 18px;
  color: #555;
}
.speed-buttons {
  display: grid;
  grid-template-columns: repeat(6, 1fr);
  gap: 8px;
  margin-bottom: 10px;
}
.speed-btn {
  padding: 15px 10px;
  font-size: 16px;
  font-weight: bold;
  border: 2px solid #4CAF50;
  background-color: white;
  color: #4CAF50;
  border-radius: 8px;
  cursor: pointer;
  transition: all 0.2s;
}
.speed-btn:active {
  background-color: #4CAF50;
  color: white;
  transform: scale(0.95);
}
.dir-buttons {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 10px;
}
.dir-btn {
  padding: 20px;
  font-size: 18px;
  font-weight: bold;
  border: none;
  border-radius: 8px;
  cursor: pointer;
  transition: all 0.2s;
}
.forward-btn {
  background-color: #2196F3;
  color: white;
}
.reverse-btn {
  background-color: #FF9800;
  color: white;
}
.dir-btn:active {
  transform: scale(0.95);
  opacity: 0.8;
}
.stop-btn {
  width: 100%;
  padding: 20px;
  font-size: 20px;
  font-weight: bold;
  background-color: #f44336;
  color: white;
  border: none;
  border-radius: 8px;
  cursor: pointer;
  margin-top: 20px;
}
.stop-btn:active {
  transform: scale(0.98);
  opacity: 0.8;
}
</style>
</head>
<body>
<h2>Motor Control</h2>
<div class="control-panel">
  <div class="section">
    <div class="section-title">Speed Control (0-10)</div>
    <div class="speed-buttons">
      <button class="speed-btn" onclick="setSpeed(0)">0</button>
      <button class="speed-btn" onclick="setSpeed(1)">1</button>
      <button class="speed-btn" onclick="setSpeed(2)">2</button>
      <button class="speed-btn" onclick="setSpeed(3)">3</button>
      <button class="speed-btn" onclick="setSpeed(4)">4</button>
      <button class="speed-btn" onclick="setSpeed(5)">5</button>
      <button class="speed-btn" onclick="setSpeed(6)">6</button>
      <button class="speed-btn" onclick="setSpeed(7)">7</button>
      <button class="speed-btn" onclick="setSpeed(8)">8</button>
      <button class="speed-btn" onclick="setSpeed(9)">9</button>
      <button class="speed-btn" onclick="setSpeed(10)">10</button>
    </div>
  </div>
  <div class="section">
    <div class="section-title">Direction Control</div>
    <div class="dir-buttons">
      <button class="dir-btn forward-btn" onclick="setDirection('fw')">Forward</button>
      <button class="dir-btn reverse-btn" onclick="setDirection('rv')">Reverse</button>
    </div>
  </div>
  <button class="stop-btn" onclick="stopMotor()">STOP</button>
</div>
<script>
let currentSpeed = 0;
let currentDir = 'fw';
function setSpeed(speed) {
  currentSpeed = speed;
  sendControl();
}
function setDirection(dir) {
  currentDir = dir;
  sendControl();
}
function sendControl() {
  let pwmValue = Math.round((currentSpeed / 10) * 1023);
  fetch('/control?speed=' + pwmValue + '&dir=' + currentDir)
    .then(response => response.text())
    .catch(error => console.error('Error:', error));
}
function stopMotor() {
  currentSpeed = 0;
  fetch('/control?speed=0&dir=' + currentDir)
    .then(response => response.text())
    .catch(error => console.error('Error:', error));
}
</script>
</body></html>
)rawliteral";

// ===== 处理 Web 请求 =====
void handleRoot() {
  server.send(200, "text/html", html_page);
}

void handleControl() {
  if (server.hasArg("speed")) {
    int speed = server.arg("speed").toInt(); // PWM 值 0-1023
    analogWrite(PWM1_PIN, speed);
    analogWrite(PWM2_PIN, speed);
  }

  if (server.hasArg("dir")) {
    String d = server.arg("dir");
    if (d == "fw") {
      digitalWrite(DIR_PIN1, HIGH);
      digitalWrite(DIR_PIN2, LOW);
    } else {
      digitalWrite(DIR_PIN1, LOW);
      digitalWrite(DIR_PIN2, HIGH);
    }
  }
  
  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "");
}

// ===== 初始化 =====
void setup() {
  Serial.begin(115200);
  
  pinMode(PWM1_PIN, OUTPUT);
  pinMode(PWM2_PIN, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  
  // 默认停止
  analogWrite(PWM1_PIN, 0);
  analogWrite(PWM2_PIN, 0);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, LOW);

  // 启动为 WiFi AP 模式，使用固定 IP
  Serial.println("Starting WiFi AP...");
  
  // Disconnect from any previous WiFi
  WiFi.disconnect();
  WiFi.mode(WIFI_AP);
  delay(100);
  
  // 启动软 AP：使用 ssid 和 password（注意：WPA2 密码至少 8 字符）
  bool apStarted = WiFi.softAP(ssid, password);
  if (!apStarted) {
    Serial.println("AP start failed! Retrying...");
    delay(1000);
    WiFi.softAP(ssid, password);
  }
  
  delay(1000); // Give more time for AP to start
  
  // 固定 AP 地址（根据需要修改）- Must be called AFTER softAP()
  IPAddress apIP(192, 168, 50, 1);
  IPAddress apGateway(192, 168, 50, 1);
  IPAddress apSubnet(255, 255, 255, 0);
  if (!WiFi.softAPConfig(apIP, apGateway, apSubnet)) {
    Serial.println("softAPConfig failed");
  }
  
  delay(500);
  Serial.println("");
  Serial.println("==========================");
  Serial.print("AP SSID: ");
  Serial.println(ssid);
  Serial.print("AP Password: ");
  Serial.println(password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("==========================");

  // Web 服务
  server.on("/", handleRoot);
  server.on("/control", handleControl);
  server.begin();
}

void loop() {
  server.handleClient();
}