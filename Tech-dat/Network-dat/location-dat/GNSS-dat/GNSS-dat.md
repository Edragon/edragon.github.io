
# GNSS-dat 

- gnss protocol - [[quectel_l76-lbl26-lblc86l_gnss_protocol_specification_v2-2.pdf]]

- GSV - GNSS Satellites in View. 

- GSA - GNSS  DOP  and  Active  Satellites.  GNSS  receiver  operating  mode,  satellites  used  in  the  navigation solution reported by the GGA sentence, and DOP values. 

- GLL - Geographic Position – Latitude/Longitude. 

- GGA - Global Positioning System Fix Data. Time, position, and fix-related data for a GNSS receiver.

- VTG - Course Over Ground & Ground Speed. 

- RMC - Recommended Minimum Specific GNSS Data. Time, date, position, course, and speed data provided by a GNSS receiver.

## commands examples 

    Search GPS + GLONASS: 
    $PMTK353,1,1,0,0,0*2B

    Enable GPS, Glonass, Galileo:
    $PMTK353,1,1,1,0,0*2A

Sets  the  speed  threshold  for  static  navigation.  

    $PMTK386,0.4*39 
    $PMTK001,386,3*3D

Gets whether the GPS/GLONASS/BDS/Galileo satellite seraching is enabled or not.

    $PMTK355*31 
    $PMTK001,355,3,1,1,0,0*33
    
## ref 

- [[GPS-dat]]