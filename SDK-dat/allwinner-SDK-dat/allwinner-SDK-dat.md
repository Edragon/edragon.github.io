
# allwinner-SDK-dat.md

- [[xboot-dat]] - [[xfel-dat]]

- [[TINA-dat]]

## compile

![](2025-07-15-01-47-37.png)



## complier 

下载 Hello Word 文件

编译完成后需要将编译好的hello_word文件下载到开发板上运行。

传入文件可使用的方法多种多样，仁者见仁智者见智。可用的方法简传单列举：

- ADB工具
- nfs挂载文件系统
- 使用SD卡挂载

在这里推荐使用我们的ADB工具来进行传输，不需要增加多余的连接，仅仅只需要一根USB线即可。


## flash tools

（1） PhoenixSuit：基于Windows的系统的烧写工具，是最常用的烧写工具，通过数据线将PC和开发板连接，把固件烧到开发板上，支持分区烧写，适用于开发和小规模生产使用。建议开发者开发时使用该工具进行固件升级。

（2）LiveSuit：基于Ubuntu的系统的烧写工具，通过数据线将PC和开发板连接，把固件烧到开发板上，即Ubuntu版的PhoenixSuit，适用于Ubuntu系统开发者进行开发烧写。

（3）PhoenixUSBpro：基于Windows的系统的烧写工具，通过数据线将PC和开发板连接，把固件烧到开发板上，一台PC可同时连接8台设备，分别控制其进行烧写，适用于产线批量生产。（如下图）


## repo 


- https://github.com/Edragon/allwinner == [[T113-dat]]
- https://github.com/Edragon/Allwinner-V831
- https://github.com/Edragon/allwinner-nano

- https://bitbucket.org/e_dragon/allwinner-f1c200s-hdk
- https://bitbucket.org/e_dragon/allwinner-f1c200s-sdk
- https://bitbucket.org/e_dragon/allwinner-h2
- https://bitbucket.org/e_dragon/allwinner-v3s-sdk

- https://github.com/lindenis-org

- https://gitlab.com/dongshanpi/tools
- https://gitlab.com/users/dongshanpi/projects





## ref 

- [[allwinner-dat]] - [[TINA-dat]] - [[SDK-dat]]

- [[allwinner-SDK]] - [[allwinner]] - [[SDK]]