#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// WiFi AP settings (fixed IP)
const char *ssid = "MotorAP";
const char *password = "motorpass"; // set to "" for open AP
IPAddress apIP(192, 168, 4, 1);
IPAddress netMsk(255, 255, 255, 0);

// Define pins for motor control
// Motor 1
const int M1_IN1 = 4;
const int M1_IN2 = 5;
// Motor 2
const int M2_IN1 = 0;
const int M2_IN2 = 2;

int motorControl = 50; // 0..100, default mid-point

ESP8266WebServer server(80);

void applyMotorControl()
{
    // Deadband: treat 40..60 as stop
    if (motorControl > 60)
    {
        // Forward
        int motorSpeed = map(motorControl, 61, 100, 0, 255);
        motorSpeed = constrain(motorSpeed, 0, 255);

        analogWrite(M1_IN1, motorSpeed);
        digitalWrite(M1_IN2, LOW);
        analogWrite(M2_IN1, motorSpeed);
        digitalWrite(M2_IN2, LOW);
    }
    else if (motorControl < 40)
    {
        // Reverse
        int motorSpeed = map(motorControl, 0, 39, 255, 0);
        motorSpeed = constrain(motorSpeed, 0, 255);

        digitalWrite(M1_IN1, LOW);
        analogWrite(M1_IN2, motorSpeed);
        digitalWrite(M2_IN1, LOW);
        analogWrite(M2_IN2, motorSpeed);
    }
    else
    {
        // Stop motors
        digitalWrite(M1_IN1, LOW);
        digitalWrite(M1_IN2, LOW);
        digitalWrite(M2_IN1, LOW);
        digitalWrite(M2_IN2, LOW);
    }
}

String pageRoot()
{
    String html = "<html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    html += "<title>Motor AP Control</title></head><body>";
    html += "<h2>Motor Control (0-100)</h2>";
    html += "<input type=\"range\" id=\"s\" min=\"0\" max=\"100\" value=\"" + String(motorControl) + "\" oninput=\"update(this.value)\"/>";
    html += "<span id=\"v\">" + String(motorControl) + "</span>";
    html += "<script>function update(v){document.getElementById('v').innerText=v;fetch('/set?val='+v);}setInterval(function(){fetch('/status').then(r=>r.text()).then(t=>{document.getElementById('s').value=t;document.getElementById('v').innerText=t;});},1000);</script>";
    html += "</body></html>";
    return html;
}

void handleRoot()
{
    server.send(200, "text/html", pageRoot());
}

void handleSet()
{
    if (!server.hasArg("val"))
    {
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

void handleStatus()
{
    server.send(200, "text/plain", String(motorControl));
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
    // Optional: keep motor state applied in case other code modifies it
    // applyMotorControl();
    delay(10);
}




