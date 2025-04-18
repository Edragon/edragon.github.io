
# CN3768-dat

The CN3768 charging system incorporates several automatic features to optimize battery health and longevity. 

**Deeply discharged batteries** are initially trickle charged at 17.5% of the programmed constant charge current. This continues until the cell voltage reaches 75% of the regulation voltage in over-charge mode. 

The **over-charge phase** ends when the charging current decreases to 38% of the constant charge current, at which point the system transitions to float charge mode. 

If the battery voltage subsequently drops below 83.95% of the over-charge voltage while in float-charge mode, a **new charge cycle** automatically begins. 

Furthermore, the CN3768 automatically enters **sleep mode** when the input voltage falls below the battery voltage, conserving power.


## ref 

[[DSE-CN3768.pdf]]