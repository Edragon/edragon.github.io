


# video-streaming-dat


- [[ivideon-dat]] == $4 per month 

- [[SRS-dat]] - [[SRT-dat]] - [[video-streaming-dat]] - [[video-dat]]


- [[android-app-dat]] - [[android-dat]]


## service 

### go2rtc 

对，需要填！ go2rtc 的 streams 配置里要写手机摄像头流的具体地址，格式就是 协议://手机IP:端口/路径。



## android 

- [[android-dat]] - [[APK-dat]] 

- good to use IP webcamera 


### Android IP Camera

❌ Android IP Camera：不支持 RTMP/SRT 推流

它支持的协议：

    ✅ HTTPS 网页流：https://<IP>:4444/video/mjpeg
    ✅ H.264 流：https://<IP>:4444/video/h264
    ✅ 音频流：https://<IP>:4444/audio
    ✅ MJPEG（Frigate/Home Assistant 直接接入）

但注意：GitHub 文档里有用 go2rtc 中转的方案——本地用 go2rtc 把它的 HTTPS 流转成 RTSP 再接入监控系统（Frigate 就是这么干的）。所以：
- 直连：不支持 RTMP/SRT ❌
- 中转：可以（ go2rtc/ffmpeg 转换）⚠️ 需要额外电脑跑服务

## Larix Broadcaster

Larix Broadcaster 是最佳选择（开源、支持 SRT+RTMP、Play/F-Droid 都有）——需要我帮你下载 Larix 的 APK 吗？📥


## RTMP

test 

- rtmp://206.237.26.66:1935/live
- http://206.237.26.66:8080/live/livestream.m3u8



## SRS install on a VPS 

VLC == srt://206.237.26.66:10080?streamid=live/livestream

- [[VPS-dat]] == 206.237.26.66

https://github.com/ossrs/srs

make == ~ 255 MB 

    git clone https://github.com/ossrs/srs.git
    cd srs/trunk
    ./configure && make

and start 

    ./objs/srs -c conf/srs.conf

info 

    make[1]: Leaving directory '/root/srs/trunk'
    The build summary:
        +------------------------------------------------------------------------------------
        For SRS benchmark, gperf, gprof and valgrind, please read:
            https://ossrs.net/lts/zh-cn/docs/v7/doc/performance
        +------------------------------------------------------------------------------------
        |The main server usage: ./objs/srs -c conf/srs.conf, start the srs server
        |     About HLS, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/hls
        |     About DVR, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/dvr
        |     About SSL, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/rtmp-handshake
        |     About transcoding, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/ffmpeg
        |     About ingester, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/ingest
        |     About http-callback, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/http-callback
        |     Aoubt http-server, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/http-server
        |     About http-api, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/http-api
        |     About stream-caster, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/streamer
        |     (Disabled) About VALGRIND, please read https://github.com/ossrs/state-threads/issues/2
        +------------------------------------------------------------------------------------
    binaries, please read https://ossrs.net/lts/zh-cn/docs/v7/doc/install
    You can:
        ./objs/srs -c conf/srs.conf
                    to start the srs server, with config conf/srs.conf.

run log 

    root@VM46294:~/srs/trunk# ./objs/srs -c conf/srs.conf
    [2026-08-14 19:37:13.057][INFO][13755][k0nfd920] XCORE-SRS/8.0.22(Kai)
    [2026-08-14 19:37:13.059][INFO][13755][k0nfd920] config parse complete
    [2026-08-14 19:37:13.059][INFO][13755][k0nfd920] you can check log by: tail -n 30 -f ./objs/srs.log
    [2026-08-14 19:37:13.059][INFO][13755][k0nfd920] please check SRS by: ./etc/init.d/srs status


fix one error 

    root@VM46294:~/srs/trunk# ulimit -n 10000
    root@VM46294:~/srs/trunk# ./etc/init.d/srs start
    Starting SRS...                                            [  OK  ]
    SRS started(pid 14036)                                     [  OK  ]
    root@VM46294:~/srs/trunk# ./etc/init.d/srs status
    SRS(pid 14036) is running.                                 [  OK  ]

tail -n 30 -f ./objs/srs.log

## SRT 

SRT == srt://206.237.26.66:10080?streamid=live/livestream&mode=caller&latency=5000000

With SRS running natively on your VPS, point your outdoor 4G camera app to your server:

Protocol: `SRT`

Mode: `Caller (Push)`

URL: `srt://206.237.26.66:10080?streamid=live/livestream`


## view 

You can then open [[VLC-dat]] player anywhere in the world, use `Open Network Stream`, and paste that exact URL to watch your live feed!


## ref 

- [[video-streaming]] - [[video]] - [[media]]
