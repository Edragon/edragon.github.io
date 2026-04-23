

# USB-SDK-type-c-dat

- [[CONN-USB-type-c-dat]] - [[USB-SDK-type-c-dat]] - [[cable-USB-type-c-dat]]

- [[cable-USB-dat]]



## tech 

- [[type-c-sniffer-dat]] 

- [[fast-charge-protocols-dat]] - [[USB-PD-dat]]

- [[USB-OTG-dat]]

- [[displayport-dat]] - [[audio-dat]]



## functions 

- [[USB-charging-dat]] - [[USB-PD-dat]]

- [[USB-OTG-dat]] 

- [[displayPort-dat]]

[[type-c-to-ethernet-dat]]

- [[thunderbolt-dat]]

- [[type-c-to-ethernet-dat]]


## apps 

- [[type-c-to-ethernet-dat]]



## debug info 

###  keeping dropping 

`USB Serial/JTAG Internal Switch`

The S3 has an internal USB Serial/JTAG controller. If your code (or the factory firmware) initializes the USB peripheral in a way that conflicts with the hardware connection, the PC will "drop" the device as soon as the code starts running (usually 1-2 seconds after boot).

Test: Hold the `BOOT` button (`GPIO 0 to GND`), then press RESET, then release BOOT. If the device stays connected to the PC in this state, your hardware is fine, and the issue is your firmware or USB configuration.


## info and knowledge 

### USB-C vs. USB Type-C: Is There a Difference?

"USB-C" is simply the shorthand, everyday name for the official technical designation, "USB Type-C."


In short: There is no difference. 

USB Type-C and USB-C are two names for the exact same physical connector. "USB-C" is simply the shorthand, everyday name for the official technical designation, "USB Type-C."

However, there is a lot of confusion because while the shape is the same, what the cable can actually do varies wildly. Here is the breakdown:

1. The Physical Connector (The "C" Shape)
USB-C refers specifically to the 24-pin physical design: the small, reversible, oval-shaped plug. Before this, we had "Type-A" (the rectangular one) and "Type-B" (the square-ish one used for printers).

1. The "Hidden" Differences (The Protocols)
While every USB-C plug looks identical on the outside, they are very different on the inside. This is where most people get frustrated. A USB-C cable could be any of the following:

| Feature         | Low-End USB-C        | High-End USB-C                              |
| :-------------- | :------------------- | :------------------------------------------ |
| Data Speed      | USB 2.0 (480 Mbps)   | USB4 / Thunderbolt 4 (40 Gbps+)             |
| Power           | Basic 5V (up to 15W) | PD 3.1 (up to 240W)                         |
| Video           | No Video support     | DisplayPort Alt Mode (Connects to Monitors) |
| Internal Wiring | 4-12 wires           | Full 24-pin wiring                          |

3. Professional vs. Casual Usage

`"USB Type-C"`: This is the term you will find in technical data sheets, engineering manuals, and official USB-IF (USB Implementers Forum) documentation.

`"USB-C"`: This is the consumer-friendly branding used by Apple, Samsung, and Google in their marketing and on product boxes.

### Can you do PD protocol without a "Control Chip" for 12V 9V?

If by "control chip" you mean the PD negotiation chip, the answer is still no.
You cannot use resistors (like the 10kΩ trick) to get 12V. Resistors only signal current limits at 5V. To get 12V, you need a PD Source Controller.




### basic fast charge setup 


The "High Current" Resistor Trick

USB-C identifies power capability based on the resistance detected on the **CC1** and **CC2** pins. To signal that your 5V supply can handle more than the standard 500mA, you must connect the CC pins to **VBUS (5V)** using specific resistor values.

| Resistor Value (Pull-up to 5V) | Advertised Current | Status                          |
| :----------------------------- | :----------------- | :------------------------------ |
| **56kΩ**                       | 500mA / 900mA      | Default USB (Slow)              |
| **22kΩ**                       | 1.5A               | Medium Speed                    |
| **10kΩ**                       | 3.0A               | **High Speed (Fastest for 5V)** |

---

#### 2. Wiring Diagram for 5V 2A DIY Charging

Since your power supply provides **2A**, using **10kΩ resistors** is the best way to ensure the phone attempts to pull the maximum available current.

##### **Steps:**
1.  **VBUS:** Connect your Power Supply (+) to the USB-C VBUS pin.
2.  **GND:** Connect your Power Supply (-) to the USB-C GND pin.
3.  **CC1 Pin:** Connect a **10kΩ resistor** from CC1 to VBUS (5V).
4.  **CC2 Pin:** Connect a **10kΩ resistor** from CC2 to VBUS (5V).
  

#### 3. Limitations & Real PD
If you want the phone to display **"Fast Charging"** (which usually requires 9V/2A or 18W+), a simple 5V connection is not enough. You would need:

* **A Boost Converter:** To step up your 5V to 9V.
* **A PD Controller Chip:** (e.g., IP6505 or SW3516) to "talk" to the phone and negotiate the higher voltage.

