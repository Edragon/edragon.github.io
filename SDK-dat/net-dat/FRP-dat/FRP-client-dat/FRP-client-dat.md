

# FRP-client-dat

- [[net-dat]] - [[openssh-dat]] - [[FRP-dat]]




## config example 

    serverAddr = "206.237.26.66"     # ← 改成你 VPS 的 IP
    serverPort = 7000                # ← 和 VPS frps 一致

    auth.method = "token"
    auth.token = "electrodragon"

    [[proxies]]
    name = "phone-cam"
    type = "tcp"
    localIP = "127.0.0.1"
    localPort = 8080                 # Android IP Camera 端口
    remotePort = 18080



## ref 

- [[FRP]] - [[FRP-client]]