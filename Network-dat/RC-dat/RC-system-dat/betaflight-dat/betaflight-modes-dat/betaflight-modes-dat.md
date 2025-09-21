
# betaflight-modes-dat


- [[radiomaster-dat]]

## Modes 

| Mode               | AUX         | radiomaster | set  | Notes |
| ------------------ | ----------- | ----------- | ---- | ----- |
| ARM                | AUX 1       | SA          | HIGH |       |
| Angle              | AUX 2  HIGH | SB          | HIGH |       |
| Horizon            | AUX 2       | SB          | MID  |       |
| acro Mode          | AUX 2       | SB          | x    |       |
| Air Mode           | AUX 3       | SC          | MID  |       |
| Flip After a Crash | AUX 3       | SC          | HIGH |       |
| Beeper             | AUX 4       | SD          | HIGH |       |



Air mode is very stable, good for beginners





### What is Air Mode?

Air Mode is a **Betaflight flight feature** that keeps the motors active and responsive even at **zero throttle**.  

- Without Air Mode:  
  - When you cut throttle, motors almost stop spinning.  
  - The quad loses control authority and can "fall" or tumble.  
- With Air Mode ON:  
  - Motors always maintain some thrust (idle speed).  
  - You can still control pitch, roll, and yaw when throttle stick is at minimum.  

### Why Use Air Mode on Whoops?
- ✅ Smoother hovering and stable control, even at low throttle.  
- ✅ Prevents sudden drop when you release throttle indoors.  
- ✅ Essential for flips, rolls, or freestyle tricks.  
- ⚠️ For very small **brushed whoops**, it can make them bounce indoors (too sensitive).  



In the standard mixer/ mode, when the roll, pitch and yaw gets calculated and saturates a motor, all motors will be reduced equally. 

When a motor goes below minimum it gets clipped off. Say you had your throttle just above minimum and tried to pull a quick roll - since two motors can't go any lower, you essentially get half the power (half of your PID gain). 

If your inputs would have asked for more than a 100% difference between the high and low motors, the low motors would get clipped, breaking the Symmetry of the motor balance by unevenly reducing the gain