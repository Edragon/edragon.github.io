
# DS3231-dat 


https://www.analog.com/media/en/technical-documentation/data-sheets/ds3231.pdf


The DS3231 is a low-cost, high-precision I2C real-time clock (RTC) with an integrated temperature-compensated crystal oscillator (TCXO) and crystal.

The device includes a battery input to maintain accurate timekeeping when mains power is removed.

Integrated crystal oscillators improve the long-term accuracy of the device and reduce component count on the production line.

The DS3231 is available in commercial and industrial temperature ranges and is available in a 16-pin 300mil SO package.

The RTC stores seconds, minutes, hours, day of the week, date, month and year information. For months with less than 31 days, the end of the month date will be automatically adjusted, including corrections for leap years.

The clock can operate in 24-hour or 12-hour format with /AM/PM indication.

Provides two programmable calendar alarms and a programmable square wave output. Address and data are transmitted serially through the I2C bidirectional bus.

Precision, temperature-compensated voltage reference and comparator circuitry monitors VCC status, detects power supply failures, provides a reset output, and automatically switches to backup power when necessary.

Additionally, the /RST monitor pin can be used as a manual input to generate a μP reset.

In addition to high timing accuracy, the DS3231 also has some other functions that expand the system host's additional functions and options.

A very accurate digital temperature sensor is integrated inside the device and can be accessed (like the time) via the I2C* interface. The accuracy of this temperature sensor is ±3°C.

On-chip control circuitry enables automatic power detection and manages power switching between primary and backup power sources (i.e., low-voltage batteries).

If the main power supply is lost, the device continues to provide accurate timing and temperature with unaffected performance.

An on-chip reset function can be used to restart the system microprocessor when the main power supply is re-applied or the voltage value returns to an acceptable range.