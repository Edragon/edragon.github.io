
# OV7725-dat

* Up to 60fps on VGA mode
* Can be through the SCCB interface, in fact, is similar to the I2C interface, the white balance, gama, color correction, exposure control, color control.
* sclk and sdat need 4.7K pull-up

## Chip 

The OV7725 sensor uses BGA packaging. Its front end is a lighting window and the pins are all led out on the back. The pin distribution is shown in Figure 47_2.

![](2024-12-28-16-54-41.png)


## silk print 

- HDF7725-BS
- HDF7725-A90
- ...

## SCH 

![](2024-12-28-16-53-22.png)

sch 2 

![](2024-12-28-16-55-21.png)

connect to a [[FIFO-dat]]

![](2024-12-28-16-55-57.png)

Wiring to a [[STM32-dat]] H7 

![](2024-12-28-16-57-56.png)



## ref 

- [[FIFO-dat]] - [[AL422B]]

- https://drive.google.com/file/d/1NdFRoW3jKUBIXRLPa3K5KMaaimx0SyS6/view