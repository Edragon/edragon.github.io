
# avr-fuse-dat

AVR Fuses: The "BIOS" of Your Microcontroller

In AVR microcontrollers (like the ATmega328P used in the Arduino Uno), **fuses** are configuration bits that determine the fundamental hardware behavior of the chip. Unlike your application code, fuses are not erased when you upload a new program; they are stored in a separate, non-volatile memory space.

### 1. Key Responsibilities
Fuses tell the hardware how to "wake up" and function at a physical level. Common configurations include:

* **Clock Source Selection:** Choosing between an internal RC oscillator, an external crystal, or an external clock.
* **Clock Divider:** A factory-set fuse (`CKDIV8`) that often slows the chip down to 1MHz by default.
* **Brown-out Detector (BOD):** Triggers a reset if the supply voltage drops below a safe threshold (e.g., 2.7V or 4.3V) to prevent data corruption.
* **Bootloader Support:** Defines how much memory to reserve for a bootloader and where the execution starts after a reset.
* **Watchdog Timer (WDT):** Can be permanently enabled via fuses to reset the chip if the software hangs.

---

### 2. The Binary Logic (Important!)
AVR fuses use **inverse logic**, which is often counter-intuitive for developers:
* **0 = Programmed (Active/Enabled)**
* **1 = Unprogrammed (Disabled/Off)**

> **Note:** If you want to enable a feature, you usually set its bit to `0`.

---

### 3. Fuse Byte Structure
Most modern AVRs organize fuses into three main bytes:

| Byte              | Primary Function              | Example Impact                                 |
| :---------------- | :---------------------------- | :--------------------------------------------- |
| **Low Fuse**      | Clock settings & Startup time | Determines how fast the chip runs.             |
| **High Fuse**     | Bootloader, SPI, & Reset      | Can disable the ability to reprogram the chip. |
| **Extended Fuse** | Brown-out Detection           | Controls stability during power fluctuations.  |



---

### 4. Risks: "Bricking" the Chip
Fuses are powerful and can "brick" your microcontroller if set incorrectly:
* **Wrong Clock:** If you select an "External Crystal" but don't have one soldered to the board, the chip will have no heartbeat and will stop responding to programmers.
* **Disable Reset:** If you disable the `RSTDISBL` fuse to gain an extra I/O pin, you can no longer use standard ISP programmers to change your code.
* **Disable SPI:** Disabling the `SPIEN` fuse prevents further programming via the standard Serial Peripheral Interface.

---

### 5. How to Change Them
Fuses cannot be changed by the code running *on* the chip. You must use an external hardware programmer (like a USBasp, AVRISP mkII, or another Arduino acting as an "ArduinoISP") and software like **AVRDUDE**.

**Example AVRDUDE command to set fuses:**
`avrdude -c usbasp -p m328p -U lfuse:w:0xFF:m`




## Arduino Uno (ATmega328P) Typical Fuse Settings

The following values are the standard configuration for a 5V, 16MHz Arduino Uno:

| Fuse Byte     | Hex Value | Binary Value | Key Functions Enabled                         |
| :------------ | :-------- | :----------- | :-------------------------------------------- |
| **Low Fuse**  | `0xFF`    | `11111111`   | External Crystal (16MHz), Max Start-up Time.  |
| **High Fuse** | `0xDE`    | `11011110`   | SPI Programming Enabled, 512-word Bootloader. |
| **Extended**  | `0xFD`    | `11111101`   | Brown-out Detection (BOD) set to 2.7V.        |

---

### 1. Low Fuse (0xFF) Breakdown
The Low Fuse primarily handles the **Clock Source**. 
* **0xFF** tells the chip: "Don't use the internal oscillator; wait for an external 16MHz crystal to stabilize before starting."
* It also disables the `CKDIV8` (Divide clock by 8) bit. If this were set to `0x7F`, your 16MHz Arduino would crawl at 2MHz.



### 2. High Fuse (0xDE) Breakdown
The High Fuse manages **System features** and **Bootloader memory**.
* **SPIEN (Bit 5):** Set to `0` (Enabled) so you can program it via the ICSP header.
* **BOOTSZ (Bits 2-1):** Set to reserve 512 words (1024 bytes) for the Optiboot bootloader.
* **BOOTRST (Bit 0):** Set to `0` (Enabled) so the chip jumps to the bootloader address immediately upon power-up instead of starting the user sketch.

### 3. Extended Fuse (0xFD) Breakdown

This byte is almost exclusively for **Brown-out Detection (BOD)**.
* **0xFD** sets the threshold to **2.7V**. 
* If the power supply dips below 2.7V, the chip will force a reset. This prevents the processor from executing "garbage" instructions or corrupting EEPROM memory when the voltage is too low for stable logic.

