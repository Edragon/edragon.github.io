
# ELRS-faq-dat

## Frequently Asked Questions (FAQ)

**Q1: Can this receiver bind with a transmitter module (TX module) from brand XXX?**
**A:** The ELRS project is open-source. Therefore, as long as the TX module uses the ELRS protocol, regardless of the brand, they can bind with each other, provided three conditions are met:
    1.  **Same Frequency:** Both must operate on the same frequency band (e.g., both 2.4GHz or both 915MHz).
    2.  **Matching Firmware Version:** The firmware versions must be identical. For example, if the TX module is flashed with firmware version 2.5.0, the receiver must also be flashed with version 2.5.0.
    3.  **Binding Phrase:** Either both devices have no binding phrase set, or they both have the exact same binding phrase configured.

**Q2: How do I enter binding mode?**
**A:** After soldering the receiver, quickly power cycle the aircraft three times: power on then immediately power off, power on then immediately power off, power on and leave it on. Each power cycle interval should be less than 1.5 seconds. If performed correctly, the receiver's LED will flash quickly twice in a repeating pattern, indicating it is in binding mode. Then, use the bind function/button on your remote controller (often found in the ELRS Lua script). Once binding is successful, the receiver's LED will turn solid.

**Q3: The first time I used my receiver, it wouldn't enter binding mode, and the LED stayed solid. Why?**
**A:** We've encountered this issue in support cases. It's often caused by an abnormality on the flight controller's TX/RX UART port, which forces the receiver into bootloader/firmware flashing mode upon power-up. Switching the receiver connection to a different, functional TX/RX UART port on the flight controller usually resolves this.

**Q4: Why is my receiver's LED flashing quickly and continuously?**
**A:** If the receiver is powered on but doesn't enter binding mode (or if it's already bound but the remote controller is off), it will automatically enter Wi-Fi firmware update mode after approximately 60 seconds of not receiving a signal. The fast flashing indicates Wi-Fi mode is active.

**Q5: How do I enter Wi-Fi mode to update the receiver's firmware?**
**A:** As mentioned above, simply power on the receiver and wait. If it doesn't connect to a transmitter within about 60 seconds, it will automatically enter Wi-Fi update mode, indicated by the rapidly flashing LED.


## ref 

