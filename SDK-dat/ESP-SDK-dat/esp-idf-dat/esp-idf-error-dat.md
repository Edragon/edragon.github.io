
# esp-idf-error-dat.md

clean and rebuild 

    *  Executing task: e:\work-data\IDF_tools\tools\ninja\1.12.1\ninja.EXE  

    [0/1] Re-running CMake...CMake Error: The source directory "E:/Git-category/Git-Arduino/esp-idf-code/blink/blink2-build" does not exist.    
    Specify --help for usage, or press the help button on the CMake GUI.  
    ninja: error: rebuilding 'build.ninja': subcommand failed

    FAILED: build.ninja 
    E:\work-data\IDF_tools\tools\cmake\3.30.2\bin\cmake.exe --regenerate-during-build -SE:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-build -BE:\Git-category\Git-Arduino\esp-idf-code\blink\blink2-build\build

    *  The terminal process "e:\work-data\IDF_tools\tools\ninja\1.12.1\ninja.EXE" terminated with exit code: 1. 

---



    *  Executing task: e:\work-data\IDF_tools\tools\cmake\3.30.2\bin\cmake.exe -G Ninja -DPYTHON_DEPS_CHECKED=1 -DESP_PLATFORM=1 -B e:\Git-category\Git-Arduino\esp-idf-code\build -S e:\Git-category\Git-Arduino\esp-idf-code -DSDKCONFIG='e:\Git-category\Git-Arduino\esp-idf-code\sdkconfig' 

    CMake Error: The source directory "E:/Git-category/Git-Arduino/esp-idf-code" does not appear to contain CMakeLists.txt.
    Specify --help for usage, or press the help button on the CMake GUI.

    *  The terminal process "e:\work-data\IDF_tools\tools\cmake\3.30.2\bin\cmake.exe '-G', 'Ninja', '-DPYTHON_DEPS_CHECKED=1', '-DESP_PLATFORM=1', '-B', 'e:\Git-category\Git-Arduino\esp-idf-code\build', '-S', 'e:\Git-category\Git-Arduino\esp-idf-code', '-DSDKCONFIG='e:\Git-category\Git-Arduino\esp-idf-code\sdkconfig''" terminated with exit code: 1. 






    ModuleNotFoundError: No module named 'setuptools.command.build'

    python.exe -m pip install --upgrade pip


    C:\Users\Administrator\.espressif\python_env\idf5.0_py3.8_env

    C:\Users\Administrator\.espressif\python_env\idf5.0_py3.8_env>scripts\activate.bat

    >python -m pip install --upgrade pip setuptools wheel




    (idf5.0_py3.8_env) C:\Users\Administrator\.espressif\python_env\idf5.0_py3.8_env>python -m pip install --upgrade pip setuptools wheel
    Requirement already satisfied: pip in c:\users\administrator\.espressif\python_env\idf5.0_py3.8_env\lib\site-packages (22.3.1)
    Requirement already satisfied: setuptools in c:\users\administrator\.espressif\python_env\idf5.0_py3.8_env\lib\site-packages (65.6.3)
    Requirement already satisfied: wheel in c:\users\administrator\.espressif\python_env\idf5.0_py3.8_env\lib\site-packages (0.38.4)


    import setuptools.command.build
    ok








Extracting C:\Users\Administrator\.espressif\dist\esp32ulp-elf-2.35_20220830-win64.zip to C:\Users\Administrator\.espressif\tools\esp32ulp-elf\2.35_20220830


