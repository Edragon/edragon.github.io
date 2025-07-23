
# PWM-chopper-type-motor-driver

A "chopper type DC brushed motor driver" is a circuit used to control the speed and direction of a DC brushed motor.

The "chopper" part refers to the technique it uses to regulate the power delivered to the motor. Instead of supplying a continuous variable voltage (like a linear regulator, which can be inefficient), a chopper driver rapidly switches the full supply voltage ON and OFF. This "chopping" action is typically done using Pulse Width Modulation (PWM).

Chopper Type (PWM Chopper):

- **PWM (Pulse Width Modulation)**: The driver switches the voltage to the motor ON and OFF very quickly (many times per second).
- **Duty Cycle**: The speed of the motor is controlled by varying the duty cycle – the ratio of ON-time to the total ON+OFF time period. A higher duty cycle means more average voltage to the motor, making it spin faster. A lower duty cycle means less average voltage, and the motor spins slower.
- **Efficiency**: This method is much more efficient than linear voltage regulation because the switching transistors in the driver are either fully ON (low resistance, low power loss) or fully OFF (no current, no power loss), minimizing the time spent in high-power-dissipation states.
- **Current Control**: Chopper drivers often include current sensing and can use the PWM chopping to limit the current to the motor, protecting both the motor and the driver, especially during startup or stall conditions. The [[TB67H450-dat]], for example, mentions "PWM constant current drive."

## ref 

- [[motor-driver-dat]]