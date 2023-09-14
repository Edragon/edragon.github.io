

AT+CPIN?

AT+COPS? 

ATD18576608994;

AT+CREG=?

AT+CBC


1.  拨打电话  AT  流程： 
+EUSIM: 1  //识别到  SIM  卡 
AT+ESLP=0  //禁止模块自动休眠 
AT+CSQ  //查询手机信号强度 
AT+CREG?  //获得手机的注册状态 
ATD13168091598  //拨打电话;  用户将其中的数字换成自己要
拨打的电话号码 
2.短信发送  AT  流程： 
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
AT+EGDCONT=0,"IP","CMNET"  //设置移动网络。  CMNET,中国移动网络; 
UNINET,中国联通网络 
AT+ETCPIP=1,0  //设置网络连接类型 
AT+ETL=1,0,0,"122.228.19.57",29329  //设置  IP  地址、  端口号。 
AT+ETLTS=0  //连接返回  socket id，  进入透传模式 
“I love you!”  //发送内容到服务器 
+++  //发送+++退出透传模式 