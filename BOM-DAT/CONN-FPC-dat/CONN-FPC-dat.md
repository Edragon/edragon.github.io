
# CONN-FPC-dat 


- [[CONN-FPC-dat]] - [[FPC-dat]]




FFC usually means “Flat Flex Cable”

- add [[test-point-dat]] for debugging 


## Info 

- common pitch 0.5 mm

overview 

![](2025-08-19-15-24-47.png)

- common pitch 1.0 mm

## type 

FPC down flip 

![](53-53-16-17-07-2023.png)



FPC upper flip 

![](41-53-16-17-07-2023.png)

![](32-14-18-03-08-2023.png)




## footprint 

THD0510－xxCL－GF == datasheet [[THD0510-xxCL-GF.pdf]]


- FPC-SMD_9P-P0.50_THD0510-09CL-GF
- FPC-SMD_5P-P0.50_THD0510-05CL-GF == 间距:0.5mm P数:5P 翻盖式 下接

![](2025-07-14-01-04-01.png)

![](2025-07-14-01-04-59.png)



## dimension 

![](05-55-16-17-07-2023.png)


## soldering 

Use low-temperature solder [[solder-paste-dat]] to tin the pads first, then clean the pads with board cleaning solution, brush on BGA soldering flux, and finally use a hot plate. The result is almost as good as factory production.


## manu code 

- AFC01-S06FCA-00 == 下接
- AFC01-S18FCA-00 == 下接
- THD0510-05CL-GF == 上接
- THD0510-09CL-GF == 上接

- 34P 上接 



## stiffener

For ordering at JLCPCB, define a seperate layer for your stiffeners, like I did here:

![](2025-08-28-15-39-53.png)

This design actually has an FR4 and a polyimide stiffener, so two layers.

## ref 

- [[soldering-dat]]

- [[FPC-fab-dat]]

- [[FPC]] - [[FPC-socket]] - [[FPC-pin]]