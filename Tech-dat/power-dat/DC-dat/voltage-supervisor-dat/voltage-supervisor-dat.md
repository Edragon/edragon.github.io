
# Voltage supervisor ICs


### 1. MAX809 / MAX810 Series
- **Purpose**: Voltage supervisor ICs for battery monitoring.
- **Features**:
  - Monitors voltage and generates a reset signal when voltage drops below a set threshold.
  - Available in SOT23-3 package.
  - Extremely low quiescent current (ideal for battery applications).
  - Fixed threshold voltages (e.g., 2.5V, 3.0V, 3.3V, etc.).
- **Application**: Battery-powered devices, microcontroller reset circuits.

---

### 2. TLV803 / TLV809 Series (Texas Instruments)
- **Purpose**: Voltage supervisor for simple battery monitoring.
- **Features**:
  - Low-power consumption (0.9 µA typical).
  - Fixed voltage threshold options (e.g., 2.7V, 3.0V, 3.3V).
  - Push-pull output or open-drain configurations.
  - Compact SOT23-3 package.

---

### 3. MCP100 / MCP101 Series (Microchip)
- **Purpose**: Voltage detector ICs for battery-powered devices.
- **Features**:
  - Ultra-low quiescent current (<1 µA).
  - Monitors battery voltage levels with fixed thresholds.
  - SOT23-3 package for compact designs.
  - Reset output for low-battery detection.

---

### 4. TPS3808 Series (Texas Instruments)
- **Purpose**: Precision voltage supervisor IC.
- **Features**:
  - Adjustable or fixed voltage thresholds.
  - Low power consumption (<2 µA typical).
  - Reset signal for microcontroller.
  - SOT23-3 package for compact designs.


### TPS382x

TPS382x Voltage Monitor With Watchdog Timer

The TPS382x family of supervisors provide circuit initialization and timing supervision, primarily for DSP and processor-based systems. 

During power on, RESET asserts when the supply voltage VDD becomes greater than 1.1 V. Thereafter, the supply voltage supervisor monitors VDD and keeps RESET active low as long as VDD remains less than the threshold voltage, VIT−. An internal timer delays the return of the output to the inactive state (high) to ensure proper system reset. 

The delay time, td, starts after VDD has risen above the threshold voltage (VIT− + VHYS). When the supply voltage drops below the threshold voltage VIT−, the output becomes active (low) again. No external components are required. All the devices of this family have a fixed-sense threshold voltage, VIT–, set by an internal voltage divider. 

The TPS382x family also offers watchdog time out options of 200 ms (TPS3820) and 1.6 s (TPS3823, TPS3824, and TPS3828).


TPS382x 系列监控器主要为 DSP 以及基于处理器的系统提供电路初始化和计时监控等功能。

上电期间，RESET 会在电源电压 VDD 超出 1.1V 时置为有效。

因此 VDD 保持在阈值电压 VIT− 以下，电源电压监控器就会监测 VDD 并将 RESET 保持为低电平有效。内部计时器将会延迟输出恢复至无效状态（高电平）的时间，以确保系统正常复位。延时时间 td 始于 VDD 上升至高于阈值电压 (VIT− + VHYS) 之后。当电源电压降到阈值电压 VIT− 以下时，输出再次变为有效状态（低电平）。无需外部组件。该系列中的所有器件均具有一个通过内部分压器设定的固定检测阈值电压 VIT–。TPS382x 系列还提供 200ms (TPS3820) 和 1.6s（TPS3823、TPS3824 和 TPS3828）的看门狗超时选项。


## ref 

- [[CONsonance-dat]]