

# radiomaster-pocket-module-dat

- [[CC2500-dat]] - [[A7105-dat]] - [[CYRF6936-dat]] - [[radiomaster-pocket-module-dat]]

- [[TI-network-dat]] - [[CC2500-dat]]



## 2. Protocol Capabilities (Internal CC2500 vs. FlySky)
The CC2500 version **does not** natively support FlySky protocols (AFHDS / AFHDS 2A) because it lacks the **A7105** RF chip.

| RF Chip | Protocols Supported |
| :--- | :--- |
| **CC2500** *(Inside Pocket CC2500)* | FrSky (D8, D16), Futaba (S-FHSS), RadioLink, Corona, Redpine |
| **A7105** *(Not included)* | FlySky (AFHDS, AFHDS 2A), Hubsan |
| **CYRF6936** *(Not included)* | Spektrum (DSM2, DSMX), Walkera DEVO |

To control FlySky receivers, you must attach an external **Nano 4-in-1 Multi-Protocol Module**.

---

## 3. External Module Support
The RadioMaster Pocket features a **Nano-size (Lite)** external module bay on the back.

### Compatible Modules
* **Multi-Protocol / FlySky:** RadioMaster RM 4IN1 Module (Nano), iRangeX IRX4 Nano
* **Long Range / ELRS:** RadioMaster Ranger Nano (2.4GHz), RadioMaster Bandit Nano (915MHz), TBS Crossfire Nano TX

---

## 4. How to Bind Pocket (CC2500) to Mobula6 (FrSky D8)

1. **Configure EdgeTX on Radio:**
   * Press and hold **`MDL`** -> Scroll to **Internal RF**.
   * Set **Mode** to `FrSky`.
   * Set **Subtype** to `D8` *(Recommended for onboard SPI receivers)*.

2. **Put Drone in Bind Mode:**
   * Connect Mobula6 to **Betaflight Configurator**.
   * Go to the **Receiver** tab -> Click **Bind Receiver** (or enter `bind_rx` in the CLI tab).

3. **Initiate Bind:**
   * Scroll down to **`[Bind]`** on the radio screen and press the scroll wheel.
   * The drone's LED will turn solid once successfully paired.


## ref 


