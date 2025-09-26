
# SPICE-dat

LM358 Inverting Amplifier Example

    Vcc VCC 0 DC 12
    Vee VEE 0 DC -12
    Vin IN 0 SIN(0 0.1 1k)   ; 100 mV amplitude, 1 kHz sine input

    R1 IN NINV 1k
    Rf NINV OUT 10k
    XU1 OUT NINV 0 VCC VEE LM358   ; op-amp instance

    .tran 0 10m
    .plot tran V(IN) V(OUT)
    .end



```markdown
# 🔌 Free Online SPICE Simulators

## 1. Falstad Circuit Simulator
- [https://falstad.com/circuit](https://falstad.com/circuit)  
- Browser-based, very visual, easy for beginners.  
- Drag-and-drop schematic style.  
- Not strict SPICE syntax, but good for quick logic/analog tests.  
- Limited component models (no full LM358), but can approximate op-amps.  

---

## 2. Ngspice on EasyEDA
- [https://easyeda.com](https://easyeda.com) (free signup required)  
- Cloud schematic editor with SPICE simulation built-in.  
- Supports real models (LM358, MOSFETs, etc.).  
- Can go directly from schematic → PCB.  
- Good if you want both sim + PCB design in one.  

---

## 3. PSPICE Online (OrCAD Cloud)
- [https://pspice.com/simulation](https://pspice.com/simulation)  
- Web-based version of OrCAD PSpice.  
- Requires free registration.  
- Professional-grade, supports vendor models.  

---

## 4. CircuitLab
- [https://www.circuitlab.com](https://www.circuitlab.com)  
- In-browser schematic capture + simulator.  
- Clean interface, works like LTspice lite.  
- Free version has limitations (saving/exporting), but works for small circuits.  

---

## 5. TINACloud (Texas Instruments)
- Desktop: [https://www.ti.com/tool/TINA-TI](https://www.ti.com/tool/TINA-TI)  
- Online: [https://www.tina.com/tinacloud/](https://www.tina.com/tinacloud/)  
- TI’s free simulator, works with TI models (LM358 included).  
- Requires TI account.  

---

## 6. PartSim
- [https://www.partsim.com](https://www.partsim.com)  
- Browser-based, SPICE backend.  
- Free and simple, good for hobby-level circuits.  
- Not as advanced as LTspice, but decent for quick tests.  

---

# ⚡ Recommendation
- **Beginner / quick tests** → Falstad.  
- **Want real LM358 model + PCB** → EasyEDA.  
- **More professional, TI chips** → TINACloud.  
- **General purpose** → CircuitLab or PartSim.  
```
