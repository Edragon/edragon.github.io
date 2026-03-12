
# resistor-Inrush-dat

== PTC

- [[resistor-dat]] - [[resistor-Inrush-dat]] - [[thermistor-dat]]




## 🔍 Purpose of 2W 300Ω Resistor Before LM317 Input

### 🔧 Common Use Cases

#### 1. 🛡️ Inrush Current Limiting
- **Function:** When power is first applied, capacitors (especially large filter caps) can draw a big inrush current.
- **The 300Ω resistor** slows the charging rate of the input capacitor.
- Helps protect:
  - Transformer
  - Diodes (in rectifier)
  - LM317 itself

#### 2. 🔥 Power Dissipation / Pre-Regulation
- **Drops excess voltage** before it hits the LM317
- Reduces the **heat load on the LM317**, especially if there's a large **Vin − Vout** difference.

For example:
```
Vin = 24V, Vout = 12V, Load = 50mA
→ Voltage drop across LM317 = 12V
→ Power = 12V × 0.05A = 0.6W (hot!)

Insert a 300Ω resistor:
  V = I × R = 0.05A × 300Ω = 15V drop before LM317
  New Vin = 24V − 15V = 9V → not enough
  So you may adjust value to drop just a few volts
```

- You must ensure **enough voltage remains** after the resistor so that LM317 operates normally (requires at least **Vin ≈ Vout + 2V**).


## ref 

- [[resistor-dat]]