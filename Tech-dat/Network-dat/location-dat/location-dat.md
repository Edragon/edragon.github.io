
# location-dat

## tech 

- [[GNSS-dat]] - [[GPS-dat]] - [[AGPS-dat]]

- [[amplifier-dat]]

- [[antenna-dat]]

## companies 

- [[u-blox-dat]] - [[NEO-7-dat]]

- [[quectel-dat]] - [[quectel-gps-dat]]





## location by [[A7670-dat]]

turn on GPS functions 

    AT+CGNSSPWR=1
    
turn on GPS power by GPIO pin 4: 

    AT+CGDRT=4,1
    AT+CGSETV=4,1

wait until GPS feedback READY!

    +CGNSSPWR: READY!

foward signal to GPS NEMA serial port 

    AT+CGNSSTST=1
    OK
    
## GPS NEMA output Port 

    SimTech HS-USB NMEA 9011 (COM346)
    设备类型：端口(COM和LPT)
    制造商：SimTechIncorporated
    位置：0000.001d.0000.001.002.002.000.000.000



## ref 

- [[location]] - [[network]]