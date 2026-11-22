



# USB-3.1-dat

- [[USB-4.0-dat]] - [[USB-3.1-dat]] - [[USB-3.0-dat]] - [[USB-2.0-dat]] - [[conn-USB-type-c-female-24p-dat]]

- [[USB-converter-dat]] 




## build 

### pixel2XL 

- [[conn-USB-type-c-dat]] - [[pixel2-dat]] - [[phone-pixel-dat]] - [[USB-3.1-dat]]


### 1. Pixel 2 XL Type-C Hardware Specs (How many signal lines?)

The Google Pixel 2 XL uses a **full 24-pin USB Type-C physical port** running the **USB 3.1 Gen 1 (5 Gbps)** standard.

Out of the 24 pins (excluding power `VBUS` and ground `GND`), there are **14 active signal lines**:

* **8 SuperSpeed Data Lines (USB 3.1):** Two pairs of `TX+/TX-` and two pairs of `RX+/RX-` (4 differential pairs total) for bidirectional 5 Gbps data transfer in either plug orientation.
* **2 Legacy Data Lines (USB 2.0):** `D+` and `D-` (1 differential pair) for standard USB 2.0 communication and initial handshakes.
* **2 Configuration Channel Lines (`CC1` and `CC2`):** The most critical lines for your setup—they negotiate USB-PD charging and tell the Pixel 2 XL whether to act as a **USB Host (OTG)** or a USB Device.
* **2 Sideband Use Lines (`SBU1` and `SBU2`):** Auxiliary lines used primarily for audio passthrough.

*(Note: Although the physical port has all 24 pins wired, Google disabled native DisplayPort Alt Mode in hardware/firmware, so HDMI video output on any hub will not work on the Pixel 2 XL.)*

---

### 2. Required Conditions When Buying an Adapter / Hub

If you want to connect your Pixel 2 XL to your router reliably (while avoiding power drops or connection failures), make sure the adapter meets these **5 criteria**:

1. **True Android OTG Host Support (Proper `CC1/CC2` Wiring)**
* Cheap charging-only adapters omit proper `CC` logic and won't trigger OTG host mode. Look for explicit **"Android OTG supported"** specs.


2. **Pass-Through PD Charging (`PD In` Port)**
* The Pixel 2 XL has weak OTG power output on its own, which causes USB network adapters or router tethering connections to randomly drop.
* Choose an adapter with a dedicated **Type-C PD charging port** so an external charger powers both the phone and the network interface simultaneously without resetting the OTG link.


3. **Driverless Ethernet Chipset Compatible with Android 11 (Linux 4.4 Kernel)**
* Because the Pixel 2 XL is capped at Android 11, newer **2.5Gbps Ethernet chips (like RTL8156)** often lack built-in kernel drivers and won't work.
* Whether built into the hub or plugged in separately, stick to classic plug-and-play **100M / 1000M chipsets**:
* **Best choice:** ASIX **AX88179** (Gigabit) or **AX88772A/B/C** (100 Mbps)
* **Second choice:** Realtek **RTL8153** (Gigabit) or **RTL8152B** (100 Mbps)




4. **Full USB 3.0 (5 Gbps) Data Wiring**
* Ensure the hub's data ports are wired for USB 3.0 (`TX/RX` lines present) rather than stripped-down USB 2.0, preventing bottlenecks or packet drops during local IP camera streaming.


5. **Short, Shielded Cable (10–15 cm / ~0.5 ft)**
* High-frequency USB 3.0 signals are sensitive to cable length and interference; a short pigtail cable keeps the connection rock-solid.



---

### Best Setup Recommendation

Instead of connecting through your router's USB port, the cleanest and most reliable setup for accessing `192.168.0.4:8080` is a **USB-C to RJ45 Gigabit Ethernet + PD Charging adapter** (built with an **AX88179** or **RTL8153** chip):

* **Wall Charger** $\rightarrow$ Adapter's **PD Port**
* **Router LAN Port (Ethernet cable)** $\rightarrow$ Adapter's **RJ45 Port**
* **Adapter USB-C Plug** $\rightarrow$ **Pixel 2 XL**

This bypasses router USB-tethering compatibility issues completely, keeps your Pixel 2 XL charged, and puts the phone directly onto your local LAN subnet (`192.168.0.x`).


- [[USB-converter-dat]] - [[USB-hub-dat]]


## ref 