
# vscode-dat

- [[MDK-ARM-dat]] - [[vscode-dat]] - [[C-dat]] - [[VS-CPP-dat]]



https://github.com/Microsoft/vscode-cpptools.git

C/C++ Configurations 

Include path: 

    ${workspaceFolder}/**

Extra path: 

    D:\arduino-1.8.19-windows\arduino-1.8.19\hardware\arduino\avr\libraries\**

https://github.com/Microsoft/vscode-arduino.git


https://github.com/microsoft/vscode-serial-monitor.git


example 
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "D:\\arduino-1.8.19-windows\\arduino-1.8.19\\hardware\\arduino\\avr\\libraries\\**",
                "E:\\Git-category\\Git-Arduino\\arduino-main2\\libraries\\**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64"
        }
    ],
    "version": 4
}
```



## developer extensions 

- arduino 
- platformio
- esp-idf
- C/C++ 
- Cmake 
- makefile tools 
- python - jupyter
- serial monitor 
- code runner 
- [[vs-cpp-dat]]


## setup formatter 

Option 2: Through GUI (Search)

    Go to File > Preferences > Settings

Search for “Python Formatting Provider”




## keil 

- [[MDK-ARM-dat]] - [[vscode-dat]] - [[C-dat]]


If you want to keep things simple, I recommend one of these two paths:

Path A: The `"Keil Assistant"` (Easiest)

Install the Keil Assistant extension in `VS Code`.

Point it to your UV4.exe (usually in D:\Keil_v5\UV4).

You can then open your .uvprojx file directly in VS Code and use the "Build" icon. It uses Keil’s engine but stays inside the VS Code interface.



## ref 

