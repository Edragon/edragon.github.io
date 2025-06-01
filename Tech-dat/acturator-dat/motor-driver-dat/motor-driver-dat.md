
# motor-driver-dat

- [[motor-dat]]

[legacy wiki page](https://www.electrodragon.com/w/Category:Driver_Board) 

## Board 

- [[SDR1040-dat]] - [[SDR1102-dat]] - [[SDR1109-dat]] - [[SDR1048-dat]] - [[SDR1059-dat]] - [[SDR1050-dat]]

- [[SDR1090-dat]] - [[SDR1079-dat]] - [[SDR1062-dat]]

- [[SDR1060-dat]] - [[SDR1076-dat]]

- [[SDR1096-dat]]

- [[TB6612-dat]] - [[SDR1059-dat]] - [[SDR1087-dat]] - [[MPC1114-dat]]

## chips 

- [[ti-motor-dat]] 
  
- [[toshiba-dat]] - [[TB6612-dat]] - [[TB6600-dat]] - board - [[SDR1059-dat]]

- [[LW556-dat]] - [[TB6600-dat]] - [[DM430-dat]] - [[DM542-dat]]

- [[allegro-dat]] - [[A4988-dat]] - [[A4954-dat]]




## stepper motor 

- [[stepper-dat]]

- [[A4988-dat]] - [[TB67H450-dat]] - [[TB6612-dat]] - [[LV8729-dat]]

- [[L293-dat]] - [[L298-dat]] 

- [[TI-motor-dat]] - [[DRV8833-dat]] - [[DRV8825-dat]] - [[drv8837-dat]] - [[drv8313-dat]] - [[DRV8871-dat]]

- [[ULN2003-dat]]

- [[PCA9685-dat]]


## and more 

- [[MC33887-dat]]

## Chip function lists 

- overcurrent / thermal shutdown protection / microstepping / precise motor control


## Comparison 

TB6612FNG vs. L298N

| Feature                 | TB6612FNG           | L298N               |
| ----------------------- | ------------------- | ------------------- |
| Motor Voltage Range     | 2.5V – 13.5V        | 5V – 46V            |
| Logic Voltage Range     | 2.7V – 5.5V         | 5V – 7V             |
| Continuous Current / ch | ~1.2A               | 2A                  |
| Peak Current / ch       | 3.2A (short bursts) | 3A (non-repetitive) |
| Efficiency              | High (CMOS)         | Low (Bipolar)       |
| Voltage Drop            | ~0.2V               | ~1.8V – 3V          |
| Heat Output             | Low                 | High                |
| PWM Frequency Support   | Up to 100 kHz       | <25 kHz             |
| Size                    | Small, modern       | Large, bulky        |
| Cost                    | Moderate            | Low                 |


more options

| Chip/Module   | Voltage Range | Continuous Current  | PWM Freq.    | Features & Notes                                                           |
| ------------- | ------------- | ------------------- | ------------ | -------------------------------------------------------------------------- |
| **TB6612FNG** | 2.5V – 13.5V  | 1.2A/ch (3.2A peak) | Up to 100kHz | Efficient CMOS, low heat, great for small robots                           |
| **DRV8833**   | 2.7V – 10.8V  | 1.5A/ch (2A peak)   | Up to 250kHz | Compact, efficient, built-in protection, ideal for small DC motors         |
| **DRV8871**   | 6.5V – 45V    | 3.6A (6A peak)      | ~100kHz      | Single-channel, robust, good for mid-power motors                          |
| **DRV8876**   | 4.5V – 37V    | 3.5A (5A peak)      | ~100kHz      | Smart current regulation, overtemp/short protection                        |
| **MC33926**   | 5V – 28V      | 3A (5A peak)        | Up to 20kHz  | Automotive-grade, robust with fault reporting                              |
| **VNH5019**   | 5.5V – 24V    | 12A (30A peak)      | ~20kHz       | High-power, onboard protection, great for large motors                     |
| **BTN7960B**  | 5.5V – 27V    | 43A (55A peak)      | ~25kHz       | High-current half-bridge, excellent for industrial/heavy-duty applications |



## ref 

- [[FOC-dat]]