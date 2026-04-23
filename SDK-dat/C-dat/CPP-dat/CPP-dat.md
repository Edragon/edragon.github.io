

# CPP-dat


## config 3 for CMSIS

- [[CMSIS-DAP]]

{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "D:/Keil_v5/Packs/ARM/CMSIS/5.9.0/CMSIS/Core/Include"
            ],
            "compilerPath": "D:\\SDK\\x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev1\\mingw64\\bin\\gcc.exe",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}


## workspace configuration json file 

    {
        "configurations": [
            {
                "name": "Win32",
                "includePath": [
                    "${workspaceFolder}/**"
                ],
                "defines": [
                    "_DEBUG",
                    "UNICODE",
                    "_UNICODE"
                ],
                "compilerPath": "D:\\SDK\\x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev1\\mingw64\\bin\\gcc.exe", 
                "cStandard": "c11",
                "cppStandard": "c++17",
                "intelliSenseMode": "windows-gcc-x64"
            }
        ],
        "version": 4
    }



## confige 2 for project 

#include errors detected. Please update your includePath. Squiggles are disabled for this translation unit (E: \Git-category\git-MCU-HDSC\MCU-HDSC-APP\APP\I2C-AHT20\source\read-data.C).C/C++(1696)

cannot open source file `"core_cmeplus.h"`(dependency of "i2c.h") c/C++(1696)

{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "E:/Git-category/git-MCU-HDSC/MCU-HDSC-APP/Device/Include",
                "E:/Git-category/git-MCU-HDSC/MCU-HDSC-APP/Drivers/Include"
            ],
            "compilerPath": "D:\\SDK\\x86_64-15.2.0-release-posix-seh-ucrt-rt_v13-rev1\\mingw64\\bin\\gcc.exe",
            "intelliSenseMode": "windows-gcc-x64",
            "browse": {
                "path": [
                    "${workspaceFolder}",
                    "E:/Git-category/git-MCU-HDSC/MCU-HDSC-APP"
                ],
                "limitSymbolsToIncludedHeaders": true
            }
        }
    ],
    "version": 4
}



