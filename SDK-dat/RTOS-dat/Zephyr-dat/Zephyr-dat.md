

# Zephyr-dat

- [[git-dat]] - [[bash-dat]] - [[shell-dat]]


## install 

Download the Windows SDK package for v0.17.0 from the Zephyr SDK releases page:
https://github.com/zephyrproject-rtos/sdk-ng/releases/tag/v0.17.0

Pick the Windows x86_64 package, install or extract it to a permanent location such as:

    E:\zephyr-sdk-0.17.0

## global install 

In your Windows bash terminal, from the firmware folder:

    cd /e/git-DL/HeadTracker/firmware
    python -m pip install --upgrade pip
    python -m pip install west
    west init zephyr
    cd zephyr/zephyr
    git checkout v3.7.1
    cd ..
    west update --narrow
    west -z "$PWD" zephyr-export
    python -m pip install -r zephyr/scripts/requirements.txt
    west blobs fetch hal_espressif



## venv 

From your bash terminal:

    cd /e/git-DL/HeadTracker/firmware
    python -m venv .venv
    source .venv/Scripts/activate
    python -m pip install --upgrade pip
    pip install west
    west init zephyr
    cd zephyr/zephyr
    git checkout v3.7.1
    cd ..
    west update --narrow
    west -z "$PWD" zephyr-export
    pip install -r zephyr/scripts/requirements.txt
    west blobs fetch hal_espressif

Then install Zephyr SDK 0.17.0 for Windows into E:/git-DL/HeadTracker/firmware/zephyr-sdk. After extracting or installing it there, run its setup command from Command Prompt or PowerShell:

    E:\git-DL\HeadTracker\firmware\zephyr-sdk\setup.cmd -t arm-zephyr-eabi -t xtensa-espressif_esp32_zephyr-elf -t riscv64-zephyr-elf -h


For your current bash session, set Zephyr base before building:

    export ZEPHYR_BASE=/e/git-DL/HeadTracker/firmware/zephyr/zephyr


After that, build from the app directory:

    cd /e/git-DL/HeadTracker/firmware/src
    source ../.venv/Scripts/activate
    export ZEPHYR_BASE=/e/git-DL/HeadTracker/firmware/zephyr/zephyr
    west build -p -b dtqsys_ht


.github\workflows\build-firmware.yml

        run: |
          cd /src/firmware/src
          west build -p -b dtqsys_ht
          cp ./build/zephyr/*.bin build_bins/