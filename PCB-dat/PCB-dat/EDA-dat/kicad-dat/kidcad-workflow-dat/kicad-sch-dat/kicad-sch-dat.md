
# kicad-sch-dat



- [[kicad-symbol-dat]]


## shortcut 

- D == datasheet 
- G == drag 
- M == move
- R == rotate
- ctrl+D == duplicate 



## bulk net labeling 

I did find the "insert" key, repeat last action but it's still too time consuming, e.g., labeling PCIe diff pairs on a connector looks like this:

- add PCIE_RX0_P label
- use insert key to step/repeat/auto increment, say 7 times
- now move each label one-by-one to their respective nets.  One-by-one because the auto incremented puts the next label right below the previous but diff pair nets on a connector need the _N below the _P and there's a GND in between, so it becomes a one-by-one shuttling operation.
- now repeat steps 1-3 above 3 more times for the _N nets, and for the TX versions of same.

## add new hierarchy sheet

- click tool icon - draw hierarchy sheets 





### add symbol 

- search based on components type and footprint

![](2024-10-06-16-39-37.png)

- ctrl+D duplicate the symbol

- [[kicad-symbol-dat]]

### mutiple assign the value

![](2024-10-09-17-15-09.png)



### sort network classes network 

- schematic setup -> net classes




### assign the footprints

![](2024-09-18-01-41-13.png)

- add symbols and assign footprint 
  - enter "E" for properties, and assign the footprint 



## ref 

- [[kicad-dat]]

