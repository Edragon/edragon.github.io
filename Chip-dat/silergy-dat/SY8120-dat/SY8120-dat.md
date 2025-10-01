
# SY8102-dat


Application Note: SY8120I

High Efficiency, Fast Response, 2.0A, 18V Input Synchronous Step Down Regulator

- [[Silergy-Corp-SY8120IABC_C479076.pdf]]


## Features 

- • Low RDS(ON) for Internal Switches  (Top/Bottom): 130mΩ/105mΩ 
- • 4.2-18V Input Voltage Range  
- • 2A Output Current Capability 
- • 500kHz Switching Frequency Minimize the External Components 
- • Stable with 10μF COUT and 1.5μ H Inductor 
- • Instant PWM Architecture to Achieve Fast Transient Responses 
- • Internal Soft-start Limits the Inrush Current 
- • Cycle-by-cycle Peak/Valley Current Limitation 
- • Hic-cup Mode Output Short Circuit Protection 
- • Thermal Shutdown with Auto Recovery 
- • Compact Package SOT23-6 

## calculation 

100K / 22.1K = 3.3V
100K / 16.6K = 4.2V
100K / 15K = 4.6V
100K / 13K = 5V


Rl = 0.6V / (Vout - 0.6V) * Rh

      = 0.6V / (3.3V - 0.6V) * 100K = **22.2K**
      = 0.6V / (3.4V - 0.6V) * 100K = 21.4K
      = 0.6V / (5V - 0.6V)   * 100K = 13.3K
      = 0.6V / (5.1V - 0.6V) * 100K = **12.8K**
      = 0.6V / (4.2V - 0.6V) * 100K = 16.6K
      = 0.6V / (4.3V - 0.6V) * 100K = **16.1K**


## ref 

- [[HDK]] - [[HDK-dat]]