


# camera-IP-dat



- [[sensor-camera-dat]] - [[camera-wifi-dat]] - [[camera-IP-dat]] - [[camera-surveillance-dat]] 

- [[sensor-camera-dat]] - [[camera-IP-dat]]



## chip 



- [[AR0130-dat]] - [[AR0237-dat]] - [[onsemi-dat]] - [[HI3518-dat]] - [[hisilicon-dat]] - [[camera-IP-dat]]
- [[IMX122-dat]] - [[sony-dat]] - [[HI3518-dat]] - [[hisilicon-dat]] - [[camera-IP-dat]]
- [[OV9712-dat]] - [[OmniVision-dat]] - [[hisilicon-dat]] - [[camera-IP-dat]]

- [[hi3516-dat]]


- [[Fullhan-dat]] - [[HiSilicon-dat]] - [[Rockchip-dat]] - [[SigmaStar-dat]] - [[sensor-camera-dat]] - [[camera-IP-dat]]


- [[Goke-dat]] - [[chip-cn-dat]]
- [[GrainMedia-dat]]
- [[Ingenic-dat]]
- [[Novatek-dat]]

- [[IVG-G2S-dat]] - [[xiongmai-dat]] - [[camera-IP-dat]] - [[IVG-G4H-dat]]

- [[SigmaStar-dat]] - [[SSC338-dat]] - [[camera-IP-dat]]




## tech 

- [[wifi-dat]]

- [[camera-IP-dat]] == [[sensor-camera-dat]] ++ chip 

光线 → 镜头(M12) → 【图像传感器】→ MIPI/DVP → 【SoC = GK7205V210】→ H.265 → RJ45
                   1/2.9" CMOS               ISP + 编码 + 网络 + AI
                  （型号规格书没写）          国科微 Goke


| 部件             | 是什么                       | IVG-G4H 上是谁     |
| ---------------- | ---------------------------- | ------------------ |
| 图像传感器       | 光电转换（光 → 电信号）      | 1/2.9" 低照度 CMOS |
| ⚠️ 型号规格书没给 |                              |                    |
| SoC / 主控       | ISP + H.265 编码 + 网络 + AI | ⭐️ GK7205V210       |

类比：传感器 = 视网膜，SoC = 视皮层 + 语言中枢



## SOC / MCU 

| 项                     | 说明                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| 厂商                   | 国科微（Goke），湖南长沙                                                 |
| 系列                   | GK72 系列 = 视频编码芯片                                                 |
| 定位                   | ⭐️ V200 的配置微调版，「支持 400 万像素，H.265」                          记录仪 / 低分 IPC 常见 |                                                                          |
| 对标                   | 海思 Hi3516EV200 的国产替代                                              |
| 集成                   | Cortex-A7 + 自研 ISP（3DNR/WDR）+ H.265 编码器 + 以太网 PHY + 音频 codec |





## apps 

- [[openIPC-dat]] - [[HiSilicon-dat]] - [[SigmaStar-dat]] - [[Goke-dat]] - [[Ingenic-dat]]



## use guide 



Accessing a Xiongmai IVG-G4H IP Camera Over a Local Network (LAN)

**Yes, you can access it directly over your LAN** without internet access or cloud app binding. Xiongmai (XM) modules like the **IVG-G4H** generally support DHCP (or a default static IP), web management, Xiongmai's proprietary protocol (port `34567`), ONVIF, and RTSP streaming.

---

### 1. Hardware Connection and Power

1. **Power supply**: Confirm whether your IVG-G4H board includes a **PoE** module.
   - If it has PoE and your router/switch supports PoE, connect via Ethernet alone.
   - If it is a standard **DC 12V** board, supply 12V power to the module and connect the Ethernet cable to a LAN port on your router.
2. **Link LEDs**: Once powered and wired, active link/activity LEDs on the Ethernet port indicate physical layer connectivity.

---

### 2. Finding the Camera's LAN IP Address

#### Option A: Router DHCP Client List
1. Open your router admin panel in a browser (for example, `192.168.0.1` or `192.168.1.1`).
2. Check **Connected Devices / DHCP Clients** for a newly appeared wired client (often listed as `IPC`, `xm`, `unknown`, or by MAC address), and note its assigned IP (for example, `192.168.0.105`).
3. If it does not appear via DHCP, the module may be set to a **static IP** on a different subnet (such as `192.168.1.10`). Use Option B.

#### Option B: Xiongmai IP Search / Device Management Tool


1. Use Xiongmai's **DeviceManage** or **CMS** utility on a PC in the same LAN.
2. Run **IP Search** (Layer 2 broadcast discovery) to locate the camera even if its default IP is on another subnet.
3. Change its IP to a static address in your router's subnet or enable **DHCP**, then apply.

---

### 3. LAN Access Methods

Assuming the camera IP is `192.168.0.105`:

#### Web Browser Interface
- **URL**: `http://192.168.0.105` (HTTP port `80`)
- **Default username**: `admin`
- **Default password**: Often **blank** (empty password) on older/default firmware, or set during initial activation / printed on a label.
- **Browser note**: Legacy Xiongmai web UIs may rely on ActiveX plugins (IE or Edge **IE mode**). If the web video view fails in modern browsers, use RTSP or CMS/ONVIF below.

#### RTSP Stream (VLC, PotPlayer, FFmpeg)
- **Main stream**:
  `rtsp://192.168.0.105:554/user=admin&password=&channel=1&stream=0.sdp?`
- **Sub stream**:
  `rtsp://192.168.0.105:554/user=admin&password=&channel=1&stream=1.sdp?`
- Replace `password=` with `password=YOUR_PASSWORD` if a password is configured.

#### CMS Client, NVR, or ONVIF
- **Xiongmai CMS**: Add via LAN search using protocol port **`34567`** for live preview, playback, and encoding/image settings (including H.265 / H.265 AI options).
- **ONVIF**: Typically available on port **`80`** or **`8899`** for third-party NVRs, VMS software, Home Assistant, or Frigate.

---

### 4. Practical Setup Tips

- Assign a **static IP** (or router DHCP reservation) so the stream URL does not change after reboots.
- Start with standard **H.264** or **H.265** if you prioritize broad player compatibility and low latency; enable **H.265 AI** when prioritizing recording storage efficiency.


## ref 