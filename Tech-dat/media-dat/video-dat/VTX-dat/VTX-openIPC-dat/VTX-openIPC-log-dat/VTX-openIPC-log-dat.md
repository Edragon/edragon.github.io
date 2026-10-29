


# VTX-openIPC-log-dat



- [[hi3516-dat]]

log == hi3516ev200

    System startup

    Uncompress Ok!

    U-Boot 2016.11-g6d2ed0c-dirty (Mar 20 2023 - 13:54:30 +0300)hi3516ev200

    Relocation Offset is: 0374c000
    Relocating to 43f4c000, new gd at 43b3bef0, sp at 43b3bed0
    SPI Nor:  hifmc_ip_ver_check(44): Check Flash Memory Controller v100 ...hifmc_ip_ver_check(50):  Found
    hifmc_spi_nor_probe(1802): SPI Nor ID Table Version 1.0
    hifmc_spi_nor_probe(1827): SPI Nor(cs 0) ID: 0xef 0x40 0x18
    spi_w25q256fv_qe_enable(193): Error: Disable Quad failed! reg:0x2
    hifmc_spi_nor_probe(1892): Block:64KB hifmc_spi_nor_probe(1893): Chip:16MB hifmc_spi_nor_probe(1894): Name:"W25Q128(B/F)V"
    hifmc100_spi_nor_probe(147): SPI Nor total size: 16MB
    NAND:  0 MiB
    MMC:   Card did not respond to voltage select!
    No SD device found !
    hisi-sdhci: 0
    In:    serial
    Out:   serial
    Err:   serial
    RAM size: 64MB
    Net:   eth0
    Warning: eth0 (eth0) using random MAC address - 8e:e3:1c:40:e9:81

    Press Ctrl-c to stop autoboot... 0 
    device 0 offset 0x50000, size 0x300000

    SF: 3145728 bytes @ 0x50000 Read: OK
    ## Booting kernel from Legacy Image at 42000000 ...
    Image Name:   Linux-4.9.37-hi3516ev200
    Image Type:   ARM Linux Kernel Image (uncompressed)
    Data Size:    2082308 Bytes = 2 MiB
    Load Address: 40008000
    Entry Point:  40008000
    Loading Kernel Image ... OK

    Starting kernel ...

    Booting Linux on physical CPU 0x0
    Linux version 4.9.37 (haven@haven-virtual-machine) (buildroot-gcc-13.3.0) #1 Sun Jan 5 19:34:43 CST 2025
    CPU: ARMv7 Processor [410fc075] revision 5 (ARMv7), cr=10c53c7d
    CPU: div instructions available: patching division code
    CPU: PIPT / VIPT nonaliasing data cache, VIPT aliasing instruction cache
    OF: fdt:Machine model: Hisilicon HI3516EV200 DEMO Board
    cmz zone is not set!
    Memory policy: Data cache writeback
    CPU: All CPU(s) started in SVC mode.
    Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 10160
    Kernel command line: mem=40M console=ttyAMA0,115200 panic=20 rootfstype=squashfs root=/dev/mtdblock3 init=/init mtdparts=hi_sfc:256k(boot),64k(env),3072k(kernel),10240k(rootfs),-(rootfs_data) mmz_allocator=hisi
    PID hash table entries: 256 (order: -2, 1024 bytes)
    Dentry cache hash table entries: 8192 (order: 3, 32768 bytes)
    Inode-cache hash table entries: 4096 (order: 2, 16384 bytes)
    Memory: 34524K/40960K available (4353K kernel code, 154K rwdata, 1020K rodata, 204K init, 189K bss, 6436K reserved, 0K cma-reserved)
    Virtual kernel memory layout:
        vector  : 0xffff0000 - 0xffff1000   (   4 kB)
        fixmap  : 0xffc00000 - 0xfff00000   (3072 kB)
        vmalloc : 0xc3000000 - 0xff800000   ( 968 MB)
        lowmem  : 0xc0000000 - 0xc2800000   (  40 MB)
        modules : 0xbf000000 - 0xc0000000   (  16 MB)
        .text : 0xc0008000 - 0xc04489a0   (4355 kB)
        .init : 0xc0549000 - 0xc057c000   ( 204 kB)
        .data : 0xc057c000 - 0xc05a2960   ( 155 kB)
        .bss : 0xc05a4000 - 0xc05d3680   ( 190 kB)
    SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
    NR_IRQS:16 nr_irqs:16 16
    Gic dist init...
    arm_arch_timer: Architected cp15 timer(s) running at 50.00MHz (phys).
    clocksource: arch_sys_counter: mask: 0xffffffffffffff max_cycles: 0xb8812736b, max_idle_ns: 440795202655 ns
    sched_clock: 56 bits at 50MHz, resolution 20ns, wraps every 4398046511100ns
    Switching to timer-based delay loop, resolution 20ns
    clocksource: arm,sp804: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 637086815595 ns
    Console: colour dummy device 80x30
    Calibrating delay loop (skipped), value calculated using timer frequency.. 100.00 BogoMIPS (lpj=500000)
    pid_max: default: 32768 minimum: 301
    Mount-cache hash table entries: 1024 (order: 0, 4096 bytes)
    Mountpoint-cache hash table entries: 1024 (order: 0, 4096 bytes)
    CPU: Testing write buffer coherency: ok
    Setting up static identity map for 0x40008200 - 0x40008258
    devtmpfs: initialized
    VFP support v0.3: implementor 41 architecture 2 part 30 variant 7 rev 5
    clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604462750000 ns
    futex hash table entries: 256 (order: -1, 3072 bytes)
    pinctrl core: initialized pinctrl subsystem
    NET: Registered protocol family 16
    DMA: preallocated 256 KiB pool for atomic coherent allocations
    Serial: AMBA PL011 UART driver
    12040000.uart: ttyAMA0 at MMIO 0x12040000 (irq = 21, base_baud = 0) is a PL011 rev2
    console [ttyAMA0] enabled
    12041000.uart: ttyAMA1 at MMIO 0x12041000 (irq = 22, base_baud = 0) is a PL011 rev2
    SCSI subsystem initialized
    ssp-pl022 12070000.spi: ARM PL022 driver, device ID: 0x00800022
    ssp-pl022 12070000.spi: mapped registers from 0x12070000 to c306b000
    ssp-pl022 12071000.spi: ARM PL022 driver, device ID: 0x00800022
    ssp-pl022 12071000.spi: mapped registers from 0x12071000 to c306f000
    usbcore: registered new interface driver usbfs
    usbcore: registered new interface driver hub
    usbcore: registered new device driver usb
    clocksource: Switched to clocksource arch_sys_counter
    NET: Registered protocol family 2
    TCP established hash table entries: 1024 (order: 0, 4096 bytes)
    TCP bind hash table entries: 1024 (order: 0, 4096 bytes)
    TCP: Hash tables configured (established 1024 bind 1024)
    UDP hash table entries: 256 (order: 0, 4096 bytes)
    UDP-Lite hash table entries: 256 (order: 0, 4096 bytes)
    NET: Registered protocol family 1
    RPC: Registered named UNIX socket transport module.
    RPC: Registered udp transport module.
    RPC: Registered tcp transport module.
    RPC: Registered tcp NFSv4.1 backchannel transport module.
    workingset: timestamp_bits=30 max_order=14 bucket_order=0
    squashfs: version 4.0 (2009/01/31) Phillip Lougher
    jffs2: version 2.2 (NAND) (ZLIB) (RTIME) (c) 2001-2006 Red Hat, Inc.
    Block layer SCSI generic (bsg) driver version 0.4 loaded (major 252)
    io scheduler noop registered
    io scheduler deadline registered (default)
    pl061_gpio 120b0000.gpio_chip: PL061 GPIO chip @0x120b0000 registered
    pl061_gpio 120b1000.gpio_chip: PL061 GPIO chip @0x120b1000 registered
    pl061_gpio 120b2000.gpio_chip: PL061 GPIO chip @0x120b2000 registered
    pl061_gpio 120b4000.gpio_chip: PL061 GPIO chip @0x120b4000 registered
    pl061_gpio 120b5000.gpio_chip: PL061 GPIO chip @0x120b5000 registered
    pl061_gpio 120b6000.gpio_chip: PL061 GPIO chip @0x120b6000 registered
    pl061_gpio 120b7000.gpio_chip: PL061 GPIO chip @0x120b7000 registered
    pl061_gpio 120b8000.gpio_chip: PL061 GPIO chip @0x120b8000 registered
    brd: module loaded
    loop: module loaded
    hisi-sfc hisi_spi_nor.0: SPI Nor ID Table Version 1.2
    hisi-sfc hisi_spi_nor.0: Force global unlock
    hisi-sfc hisi_spi_nor.0: SR1:[02]->[00] 
    hisi-sfc hisi_spi_nor.0: SR2:[02]->[00]
    hisi-sfc hisi_spi_nor.0: all blocks are unlocked.
    @spi_nor_scan(), no "m25p,fast-read".
    @spi_nor_scan(), modes->rd_modes:0xd.
    hisi-sfc hisi_spi_nor.0: SR1 [00], SR2 [02], SR3 [e0]
    hisi-sfc hisi_spi_nor.0: (Fast) Read:  opcode=BBh, protocol=122, mode=8, wait=0
    hisi-sfc hisi_spi_nor.0: nor->read_opcode[3: Read; 0B: Fast Read; 3B: Dual; BB: Dual IO; 6B: Quad; EB: Quad IO]: 0xbb.
    hisi-sfc hisi_spi_nor.0: w25q128(b/f)v (Chipsize 16 Mbytes, Blocksize 64KiB)
    5 cmdlinepart partitions found on MTD device hi_sfc
    5 cmdlinepart partitions found on MTD device hi_sfc
    Creating 5 MTD partitions on "hi_sfc":
    0x000000000000-0x000000040000 : "boot"
    0x000000040000-0x000000050000 : "env"
    0x000000050000-0x000000350000 : "kernel"
    0x000000350000-0x000000d50000 : "rootfs"
    0x000000d50000-0x000001000000 : "rootfs_data"
    SPI Nand ID Table Version 2.7
    Cannot found a valid SPI Nand Device
    hisi_spi_nand_probe(175): Error: driver probe, result: -19
    FEPHY:addr=1, la_am=0xb, ldo_am=0x4, r_tuning=0x1d
    libphy: hisi_femac_mii_bus: probed
    libphy: Fixed MDIO Bus: probed
    tun: Universal TUN/TAP device driver, 1.6
    tun: (C) 1999-2004 Max Krasnyansky <maxk@qualcomm.com>
    Generic PHY 10041100.mdio:01: attached PHY driver [Generic PHY] (mii_bus:phy_addr=10041100.mdio:01, irq=-1)
    phy_id=0x20669903, phy_mode=mii
    hisi-femac 10040000.ethernet: using random MAC address 7e:65:b4:d8:a8:39
    xhci-hcd xhci-hcd.0.auto: xHCI Host Controller
    xhci-hcd xhci-hcd.0.auto: new USB bus registered, assigned bus number 1
    xhci-hcd xhci-hcd.0.auto: hcc params 0x0220fe6c hci version 0x110 quirks 0x20010010
    xhci-hcd xhci-hcd.0.auto: irq 115, io mem 0x10030000
    hub 1-0:1.0: USB hub found
    hub 1-0:1.0: 1 port detected
    xhci-hcd xhci-hcd.0.auto: xHCI Host Controller
    xhci-hcd xhci-hcd.0.auto: new USB bus registered, assigned bus number 2
    usb usb2: We don't know the algorithms for LPM for this host, disabling LPM.
    hub 2-0:1.0: USB hub found
    hub 2-0:1.0: hub can't support USB3.0
    hibvt_rtc 120e0000.rtc: rtc core: registered 120e0000.rtc as rtc0
    hibvt_rtc 120e0000.rtc: RTC driver for hibvt enabled
    i2c /dev entries driver
    hibvt-i2c 12060000.i2c: hibvt-i2c0@100000hz registered
    hibvt-i2c 12061000.i2c: hibvt-i2c1@100000hz registered
    hibvt-i2c 12062000.i2c: hibvt-i2c2@100000hz registered
    sdhci: Secure Digital Host Controller Interface driver
    sdhci: Copyright(c) Pierre Ossman
    sdhci-pltfm: SDHCI platform and OF driver helper
    mmc0: SDHCI controller on 10010000.sdhci [10010000.sdhci] using ADMA in legacy mode
    NET: Registered protocol family 10
    NET: Registered protocol family 17
    hibvt_rtc 120e0000.rtc: hctosys: unable to read the hardware clock
    VFS: Mounted root (squashfs filesystem) readonly on device 31:3.
    devtmpfs: mounted
    Freeing unused kernel memory: 204K (c0549000 - c057c000)
    This architecture does not have kernel memory protection.
    Seeding 2048 bits and crediting
    random: crng init done
    Saving 2048 bits of creditable seed for next boot
    Starting syslogd: OK
    Running sysctl: OK
    Sun Jan  5 11:39:49 GMT 2025
    Loading kernel modules...
    modprobe: module exfat not found in modules.dep
    Starting mdev...
    Starting network...
    udhcpc: started, v1.36.1
    udhcpc: broadcasting discover
    udhcpc: broadcasting discover
    udhcpc: broadcasting discover
    udhcpc: broadcasting discover
    udhcpc: broadcasting discover
    udhcpc: no lease, forking to background
    Starting dropbear: OK
    Loading vendor modules...
    mmz_start: 0x42800000, mmz_size: 24M
    hisilicon: Manualy set SENSOR as imx307
    modprobe: can't load module open_jpege (extra/open_jpege.ko): No such file or directory
    modprobe: can't load module open_ive (extra/open_ive.ko): No such file or directory
    modprobe: can't load module open_aio (extra/open_aio.ko): No such file or directory
    modprobe: can't load module open_ai (extra/open_ai.ko): No such file or directory
    modprobe: can't load module open_ao (extra/open_ao.ko): No such file or directory
    modprobe: can't load module open_aenc (extra/open_aenc.ko): No such file or directory
    modprobe: can't load module open_adec (extra/open_adec.ko): No such file or directory
    modprobe: can't load module open_aio (extra/open_aio.ko): No such file or directory
    insert audio
    Starting majestic: OK
    Starting wifibroadcast service...
    Loading modules and wireless driver...
    Wireless module not detected, check the usb connection.


final error [[RTL8812EU-dat]] not installed == Wireless module not detected, check the usb connection.

## ref 

