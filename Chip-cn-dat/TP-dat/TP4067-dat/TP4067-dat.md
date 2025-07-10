
# TP4067-dat

## TP4067 

3mA-600mA Linear Li-ion Battery Charger

The TP4067 is a complete single-cell lithium battery charger, the world's first single-chip solution with **battery reverse polarity protection and input power reverse polarity protection**. It supports a wide charging current range from 3mA to 600mA.

Using trickle, constant current, and constant voltage control, the SOT23-6 package and minimal external components make the TP4067 an ideal choice for portable applications. The TP4067 is suitable for both USB power and adapter power sources.

Thanks to its internal PMOSFET architecture and anti-reverse charging circuit, there is no need for external detection resistors or isolation diodes. Thermal feedback automatically adjusts the charging current to limit the chip temperature during high-power operation or high ambient temperature conditions.

The fully charged voltage can be set to four levels: 4.35V, 4.2V, 3.7V, and 2.8V. The charging current can be set externally with a resistor. When the battery reaches the preset voltage, the charging current drops to 1/10 of the set value, and the TP4067 will automatically terminate charging.

When the input voltage (AC adapter or USB power) is removed, the TP4067 automatically enters a low current state, with battery leakage current below 1μA. Other features of the TP4067 include power adaptation, undervoltage lockout, automatic recharge, and two status pins for indicating charging completion and input voltage connection.

**Schematic is the same as TP4057 as below** == [[TP4057-dat]]


