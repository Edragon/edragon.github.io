
# kicad-pcb-dat

## import from other template projects 

pre-defined file: D:\Program Files\KiCad\8.0\share\kicad\template\Arduino_Nano

- DRC rules = design rules constrains 
- teardrop defaults 



![](2024-10-08-19-42-52.png)



### update into PCB



- switch to PCB
- update from PCB
- fix errors 
- update PCB
- layout it

![](2024-09-18-01-43-12.png)

![](2024-09-18-01-43-55.png)




## PCB layout 

- autoroute - by [[kicad-plugin-dat]]



## PCB Info 

commom layers 

| layers         | explain            | CN     |
| -------------- | ------------------ | ------ |
| edge.cuts      | board edge layer   | 边框层 |
| F/B Silkscreen | Silkscreen layer   | 丝印层 |
| F/B Mask       | Mask layer         | 阻焊层 |
| F/B Paste      | solder Paste layer | 锡膏层 |
| F/B Cu         | copper layer       | 铜箔层 |

* F for front and B for back 

## PCB init setup 

![](2023-12-11-00-04-17.png)

- 网络线宽
- 钻孔尺寸
- 网格 1.0 mm 
- 缩放 

## Layout setup 

Simply Only use Trace x.CU, Silkscreen layer x.Silkscreen, and Edge.Cuts 

![](2025-04-29-16-22-13.png)


## routing PCB

![](2025-04-29-16-11-14.png)

![](2025-04-29-16-11-39.png)


## Modify PCB 


## Filled Zones (ground pour)

Edit - Fill All Zones (B or Ctrl+B)


### Optimized the Text 

Optimize the text size of the desginators

![](2025-05-12-13-02-00.png)


## export gerber 

output folder 

    for the current folder == ./
    for the sub folder "gerber" in current folder == ./gerber