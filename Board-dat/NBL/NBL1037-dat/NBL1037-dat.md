
# NBL1037-dat 


read more at - [[NBL1037-FAQ-dat]] - [[BK8000-dat]]

- new module instead [[BK3266-dat]]


BK8000L Bluetooth Audio+ SPP Module, v2.1,

https://www.electrodragon.com/product/eb8000-bluetooth-audio-module-bt_v2-1/


- [Very comprehensive documentation can see on this page.](https://www.electrodragon.com/w/EB8000_Audio_Bluetooth_Module#Basic_Application_Circuit)



## Boards 

- core board - [[NBL1037-dat]]
- convert board documentation - [[NBL1038-dat]]
- [mini development board here. ](https://www.electrodragon.com/product/bk8000d-bt-bluetooth-spp-audio-hpf-player/) - [[NBL1097-dat]]




## suitable amplifier 


* Earphone - SGM4812 (132mw)
* [HT6872 (4ohm 3W)](https://w2.electrodragon.com/gollum/search?q=HT6872) - [[AMP1021-dat]]
* HT8696 (4ohm 10W)
* [PAM8610 (8ohm 10W&4ohm 15W)](https://www.electrodragon.com/product/210w-dual-channel-hifi-mini-audio-amplifier-pam8610/) - [[AMP1000-dat]]

* TDA7737-dat 

## hardware design notes 

- Module application process, please pay attention to avoid the impact of interference sources amplifier, boost lines, etc. on the module, the module power supply circuit to avoid the formation of a series circuit with the power circuit unit, in order to improve overall SNR.
- About wireless Bluetooth environment, including Bluetooth wireless signals are greatly affected by the surrounding environment, such as trees, metal and other obstructions the wireless signal will have some absorption, so in practical applications, distance data transmission by certain influences.
- Since Bluetooth module should be supporting existing systems, placed in the housing. Since the metal casing of the radio frequency signals are shielded effect. It is not recommended to be installed in a metal housing.
- PCB layout: the antenna is part of the Bluetooth module PCB antenna, since the metal will weaken the function of the antenna, in layout to the module when the module antenna to the following non-paved and traces, if hollowed out better.
- **Amplifier LM386, PAM8403, etc need isolated ground, otherwise will have a lot noise. Recomandded HT6782**



## Demo 

- [Demo video 1 please see on this page.](https://www.youtube.com/watch?v=OmE9uVmMsgA)
- [Demo video 2 using with TDA7377 AMP board.](https://www.youtube.com/watch?v=UrPl5gYwG1w)
- [Demo video 3 using with LM386, rough test](https://www.youtube.com/watch?v=izWYJiukZbo)
- [Demo video 4 – SPP AT commands test.](https://www.youtube.com/watch?v=m3IJFxKQyt0)
- [New demo video – streaming and AT control here.](https://www.youtube.com/watch?v=z4KTndMXxmM)


## ref 

- [BT Audio selection guide see here.](https://www.electrodragon.com/w/Category:BT_Audio)


- [[BK8000-dat]] - [[BEKEN-dat]] - [[HT6872-dat]] - [[PAM8610-dat]]