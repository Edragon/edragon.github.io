

# boot.py — run once on boot before main.py
import machine
import esp
import network

# Optional: disable debug output
esp.osdebug(None)

# Optional: turn off REPL on UART0
# import uos
# uos.dupterm(None, 1)

# Connect to Wi-Fi
sta = network.WLAN(network.STA_IF)
sta.active(True)
sta.connect('your-SSID', 'your-PASSWORD')

# Wait for connection
while not sta.isconnected():
    pass

print('Connected to Wi-Fi:', sta.ifconfig())



