


# FHSS-dat


- [[ELRS-dat]] - [[FHSS-dat]] - [[rc-protocols-dat]]



## Solution 1: Use Receiver Voltage (RX-V) instead of RSSI


The HT-8A screen displays RX-V (Receiver Voltage) and transmits basic telemetry / link status, but standard budget FHSS setups often do not pass a clean digital RSSI packet through to Betaflight via traditional SBUS.

Instead of displaying an RSSI percentage that may not work without a dedicated analog line, many pilots using this hardware combination simply disable the RSSI element in Betaflight OSD and rely on Craft Name, Battery Voltage (Main LiPo), or Fly Time.

## Solution 2: Check if Analog RSSI Pad is Available on Your Flight Controller


If you absolutely must have an RSSI indicator on your OSD with this budget receiver:

Check your FPV receiver (e.g., Hotrc F-08A or similar) to see if it has an RSSI or PWM/Analog output pad.

If it does, run a physical signal wire from that pad to an RSSI or ADC pad on your flight controller.

In Betaflight Configuration tab, enable RSSI ADC Analog.

In the OSD tab, enable the RSSI Value element.



## ref 


