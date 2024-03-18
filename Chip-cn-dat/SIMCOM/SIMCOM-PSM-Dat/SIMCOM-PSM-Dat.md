

# SIMCOM-PSM-Dat.md

## Power Supply Mode 

* 500mA @ 3.3V 
  
Test based on our current SIM7020E module 

| Module               | Current       | -   |
| -------------------- | ------------- | --- |
| Registeration Mode   | ~15mA         | -   |
| Registered Idle Mode | ~5mA          | -   |
| PSM mode             | 110 ~ 140 0uA |     |


### To enter into PSM mode
* AT+CFUN=0,0 // minimium function mode
* AT+CFUN=1,1 // full working mode
* AT+CPSMS=1  // turn on PSM mode 
  
### Quit PSM mode
* Short pulse Boot pin to leave PSM mode





## PSM 

AT+CPSMSTATUS=1 
OK 
//开启 PSM 事件上报 


AT+CPSMS=1,,,"01011111","00000001"

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


## sleep mode 
AT+CSCLK=1
OK

AT+CSCLK?
+CSCLK: 1

OK
