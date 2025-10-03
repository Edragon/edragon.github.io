
# sunxi-log-dat

```
[32]HELLO! BOOT0 is starting!
[35]BOOT0 commit : adaf1174cc
[38]set pll start
[40]periph0 has been enabled
[42]set pll end
[44][pmu]: bus read error
[46]board init ok
[48]ZQ value = 0x2d
[50]get_pmu_exist() = -1
[52]ddr_efuse_type: 0xa
[55]trefi:7.8ms
[57][AUTO DEBUG] single rank and full DQ!
[61]ddr_efuse_type: 0xa
[63]trefi:7.8ms
[65][AUTO DEBUG] rank 0 row = 13 
[68][AUTO DEBUG] rank 0 bank = 4 
[71][AUTO DEBUG] rank 0 page size = 2 KB 
[75]DRAM BOOT DRIVE INFO: V0.33
[78]DRAM CLK = 528 MHz
[80]DRAM Type = 2 (2:DDR2,3:DDR3)
[83]DRAMC read ODT  off.
[85]DRAM ODT off.
[87]ddr_efuse_type: 0xa
[90]DRAM SIZE =64 M
[91]dram_tpr4:0x0
[93]PLL_DDR_CTRL_REG:0xf8002b00
[96]DRAM_CLK_REG:0xc0000000
[99][TIMING DEBUG] MR2= 0x0
[103]DRAM simple test OK.
[105]dram size =64
[107]card no is 0
[109]sdcard 0 line count 4
[111][mmc]: mmc driver ver 2021-04-2 16:45
[121][mmc]: Wrong media type 0x0
[124][mmc]: ***Try SD card 0***
[133][mmc]: HSSDR52/SDR25 4 bit
[136][mmc]: 50000000 Hz
[138][mmc]: 15343 MB
[140][mmc]: ***SD/MMC 0 init OK!!!***
[191]Loading boot-pkg Succeed(index=0).
[194]Entry_name        = opensbi
[198]Entry_name        = u-boot
[201]Entry_name        = dtb
[204]mmc not para
[206]Jump to second Boot.

OpenSBI auto-t113-linux-V0.8-1-g771d82e
   ____                    _____ ____ _____
  / __ \                  / ____|  _ \_   _|
 | |  | |_ __   ___ _ __ | (___ | |_) || |
 | |  | | '_ \ / _ \ '_ \ \___ \|  _ < | |
 | |__| | |_) |  __/ | | |____) | |_) || |_
  \____/| .__/ \___|_| |_|_____/|____/_____|
        | |
        |_|

Platform Name          : T-HEAD Xuantie Platform
Platform HART Features : RV64ACDFIMSUVX
Platform Max HARTs     : 1
Current Hart           : 0
Firmware Base          : 0x41fc0400
Firmware Size          : 75 KB
Runtime SBI Version    : 0.2

MIDELEG : 0x0000000000000222
MEDELEG : 0x000000000000b1ff
PMP0    : 0x0000000041fc0000-0x0000000041fdffff (A)
PMP1    : 0x0000000040000000-0x000000007fffffff (A,R,W,X)
PMP2    : 0x0000000080000000-0x00000000bfffffff (A,R,W,X)
PMP3    : 0x0000000000020000-0x0000000000027fff (A,ÿ

U-Boot 2018.05-g2a1965a (Jul 10 2022 - 02:50:57 +0000) Allwinner Technology

[00.291]DRAM:  64 MiB
[00.293]Relocation Offset is: 01ed9000
[00.297]secure enable bit: 0
[00.300]CPU=1008 MHz,PLL6=600 Mhz,AHB=200 Mhz, APB1=100Mhz  MBus=300Mhz
[00.306]flash init start
[00.308]workmode = 0,storage type = 1
[00.312][mmc]: mmc driver ver uboot2018:2021-12-20 13:35:00
[00.317][mmc]: get sdc_type fail and use default host:tm1.
[00.324][mmc]: can't find node "mmc0",will add new node
[00.328][mmc]: fdt err returned <no error>
[00.332][mmc]: Using default timing para
[00.336][mmc]: SUNXI SDMMC Controller Version:0x50310
[00.354][mmc]: card_caps:0x3000000a
[00.357][mmc]: host_caps:0x3000003f
[00.360]sunxi flash init ok
[00.363]line:703 init_clocks
[00.366]drv_disp_init
request pwm success, pwm7:pwm7:0x2000c00.
fdt get node offset faill: hdmi
[00.384]unable to map hdmi registers
[00.387]drv_disp_init finish
[00.404]Loading Environment from SUNXI_FLASH... OK
[00.425]boot_gui_init:start
[00.428]set disp.dev2_output_type fail. using defval=0
[00.435]boot_gui_init:finish
partno erro : can't find partition bootloader
54 bytes read in 1 ms (52.7 KiB/s)
[00.449]bmp_name=bootlogo.bmp size 28854
28854 bytes read in 19 ms (1.4 MiB/s)
[00.478]out of usb burn from boot: not need burn key
[00.483]Item0 (Map) magic is bad
[00.486]the secure storage item0 copy0 magic is bad
[00.491]Item0 (Map) magic is bad
[00.494]the secure storage item0 copy1 magic is bad
[00.499]Item0 (Map) magic is bad
List file under ULI/factory
** Unrecognized filesystem type **
root_partition is rootfs
set root to /dev/mmcblk0p5
[00.514]update part info
[00.518]update bootcmd
[00.522]change working_fdt 0x42a98da0 to 0x42a78da0
disable nand error: FDT_ERR_BADPATH
[00.531]The storage not support sample function
No reserved memory region found in source FDT
[00.556]update dts
noncached_alloc(): addr = 0x42b02a40
noncached_alloc(): addr = 0x42b02a80
noncached_alloc(): addr = 0x42b02ac0
noncached_alloc(): addr = 0x42b03300
geth_sys_init:639: get node 'gmac0' error
geth_sys_init fail!
[00.577]Board Net Initialization Failed
[00.580]No ethernet found.
Hit any key to stop autoboot:  1 FDT ERROR:get muxsel err returned FDT_ERR_INTERNAL
sunxi_pwm_pin_set_state, fdt_set_all_pin, ret=-1
[00.625]LCD open finish
 0 
[01.882]no vendor_boot partition is found
Android's image name: f133-mq_r
Detect comp none
[01.898]
Starting kernel ...

[01.901][mmc]: MMC Device 2 not found
[01.905][mmc]: mmc 2 not find, so not exit
[    0.000000] Linux version 5.4.61 (test@test-virtual-machine) (riscv64-unknown-linux-gnu-gcc (C-SKY RISCV Tools V1.8.4 B20200702) 8.1.0, GNU ld (GNU Binutils) 2.32) #2 PREEMPT Tue May 2 06:32:35 UTC 2023
[    0.000000] Zone ranges:
[    0.000000]   DMA32    [mem 0x0000000040000000-0x0000000043ffffff]
[    0.000000]   Normal   empty
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000040000000-0x0000000043ffffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000040000000-0x0000000043ffffff]
[    0.000000] On node 0 totalpages: 16384
[    0.000000]   DMA32 zone: 224 pages used for memmap
[    0.000000]   DMA32 zone: 0 pages reserved
[    0.000000]   DMA32 zone: 16384 pages, LIFO batch:3
[    0.000000] elf_hwcap is 0x20112d
[    0.000000] pcpu-alloc: s0 r0 d32768 u32768 alloc=1*32768
[    0.000000] pcpu-alloc: [0] 0 
[    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 16160
[    0.000000] Kernel command line: earlyprintk=sunxi-uart,0x02500000 clk_ignore_unused initcall_debug=0 console=ttyS0,115200 loglevel=8 root=/dev/mmcblk0p5 init=/pseudo_init partitions=boot-resource@mmcblk0p1:env@mmcblk0p2:env-redund@mmcblk0p3:boot@mmcblk0p4:rootfs@mmcblk0p5:private@mmcblk0p6:rootfs_data@mmcblk0p7:UDISK@mmcblk0p8 cma=0M snum= mac_addr= wifi_mac= bt_mac= specialstr= gpt=1 androidboot.mode=normal androidboot.hardware=sun20iw1p1 boot_type=1 androidboot.boot_type=1 gpt=1 uboot_message=2018.05-g2a1965a(07/10/2022-02:50:57) mbr_o
[    0.000000] Dentry cache hash table entries: 8192 (order: 4, 65536 bytes, linear)
[    0.000000] Inode-cache hash table entries: 4096 (order: 3, 32768 bytes, linear)
[    0.000000] Sorting __ex_table...
[    0.000000] mem auto-init: stack:off, heap alloc:off, heap free:off
[    0.000000] Memory: 55896K/65536K available (4123K kernel code, 405K rwdata, 1699K rodata, 136K init, 229K bss, 9640K reserved, 0K cma-reserved)
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
[    0.000000] rcu: Preemptible hierarchical RCU implementation.
[    0.000000] 	Tasks RCU enabled.
[    0.000000] rcu: RCU calculated value of scheduler-enlistment delay is 10 jiffies.
[    0.000000] NR_IRQS: 0, nr_irqs: 0, preallocated irqs: 0
[    0.000000] plic: mapped 200 interrupts with 1 handlers for 2 contexts.
[    0.000000] riscv_timer_init_dt: Registering clocksource cpuid [0] hartid [0]
[    0.000000] clocksource: riscv_clocksource: mask: 0xffffffffffffffff max_cycles: 0x588fe9dc0, max_idle_ns: 440795202592 ns
[    0.000006] sched_clock: 64 bits at 24MHz, resolution 41ns, wraps every 4398046511097ns
[    0.000027] riscv_timer_clockevent depends on broadcast, but no broadcast function available
[    0.000361] clocksource: timer: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 79635851949 ns
[    0.000947] Calibrating delay loop (skipped), value calculated using timer frequency.. 48.00 BogoMIPS (lpj=240000)
[    0.000968] pid_max: default: 32768 minimum: 301
[    0.001127] Mount-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.001147] Mountpoint-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.002817] ASID allocator initialised with 65536 entries
[    0.002985] rcu: Hierarchical SRCU implementation.
[    0.003645] devtmpfs: initialized
[    0.019187] random: get_random_u32 called from bucket_table_alloc.isra.27+0x102/0x124 with crng_init=0
[    0.020051] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604462750000 ns
[    0.020136] futex hash table entries: 256 (order: 0, 6144 bytes, linear)
[    0.020282] pinctrl core: initialized pinctrl subsystem
[    0.021646] NET: Registered protocol family 16
[    0.022409] DMA: preallocated 256 KiB pool for atomic allocations
[    0.023075] cpuidle: using governor menu
[    0.065986] rtc_ccu: sunxi ccu init OK
[    0.074358] clock: sunxi ccu init OK
[    0.076207] clock: sunxi ccu init OK
[    0.106479] iommu: Default domain type: Translated 
[    0.106671] sunxi iommu: irq = 4
[    0.107895] SCSI subsystem initialized
[    0.108147] usbcore: registered new interface driver usbfs
[    0.108240] usbcore: registered new interface driver hub
[    0.108356] usbcore: registered new device driver usb
[    0.109357] Advanced Linux Sound Architecture Driver Initialized.
[    0.110341] pwm module init!
[    0.112130] g2d 5410000.g2d: Adding to iommu group 0
[    0.112659] G2D: rcq version initialized.major:252
[    0.113669] clocksource: Switched to clocksource riscv_clocksource
[    0.127223] sun8iw20-pinctrl 2000000.pinctrl: initialized sunXi PIO driver
[    0.130584] NET: Registered protocol family 2
[    0.131469] tcp_listen_portaddr_hash hash table entries: 256 (order: 0, 4096 bytes, linear)
[    0.131512] TCP established hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.131534] TCP bind hash table entries: 512 (order: 0, 4096 bytes, linear)
[    0.131548] TCP: Hash tables configured (established 512 bind 512)
[    0.131696] UDP hash table entries: 256 (order: 1, 8192 bytes, linear)
[    0.131742] UDP-Lite hash table entries: 256 (order: 1, 8192 bytes, linear)
[    0.131974] NET: Registered protocol family 1
[    0.133142] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pc not found, using dummy regulator
[    0.133848] spi spi0: spi0 supply spi not found, using dummy regulator
[    0.134130] sunxi_spi_resource_get()2116 - [spi0] SPI MASTER MODE
[    0.134192] sunxi_spi_resource_get()2154 - Failed to get sample mode
[    0.134203] sunxi_spi_resource_get()2159 - Failed to get sample delay
[    0.134214] sunxi_spi_resource_get()2163 - sample_mode:-1431633921 sample_delay:-1431633921
[    0.134279] sunxi_spi_clk_init()2205 - [spi0] mclk 100000000
[    0.135104] sunxi_spi_probe()2623 - [spi0]: driver probe succeed, base ffffffd004058000, irq 31
[    0.137212] workingset: timestamp_bits=62 max_order=14 bucket_order=0
[    0.145805] squashfs: version 4.0 (2009/01/31) Phillip Lougher
[    0.146050] ntfs: driver 2.1.32 [Flags: R/W].
[    0.146381] fuse: init (API version 7.31)
[    0.167788] io scheduler mq-deadline registered
[    0.167805] io scheduler kyber registered
[    0.168708] [DISP]disp_module_init
[    0.169333] disp 5000000.disp: Adding to iommu group 0
[    0.169884] [DISP] parser_disp_init_para,line:1430:
[    0.169889] of_property_read fb0_width fail
[    0.169911] [DISP] disp_init,line:2386:
[    0.169915] smooth display screen:0 type:1 mode:4
[    0.210704] display_fb_request,fb_id:0
[    0.219072] Freeing logo buffer memory: 1500K
[    0.219594] disp_al_manager_apply ouput_type:1
[    0.220023] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pd not found, using dummy regulator
[    0.220808] [DISP]disp_module_init finish
[    0.221700] sunxi_sid_init()551 - insmod ok
[    0.222296] pwm-regulator: supplied by regulator-dummy
[    0.224054] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pe not found, using dummy regulator
[    0.224538] uart uart0: uart0 supply uart not found, using dummy regulator
[    0.224930] uart0: ttyS0 at MMIO 0x2500000 (irq = 18, base_baud = 1500000) is a SUNXI
[    0.224958] sw_console_setup()1808 - console setup baud 115200 parity n bits 8, flow n
[    0.943314] printk: console [ttyS0] enabled
[    0.949217] misc dump reg init
[    0.953736] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pg not found, using dummy regulator
[    0.965027] sunxi-rfkill soc@3000000:rfkill@0: module version: v1.0.9
[    0.972243] sunxi-rfkill soc@3000000:rfkill@0: get gpio chip_en failed
[    0.979639] sunxi-rfkill soc@3000000:rfkill@0: get gpio power_en failed
[    0.987062] sunxi-rfkill soc@3000000:rfkill@0: wlan_busnum (1)
[    0.993594] sunxi-rfkill soc@3000000:rfkill@0: Missing wlan_power.
[    1.000552] sunxi-rfkill soc@3000000:rfkill@0: wlan clock[0] (32k-fanout1)
[    1.008358] sunxi-rfkill soc@3000000:rfkill@0: wlan_regon gpio=204 assert=1
[    1.016247] sunxi-rfkill soc@3000000:rfkill@0: wlan_hostwake gpio=202 assert=1
[    1.024389] sunxi-rfkill soc@3000000:rfkill@0: wakeup source is enabled
[    1.032096] sunxi-rfkill soc@3000000:rfkill@0: Missing bt_power.
[    1.038871] sunxi-rfkill soc@3000000:rfkill@0: bt clock[0] (32k-fanout1)
[    1.046472] sunxi-rfkill soc@3000000:rfkill@0: bt_rst gpio=210 assert=0
[    1.054697] [ADDR_MGT] addr_mgt_probe: module version: v1.0.11
[    1.062397] [ADDR_MGT] addr_mgt_probe: success.
[    1.068483] sunxi-spinand: AW SPINand MTD Layer Version: 2.3 20211223
[    1.075810] sunxi-spinand-phy: AW SPINand Phy Layer Version: 1.10 20200306
[    1.086619] random: fast init done
[    1.284341] random: crng init done
[    2.073747] sunxi-spinand-phy: read id failed : -110
[    2.079316] spi-nand: probe of spi0.0 failed with error -110
[    2.085807] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
[    2.093089] sunxi-ehci: EHCI SUNXI driver
[    2.098062] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
[    2.105090] sunxi-ohci: OHCI SUNXI driver
[    2.112178] sunxi-rtc 7090000.rtc: registered as rtc0
[    2.118048] sunxi-rtc 7090000.rtc: setting system clock to 1970-01-01T00:00:21 UTC (21)
[    2.127044] sunxi-rtc 7090000.rtc: sunxi rtc probed
[    2.133047] i2c /dev entries driver
[    2.137049] sunxi cedar version 1.1
[    2.141227] sunxi-cedar 1c0e000.ve: Adding to iommu group 0
[    2.147532] VE: install start!!!
[    2.147532] 
[    2.153114] VE: cedar-ve the get irq is 6
[    2.153114] 
[    2.159496] VE: ve_debug_proc_info:00000000f36217e6, data:00000000dc0b564d, lock:00000000c9928603
[    2.159496] 
[    2.171135] VE: install end!!!
[    2.171135] 
[    2.176213] VE: sunxi_cedar_probe
[    2.180880] sunxi-wdt 6011000.watchdog: Watchdog enabled (timeout=16 sec, nowayout=0)
[    2.192331] sunxi-mmc 4020000.sdmmc: SD/MMC/SDIO Host Controller Driver(v4.22 2021-12-20 15:40)
[    2.202403] sunxi-mmc 4020000.sdmmc: ***ctl-spec-caps*** 8
[    2.208636] sunxi-mmc 4020000.sdmmc: No vmmc regulator found
[    2.214972] sunxi-mmc 4020000.sdmmc: No vqmmc regulator found
[    2.221410] sunxi-mmc 4020000.sdmmc: No vdmmc regulator found
[    2.227844] sunxi-mmc 4020000.sdmmc: No vd33sw regulator found
[    2.234413] sunxi-mmc 4020000.sdmmc: No vd18sw regulator found
[    2.240918] sunxi-mmc 4020000.sdmmc: No vq33sw regulator found
[    2.247452] sunxi-mmc 4020000.sdmmc: No vq18sw regulator found
[    2.254497] sunxi-mmc 4020000.sdmmc: Got CD GPIO
[    2.259842] sunxi-mmc 4020000.sdmmc: set cd-gpios as 24M fail
[    2.266531] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 0Hz bm PP pm UP vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.277729] sunxi-mmc 4020000.sdmmc: no vqmmc,Check if there is regulator
[    2.297920] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.322389] sunxi-mmc 4020000.sdmmc: detmode:gpio irq
[    2.322460] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 0Hz bm PP pm OFF vdd 0 width 1 timing LEGACY(SDR12) dt B
[    2.339973] sunxi-mmc 4021000.sdmmc: SD/MMC/SDIO Host Controller Driver(v4.22 2021-12-20 15:40)
[    2.350011] sunxi-mmc 4021000.sdmmc: ***ctl-spec-caps*** 8
[    2.356403] sunxi-mmc 4021000.sdmmc: No vmmc regulator found
[    2.362761] sunxi-mmc 4021000.sdmmc: No vqmmc regulator found
[    2.369255] sunxi-mmc 4021000.sdmmc: No vdmmc regulator found
[    2.375687] sunxi-mmc 4021000.sdmmc: No vd33sw regulator found
[    2.382189] sunxi-mmc 4021000.sdmmc: No vd18sw regulator found
[    2.388749] sunxi-mmc 4021000.sdmmc: No vq33sw regulator found
[    2.395280] sunxi-mmc 4021000.sdmmc: No vq18sw regulator found
[    2.401863] sunxi-mmc 4021000.sdmmc: Cann't get pin bias hs pinstate,check if needed
[    2.411334] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 0Hz bm PP pm UP vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.422536] sunxi-mmc 4021000.sdmmc: no vqmmc,Check if there is regulator
[    2.442694] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.466946] sunxi-mmc 4021000.sdmmc: detmode:manually by software
[    2.474658] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 52, RTO !!
[    2.481767] ashmem: initialized
[    2.485295] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 52, RTO !!
[    2.492229] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.503844] exFAT: Version 1.3.0
[    2.511958] [AUDIOCODEC][sunxi_codec_parse_params][2412]:digital_vol:0, lineout_vol:26, mic1gain:31, mic2gain:31 pa_msleep:120, pa_level:1, pa_pwr_level:1
[    2.511958] 
[    2.529288] [AUDIOCODEC][sunxi_codec_parse_params][2448]:adcdrc_cfg:0, adchpf_cfg:1, dacdrc_cfg:0, dachpf:0
[    2.540874] [AUDIOCODEC][sunxi_internal_codec_probe][2609]:codec probe finished
[    2.549134] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
[    2.562143] debugfs: Directory '203034c.dummy_cpudai' with parent 'audiocodec' already present!
[    2.572145] [SNDCODEC][sunxi_card_init][583]:card init finished
[    2.579640] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RTO !!
[    2.587275] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RTO !!
[    2.594861] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RTO !!
[    2.601807] sunxi-codec-machine 2030340.sound: 2030000.codec <-> 203034c.dummy_cpudai mapping ok
[    2.611615] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RTO !!
[    2.618428] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 0Hz bm PP pm OFF vdd 0 width 1 timing LEGACY(SDR12) dt B
[    2.631090] input: audiocodec sunxi Audio Jack as /devices/platform/soc@3000000/2030340.sound/sound/card0/input0
[    2.643523] [SNDCODEC][sunxi_card_dev_probe][836]:register card finished
[    2.653163] NET: Registered protocol family 10
[    2.658258] [SNDCODEC][sunxi_hs_init_work][259]:resume-->report switch
[    2.667015] Segment Routing with IPv6
[    2.671338] NET: Registered protocol family 17
[    2.697764] sunxi-i2c sunxi-i2c2: sunxi-i2c2 supply twi not found, using dummy regulator
[    2.712526] sunxi-i2c sunxi-i2c2: probe success
[    2.720000] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pb not found, using dummy regulator
[    2.734084] get ehci0-controller wakeup-source is fail.
[    2.740050] sunxi ehci0-controller don't init wakeup source
[    2.746322] [sunxi-ehci0]: probe, pdev->name: 4101000.ehci0-controller, sunxi_ehci: 0xffffffe000661b28, 0x:ffffffd0040f1000, irq_no:2e
[    2.759871] [sunxi-ehci0]: Not init ehci0
[    2.764901] get ohci0-controller wakeup-source is fail.
[    2.770904] sunxi ohci0-controller don't init wakeup source
[    2.777174] [sunxi-ohci0]: probe, pdev->name: 4101400.ohci0-controller, sunxi_ohci: 0xffffffe000661ef0
[    2.787649] [sunxi-ohci0]: Not init ohci0
[    2.792655] get ehci1-controller wakeup-source is fail.
[    2.798643] sunxi ehci1-controller don't init wakeup source
[    2.804975] [sunxi-ehci1]: probe, pdev->name: 4200000.ehci1-controller, sunxi_ehci: 0xffffffe0006622b8, 0x:ffffffd0040fb000, irq_no:31
[    2.818819] sunxi-ehci 4200000.ehci1-controller: 4200000.ehci1-controller supply hci not found, using dummy regulator
[    2.832493] sunxi-ehci 4200000.ehci1-controller: EHCI Host Controller
[    2.839819] sunxi-ehci 4200000.ehci1-controller: new USB bus registered, assigned bus number 1
[    2.849685] sunxi-ehci 4200000.ehci1-controller: irq 49, io mem 0x04200000
[    2.883725] sunxi-ehci 4200000.ehci1-controller: USB 2.0 started, EHCI 1.00
[    2.892631] hub 1-0:1.0: USB hub found
[    2.896950] hub 1-0:1.0: 1 port detected
[    2.902503] get ohci1-controller wakeup-source is fail.
[    2.908576] sunxi ohci1-controller don't init wakeup source
[    2.914865] [sunxi-ohci1]: probe, pdev->name: 4200400.ohci1-controller, sunxi_ohci: 0xffffffe000662680
[    2.925618] sunxi-ohci 4200400.ohci1-controller: 4200400.ohci1-controller supply hci not found, using dummy regulator
[    2.938083] sunxi-ohci 4200400.ohci1-controller: OHCI Host Controller
[    2.945418] sunxi-ohci 4200400.ohci1-controller: new USB bus registered, assigned bus number 2
[    2.955262] sunxi-ohci 4200400.ohci1-controller: irq 50, io mem 0x04200400
[    3.028775] hub 2-0:1.0: USB hub found
[    3.033013] hub 2-0:1.0: 1 port detected
[    3.040483] get usb_detect_mode is fail, -22
[    3.045369] get det_vbus is fail, -84
[    3.049451] get id is fail, -84
[    3.055469] platform regulatory.0: Direct firmware load for regulatory.db failed with error -2
[    3.065199] clk: Not disabling unused clocks
[    3.069966] ALSA device list:
[    3.073320]   #0: audiocodec
[    3.076619] cfg80211: failed to load regulatory.db
[    3.082023] alloc_fd: slot 0 not NULL!
[    3.086691] VFS: Cannot open root device "mmcblk0p5" or unknown-block(0,0): error -6
[    3.095459] Please append a correct "root=" boot option; here are the available partitions:
[    3.104843] Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0)
[    3.114063] CPU: 0 PID: 1 Comm: swapper Not tainted 5.4.61 #2
[    3.120464] Call Trace:
[    3.123206] [<ffffffe000023d56>] walk_stackframe+0x0/0x70
[    3.129230] [<ffffffe000027d2c>] panic+0xdc/0x266
[    3.134478] [<ffffffe000000d9c>] mount_block_root+0x1fe/0x266
[    3.140888] [<ffffffe000000fc2>] prepare_namespace+0x136/0x144
[    3.147392] [<ffffffe0004242a2>] rest_init+0xbc/0xc0
[    3.152925] [<ffffffe0004242b0>] kernel_init+0xa/0xe8
[    3.158554] [<ffffffe0004242a2>] rest_init+0xbc/0xc0
[    3.164087] [<ffffffe000022d5c>] ret_from_syscall+0xa/0xe
[    3.170114] ---[ end Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0) ]---

```
