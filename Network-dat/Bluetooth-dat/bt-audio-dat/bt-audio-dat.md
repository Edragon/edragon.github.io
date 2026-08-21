
# bt-audio-dat 



[legacy wiki page](https://www.electrodragon.com/w/Category:BT_Audio) 

## tech 

- [[bluetooth-dat]] 

- [[amplifier-audio-dat]]



## boards 

- [[NBL1037-dat]] - [[NBL1038-dat]] - [[NBL1097-dat]]

- [[NBL1111-dat]] - [[NBL1115-dat]]





## decodec board 

- [[AMP1006-dat]] 



## chip 

- [[qualcomm-dat]] 

- [[CSR8645-dat]] - [[CSR8635-dat]] == [[NBL1050-dat]] - [[NBL1051-dat]] - [[NBL1054-dat]] - [[NBL1055-dat]]



- [[CSRA64215-dat]] == [[NBL1083-dat]] - [[NBL1084-dat]] - [[NBL1084-dat]]

- [[beken-dat]] - [[NBL1111-dat]] - [[NBL1115-dat]]

- [[JieLi-dat]]

- [[CSR8645-dat]] - [[CSR8635-dat]] - [[qualcomm-dat]] - [[BT-audio-dat]] - [[CSR8675-dat]]

- [[QCC3084-dat]] - [[QCC5181-dat]] - [[QCC5125-dat]] - [[QCC3034-dat]] - [[QCC3095-dat]] - [[QCC3094-dat]] - [[qualcomm-dat]] - [[BT-audio-dat]]


### chip compare 

| Chip Model      | Manufacturer        | Ver. | aptX          | Codec                       | Power Efficiency | Lifetime Status | Notable Features                               | Ideal Use Case               |
| --------------- | ------------------- | ---- | ------------- | --------------------------- | ---------------- | --------------- | ---------------------------------------------- | ---------------------------- |
| CSR64215        | [[Qualcomm-dat]]    | 4.2  | Yes           | SBC, AAC, aptX              | High             | EOL             | Low power, high-quality audio                  | Wireless audio devices       |
| QCC3031         | [[Qualcomm-dat]]    | 5.0  | Yes (aptX HD) | SBC, AAC, aptX HD           | High             | Active          | Advanced Bluetooth audio, low-power design     | Bluetooth audio products     |
| QCC5181         | [[Qualcomm-dat]]    | 5.2  | Yes (aptX HD) | SBC, AAC, aptX HD, LE Audio | Very High        | Active          | TrueWireless Mirroring, LE Audio support       | Modern Bluetooth headphones  |
| CSR8675         | [[Qualcomm-dat]]    | 4.2  | Yes (aptX HD) | SBC, AAC, aptX HD           | Moderate         | Active          | aptX HD, premium audio features                | High-end headphones/speakers |
| CSR8645         | [[Qualcomm-dat]]    | 4.0  | Yes           | SBC, AAC, aptX              | Moderate         | EOL             | Mid-range audio support                        | Affordable audio devices     |
| CSR8635         | [[Qualcomm-dat]]    | 4.0  | Yes           | SBC, AAC, aptX              | Moderate         | EOL             | Budget-friendly with aptX                      | Low-cost audio solutions     |
| QCC3003/QCC3008 | [[Qualcomm-dat]]    | 5.0  | Yes           | SBC, AAC, aptX, TWS+        | Very High        | Active          | TrueWireless Stereo, low power                 | Modern Bluetooth audio       |
| nRF52832        | [[Nordic-dat]]      | 5.0  | No            | SBC                         | High             | Active          | Low-energy profile, flexible for IoT and audio | IoT and general Bluetooth    |
| CC2564C         | [[TI-bt-audio-dat]] | 4.1  | No            | SBC                         | Moderate         | Active          | Dual-mode (Classic + Low Energy)               | IoT and audio solutions      |
| ATS2825         | Actions Semi        | 5.0  | No            | SBC                         | High             | Active          | Cost-effective, supports basic audio           | Budget Bluetooth devices     |
| RTL8763B        | [[Realtek-dat]]     | 5.0  | No            | SBC, AAC                    | High             | Active          | Low latency, reliable for TWS earbuds          | True Wireless Earbuds        |
| [[BK8000-dat]]  | [[beken-dat]]       |
| [[BK3266-dat]]  | [[beken-dat]]       | 5.0  |


## chip solutions 

- [[qualcomm-dat]] - [[Nordic-dat]] - [[TI-bt-audio-dat]] - [[Dialog-dat]]

CN - [[Actions-Semi-dat]] - [[RDA-dat]] - [[Beken-dat]] - [[jieli-dat]]
asia - [[airoha-dat]] - [[Realtek-dat]]

## bluetooth 5.0 

Bluetooth 5.0 does support longer range but with a 10 meters range this solution clearly does not take advantage of this new feature. Bluetooth 5 announcement did not include any specific about audio improvement, So I had a look at a Bluetooth 5 paper, and audio is mentioned three times:

- Bluetooth 5 introduces the ability to perform periodic data to be broadcast, it’s possible to chain packets and deterministic advertising, which allows scanners together and for each packet to contain a different to synchronicity their scanning for packets with the subset of the whole data set. Schedule of the advertising device. This can be a more power-efficient way to perform scanning and is also likely to pave the way for new uses of Bluetooth LE in connection-less scenarios, such as audio applications
- The Bluetooth 4 channel selection algorithm used in frequency hopping produced only 12 distinct sequences of channels and all packets in a given connection event would use the same channel, which is not optimal for some applications, such as audio. Bluetooth 5 introduced a new channel selection algorithm called channel selection algorithm #2. Hopping sequences are now pseudo random and the distinct sequences which are possible are very large.
- Bluetooth’s advertising extensions feature will pave the way for next-generation beacons, advanced audio applications and more.


## tech info 

### profile 

A2DP (Advanced Audio Distribution Profile) is a Bluetooth profile that defines how high-quality audio can be streamed from one device to another over a Bluetooth connection. It is commonly used for wireless audio streaming between devices such as smartphones, tablets, computers, and Bluetooth-enabled speakers or headphones.

### codec 

SBC stands for Low Complexity Subband Codec. It is the default, mandatory audio codec for the Bluetooth Advanced Audio Distribution Profile (A2DP), meaning every Bluetooth audio device (headphones, speakers, smartphones, and computers) supports it.

**LHDC** stands for **Low Latency High-Definition Audio Codec**. Developed by Savitech, it is a high-resolution Bluetooth audio codec designed to compete directly with Sony’s LDAC and Qualcomm’s aptX Adaptive. - [[qualcomm-dat]]


### AAC and LDAC?

- [[apple-dat]] - [[sony-dat]]

Both are popular Bluetooth audio codecs, but they serve different priorities: **AAC** focuses on efficiency and Apple ecosystem integration, while **LDAC** focuses on maximum high-resolution audio quality.

## 1. AAC (Advanced Audio Coding)
* **What it is:** A lossy compression codec standardized by MPEG. While widely used for general audio (and the default standard for Apple devices), it is also supported over Bluetooth.
* **Bitrate:** Typically streams around **250 kbps** over Bluetooth.
* **Pros:** Highly optimized for power efficiency and sound quality on iOS devices (iPhone, iPad, Mac); widely supported on Android as well.
* **Cons:** Performance varies significantly depending on the sending device's operating system and encoder implementation (Android often handles AAC less efficiently than iOS).

## 2. LDAC
* **What it is:** A high-resolution Bluetooth audio codec developed by **Sony**.
* **Bitrate:** Scales dynamically up to **990 kbps** (with lower fallback tiers of 660 kbps and 330 kbps for unstable connections).
* **Audio Quality:** Supports up to **24-bit / 96kHz** Hi-Res audio transmission.
* **Pros:** Exceptional audio detail and minimal compression artifacts; built directly into Android (version 8.0 and above).
* **Cons:** Consumes more battery and bandwidth; can suffer from stuttering or dropouts in crowded wireless environments when locked to the highest 990 kbps bitrate. Not natively supported by Apple devices.






## ref 

- [[I2S-dat]] - [[Analog-audio-dat]] - [[TP6132-dat]]

- [[NBL1050-dat]] - [[NBL1054-dat]] - [[NBL1055-dat]]

- [[audio-dat]] - [[amplifier-audio-dat]]