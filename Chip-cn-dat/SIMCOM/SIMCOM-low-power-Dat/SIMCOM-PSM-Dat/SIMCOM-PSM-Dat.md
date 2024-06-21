
- [[SOMCOM-low-power-dat]] 


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



## Demo video 

- https://www.youtube.com/shorts/S57VZSJNvnw
- Notice in some of our modules, the pull-up resistors are costly to power, which has to be removed for best low power performance.
- Double check if your net work support PSM mode, or EDRX mode, we don't have it here (cn), so can not test

## PSM AT commands demo 

turn on/off PSM mode examples 

    AT+CPSMSTATUS=1 
    OK 
    //开启 PSM 事件上报 

    AT+IPR=115200 
    OK 
    //固定波特率 

    AT+CEREG=4 
    OK 
    AT+CEREG? 
    +CEREG: 
    4,1,"5B57","01A50B1A",9,"00",,,"11100000","1110000
    0" 
    
    OK 
    
    AT+CPSMS=1,,,"01011111","00000001" 
    OK 
    
    +CEREG: 
    1,"5B57","01A50B1A",9,"00",,,"11100000","11100000
    " 
    
    +CEREG: 
    1,"5B57","01A50B1A",9,"00",,,"00000001","11100000
    " 
    
    +CPSMSTATUS: "ENTER PSM" 
    //开启 PSM 模式，并且设置 T3412_ext  和 T3324 

    AT+CEREG? 
    +CEREG: 
    4,1,"5B57","01A50B1A",9,"00",,,"00000001","111000
    00" 
    
    OK 
    //查询网络配置的定时器 
    AT+CEREG=0 
    OK 
    //禁用网络注册 URC 
    AT+CPSMS=0 
    OK 
    //关闭 PSM 

###  PSM 和 UDP 测试用例 

    //PSM 和 UDP 测试示例 
    AT+CPSMSTATUS=1 
    OK 
    //开启 PSM 事件上报 

    AT+IPR=115200 
    OK 
    //固定波特率 

    AT+CPSMS=1,,,"01011111","00000001" 
    OK 
    
    +CPSMSTATUS: "ENTER PSM" 
    //开启 PSM 模式，并且设置 T3412_ext  和 T3324 

    +CPIN: READY 
    
    +CPSMSTATUS: "EXIT PSM" 
    //拉低 PWRKEY  从 PSM 唤醒。 
    //PSM 模式退出时上报 URC。 

    AT+CSOC=1,2,1 
    +CSOC: 0 
    
    OK 
    //建立  UDP  连接 
    AT+CSOCON=0,8309,"117.131.85.139" 
    OK 
    
    AT+CSOSEND=0,0,"Hello Light" 
    
    OK 
    
    +CSONMI: 0,28,68656C6C6F2053494D3730323045 
    
    +CPSMSTATUS: "ENTER PSM" 
    //发送数据到 UDP 服务器 
    //从 UDP 服务器接收数据 
    //如果数据传输完毕，模式将自动进入 PSM 模式 



## Sleep mode 

AT+CSCLK=1 
OK 
//进入慢时钟模式，然后拉高 DTR，模块就会进入休眠模式 
//拉低 DTR，模块会退出休眠模式 
 
 
6.4.2  方法二 
 
//sleep 模式示例 
AT+CSCLK=2 
OK 
//自动进入慢时钟模式，当没有外部设备与模块交互时，模块会自动进入休眠模式 
//发两次 AT 给模块即可唤醒模块 