> **Warning:** Using 10kΩ resistors signals to the phone that it can pull up to 3A. If your 5V 2A power supply does not have **Over-Current Protection (OCP)**, the phone might try to pull more than 2A, causing your power supply to overheat or fail.


### basic charge setup 

#### 1. The Role of the CC Pin (Configuration Channel)
In the USB-C specification, the power pins (VBUS) are "cold" by default. The phone (the Sink) will not pull power unless it detects a specific signal on the **CC pins**.

* **Detection:** The phone looks for a specific voltage level on the CC1 or CC2 pins. 
* **The Problem:** If you only connect 5V and GND, the CC pins remain "floating" (disconnected). The phone’s charging controller assumes nothing is plugged in and will keep its internal charging gates closed to protect the battery.



---

#### 2. How to Make it Work (The 5.1kΩ Trick)
If you are DIY-ing a power source and want the phone to recognize the 5V supply, you must simulate a "Standard Downstream Port" (SDP).

* **The Fix:** Connect a **5.1kΩ resistor** between the **CC pin** and **GND**.
* **The Result:** This resistor tells the phone: "I am a basic power source capable of providing 5V." 
* **Limitation:** Without data line (D+/D-) negotiation or Power Delivery (PD) communication, the phone will usually limit itself to a slow charge (roughly 500mA to 1.5A).



---

#### 3. Summary Table

| Connection                 | Result          | Why?                                                         |
| :------------------------- | :-------------- | :----------------------------------------------------------- |
| **5V + GND Only**          | **No Charge**   | The CC pin is floating; the phone doesn't "see" the charger. |
| **5V + GND + 5.1kΩ on CC** | **Slow Charge** | The resistor triggers the basic 5V detection.                |
| **Full USB-C Cable**       | **Fast Charge** | PD (Power Delivery) chips negotiate higher voltage/current.  |

---

#### ⚠️ Potential Risks
* **Voltage Sag:** If your 5V source isn't stable, the phone might repeatedly connect and disconnect as the voltage drops under load.
* **Heat:** Cheap DIY connections can have high resistance, leading to heat at the connector.


### SBU SDK info 

Repurposing USB-C SBU Wires

In the USB-C standard, **SBU1** and **SBU2** are "extra" wires. While they were originally intended for DisplayPort or Analog Audio, they are perfect for adding custom features to a small robot like your [[ESP32-S3-dat]] quadruped. - [[robotic-dat]]

#### 1. Electrical Constraints (Safety First)
| Constraint | Limit | Reason |
| :--- | :--- | :--- |
| **Max Voltage** | **3.3V** | SBU wires connect to ESP32 GPIOs; 5V will fry them. |
| **Max Current** | **< 50mA** | These wires are extremely thin (30-32 AWG). |
| **Best For** | **Logic Signals** | Buttons, I2C, UART, or Analog Sensors. |
| **Avoid** | **Power Delivery** | Never use SBU to power servos or bright LEDs. |

---

#### 2. Practical DIY Examples

##### A. External "Kill-Switch" (Safety)
If your robot's gait code fails and it starts running into a wall:
- **Wiring:** Connect a button between **SBU1** and **GND** at the cable end.
- **Code:** Set the ESP32 pin to `INPUT_PULLUP`. 
- **Action:** If the pin goes `LOW`, the code stops all servos immediately.

##### B. Remote I2C Debugging Screen
Since your robot is small and space is limited, you can keep the screen outside the robot:
- **Wiring:** Use **SBU1 for SDA** and **SBU2 for SCL**.
- **Usage:** Connect a tiny 0.91" OLED display to the end of your USB cable.
- **Benefit:** You can read real-time "Leg Degrees" or "Battery Voltage" while the robot moves.

##### C. Remote "Boot" or "Reset" Button
If the ESP32-S3 is hidden inside a chassis:
- **Wiring:** Connect **SBU1** to the **EN (Reset)** pin or **BOOT (GPIO 0)** pin.
- **Benefit:** You can put the robot into "Upload Mode" or Reset it without opening the shell.

---

#### 3. Using SBU for Audio (Important Logic)
While a PC will not "read" analog audio from SBU pins automatically, you can 
build a custom point-to-point system:

- **Legacy Audio Mode:** In custom hardware, **SBU1** is often used for the 
  **Microphone** signal and **SBU2** for **Analog Ground**.
- **DIY Implementation:** 1. Send a low-voltage analog signal from a microphone through SBU1.
  2. Use an ADC (Analog-to-Digital Converter) pin on the ESP32-S3 to read it.
  3. **Note:** You must use a **0.1µF capacitor** to filter out the electrical 
     noise caused by your SG90 servos, as they share the same ground.

---

#### 4. How to Identify SBU Wires
Since manufacturers use different colors, use a Multimeter in "Continuity Mode":
1. Touch one probe to **Pin A8 (SBU1)** or **Pin B8 (SBU2)** on the USB-C plug.
2. Touch the other probe to the stripped wires until you hear a "Beep."
3. **Label them immediately** with tape to avoid mixing them up with VCC/GND.


## ref 

- [[USB-type-c]]