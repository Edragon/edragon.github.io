


# NAS-dat



- [[NAS-dat]] - [[RK3566-dat]]



- [[NAS-dat]] - [[ethernet-dat]] - [[RK3566-dat]] - [[rockchip-dat]]

- [[conn-RJ45-dat]] - [[NAS-dat]] - [[ethernet-dat]] -


- [[mSata-dat]] - [[interface-dat]] - [[sata-dat]]

- [[DCDC-down-dat]] - [[power-dat]]


- [[logic-level-shifter-dat]] 


- [[USB-PD-dat]] - [[USB-hub-dat]] - [[USB-SDK-dat]] - [[CONN-USB-dat]] - [[impedance-USB-dat]] - [[USB-2.0-dat]] - [[USB-3.0-dat]]

- [[wifi-sdio-dat]] - [[RTL8211-dat]]

## HDK 

以太网芯片和RJ45芯片之间的距离尽可能的近，距离一般不超过5inch

led信号管脚加粗至少10mil以上

变压器引出接地脚至少加粗10~20mil

高速信号换层时需要再附近不超过200mil打地孔增加回流

MDI信号需要对内差分等长，不需要对外等长。MDI差分100Ω

RGMII信号的发送信号和接收信号不要混合走线，一般同层走线靠近一起走线

且分别要进行组内等长，单线阻抗50Ω 走线总长度推荐小于2inch，最长不超过6inch

MDI走线总长度应小于2inch

MDIO和MDC信号是配置寄存器用的，你可以理解为I2C不需要特殊走线处理，随便布

MCLKINOUT 时钟信号线在布线的时候请与其他信号线保持间距并有条件打地孔包裹处理

看完上面的理论部分，简要分析下笔者设计中的要点

四根MDI差分对要保持组内等长，对外不强制必须等长。




## ref 

- [[NAS]] - [[APP]]