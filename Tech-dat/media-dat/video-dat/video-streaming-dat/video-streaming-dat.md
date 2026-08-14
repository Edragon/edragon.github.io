


# video-streaming-dat


- [[ivideon-dat]] == $4 per month 

- [[SRS-dat]] - [[SRT-dat]] - [[video-streaming-dat]] - [[video-dat]]



## android 

- [[android-dat]] - [[APK-dat]] 

- good to use IP webcamera 

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
