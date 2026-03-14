
# eagle-CAD-dat


- [[bitmap-dat]] - [[dxf-dat]]

- [[PCB-design-dat]] 

- https://github.com/Edragon/Eagle-CAD-dat
- ~~https://github.com/Edragon/CAD-Eagle-part~~

- [[PCB-footprint-dat]] - [[EDA-dat]]

- [[eaglecad-dat]] - [[EDA-dat]] - [[EDA-footprint-dat]]



## DRC 

### distance 

信号层内的对象（焊盘、SM 以及任何连接到它们的铜箔)与印制板外框之间、钻孔之间的最小距离;

设置 Copper/Dinension 为 0；以禁止该项检查。


### sizes 

- Minimun Width - 8mil
- Minimum Drill - 12mil
- Min. Micro Via - 9. 99mm
- Min. Blind Via Ratio - 0.5

Minimun Sizes of objects in signal layers and of drill holes.




### supply thermal isolation 

12 mil 

![](2026-01-06-17-34-51.png)

thermal for vias 

![](2026-01-06-17-33-57.png)

thermal only for holes 

![](2026-01-06-17-34-18.png)


## BOM 

- schematic - export - BOM - by values / csv



## artwork 

1. invert the color, only left black to use, white to left out, saved as BMP, tools is opensource photodemon  

![](2026-03-12-02-11-13.png)

saved file size is 430 x 150 px 

![](2026-03-12-02-13-20.png)


2. import in eagleCAD brd, 

![](2026-03-12-02-12-19.png)

PCB size rougly 90 x 60 mm  

import only color black to use 

![](2026-03-12-02-14-57.png)

scale 1 will be too big for this PCB size, size scale 0.1 looks good 

![](2026-03-12-02-18-02.png)

finally copy paste to layer 21 tplace 



## Tips 

### oval, or oblong shapes

Unfortunately there is still no option for creating a plated slot in the library editor with the ease you can an SMD or PAD. However, you can do as @millingm suggested or the variation I prefer which is a PAD on each end of the slot and then draw each of the inner/outer layer pad areas with a polygon on each of the 16 routing layers. The also draw the slot as a line on the Milling layer. You end up with something like this in your library:

![](2024-04-02-14-24-27.png)

And when it is in the board you end up with:

![](2024-04-02-14-24-54.png)

https://forums.autodesk.com/t5/eagle-forum/slotted-pads/td-p/7487203






## ref 

- [[eagle-cad]]

- [[MPC1073-dat]]

https://forums.autodesk.com/t5/eagle-forum


- [[PCB-design-dat]]