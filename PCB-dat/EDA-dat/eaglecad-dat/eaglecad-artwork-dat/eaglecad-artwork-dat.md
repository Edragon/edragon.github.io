

# eaglecad-artwork-dat

- [[eaglecad-artwork-dat]] - [[eaglecad-dat]]



## artwork 

default settings scaled // mil // scale == 1.0


some more notes: 

- if print on the back side of the PCB, image must be mirrored, otherwise the image will be reversed after printing.

size definitions 

- define the pixels, for example your raw bitmap image size is 620 x 480 px 
- define the import scale, for exmample 1.0 

![](2026-04-02-16-59-10.png)



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

## ref 

