


# betaflight-CLI-dat

- [[betaflight-CLI-dat]] - [[betaflight-firmware-dat]]


## diff all == output

output for [[mobula6-dat]] - [[FRSKY-dat]] - [[betaflight-CLI-dat]] - [[betaflight-firmware-dat]]

    # diff all

    # version
    # Betaflight / STM32F411 (S411) 4.3.0 Jan 14 2023 / 13:53:38 (norevision) MSP API: 1.44

    # config: YES

    # start the command batch
    batch start

    # reset configuration to default settings
    defaults nosave

    mcu_id 004700524731500620313348
    signature 

    # name: Mobula6

    # resources
    resource BEEPER 1 C15
    resource MOTOR 1 B10
    resource MOTOR 2 B06
    resource MOTOR 3 B07
    resource MOTOR 4 B08
    resource PPM 1 A03
    resource PWM 1 A02
    resource PWM 2 A09
    resource PWM 3 A10
    resource LED_STRIP 1 A00
    resource SERIAL_TX 1 A09
    resource SERIAL_TX 2 A02
    resource SERIAL_RX 1 A10
    resource SERIAL_RX 2 A03
    resource LED 1 C13
    resource SPI_SCK 1 A05
    resource SPI_SCK 2 B13
    resource SPI_SCK 3 B03
    resource SPI_MISO 1 A06
    resource SPI_MISO 2 B14
    resource SPI_MISO 3 B04
    resource SPI_MOSI 1 A07
    resource SPI_MOSI 2 B15
    resource SPI_MOSI 3 B05
    resource ADC_BATT 1 B00
    resource ADC_CURR 1 B01
    resource OSD_CS 1 B12
    resource RX_SPI_CS 1 A15
    resource RX_SPI_EXTI 1 C14
    resource RX_SPI_BIND 1 B02
    resource RX_SPI_LED 1 B09
    resource GYRO_EXTI 1 A01
    resource GYRO_CS 1 A04

    # timer
    timer A03 AF3
    # pin A03: TIM9 CH2 (AF3)
    timer B10 AF1
    # pin B10: TIM2 CH3 (AF1)
    timer B06 AF2
    # pin B06: TIM4 CH1 (AF2)
    timer B07 AF2
    # pin B07: TIM4 CH2 (AF2)
    timer B08 AF2
    # pin B08: TIM4 CH3 (AF2)
    timer A00 AF2
    # pin A00: TIM5 CH1 (AF2)
    timer A02 AF3
    # pin A02: TIM9 CH1 (AF3)
    timer A09 AF1
    # pin A09: TIM1 CH2 (AF1)
    timer A10 AF1
    # pin A10: TIM1 CH3 (AF1)

    # dma
    dma ADC 1 1
    # ADC 1: DMA2 Stream 4 Channel 0
    dma pin B10 0
    # pin B10: DMA1 Stream 1 Channel 3
    dma pin B06 0
    # pin B06: DMA1 Stream 0 Channel 2
    dma pin B07 0
    # pin B07: DMA1 Stream 3 Channel 2
    dma pin B08 0
    # pin B08: DMA1 Stream 7 Channel 2
    dma pin A00 0
    # pin A00: DMA1 Stream 2 Channel 6
    dma pin A09 0
    # pin A09: DMA2 Stream 6 Channel 0
    dma pin A10 0
    # pin A10: DMA2 Stream 6 Channel 0

    # feature
    feature -RX_PARALLEL_PWM
    feature -AIRMODE
    feature TELEMETRY
    feature RSSI_ADC
    feature OSD
    feature RX_SPI

    # serial
    serial 1 2048 115200 57600 0 115200

    # beacon
    beacon RX_LOST
    beacon RX_SET

    # aux
    aux 0 0 0 1700 2100 0 0
    aux 1 1 1 1700 2100 0 0
    aux 2 2 1 1300 1700 0 0
    aux 3 13 3 1700 2100 0 0
    aux 4 28 255 1300 1700 0 0
    aux 5 35 2 900 1300 0 0
    aux 6 47 1 900 1300 0 0

    # vtxtable
    vtxtable bands 6
    vtxtable channels 8
    vtxtable band 1 BOSCAM_A A FACTORY 5865 5845 5825 5805 5785 5765 5745 5725
    vtxtable band 2 BOSCAM_B B FACTORY 5733 5752 5771 5790 5809 5828 5847 5866
    vtxtable band 3 BOSCAM_E E FACTORY 5705 5685 5665    0 5885 5905    0    0
    vtxtable band 4 FATSHARK F FACTORY 5740 5760 5780 5800 5820 5840 5860 5880
    vtxtable band 5 RACEBAND R FACTORY 5658 5695 5732 5769 5806 5843 5880 5917
    vtxtable band 6 LOWRACE  L FACTORY 5333 5373 5413 5453 5493 5533 5573 5613
    vtxtable powerlevels 5
    vtxtable powervalues 10 2 14 20 26
    vtxtable powerlabels 0 RCE 25 100 400

    # master
    set gyro_lpf1_static_hz = 0
    set gyro_lpf2_type = PT2
    set gyro_lpf2_static_hz = 135
    set dyn_notch_min_hz = 100
    set gyro_lpf1_dyn_min_hz = 0
    set gyro_lpf1_dyn_max_hz = 0
    set acc_calibration = 17,5,0,1
    set mag_hardware = NONE
    set baro_hardware = NONE
    set rx_spi_protocol = FRSKY_D
    set rx_spi_bus = 3
    set dshot_burst = AUTO
    set dshot_bitbang = OFF
    set motor_pwm_protocol = DSHOT300
    set motor_poles = 12
    set vbat_max_cell_voltage = 440
    set vbat_min_cell_voltage = 290
    set vbat_warning_cell_voltage = 310
    set current_meter = ADC
    set battery_meter = ADC
    set ibata_scale = 1175
    set beeper_inversion = ON
    set beeper_od = OFF
    set yaw_motors_reversed = ON
    set small_angle = 180
    set deadband = 1
    set yaw_deadband = 1
    set pid_process_denom = 4
    set runaway_takeoff_prevention = OFF
    set simplified_gyro_filter = OFF
    set simplified_gyro_filter_multiplier = 135
    set osd_warn_batt_not_full = OFF
    set osd_warn_batt_warning = OFF
    set osd_warn_esc_fail = OFF
    set osd_warn_rssi = ON
    set osd_warn_link_quality = ON
    set osd_rssi_pos = 2392
    set osd_link_quality_pos = 344
    set osd_rssi_dbm_pos = 312
    set osd_tim_2_pos = 2433
    set osd_flymode_pos = 2457
    set osd_throttle_pos = 2424
    set osd_vtx_channel_pos = 2305
    set osd_current_pos = 2336
    set osd_mah_drawn_pos = 2368
    set osd_craft_name_pos = 2442
    set osd_warnings_pos = 2345
    set osd_avg_cell_voltage_pos = 2401
    set osd_disarmed_pos = 2314
    set osd_esc_rpm_pos = 161
    set osd_core_temp_pos = 2360
    set osd_stat_tim_1 = ON
    set osd_stat_max_spd = OFF
    set osd_stat_battery = ON
    set osd_stat_bbox = OFF
    set osd_stat_bb_no = OFF
    set system_hse_mhz = 8
    set debug_mode = RX_FRSKY_SPI
    set vtx_band = 3
    set vtx_channel = 2
    set vtx_power = 5
    set vtx_low_power_disarm = ON
    set vtx_freq = 5685
    set max7456_spi_bus = 2
    set frsky_spi_tx_id = 96,87,1
    set frsky_spi_offset = -34
    set frsky_spi_bind_hop_data = 0,30,60,91,120,150,180,210,5,35,65,95,125,155,185,215,10,40,70,100,130,160,190,221,15,45,75,105,135,165,195,225,20,50,80,110,140,170,200,230,25,55,85,115,145,175,205,0,0,0
    set gyro_1_bustype = SPI
    set gyro_1_spibus = 1
    set gyro_1_sensor_align = CW90
    set gyro_1_align_yaw = 900
    set name = Mobula6

    profile 0

    # profile 0
    set dterm_lpf1_dyn_min_hz = 97
    set dterm_lpf1_dyn_max_hz = 195
    set dterm_lpf1_static_hz = 97
    set dterm_lpf2_static_hz = 195
    set iterm_relax = RPY
    set p_pitch = 80
    set i_pitch = 100
    set d_pitch = 85
    set f_pitch = 140
    set p_roll = 85
    set i_roll = 100
    set d_roll = 85
    set f_roll = 140
    set p_yaw = 120
    set i_yaw = 100
    set f_yaw = 140
    set feedforward_transition = 21
    set simplified_pids_mode = OFF
    set simplified_dterm_filter_multiplier = 130

    profile 1

    profile 2

    # restore original profile selection
    profile 0

    rateprofile 0

    # rateprofile 0
    set rates_type = BETAFLIGHT
    set roll_rc_rate = 100
    set pitch_rc_rate = 100
    set yaw_rc_rate = 100
    set roll_srate = 70
    set pitch_srate = 70
    set yaw_srate = 70

    rateprofile 1

    rateprofile 2

    rateprofile 3

    rateprofile 4

    rateprofile 5

    # restore original rateprofile selection
    rateprofile 0

    # save configuration
    save



## ref 

