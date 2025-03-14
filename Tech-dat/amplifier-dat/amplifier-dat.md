
# amplifier-dat


## operational amplifiers (op-amps)

| Feature               | LM387                           | MCP6002                      |
| --------------------- | ------------------------------- | ---------------------------- |
| **Type**              | Low-noise audio op-amp          | General-purpose CMOS op-amp  |
| **Voltage Supply**    | ±3V to ±18V                     | 1.8V to 6V (single supply)   |
| **Bandwidth**         | ~4.5 MHz                        | ~1 MHz                       |
| **Noise Performance** | Low noise (optimized for audio) | Higher noise than LM387      |
| **Power Consumption** | Higher                          | Lower (low-power design)     |
| **Rail-to-Rail I/O**  | No                              | Yes                          |
| **Input Impedance**   | High (audio optimized)          | High                         |
| **Best for**          | Audio applications              | Battery-powered, general use |

- [[Audio-amplifier-dat]]


| Alternative Chip | Key Differences/Advantages                         |
|-----------------|----------------------------------------------------|
| **MCP6022**     | Higher bandwidth (10 MHz vs. 1 MHz), lower noise  |
| **TLV2372**     | Similar specs, slightly better bandwidth (3 MHz)  |
| **TLV9002**     | Lower power consumption, similar bandwidth (1 MHz) |
| **OPA2333**     | Higher precision, lower offset voltage            |
| **LM358**       | Similar voltage range but not rail-to-rail        |
| **TSV912**      | Lower voltage noise, better for precision applications |

- [[LM358-DAT]]


## Voltage Reference

LM258, LM358, LM358A, LM358E, LM2904, LM2904A, LM2904E, LM2904V, NCV2904

![](2025-03-14-20-49-15.png)


## Noninverting Amplifier

![](2025-03-14-20-36-11.png)




- [[DAC-dat]] - [[audio-dat]]

- [[MS6002-dat]]


## Solutions 

- [[OP07-dat]] - [[LM386-dat]]



### NS4150 

- [[NS4150-dat]]

- [[NS4150]]


## Driver 

- [[ESP32-DAC-dat]]




## ref 

- [[tech-dat]]