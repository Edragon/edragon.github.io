#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi AP settings (fixed IP)
const char* ssid = "MotorAP";
const char* password = "motorpass"; // set to "" for open AP
IPAddress apIP(192, 168, 4, 1);
IPAddress netMsk(255, 255, 255, 0);

// Define pins for motor control
const int ENA = 5; // PWM for speed for Motor (single motor)
const int IN1 = 0; // Direction pin A for Motor (GPIO0) - be careful at boot
const int IN2 = 2; // Direction pin B for Motor (GPIO2)

int motorControl = 50; // 0..100, default mid-point

ESP8266WebServer server(80);

void applyMotorControl() {
    // Deadband: treat 40..60 as stop
    if (motorControl > 60) {
        // Forward: IN1 = HIGH, IN2 = LOW
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);

        // Map motorControl (61-100) to PWM speed (0-255)
        int motorSpeed = map(motorControl, 61, 100, 0, 255);
        motorSpeed = constrain(motorSpeed, 0, 255);
        analogWrite(ENA, motorSpeed);
    } else if (motorControl < 40) {
        // Reverse: IN1 = LOW, IN2 = HIGH
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);

        // Map motorControl (0-39) to PWM speed (0-255)
        int motorSpeed = map(motorControl, 0, 39, 0, 255);
        motorSpeed = constrain(motorSpeed, 0, 255);
        analogWrite(ENA, motorSpeed);
    } else {
        // Stop motor
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENA, 0);
    }
}

String pageRoot() {
    String html = "<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    html += "<title>Motor AP Control</title></head><body>";
    html += "<h2>Motor Control (0-100)</h2>";
    html += "<input type=\"range\" id=\"s\" min=\"0\" max=\"100\" value=\"" + String(motorControl) + "\" oninput=\"update(this.value)\"/>";
    html += "<span id=\"v\">" + String(motorControl) + "</span>";
    html += "<script>function update(v){document.getElementById('v').innerText=v;fetch('/set?val='+v);}setInterval(function(){fetch('/status').then(r=>r.text()).then(t=>{document.getElementById('s').value=t;document.getElementById('v').innerText=t;});},1000);</script>";
    html += "</body></html>";
    return html;
}

void handleRoot() {
    server.send(200, "text/html", pageRoot());
}

void handleSet() {
    if (!server.hasArg("val")) {
        server.send(400, "text/plain", "missing val");
        return;
    }
    String v = server.arg("val");
    int val = v.toInt();
    val = constrain(val, 0, 100);
    motorControl = val;
    applyMotorControl();
    server.send(200, "text/plain", String(motorControl));
}

void handleStatus() {
    server.send(200, "text/plain", String(motorControl));
}

void setup() {
    // Initialize pins
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);

    // Initialize motor to off
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    Serial.begin(115200);
    delay(100);

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

void loop() {
    server.handleClient();
    // Optional: keep motor state applied in case other code modifies it
    // applyMotorControl();
    delay(10);
}