#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// AP Settings
const char* ssid = "BTS7960_Motor_Controller";
const char* password = "12345678";

ESP8266WebServer server(80);

// Motor 1 Pins (Left Motor)
const int M1_LPWM = 5; // D1
const int M1_RPWM = 4; // D2

// Motor 2 Pins (Right Motor)
const int M2_LPWM = 14; // D5
const int M2_RPWM = 12; // D6

// Global speed (0 to 100%)
int currentSpeedPercent = 50;

// HTML Page with fixed JavaScript execution
const char HTML_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Dual BTS7960 Control</title>
  <style>
    body { font-family: Arial, sans-serif; text-align: center; background: #1e1e24; color: #fff; padding: 20px; user-select: none; }
    .container { max-width: 400px; margin: auto; background: #2a2a35; padding: 20px; border-radius: 10px; box-shadow: 0 4px 10px rgba(0,0,0,0.5); }
    h2 { color: #00adb5; margin-bottom: 25px; }
    .btn { display: inline-block; width: 90px; padding: 15px; margin: 8px; font-weight: bold; background: #00adb5; border: none; color: white; border-radius: 5px; cursor: pointer; }
    .btn:active { background: #008188; }
    .btn-stop { background: #ff2e63; width: 200px; }
    .btn-stop:active { background: #cc234f; }
    .slider-container { margin-top: 25px; padding: 10px; background: #22222b; border-radius: 5px; }
    .slider-label { display: flex; justify-content: space-between; font-weight: bold; margin-bottom: 5px; }
    .slider { width: 100%; margin: 10px 0; }
  </style>
</head>
<body>
  <div class="container">
    <h2>Dual BTS7960 Control</h2>
    
    <div>
      <button class="btn" onclick="sendCmd('forward')">FORWARD</button><br>
      <button class="btn" onclick="sendCmd('left')">LEFT</button>
      <button class="btn btn-stop" onclick="sendCmd('stop')">STOP</button>
      <button class="btn" onclick="sendCmd('right')">RIGHT</button><br>
      <button class="btn" onclick="sendCmd('backward')">REVERSE</button>
    </div>

    <div class="slider-container">
      <div class="slider-label"><span>Target Speed:</span><span id="speedVal">50%</span></div>
      <input type="range" min="10" max="100" value="50" class="slider" id="speedSlider" onchange="updateSpeed(this.value)">
    </div>
  </div>

  <script>
    let speed = 50;
    
    function sendCmd(dir) {
      fetch(`/control?dir=${dir}&speed=${speed}`)
        .then(response => { if(!response.ok) console.log('Network error'); })
        .catch(err => console.error(err));
    }

    function updateSpeed(val) {
      speed = val;
      document.getElementById('speedVal').innerText = val + '%';
      fetch(`/control?dir=update&speed=${speed}`);
    }
  </script>
</body>
</html>
)=====";

void handleRoot() {
  server.send_P(200, "text/html", HTML_PAGE);
}

void handleControl() {
  String direction = server.arg("dir");
  String speedParam = server.arg("speed");
  
  if (speedParam.length() > 0) {
    currentSpeedPercent = speedParam.toInt();
  }
  
  // Map 0-100% slider to 0-1023 ESP8266 PWM range
  int pwmValue = map(currentSpeedPercent, 0, 100, 0, 1023);

  if (direction == "forward") {
    analogWrite(M1_LPWM, pwmValue); analogWrite(M1_RPWM, 0);
    analogWrite(M2_LPWM, pwmValue); analogWrite(M2_RPWM, 0);
  } 
  else if (direction == "backward") {
    analogWrite(M1_LPWM, 0);        analogWrite(M1_RPWM, pwmValue);
    analogWrite(M2_LPWM, 0);        analogWrite(M2_RPWM, pwmValue);
  } 
  else if (direction == "left") {
    analogWrite(M1_LPWM, 0);        analogWrite(M1_RPWM, pwmValue); 
    analogWrite(M2_LPWM, pwmValue); analogWrite(M2_RPWM, 0);        
  } 
  else if (direction == "right") {
    analogWrite(M1_LPWM, pwmValue); analogWrite(M1_RPWM, 0);        
    analogWrite(M2_LPWM, 0);        analogWrite(M2_RPWM, pwmValue); 
  } 
  else if (direction == "stop") {
    analogWrite(M1_LPWM, 0); analogWrite(M1_RPWM, 0);
    analogWrite(M2_LPWM, 0); analogWrite(M2_RPWM, 0);
  }
  
  server.send(200, "text/plain", "OK");
}

void setup() {
  Serial.begin(115200);

  // Configure Pins
  pinMode(M1_LPWM, OUTPUT);
  pinMode(M1_RPWM, OUTPUT);
  pinMode(M2_LPWM, OUTPUT);
  pinMode(M2_RPWM, OUTPUT);

  // Default to Stopped
  analogWrite(M1_LPWM, 0);
  analogWrite(M1_RPWM, 0);
  analogWrite(M2_LPWM, 0);
  analogWrite(M2_RPWM, 0);

  // Set up Access Point
  WiFi.softAP(ssid, password);
  Serial.println("\n--- Access Point Active ---");
  Serial.print("SSID: "); Serial.println(ssid);
  Serial.print("Web Interface URL: http://"); Serial.println(WiFi.softAPIP());

  // Server Routing
  server.on("/", handleRoot);
  server.on("/control", handleControl);
  server.begin();
}

void loop() {
  server.handleClient();
}