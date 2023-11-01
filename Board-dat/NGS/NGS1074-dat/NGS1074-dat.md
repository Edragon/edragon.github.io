# NGS1074-dat

- retired


GIF demo please see here [[SIM800_RTU_Test.gif]]

## Features

- UART1 - for data transfer and parameter setting
- UART2 - for standard AT command communication
- The baud rate is 115200, 8bit data, 1bit stop, no parity
- NETLIGHT PIN - is used to indicate the network registration status
- STATUS PIN - is used for power on indication, high level is for power on

## Descriptions

- Based on R2 hardware.
- Customized firmware, connect to specified server by TCP or UDP
- Data send to UART1 will be directly forward to server.
- Setup once and done, please see configuration here.

## Mode

- To enter AT command mode, first enter into commands mode by +++
- confirm password by AT+DTUW=900,12345678
- after setup, save configuration by AT+DTUW=999
- exit commands mode and enter into data mode by ATO

| Commands                     | read        | write                       |
| ---------------------------- | ----------- | --------------------------- |
| password                     | -           | AT+DTUW=900,12345678        |
| APN                          | AT+DTUR=1   | AT+DTUW=1,CMNET             |
| Link Status                  | -           | AT+DTUS                     |
| IP address                   | AT+DTUR=102 | AT+DTUW=102, 167.88.114.101 |
| Port                         | AT+DTUW=103 | AT+DTUW=103,9999            |
| Save                         |             | AT+DTUW=999                 |
| exit commands mode           |             | ATO                         |
| Fail times                   |             | AT+DTUW=921,3               |
| Restart Module if still fail |             | AT+DTUW=922,1               |
| enter into commands mode     |             | +++                         |

### SMS Usasge 

The format is: $SMS number # SMS content SMS$ (Do not add any characters after SMS$)

    E.g:  $SMS10086#Test SMS SMS$

When a text message is received, it will be output through the serial port in the same format as the text message sent:

    $SMS number # SMS content SMS$

The content of the SMS is GBK code. On Chinese computers, the default is GBK code.<br>

Write the MCU program can be written directly like this:

    Sprint(buffer,"$SMS%s#%sSMS$", "10086", "Test SMS");



