

# android-bootloader-dat



After unlocking the Bootloader, we can flash the device by manually flashing images.


## Enter bootloader mode

Connect the phone to the computer while it is powered on, then type `adb reboot bootloader` in cmd and press Enter. (The same command won't be listed again later.)


## Unlock bootloader

Start flashing: connect the phone and computer with a USB cable, restart the phone, then hold the "Volume Down" key to enter bootloader.

Confirm the fastboot connection is successful: open a terminal, type `fastboot devices`. If it returns `XXXXXX fastboot`, the connection is successful.

Unlock the phone: type `fastboot flashing unlock` and press Enter. On the phone, use the volume up/down keys to select "Unlock Bootloader", and confirm with the power button. When you see `Finished` in the terminal, the unlock is successful.


## Enter recovery mode for a factory reset (wipe)

In bootloader mode, use the volume up/down keys to select "Recovery" and enter the screen that shows "No command". Press and hold the power button, then tap the volume up key once to enter recovery mode. Use the volume keys to select "Wipe data/factory reset", and after completing it, return to recovery mode and select the other wipe option.

## Flashing via USB (flash factory image)

1. Connect the phone to the computer

2. Extract the flashing package (full factory image) into the `Platform-tools` folder

3. Put the phone into bootloader mode

4. Run `flash-all.bat` in the `Platform-tools` folder

5. Wait for the terminal prompts; once the phone restarts, flashing is complete

 

## Flashing via sideload (OTA upgrade)

1. Connect the phone to the computer

2. Move the OTA package to the `Platform-tools` folder (no need to extract)

3. Enter recovery mode

4. Select the "Apply update from ADB" option

5. Open cmd in the `Platform-tools` folder (or type `cmd` in PowerShell and press Enter), then run the command: `adb sideload OTA.zip` (OTA.zip refers to the full name of the downloaded OTA upgrade package)

6. Wait for the terminal prompts; once the phone restarts, flashing is complete

## ref 