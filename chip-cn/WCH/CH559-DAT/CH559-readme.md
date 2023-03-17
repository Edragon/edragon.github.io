

南京沁恒电子有限公司 2015.04
最新资料请到我们的网站上查询
http://wch.cn
http://winchiphead.com


文件目录
  |
  |-- README.TXT：目录文件说明
  |-- BRIEF
  |      |--CH559DS0.PDF：CH559简介
  |-- DS
  |      |--CH559DS1.PDF：CH559应用手册
  |-- EVT
  |      |-- EXAM: C例程
  |      |      |--CH559.uvproj：CH559 keil工程文件
  |      |      |--CH559.H：CH559 C语言头文件，SFR定义
  |      |      |--CH559.INC：CH559汇编头文件，SFR定义
  |      |      |--DEBUG.C：UART0初始化、常用延时函数、UART0数据收发子函数
  |      |      |--DEBUG.H：UART0初始化、常用延时函数、UART0数据收发子函数声明
  |      |      |--CHIP_ID
  |      |      |      |-- GETID.C:获取芯片唯一ID号
  |      |      |      |-- GETID.hex:
  |      |      |--Encryption
  |      |      |      |-- Encryption.C:芯片用户程序加密例程
  |      |      |      |-- Encryption.hex:
  |      |      |      |-- 芯片加密建议.PDF  
  |      |      |--ADC：
  |      |      |      |-- ADCAUTODMA.C:DMA方式自动AD采样
  |      |      |      |-- ADCAUTODMA.hex:DMA方式自动AD采样hex文件
  |      |      |      |-- ADCManual.C:手动方式AD采样
  |      |      |      |-- ADCManual.hex:手动AD采样hex文件
  |      |      |--DataFlash
  |      |      |      |-- DataFlash.C:DATA Flash读写、擦除例程
  |      |      |      |-- DataFlash.hex:DATA Flash操作hex文件
  |      |      |--GPIO
  |      |      |      |-- GPIO.C:IO口配置、驱动能力设置和IO中断设置
  |      |      |      |-- GPIO.hex:IO操作hex文件
  |      |      |--LED_CTL
  |      |      |      |-- LED_Udisk_Flash_DMA
  |      |      |      |      |--完整演示工程，需要添加文件系统LIB 
  |      |      |--PWM
  |      |      |      |-- PWM.C:PWM1和PWM2操作程序
  |      |      |      |-- PWM.hex:PWM1和PWM2操作hex文件 
  |      |      |--SPI0
  |      |      |      |-- SPI0Flash.C:SPI0操作串行Flash
  |      |      |      |-- SPI0Flash.hex:SPI0操作串行Flash的hex文件 
  |      |      |      |-- SPI0Master.C:SPI0主机发送、接收程序
  |      |      |      |-- SPI0Master.hex:SPI0主机接口函数hex文件 
  |      |      |      |-- SPI0Slv.C:SPI0从机初始化程序
  |      |      |      |-- SPI0Slv.hex:SPI0从机接口函数hex文件 
  |      |      |--SPI1
  |      |      |      |-- SPI1Master.C:SPI1主机发送、接收程序
  |      |      |      |-- SPI1Master.hex:SPI1主机接口函数hex文件
  |      |      |--Timer0
  |      |      |      |-- Timer0.C:Timer0中断、定时器设置
  |      |      |      |-- Timer0.hex:Timer0操作hex文件
  |      |      |--Timer1
  |      |      |      |-- Timer1.C:Timer1设中断、定时器设置
  |      |      |      |-- Timer1.hex:Timer1操作hex文件
  |      |      |--Timer2
  |      |      |      |-- Timer2.C:Timer1中断、定时器设置和捕捉
  |      |      |      |-- Timer2.hex:Timer2操作hex文件
  |      |      |--Timer3
  |      |      |      |-- Timer3.C:Timer1中断、定时器设置、捕捉和PWM3
  |      |      |      |-- Timer3.hex:Timer3操作hex文件
  |      |      |--UART1
  |      |      |      |-- UART1.C:
  |      |      |      |-- UART1.hex:
  |      |      |      |-- UART1_485.C:UART1 485模式数据收发
  |      |      |      |-- UART1_485.hex:
  |      |      |      |-- UART1_INT.C:UART1中断方式数据收发
  |      |      |      |-- UART1.hex:
  |      |      |      |-- UART1_Query.C:UART1查询方式数据收发
  |      |      |      |-- UART1.hex:
  |      |      |--WDOG
  |      |      |      |-- WDOG.C:看门狗操作
  |      |      |      |-- WDOG.hex:看门狗操作hex文件
  |      |      |--XBUS
  |      |      |      |-- XBUS.C:直接、复用地址方式操作外扩RAM
  |      |      |      |-- XBUS.hex:XBUS操作hex文件
  |      |      |--IAP
  |      |      |      |--CH559 IAP功能使用说明.doc
  |      |      |      |--CH559IAP
  |      |      |      |     |-- CH559_IAP.uvproj:CH559 IAP工程文件
  |      |      |      |     |-- CH559_IAP.C:IAP功能C程序，支持串口和USB方式升级用户程序
  |      |      |      |     |-- CH559_IAP.H:IAP功能头文件
  |      |      |      |     |-- CH559_IAP.hex:IAP功能hex文件
  |      |      |      |--CH559User
  |      |      |      |     |-- CH559_User.uvproj:CH559 IAP 用户程序工程文件
  |      |      |      |     |-- CH559_Demo.C: CH559 配合IAP的应用程序，通过按键进入IAP
  |      |      |      |     |-- CH559_Demo.hex:配合IAP功能用户程序hex文件
  |      |      |      |--CH559WINUser 
  |      |      |      |     |-- WCHMCUIAP_WINAPP.exe:CH559 配合例程IAP的上位机工具，支持串口和USB下载
  |      |      |--USB
  |      |      |      |-- DEVICE
  |      |      |      |      |-- Compound Dev.C:模拟键鼠例程，支持部分类命令
  |      |      |      |      |-- Compound Dev.hex:模拟键鼠hex文件  
  |      |      |      |      |-- USBDEV.C:模拟厂商自定义设备，需要安装CH372驱动，可以通过372test.exe调试(批量数据收发)
  |      |      |      |      |-- USBDEV.hex:模拟厂商自定义设备hex文件 
  |      |      |      |-- HOST
  |      |      |      |      |-- USBHOST.C:主机模式ROOT-HUB下初始化和枚举DP/DM端口连接的USB设备,可以操作U盘或者操作USB鼠标,不包含HID类命令处理
  |      |      |      |      |-- USBHOST.hex:  
  |      |      |      |      |-- USBH_HUB_KM.C: USB主机应用例子,初始化和枚举USB端口连接的设备,同时支持最多2个USB设备,支持一级外部HUB,可以操作USB键鼠和HUB,包含HID类命令处理
  |      |      |      |      |-- USBH_HUB_KM.hex: 
  |      |      |      |      |-- USBH_KM.C: USB主机应用例子,仅支持操作ROOTHUB上挂接的键鼠等HID设备。
  |      |      |      |      |-- USBH_KM.hex: 
  |      |      |      |      |-- USBH_AOA.C: USB主机应用例子,支持ROOTHUB上连接安卓设备与APP进行通讯。
  |      |      |      |      |-- USBH_AOA.hex: 
  |      |      |      |      |-- TOOL
  |      |      |      |      |    |-- UARTDemo.apk:AOA调试配套APK测试文件
  |      |      |      |-- U_DISK
  |      |      |      |      |      |-- EXAM1.C:C示例源程序,以字节为单位读写文件，包括文件创建、删除、修改文件属性,修改文件名
  |      |      |      |      |      |-- EXAM1.hex:字节方式文件读写hex文件
  |      |      |      |      |      |-- EXAM6.C:C示例源程序,以扇区为单位读写文件，包括文件创建、删除、修改文件属性
  |      |      |      |      |      |-- EXAM6.hex:字节方式文件读写hex文件
  |      |      |      |      |      |-- EXAM9.C:C示例源程序,新建文件夹，文件下创建文件和子目录
  |      |      |      |      |      |-- EXAM9.hex:创建目录hex文件
  |      |      |      |      |      |-- EXAM11.C:C示例源程序,枚举根目录或者指定目下的文件
  |      |      |      |      |      |-- EXAM11.hex:
  |      |      |-- USB_LIB
  |      |      |      |      |-- CH559UFI.C:CH559 U盘文件系统库常用接口函数
  |      |      |      |      |-- CH559UFI.H:CH559 U盘文件系统库变量和函数声明头文件
  |      |      |      |      |-- CH559UFI.LIB:CH559 U盘文件系统库文件(编译器内存模式设置成:small)
  |      |      |      |      |-- CH559UFX.LIB:U盘文件系统库文件(编译器内存模式设置成:large)
  |      |      |      |      |-- CH559UF_README.TXT:CH559 U盘文件系统变更文档
  |      |-- PUB: 评估板说明
  |      |      |-- CH559EVT.PDF: 评估板说明
  |      |      |-- CH559SCH.PDF: 评估板原理图
  |      |      |-- CH55X指令周期.PDF: CH55X汇编指令周期表
  |      |      |-- CH55X脱机烧录器V130 
  |      |      |      |      |-- 脱机烧录器使用说明.PDF
  |      |      |      |      |-- 脱机烧录器结构图.PDF 
  |      |      |      |      |-- OffLineWCH_ISP配置工具 
  |      |      |      |      |      |--脱机烧录器配置工具.exe
  |      |      |      |      |      |--SV00xISPDLL.dll 


