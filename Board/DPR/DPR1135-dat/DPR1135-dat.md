
# DPR1135 dat 


## The differences between JLink V8 and Jlink V9:

1. Different speeds: V8 supports up to 10M (JTAG debugging mode)/4M (SDW debugging mode), while Jlink V9 supports up to 20M (JTAG debugging mode)/15M (SDW debugging mode).

2. Different stability: V9's driver IC has voltage adaptive capability and can automatically adapt to the CPU voltage of the target board when the wiring is correct. All 1.8-5.5V CPUs can be debugged, while the V8 version can only debug 3.3v version of the CPU, and the stability of debugging 5vcpu is very poor.

3. JlinkV8 is easy to lose firmware and become bricked. Many V8s here have crashed. I have to re-flash the firmware, and ordinary users can only watch them become bricks, but V9 basically does not have this situation.

4. Some of the latest CPUs are no longer supported by V8, while V9 supports almost all ARM CPUs.



## Six major features of JLINK V9:

1. The main control chip uses STM32F205, and the firmware will not be lost.

2. It can provide 3.3V voltage and 0.8A current for the development board. Pin 19 outputs 5V voltage and can adapt to 1.8V-5V voltage.

3. Supports standard JTAG interface and 2-wire SWD debugging interface. The speed can reach 20M(JTAG)/15M(SWD) per second.

4. Support debugging of all ARM chips, support MDK or IAR, and other standard compilation environment IDE supported by JLink.

5. Original firmware, fully automatic firmware upgrade


## Support ICs list:

- Actel(ARM7/ARM9/Cortex Family)
- A2F200M3F,A2F500M3G,COREMP7,Cortex-M1
- Analog Devices(ARM7/ARM9/Cortex Family)
- ADuC7019,ADuC7020,ADuC7021,ADuC7022,ADuC7023,ADuC7024,ADuC7025,ADuC7026,ADuC7027,ADuC7028,
- ADuC7030,ADuC7032
- ARM(ARM7/ARM9/Cortex Family)
- Cortex-M0,Cortex-M1 (Altera),Cortex-M3
- Atmel(ARM7/ARM9/Cortex Family)
- AT91C140,AT91F40416,AT91F40816,AT91FR40162,AT91FR4042,AT91FR4081,AT91M40400,AT91M40800,
- AustriaMicroSystems(ARM7/ARM9/Cortex Family)
- AS3525
- Cirrus Logic(ARM7/ARM9/Cortex Family)
- CS740110-IQZ,CS740120-IQZ,CS740130-IQZ
- Ember(ARM7/ARM9/Cortex Family)
- EM351,EM357
- Energy Micro(ARM7/ARM9/Cortex Family)
- EFM32G200F16,EFM32G200F32,EFM32G200F64,EFM32G210F128,EFM32G230F128,EFM32G230F32,
- EFM32G230F64,EFM32G280F128
- Freescale Semiconductor(ARM7/ARM9/Cortex Family)
- MAC7101,MAC7104,MAC7105,MAC7106,MAC7111,MAC7112,MAC7114,MAC7115,MAC7116,MAC7121,
- Luminary Micro(ARM7/ARM9/Cortex Family)
- LM3S101,LM3S102,LM3S1110,LM3S1133,LM3S1138,LM3S1150,LM3S1162,LM3S1165,LM3S1332,LM3S1435,
- LM3S1439,LM3S1512
- Nuvoton(ARM7/ARM9/Cortex Family)
- NUC100LC1AN,NUC100LD1AN,NUC100LD2AN,NUC100LD3AN,NUC100LE3AN,NUC100RC1AN,NUC100RD1AN,
- NUC100RD2AN,NUC100RD3AN
- NXP(founded by Philips)(ARM7/ARM9/Cortex Family) : LH75400,LH75401,LH75410,LH75411,LH79520,LH79524,LH79525,LH7A400,LH7A404,LPC1111x101,LPC1111x201,
- LPC1112x101
- OKI Semiconductor(ARM7/ARM9/Cortex Family) ML674000,ML674001,ML674002,ML674003,ML675001,ML675002,ML675003,ML675011,ML67Q4050,ML67Q4051,
- ML67Q4060,
- ROHM(ARM7/ARM9/Cortex Family)
- BU1511KV2
- Samsung(ARM7/ARM9/Cortex Family)
- S3C2410A,S3C2440A,S3C44B0X,S3C4510B,S3F4A0KR,S3F4A1HR,S3F4A2FR,S3C6410
- Socle Technology Corp(ARM7/ARM9/Cortex Family)
- PC7130,PC7230
- STMicroelectronics(ARM7/ARM9/Cortex Family)
- STA2051,STM32F100C4,STM32F100C6,STM32F100C8,STM32F100CB,STM32F100R4,STM32F100R6,
- STM32F100R8,STM32F100RB
- Texas Instruments(ARM7/ARM9/Cortex Family)
- TMS470R1A128,TMS470R1A256,TMS470R1A288,TMS470R1A384,TMS470R1A64,TMS470R1B1M,TMS470R1B512,
- TMS470R1B768
- Toshiba(ARM7/ARM9/Cortex Family)
- TMPA900CMXBG,TMPA910CRAXBG,TMPM330FDFG,TMPM330FWFG,TMPM330FYFG,TMPM332FWUG,
- TMPM360F20FG,TMPM361F10FG
- Zilog(ARM7/ARM9/Cortex Family)
- ZA9L


## ref 

- [[DPR1135]]