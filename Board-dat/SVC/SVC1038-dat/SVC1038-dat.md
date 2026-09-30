
# SVC1038-dat

This is an upgradion board from the old board [[SVC1035-dat]] 

## tech 


- [[CT226-dat]] == 1000:1 // 2000:1 [[current-dat]] - [[current-transformer-dat]]

- [[ZMCT103-dat]] == 1000:1 [[current-dat]] - [[current-transformer-dat]]
  
- [[ZMPT107-dat]] == 1000:1000 [[voltage-dat]] - [[ac-voltage-transformer-dat]] 



## boards 

- [[SVC1038-dat]] - [[SVC1042-dat]] - [[SVC1035-dat]]

- [[SVC1038-dat]] == 10A
- [[SVC1042-dat]] == 30A


## Info

[product url - VAC Energy Meter Power Sensor Board, HLW8032 Isolated V2 [Amp]](https://www.electrodragon.com/product/vac-energy-meter-power-sensor-board-hlw8032-isolated-version/)

### Board Map, Dimension, Pins, chip info, Use Guide, Setup Jumper, etc.

Board map 

![](2025-06-07-17-30-01.png)

- note the [[current-transformer-dat]] (section BX-CT) sensor has two types footprint, bigger and smaller, to compatible with more types of sensors




New Wiring (default, use your own load's wire)

- connnect [[AC-mains-dat]] input from the bottom blue and red wire 
- connect the load to the top blue and red wire

![](2025-06-12-16-02-42.png)

Old Wiring (on-board sensor wire)

- The orange wires are the old wiring method, only use when the [[current-transformer-dat]] has wire inside

![](2025-06-12-16-02-19.png)

![](2025-06-07-17-35-24.png)





## Applications, category, tags, etc. 

## Demo Code and Video

- [[HLW8032-dat]]






## ref 

- [[SVC1038-dat]] - [[SVC1042-dat]]

- [[SVC1038]] 

- legacy wiki page 