2015-08-21改动说明：
(1)、更新DataFlash操作(读取溢出定义缓冲区大小)。
(2)、修正EXAM1文件读取操作时没有指向存储缓冲区的操作。
(3)、修正FlashMaster.C SPI初始化重复操作位bS0_MST_CLK。
(4)、增加了PWM引脚映射的接口函数。
(5)、修改Timer2.C文件捕获之后需要加延时的问题，不加延时最后一次采样数据会丢失。
(6)、2015.06.27 CH559.H更新，变换了LED接口DMA数据发送方式，有原来的多通道分位发改成多通道字节方式，
有原来的8数据通道改成4数据通道，最多可以同时使用2个DMA发送数据；
此外还增加了看门狗超时标志位（只读）。
(7)、修改UART1.C中断里面发送的错误，接收长度自减，自发自收的时候数据长度为0.
(8)、修改TIMER3.C文件CAP3时，没有清空中断导致获取不到第一次数据的问题。
(9)、修改Mouse.C,原程序文件存在错误，使用同地址主机寄存器操作设备和全速\低速设置问题,增加模拟键盘功能，模拟复合设备，支持部分类命令。
(10)、CH559SCH.PDF中增加CH559MINIEVT的原理图。
(11)、EVT\PCB更新，增加CH559MINIEVT的原理图和PCB。
(12)、增加EXAM11文件，U盘文件枚举功能。
(13)、修改了XBUS.C文件，原来文件存在变量溢出的问题。
(14)、删除.C文件中使用的LED4~LED7，每个.C文件增加上电延时30ms的操作。
(15)、更改了SPI0从机模式数据发送时，先发送预置数的问题。
(16)、EVT\PUB\CH559EVT.PDF更新，对原来的说明进行调整，增加MINI板说明和IAP功能使用说明。
(17)、删除了原来的LED控制程序，改成标准的驱动方式，可以实现读U盘显示信息，存储至Flash,然后读Flash显示信息。
(18)、EXAM6中添加了一个16位的变量CH559vSectorSize来指定实际扇区的大小，现在默认是512，这样解决了原来使用扇区大小高字节CH559vSectorSizeH运算错误（默认2）的问题。
(19)、增加IAP功能资料包。


