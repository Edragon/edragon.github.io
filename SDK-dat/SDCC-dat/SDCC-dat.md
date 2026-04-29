


# SDCC-dat


## supports 

- [[CH55x-dat]] - [[8051-dat]] - [[MCU-dat]]

- [[STM8-dat]]


- [[GCC-dat]] - [[Clang-dat]]


## SDCC Supported Microcontroller List (2026)

- **Intel MCS-51 (8051)**
    - 8031, 8032, 8051, 8052
    - Silicon Labs C8051F
    - STC 89/12/15/8 Series
    - Dallas DS80C390, DS80C400
- **STMicroelectronics**
    - STM8S (Standard)
    - STM8L (Low Power)
    - STM8AF / STM8AL (Automotive)
- **Zilog & Derivatives**
    - Z80, Z180
    - eZ80 (in Z80 mode)
    - Z80N (ZX Spectrum Next)
    - Rabbit 2000, 3000, 4000
    - R800 (MSX)
- **Padauk**
    - PDK13, PDK14, PDK15
- **MOS Technology / WDC**
    - 6502, 65C02
- **Freescale / NXP**
    - HC08
    - S08
- **Sharp**
    - SM83 (Game Boy)
- **Other Targets**
    - Toshiba TLCS-90
    - Microchip PIC16/PIC18 (Unmaintained)


## SDCC (Small Device C Compiler) Toolchain Overview

The **SDCC (Small Device C Compiler)** is an open-source, retargetable C compiler suite primarily designed for **8-bit microcontrollers**. Unlike general-purpose compilers like GCC or Clang that target powerful 32-bit or 64-bit processors, SDCC is highly optimized for devices with very limited RAM, small code space, and non-standard memory architectures.

---

## 1. Core Architecture and Components
The SDCC toolchain is a collection of tools that transform C source code into a format that a microcontroller can execute (typically a `.hex` or `.bin` file).

### The Compilation Flow:
1.  **Preprocessor (sdcpp):** Handles macros, `#include` directives, and conditional compilation.
2.  **Compiler (sdcc):** The heart of the toolchain. It translates C code into assembly language for the specific target architecture. It performs heavy optimizations specifically for 8-bit constraints.
3.  **Assembler (sdas):** Converts the assembly files produced by the compiler into relocatable object files (`.rel`).
4.  **Linker (sdld):** Combines object files and library files, assigns memory addresses to variables and code, and produces the final output.

---

## 2. Supported Architectures
SDCC is the "go-to" open-source toolchain for several classic and modern 8-bit families:
* **Intel 8051:** The primary target (including variants like Silicon Labs, STC, and Dallas).
* **Zilog Z80:** Used in vintage computers, calculators, and embedded systems.
* **Maxim Tiny (TINI):** Specialized networked microcontrollers.
* **STMicroelectronics STM8:** A popular modern 8-bit MCU family.
* **Padauk:** Ultra-cheap "pennies-per-unit" microcontrollers (PDK13, PDK14, PDK15).

---

## 3. Key Features for Embedded Developers
Working with 8-bit systems requires unique features that you won't find in standard desktop C compilers:

* **Memory Models:** Since many 8-bit MCUs have banked memory (like the 8051’s `DATA`, `IDATA`, `XDATA`), SDCC allows you to use specific keywords to tell the compiler exactly where to store a variable.
* **Inline Assembler:** You can easily embed assembly code within C functions using the `__asm` and `__endasm` keywords for time-critical tasks.
* **Standard Library:** It comes with a subset of the standard C library (libc) optimized for small footprints.
* **Bit-Level Addressing:** Support for special function registers (SFRs) and bit-addressable memory, which are common in industrial MCUs.

---

## 4. Why use SDCC?
* **Open Source & Cross-Platform:** It runs on Linux, Windows, and macOS, making it a staple for open-source hardware projects.
* **No Licensing Costs:** Unlike proprietary compilers (like Keil or IAR) which can cost thousands of dollars, SDCC is free for commercial and personal use.
* **Modern C Support:** It tracks modern standards (ISO C99, C11, and some C23) much better than many older proprietary 8-bit compilers.

---

## 5. Typical Workflow Example
To compile a simple project for an 8051 microcontroller, you would typically run:

```bash
sdcc -mmcs51 main.c


## ref 



