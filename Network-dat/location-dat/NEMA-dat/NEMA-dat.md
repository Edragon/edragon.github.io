
# NEMA-dat



## data 2 

- [[MPC1056-dat]] 


- [[location-dat]] - [[GNSS-dat]] - [[GPS-dat]] - [[nema-dat]]


    $GPRMC,140037.00,A,2234.27140,N,11353.24961,E,0.455,,170126,,,D79
    $GPVTG,,T,,M,0.455,N,0.844,K,D2A
    $GPGGA,140037.00,2234.27140,N,11353.24961,E,2,04,1.86,80.5,M,-2.9,M,,000074
    $GPGSA,A,3,05,11,12,13,,,,,,,,,6.80,1.86,6.5400
    $GPGSV,3,1,09,05,51,274,43,09,09,040,,11,49,006,20,12,32,252,227F
    $GPGSV,3,2,09,13,28,177,16,29,06,321,19,30,04,114,16,42,53,228,387D
    $GPGSV,3,3,09,50,60,149,4F
    $GPGLL,2234.27140,N,11353.24961,E,140037.00,A,D67
    $GPTXT,01,01,01,NMEA unknown msg*58


$GPRMC,140037.00,A,2234.27140,N,11353.24961,E,0.455,,170126,,,D*79

- UTC Time: **14:00:37**
- Status: **A (Valid fix)**
- Latitude: **22°34.27140′ N**
- Longitude: **113°53.24961′ E**
- Speed: **0.455 knots ≈ 0.84 km/h**
- Date: **2026-01-17**
- Mode: **D (Differential GPS)**




## data 


    AT+QGNSSRD?
    +QGNSSRD: $GNRMC,075620.000,A,2234.2809,N,11353.2465,E,0.20,253.84,140525,,,A*7F
    $GNVTG,253.84,T,,M,0.20,N,0.38,K,A*22
    $GNGGA,075620.000,2234.2809,N,11353.2465,E,1,12,0.91,52.5,M,-2.9,M,,*5F
    $GPGSA,A,3,12,19,13,15,05,29,194,06,,,,,1.20,0.91,0.79*3E
    $BDGSA,A,3,03,10,07,13,,,,,,,,,1.20,0.91,0.79*11
    $GPGSV,3,1,10,50,59,148,30,13,55,166,44,05,52,310,38,15,29,211,34*7F
    $GPGSV,3,2,10,06,27,091,27,29,22,320,20,12,19,232,35,19,12,149,24*70
    $GPGSV,3,3,10,194,,,31,195,,,30*78
    $BDGSV,4,1,14,10,65,231,36,03,64,189,38,07,63,205,37,08,52,325,*6F
    $BDGSV,4,2,14,13,49,300,42,01,48,121,,02,47,236,,04,34,107,*6D
    $BDGSV,4,3,14,05,23,254,,16,12,169,,06,10,176,,09,04,188,*6C
    $BDGSV,4,4,14,11,01,318,,12,,,20*57
    $GNGLL,2234.2809,N,11353.2465,E,075620.000,A,A*45

    OK

