
# TI-Motor-dat

- [[DRV8313-dat]]

- [[DRV8837-dat]]

- [[DRV8833-dat]] - [[DRV8825-dat]]

## compare 

| Feature/Specification       | **DRV8837**                        | **DRV8833**                        | **DRV8825**                    |
| --------------------------- | ---------------------------------- | ---------------------------------- | ------------------------------ |
| **Type**                    | Low-Voltage Motor Driver           | Dual H-Bridge Motor Driver         | Stepper Motor Driver           |
| **Operating Voltage Range** | 1.8 V–7 V                          | 2.7 V–10.8 V                       | 8.2 V–45 V                     |
| **Output Current (Max)**    | 1.8 A                              | 1 A per channel (2 A peak)         | 2.5 A per phase (with cooling) |
| **Control Interface**       | PWM                                | PWM                                | Step/Direction                 |
| **Number of Outputs**       | 1 H-Bridge (single motor)          | 2 H-Bridges (dual motors)          | 2 H-Bridges (bipolar stepper)  |
| **Features**                | Low voltage, small size            | Current limiting, thermal shutdown | Adjustable current regulation  |
| **Microstepping**           | N/A                                | N/A                                | Up to 1/32 microstepping       |
| **Protection Features**     | Undervoltage, thermal, overcurrent | Undervoltage, thermal, overcurrent | Overtemperature, overcurrent   |
| **Typical Applications**    | Portable devices, toys             | Robotics, small DC motors          | 3D printers, CNC machines      |
| **Package Options**         | 8-pin WSON, MSOP                   | 16-pin HTSSOP                      | 28-pin HTSSOP                  |



## ref 

- [[motor-driver-dat]]