
# QFN-dat


- [[PCB-footprint-dat]] - [[BGA-dat]] - [[QFN-dat]] - [[QFP-dat]]



## workflow 

- 引脚在底部：侧面只露出 0.1-0.2mm 的切面，烙铁逐脚焊基本不可行
- 中央散热焊盘（thermal pad）：这是最大的坑——它是块超大铜面，吸热极猛，锡量还极难控制
- 无法目检：唯一的可靠检查是 X-ray，目视只能看外侧一点 fillet


- 中央散热焊盘：绝不能整片开！整片开 = 锡太多 → 元件被顶起来浮空 + 短路
  - 正确做法：井字/网格/圆点阵列开孔，总面积只占焊盘的 40-60%
  - 这是 QFN 手工回流最常见的翻车点


## chip 

- [[hisilicon-dat]] - [[hi3516-dat]] == 20 == 416-pin FC-CSP

Hi3516C / Hi3516D / Hi3516E series

$0.65\text{ mm}$ pitch

- [[PCB-design-fanout-dat]] - [[PCB-design-dat]]

### RP2040

- [[RP2040-dat]] - [[QFN-dat]]

1. 核心封装规格封装类型： QFN (Quad Flat No-Lead，方形扁平无引脚封装)引脚数量： 56 脚 + 1 个底部散热焊盘 (Exposed Thermal Pad / Ground Pad)本体尺寸： $7\text{ mm} \times 7\text{ mm}$引脚间距 (Pitch)： $0.4\text{ mm}$



## QFN32 table 

| pin | name | note | custom |
| --- | ---- | ---- | ------ |
| 1   |      |      |        |
| 2   |      |      |        |
| 3   |      |      |        |
| 4   |      |      |        |
| 5   |      |      |        |
| 6   |      |      |        |
| 7   |      |      |        |
| 8   |      |      |        |
| 9   |      |      |        |
| 10  |      |      |        |
| 11  |      |      |        |
| 12  |      |      |        |
| 13  |      |      |        |
| 14  |      |      |        |
| 15  |      |      |        |
| 16  |      |      |        |
| 17  |      |      |        |
| 18  |      |      |        |
| 19  |      |      |        |
| 20  |      |      |        |
| 21  |      |      |        |
| 22  |      |      |        |
| 23  |      |      |        |
| 24  |      |      |        |
| 25  |      |      |        |
| 26  |      |      |        |
| 27  |      |      |        |
| 28  |      |      |        |
| 29  |      |      |        |
| 30  |      |      |        |
| 31  |      |      |        |
| 32  |      |      |        |
| pad |      |      |        |



## ref 

- [[footprint-dat]]