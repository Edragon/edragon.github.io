
# TI-power-dat


- [[ti-power-dcdc-boost-dat]] - [[TI-power-dcdc-down-dat]]

- [[power-energy-harvest-dat]] - [[bq25570-dat]] - [[bq25505]] - [[ti-power-dat]]


## battery charger 

- [[battery-charger-dat]] - [[BQ24075-dat]] - [[TI-power-dat]]

1.5A USB-FRIENDLY Li-Ion BATTERY CHARGER AND POWER-PATH MANAGEMENT IC

![](2026-02-12-19-20-12.png)





- [[BQ24650-dat]] - BQ24650RVAR 丝印PAS VQFN-16 电池充电控制器芯片 - [[MPPT-dat]] == PAS TI71W 

BQ24650 Stand-Alone Synchronous Buck Battery Charge Controller for Solar Power With Maximum Power Point Tracking

![](2026-02-12-19-17-09.png)



## LDO 




## LP2985 

![](2026-02-12-21-26-21.png)

[LP2985 150mA, Low-Noise, Low-Dropout Regulator With Shutdown](https://www.ti.com/lit/ds/symlink/lp2985.pdf)




## LP3853/LP3856 3A Fast Response Ultra Low Dropout Linear Regulators

FEATURES
- Ultra Low Dropout Voltage
- Stable with Selected Ceramic Capacitors
- Low Ground Pin Current
- Load Regulation of 0.08%
- 10nA Quiescent Current in Shutdown Mode
- Ensured Output Current of 3A DC
- Available in TO-263 and TO-220 Packages
- Output Voltage Accuracy ± 1.5%
- Error Flag Indicates Output Status
- Sense Option Improves Load Regulation 
- Overtemperature/overcurrent Protection 
- -40°℃ to +125°C Junction Temperature Range




## info 

- [[DCDC-down-dat]] - [[LDO-dat]]



- [[TPS54302-dat]] - [[LM2596-dat]]

- [[TPS5430-dat]]




- [[LM7805-dat]] - [[LM317-dat]]

- [[BQ51013-dat]] - [[BQ51050-dat]]



PUCC33421QDHARQ1 == UCC33421-Q1 Ultra-Small, 1.5W, 5.0V, 5kVRMS Isolation, Automotive DC/DC Module


BQxx 

- [[BQ24650-dat]] == Standalone 1-6 cell Buck battery charge controller with solar input and integrated MPPT





## prebuild module 

PTH04T231WAD - Non-Isolated DC/DC Converters 6A 2.2V-5.5Vin Non- Iso Adj Pwr Module

## step-down 

TLV62130RGTR - TLV62130x 3-V to 17-V 3-A Step-Down Converter In 3x3 QFN Package - Buck Switching Regulator IC Positive Adjustable 0.9V 1 Output 3A 16-VFQFN Exposed Pad



## LDO 

TPS74401-EP == 3.0-A ULTRA-LDO WITH PROGRAMMABLE SOFT-START

TPS7A89 == Small, Dual, 2-A, Low-Noise (3.8 μVRMS), LDO Voltage Regulator

TPS76350DBVR == 150-mA, 10-V, low-dropout voltage regulator with enable

TPS7A45xx Low-Noise Fast-Transient-Response 1.5-A Low-Dropout Voltage Regulators - TPS7A4501, TPS7A4515, TPS7A4518, TPS7A4525, TPS7A4533

[LM78L - LM78L 100-mA Fixed Output Linear Regulator](https://www.ti.com/lit/ds/symlink/lm78l.pdf?ts=1769674083676)

LM3940 1-A Low-Dropout Regulator for 5-V to 3.3-V Conversion

The LM3940 is a 1-A low-dropout regulator designed to provide 3.3 V from a 5-V supply.


## design 

### parallel 

Two LDOs cannot simply be paralleled to get double the current unless they are specifically designed for current sharing.

Workaround - Add small ballast resistors (common workaround)

    LDO1 ──0.1Ω──┐
                ├── Vout
    LDO2 ──0.1Ω──┘

Resistors force current sharing

Typical values: 50–200 mΩ

Trade-offs:
- Voltage drop
- Worse load regulation
- Extra heat

⚠️ Still not ideal for high precision or high current

Better solutions (recommended)

Use one higher-current LDO
- Simplest
- Most reliable

Use a switching regulator + LDO
- Buck converter for current
- LDO for low noise

Use a regulator family designed for paralleling
- Some PMICs allow this





## battery charger 

- [[BT24075-dat]] - [[TI-power-dat]]

![](2026-02-10-16-44-18.png)


## ref 

- [[TI-dat]]

- [[dcdc-down]] - [[ti-power]]