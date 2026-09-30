
# betaflight-video-transmitter-dat




- [[betaflight-OSD-dat]] - [[betaflight-video-transmitter-dat]] - [[betaflight-dat]]


⭐️ Raceband**** + • Ch2: ⭐️ 5695


⚠️ 800mW 使用提醒

- 发热大 → 注意散热（尤其连续飞行）
- 耗电快 → 影响续航
- 室内/近距离 → 调到 25-200mW（否则干扰 + 烧毁风险）
- `Low Power Disarm = On` 是个好设置（落地不解锁时自动降功率）



## Low Power Disarm = On

但是我刚才进入OSD 发现 功率 是 25mW tramp 里面我设置的是 800mW

✅ 这是正常现象 —— 原因就是你的设置 Low Power Disarm = On

## Current Values

- Device ready - True
- VTX Type - SmartAudio 2.1 unlocked
- Band - RACEBAND
- Channel - 2
- Frequency - 5695
- Power - 400
- Pit Mode - No
- Pit Mode frequency - 0
- Low Power Disarm - On



## read table 

vtxtable

    # vtxtable
    vtxtable bands 5
    vtxtable channels 8
    vtxtable band 1 BOSCAM_A A CUSTOM  5865 5845 5825 5805 5785 5765 5745 5725
    vtxtable band 2 BOSCAM_B B CUSTOM  5733 5752 5771 5790 5809 5828 5847 5866
    vtxtable band 3 BOSCAM_E E CUSTOM  5705 5685 5665 5645 5885 5905 5925 5945
    vtxtable band 4 FATSHARK F CUSTOM  5740 5760 5780 5800 5820 5840 5860 5880
    vtxtable band 5 RACEBAND R CUSTOM  5658 5695 5732 5769 5806 5843 5880 5917
    vtxtable powerlevels 4
    vtxtable powervalues 25 200 500 800
    vtxtable powerlabels 25 200 500 800



## info 


power == 25mW / 200mW / 500mW, 100 == good starting point 

low power disarm == turn ON 


- [[betaflight-VTX-dat]] - [[betaflight-dat]] - [[betaflight-video-transmitter-dat]]

- [[FPV-fix-dat]] - [[PCB-fix-dat]] - [[betaflight-video-transmitter-dat]]

- [[betaflight-CLI-dat]] - [[betaflight-video-transmitter-dat]]



## betaflight VTX 

https://betaflight.com/docs/wiki/guides/current/VTX

VTX tables 

https://betaflight.com/assets/files/vtx_table_irc_tramp_us-8cd6f98f573d283686383f65d43f5c3a.json

https://betaflight.com/assets/files/vtx_table_smart_audio_1_0_us-5a629f4cde82aa982b5f11fb83205452.json





## ref 

- [[betaflight-dat]]