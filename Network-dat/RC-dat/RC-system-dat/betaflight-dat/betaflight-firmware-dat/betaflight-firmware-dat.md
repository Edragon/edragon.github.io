

# betaflight-firmware-dat



[[mobula6-dat]] - [[FRSKY-dat]] - [[betaflight-CLI-dat]] - [[betaflight-firmware-dat]] - [[betaflight-dat]]



check version first 

    # version
    # Betaflight / STM32F411 (S411) 4.3.0 Jan 14 2023 / 13:53:38 (norevision) MSP API: 1.44

    # config: YES


1. 你的板子当前刷的是「通用统一固件（Unified Target: STM32F411）」
在 Betaflight 4.3 之后，官方把所有 F411 板子合并到了大池子 STM32F411，然后再通过硬件配置表（Config File）去挂载外设。

---

2. 致命大坑：Betaflight 4.4+ 官方已经彻底砍掉了「FrSky SPI 接收机」！⭐️⭐️⭐️

请千万注意这个关键变化：
* 早期 Betaflight 4.3（你现在的版本）还保留着 CC2500 SPI 接收机驱动。
* 从 Betaflight 4.4 开始，由于 F411 芯片 Flash 空间不足，官方源码已经彻底移除了板载 SPI FrSky / FlySky 接收机支持！
* 这就是为什么：
  * 你选择最新的 2026 / 4.4+ 固件时，Radio Protocol 里根本没有 SPI / FrSky 选项，只有 CRSF / SBUS / IBUS 这些外接串口协议！
  * 如果你强行刷入最新的 4.4+ / 4.5+ 固件，你的板载 FrSky 接收机将直接永久失效、无法对频！

---

🎯 正确操作方案（二选一）：

方案 A（最稳妥、绝不翻车）：留在 Betaflight 4.3.0 / 4.3.2
对于 1S Tiny Whoop（Mobula6）来说，4.3 版本的性能、滤波和手感已经完全足够。
* 做法：
  1. 固件版本不要选 2026/4.4+，下拉版本选择 4.3.2（或 4.3.0）。
  2. Target 依然选 STM32F411。
  3. 此时固件是完整包（无需云端定制裁切 Radio Protocol），刷完后直接把板载 CC2500 驱动带进来。
  4. 刷完进入 CLI，把原厂的 diff 配置贴回去即可。

方案 B：如果必须刷当前这个页面，Radio Protocol 怎么选？
如果你只是想测试这个固件编译：
* 在那个下拉列表（CRSF, SBUS...）里，随便选一个（比如 SBUS 或留空）。
* 但是切记：刷完后，进 Receiver 页面看有没有 SPI Rx。如果没有，就证明该版本已无 SPI 驱动，必须降级退回 4.3.2。

---

💡 强烈建议：
刷机前，务必在 CLI 里先输入 diff all 并把全部输出复制保存到本地记事本！
这是你的救命配置备份（包含了电机顺序、PID、板载 SPI 接收机的映射），一旦刷机被清空，靠这个 1 秒就能恢复。



## ref 

