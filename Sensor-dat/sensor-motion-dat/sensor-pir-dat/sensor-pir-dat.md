
# sensor-PIR-dat

- [legacy wiki page](https://w.electrodragon.com/w/PIR_sensor)

## Boards 

- mini type [[SMO1088-dat]] - panel integrated [[SMOS026-dat]] - classic type [[SMO1060-dat]]


## chip 

- [[D203S-dat]]

- [[senba-sensing-dat]] - [[sensor-PIR-dat]] - [[sensor-motion-dat]]

## Working priciple 

![](2023-12-12-17-56-14.png)




## APP SCH 

![](2026-07-22-20-46-35.png)


## Arduino Demo Code 

- http://playground.arduino.cc/Code/PIRsense

Connecting PIR sensors to a microcontroller is really simple. The PIR acts as a digital output so all you need to do is listen for the pin to flip high (detected) or low (not detected).

Its likely that you'll want reriggering, so be sure to put the jumper in the H position!

Power the PIR with 5V and connect ground to ground. Then connect the output to a digital pin. In this example we'll use pin 2.
See the following picture about how it connects:

![](2023-12-12-17-58-19.png)

Without a microcontroller, PIR sensor can also be a simple TTL signal control relay, to use on many application such as road light!

Use following code to read the PIR value:

    /*
    * PIR sensor tester
    */
    
    int ledPin = 13;                // choose the pin for the LED
    int inputPin = 2;               // choose the input pin (for PIR sensor)
    int pirState = LOW;             // we start, assuming no motion detected
    int val = 0;                    // variable for reading the pin status
    
    void setup() {
    pinMode(ledPin, OUTPUT);      // declare LED as output
    pinMode(inputPin, INPUT);     // declare sensor as input
    
    Serial.begin(9600);
    }
    
    void loop(){
    val = digitalRead(inputPin);  // read input value
    if (val == HIGH) {            // check if the input is HIGH
        digitalWrite(ledPin, HIGH);  // turn LED ON
        if (pirState == LOW) {
        // we have just turned on
        Serial.println("Motion detected!");
        // We only want to print on the output change, not state
        pirState = HIGH;
        }
    } else {
        digitalWrite(ledPin, LOW); // turn LED OFF
        if (pirState == HIGH){
        // we have just turned of
        Serial.println("Motion ended!");
        // We only want to print on the output change, not state
        pirState = LOW;
        }
    }
    }


## Note of the sensing 
* Sensor module is powered up after a minute, in this initialization time intervals during this module will output 0-3 times, a minute later enters the standby state.
  
* Should try to avoid the lights and other sources of interference close direct module surface of the lens, in order to avoid the introduction of interference signal malfunction; environment should avoid the wind flow, the wind will cause interference on the sensor.
  
* Sensor module with dual probe, the probe window is rectangular, dual (A B) in both ends of the longitudinal direction so when the human body from '''left to right or right to left''' through the infrared spectrum to reach dual time, distance difference, the greater the difference, the more sensitive the sensor,
when the human body from the front to the probe or from top to bottom or from bottom to top on the direction traveled, double detects changes in the distance of less than infrared spectroscopy, no difference value the sensor insensitive or does not work;

* '''The dual direction of sensor should be installed parallel as far as possible in inline with human movement.''' In order to increase the sensor angle range, the module using a circular lens also makes the probe surrounded induction, but the left and right sides still up and down in both directions sensing range, sensitivity, still need to try to install the above requirements.

## BOM 

- [[BISS0001]]


## demo video 

- works with [[ESP32-dat]] - https://x.com/electro_phoenix/status/1877256534687650008


read PIR IO 14 - [[senba-sensing-dat]] - [[sensor-pir-IO14-1.ino]]

![](2026-07-22-20-54-39.png)




## SCH 

![](2026-07-23-17-04-54.png)



## build 


build 1 == Esp32 3.3V 供电，用模拟管脚输入，触发高电平 4095，30 秒没检测到物体跳会低电平 0（1），如果一直对着人物持续输出高电平。 

![](2026-09-08-16-00-24.png)

PIR N219S 

- Series:Pyroelectric Infrared Sensor
- Features:Change with temperature, Digital signal processing
- Mounting Type:Digital signal output
- Description:Dual sensitive element design
- Model Number:BL-RD-N219S
- Place of Origin:Guangdong, China
- Brand Name:GBeelee
- Usage:Especially suitable for intelligent
- Theory:Infrared detection
- Output:Analog signal
- Brand:Pyroelectric Infrared Sensor
- Voltage - Supply:3~15V
- Output Type:≥ 3500mV
- Operating Temperature:-30~70℃
- Current - Supply (Max):<12uA
- Output Configuration:Output Balance<10%
- Voltage Rating:0.4~0.75V
- Size / Dimension:Window Size: 3*4mm
- Resolution:≥ 75%
- Sensing Range:120° (horizontal direction)
- Current - Output (Max):Supply Voltage:3~15V
- Sensitivity (LSB/g):≥ 3300V/W
- Sensing Distance:10M (lens SB-F-02)
- Voltage - Max:3.7V
- Sensing Light:5~14um
- Voltage - Input:3~15V
- Application:smart toys,automatic light switch,Sensor door
- Window Size:3*4mm
- IR Receiving Electrode:2*1mm,2elements
- Package Type:TO-5
- Spectral Response:5-14μ m
- Transmittance:≥ 75%
- Signal Output[Vp-p]:≥ 3500mV
- Sensitivity:≥ 3300V/W
- Noise[Vp-p]:≤70mV
- Output Balance:<10%
- Offset Voltage:0.4~0.75V


## ref 

- [[PIR-sensor]]