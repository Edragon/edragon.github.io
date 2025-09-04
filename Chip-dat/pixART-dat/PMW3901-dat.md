
# PMW3901-dat.md


General Description  

The PMW3901MB-TXQT is PixArt Imaging's latest optical navigation chip designed with far field optics technology that enables navigation in the air. It is housed in a 28-pin chip-on-board (COB) package that provides X-Y motion information with a wide working range of 80 mm to infinity. It is most suitable for far field applications for motion detection.

Key Features  
- Wide working range from 80 mm to infinity  
- No lens focusing required during lens mounting process  
- Power consumption of <9mA @ run mode  
- 16-bit motion data registers  
- Motion detect pin output  
- Internal oscillator – no clock input needed  

Applications  

Devices that require far field motion detection, e.g.  
- Drone  
- Indoor and outdoor X-Y positioning, especially in GPS-


https://download.kamami.pl/p587092-pmw3901mb-txqt_-_productbrief_2451186_7.pdf



The PMW3901 is a crafty little sensor that uses a low-resolution camera and some clever algorithms to detect motion of surfaces. A great use for it is detecting and correcting for drift of a drone by looking for x/y motion of the ground below. 



## raspberry pi 


Our library is set up to use SPI 0 on the Pi: BCM 8 for CS, BCM 11 for SCK, BCM 10 for MOSI, BCM 9 for MISO, and BCM 18 for the INT pin. 



Here's which pins to connect between your Optical Flow Sensor Breakout and your Pi's GPIO (note that it's BCM pin numbering): 

- 3-5V to any 5V or 3V pin
- CS to BCM 8
- SCK to BCM 11
- MOSI to BCM 10
- MISO to BCM 9
- INT to BCM 18
- GND to any ground pin


## library code 

- python == https://github.com/pimoroni/pmw3901-python


## ref 

- [[pixart-dat]]