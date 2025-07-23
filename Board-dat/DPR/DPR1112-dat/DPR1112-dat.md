
# DPR1112-dat 


- Provides 3.3V and 1.8V dual power output, easy to use!
- Added SPI level switching function, supporting 3.3V and 1.8V (exclusive to the voltage switching version)!
- Added PTC current-limiting protection, with a current limit of 500MA, so you don’t have to worry about wrong connections or short circuits (exclusive to the voltage switching version)!
- ach writer has a unique ID number
- Driver, burning tool, manual download address: www.cisdo.cn/post/5.html (copy the link to open in a new window)


## Pin Definitions 

- ● MISO, CLK, CSB, and CLK are SPI programmer interfaces, which are connected to the SPI interface of the CSR Bluetooth chip in one-to-one correspondence. The default SPI level is 1.8V!
- ● 3V3 and 1V8 are reserved power outputs, which can provide a current of no more than 500MA (it will be automatically protected if it exceeds 500MA)!
- ● VS is the SPI voltage selection port. When VS is left floating (there is an internal pull-up), the SPI level is 1.8V. When VS is grounded, the SPI level is 3.3V!

## Supported Chips 

- ● BC2 series (such as BC215159A, etc.)
- ● BC3 series (such as BC31A223, BC358239A, etc.)
- ● BC4 series (such as BC413159A06, BC417143B, BC419143A, etc.)
- ● BC5 series (such as BC57F687, BC57E687, BC57H687C, etc.)
- ● BC6 series (such as BC6110, BC6130, BC6145, CSR6030, BC6888, etc.)
- ● BC7 series (such as BC7820, BC7830, etc.)
- ● CSR86xx series (such as CSR8605, CSR8610, CSR8615, CSR8620, CSR8630, CSR8635, CSR8640, CSR8645, CSR8670, CSR8675, etc.)
- ● CSRA63/CSRA64 series (such as CSRA64110, CSRA64210, CSRA64215, etc.)
- ● CSR10 series (such as CSR1000, CSR1001, CSR1010, CSR1011, CSR1012, CSR1013, etc.)
- ● CSRB5 series (such as CSRB5341, CSRB5342, CSRB5348, etc.)
- ● QCC300x series (QCC3001~QCC3008 series)

## ref 

- [[CSR-dat]]

- [[DPR1112]]