2015-11-26改动说明：
(1)原理图改动，485使用XA和XB之间的匹配电阻由120Ω改成0欧姆；
(2)UART1例程将485和TTL分开，突出串口FIFO的使用；
(3)增加EXAM9，使用CH559新建文件夹，文件夹文件操作；

2015-12-28改动说明：
(1)、CH559DS1发布版本1B，更改主要包括LED控制说明和主频;
(2)、CH559.H:  Fxt由4-13MHz改成4-20MHz；Fpll由24-320MHz改成24-350MHz；Fsys由1-60MHz改成1-57MHz；
(3)、CH559.INC:  Fxt由4-13MHz改成4-20MHz；Fpll由24-320MHz改成24-350MHz；Fsys由1-60MHz改成1-57MHz；
   typedef USB_SETUP_REQ xdata PXUSB_SETUP_REQ;改成 typedef USB_SETUP_REQ xdata *PXUSB_SETUP_REQ;修正了错误；
(4)、CH559UFI.H:  CH559_LIB_VER 由0x10改成0x11;
(5)、修改USBDEV.C中设备初始化函数中原来使用UHUB0_CTRL改成UDEV_CTRL寄存器，两者地址相同，只是前者用于主机，后者用于设备，避免误解；
(6)、CH559UFI(small)/CH559UFX(large) V1.1 最新更新 2015.12.23
   一、修正BUG
    1、CH559FileWrite写根目录长度限制失败
   一、更新和增加
    1、更新DMA支持4096字节的大扇区
(7)、ADCManual.C的ADC采样增加一个通道选择数组，防止客户通道赋值出错；
(8)、DataFlash.C芯片改进了DataFlash读写，旧的擦和写兼容新版本，新版操作旧片子会有问题；
(9)、Timer0.C Timer1.C Timer2.C更改了定时器赋值的方式；
(10)、增加了芯片用户程序加密的例子程序Encryption.C和一般的加密方法的说明文档；
(11)、增加了CH55X系列单片机汇编指令周期表；

2016-2-18改动说明：
(1)、CH559DS1 主频最高改为56MHz，明确部分引脚说明和USB部分说明；
(2)、CH559.H和CH559.INC中涉及主频部分改成最高56MHz，MASK_LED_CHAN_MOD由0x80改为0xC0;
(3)、CH559UFI.H:  CH559_LIB_VER 由0x11改成0x12;
(4)、CH559UFI(small)/CH559UFX(large) V1.2 最新更新 2016.2.18
     一、修正BUG
     1、CH559FileModify文件日期和时间大小端错误;
