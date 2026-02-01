
# sensor-soil-moisture-dat


- [[sensor-soil-dat]]



## board 

- [[STH1052-dat]] - soil moisture sensor board






## working principles 

The principle of detecting soil moisture is mainly **based on measuring how the presence of water affects the electrical or physical properties of the soil**. The most common types are as follows:

---

### 🌱 1. Resistive (Conductivity-Based) Principle
**Principle:**  
The more water in the soil, the higher its conductivity (lower resistance) because water contains electrolytes. When the soil is dry, resistance increases.

**How it works:**  
- Two metal probes are inserted into the soil.  
- A small voltage is applied across them.  
- The resulting current or resistance is measured and converted to moisture content.

**Advantages:** Simple, inexpensive, fast response.  
**Disadvantages:** Electrodes corrode easily, affected by soil salinity, limited long-term stability.

---

### 🌾 2. Capacitive Principle
**Principle:**  
The dielectric constant of water (~80) is much higher than that of dry soil (~4) or air (~1).  
As soil moisture increases, the dielectric constant of the soil rises, and the sensor’s capacitance increases.

**How it works:**  
- The sensor forms a capacitor (with metal probes or plates).  
- The capacitance change is measured and calibrated to indicate moisture level.

**Advantages:**  
- No direct electrical contact with soil (non-corrosive).  
- High stability, suitable for long-term monitoring.  

**Disadvantages:**  
- Slightly higher cost.  
- Requires high-frequency measurement circuitry.

---

### 🌿 3. Time Domain Reflectometry (TDR)


**Principle:**  

The propagation speed of an electromagnetic pulse in soil depends on the soil’s dielectric constant, which varies with moisture content.  
More water → higher dielectric constant → slower signal propagation.

**How it works:**  
- A high-frequency pulse is sent along probes.  
- The reflection time or waveform change is measured.  
- The dielectric constant is calculated and converted into volumetric water content.

**Advantages:** Very accurate, measures volumetric water content.  
**Disadvantages:** Expensive and complex equipment.

---

### 🍂 4. Neutron Scattering Method (Scientific Use)
**Principle:**  
Fast neutrons are slowed down when they collide with hydrogen atoms (mainly from water molecules).  
The number of slow neutrons detected indicates the soil water content.

**Advantages:** Extremely accurate.  
**Disadvantages:** Very expensive, requires radioactive sources, strict safety requirements.

---

### ✅ Comparison Table

| Type | Measurement Basis | Accuracy | Cost | Stability | Characteristics |
|------|--------------------|----------|------|------------|----------------|
| Resistive | Conductivity | ★★ | Low | ★ | Simple but corrodes easily |
| Capacitive | Dielectric constant | ★★★ | Medium | ★★★ | Stable, most commonly used |
| TDR | Electromagnetic wave velocity | ★★★★★ | High | ★★★★★ | High precision, research use |
| Neutron | Hydrogen atom count | ★★★★★ | Very High | ★★★★ | Laboratory / scientific use |



## ref 

- [[sensor-dat]]