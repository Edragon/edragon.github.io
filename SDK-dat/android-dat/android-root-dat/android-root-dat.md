

# android-root-dat

- [[android-dat]] - [[ADB-dat]] - [[phone-dat]]

- [[android-root-dat]]

- [[voLTE-dat]]



- [[Magisk-dat]] - [[android-root-dat]]

- [[QPST-dat]] - [[EFSTool-dat]] - [[qualcomm-dat]]

- [[ADB-dat]] - [[android-fastboot-dat]] - [[android-recovery-dat]] - [[android-dat]]



## TWRP

Download the TWRP (TeamWin Recovery Project) file. Run it in SPECIFIC mode: https://twrp.me/Devices/, select your phone model, and download the latest img file.



## Root

Root the phone

After unlocking the Bootloader, you can root the phone. Some modules may not work due to version incompatibility. For example, the "Remove Navigation Bar" module I use does not work on Android 14, and the Fore Dark module also does not work on Android 14. It is recommended to flash stable, well-tested versions. If the phone is not your daily driver, feel free to try anything. Rooting is done with Magisk:

- [[magisk-dat]] 



1. Extract the boot.img file

Extract `boot.img` from the firmware package (it is inside the image archive within the package). Copy the `boot.img` file to your phone (I put it in the Download folder — any easy-to-find directory works).

3. Select and patch a file

Open Magisk Manager, select Install, and tap **"Select and Patch a File"**. In the file manager that appears, choose `boot.img`. This will generate a `magisk_patched_xxxx.img` file (if this step fails, it may be because you don't have proper network access, e.g., no VPN/proxy).

4. Enter bootloader mode on the phone and put the generated `magisk_patched_xxxx.img` file into the `platform-tools` folder

5. Open cmd or PowerShell inside the `platform-tools` folder and run the command: `fastboot flash boot magisk_patched_xxxx.img` and press Enter (you can also rename the file and replace the filename in the command accordingly)

6. Run the command: `fastboot reboot` and press Enter, wait for the reboot — ROOT is successful


## ref 


