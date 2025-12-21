
# TSL2561-dat.md

- [[sensor-ambient-light-dat]]

Description:TheTSL2561LuminositySensorBreakout.isasophisticated lightsensorwhichhasa flatresponse acrossmostof thevisible spectrum.Unlikesimplersensors,theTSL2561measuresbothinfrared andvisible light to better approximate the response of thehuman eye.

And because the TSL2561 is an integrating sensor(it soaks up light forapredeterminedamountof time),it is capable of.measuring bothsmall andlarge amountsof lightbychanging the integration time. 

The TSL2561 is capable of direct I2C communication and is able to conduct specific light ranges from0.1-40k+Lux easily.Additionally,theTSL12561containstwointegrating analog-to-digitalconverters(ADC)thatintegratecurrents fromtwophotodiodes,simultaneously.Each breakout requiresa supply voltage of 3V and a low supply currentmax of 0.6mA.





## Info 
 
chip info, datasheet, etc.

datahseet - [[TSL2561.pdf]]

features 


TSL2561是光数字转换器，它将光强转换成数字信号输出，具有直接12C接或者SMBus接口。每个设备都连接一个带宽的光敏二极管和在单独CMOS集成电路上的一个红外响应的光敏二极管，这个集成电路具有提供20bit动态范围的近适光响应的能力。

两个集成的ADCs将光敏电流转换成一个数字输出，这个数字输出表示测量每一个通道的发光。这个数字输出可以S一个微处理器的输入。


2.数字输出符合标准的SMBuS（TSL2560）和I2C（TSL2561）总线协议；
3.模拟增益和数字输出时间可编程控制；
4.低功耗模式下，功耗仅为0.75mW
5.自动抑制50Hz/60Hz的光照波动。



## App. 

- [[SSL1053-dat]]


## ref 

- [[sensor-ambient-light-dat]] - [[sensor-dat]]
 
- [[TSL2561]] 
 


