
# HLW8032-reg-dat.md

![](2024-12-08-16-37-50.png)

![](2025-05-21-16-43-03.png)

![](2024-12-08-16-38-09.png)

![](2024-12-08-16-38-22.png)

![](2024-12-08-16-38-54.png)

## sample data calculation for voltage 

    F2 5A 02 E1 80 00 06 52 0 3E A8 3 A6 C8 4F 9A E8 5E 79 B 61 0 1 27

**Voltage Parameter Register**

    02 E1 80 == (Dec) 188,800

![](2024-12-08-16-39-38.png)

Summing these values gives the voltage parameter register value: 131072 + 57600 + 128 = 188800

**Voltage Register Calculation**

    00 06 52 == (Dec) 1618

![](2024-12-08-16-40-36.png)

voltage register value: 0 + 1536 + 82 = 1618

Voltage Coefficient = 

    470K * 4 / 1K * 1000 = 1880K / 1000K = 1.88


**Effective Voltage Calculation**

    V_Para_Reg / V_reg * V_coefficient = 1888800 / 1618 * 1.88 = 219.372V 

Therefore, the effective voltage is approximately 219.372V.

![](2024-12-08-16-41-04.png)




## obselete 

## Hex Read

    F2 5A 02 DC D0 04 C8 20 00 3E 4E 03 7C A6 4E 2B B8 B9 8A BB 61 00 01 DC

    seperated: F2 | 5A | 02 DC D0 | 04 C8 20 | 00 3E 4E | 03 7C A6 | 4E 2B B8 | B9 8A BB | 61 | 00 01 | DC

    convert to int: 242 90 2 220 208 4 134 64 0 62 78 4 25 218 78 43 184 235 216 59 97 0 0 139

|                            | hex      | dec / int  |
| -------------------------- | -------- | ---------- |
| start                      | F2       | 242        |
| Check register             | 5A       | 90         |
| Voltage parameter register | 02 DC D0 | 2 220 208  |
| Voltage register           | 04 C8 20 | 4 134 64   |
| Current parameter register | 00 3E 4E | 0 62 78    |
| Current register           | 03 7C A6 | 3 124 166  |
| Power parameter register   | 4E 2B B8 | 78 43 184  |
| Power register             | B9 8A BB | 235 216 59 |
| Data updata register       | 61       | 97         |
| PF register                | 00 01    | 0 1        |
| CheckSum register          | DC       | 139        |

read into dec from [[hex-dat]]

    unsigned long voltageParam = ((unsigned long)vpReg[0] << 16) | ((unsigned long)vpReg[1] << 8) | vpReg[2];


## demo code 

- [[hlw8032-1.ino]]