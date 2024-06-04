
# SIMCOM-eDRX-dat.md




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
