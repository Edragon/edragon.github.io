
# betaflight-PID-fliter-dat.md


### filter settings 

Profile dependent Filter Settings

D Term Lowpass Filters



## safe indoor tune 

### Gyro Lowpass Filters + Gyro RPM Filter + Dynamic Notch Filter 


    set gyro_lpf1_static_hz = 250
    set gyro_lpf2_static_hz = OFF

    set gyro_lpf1_dyn_min_hz = 200
    set gyro_lpf1_dyn_max_hz = 550

    set rpm_filter_min_hz = 150
    set dyn_notch_min_hz = 200
    set dyn_notch_q = 500

If motors get hot in <1 min → lower **gyro_lpf1_static_hz** back to 200.

If motors stay cool → you can even push **gyro_lpf1_dyn_max_hz** to 600.



### D Term LowpassFilters + D Term Notch Filter + Yaw Lowpass Filter

    set dterm_lpf1_static_hz = 150
    set dterm_lpf1_dyn_min_hz = 100
    set dterm_lpf1_dyn_max_hz = 200
    set dterm_lpf2_static_hz = OFF
    set yaw_lowpass_hz = 0