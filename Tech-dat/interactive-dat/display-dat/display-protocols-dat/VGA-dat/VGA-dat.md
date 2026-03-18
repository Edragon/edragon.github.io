
# VGA-dat


## board 

- [[MPC1105-dat]]

## tech 

- [[VGA-dat]] - [[DPI-dat]]

- [[DB9-dat]] - [[DB15-dat]] - [[DB25-dat]] - [[CONN-dat]] - [[DB-series-dat]]

- [[VGA-dat]] - [[DVI-dat]] - [[RS343-dat]]


VGA接口是显卡上应用最为广泛的接口类型，绝大多数的显卡都带有此种接口。VGA接口是一种D型接口，上面共有15针孔，分成三排，每排五个。

其中，除了2根NC（NotConnect）信号、3根显示数据总线和5个GND信号，比较重要的是3根RGB彩色分量信号和2根扫描同步信号HSYNC和VSYNC针。

VGA接口中彩色分量采用RS343电平标准。RS343电平标准的峰峰值电压为1V。

VGA接口是显卡上应用最为广泛的接口类型，多数的显卡都带有此种接口。

有些不带VGA接口而带有DVi（DigitalVisualInterface数字视频接口）接口的显卡，也可以通过一个简单的转接头将DVI接口转成VGA接口，通常没有VGA接口的显卡会附赠这样的转接头。



A standard 15-pin VGA (DE-15) connector uses an analog interface with 

- three main color channels (Red, Green, Blue), 
- two sync signals (Horizontal and Vertical), 
- and several grounds to send video to a monitor. 

Key pins include: Pin 1-3 (RGB), 13 (HSYNC), 14 (VSYNC), and Ground pins 5, 6, 7, 8, 10.


## signals 

- PL_HSYNC
- PL_VSYNC


- RED2
- RED3
- RFD4
- RED5
- RED6
- RED7

- GREEN2
- GRFEN3
- GREEN4
- GREEN5
- GRFEN6
- GRFEN7

- BLUE2
- BLUE3
- BLUE4
- BLUE5
- BLUE6
- BLUE7

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


## Connector 

- VGA female 15 = 3x5 pins 


## ref 

- [[CONN-vga-dat]]