*   `+QGNSSRD: $GNRMC,075620.000,A,2234.2809,N,11353.2465,E,0.20,253.84,140525,,,A*7F`: Recommended Minimum GNSS data: Fix at 07:56:20.000 UTC, Lat 22°34.2809'N, Lon 113°53.2465'E, speed 0.2 knots, course 253.84°, date 14/05/2025, valid, autonomous.
*   `$GNVTG,253.84,T,,M,0.20,N,0.38,K,A*22`: Course Over Ground and Ground Speed: Course 253.84° True, speed 0.20 knots (0.38 km/h), autonomous.
*   `$GNGGA,075620.000,2234.2809,N,11353.2465,E,1,12,0.91,52.5,M,-2.9,M,,*5F`: Global Positioning System Fix Data: Fix at 07:56:20.000 UTC, Lat/Lon, quality 1 (GPS fix), 12 satellites, HDOP 0.91, altitude 52.5m.
*   `$GPGSA,A,3,12,19,13,15,05,29,194,06,,,,,1.20,0.91,0.79*3E`: GPS DOP and Active Satellites: Automatic 3D fix, using 8 GPS satellites (IDs listed), PDOP 1.20, HDOP 0.91, VDOP 0.79.
*   `$BDGSA,A,3,03,10,07,13,,,,,,,,,1.20,0.91,0.79*11`: BeiDou DOP and Active Satellites: Automatic 3D fix, using 4 BeiDou satellites (IDs listed), PDOP 1.20, HDOP 0.91, VDOP 0.79.
*   `$GPGSV,3,1,10,50,59,148,30,13,55,166,44,05,52,310,38,15,29,211,34*7F`: GPS Satellites in View (message 1 of 3): 10 GPS satellites total, details for 4 (IDs 50, 13, 05, 15).
*   `$GPGSV,3,2,10,06,27,091,27,29,22,320,20,12,19,232,35,19,12,149,24*70`: GPS Satellites in View (message 2 of 3): Details for 4 more GPS satellites (IDs 06, 29, 12, 19).
*   `$GPGSV,3,3,10,194,,,31,195,,,30*78`: GPS Satellites in View (message 3 of 3): Details for the last 2 GPS satellites (IDs 194, 195).
*   `$BDGSV,4,1,14,10,65,231,36,03,64,189,38,07,63,205,37,08,52,325,*6F`: BeiDou Satellites in View (message 1 of 4): 14 BeiDou satellites total, details for 4 (IDs 10, 03, 07, 08).
*   `$BDGSV,4,2,14,13,49,300,42,01,48,121,,02,47,236,,04,34,107,*6D`: BeiDou Satellites in View (message 2 of 4): Details for 4 more BeiDou satellites (IDs 13, 01, 02, 04).
*   `$BDGSV,4,3,14,05,23,254,,16,12,169,,06,10,176,,09,04,188,*6C`: BeiDou Satellites in View (message 3 of 4): Details for 4 more BeiDou satellites (IDs 05, 16, 06, 09).
*   `$BDGSV,4,4,14,11,01,318,,12,,,20*57`: BeiDou Satellites in View (message 4 of 4): Details for the last 2 BeiDou satellites (IDs 11, 12).
*   `$GNGLL,2234.2809,N,11353.2465,E,075620.000,A,A*45`: Geographic Position (Latitude/Longitude): Fix at 07:56:20.000 UTC, Lat 22°34.2809'N, Lon 113°53.2465'E, data valid, autonomous mode.
*   


### `+QGNSSRD: $GNRMC,075620.000,A,2234.2809,N,11353.2465,E,0.20,253.84,140525,,,A*7F`

This line is the response from the module, starting with the NMEA RMC sentence.
*   `+QGNSSRD:`: Indicates this is a response to the `AT+QGNSSRD?` command.
*   `$GNRMC`: NMEA sentence type.
    *   `GN`: Indicates a combined GNSS fix (e.g., GPS, GLONASS, Galileo, BeiDou).
    *   `RMC`: Recommended Minimum Specific GNSS Data.
*   `075620.000`: UTC Time of fix: 07:56:20.000.
*   `A`: Status: `A` = Active (data valid). `V` = Void (data not valid).
*   `2234.2809,N`: Latitude: 22 degrees, 34.2809 minutes North.
*   `11353.2465,E`: Longitude: 113 degrees, 53.2465 minutes East.
*   `0.20`: Speed over ground in knots.
*   `253.84`: Course over ground in degrees (True).
*   `140525`: Date: 14th May 2025 (DDMMYY format).
*   `,,,`: Magnetic variation (degrees, E/W) - field is empty, not provided.
*   `A`: Mode indicator (NMEA 0183 v2.3 and later): `A` = Autonomous mode. `D` = Differential mode. `E` = Estimated (dead reckoning) mode. `N` = Data not valid.
*   `*7F`: Checksum for data integrity (hexadecimal).

### `$GNVTG,253.84,T,,M,0.20,N,0.38,K,A*22`

This is the VTG (Course Over Ground and Ground Speed) sentence.
*   `$GNVTG`: NMEA sentence type.
    *   `GN`: Combined GNSS.
    *   `VTG`: Course Over Ground and Ground Speed.
*   `253.84,T`: Course over ground (degrees True). `T` indicates True North.
*   `,,M`: Course over ground (degrees Magnetic). `M` indicates Magnetic North - field is empty, not provided.
*   `0.20,N`: Speed over ground in knots. `N` indicates Knots.
*   `0.38,K`: Speed over ground in kilometers per hour. `K` indicates Kilometers per hour.
*   `A`: Mode indicator (NMEA 0183 v2.3 and later): `A` = Autonomous. `D` = Differential. `E` = Estimated. `N` = Data not valid.
*   `*22`: Checksum.

### `$GNGGA,075620.000,2234.2809,N,11353.2465,E,1,12,0.91,52.5,M,-2.9,M,,*5F`

This is the GGA (Global Positioning System Fix Data) sentence.
*   `$GNGGA`: NMEA sentence type.
    *   `GN`: Combined GNSS.
    *   `GGA`: Global Positioning System Fix Data.
