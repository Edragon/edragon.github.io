
# VGA-dat

## VGA for raspberry pi 

From the birth of the Raspberry-Pi there have been complaints about the lack of a VGA output. That has now been remedied. But only for the B+ and at the cost of losing most of your GPIOs. 

The BCM2835 has a parallel display interface on the GPIO pins. I did not publish this in the 2835 datasheet as 50% of the DPI pins where not on the GPIO connector, making it impossible to get any decent video out. 

The B+ however has all of the necessary DPI signals brought out. Dom has been working on the software side and the new DPI (read: VGA) driver software has been added to the latest release. 

### Resolution & Quality 

The VGA output supports the same resolutions as your HDMI one. Thus from 640x480 up to 1920x1024 60fps. At the highest resolution the pixel quality is almost as good as HDMI. 

If you look very closely there is a slight pixel crawl. The adapter uses a simple resistor ladder network as digital-to-analogue converter. Therefore the colour quality depends on how well balanced your resistors are. 

The video shown uses an adapter with 1% SMD resistors. There is a slight colour banding and with 6 bits per channel you have a maximum of 262144 colours.  


### Double screen 
In contrast to the composite video, the DPI interface can be run independent of the HDMI. Thus next to the HDMI screen, the VGA can be used as ‘second monitor’. The software for that is still under development but I expect that to arrive in the next two week. 

Beware that running two screens at maximum resolution will really eat into your SDRAM bandwidth. In fact it has not tried yet, so it might not be possible. 