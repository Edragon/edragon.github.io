
# EY-25M-dat

[legacy wiki page](https://www.electrodragon.com/w/EY-25M)


- 电源（1.8-3.6V）
- baudrate default 9600bps 


## boards 


![](2024-05-15-18-59-17.png)

- [[NBL1101-dat]] - [[NBL1107-dat]]

## Pins 

| Pin | Definition | Function                 | Description                                                   |
| --- | ---------- | ------------------------ | ------------------------------------------------------------- |
| 1   | TXD        | Serial port              | Serial output, the level is TTL level                         |
| 2   | RXD        | Serial port              | Serial input, the level is TTL level                          |
| 3   | NULL       | Null                     | -                                                             |
| 4   | NULL       | Null                     | -                                                             |
| 5   | KEY5       | Input 5                  | inputs*                                                       |
| 6   | KEY4       | Input 4                  | inputs*                                                       |
| 7   | KEY3       | Input 3                  | inputs*                                                       |
| 8   | KEY2       | Input 2                  | inputs*                                                       |
| 9   | NULL       | Null                     | -                                                             |
| 10  | KEY1       | Input 1                  | inputs*                                                       |
| 11  | RESET      | Reset                    | Low level reset, high level working (high level if suspended) |
| 12  | VCC        | Power Supply             | Supply（1.8-3.6V）                                            |
| 13  | GND        | GND                      | Power ground                                                  |
| 14  | PWRC       | Sleep wake pin           | PWRC descriptions*                                            |
| 15  | ALED       | Broadcast LED indication | LED_status*                                                   |
| 16  | STAT       | Connection status        | status*                                                       |
| 17  | OUTPUT5    | Output 5                 | outputs*                                                      |
| 18  | NULL       | Null                     | -                                                             |
| 19  | NULL       | Null                     | -                                                             |
| 20  | NULL       | Null                     | -                                                             |
| 21  | NULL       | Null                     | -                                                             |
| 22  | OUTPUT1    | Output 1                 | outputs*                                                      |
| 23  | OUTPUT2    | Output 2                 | outputs*                                                      |
| 24  | OUTPUT3    | Output 3                 | outputs*                                                      |
| 25  | OUTPUT4    | Output 4                 | outputs*                                                      |

* outputs = Default low level, support serial instruction control and input KEY pin control in network state 
* status = In non mesh mode, low level if not connected, high level after connection In mesh mode (output high level if connect to network successfully, if not, output low level)
* inputs = inputs
* PWRC descriptions = Support PWRC pin wake-up in deep sleep state, and AT instruction sending is supported when the connection status is pulled down
* LED_status = In non mesh mode (flash if not connected, light on after connection)

## AT commands 

| Num. | CMD          | Funcs                               | Default          |
| ---- | ------------ | ----------------------------------- | ---------------- |
| 1    | AT           | 测试指令                            | -                |
| 2    | AT+RESET     | 复位                                | -                |
| 3    | AT+VERSION   | 固件版本                            | -                |
| 4    | AT+LADDR     | 读 MAC 地址                         | -                |
| 5    | AT+NAME      | 广播名读写                          | EY-25M          |
| 6    | AT+PIN       | 连接密码设置                        | 123456           |
| 7    | AT+TYPE      | 是否打开密码连接方式                | 0                |
| 8    | AT+BAUD      | 波特率                              | 9600             |
| 9    | AT+DISC      | 断开连接                            | -                |
| 10   | AT+STAT      | 读取连接状态                        | 0                |
| 11   | AT+STARTEN   | 开机睡眠设置                        | 1                |
| 12   | AT+ADVIN     | 广播间隔                            | 1                |
| 13   | AT+POWR      | 发射功率                            | 3                |
| 14   | AT+ROLE      | 工作模式设置                        | 0                |
| 15   | AT+SLEEP     | 睡眠指令                            | -                |
| 16   | AT+DEFAULT   | 恢复出厂配置                        | -                |
| 17   | AT+INQ       | 主机搜索从机广播                    | -                |
| 18   | AT+STOP      | 停止广播                            | -                |
| 19   | AT+CONN      | 连接扫描列表 ID 号                  | -                |
| 20   | AT+CONA      | 指令 MAC 地址连接                   | -                |
| 21   | AT+BAND      | 绑定从机 MAC 地址                   | -                |
| 22   | AT+CLRBAND   | 清除绑定                            | -                |
| 23   | AT+SRBAND    | 连接周边信号最强的从机              | -                |
| 24   | AT+MESH      | MESH 发数据                         | -                |
| 25   | AT+KEY       | 按键参数配置                        | -                |
| 26   | AT+NETID     | 组网 ID 号配置                      | 1189             |
| 27   | AT+MADDR     | 组网短地址                          | MAC 地址后两位   |
| 28   | AT+MCLSS     | 组网设备类型                        | 0（路由器）      |
| 29   | AT+FRIEND    | 添加私密朋友 MAC 地址               | 000000000000     |
| 30   | AT+CLRFRIEND | 清除朋友                            |
| 31   | AT+FRTYPE    | 朋友类型                            | 0                |
| 32   | AT+IBUUID    | iBeacon 的 UUID 配置                |
| 33   | AT+MAJOR     | iBeacon 的 MAJOR 配置               | 000A             |
| 34   | AT+MINOR     | iBeacon 的 MINOR 配置               | 0007             |
| 35   | AT+IBSING    | iBeacon 的 SING 配置                |
| 36   | AT+ENLOG     | 串口输出状态开关                    | 1（开）          |
| 37   | AT+DATA      | 从机多连发数据指令                  |
| 38   | AT+CUIO      | 串口设置当前模块输出 IO电平         |
| 39   | AT+TGIO      | 主机通信时主机控制从机输出 IO电平   |
| 40   | AT+FUNC      | 主机设置从机无线参数                |
| 41   | AT+SUBTYPE   | 子功能类型（路由模式有效）          | 0                |
| 42   | AT+LEARN     | 学习开关                            | 0                |
| 43   | AT+LEAVAL    | 输出 IO 学习参数                    | 0,0,0000         |
| 44   | AT+DEVCLSS   | 用于一键主机连接周边信号最强的从机  | 0                |
| 45   | AT+KLABEL    | 添加标签地址 (支持 10 个标签)       | 0,0,000000000000 |
| 46   | AT+KLTIME    | 设置标签超时时间                    | 3s               |
| 47   | AT+KLRSSI    | 设置标签灵敏度 （用于接收范围设置） | 99               |
| 48   | AT+ALED      | 广播 LED 开关                       | 1                |


## examples 

| category   | Operations                                | Send                                         | feedback                                                     |
| ---------- | ----------------------------------------- | -------------------------------------------- | ------------------------------------------------------------ |
| Networking | AT+MADDR - get broadcasting short address | AT+MADDR                                     | +MADDR=0733                                                  |
| Networking | AT+MESH - broadcasting data               | 41 54 2b 4d 45 53 48 00 ff ff 11 22 33 0d 0a | 4F 4B 0D 0A F1 DD 07 07 33 FF FF 11 22 33 (4F 4B 0D 0A = OK) |
|            |                                           | AT+PIN                                       | +PIN=123456                                                  |
|            |                                           | AT+STAT                                      | +STAT=0                                                      |
|            |                                           | AT+POWR                                      | +POWR=4                                                      |
|            |                                           | AT+ROLE                                      | +ROLE=5                                                      |
|            | set/enquiry --MESH network ID number      | AT+NETID                                     | +NETID=1189                                                  |
| Networking | check networking types                    | AT+MCLSS                                     | +MCLSS=0                                                     |
|            | mesh friend                               | AT+FRIEND                                    | +FRIEND=000000000000                                         |
|            |                                           | AT+IBUUID                                    | +IBUUID=FDA50693A4E24FB1AFCFC6EB07647825                     |
|            |                                           | AT+ENLOG                                     | +ENLOG=1                                                     |
|            |                                           | AT+CUIO                                      | +CUIO=0,0,0,0,0,                                             |


## UUID 

UUID List

| type                | uuid | note                                                                                                                                |
| ------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------------------- |
| Service UUID        | FFE0 | (Service UUID)                                                                                                                      |
| Characteristic UUID | FFE1 | (for pass-through data)                                                                                                             |
| Characteristic UUID | FFE2 | (for pass-through data)                                                                                                             |
| Characteristic UUID | FFE3 | (for MESH data transmission and reception, MESH command transmission and reception, APP control of IO, and parameter configuration) |


### APP commands 

### # APP 透传 （使用特征 UUID：FFE1）

0XFFE1 为 APP 透传特征 UUID（应用于 IOS、Android 或微信小程序通信）

#### APP 向 MESH 发送数据或指令 （使用特征 FFE3）

数据格式 HEAD(2byte) + CMD(1byte) + MADDR(2byte) + data(1-16byte)

    例子 1：APP 向所有设备广播数据：31323334353637383930
    指令 1：F101 00 FFFF 31323334353637383930
    例子 2：APP 向 0008 设备串口发送 1122334455 数据
    指令 2：F101 00 0008 1122334455
    例子 3：APP 将所有模块的 OUT1 引脚设置成高电平
    指令 3：F101 10 FFFF AAB1E70101
    例子 4：APP 将 0008 模块的 OUT1 引脚设置成低电平
    指令 4：F101 10 0008 AAB1E70100
    例子 5：APP 读取 0008 模块的所有 OUT 引脚电平
    指令 5：F101 31 0008 F0B100
    例子 6：APP 读取 0008 模块的所有 INPUT 引脚电平
    指令 6：F101 31 0008 F1B101


## FAQ 

If the transmission distance is relatively long, will it extend the network transmission distance if EY-24M/25M is placed every several dozen meters?
- Answer: Yes

![](2024-06-07-15-11-10.png)

Example: A needs to send data to (C, D, E, F). Due to the long distance, A's signal cannot reach (C, D, E, F). Here, a device B needs to be placed between A and C to solve the communication distance problem between A and C.



## Applications 

### Mesh mode 

#### broadcasting to control the IO of all nodes

- Configure the network NETID to 1122: AT+NETID1122
- Configure the current device short address to 0005: AT+MADDR0005

- Configure the current KEY1 broadcast to control the OUT3 output IO of all devices in the network: AT+KEY1,0008,3,1
- Send AT+RESET again to restart and take effect. At this time, KEY1 can control the output IO level of all OUT3 in the network

low power mode options 
- Configure the device as a low-power terminal node: AT+MCLSS1
- In low-power mode, the current is 3uA, the key is pressed to send data, and the key is released to enter deep sleep

#### broadcasting to send data to all nodes

- Configure the network NETID to 1122: AT+NETID1122
- Configure the current device short address to 0005: AT+MADDR0005
- Configure the device as a routing node: AT+MCLSS0
- Configuration takes effect after restart

Broadcast 1122334455 data to all devices (FF FF) on the network, send the following instructions

    41 54 2b 4d 45 53 48 00 FF FF 11 22 33 44 55 0D0A

Send 1122334455 data to device 0008 (00 08) in the network, the instructions are as follows

    41 54 2b 4d 45 53 48 00 00 08 11 22 33 44 55 0D0A

Control the OUT1 pin of target 0008 to be low level, and there is an ACK response, the instructions are as follows

    41 54 2b 4d 45 53 48 11 00 08 AA B2 E7 01 00

## ref 

- [[BLE-dat]]


- [[EY-25M Super Bluetooth Module Manual.pdf]]

- [[EY-dat]]