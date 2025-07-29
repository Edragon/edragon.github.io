
# stack-trace-decoder-dat

https://github.com/me-no-dev/EspExceptionDecoder

Unpack the tool into tools directory (the path will look like <home_dir>/Arduino/tools/EspExceptionDecoder/tool/EspExceptionDecoder.jar).


    Guru Meditation Error: Core  1 panic'ed (LoadProhibited). Exception was unhandled.

    Core  1 register dump:
    PC      : 0x400ec72f  PS      : 0x00060530  A0      : 0x800d3ba1  A1      : 0x3ffb2160  
    A2      : 0x00000000  A3      : 0x3ffb21a4  A4      : 0x00000000  A5      : 0x3ffc5c04  
    A6      : 0x00000002  A7      : 0x00000000  A8      : 0x3ffc5c04  A9      : 0x3ffb2150  
    A10     : 0x03fc3bff  A11     : 0x00000000  A12     : 0x00000000  A13     : 0x3ffb922c  
    A14     : 0x000000a8  A15     : 0x3ffc4d38  SAR     : 0x0000000e  EXCCAUSE: 0x0000001c  
    EXCVADDR: 0x0000003c  LBEG    : 0x4008a845  LEND    : 0x4008a855  LCOUNT  : 0xffffffff  


    Backtrace: 0x400ec72c:0x3ffb2160 0x400d3b9e:0x3ffb2190 0x400dea07:0x3ffb2270 0x4008d956:0x3ffb2290



PC: 0x400ec72f
EXCVADDR: 0x0000003c

Decoding stack results