*   `075620.000`: UTC Time of fix.
*   `2234.2809,N`: Latitude.
*   `11353.2465,E`: Longitude.
*   `1`: Fix quality:
    *   `0` = Invalid
    *   `1` = GPS fix (SPS)
    *   `2` = DGPS fix
    *   `3` = PPS fix
    *   `4` = Real Time Kinematic
    *   `5` = Float RTK
    *   `6` = Estimated (dead reckoning)
    *   `7` = Manual input mode
    *   `8` = Simulation mode
*   `12`: Number of satellites being tracked.
*   `0.91`: Horizontal Dilution of Precision (HDOP).
*   `52.5,M`: Altitude of antenna above mean sea level. `M` indicates Meters.
*   `-2.9,M`: Geoidal separation (difference between WGS-84 earth ellipsoid and mean sea level). `M` indicates Meters.
*   `,,`: Age of DGPS data (seconds since last SC104 type 1 or 9 update) - field is empty. DGPS station ID number - field is empty.
*   `*5F`: Checksum.

### `$GPGSA,A,3,12,19,13,15,05,29,194,06,,,,,1.20,0.91,0.79*3E`

This is the GSA (GNSS DOP and Active Satellites) sentence, specifically for GPS satellites.
*   `$GPGSA`: NMEA sentence type.
    *   `GP`: GPS satellites.
    *   `GSA`: GNSS DOP and Active Satellites.
*   `A`: Mode: `M` = Manual, forced to operate in 2D or 3D mode. `A` = Automatic, allowed to automatically switch 2D/3D.
*   `3`: Fix type: `1` = Fix not available. `2` = 2D. `3` = 3D.
*   `12,19,13,15,05,29,194,06,,,,,`: PRNs (Pseudo-Random Noise codes) of satellites used in fix (up to 12). Here, GPS satellites with PRNs 12, 19, 13, 15, 05, 29, 194, and 06 are used.
*   `1.20`: Position Dilution of Precision (PDOP).
*   `0.91`: Horizontal Dilution of Precision (HDOP).
*   `0.79`: Vertical Dilution of Precision (VDOP).
*   `*3E`: Checksum.

### `$BDGSA,A,3,03,10,07,13,,,,,,,,,1.20,0.91,0.79*11`

This is the GSA sentence, specifically for BeiDou satellites.
*   `$BDGSA`: NMEA sentence type.
    *   `BD`: BeiDou satellites.
    *   `GSA`: GNSS DOP and Active Satellites.
*   `A`: Mode: `A` = Automatic.
*   `3`: Fix type: `3` = 3D.
*   `03,10,07,13,,,,,,,,,`: PRNs of BeiDou satellites used in fix. Here, BeiDou satellites with PRNs 03, 10, 07, and 13 are used.
*   `1.20`: PDOP.
*   `0.91`: HDOP.
*   `0.79`: VDOP.
*   `*11`: Checksum.

### `$GPGSV,3,1,10,50,59,148,30,13,55,166,44,05,52,310,38,15,29,211,34*7F`

This is the GSV (GNSS Satellites in View) sentence, specifically for GPS satellites. This is the first message of three.
*   `$GPGSV`: NMEA sentence type.
    *   `GP`: GPS satellites.
    *   `GSV`: GNSS Satellites in View.
*   `3`: Total number of GSV messages for current data (this is message 1 of 3 for GPS).
*   `1`: Message number (this is the first message).
*   `10`: Total number of GPS satellites in view.
*   For each satellite (up to 4 per message):
    *   `50`: Satellite PRN number (ID 50).
    *   `59`: Elevation in degrees (max 90).
    *   `148`: Azimuth in degrees (True, 0-359).
    *   `30`: SNR (Signal to Noise Ratio) in dB (00-99), null when not tracking.
    *   `13,55,166,44`: Satellite ID 13, Elevation 55, Azimuth 166, SNR 44.
    *   `05,52,310,38`: Satellite ID 05, Elevation 52, Azimuth 310, SNR 38.
    *   `15,29,211,34`: Satellite ID 15, Elevation 29, Azimuth 211, SNR 34.
*   `*7F`: Checksum.

### `$GPGSV,3,2,10,06,27,091,27,29,22,320,20,12,19,232,35,19,12,149,24*70`

Second GSV message for GPS satellites (message 2 of 3).
*   `$GPGSV`: GPS Satellites in View.
*   `3`: Total number of GSV messages.
*   `2`: Message number.
*   `10`: Total number of GPS satellites in view.
*   Satellite data:
    *   `06,27,091,27`: ID 06, El 27, Az 091, SNR 27.
    *   `29,22,320,20`: ID 29, El 22, Az 320, SNR 20.
    *   `12,19,232,35`: ID 12, El 19, Az 232, SNR 35.
    *   `19,12,149,24`: ID 19, El 12, Az 149, SNR 24.
