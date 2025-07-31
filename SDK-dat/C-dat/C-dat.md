
# C-dat


IntelliSense Configurations

${config:idf.toolsPathWin}\tools\xtensa-esp-elf\esp-13.2.0_20240530\xtensa-esp-elf\bin\xtensa-esp32s3-elf-gcc.exe

    Cannot find: d:\Espressif\tools\tools\xtensa-esp-elf\esp-13.2.0_20240530\xtensa-esp-elf\bin\xtensa-esp32s3-elf-gcc.exe

Include path

One include path per line.

${config:idf.espIdfPath}/components/**
${config:idf.espIdfPathWin}/components/**
${workspaceFolder}/**
C:/Users/flushddd/Desktop/esp32projects/esp32cam/components/cam_driver/**

    Cannot find: d:/Espressif/frameworks/esp-idf-v5.4.1/components/
    Cannot find: C:/Users/flushddd/Desktop/esp32projects/esp32cam/components/cam_driver/


- [[ccache-dat]]

command example 

    ./epd


## The 'clang-format' command is not available. Please check your clang-format.executable user setting and ensure it is installed.

clang-format.executable

This error message gets thrown at https://github.com/xaverh/vscode-clang-format-provider/blob/master/src/extension.ts#L187. It ususally appears when the clang-format extension cannot find clang-format.
It requires clang-format by LLVM in order to work. You can either download it from http://llvm.org or install it via npm install -g clang-format or through a package manager (apt, pacman, brew, nuget, dnf).

http://llvm.org/

https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8 == LLVM-18.1.8-woa64.exe

    "clang-format.executable": "C:\\Program Files (x86)\\LLVM\\bin\\clang-format.exe"

D:\Program Files\LLVM\bin\clang-format.exe

- [[MSYS2-dat]]

- [[rpi-c-dat]]

## ref 

- [[sdk-dat]]