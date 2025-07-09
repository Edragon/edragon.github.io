
# auto-serial-dat

![](2023-11-30-17-20-37.png)

by 2x SS8050

![](2024-08-05-18-41-59.png)


- [[dual-mosfet-dat]]

| DTR | RTS | EN  | IO0 |
| --- | --- | --- | --- |
| 1   | 1   | 1   | 1   |
| 0   | 0   | 1   | 1   |
| 0   | 1   | 1   | 0   |



| Gate G1 | Source S1 | Drain D1 | Gate G2 | Source S2 | Drain D2 |
| ------- | --------- | -------- | ------- | --------- | -------- |
| DTR     | RTS       | EN       | RTS     | DTR       | IO0      |
| 1       | 1         | 1        | 1       | 1         | 1        |
| 0       | 0         | 1        | 0       | 0         | 1        |
| 0       | 1         | 1        | 1       | 0         | 0        |

## ref 

- [[serial-dat]]