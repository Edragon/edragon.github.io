
# slCAN-dat

## supported commands 

    O - Open channel
    C - Close channel
    S0 - Set bitrate to 10k
    S1 - Set bitrate to 20k
    S2 - Set bitrate to 50k
    S3 - Set bitrate to 100k
    S4 - Set bitrate to 125k
    S5 - Set bitrate to 250k
    S6 - Set bitrate to 500k
    S7 - Set bitrate to 750k
    S8 - Set bitrate to 1M
    M0 - Set mode to normal mode (default)
    M1 - Set mode to silent mode
    A0 - Disable automatic retransmission
    A1 - Enable automatic retransmission (default)
    TIIIIIIIILDD... - Transmit data frame (Extended ID) [ID, length, data]
    tIIILDD... - Transmit data frame (Standard ID) [ID, length, data]
    RIIIIIIIIL - Transmit remote frame (Extended ID) [ID, length]
    rIIIL - Transmit remote frame (Standard ID) [ID, length]
    V - Returns firmware version and remote path as a string


## ref 

- [[can-dat]]