Creating a new Python environment in C:\Users\Administrator\.espressif\python_env\idf5.0_py3.11_env




    Using cached https://dl.espressif.com/pypi/certifi/certifi-2022.12.7-py3-none-any.whl (155 kB)
    Installing collected packages: windows-curses, reedsolo, pyserial, pygdbmi, pyelftools, msgpack, lockfile, bitstring, urllib3, six, pyyaml, pyparsing, pycparser, packaging, kconfiglib, idna, future, freertos_gdb, contextlib2, construct, colorama, charset-normalizer, certifi, tqdm, schema, requests, ecdsa, click, cffi, requests-toolbelt, requests-file, cryptography, cachecontrol, esptool, idf-component-manager, esp-coredump
    DEPRECATION: esp-coredump is being installed using the legacy 'setup.py install' method, because it does not have a 'pyproject.toml' and the 'wheel' package is not installed. pip 23.1 will enforce this behaviour change. A possible replacement is to enable the '--use-pep517' option. Discussion can be found at https://github.com/pypa/pip/issues/8559
    Running setup.py install for esp-coredump ... done
    Successfully installed bitstring-3.1.9 cachecontrol-0.12.11 certifi-2022.12.7 cffi-1.15.1 charset-normalizer-2.1.1 click-8.0.4 colorama-0.4.6 construct-2.10.68 contextlib2-21.6.0 cryptography-36.0.2 ecdsa-0.18.0 esp-coredump-1.4.2 esptool-4.4 freertos_gdb-1.0.1 future-0.18.2 idf-component-manager-1.2.1 idna-3.4 kconfiglib-14.1.0 lockfile-0.12.2 msgpack-1.0.4 packaging-22.0 pycparser-2.21 pyelftools-0.27 pygdbmi-0.9.0.2 pyparsing-3.0.9 pyserial-3.5 pyyaml-6.0 reedsolo-1.5.4 requests-2.28.1 requests-file-1.5.1 requests-toolbelt-0.10.1 schema-0.7.5 six-1.16.0 tqdm-4.64.1 urllib3-1.26.13 windows-curses-2.3.1
    All done! You can now run:
    export.bat
    PS E:\soft\Clash.for.Windows-0.20.6-win> Creating a new Python environment in C:\Users\Administrator\.espressif\python_env\idf5.0_py3.11_env


export.bat

    PS E:\esp-idf-v5.0> .\export.bat
    Checking Python compatibility
    Setting IDF_PATH: E:\esp-idf-v5.0

    Adding ESP-IDF tools to PATH...
        C:\Users\Administrator\.espressif\tools\xtensa-esp-elf-gdb\11.2_20220823\xtensa-esp-elf-gdb\bin
        C:\Users\Administrator\.espressif\tools\riscv32-esp-elf-gdb\11.2_20220823\riscv32-esp-elf-gdb\bin
        C:\Users\Administrator\.espressif\tools\xtensa-esp32-elf\esp-2022r1-11.2.0\xtensa-esp32-elf\bin
        C:\Users\Administrator\.espressif\tools\xtensa-esp32s2-elf\esp-2022r1-11.2.0\xtensa-esp32s2-elf\bin
        C:\Users\Administrator\.espressif\tools\xtensa-esp32s3-elf\esp-2022r1-11.2.0\xtensa-esp32s3-elf\bin
        C:\Users\Administrator\.espressif\tools\riscv32-esp-elf\esp-2022r1-11.2.0\riscv32-esp-elf\bin
        C:\Users\Administrator\.espressif\tools\esp32ulp-elf\2.35_20220830\esp32ulp-elf\bin
        C:\Users\Administrator\.espressif\tools\cmake\3.24.0\bin
        C:\Users\Administrator\.espressif\tools\openocd-esp32\v0.11.0-esp32-20221026\openocd-esp32\bin
        C:\Users\Administrator\.espressif\tools\ninja\1.10.2\
        C:\Users\Administrator\.espressif\tools\idf-exe\1.0.3\
        C:\Users\Administrator\.espressif\tools\ccache\4.6.2\ccache-4.6.2-windows-x86_64
        C:\Users\Administrator\.espressif\tools\dfu-util\0.9\dfu-util-0.9-win64
        C:\Users\Administrator\.espressif\python_env\idf5.0_py3.11_env\Scripts
        E:\esp-idf-v5.0\tools

    Checking if Python packages are up to date...
    Constraint file: C:\Users\Administrator\.espressif\espidf.constraints.v5.0.txt
    Requirement files:
    - E:\esp-idf-v5.0\tools\requirements\requirements.core.txt
    Python being checked: C:\Users\Administrator\.espressif\python_env\idf5.0_py3.11_env\Scripts\python.exe
    Python requirements are satisfied.

    Done! You can now compile ESP-IDF projects.
    Go to the project directory and run:

    idf.py build

    PS E:\esp-idf-v5.0>