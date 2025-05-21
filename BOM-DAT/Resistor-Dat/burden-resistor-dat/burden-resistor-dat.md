
# burden-resistor-dat

A burden resistor is a component used with current transformers (CTs). - [[current-transformer-dat]]

## Purpose:

**Convert Current to Voltage**: The primary function of a burden resistor is to convert the current output of a current transformer into a voltage signal. CTs are designed to produce a current in their secondary winding that is proportional to the current in their primary winding. 

Many measurement circuits (like analog-to-digital converters in microcontrollers) are designed to read voltage, not current directly. 

The burden resistor, when placed across the secondary winding of the CT, allows this current to develop a voltage across it (V = I * R).

**Provide a Load**: It provides a necessary load for the current transformer. Operating a CT without a burden (i.e., with an open-circuited secondary) can lead to dangerously high voltages across the secondary terminals, potentially damaging the CT or posing a safety hazard.
Selection:

The value of the burden resistor is chosen based on the CT's characteristics (like its turns ratio and maximum secondary current) and the desired output voltage range for the measurement circuitry.

It's important **not to choose a burden resistor value that is too high**, as this can lead to saturation of the CT core, causing inaccurate readings.


In summary, a burden resistor is crucial for safely and accurately measuring current using a current transformer by converting its current output to a measurable voltage and providing a safe operating load.


## ref 

- [[resistor-dat]]