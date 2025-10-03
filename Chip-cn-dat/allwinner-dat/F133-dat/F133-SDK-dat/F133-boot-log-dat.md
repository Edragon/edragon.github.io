
# F133-boot-log-dat.md

    [32]HELLO! BOOT0 is starting!
    [35]BOOT0 commit : adaf1174cc
    [38]set pll start
    [40]periph0 has been enabled
    [43]set pll end
    [44][pmu]: bus read error
    [46]board init ok
    [48]ZQ value = 0x31
    [50]get_pmu_exist() = -1
    [53]ddr_efuse_type: 0xa
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
    [92]dram_tpr4:0x0
    [93]PLL_DDR_CTRL_REG:0xf8002b00
    [96]DRAM_CLK_REG:0xc0000000
    [99][TIMING DEBUG] MR2= 0x0
    [103]DRAM simple test OK.
    [106]dram size =64
    [107]card no is 0
    [109]sdcard 0 line count 4
    [112][mmc]: mmc driver ver 2021-04-2 16:45
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
    PMP3    : 0x0000000000020000-0x0000000000027fff (A,

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
    [00.448]bmp_name=bootlogo.bmp size 28854
    28854 bytes read in 20 ms (1.4 MiB/s)
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
    [00.513]update part info
    [00.517]update bootcmd
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
    [00.576]Board Net Initialization Failed
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
    [    0.000365] clocksource: timer: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 79635851949 ns
    [    0.000940] Calibrating delay loop (skipped), value calculated using timer frequency.. 48.00 BogoMIPS (lpj=240000)
    [    0.000962] pid_max: default: 32768 minimum: 301
    [    0.001123] Mount-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
    [    0.001142] Mountpoint-cache hash table entries: 512 (order: 0, 4096 bytes, linear)
    [    0.002829] ASID allocator initialised with 65536 entries
    [    0.003000] rcu: Hierarchical SRCU implementation.
    [    0.003670] devtmpfs: initialized
    [    0.019704] random: get_random_u32 called from bucket_table_alloc.isra.27+0x102/0x124 with crng_init=0
    [    0.020661] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604462750000 ns
    [    0.020690] futex hash table entries: 256 (order: 0, 6144 bytes, linear)
    [    0.020830] pinctrl core: initialized pinctrl subsystem
    [    0.022223] NET: Registered protocol family 16
    [    0.022989] DMA: preallocated 256 KiB pool for atomic allocations
    [    0.023663] cpuidle: using governor menu
    [    0.066933] rtc_ccu: sunxi ccu init OK
    [    0.075469] clock: sunxi ccu init OK
    [    0.077352] clock: sunxi ccu init OK
    [    0.107807] iommu: Default domain type: Translated 
    [    0.108001] sunxi iommu: irq = 4
    [    0.109244] SCSI subsystem initialized
    [    0.109497] usbcore: registered new interface driver usbfs
    [    0.109592] usbcore: registered new interface driver hub
    [    0.109709] usbcore: registered new device driver usb
    [    0.110979] Advanced Linux Sound Architecture Driver Initialized.
    [    0.111975] pwm module init!
    [    0.113668] g2d 5410000.g2d: Adding to iommu group 0
    [    0.114193] G2D: rcq version initialized.major:252
    [    0.115215] clocksource: Switched to clocksource riscv_clocksource
    [    0.129104] sun8iw20-pinctrl 2000000.pinctrl: initialized sunXi PIO driver
    [    0.132498] NET: Registered protocol family 2
    [    0.133391] tcp_listen_portaddr_hash hash table entries: 256 (order: 0, 4096 bytes, linear)
    [    0.133435] TCP established hash table entries: 512 (order: 0, 4096 bytes, linear)
    [    0.133456] TCP bind hash table entries: 512 (order: 0, 4096 bytes, linear)
    [    0.133471] TCP: Hash tables configured (established 512 bind 512)
    [    0.133619] UDP hash table entries: 256 (order: 1, 8192 bytes, linear)
    [    0.133666] UDP-Lite hash table entries: 256 (order: 1, 8192 bytes, linear)
    [    0.133897] NET: Registered protocol family 1
    [    0.135067] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pc not found, using dummy regulator
    [    0.135789] spi spi0: spi0 supply spi not found, using dummy regulator
    [    0.136063] sunxi_spi_resource_get()2116 - [spi0] SPI MASTER MODE
    [    0.136125] sunxi_spi_resource_get()2154 - Failed to get sample mode
    [    0.136136] sunxi_spi_resource_get()2159 - Failed to get sample delay
    [    0.136146] sunxi_spi_resource_get()2163 - sample_mode:-1431633921 sample_delay:-1431633921
    [    0.136210] sunxi_spi_clk_init()2205 - [spi0] mclk 100000000
    [    0.137048] sunxi_spi_probe()2623 - [spi0]: driver probe succeed, base ffffffd004058000, irq 31
    [    0.139181] workingset: timestamp_bits=62 max_order=14 bucket_order=0
    [    0.147950] squashfs: version 4.0 (2009/01/31) Phillip Lougher
    [    0.148208] ntfs: driver 2.1.32 [Flags: R/W].
    [    0.148557] fuse: init (API version 7.31)
    [    0.169851] io scheduler mq-deadline registered
    [    0.169868] io scheduler kyber registered
    [    0.170787] [DISP]disp_module_init
    [    0.171417] disp 5000000.disp: Adding to iommu group 0
    [    0.171973] [DISP] parser_disp_init_para,line:1430:
    [    0.171977] of_property_read fb0_width fail
    [    0.171999] [DISP] disp_init,line:2386:
    [    0.172004] smooth display screen:0 type:1 mode:4
    [    0.213322] display_fb_request,fb_id:0
    [    0.221666] Freeing logo buffer memory: 1500K
    [    0.222198] disp_al_manager_apply ouput_type:1
    [    0.222633] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pd not found, using dummy regulator
    [    0.223441] [DISP]disp_module_init finish
    [    0.224359] sunxi_sid_init()551 - insmod ok
    [    0.224974] pwm-regulator: supplied by regulator-dummy
    [    0.226806] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pe not found, using dummy regulator
    [    0.227292] uart uart0: uart0 supply uart not found, using dummy regulator
    [    0.227690] uart0: ttyS0 at MMIO 0x2500000 (irq = 18, base_baud = 1500000) is a SUNXI
    [    0.227718] sw_console_setup()1808 - console setup baud 115200 parity n bits 8, flow n
    [    0.946116] printk: console [ttyS0] enabled
    [    0.952001] misc dump reg init
    [    0.956527] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pg not found, using dummy regulator
    [    0.967849] sunxi-rfkill soc@3000000:rfkill@0: module version: v1.0.9
    [    0.975097] sunxi-rfkill soc@3000000:rfkill@0: get gpio chip_en failed
    [    0.982444] sunxi-rfkill soc@3000000:rfkill@0: get gpio power_en failed
    [    0.989860] sunxi-rfkill soc@3000000:rfkill@0: wlan_busnum (1)
    [    0.996445] sunxi-rfkill soc@3000000:rfkill@0: Missing wlan_power.
    [    1.003371] sunxi-rfkill soc@3000000:rfkill@0: wlan clock[0] (32k-fanout1)
    [    1.011149] sunxi-rfkill soc@3000000:rfkill@0: wlan_regon gpio=204 assert=1
    [    1.019036] sunxi-rfkill soc@3000000:rfkill@0: wlan_hostwake gpio=202 assert=1
    [    1.027232] sunxi-rfkill soc@3000000:rfkill@0: wakeup source is enabled
    [    1.034908] sunxi-rfkill soc@3000000:rfkill@0: Missing bt_power.
    [    1.041762] sunxi-rfkill soc@3000000:rfkill@0: bt clock[0] (32k-fanout1)
    [    1.049311] sunxi-rfkill soc@3000000:rfkill@0: bt_rst gpio=210 assert=0
    [    1.057527] [ADDR_MGT] addr_mgt_probe: module version: v1.0.11
    [    1.065338] [ADDR_MGT] addr_mgt_probe: success.
    [    1.071384] sunxi-spinand: AW SPINand MTD Layer Version: 2.3 20211223
    [    1.078712] sunxi-spinand-phy: AW SPINand Phy Layer Version: 1.10 20200306
    [    1.089504] random: fast init done
    [    1.286801] random: crng init done
    [    2.085310] sunxi-spinand-phy: read id failed : -110
    [    2.090881] spi-nand: probe of spi0.0 failed with error -110
    [    2.097336] ehci_hcd: USB 2.0 'Enhanced' Host Controller (EHCI) Driver
    [    2.104651] sunxi-ehci: EHCI SUNXI driver
    [    2.109628] ohci_hcd: USB 1.1 'Open' Host Controller (OHCI) Driver
    [    2.116658] sunxi-ohci: OHCI SUNXI driver
    [    2.122234] sunxi-rtc 7090000.rtc: errata__fix_alarm_day_reg_default_value(): ALARM0_DAY_REG=0, set it to 1
    [    2.133413] sunxi-rtc 7090000.rtc: Warning: Using internal RC 16M clock source. Time may be inaccurate!
    [    2.144372] sunxi-rtc 7090000.rtc: Warning: Using internal RC 16M clock source. Time may be inaccurate!
    [    2.155136] sunxi-rtc 7090000.rtc: Warning: Using internal RC 16M clock source. Time may be inaccurate!
    [    2.166510] sunxi-rtc 7090000.rtc: registered as rtc0
    [    2.172178] sunxi-rtc 7090000.rtc: Warning: Using internal RC 16M clock source. Time may be inaccurate!
    [    2.182804] sunxi-rtc 7090000.rtc: setting system clock to 1970-01-01T00:00:28 UTC (28)
    [    2.191852] sunxi-rtc 7090000.rtc: sunxi rtc probed
    [    2.197850] i2c /dev entries driver
    [    2.201838] sunxi cedar version 1.1
    [    2.206064] sunxi-cedar 1c0e000.ve: Adding to iommu group 0
    [    2.212314] VE: install start!!!
    [    2.212314] 
    [    2.217960] VE: cedar-ve the get irq is 6
    [    2.217960] 
    [    2.224292] VE: ve_debug_proc_info:00000000b4714d51, data:00000000bf5ab713, lock:00000000cc0db6a8
    [    2.224292] 
    [    2.235933] VE: install end!!!
    [    2.235933] 
    [    2.240983] VE: sunxi_cedar_probe
    [    2.245719] sunxi-wdt 6011000.watchdog: Watchdog enabled (timeout=16 sec, nowayout=0)
    [    2.257176] sunxi-mmc 4020000.sdmmc: SD/MMC/SDIO Host Controller Driver(v4.22 2021-12-20 15:40)
    [    2.267261] sunxi-mmc 4020000.sdmmc: ***ctl-spec-caps*** 8
    [    2.273444] sunxi-mmc 4020000.sdmmc: No vmmc regulator found
    [    2.279802] sunxi-mmc 4020000.sdmmc: No vqmmc regulator found
    [    2.286282] sunxi-mmc 4020000.sdmmc: No vdmmc regulator found
    [    2.292689] sunxi-mmc 4020000.sdmmc: No vd33sw regulator found
    [    2.299225] sunxi-mmc 4020000.sdmmc: No vd18sw regulator found
    [    2.305788] sunxi-mmc 4020000.sdmmc: No vq33sw regulator found
    [    2.312292] sunxi-mmc 4020000.sdmmc: No vq18sw regulator found
    [    2.319344] sunxi-mmc 4020000.sdmmc: Got CD GPIO
    [    2.324688] sunxi-mmc 4020000.sdmmc: set cd-gpios as 24M fail
    [    2.331378] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 0Hz bm PP pm UP vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.342579] sunxi-mmc 4020000.sdmmc: no vqmmc,Check if there is regulator
    [    2.362746] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.387281] sunxi-mmc 4020000.sdmmc: sdc set ios:clk 0Hz bm PP pm OFF vdd 0 width 1 timing LEGACY(SDR12) dt B
    [    2.398403] sunxi-mmc 4020000.sdmmc: detmode:gpio irq
    [    2.404766] sunxi-mmc 4021000.sdmmc: SD/MMC/SDIO Host Controller Driver(v4.22 2021-12-20 15:40)
    [    2.414907] sunxi-mmc 4021000.sdmmc: ***ctl-spec-caps*** 8
    [    2.421208] sunxi-mmc 4021000.sdmmc: No vmmc regulator found
    [    2.427560] sunxi-mmc 4021000.sdmmc: No vqmmc regulator found
    [    2.433967] sunxi-mmc 4021000.sdmmc: No vdmmc regulator found
    [    2.440440] sunxi-mmc 4021000.sdmmc: No vd33sw regulator found
    [    2.446977] sunxi-mmc 4021000.sdmmc: No vd18sw regulator found
    [    2.453501] sunxi-mmc 4021000.sdmmc: No vq33sw regulator found
    [    2.460033] sunxi-mmc 4021000.sdmmc: No vq18sw regulator found
    [    2.466593] sunxi-mmc 4021000.sdmmc: Cann't get pin bias hs pinstate,check if needed
    [    2.476100] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 0Hz bm PP pm UP vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.487302] sunxi-mmc 4021000.sdmmc: no vqmmc,Check if there is regulator
    [    2.507432] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.531703] sunxi-mmc 4021000.sdmmc: detmode:manually by software
    [    2.538888] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 52, RE !!
    [    2.545969] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 52, RE !!
    [    2.552755] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.564868] ashmem: initialized
    [    2.568425] exFAT: Version 1.3.0
    [    2.576902] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 400000Hz bm PP pm ON vdd 21 width 1 timing LEGACY(SDR12) dt B
    [    2.588736] [AUDIOCODEC][sunxi_codec_parse_params][2412]:digital_vol:0, lineout_vol:26, mic1gain:31, mic2gain:31 pa_msleep:120, pa_level:1, pa_pwr_level:1
    [    2.588736] 
    [    2.606064] [AUDIOCODEC][sunxi_codec_parse_params][2448]:adcdrc_cfg:0, adchpf_cfg:1, dacdrc_cfg:0, dachpf:0
    [    2.617293] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RE !!
    [    2.624255] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RE !!
    [    2.630975] [AUDIOCODEC][sunxi_internal_codec_probe][2609]:codec probe finished
    [    2.639143] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RE !!
    [    2.646141] sunxi-mmc 4021000.sdmmc: smc 1 p1 err, cmd 5, RE !!
    [    2.652793] sunxi-mmc 4021000.sdmmc: sdc set ios:clk 0Hz bm PP pm OFF vdd 0 width 1 timing LEGACY(SDR12) dt B
    [    2.665097] debugfs: Directory '203034c.dummy_cpudai' with parent 'audiocodec' already present!
    [    2.675088] [SNDCODEC][sunxi_card_init][583]:card init finished
    [    2.684331] sunxi-codec-machine 2030340.sound: 2030000.codec <-> 203034c.dummy_cpudai mapping ok
    [    2.695841] input: audiocodec sunxi Audio Jack as /devices/platform/soc@3000000/2030340.sound/sound/card0/input0
    [    2.708175] [SNDCODEC][sunxi_card_dev_probe][836]:register card finished
    [    2.717814] NET: Registered protocol family 10
    [    2.724255] Segment Routing with IPv6
    [    2.728458] [SNDCODEC][sunxi_hs_init_work][259]:resume-->report switch
    [    2.736029] NET: Registered protocol family 17
    [    2.762397] sunxi-i2c sunxi-i2c2: sunxi-i2c2 supply twi not found, using dummy regulator
    [    2.777276] sunxi-i2c sunxi-i2c2: probe success
    [    2.784722] sun8iw20-pinctrl 2000000.pinctrl: 2000000.pinctrl supply vcc-pb not found, using dummy regulator
    [    2.798778] get ehci0-controller wakeup-source is fail.
    [    2.804771] sunxi ehci0-controller don't init wakeup source
    [    2.811047] [sunxi-ehci0]: probe, pdev->name: 4101000.ehci0-controller, sunxi_ehci: 0xffffffe000661b28, 0x:ffffffd0040f1000, irq_no:2e
    [    2.824598] [sunxi-ehci0]: Not init ehci0
    [    2.829632] get ohci0-controller wakeup-source is fail.
    [    2.835626] sunxi ohci0-controller don't init wakeup source
    [    2.841879] [sunxi-ohci0]: probe, pdev->name: 4101400.ohci0-controller, sunxi_ohci: 0xffffffe000661ef0
    [    2.852292] [sunxi-ohci0]: Not init ohci0
    [    2.857351] get ehci1-controller wakeup-source is fail.
    [    2.863287] sunxi ehci1-controller don't init wakeup source
    [    2.869561] [sunxi-ehci1]: probe, pdev->name: 4200000.ehci1-controller, sunxi_ehci: 0xffffffe0006622b8, 0x:ffffffd0040fb000, irq_no:31
    [    2.883450] sunxi-ehci 4200000.ehci1-controller: 4200000.ehci1-controller supply hci not found, using dummy regulator
    [    2.897097] sunxi-ehci 4200000.ehci1-controller: EHCI Host Controller
    [    2.904329] sunxi-ehci 4200000.ehci1-controller: new USB bus registered, assigned bus number 1
    [    2.914258] sunxi-ehci 4200000.ehci1-controller: irq 49, io mem 0x04200000
    [    2.945270] sunxi-ehci 4200000.ehci1-controller: USB 2.0 started, EHCI 1.00
    [    2.954182] hub 1-0:1.0: USB hub found
    [    2.958539] hub 1-0:1.0: 1 port detected
    [    2.964105] get ohci1-controller wakeup-source is fail.
    [    2.970143] sunxi ohci1-controller don't init wakeup source
    [    2.976481] [sunxi-ohci1]: probe, pdev->name: 4200400.ohci1-controller, sunxi_ohci: 0xffffffe000662680
    [    2.987198] sunxi-ohci 4200400.ohci1-controller: 4200400.ohci1-controller supply hci not found, using dummy regulator
    [    2.999696] sunxi-ohci 4200400.ohci1-controller: OHCI Host Controller
    [    3.007029] sunxi-ohci 4200400.ohci1-controller: new USB bus registered, assigned bus number 2
    [    3.016883] sunxi-ohci 4200400.ohci1-controller: irq 50, io mem 0x04200400
    [    3.090386] hub 2-0:1.0: USB hub found
    [    3.094626] hub 2-0:1.0: 1 port detected
    [    3.102073] get usb_detect_mode is fail, -22
    [    3.107025] get det_vbus is fail, -84
    [    3.111108] get id is fail, -84
    [    3.117155] platform regulatory.0: Direct firmware load for regulatory.db failed with error -2
    [    3.126885] clk: Not disabling unused clocks
    [    3.131651] ALSA device list:
    [    3.134956]   #0: audiocodec
    [    3.138250] cfg80211: failed to load regulatory.db
    [    3.143682] alloc_fd: slot 0 not NULL!
    [    3.148356] VFS: Cannot open root device "mmcblk0p5" or unknown-block(0,0): error -6
    [    3.157147] Please append a correct "root=" boot option; here are the available partitions:
    [    3.166532] Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0)
    [    3.175754] CPU: 0 PID: 1 Comm: swapper Not tainted 5.4.61 #2
    [    3.182154] Call Trace:
    [    3.184895] [<ffffffe000023d56>] walk_stackframe+0x0/0x70
    [    3.190919] [<ffffffe000027d2c>] panic+0xdc/0x266
    [    3.196168] [<ffffffe000000d9c>] mount_block_root+0x1fe/0x266
    [    3.202578] [<ffffffe000000fc2>] prepare_namespace+0x136/0x144
    [    3.209081] [<ffffffe0004242a2>] rest_init+0xbc/0xc0
    [    3.214613] [<ffffffe0004242b0>] kernel_init+0xa/0xe8
    [    3.220240] [<ffffffe0004242a2>] rest_init+0xbc/0xc0
    [    3.225773] [<ffffffe000022d5c>] ret_from_syscall+0xa/0xe
    [    3.231800] ---[ end Kernel panic - not syncing: VFS: Unable to mount root fs on unknown-block(0,0) ]---
