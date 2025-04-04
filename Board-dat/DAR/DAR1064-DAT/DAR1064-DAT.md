

# DAR1064 

[AVR128DB64 Mini Develpment Board AVR128](https://www.electrodragon.com/product/avr128db64-mini-develpment-board-avr128/)

- [[avr128-dat]]

[legacy wiki page. ](https://w.electrodragon.com/w/Category:AVR128#AVR128_Board)

## hardware 

![](30-27-16-19-04-2023.png)

![](14-28-16-19-04-2023.png)


| On board resources | Pin | arduino setup |
| ------------------ | --- | ------------- |
| prog led           | PC6 | D22           |
| prog button        | PC7 | D23           |
| Reset              | PF6 | reset         |


### Jumper Setup 

| Options                 | Selections                             | Default           |
| ----------------------- | -------------------------------------- | ----------------- |
| Power Supply            | 5V or 3V3                              | 5V                |
| Power Supply of Vdd_io2 | to Vdd                                 | to Vdd            |
| USART of Programming    | PB0 PB1 (USART 3) or PE0 PE1 (USART 4) | PB0 PB1 (USART 3) |



## Usage 

- Install Driver for [[CH340-DAT]], check CH340K
- Power LED indicator should be light up



## bootloader settings 

- Clock -24 mhz internal 
- Bootloader serial port: PB0 / PB1
- Reset pin: default 

![](55-05-18-02-02-2023.png)

## Crystal Setup 

- please notice all crystal are not populated, normally use the internal clock is enough
- PF0 / PF1 low speed RTC clock, PTH footprint 
- PA0 / PA1 high speed clock , SMD footprint 
- [[crystal-dat]]


## Debug 

- Please check if backside jumpers are all soldered or not, power LED is NO or not.
- The full schematic is for purchased customers only, you can also view it directly here. 
- Default firmware should be hold down PC7 button and PC6 LED light up, or simple blink sketch. You can find all sketches in our [[arduino-IDE-DAT]]
- [More information please find at page here.](https://w2.electrodragon.com/Board/DAR/DAR1064-DAT/DAR1064-DAT.md)


## demo video 

- [A quick start guide video please see here. Easy to use with Atmel-ICE or other UPDI programming methods.](https://www.youtube.com/watch?v=IgVMIRHFTLs)


## ref 
- https://w.electrodragon.com/w/Category:AVR128#AVR128_Board

- [[UPDI-DAT]] - [[CH340-DAT]] - [[CH341-DAT]] - [[avr128-dat]]

- [[DAR1064]] 


