
# SCU1048-dat

https://www.electrodragon.com/product/intermittent-switching-mosfet-module-mcu-control/

- [[N76E003-dat]] - [[LM317-dat]]

- [[mosfet-dat]] - [[AOD4184-dat]]

- [[segment-display-dat]]

[legacy wiki page](https://www.electrodragon.com/w/MCU_Relay)




## Board map 

![](2025-02-16-18-05-24.png)

board system voltage from [[LM317-dat]] == 5V 

VOUT++ == VIN++ 

VOUT-- == mosfet control ON/FF to GND 




template 

| set    | alt | pin  | pin  | alt | set     |
| ------ | --- | ---- | ---- | --- | ------- |
|        |     | P0.5 | P0.4 |     | S2=down |
|        |     | P0.6 | P0.3 |     |         |
|        |     | P0.7 | P0.2 |     |         |
|        |     | P2.0 | P0.1 |     | S3=stop |
|        |     | P3.0 | P0.0 |     |         |
| S1=set |     | P1.7 | P1.0 |     | S4=up   |
|        |     | GND  | P1.1 |     |         |
|        |     | P1.6 | P1.2 |     |         |
|        |     | VDD  | P1.3 |     |         |
| input  |     | P1.5 | P1.4 |     |         |

## SDK 

- default flashed firmware with starting counting down from 255 to 0 

![](2025-11-23-19-21-17.png)

- https://github.com/Edragon/nuvoton-app - [[private-repo-dat]]


### workflow chart 

```
START
  |
  v
main() init:
  - Set_All_GPIO_Quasi_Mode, P15_Input_Mode
  - P1SR/P0SR, UART init, display_init(), set key lines
  |
  v
+----------------------------------+
| while (1)                        |
|                                  |
|  check_boot()                    |--> (reads save_byte_3; sets test_flag)
|                                  |
|  printf("key2=%d, cfg=%d")       |
|                                  |
|  key1_scan()                     |--> (debounce; increments k1_value on K1)
|                                  |
|  key_operate()                   |--> (if K2 pressed => cycle config_flag:
|                                  |        0->1 (enter cfg1),
|                                  |        1->2 (save k1 -> k1_val1),
|                                  |        2->0 (save k1 -> k1_val2 + write flash))
|                                  |
|  boot_select()                   |--> switch(config_flag)
|       |                          |
|       |-- config_flag == 0 -------+--> route_active()
|       |                                 |
|       |                                 v
|       |                         route_active():
|       |                           - activeTime = read_APROM or test(2)
|       |                           - for count = activeTime..0:
|       |                               set_relay
|       |                               flash_display(count)  (multiplex display)
|       |                               k2_state = key2_scan()
|       |                               if k2_state==1: break (back to loop)
|       |                           - when count==0: clr_relay ; route_deactive()
|       |
|       |-- config_flag == 1 -------+--> show k1_value on display (display_digis)
|       |                           +--> k2_state = key2_scan()
|       |
|       `-- config_flag == 2 -------+--> show k1_value on display (dot=1)
|                                   +--> k2_state = key2_scan()
+----------------------------------+
  |
  v
loop back to top of while
```




## ref 

- [[MCU-relay-dat]]

- [[SCU1048]]