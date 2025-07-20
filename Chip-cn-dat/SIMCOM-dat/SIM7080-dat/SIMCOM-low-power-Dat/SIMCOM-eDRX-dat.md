
# SIMCOM-eDRX-dat.md


## DRX & eDRX

DRX (Discontinuous Reception Mode) can be considered a mode where downstream data can reach the terminal device at any time. Within each DRX cycle (typically set to 1.28 seconds, 2.56 seconds, 5.12 seconds, 10.24 seconds, etc.), the terminal checks for the arrival of downstream data. 

This mode is suitable for applications with relatively high latency requirements. Terminal devices in this mode are typically powered, such as those used in services like street lighting. Compared to DRX, eDRX (Extended DRX) has longer paging cycles, making the terminal more power-efficient. 

However, it also comes with longer downstream data latency (e.g., DRX values are 1.28 seconds, and 2.56 seconds, while eDRX values can go up to 20.48 seconds or even 2.9 hours). This makes it ideal for application scenarios where time constraints are not very high.



## eDRX

    AT+CEDRXS? 
    AT+CEDRXS=1 
    AT+CEDRXS=5

    AT+CEDRXRDP 
    +CEDRXRDP: 5,"0010","0010","0011" 
    
    OK 
    如果  eDRX  支持, 
    第一个“0010”  请求的 cycle length 
    第二个“0010”  网络下发的 Cycle length   
    第三个“0011”  网络下发的  PTW 
    AT+CEDRXRDP 
    +CEDRXRDP: 0 
    
    OK 
    //如果 eDRX 不支持,  返回 0. 
