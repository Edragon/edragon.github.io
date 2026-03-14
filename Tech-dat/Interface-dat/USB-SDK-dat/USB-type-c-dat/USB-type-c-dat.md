

# USB-type-c-dat

- [[CONN-USB-type-c-dat]] - [[USB-type-c-dat]] - [[cable-USB-type-c-dat]]

- [[cable-USB-dat]]



## tech 

- [[type-c-sniffer-dat]] 

- [[fast-charge-protocols-dat]] - [[USB-PD-dat]]

## apps 

- [[type-c-to-ethernet-dat]]



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

## ref 

- [[USB-type-c]]