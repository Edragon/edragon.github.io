

# single-end-double-end-dat

## Relationship and Evolution: Flyback, Forward, Half-Bridge, and Full-Bridge Topologies

In isolated switched-mode power supplies (SMPS), **Flyback**, **Forward**, **Half-Bridge**, and **Full-Bridge** are not isolated concepts—they belong to the same family of isolated DC-DC converter topologies.

Their fundamental relationships can be understood through two primary criteria: **transformer magnetization mode (single-ended vs. double-ended)** and **circuit lineage (Buck-derived vs. Buck-Boost-derived)**.

---

## 1. Classification by Transformer Magnetization (Single-Ended vs. Double-Ended)

This is the most critical physical distinction among these topologies:


                    Isolated DC-DC Topologies
                              |
        +---------------------+---------------------+
        |                                           |
    [Single-Ended]                               [Double-Ended]
    Unidirectional Magnetization                 Bidirectional Symmetrical Magnetization
    (Quadrant I only)                            (Quadrants I & III)
            |                                           |
        +---+---+                                   +---+---+
        |       |                                   |       |
    Flyback  Forward                         Half-Bridge Full-Bridge


### 1) Single-Ended Topologies: Flyback & Forward
* **Core Trait:** Primary current flows in only one direction, utilizing only Quadrant I of the transformer's $B\text{-}H$ hysteresis loop.
* **Operating Constraint:** The transformer core **must be explicitly demagnetized (reset)** during the switch OFF-time to prevent magnetic saturation.
* **Limitation:** Lower core utilization limits these topologies primarily to **low-to-medium power applications**.

### 2) Double-Ended Topologies: Half-Bridge & Full-Bridge
* **Core Trait:** Primary current alternates direction every half-cycle, achieving **symmetrical bidirectional magnetization** across Quadrants I and III.
* **Operating Constraint:** Natural magnetic balance occurs as negative half-cycles reset positive half-cycles—**no dedicated demagnetization/reset circuit is required**.
* **Advantage:** Maximum transformer core utilization, enabling higher power density for **medium-to-high and ultra-high power levels**.

---

## 2. Classification by Circuit Lineage (Buck vs. Buck-Boost Families)

Looking at the secondary-side power stage and how energy is transferred:

* **[Buck-Boost Lineage] — Flyback**
  * Stores energy during switch ON-time; releases energy during switch OFF-time.
  * No secondary output inductor required.

* **[Buck Lineage] — Forward / Half-Bridge / Full-Bridge**
  * Transfers energy directly during switch ON-time.
  * Requires a secondary rectifier, freewheeling diode, and filter inductor.


* **Flyback:** Unique standalone structure. It is the only isolated topology derived from the **Buck-Boost** converter (functioning as a coupled inductor).
* **Forward, Half-Bridge, and Full-Bridge:** All three are **isolated variants of the Buck converter**. They share identical secondary-side filter architectures requiring a secondary smoothing inductor.

---

## 3. Structural Power Evolution: Forward $\rightarrow$ Half-Bridge $\rightarrow$ Full-Bridge

If the **Forward converter** is viewed as the baseline isolated Buck topology, **Half-Bridge** and **Full-Bridge** represent structural upgrades designed to overcome the power limits of single-ended transformers:


    Forward Converter          Half-Bridge Converter        Full-Bridge Converter
    [1-2 Switches, 100W~500W] ──> [2 Switches, 300W~1kW] ──> [4 Switches, 1kW~10kW+]
    (Unidirectional Core /       (Bidirectional Core /        (Bidirectional Core /
    Demag Circuit Needed)       Half Primary Voltage)        Full Primary Voltage)

1. **Forward Converter (1 or 2 Switches):**
   * Uses 1 or 2 switches. Unidirectional magnetization and the need for core reset limit practical power scaling (typically capped under $500\text{ W}$).
2. **Half-Bridge Converter (2 Switches):**
   * Employs 2 switches in a totem-pole arrangement to enable **bidirectional magnetization**.
   * Eliminates the demagnetization circuit while applying $\frac{1}{2} V_{in}$ across the transformer primary, scaling power capability to $300\text{ W} \sim 1\text{ kW}$.
3. **Full-Bridge Converter (4 Switches):**
   * Uses 4 switches in an H-bridge configuration to maintain **bidirectional magnetization** while applying the **full $V_{in}$** across the transformer primary.
   * Delivers double the output power of a Half-Bridge at the same primary current, serving high-power demands from $1\text{ kW}$ to well over $10\text{ kW}$.

---

## Summary Mapping

| Topology | Magnetization Type | Circuit Lineage | Switch Count | Transformer Core Utilization | Typical Power Application |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Flyback** | **Single-Ended** (Unidirectional) | **Buck-Boost** | 1 | Low (Store / Release) | $< 100\text{ W}$ (Adapters, bias supplies) |
| **Forward** | **Single-Ended** (Unidirectional) | **Buck** | 1 or 2 | Low (Requires core reset) | $100\text{ W} \sim 500\text{ W}$ (Telecom / industrial bricks) |
| **Half-Bridge**| **Double-Ended** (Bidirectional) | **Buck** | 2 | High (Alternating symmetry) | $300\text{ W} \sim 1\text{ kW}$ (PC ATX, mid-power supplies) |
| **Full-Bridge**| **Double-Ended** (Bidirectional) | **Buck** | 4 | Highest (Full voltage drive) | $1\text{ kW} \sim 10\text{ kW}+$ (EV OBC, servers, solar inverters) |

## ref 

