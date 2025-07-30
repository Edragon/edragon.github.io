
# esp-idf-error-dat.md

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




