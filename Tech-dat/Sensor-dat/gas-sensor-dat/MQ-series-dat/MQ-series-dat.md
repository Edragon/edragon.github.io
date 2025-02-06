
# MQ-series-dat


* You can use arduino default "analogread" example to read the analog value from the sensor


* [Wiring Example](http://wiring.org.co/learning/basics/airqualitymq135.html)
* [Arduino Breathalyzer](http://www.danielandrade.net/2010/03/07/building-an-breathalyzer-with-mq-3-and-arduino/)
* [Another Breathalyzer Design](http://nootropicdesign.com/projectlab/2010/09/17/arduino-breathalyzer/)



- [[MQ-2-dat]] - [[STH1042-dat]]

- [[MQ-3-dat]] - [[STH1043-dat]]

- [[MQ-5-dat]] - [[STH1044-dat]]

## Gas type and models 

# Selection Guide

| Model | Detect Type                                                                                                                                                |
|-------|------------------------------------------------------------------------------------------------------------------------------------------------------------|
| MQ-2  | LPG, i-butane, propane, methane, alcohol, Hydrogen, smoke                                                                                                  |
| MQ-3  | Alcohol                                                                                                                                                    |
| MQ-5  | High sensitivity to LPG, natural gas, town gas  <br>   Small sensitivity to alcohol, smoke. <br> **Combustible gases**: Butane, propane, methane, hydrogen |




## Note of use 

Initiation check<br />

* The sensor first warm-up for about 20 seconds.
* Put the sensor on a place without detecting gas, 
* clockwise adjustment potentiometer until the light is on, 
* then one-half turn counterclockwise until indicator does not light
* then close to the measured gas light is on, leave the measured gas, the light is off, this proof the sensor is working well



## ref 

### obseleted 

* [Arduino Tutorial in Portuguese](http://lusorobotica.com/index.php/topic,111.0.html)