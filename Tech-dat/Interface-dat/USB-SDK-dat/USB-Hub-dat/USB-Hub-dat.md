
# USB-Hub-dat

- [[microchip-dat]]

- [[diodes-dat]] - [[power-protection-dat]]

- [[onsemi-dat]] - [[FSUSB42-dat]]



## FE1.1 

![](2023-11-30-15-28-49.png)



## GL850

- [[GL850-dat]]


## CH334 

项目采用CH334F将一路usb信号拓展至四路，其中ESP32S3、RP2040和CH549G各连接一路，另外的一路由一个usbA口引出，可以外接usb设备同时为开发板或者手机供电。


![](2025-08-19-16-49-07.png)


## SDK


### RPI CM4 USB-HUB detect log 

- [[dmesg-dat]] - [[linux-dat]]

    [  255.036607] usb usb1-port1: connect-debounce failed
    [  255.704572] usb 1-1: new high-speed USB device number 2 using xhci-hcd
    [  255.854484] usb 1-1: New USB device found, idVendor=ffff, idProduct=5678, bcdDevice= 2.00
    [  255.854515] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
    [  255.854531] usb 1-1: Product: Disk 2.0
    [  255.854545] usb 1-1: Manufacturer: USB
    [  255.854559] usb 1-1: SerialNumber: 4935471142263206857
    [  255.871936] usb-storage 1-1:1.0: USB Mass Storage device detected
    [  255.873428] scsi host0: usb-storage 1-1:1.0
    [  256.901207] scsi 0:0:0:0: Direct-Access     VendorCo ProductCode      2.00 PQ: 0 ANSI: 4
    [  256.901940] sd 0:0:0:0: [sda] 55296000 512-byte logical blocks: (28.3 GB/26.4 GiB)
    [  256.902058] sd 0:0:0:0: [sda] Write Protect is off
    [  256.902067] sd 0:0:0:0: [sda] Mode Sense: 03 00 00 00
    [  256.902186] sd 0:0:0:0: [sda] No Caching mode page found
    [  256.902194] sd 0:0:0:0: [sda] Assuming drive cache: write through
    [  256.905659]  sda: sda1 sda4
    [  256.906643] sd 0:0:0:0: [sda] Attached SCSI removable disk
    [  256.919051] sd 0:0:0:0: Attached scsi generic sg0 type 0
    [  257.224765] hwmon hwmon1: Undervoltage detected!
    [  257.848134] ntfs3: Max link count 4000
    [  257.851810] ntfs3: Unknown parameter 'windows_names'
    [  263.269102] hwmon hwmon1: Voltage normalised
    [  266.367000] usb 1-1: USB disconnect, device number 2
    [  266.381774] device offline error, dev sda, sector 6283224 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.381803] Buffer I/O error on dev sda1, logical block 6282968, lost async page write
    [  266.381818] Buffer I/O error on dev sda1, logical block 6282969, lost async page write
    [  266.381826] Buffer I/O error on dev sda1, logical block 6282970, lost async page write
    [  266.381834] Buffer I/O error on dev sda1, logical block 6282971, lost async page write
    [  266.381842] Buffer I/O error on dev sda1, logical block 6282972, lost async page write
    [  266.381849] Buffer I/O error on dev sda1, logical block 6282973, lost async page write
    [  266.381857] Buffer I/O error on dev sda1, logical block 6282974, lost async page write
    [  266.381865] Buffer I/O error on dev sda1, logical block 6282975, lost async page write
    [  266.381883] Buffer I/O error on dev sda1, logical block 6282976, lost async page write
    [  266.381891] Buffer I/O error on dev sda1, logical block 6282977, lost async page write
    [  266.382553] device offline error, dev sda, sector 6283464 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.383223] device offline error, dev sda, sector 6283704 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.384813] device offline error, dev sda, sector 6283944 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.385457] device offline error, dev sda, sector 6284184 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.387392] device offline error, dev sda, sector 6284424 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.388071] device offline error, dev sda, sector 6284664 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.389646] device offline error, dev sda, sector 6284904 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.390390] device offline error, dev sda, sector 6285144 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  266.391057] device offline error, dev sda, sector 6285384 op 0x1:(WRITE) flags 0x4800 phys_seg 240 prio class 2
    [  267.302308] hwmon hwmon1: Undervoltage detected!
    [  270.051500] usb 1-1: new high-speed USB device number 3 using xhci-hcd
    [  270.201539] usb 1-1: New USB device found, idVendor=ffff, idProduct=5678, bcdDevice= 2.00
    [  270.201572] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
    [  270.201590] usb 1-1: Product: Disk 2.0
    [  270.201604] usb 1-1: Manufacturer: USB
    [  270.201617] usb 1-1: SerialNumber: 4935471142263206857
    [  270.203094] usb-storage 1-1:1.0: USB Mass Storage device detected
    [  270.204120] scsi host0: usb-storage 1-1:1.0
    [  271.208587] scsi 0:0:0:0: Direct-Access     VendorCo ProductCode      2.00 PQ: 0 ANSI: 4
    [  271.209228] sd 0:0:0:0: Attached scsi generic sg0 type 0
    [  271.209524] sd 0:0:0:0: [sda] 55296000 512-byte logical blocks: (28.3 GB/26.4 GiB)
    [  271.209667] sd 0:0:0:0: [sda] Write Protect is off
    [  271.209675] sd 0:0:0:0: [sda] Mode Sense: 03 00 00 00
    [  271.209815] sd 0:0:0:0: [sda] No Caching mode page found
    [  271.209822] sd 0:0:0:0: [sda] Assuming drive cache: write through
    [  271.213152]  sda: sda1 sda4
    [  271.213741] sd 0:0:0:0: [sda] Attached SCSI removable disk
    [  271.866218] ntfs3: Unknown parameter 'windows_names'




## ref 

- [[USB-dat]]