*   `*70`: Checksum.

### `$GPGSV,3,3,10,194,,,31,195,,,30*78`

Third GSV message for GPS satellites (message 3 of 3).
*   `$GPGSV`: GPS Satellites in View.
*   `3`: Total number of GSV messages.
*   `3`: Message number.
*   `10`: Total number of GPS satellites in view.
*   Satellite data for the remaining 2 GPS satellites:
    *   `194,,,31`: ID 194, Elevation and Azimuth not provided, SNR 31.
    *   `195,,,30`: ID 195, Elevation and Azimuth not provided, SNR 30.
*   `*78`: Checksum.

### `$BDGSV,4,1,14,10,65,231,36,03,64,189,38,07,63,205,37,08,52,325,*6F`

This is the GSV sentence for BeiDou satellites. This is the first message of four.
*   `$BDGSV`: NMEA sentence type.
    *   `BD`: BeiDou satellites.
    *   `GSV`: GNSS Satellites in View.
*   `4`: Total number of GSV messages for BeiDou data.
*   `1`: Message number.
*   `14`: Total number of BeiDou satellites in view.
*   Satellite data:
    *   `10,65,231,36`: ID 10, El 65, Az 231, SNR 36.
    *   `03,64,189,38`: ID 03, El 64, Az 189, SNR 38.
    *   `07,63,205,37`: ID 07, El 63, Az 205, SNR 37.
    *   `08,52,325,`: ID 08, El 52, Az 325, SNR not provided (field ends before SNR).
*   `*6F`: Checksum. (Note: The line in the example seems to be truncated for the last satellite's SNR, which might affect checksum if it was fully present).

### `$BDGSV,4,2,14,13,49,300,42,01,48,121,,02,47,236,,04,34,107,*6D`

Second GSV message for BeiDou satellites (message 2 of 4).
*   `$BDGSV`: BeiDou Satellites in View.
*   `4`: Total number of GSV messages.
*   `2`: Message number.
*   `14`: Total number of BeiDou satellites in view.
*   Satellite data:
    *   `13,49,300,42`: ID 13, El 49, Az 300, SNR 42.
    *   `01,48,121,,`: ID 01, El 48, Az 121, SNR not provided.
    *   `02,47,236,,`: ID 02, El 47, Az 236, SNR not provided.
    *   `04,34,107,`: ID 04, El 34, Az 107, SNR not provided.
*   `*6D`: Checksum.

### `$BDGSV,4,3,14,05,23,254,,16,12,169,,06,10,176,,09,04,188,*6C`

Third GSV message for BeiDou satellites (message 3 of 4).
*   `$BDGSV`: BeiDou Satellites in View.
*   `4`: Total number of GSV messages.
*   `3`: Message number.
*   `14`: Total number of BeiDou satellites in view.
*   Satellite data:
    *   `05,23,254,,`: ID 05, El 23, Az 254, SNR not provided.
    *   `16,12,169,,`: ID 16, El 12, Az 169, SNR not provided.
    *   `06,10,176,,`: ID 06, El 10, Az 176, SNR not provided.
    *   `09,04,188,`: ID 09, El 04, Az 188, SNR not provided.
*   `*6C`: Checksum.

### `$BDGSV,4,4,14,11,01,318,,12,,,20*57`

Fourth GSV message for BeiDou satellites (message 4 of 4).
*   `$BDGSV`: BeiDou Satellites in View.
*   `4`: Total number of GSV messages.
*   `4`: Message number.
*   `14`: Total number of BeiDou satellites in view.
*   Satellite data for the remaining 2 BeiDou satellites:
    *   `11,01,318,,`: ID 11, El 01, Az 318, SNR not provided.
    *   `12,,,20`: ID 12, Elevation and Azimuth not provided, SNR 20.
*   `*57`: Checksum.

### `$GNGLL,2234.2809,N,11353.2465,E,075620.000,A,A*45`

This is the GLL (Geographic Position - Latitude/Longitude) sentence.
*   `$GNGLL`: NMEA sentence type.
    *   `GN`: Combined GNSS.
    *   `GLL`: Geographic Position - Latitude/Longitude.
*   `2234.2809,N`: Latitude: 22 degrees, 34.2809 minutes North.
*   `11353.2465,E`: Longitude: 113 degrees, 53.2465 minutes East.
*   `075620.000`: UTC Time of fix.
*   `A`: Status: `A` = Data valid. `V` = Data invalid.
*   `A`: Mode indicator (NMEA 0183 v2.3 and later): `A` = Autonomous. `D` = Differential. `E` = Estimated. `N` = Data not valid.
*   `*45`: Checksum.

