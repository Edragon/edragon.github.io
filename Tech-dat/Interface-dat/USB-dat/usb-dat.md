
# usb-dat 

- [[USB-cable-dat]] - [[USB-ESD-dat]] 

- [[CONN-USB-dat]]

- libusb-win32
- https://zadig.akeo.ie/

## USB variations 

- [[USB2.0-dat]] - [[type-c-dat]]

## Devices 

- [[ARM1003-dat]] - [[MOT1022-dat]]

![](2024-05-07-16-19-57.png)


## Schematic

### USB with STM32 

![](2024-01-13-17-48-33.png)



## USB w/ [[CH579-dat]]

![](2024-05-06-17-38-37.png)


## Terms 

### USB standard 

- USB 2.0 is a widely used standard for connecting devices to computers and other peripherals. It supports data transfer rates of up to 480 Mbps and is backward compatible with USB 1.1.
- USB 3.0 is a newer standard that offers significantly faster data transfer rates of up to 5 Gbps and improved power management features. It is backward compatible with USB 2.0.
- USB 3.1 is an even newer standard that provides data transfer rates of up to 10 Gbps and introduces new features like USB Type-C connectors, which are reversible and support higher power delivery.
- USB 3.2 is the latest standard that can achieve data transfer rates of up to 20 Gbps by using multiple lanes for data transmission. It also supports USB Type-C connectors and improved power delivery capabilities.
- USB 4.0 is the latest standard that combines the features of USB 3.2 and Thunderbolt 3, offering data transfer rates of up to 40 Gbps and improved compatibility with Thunderbolt devices.

### USB others 

- USB-C is a new connector type that is reversible and can support various protocols, including USB 3.1, Thunderbolt 3, and DisplayPort. It is becoming the standard connector for many devices, including smartphones, laptops, and peripherals.
- USB Power Delivery (PD) is a specification that allows devices to negotiate power requirements and deliver higher power levels over USB connections. It enables faster charging and power delivery to devices like laptops and smartphones.
- USB Audio is a specification that allows audio devices to connect to computers and other peripherals using USB connections. It supports high-quality audio streaming and can replace traditional audio connectors like 3.5mm jacks.
- USB HID (Human Interface Device) is a class of USB devices that includes keyboards, mice, and game controllers. It allows these devices to communicate with computers without the need for custom drivers.
- USB Mass Storage is a class of USB devices that allows storage devices like flash drives and external hard drives to connect to computers and other peripherals. It enables easy file transfer and access to storage media.
- USB Serial is a class of USB devices that allows serial communication over USB connections. It is commonly used for connecting microcontrollers and other embedded systems to computers for debugging and data transfer.
- USB CDC (Communications Device Class) is a class of USB devices that allows devices to emulate serial ports over USB connections. It is commonly used for connecting modems, network adapters, and other communication devices to computers.
- USB MTP (Media Transfer Protocol) is a protocol that allows devices to transfer media files like photos and videos over USB connections. It is commonly used for connecting smartphones and cameras to computers for file transfer.
- USB PTP (Picture Transfer Protocol) is a protocol that allows devices to transfer images and videos over USB connections. It is commonly used for connecting digital cameras to computers for file transfer.

### USB OTG 

- USB OTG (On-The-Go) is a specification that allows USB devices to act as hosts, enabling them to connect directly to other USB devices without the need for a PC. This is particularly useful for mobile devices and embedded systems.
- USB OTG ID is a pin used in USB OTG connections to determine the role of the device (host or peripheral). It helps devices negotiate their roles in the connection.
- USB OTG cable is a special cable that allows devices to connect in USB OTG mode. It typically has a micro USB connector on one end and a standard USB connector on the other end.
- USB OTG adapter is a device that allows devices to connect in USB OTG mode. It typically has a micro USB connector on one end and a standard USB connector on the other end.
- USB OTG host mode is a mode in which a device acts as a host in a USB OTG connection. This allows it to connect to other USB devices and control them.
- USB OTG peripheral mode is a mode in which a device acts as a peripheral in a USB OTG connection. This allows it to connect to a host device and be controlled by it.
- USB OTG power is the power supplied to a device in a USB OTG connection. It can be negotiated between the host and peripheral devices to ensure proper operation.
- USB OTG power supply is the power source used to power devices in a USB OTG connection. It can be provided by the host device or an external power source.
- USB OTG power management is the process of managing power consumption in USB OTG connections. It involves negotiating power requirements and optimizing power usage to extend battery life.
- USB OTG power delivery is a feature that allows devices to negotiate power requirements and deliver higher power levels over USB connections. It enables faster charging and power delivery to devices like laptops and smartphones.
- USB OTG power bank is a portable power source that can be used to power devices in a USB OTG connection. It typically has a USB connector for charging and can provide power to multiple devices simultaneously.
- USB OTG power switch is a device that allows users to control the power supply to devices in a USB OTG connection. It can be used to turn devices on or off and manage power consumption.
- USB OTG power cable is a special cable that allows devices to connect in USB OTG mode and provides power to the connected devices. It typically has a micro USB connector on one end and a standard USB connector on the other end.
  

## Converter 

MicroA_2_A_Female


## STM32 USB 

### DFU USB OTG 
* Listed supported device in ST documents [https://www.st.com/content/ccc/resource/technical/document/application_note/6a/17/92/02/58/98/45/0c/CD00264379.pdf/files/CD00264379.pdf/jcr:content/translations/en.CD00264379.pdf AN3156] 
[[File:DFU.gif]]
* Download [http://www.st.com/en/development-tools/stsw-stm32080.html DfuSe USB device firmware upgrade (DFU) software]
* Install the drive in installation folder -C:\Program Files (x86)\STMicroelectronics\Software\DfuSe v3.0.5\Bin\Driver or here [[STM-Bootloader-Driver.zip]] STM32 Bootloader Driver
* Testing firmware for [[File:Can-usb.zip]] USB-CAN here.
* Open the DFU tool to upload firmware to internal flash, see left animation.


### USB DFU
* Short connect Boot0 + 3V3 to re-enter into USB DFU mode
* use STM32CubeProgrammer upload hex or DFU file.
In other boot try:
* In case of SLCAN software connect UCCB and type in terminal '''boot''' device should reset and new device should connect to Your pc

## USB mode 

- USB CDC / Serial
- USB JTAG 



## ref 

- [[USB-A-dat]]
  
- [[USB]]