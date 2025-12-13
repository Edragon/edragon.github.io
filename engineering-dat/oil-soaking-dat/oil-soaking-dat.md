
# oil-soaking-dat.md


- [[electrochemical-corrosion-dat]]

## power burned 

![](2025-12-04-00-46-41.png)


It looks like your 12V camera, after being soaked in mineral oil for a while, fails to start up after being powered off and on again.  

This situation is very common in electronics "oil immersion" experiments. Let me help you analyze the most likely causes and troubleshooting methods.

✅ Why does soaking in mineral oil cause startup failure?

1. Oil enters the interior, causing poor heat dissipation → Chip overheating and damage

Mineral oil is insulating, but its heat dissipation is worse than air.  
Inside the camera, there are usually:

- Image sensor (CMOS)
- ISP chip
- DC-DC power supply
- Voltage regulator IC

These components are already prone to heating. After oil immersion, the temperature rises, which may cause:

- Chip solder balls to fall off (especially BGA packages)
- Voltage regulator damage
- Capacitors aging due to long-term overheating

👉 Symptoms: The camera lights up for a few seconds after powering on, then slowly goes dark or doesn't light up at all.

2. Oil dissolves certain materials → Causes short circuits or failure

Although mineral oil is insulating, it is not friendly to some component materials:

- Rubber seals may swell and soften → Oil seeps into the lens and sensor area
- Some plastic housings may soften → Component displacement
- Thermal paste / thermal grease dissolves → Chips lose heat dissipation path
- Adhesive for lens attachment swells → Lens shifts or even falls off

👉 Lens misalignment can also cause the camera to fail to start (auto-calibration fails).

3. Oil enters connectors → Poor contact

Typical examples:

- FPC (flex cable) connectors get oil inside → Poor contact of spring contacts
- Lens module to mainboard interface gets oil → Abnormal resistance values
- DC plug / solder joints get oil in the gaps → Increased contact resistance

👉 Symptoms: Completely dark, almost no current flows, or current instantly drops to 0 when plugged in.

4. Electrolytic capacitors affected by oil (severe cases)

Although mineral oil is non-conductive, long-term soaking can cause the rubber seal of electrolytic capacitors to age, leading to:

- Internal electrolyte evaporation
- Capacitor ESR increases → Unstable power supply

Cannot power on or keeps rebooting

🔍 Troubleshooting you can do (safe, non-destructive)

① Measure the power-on current (most important)

If you have a multimeter, measure the camera's current:

| Current Behavior                  | Suspected Fault                        |
|------------------------------------|----------------------------------------|
| 0 mA                              | Interface open, fuse blown, DC/DC front-end failure |
| Power on: tens of mA → drops to 0 | Startup failure/auto-protection        |
| Stable 200–300 mA, no change      | Chip short circuit/internal damage     |
| Regular 100–200 mA fluctuations   | Unstable power, capacitor ESR increased|

② Low-temperature drying

Although mineral oil does not evaporate, a layer of oil may remain on the PCB and affect contact.

You can:

- Use a napkin to absorb surface oil
- Place in a 40–50°C environment for 24 hours to slowly remove oil  
  (Do not exceed 60°C, or plastic parts may deform)

③ Clean flex cables and connectors

The most vulnerable part is the "flex cable + connector".

Method:

- Remove the flex cable
- Clean the cable's gold fingers with isopropyl alcohol (IPA)
- Gently blow air into the connector, let it dry
- Reinsert

80% of "oil immersion failures" in cameras are caused by poor flex cable contact.

④ Open and check if the lens module has oil ingress

If the lens group has oil inside:

- Internal blades will be contaminated by oil
- Optical module cannot work properly
- Sensor cannot initialize → Camera does not power on or freezes

💡 If you like, I can continue to help you:

Please tell me the current when you power on.  
For example:

- 0 mA
- 0 → 200 mA → 0
- Stable 150 mA
- Irregular fluctuations

As long as you provide the power-on current, I can further determine if it is:

- Power stage failure
- Connector contact issue
- Sensor module damage
- Chip overheating damage
- DC-DC power instability


## ref 

- [[oil-mineral-dat]]