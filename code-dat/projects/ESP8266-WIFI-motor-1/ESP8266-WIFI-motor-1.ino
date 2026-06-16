#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi AP settings (fixed IP)
const char *ssid = "MotorAP";
const char *password = "motorpass"; // set to "" for open AP
IPAddress apIP(192, 168, 4, 1);
IPAddress netMsk(255, 255, 255, 0);

// Define pins for motor control
// Motor 1 (Left)
const int M1_IN1 = 4;
const int M1_IN2 = 5;
// Motor 2 (Right)
const int M2_IN1 = 0;
const int M2_IN2 = 2;

int carSpeed = 200; // 0..255 (Base Speed)
int minSpeed = 100; // Minimum speed to avoid stalling
int turnDiff = 85;  // Increased for more "agility" (sharper turns)
int carAction = 0;  // 0: stop, 1: forward, 2: backward, 3: left, 4: right
unsigned long lastCommandTime = 0;
const unsigned long SAFETY_TIMEOUT = 300; // Even tighter for high responsiveness

int batteryS = 3; // Default 3S (11.1V)

ESP8266WebServer server(80);

int getCompensatedSpeed(int baseSpeed) {
    if (baseSpeed == 0) return 0;
    // Simple inverse scaling: 
    // If it's 3S (11.1V), we scale DOWN the speed compared to 2S (7.4V)
    // Scale factor = 7.4 / 11.1 = ~0.66
    if (batteryS == 3) {
        return (int)(baseSpeed * 0.66);
    }
    return baseSpeed; // Use raw speed for 2S
}

void applyMotorControl()
{
    int leftSpeed = 0;
    int rightSpeed = 0;
    
    int compensatedSpeed = getCompensatedSpeed(carSpeed);
    int compensatedTurnDiff = getCompensatedSpeed(turnDiff);

    // Helper to ensure motor gets enough power or is OFF
    auto normalizeSpeed = [&](int s) {
        if (s <= 0) return 0;
        if (s < minSpeed) return minSpeed;
        if (s > 255) return 255;
        return s;
    };

    switch (carAction)
    {
    case 0: // Stop
        leftSpeed = rightSpeed = 0;
        break;
    case 1: // Forward
        leftSpeed = rightSpeed = compensatedSpeed;
        break;
    case 2: // Backward
        leftSpeed = rightSpeed = -compensatedSpeed;
        break;
    case 3: // Spin Left
        leftSpeed = -compensatedSpeed;
        rightSpeed = compensatedSpeed;
        break;
    case 4: // Spin Right
        leftSpeed = compensatedSpeed;
        rightSpeed = -compensatedSpeed;
        break;
    case 5: // Forward Left (Curve) - Swapped
        leftSpeed = compensatedSpeed + compensatedTurnDiff;
        rightSpeed = compensatedSpeed - compensatedTurnDiff;
        break;
    case 6: // Forward Right (Curve) - Swapped
        leftSpeed = compensatedSpeed - compensatedTurnDiff;
        rightSpeed = compensatedSpeed + compensatedTurnDiff;
        break;
    case 7: // Backward Left (Curve)
        leftSpeed = -(compensatedSpeed + compensatedTurnDiff);
        rightSpeed = -(compensatedSpeed - compensatedTurnDiff);
        break;
    case 8: // Backward Right (Curve)
        leftSpeed = -(compensatedSpeed - compensatedTurnDiff);
        rightSpeed = -(compensatedSpeed + compensatedTurnDiff);
        break;
    default:
        leftSpeed = rightSpeed = 0;
        break;
    }

    // Apply Left Motor
    int absL = abs(leftSpeed);
    int finalL = normalizeSpeed(absL);
    if (leftSpeed > 0) {
        analogWrite(M1_IN1, finalL);
        digitalWrite(M1_IN2, LOW);
    } else if (leftSpeed < 0) {
        digitalWrite(M1_IN1, LOW);
        analogWrite(M1_IN2, finalL);
    } else {
        digitalWrite(M1_IN1, LOW);
        digitalWrite(M1_IN2, LOW);
    }

    // Apply Right Motor
    int absR = abs(rightSpeed);
    int finalR = normalizeSpeed(absR);
    if (rightSpeed > 0) {
        analogWrite(M2_IN1, finalR);
        digitalWrite(M2_IN2, LOW);
    } else if (rightSpeed < 0) {
        digitalWrite(M2_IN1, LOW);
        analogWrite(M2_IN2, finalR);
    } else {
        digitalWrite(M2_IN1, LOW);
        digitalWrite(M2_IN2, LOW);
    }
}

