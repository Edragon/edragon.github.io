
# platform-io-dat

https://w.electrodragon.com/w/PlatformIO


create a new project in PlatformIO IDE:


platformio project structure: 


    your_project/
    ├── .pio/                  # PlatformIO build system directory (auto-generated)
    ├── .vscode/               # VS Code configuration (if using VS Code)
    ├── include/               # Header files (.h)
    │   └── your_header.h
    ├── lib/                   # Custom libraries
    │   └── your_library/
    │       ├── your_library.cpp
    │       └── your_library.h
    ├── src/                   # Source files (.cpp or .ino)
    │   └── main.cpp           # Main program entry
    ├── test/                  # Unit tests
    │   └── test_main.cpp
    ├── platformio.ini         # PlatformIO project configuration file

default code template 

    #include <Arduino.h>

    // put function declarations here:
    int myFunction(int, int);

    void setup() {
    // put your setup code here, to run once:
    int result = myFunction(2, 3);
    }

    void loop() {
    // put your main code here, to run repeatedly:
    }

    // put function definitions here:
    int myFunction(int x, int y) {
    return x + y;
    }