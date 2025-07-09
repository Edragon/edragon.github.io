
# M2M Interface 

## common pin definitions 


| Pin  | Functions                                    |
| ---- | -------------------------------------------- |
| VBUS | Power supply from USB port                   |
| VIN  | Power input up to ~18V                       |
| 3V3  | on board 3.3V LDO output                     |
| DTR  | UART DRT pin                                 |
| ~RI  | UART RI pin                                  |
| RXD  | UART receive via logic shifter                  |
| TXD  | UART send via logic shifter               |
| PEN  | on board dcdc power supply enable default on |
| GND  | board power supply ground                    |
| RST  | gpio_control_reset                           |



- [[A7670-dat]] - [[NGS1131-dat]] - [[NGS1141-dat]]


## obseleted 

| pin        | function                       |
| ---------- | ------------------------------ |
| 3v3 or bat | direct system power supply     |
| vin        | external high voltage supply   |
| gnd        | Power Ground                   |
| p_en       | on board power chip enable pin |
| logic_pwr  | logic power level supply       |
| rx         | RXD                            |
| tx         | TXD                            |
| boot       | M2M module boot pin            |
| ..         | ..                             |


## ref 

- [[M2M-dat]]