
# PCB-Castellated-Holes-dat

With the rapid development of electronic technology, electronic products are moving towards miniaturization, portability, multifunctionality, high integration, and high reliability. 

Printed circuit boards (PCBs), as the support and connectors for electronic components, often require the integration of core small carrier boards and PCBs in applications. 

For example, Bluetooth/NB-IoT modules for the Internet of Things (IoT) can be soldered onto PCBs like chips. These small carrier boards are characterized by their small size and rows of metallized half-holes along their edges. 

These metallized half-holes are used to solder the PCB to the motherboard and the component leads; this PCB manufacturing process is known in the industry as the half-hole process.

![](2026-04-18-15-01-56.png)

![](2026-04-18-15-02-20.png)

这类板边有整排半金属化孔的 PCB ，其特点是孔径比较小，大多用于载板上，作为一个母板的子板，通过这些半金属化孔与母板以及元器件的引脚焊接到一起。



■ 半孔的难点

如何控制好板边半金属化孔成型后的产品质量，如孔壁铜刺脱落翘起、残留一直是加工过程中的一个难题。如果这些半金属化孔内残留有铜刺，在插件厂家进行焊接的时候，将导致焊脚不牢、虚焊，严重的会造成两引脚之间桥接短路。



常规的生产中，半孔是先钻个圆孔再沉铜，难点是去掉另一半的孔的同时，需要保证剩下的一半孔壁有铜存在且不脱落不翘起。


无论是钻加工还是铣加工，其SPINDLE（主轴）的旋转方向都是顺时针的。当刀具加工到A点的时候，由于A点的孔壁金属化层与基材层紧密相连，因此附着在孔壁上的金属化层具有支撑，可防止金属化层在加工时的延伸以及金属化层与孔壁的分离，保证此处加工后的不会产生铜刺翘起、残留; 而当刀具加工到B点的时候，由于附着在孔壁上的铜没有任何附着力支撑，刀具向前运转时，受外力影响孔内金属化层就会随刀具旋转方向卷曲，产生铜刺翘起、残留，这些都将直接影响客户的安装及使用。



为实现上述目的，我们经过前期多次探索试验，已熟练掌握半孔工艺制作。一次钻孔经沉铜孔化后再采用二钻/锣板外形工艺，最终保留金属化孔（槽）的一半。简单的说就是板边金属化孔切一半，同时保证孔壁铜面完整导通，以便客户焊接使用，目前半孔工艺已经是很成熟的工艺！



半孔板要增加费用的原因：半孔是一种特殊工艺流程，为了保证孔内有铜，必须得工序做到一半的时候先锣边，而且一般的半孔板非常小，所以半孔板一般费用比较高，非常规设计得非常规价格。有需要做半孔的，请在下单平台选择半孔工艺。

## 非半孔工艺的隐患：

若不做半孔工艺，可能会有以下几个隐患：

1）孔内铜面卷起

2）孔内没有铜皮

3）孔边残留铜面卷起形成披峰，严重时会搭附在相邻焊盘引起短路

![](2026-04-18-15-03-59.png)

## 半孔的设计

A 半孔孔边到板边距离≥1MM

B 半孔直径大小≥0.5MM

C 半孔孔边到孔边≥0.5MM

D 半孔单边焊环0.25mm(极限0.18mm)以上，小于此参数工程会适当优化，对于半孔间焊盘间隙有要求的请下单时说明并确认生产稿

![](2026-04-18-15-05-00.png)

可以制作圆形或椭圆形半孔（其焊盘形状可以为圆形或方形），但需要留意半孔在设计中尽量焊盘向板框线内部（挂铜）区域放。

## penalization 

半孔板单板尺寸长宽≥10MM（拼板的也需要满足此尺寸），跟常规的板一样，半孔板也可以采用V割和邮票孔拼板法。

需要强调一点：半孔边不可做V割成形（因为V割会拉铜丝，造成孔内无铜），一定要锣空（CNC）成形。


![](2026-04-18-15-06-25.png)


Stamp holes panelization 

![](2026-04-18-15-07-40.png)


