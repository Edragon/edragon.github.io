
# HLW8032 DAT 

- [[SVC1031-dat]]

## Chip Info 

- The HLW8032 is a high precision energy metering IC that uses a CMOS manufacturing process and is primarily intended for single phase applications. It can measure line voltage and current, and can calculate active power, apparent power and power factor.
- The device integrates two ∑-Δ ADCs and a high-precision energy metering core. The HLW8032 can communicate data through the UART port. The HLW8032 uses a 5V supply, a built-in 3.579M crystal, and an 8PIN SOP package.
- The HLW8032 has the advantages of high precision, low power consumption, high reliability and strong adaptability to the environment. It is suitable for energy metering of single-phase two-wire power users.


## Hex Read 

    F2 5A 02 DC D0 04 C8 20 00 3E 4E 03 7C A6 4E 2B B8 B9 8A BB 61 00 01 DC

    seperated: F2 | 5A | 02 DC D0 | 04 C8 20 | 00 3E 4E | 03 7C A6 | 4E 2B B8 | B9 8A BB | 61 | 00 01 | DC

    convert to int: 85 90 2 220 208 4 134 64 0 62 78 4 25 218 78 43 184 235 216 59 97 0 0 139