String pageRoot()
{
    String html = "<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no\">";
    html += "<style>";
    html += "body { font-family: sans-serif; text-align: center; display: flex; flex-direction: column; align-items: center; justify-content: center; height: 100vh; margin: 0; background: #f0f0f0; }";
    html += ".btn { width: 80px; height: 80px; margin: 10px; border-radius: 15px; border: none; background: #3498db; color: white; font-size: 24px; font-weight: bold; cursor: pointer; user-select: none; -webkit-tap-highlight-color: transparent; box-shadow: 0 4px #2980b9; }";
    html += ".btn:active { background: #2980b9; box-shadow: 0 2px #1c5982; transform: translateY(2px); }";
    html += ".stop-btn { background: #e74c3c; box-shadow: 0 4px #c0392b; }";
    html += ".stop-btn:active { background: #c0392b; box-shadow: 0 2px #962d22; }";
    html += ".row { display: flex; justify-content: center; }";
    html += ".speed-container { margin-top: 20px; width: 80%; }";
    html += "input[type=range] { width: 100%; height: 25px; cursor: pointer; }";
    html += "select { padding: 8px; font-size: 16px; border-radius: 5px; }";
    html += "</style></head><body>";
    html += "<h2>Motor Control</h2>";
    
    auto btnHtml = [&](int act, String icon) {
        String s_act = String(act);
        return "  <button class='btn' onmousedown=\"setAction(" + s_act + ", event)\" ontouchstart=\"setAction(" + s_act + ", event)\" "
               "onmouseup=\"setAction(0, event)\" onmouseleave=\"setAction(0, event)\" ontouchend=\"setAction(0, event)\" ontouchcancel=\"setAction(0, event)\">" + icon + "</button>";
    };

    html += "<div class='row'>";
    html += btnHtml(5, "&#8598;");
    html += btnHtml(1, "&#8593;");
    html += btnHtml(6, "&#8599;");
    html += "</div>";
    
    html += "<div class='row'>";
    html += btnHtml(3, "&#8592;");
    html += "  <button class='btn stop-btn' onclick=\"setAction(0, event)\" ontouchstart=\"setAction(0, event)\">OFF</button>";
    html += btnHtml(4, "&#8594;");
    html += "</div>";
    
    html += "<div class='row'>";
    html += btnHtml(7, "&#8601;");
    html += btnHtml(2, "&#8595;");
    html += btnHtml(8, "&#8600;");
    html += "</div>";

    html += "<div class='speed-container'>";
    html += "  Speed: <span id='v'>" + String(carSpeed) + "</span>";
    html += "  <input type='range' id='s' min='100' max='255' value='" + String(carSpeed) + "' oninput='setSpeed(this.value)' />";
    html += "</div>";

    html += "<div class='speed-container'>";
    html += "  Battery Mode: <select onchange=\"setBattery(this.value)\">";
    html += "    <option value='2'" + String(batteryS == 2 ? " selected" : "") + ">2S (7.4V)</option>";
    html += "    <option value='3'" + String(batteryS == 3 ? " selected" : "") + ">3S (11.1V)</option>";
    html += "  </select>";
    html += "</div>";

    html += "<script>";
    html += "let lastA = -1; let lastS = -1;";
    html += "function setAction(a, e, f) { if(e) { e.preventDefault(); } if(!f && a == lastA && a != 0) return; lastA = a; fetch('/set?action=' + a).catch(e => console.error(e)); }";
    html += "function setSpeed(s) { if(s == lastS) return; lastS = s; document.getElementById('v').innerText = s; fetch('/set?speed=' + s).catch(e => console.error(e)); }";
    html += "function setBattery(b) { fetch('/set?batt=' + b); }";
    html += "setInterval(() => { if(lastA > 0) setAction(lastA, null, true); }, 100);"; // "Pro" agility: 100ms heartbeat
    html += "</script></body></html>";
    return html;
}

void handleRoot()
{
    server.send(200, "text/html", pageRoot());
}

void handleSet()
{
    server.client().setNoDelay(true); // Disable Nagle's algorithm for faster response
    lastCommandTime = millis(); // Refresh safety watchdog
    if (server.hasArg("action"))
    {
        carAction = server.arg("action").toInt();
    }
    if (server.hasArg("speed"))
    {
        carSpeed = server.arg("speed").toInt();
        carSpeed = constrain(carSpeed, 0, 255);
    }
    if (server.hasArg("batt"))
    {
        batteryS = server.arg("batt").toInt();
    }
    applyMotorControl();
    server.send(200, "text/plain", "OK");
}

void handleStatus()
{
    String status = "Action: " + String(carAction) + ", Speed: " + String(carSpeed) + ", Batt: " + String(batteryS) + "S";
    server.send(200, "text/plain", status);
}

void setup()
{
    // Initialize pins
    pinMode(M1_IN1, OUTPUT);
    pinMode(M1_IN2, OUTPUT);
    pinMode(M2_IN1, OUTPUT);
    pinMode(M2_IN2, OUTPUT);

    // Initialize motors to off
    digitalWrite(M1_IN1, LOW);
    digitalWrite(M1_IN2, LOW);
    digitalWrite(M2_IN1, LOW);
    digitalWrite(M2_IN2, LOW);

    // Set PWM frequency for DRV8871 (supports up to 200kHz, but 20kHz is standard for silence and efficiency)
    analogWriteFreq(20000); 

    Serial.begin(115200);
    delay(100);

    Serial.println("Test...");
    delay(1000);
    Serial.println("Test...");
    delay(1000);
    Serial.println("Test...");
    delay(1000);
    // Configure AP with fixed IP
    WiFi.softAPConfig(apIP, apIP, netMsk);
    WiFi.softAP(ssid, password);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);

    // Configure server routes
    server.on("/", handleRoot);
    server.on("/set", handleSet);
    server.on("/status", handleStatus);
    server.begin();
    Serial.println("HTTP server started");

    // Ensure PWM range 0-255
    analogWriteRange(255);

    // Apply initial motor state
    applyMotorControl();
}

void loop()
{
    server.handleClient();
    
    // Safety Watchdog: Stop motors if no command received for > 1 second
    if (carAction != 0 && (millis() - lastCommandTime > SAFETY_TIMEOUT)) {
        carAction = 0;
        applyMotorControl();
        Serial.println("Safety Timeout: Motors stopped");
    }
    
    delay(10);
}




