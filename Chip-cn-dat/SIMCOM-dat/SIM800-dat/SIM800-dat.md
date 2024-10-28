# SIM800-dat

legacy wiki page - https://www.electrodragon.com/w/Category:SIM800



## boards

- [[NGS1055-dat]] - [[NGS1056-dat]]


- [[NGS1070-dat]] - [[NGS1071-dat]] - [[NGS1072-dat]] - [[NGS1074-dat]]

## Versions

| Version  | Flash | LBS | Bluetooth 3.0 | TTS | 2-DEV |
| -------- | ----- | --- | ------------- | --- | ----- |
| V_Basic  | 24M   | -   | -             | -   | -     |
| V_LBS+BT | 24M   | YES | YES           | -   | -     |
| V_TTS    | 32M   | YES | YES           | YES | ?     |
| V_MCU    | 32M   | YES | YES           | ?   | YES   |

- LBS = AGPS, LBS (loaction)
- 2-DEV = Secondary Development




## Serial Number Versions

| PN             | Specs              | Note                           | AT+GMR              | Split Data              | Test with CN Mobile | Test with CN Unicorn |
| -------------- | ------------------ | ------------------------------ | ------------------- | ----------------------- | ------------------- | -------------------- |
| S2-1068S-ZIL1D | 24M, basic version | 1068S                          | 1418B06SIM800C24    | 1418B 06 SIM800C24      | +CREG: 0,3          | 0 / 2 loop           |
| S2-10686-ZIL19 | 24M+BT             | 10686 stopped                  | 1418B07SIM800C24_BT | 1418B 07 SIM800C24 \_BT | +CREG: 0,1          | 0 / 2 loop           |
| S2-10686-ZIL1E | 24M+BT             | 10686                          | 1418B08SIM800C24_BT | 1418B 08 SIM800C24 \_BT | +CREG: 0,1          | 0 / 2 loop           |
| S2-1068F-ZIL1E | 24M+BT             | 10686                          | 1418B08SIM800C24_BT | 1418B 08 SIM800C24 \_BT | +CREG: 0,1          | 0 / 2 loop           |
| S2-10686-ZIL0T | 24M+BT             | 10686                          | ?                   | ?                       | ?                   | ?                    |
| S2-10688-ZIL0S | EAT version        | 10688 (series are EAT version) | -                   |                         |                     |                      |
| S2-10698-ZIL0S | EAT version        | 10688 (series are EAT version) | -                   |                         |                     |                      |



## docs 

- [[SIM808-dat]] - [[SIMCOM-dat]]

- [[SIM800 Series_GNSS_Application Note V1.00.pdf]] - [[SIM800_Series_AT_Command_Manual_V1.07.pdf]]

