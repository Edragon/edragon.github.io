

# android-app-dat


- [[android-app-dat]] - [[ip-webcam-dat]] - [[termux-dat]]

- [[net-dat]] - [[FRP-dat]]

- [[android-dat]] - [[adb-dat]]



- [[termux-dat]] - [[tailscale-dat]] - [[FRP-dat]]


| app               | ver.          | android 13 | android 11 |
| ----------------- | ------------- | ---------- | ---------- |
| Latrix            | 1.46          | x          | x          |
| IP Webcam         |               | ok         | ok         |
| Android IP Camera | 1.19          | x          | x          |
| Android IP Camera | 1.18          | x          | x          |
| Android IP Camera | 1.17          | x          | x          |
| Android IP Camera | 1.15          | ok         | ok         |
| termux            | 0.119.0-beta3 | ?          | ok         |

- [[android-11-dat]] - [[android-13-dat]]


- [[GFW-dat]] - [[GFW]]





## shizuka == [[pixel6-dat]] ++

== [[pixel6-dat]] ++

PixelIMS cannot directly provide service for the Google Pixel 2 XL, for the following reasons:

- **Chip architecture limitation:** PixelIMS (a VoLTE enabling tool used alongside Shizuku) is developed specifically for devices powered by Google Tensor chips (Pixel 6 series and newer). The Pixel 2 XL is equipped with the Qualcomm Snapdragon 835 chip, whose underlying communication architecture is completely different from that of the Tensor chip.
- **Difference in implementation mechanism:**
  - PixelIMS works by modifying the `ICarrierConfigLoader` on Tensor-based systems to override carrier configurations.
  - On the Qualcomm-based Pixel 2 XL, forcibly modifying the baseband or enabling VoLTE/VoWiFi for a specific carrier typically requires ROOT access, along with writing MBN baseband configuration files via a [[Magisk-dat]] module or QPST / EfsTools.

- [[Magisk-dat]] - [[android-root-dat]]

- [[QPST-dat]] - [[EFSTool-dat]] - [[qualcomm-dat]]

If your Pixel 2 XL cannot use VoLTE on the current network, it cannot be resolved through the ROOT-free PixelIMS solution. The only option is to unlock the Bootloader, gain ROOT, and then flash Magisk/EfsTools-related fix modules to attempt a solution.




## ref 

