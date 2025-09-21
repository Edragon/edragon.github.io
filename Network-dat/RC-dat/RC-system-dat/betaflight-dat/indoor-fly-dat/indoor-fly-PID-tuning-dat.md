
# indoor-fly-PID-tuning-dat.md


→ **Damping: D Gains → 1.0–1.4**  
- Keep moderate to reduce fast oscillations  
- Avoid too high → jitter on small indoor props  

→ **Tracking: P & I Gains → 1.0**  
- Stable for indoor hover  
- Low enough to prevent twitchy movement  

→ **Stick Response: FF (Feedforward) Gains → 0.8–1.0**  
- Smooth, predictable response to stick input  
- Don’t overdo → prevents overcorrecting during small indoor maneuvers  

→ **Dynamic Damping: D Max → 0**  
- Disable aggressive D scaling for indoor flight  
- Keeps quad smooth in low-throttle hover  

→ **Drift / Wobble: /Gains → 0.8–1.0**  
- Helps slow drift correction  
- Avoid too high → quad oscillates slowly  

→ **Pitch Damping: Pitch:Roll D → 1.0**  
- Keep pitch & roll D similar → balanced indoor control  

→ **Pitch Tracking: Pitch:Roll P, I & FF → 1.0**  
- Keeps stable hover during small corrections  

→ **Master Multiplier → 1.5–1.6**  
- Adjust global scale of all PID terms  
- Indoor: keep lower to avoid twitchy behavior  



✅ Notes:  

- Test hover after each adjustment  
- Make small increments (0.05–0.1)  
- Goal: smooth, steady indoor hover with minimal stick corrections


## ref 

- [[betaflight-PID-dat]]