(5)、删除了USBHOST中的两个冗余的例子程序，现在改成一个只操作ROOT_HUB下HID的例子和支持操作2个ROOT_HUB下设备和一级HUB下HID的例子，并且支持HID类命令；
(6)、统一文件风格和文件结构，主要是操作U盘的LIB库换了一个位置,从EXAM根目录下调用公共文件；

2016-3-1改动说明：
(1)、Compound Dev.C修改NUM_LOCK的判断条件;

2016-3-3改动说明：
(1)、GPIO.C 修改如何配置单个IO状态。
(2)、所有.C文件增加 #pragma  NOAREGS。

2016-3-22改动说明：
(1)、Compound Dev.C 注：接收数据的缓冲区的长度 >= min（可能接收到的最大数据包长度 + 2字节，64 字节）
     USB总线复位增加UEP0/1/2/3_CTRL的清理
     CH559中断清零，只支持按位清0，或者写1清零
     支持标准请求 USB_CLEAR_FEATURE和USB_GET_STATUS和USB_SET_FEATURE
     
2016-6-24改动说明：
(1)、ADCManual.C增加个通道切换采样函数，同时把首次采样值取出丢弃
(2)、DataFlash.C修改了DataFlash的写和擦除函数
(3)、Compond_Dev.C和USBDEV.C 在端点1、2上传数据时增加while(( UEP1_CTRL & MASK_UEP_T_RES ) == UEP_T_RES_ACK);确保DMA缓冲区不被同时读写
(4)、USBH_HUB_KM.C 修改之前HUB先插入设备不能识别，必须重新插拔才能识别的问题，修正了HUB操作部分，增加支持USB打印机部分，不支持USB打印机类命令
(5)、EXAM.6修改之前只读文件几个扇区信息，改为读整个文件，强调关于不足1扇区如何读取
(6)、增加了GETID.C的例子，获取芯片唯一ID号
(7)、增加CH55X_MINIEVT_V20.DDB， CH559&CH558 L和T封装、CH557 L&Q封装PCB、原理图
(8)、更新CH559SCH.pdf
(9)、EXAM1增加修改文件名相关函数,所有U盘例程由原来支持HUB0，改成支持HUB1和HUB0
(10)、在PUB文件夹下增加脱机烧录器使用说明和PCB
(11)、修改了所有USB主机程序在设备接入后，端口重新启用的等待时间，由原来的100ms改成20-30ms 

2016-8-25改动说明：
(1)、CH55X脱机烧录器使用说明.pdf  增加USB连接消抖延时，USB方式下载LED状态变更，D3作为连接状态指示，D4作为开始下载指示

2016-11-29 改动说明：
(1)、修改CH55X_MINIEVTV13的BOM文件，串口下载口改为跟原理图一致的0欧姆。

2017-2-10 11:14
(1)、修改CH559.H解释说明的笔误。

20172017-3-6 16:40
(1)、修改CH559EVT说明和CH559SCH.PDF。
(2)、修改CH55X指令周期表，增加了DB命令和CH551/2/3/4的说明。

2018-3-2 9:56
(1)、修改CH559EVT.PDF。
(2)、删除EVT/PCB文件夹。 
(3)、修改CH559 IAP功能使用说明.pdf，更新至V1.2版本。
(4)、修改USBH_HUB_KM.C，枚举部分增加重试次数，确保USB设备枚举成功。
(5)、删除EVT/PUB/CH55X脱机烧录器 下CH55X_OFF_LINE_LOAD_V10.DDB
(6)、增加EVT/PUB/CH55X脱机烧录器/CH55X_OFF_LINE_LOAD_SCH.pdf  

2018-08-01
(1)、USB/Host目录下增加USBH_KM.C文件，其是从USBH_HUB_KM.C分离出来仅用于操作键鼠的例子。
(2)、修改USBH_HUB_KM.C文件下SelectHubPort函数，以支持HUB下低速设备的正常操作。
(3)、修改USBH_HUB_KM.C文件下main函数代码结构，插上设备自动操作而不用getkey做触发。         
(4)、删除USBH_HUB_KM.C文件下InitRootDevice函数HUB操作的部分代码。
(5)、CH559EVT.PDF更新V1.5版本，主要添加创建工程时，CH559器件的选择。
(6)、添加USBH_AOA.C文件，支持ROOTHUB下对安卓配件模式的支持。
(7)、删除旧版本脱机烧录器相关文件，新增新版脱机烧录器说明、结构图和配置软件。

2019-7-22
1、修改SPI0_Master.c、SPI0_Slv.c、SPI1_Master.c文件：
主机：下发数据，数据为0~255递增，并检测接收到的数据是否是下发数据的取反；
从机：接收数据，并将接收到的数据取反后放进SPI_DATA，等待主机来取数据。