
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



## ref 

- [[I2S-dat]] - [[Analog-audio-dat]] - [[TP6132-dat]]

- [[NBL1050-dat]] - [[NBL1054-dat]] - [[NBL1055-dat]]

- [[audio-dat]] - [[amplifier-audio-dat]]