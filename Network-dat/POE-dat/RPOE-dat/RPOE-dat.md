


# RPOE-dat

- [[POE-dat]] - [[RPOE-dat]] 


**RPoE** (or **RPOE**) usually stands for **Reverse Power over Ethernet**—a variation of standard PoE where electrical power travels *toward* the switch or hub instead of *away* from it. (In a few specific hardware manuals, like Ashly Audio's `RPOE-1` injector, "RPOE" is simply a model prefix for a remote PoE injector.)

### Standard PoE vs. Reverse PoE (RPoE)

| Feature               | Standard PoE                                                                 | Reverse PoE (RPoE)                                                                               |
| --------------------- | ---------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------ |
| **Power Direction**   | Switch/injector pushes power **out** to edge devices (cameras, APs, phones). | Edge/client devices push power **in** to an upstream switch, media converter, or hub.            |
| **Where Power Lives** | Centralized at the switch/closet.                                            | Distributed at remote/subscriber endpoints.                                                      |
| **Typical Use Case**  | Indoor APs, IP security cameras, VoIP phones.                                | Rooftop/hallway ISP or WISP switches, fiber media converters, CPEs, multi-dwelling distribution. |

### How RPoE Works and Why It Is Used

In a typical RPoE setup, an outdoor or hallway switch or fiber media converter sits in a spot where AC mains power and a UPS are hard to install or pay for. Instead of running a dedicated power line to that switch, power is injected over the Ethernet cables coming *from* downstream/client locations (often via PoE injectors on the client side) into the RPoE switch's ports.

Key practical advantages and caveats:

* **No local AC outlet needed at the switch:** Allows ISPs, WISPs, or building installers to power a distribution switch or optical converter from one or more connected lines.
* **Redundancy across lines:** If a switch accepts reverse power from multiple connected ports, it can sometimes stay up even if one downstream link loses power (depending on hardware design).
* **Standards & voltage differences:** Many RPoE switches use passive or proprietary DC ranges (such as 18V–48V or 24V DC) rather than full IEEE 802.3af/at/bt negotiation, so matching voltage, polarity, and wattage limits is essential.
* **Cable distance & loss:** Like standard Ethernet PoE, voltage drop over long Cat5e/Cat6 runs reduces available wattage at the receiving end.




## ref 