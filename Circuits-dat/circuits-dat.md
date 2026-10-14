
# circuits-dat 





- [[circuits-dat]] - [[PCB-design-dat]] - [[resistor-dat]] - [[capacitor-dat]] - [[RCL-dat]]



- [[impedance-dat]] - [[virtual-ground-dat]] - [[circuits-dat]]




- [[interface-dat]] - [[power-dat]]

- [[logic-dat]] - [[logic-gate-dat]] - [[buffer-dat]] - [[logic-level-shifter-dat]] - [[multiplexer-dat]]

- [[74xx-dat]]

- [[protection-dat]]

- [[signal-differential-dat]] - [[signal-dat]]

- [[MMA7660-dat]] - [[SD-card-dat]]

- [[mosfet-dat]] - [[logic-gate-dat]]








- [[auto-serial-dat]]

- [[LC-circuits-dat]]

- [[DC-blocking-dat]] - [[AC-blocking-dat]]



- [[switching-dat]] - [[switch-dat]]


- [[comparator-dat]] - [[latch-dat]]

- [[PPL-dat]]

- [[counter-dat]]

- [[PWM-dat]]

- [[timer-dat]]


- [[Multivibrator-dat]]

- [[mosfet-dat]]

- [[Optical-Coupler-DAT]]

- [[Vref-dat]]

- [[Multiplexer-dat]]

- [[switching-dat]]

- [[amplifier-dat]] - [[op-amp-dat]]

- [[LNA-dat]]

- [[digital-dat]]

- [[frequency-dat]]



## output 

- [[open-drain-dat]] - [[push-pull-dat]] - [[circuits-dat]] - [[open-collector-dat]]

**Open-Collector / Open-Drain** uses a single transistor that can only pull the output low or let it float.

**Push-Pull** uses two complementary transistors to actively drive the output both high and low.


### Collector vs. Drain

The terms depend on the type of semiconductor technology used in the circuit:

Open-Collector refers to Bipolar Junction Transistors (BJTs). The output pin is tied to the collector of the transistor, with the emitter grounded.

Open-Drain refers to MOSFETs (CMOS logic). The output pin is tied to the drain of the transistor, with the source grounded.

Functionally, they behave identically: they can pull low or float, requiring an external pull-up resistor to go high.


### Why Push-Pull is Different

A push-pull output replaces the single transistor and external resistor setup with a complementary pair of transistors:

BJT version (Totem-Pole): Uses one NPN transistor on top and one PNP transistor on the bottom. One turns on to source current (pull high), and the other turns on to sink current (pull low).

CMOS version: Uses a PMOS transistor on top and an NMOS transistor on the bottom.



## repo 

- https://github.com/Edragon/logic-shifter


## ref 

- [[tech-dat]]