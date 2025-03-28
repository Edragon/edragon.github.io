
# OV7725-dat


## board 

- [[SCM1017-dat]]


## Pin Definitison 

As shown in the figure, the pins required to control the sensor are defined as follows:
- VCC -- -input power supply voltage (3.3V is recommended, 5V is also acceptable, but not recommended)
- GDN --  ground point
- SIO_C -- -control clock of SCCB interface (Note: some low-level microcontrollers require pull-up control, similar to I2C interface)
- SIO_D -- Serial data input (output) end of SIO_DSCCB interface (Note: some low-level microcontrollers require pull-up control, similar to I2C interface)
- VSYNC -- -frame synchronization signal (output signal), which can be used as a synchronization signal for a pair of images
- HREF --  line synchronization signal (output signal), which can be used as a line synchronization signal
- PCLK --  pixel clock (output signal), image chip output signal, used as the output clock of the image signal
- XCLCK -- -clock signal (input signal), input clock signal, which can be provided by an external crystal oscillator or an external processor
- D0-D10 -- -data port (output signal), usually 8-bit data is used (most chip buses are multiples of 8), D0 and D1 can be unused.
- RESTE --  - reset port (pull high for normal use)
- PWDN --  power consumption selection mode (pull low for normal use)


## specs 

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