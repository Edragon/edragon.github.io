

# FPV-size-dat


- [[thrust-dat]] - [[FPV-load-dat]] - [[FPV-size-dat]]

- [[battery-paradox-dat]] - [[FPV-size-dat]]



## Summary


| Size   | Typical Weight | Battery / Power | Rotor Disk Load | Endurance  | Payload Capacity                    | Best Use                         |
| :----- | :------------: | :-------------- | :-------------- | :--------- | :---------------------------------- | :------------------------------- |
| 3.5 in |     ~250 g     | 4S 850 mAh      | High            | ~4-6 min   | ~100-150 g (GoPro only, limited)    | Fast freestyle, compact flying   |
| 5 in   |     ~500 g     | 4S 1500 mAh     | Medium          | ~4-6 min   | ~300-400 g (GoPro + gimbal easily)  | General FPV, cinematic work      |
| 7 in   |    ~1000 g     | 6S typical      | Low             | ~15-20 min | ~500-800 g (larger camera / gimbal) | Aerial photography, long flights |


| Topic           | 3.5 in                                    | 5 in                  | 7 in                                                      | Summary                                                                                                |
| :-------------- | :---------------------------------------- | :-------------------- | :-------------------------------------------------------- | :----------------------------------------------------------------------------------------------------- |
| Scaling logic   | Proportional scale                        | Proportional scale    | Breaks the same scaling rule                              | 3.5 and 5 in are close in endurance because their size, weight, battery, and rotor area scale together |
| Endurance       | ~4-6 min                                  | ~4-6 min              | ~15-20 min                                                | Small drones sit in the same efficiency band; 7 in enters a much more efficient regime                 |
| Payload         | Low margin                                | Medium margin         | High margin                                               | Bigger airframes carry proportionally more absolute weight                                             |
| Propeller load  | High                                      | Medium                | Low                                                       | Lower disk loading means less power loss and better efficiency                                         |
| Motor / voltage | High-KV, small motors, 4S                 | Medium-KV, 4S         | Low-KV, higher torque, often 6S                           | 7 in benefits from higher efficiency and lower current draw                                            |
| Camera fit      | GoPro only, limited                       | GoPro + gimbal easily | Mirrorless / larger camera                                | Payload capability is the main reason to choose larger drones for filming                              |
| Main takeaway   | Small and agile, but tight payload margin | Best all-round choice | Best for endurance and payload, but larger and less agile | For aerial filming, 5 in is the practical minimum and 7 in is the better long-flight choice            |


| Rule                     | Explanation                                                                                                         |
| :----------------------- | :------------------------------------------------------------------------------------------------------------------ |
| Endurance is a ratio     | Battery energy and power rise together when the drone is scaled proportionally, so endurance stays roughly the same |
| Payload is absolute mass | A larger drone can carry more total grams even if efficiency remains similar                                        |
| 3.5 vs 5 in              | Similar endurance because both are in the same scaling band                                                         |
| 7 in+                    | Higher efficiency due to lower disk loading, larger props, lower current, and often 6S power                        |
| Best practical choice    | 5 in for balanced FPV and filming; 7 in for serious payload and long flight time                                    |


In short: 

3.5 in and 5 in are effectively the same endurance class, while 7 in is a different efficiency tier. The real reason to move up is not just size—it is payload margin and efficiency.


## whoop by size 

# FPV Drone Categories Comparison

| Category        | Size (Wheelbase / Prop)  | Weight (approx) | Features                              | Best Use Case                         | Example Models                       |
| --------------- | ------------------------ | --------------- | ------------------------------------- | ------------------------------------- | ------------------------------------ |
| **TinyWhoop**   | 65–75mm / 31–40mm props  | 20–30g          | Ducted, safe, brushed/brushless       | Indoor, beginner, safe around people  | Mobula6, BetaFPV Meteor65            |
| **MicroWhoop**  | 75–100mm / 40–50mm props | 30–60g          | Brushless, small ducts, more power    | Indoor & small outdoor                | Mobula7, Meteor85                    |
| **CineWhoop**   | 3 inch / 120–150mm       | 200–400g        | Ducted, smooth flight, carries camera | Cinematic filming (GoPro/naked GoPro) | GEPRC CineLog 30, iFlight Protek35   |
| **Toothpick**   | 2.5–4 inch / 90–160mm    | 40–120g         | Very light, no ducts, carbon frame    | Outdoor freestyle, nimble flying      | Happymodel Sailfly-X, HX115          |
| **Micro Quad**  | 100–150mm / 2–3 inch     | 70–150g         | Small frame, not always ducted        | Small park freestyle & racing         | Emax Babyhawk II, iFlight Alpha A85  |
| **5-inch Quad** | 210–250mm / 5 inch       | 250–600g        | Most common, powerful, versatile      | Freestyle, racing, cinematic w/ GoPro | ImpulseRC Apex, iFlight Nazgul5      |
| **Long Range**  | 6–7 inch                 | 400–800g+       | Large props, GPS, big batteries       | Long-distance cruising, mountains     | iFlight Chimera7, Flywoo Explorer LR |
| **X-Class**     | 10–13 inch+              | >2kg            | Huge, heavy lift, pro cameras         | Professional filming, commercial work | Shendrones Siccario, custom builds   |

- **Whoop**:  
  - Smallest class, typically **65mm–85mm** frames.  
  - Ducted props (prop guards).  
  - Prop size: ~31–40 mm.  
- **Micro (2"–4")**:  
  - Larger, **90mm–150mm** frames.  
  - Open props (no ducts, usually).  
  - Prop size: **2"–4"**.  


## ref