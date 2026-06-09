

# ESP-NOW-dat

- [[ESP32-S3-dat]]

- [[ESP32-C3-supermini-dat]] - [[ESP32-C3-NOW-code-1]] - [[ESP-NOW-dat]]


### 1. Enable ESP-NOW "Long Range" Mode (LR Mode)
By default, ESP-NOW runs on standard Wi-Fi physical rates. However, Espressif built a hidden protocol layer called **LR Mode** specifically for long-distance communication. It reduces the data rate down to 256 Kbps or 512 Kbps (which is still a massive amount of speed for tiny RC joystick coordinates) but heavily boosts the receiver's sensitivity.

In your initialization code (after `esp_wifi_start()`), use this to force the radio into Long Range mode:

```cpp
// Set the Wi-Fi protocol to Long Range mode on the station interface
esp_wifi_set_protocol(WIFI_IF_STA, WIFI_PROTOCOL_LR); 
```

**The Impact:** This simple software toggle can easily double or triple your line-of-sight range in open fields.

### 2. Max Out the Transmission Power
Dev boards sometimes ship with conservative radio transmission settings to save power. For an RC vehicle where reliability is everything, you want to force the S3’s internal power amplifier to its absolute hardware limit (21 dBm).

Add this right after initializing your Wi-Fi settings:

```cpp
// Set maximum TX power (84 represents 21dBm, where 1 unit = 0.25dBm)
esp_wifi_set_max_tx_power(84); 
```

### 3. Lock Down a Clean Wi-Fi Channel
Standard home Wi-Fi routers hop around channels 1 through 11, causing massive interference if your RC toy crosses paths with a residential area.

In your code, explicitly bind both your transmitter and receiver to Channel 1, 6, or 11 (the non-overlapping channels).

Make sure both chips are hard-coded to the exact same channel so they don't waste precious time searching for each other if a packet drops.

### A Critical Note on Your Specific S3 Hardware
Since you are avoiding extra hardware add-ons, look closely at your ESP32-S3 boards right now:

If they have a built-in PCB Trace Antenna (the onboard wavy copper line): You will get a reliable 80 to 150 meters outdoors with the software optimizations above.

If they have an IPEX/U.FL connector (the tiny gold metal circle): Make sure you plug a standard 2.4GHz rubber ducky antenna into it. With a proper antenna attached directly to that port, ESP-NOW in LR mode can routinely push 400 to 700+ meters line-of-sight.

If you are using the tiny "Super Mini" style S3 boards, be extra careful to keep the built-in antenna clear of power wires or metal structural components on your toy, as their small antennas are highly sensitive to nearby electronic noise.