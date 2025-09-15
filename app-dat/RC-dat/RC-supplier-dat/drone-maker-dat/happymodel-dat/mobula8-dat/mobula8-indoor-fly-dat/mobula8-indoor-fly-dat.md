
# mobula8-indoor-fly-dat

- [[betaflight-PID-dat]]


1. Flight Modes

Enable Angle or Horizon Mode for self-leveling and easy control indoors.
- Angle: safest, no flips/rolls.
- Horizon: allows gentle flips/rolls, still self-levels.

2. Rates and Expo

- Lower your rates (e.g., 400–500 deg/s) for smoother, slower stick response.
- Increase expo (e.g., 0.3–0.5) for finer control near center stick.

3. PID Tuning

- Lower P and D gains slightly for softer, less twitchy response.
- Increase I gain a bit to help hold attitude against drafts.
- Use the “tuned profile” in your table as a starting point, but reduce values if the quad feels too sharp.

4. Feedforward

Set Feedforward (FF) lower for smoother, less aggressive stick response (e.g., 130–140).

5. Anti-Gravity

Enable Anti-Gravity and set gain to 10 or higher for stable altitude during throttle changes.

6. Throttle and Motor Settings

- Motor Output Limit: Set to 75–80% for safer, gentler indoor power.
- Throttle Boost: Set low (5–7) for smooth throttle response.
- Dynamic Idle: Set to 30–35 to prevent motor stalling at low throttle.
- Vbat Sag Compensation: Enable to keep performance consistent as battery drains.

7. Master Multiplier/Sliders

Keep Master Multiplier low (0.5–1.0) for gentle, stable flight.

8. Angle/Horizon Strength

Lower “Strength” and “Angle Limit” for less aggressive self-leveling and more cinematic movement (see your “optimized for indoor fly” table).


## ref 

- [[indoor-fly-dat]] - [[indoor-fly]] - [[betaflight]]