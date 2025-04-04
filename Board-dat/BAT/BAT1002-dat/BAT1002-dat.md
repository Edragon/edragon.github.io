
# BAT1002-dat

https://www.electrodragon.com/product/linear-battery-charger-by-solar-power-or-usb/



## blink 

When the battery is not present, the charger charges the output capacitor to the regulation voltage quickly, then 
the BAT pin’s voltage decays slowly to recharge threshold because of low leakage current at BAT pin, which 
results in a 100mv ripple waveform at BAT pin, in the meantime,    pin outputs a pulse to indicate that the 
battery’s absence. 

The pulse’s frequency is around 10Hz when a 4.7uF output capacitor is used. 

The open drain status output that is not used should be tied to ground. 



## demo 

- https://x.com/electro_phoenix/status/1662021326901739520


## ref 

- [[consonance-dat]]

- [[BAT1002]]