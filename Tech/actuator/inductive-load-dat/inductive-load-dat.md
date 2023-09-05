
# inductive load dat


## AC Inductive Load 

- RC Snubber Board - https://www.electrodragon.com/product/2pcs-ac-kickback-absorb-board-inductive-load/



## Cause analysis 

### ground bounce

Almost always, RS232 disconnects are from something called ground bounce, which means that some inductive device like a motor or a solenoid puts a lot of power onto the ground. When that happens, the signaling, which is relative to ground, can end up being high or low.

 
### float ground by seperated power supply 

The problem is worse when the systems all share a ground. If you powered the new board with a battery, not a power supply, this can help to float the ground. Or, if the PC is a laptop, disconnect from the wall and run it on battery.  Try that first if you haven’t. if you haven’t tried, change the cycle time, where maybe the motor is on 5 seconds and then off 5 second. That makes it easier to see when the error happens- at the start or the stop of the motor. If the start, it is going to be a voltage drop on the RS232 chip, and a local capacitor of 5uf or so can make a huge difference. If this happens with the motor turning off, this is almost certainly inductive spike causing a ground bounce. 

### extra capacitances 
I usually put some extra capacitance on CPU, comms chips, and any logic chips and make sure there is a good ground between them- either a ground plane, or at least a 20mil trace. Same with power. The caps will handle all short term power changes- 

### power trace
but you need the larger power traces to get that power to or from the chip before the cap is no longer able to keep voltage in limits.

 
### oscilloscope check 

Do you have a DSO oscilloscope? You will never see this with a power supply meter- you need to check for voltage spikes that are much shorter than 0.1 second. Often, they are more like 0.00001s. If you don’t have that test equipment, I do, and maybe you can send the proto board over with just the bare minimum parts- RS232 chip, motor drive chip, controller. I have motors and all that stuff.


## Solution Tried 

- add 100uf capacitors to 5V/GND and 3V3/GND
- use a seperated 12V/2A battery, USB-RS232 board does not keeping reboot, can still can not be opened COM port to use 
- mosfet control is already optocoupler isolated as the design, and used seperated power supply 
- [[DPR1084-dat]] RS232 board only connects with RXD, TXD, GND, no power supply 




