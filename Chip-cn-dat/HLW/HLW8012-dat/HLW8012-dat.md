
# HLW8012-dat 

- [legacy wiki page ](https://w.electrodragon.com/w/HLW8012)


### Hardware Design Note
* Board AC Mains is be NOT isolated.
* Better use optical-coupler to send isolated signal to your MCU. 
* MCU better use seperated power supply to HLW8012.

#### other note 
* Built-in crystal, 2.43V voltage reference source and power monitoring circuit
* 5V single power supply, operating current less than 3mA

#### Sample resistor 

* Sample Resistor is 0.002R, 2mR (diameter 2.5mm, rate current is 20A. space is 10mm, height 7.5mm, "door" shape).


## Calculatoin 

![](2023-10-24-12-28-02.png)



    F_cf  = (V1xV2x48)/(V_ref)^2 x (F_osc/128)
    F_cf1 = (V1x24)/(V_ref)      x (F_osc/512)
    F_cfu = (V2x2)/V_ref         x (F_osc/512)

Note 

* Fcf = Power, Fcf1 = current, Fcfu = voltage
* V1: Voltage signal on the current channel pin
* V2: Voltage signal on voltage channel pin
* Fosc: built-in crystal, the typical frequency of about 3.579MHz;
* Vref: built-in reference source, the typical voltage is 2.43V

## Use with ESP8266

* The demo code will monitoring the power, current, voltage and frequency, you can monitor it via telnet to see remote debug output, same as serial output, but safe when AC main power connected. 
* Pin definition to esp8266 please see the comments in sketch
* Also can calibrate the parameters, see the comments in sketch
* Enter SSID and password in the sketch, run the demo code first to see IP address
* Connect to AC main power, login remotely via telnet, in windows for example, command: telnet 192.168.0.100

* [Demo code here](https://github.com/Edragon/esp8266_arduino/tree/master/HLW8012/remote_debug)


## Demo 

https://www.youtube.com/watch?v=0aiuwRB8Uic


## DS

- [[HLW8012-HLW-REV1.3.pdf]]



## ref 

- [[HLW8012-dat]] - [[HLW8032-dat]] - [[HLW-dat]] - [[ac-mains-dat]] - [[power-meter-dat]]

Boards - [[OPM1126-dat]]

- [[OPM1126]]