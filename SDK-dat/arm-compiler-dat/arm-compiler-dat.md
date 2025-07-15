# ARM Cross-Compiler Installation Tutorial

This guide will walk you through installing the ARM cross-compiler toolchain (version 7.2.1 as an example), configuring your environment, and testing the installation.

## 1. Download the Toolchain
You can download version 7.2.1 or choose another version as needed:

    wget http://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/arm-linux-gnueabi/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabi.tar.xz


## 2. Extract the Archive

    tar -vxJf gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabi.tar.xz


## 3. Move the Toolchain to /opt

    sudo cp -r ./gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabi /opt/


## 4. Add Toolchain to PATH

Edit `/etc/bash.bashrc` and add the following line at the end:

    PATH="$PATH:/opt/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabi/bin"


## 5. Reload Environment Variables

    source /etc/bash.bashrc


## 6. Test the Installation
Run the following command to verify the compiler is available:

    arm-linux-gnueabi-gcc -v

If you encounter issues as a regular user, try switching to the root user with `sudo su` and test again.



## ref 

- [[ubuntu-dat]]