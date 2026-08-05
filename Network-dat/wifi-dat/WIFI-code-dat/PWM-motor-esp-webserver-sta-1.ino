

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ===== WiFi 配置 =====
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// ===== GPIO 定义 =====
const int PWM_PIN = 5;    // PWM 控制速度 IO5
const int DIR_PIN1 = 4;   // 方向引脚1 IO4
const int DIR_PIN2 = 0;   // 方向引脚2 IO0

// ===== Web Server =====
ESP8266WebServer server(80);

// ===== HTML Web 控制界面 =====
const char html_page[] PROGMEM = R"rawliteral(
<!DOCTYPE html><html>
<head><title>ESP8266 Motor Control</title></head>
<body>
<h2>Motor Control</h2>
<form action="/control">
Speed: <input type="range" name="speed" min="0" max="1023"><br>
Direction:
<select name="dir">
 <option value="fw">Forward</option>
 <option value="rv">Reverse</option>
</select><br>
<input type="submit" value="Apply">
</form>
</body></html>
)rawliteral";

// ===== 处理 Web 请求 =====
void handleRoot() {
  server.send(200, "text/html", html_page);
}

void handleControl() {
  if (server.hasArg("speed")) {
    int speed = server.arg("speed").toInt(); // PWM 值 0-1023
    analogWrite(PWM_PIN, speed);
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
  
  pinMode(PWM_PIN, OUTPUT);
  pinMode(DIR_PIN1, OUTPUT);
  pinMode(DIR_PIN2, OUTPUT);
  
  // 默认停止
  analogWrite(PWM_PIN, 0);
  digitalWrite(DIR_PIN1, LOW);
  digitalWrite(DIR_PIN2, LOW);

  // 连接 WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected, IP: ");
  Serial.println(WiFi.localIP());

  // Web 服务
  server.on("/", handleRoot);
  server.on("/control", handleControl);
  server.begin();
}

void loop() {
  server.handleClient();
}