
# Y7080-AT-log-dat.md

## boot log 
+POWERON:0

^SIMST:0


+CGEV:ME PDN ACT 0

+CTZEU:+32,0,2024/08/01,10:45:10


## test 

+COPS:0,2,"46000",9

AT+CIMI
+CIMI:460047209708095 - This command is used to query the IMSI value of the USIM card.
+CIMI:460047209708095

AT+CGSN
MP0623208BB17E0
MP0624148A51567

- SN: The serial number of the product, also known as machine code, authentication code, registration application code, etc., is used to identify and verify the "legal identity of the product". The SN code contains a maximum of 64 characters, including digits, uppercase letters and lowercase letters.

AT+CGSN=2
+CGSN:86343106 003616 00

OK

AT+CGSN=3 - svn - The software version number is a string of 2 bytes.
+CGSN:00

OK

AT+CGSN=1 - imei - Returns the IMEI value of the board. 
+CGSN:86343106 003616 0

OK

    TAC-- Type code assigned by the device
    SNR-- Equipment serial number
    CD/SD-- If it is CD (Check Digit), it is used for verification. When SD
    (Spare Digit) is used, the default value is 0.

AT+CGMR
2212 B07 Y7080E
2212 B07 Y7080E

AT+NV=GET,EXTVER

    V1100B10012R05C1605P02


AT+CEER Extended Error reporting


AT+NPING=221.229.214.202,64,4,20,2
OK
statistics: ping num:4, reply:4, longest_rtt:792ms, shortest_rtt:564ms, average_time:654ms

statistics: ping num:4, reply:4, longest_rtt:3281ms, shortest_rtt:1684ms, average_time:2489ms

AT+CGNSSPWR=1


AT+CGNSSINFO

AT+CGNSSINFO=2

    +CGNSSINFO: 3,11,,01,03,22.5710735,N,113.8874130,E,070824,082938.00,22.5,0.609,,10.,2.3,10.

where:
    N = 22.5710735
    E = 113.8874130


AT+CGNSSTST=1

AT+CGNSSMODE=1

AT+CGNSSPROD
PRODUCT: UNICORECOMM,UC6226NIS,R3.2.10.0Build8016

PRODUCT: ,,



平台禁用休眠功能操作 AT 如下：
AT+NV=SET,EXTLOCK,0
AT+NV=SET,DEEPSLEEP,0
AT+NV=SET,STANDBY,0
AT+NV=SAVE




UC6226NIS G1L1E1 COM1
PN 080101800621
SN 20230518202010001
HWVer VE310E1
FWVer R3.4.1.0Build16190
Copyright (c), Unicore Communications Inc.
All rights reserved.