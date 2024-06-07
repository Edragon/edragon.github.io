
## quectel AT 

legacy wiki page - https://w.electrodragon.com/w/Category:Quectel_AT

| CMD | enquiry or notification | Set enable | feedback       | description             | CN                                      |
| --- | ----------------------- | ---------- | -------------- | ----------------------- | --------------------------------------- |
|     | AT+CREG?                |            | 1 = registered | ge registeration status | //获得手机的注册状态                    |
|     | AT+CPIN?                |            |                |                         |                                         |
|     | AT+COPS?                |            |                |                         |                                         |
|     | ATD18576608994;         |            |                |                         | //拨打电话;  用户将其中的数字换成自己要 |
|     | AT+CBC                  |            |                |                         |                                         |
|     | +EUSIM: 1               |            |                |                         | //识别到  SIM  卡                       |
|     |                         | AT+ESLP=0  |                |                         | //禁止模块自动休眠                      |
|     | AT+CSQ                  |            | +CSQ: 24,99    |                         | //查询手机信号强度                      |



1.  拨打电话  AT  流程： 
+EUSIM: 1  //识别到  SIM  卡 
AT+ESLP=0  //禁止模块自动休眠 
AT+CSQ  //查询手机信号强度 
AT+CREG?  //获得手机的注册状态 
ATD13168091598  //拨打电话;  用户将其中的数字换成自己要
拨打的电话号码 

## 2.短信发送  AT  流程： 
+EUSIM: 1  //识别到  SIM  卡 
AT+ESLP=0  //禁止模块自动休眠 
AT+CSQ  //查询手机信号强度 
AT+CREG?  //获得手机的注册状态 
AT+CMGF=1  //设置短信格式为  TEXT  模式; AT+CMGF=0  为  PDU 模式 
AT+CMGS="13168091598"  //设置短信接收方号码 
“I love you!”  //发送短信内容 
0x1A  //发送短信结束符 

3.  GPRS  入网流程： 
+EUSIM: 1  //识别到  SIM  卡 
AT+ESLP=0  //禁止模块自动休眠 
AT+CSQ  //查询手机信号强度 
AT+CREG?  //获得手机的注册状态 
AT+EGDCONT=0,"IP","CMNET"  //设置移动网络。  CMNET,中国移动网络; UNINET,中国联通网络 
AT+ETCPIP=1,0  //设置网络连接类型 
AT+ETL=1,0,0,"122.228.19.57",29329  //设置  IP  地址、  端口号。 
AT+ETLTS=0  //连接返回  socket id，  进入透传模式 
“I love you!”  //发送内容到服务器 
+++  //发送+++退出透传模式 



## AT+CPIN

//Enter PIN
AT+CPIN?
+CPIN: SIM PIN //Query PIN code is locked
OK
AT+CPIN=1234 //Enter PIN
OK
+CPIN: READY
AT+CPIN? //PIN has already been entered
+CPIN: READY
OK





## AT+QSIMSTAT?

<enable> 
Enable or disable SIM/USIM inserted status report. If it is enabled, when SIM/USIM
card is removed or inserted, the URC: +QSIMSTAT: <enable>,<insertedstatus> 
will be reported.
0 Disable
1 Enable
<insertedstatus> 
SIM/USIM is inserted or removed. This argument is not allowed to be set.
0 Removed
1 Inserted
2 Unknown, before SIM initialization



## 13.3. AT+CBC Battery Charge
AT+CBC returns battery charge status <bcs> and battery charge level <bcl> of the MT.




## 2.22. AT+CFUN Set Phone Functionality

Parameter

<fun> 
- 0 Minimum functionality
- 1 Full functionality (Default)
- 4 Disable the phone from both transmitting and receiving RF signals
  
<rst> 
- 0 Do not reset the ME before setting it to <fun> power level. This is default when <rst> is not given.
- 1 Reset the ME. The device is fully functional after the reset. This value is available only for <fun>=1



## 7.15. AT+CLCC List Current Calls of ME




## network status 

### AT+COPS?

commands 

    AT+COPS? //Query the currently selected network operator
    +COPS: 0,0,“CHN-UNICOM”,0
    OK


AT+COPS?
+COPS: 0,0,"CHINA MOBILE",0



### AT+CREG 

AT+CREG?

+CREG: <n>,<stat>[,<lac>,<ci>[,<Act>]]

<n> 
- 0 Disable network registration unsolicited result code
- 1 Enable network registration unsolicited result code +CREG: <stat>
- 2 Enable network registration unsolicited result code with location information
+CREG: <stat>[,<lac>,<ci>[,<Act>]]

<stat> 
- 0 Not registered, ME is not currently searching a new operator to register to
- 1 Registered, home network
- 2 Not registered, but ME is currently searching a new operator to register to
- 3 Registration denied
- 4 Unknown
- 5 Registered, roaming

For NBIOT 

AT+CEREG?
+CEREG: 0,4



### 6.3. AT+CSQ Signal Quality Report




## Mobile Call 

- ATD18576608994; 
- ATD15318413464;
- ATD15575141816;