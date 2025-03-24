#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket
import sys
import select
import json
import urllib2
import thread
from coordTransform import wgs84_to_gcj02

# Define the directory for storing GPS HTML files
www = '/var/www/html/2503/gps'

def amap(x, y, id, tm, nums, loc_type):
    """
    Generates an HTML page with a map from AMAP (Gaode) API.

    Args:
        x (float): WGS84 Longitude.
        y (float): WGS84 Latitude.
        id (str):  Tracker ID.
        tm (str):  Timestamp.
        nums (int): Number of module sends.
        loc_type (str): Location type (e.g., GPS, LBS).
    """
    # Convert WGS84 coordinates to GCJ02 (Gaode)
    gpsDATA = wgs84_to_gcj02(x, y)

    # Create the HTML file
    f = open('%s/a-%s.html' % (www, id),'w')

    # HTML template with placeholders for data
    amap_page = """
    <!doctype html>
    <html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="initial-scale=1.0, user-scalable=no, width=device-width">
        <title>AMAP Demo</title>
        <link rel="stylesheet" href="http://iot.electrodragon.com/gps/2503/amap.css"/>
        <script src="http://webapi.amap.com/maps?v=1.4.0&key=YOUR_AMAP_API_KEY"></script>
        <script type="text/javascript" src="http://cache.amap.com/lbs/static/addToolbar.js"></script>
    </head>

    <body>
    <h3>My Electrodragon Tracker Demo (AMP-gaode.com API)</h3>
    <h5>Module send times: %s, module time: %s, location type %s </h5>
    <h5>Location data %s - %s (GPS -> GCJ02 version fix)</h5>
    <div id="container"></div>

    <script>
        var map = new AMap.Map('container', {
            resizeEnable: true,
            center: [%s, %s],
            zoom: 20
        });
        var marker = new AMap.Marker( {
            map: map,
            position: [%s, %s]
        });

    </script>

    </body>
    </html>
    """ % ( str(nums), str(tm), loc_type, str(gpsDATA[0]), str(gpsDATA[1]),
    str(gpsDATA[0]), str(gpsDATA[1]), str(gpsDATA[0]), str(gpsDATA[1]) )

    f.writelines(amap_page)
    print ("Successfully wrote to a-%s.html" % id )
    f.close()

def gmap(x, y, id, tm, nums, loc_type):
    """
    Generates an HTML page with a map from Google Maps API.

    Args:
        x (float): WGS84 Longitude.
        y (float): WGS84 Latitude.
        id (str):  Tracker ID.
        tm (str):  Timestamp.
        nums (int): Number of module sends.
        loc_type (str): Location type (e.g., GPS, LBS).
    """
    # Create the HTML file
    f = open('%s/g-%s.html' % (www, id),'w')

    # HTML template with placeholders for data
    gmap_page = """
    <!DOCTYPE html>
    <html>
    <head>
        <style>
        #map {
            height: 800px;
            width: 100%%;
        }
        </style>
    </head>

    <body>
        <h3>My Electrodragon Tracker Demo</h3>
        <h5>Module send times: %s, module time: %s, location type %s </h5>
        <h5>Location data %s - %s </h5>

        <div id="map"></div>

        <script>
        function initMap() {
            var uluru = {lat: %s, lng: %s};

            var map = new google.maps.Map(document.getElementById('map'), {
            zoom: 15,
            center: uluru
            });

            var marker = new google.maps.Marker({
            position: uluru,
            map: map
            });
        }
        </script>

        <script async defer
        src="https://maps.googleapis.com/maps/api/js?key=YOUR_GOOGLE_MAPS_API_KEY&callback=initMap">
        </script>

    </body>
    </html>
    """ % ( str(nums), str(tm), loc_type, str(y), str(x), str(y), str(x) )

    f.writelines(gmap_page)
    print ("Successfully wrote to g-%s.html" % id)
    f.close()


# Server configuration
HOST = ''  # Listen on all available interfaces
PORT = 8100

# Create a TCP socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Allow reuse of the same address
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
# Bind the socket to the address
s.bind((HOST, PORT))
# Listen for incoming connections
s.listen(5)

print ('Server started at: %s:%s') %(HOST, PORT)
print ('Waiting for connection...')

def httpsend(x, y):
    """
    Sends GPS data to ThingsBoard via HTTP.

    Args:
        x (float): Longitude.
        y (float): Latitude.
    """
    # JSON data payload
    data = {
        "latitude": y,
        "longitude": x,
        "batteryLevel": "0",
        "batteryCharging": "0"
    }
    credential = "qt6GZuEqH685HYzi8OlH"  # Device access token
    addr = "demo.thingsboard.io:80"

    # Create the request
    req = urllib2.Request('http://%s/api/v1/%s/attributes' % (addr,credential) )
    req.add_header('Content-Type', 'application/json')

    # Send the request
    response = urllib2.urlopen(req, json.dumps(data))
    #print("data uploaded")

def findDATA(DATA, codec_data):
    """
    Finds specific data within the codec data string.

    Args:
        DATA (str):  Data identifier to search for.
        codec_data (str): Encoded data string.

    Returns:
        tuple: Two 8-character hexadecimal strings.
    """
    result = codec_data.find(DATA)  # Find the data identifier
    hexdata_1 = codec_data[result+8:result+16]  # Extract the first 8 bytes
    hexdata_2 = codec_data[result+16:result+24] # Extract the next 8 bytes
    return hexdata_1, hexdata_2

def hexDEC(HEXdata):
    """
    Converts a tuple of two hexadecimal strings to decimal integers.

    Args:
        HEXdata (tuple): A tuple containing two hexadecimal strings.

    Returns:
        tuple: A tuple containing two decimal integers.
    """
    # Convert hex string to decimal
    decdata_1 = int(HEXdata[0],16)
    decdata_2 = int(HEXdata[1],16)
    return decdata_1, decdata_2


def restDATA(codec_data):
    """
    Extracts and processes the remaining data (time, ID, serial number)
    from the codec data.

    Args:
        codec_data (str): Encoded data string.

    Returns:
        tuple: Formatted serial number, formatted time, and packet times.
    """
    # Extract hexadecimal data
    hex_time = findDATA("00040006", codec_data)  # 12 long
    hex_ID = findDATA("a0950006", codec_data)    # 12 long
    hex_sn = findDATA("00010006", codec_data)    # 12 long

    # Format the extracted data
    hex_sn_format = hex_sn[0]+hex_sn[1][0:4]
    hex_tm = "%s-%s%s" % (hex_time[0][0:6], hex_time[0][6:8], hex_time[1][0:4])
    pcktimes = int(codec_data[16:20],16)

    print ("HEX DATE 3L- Y-N-D: %s" % hex_time[0][0:6])
    print ("HEX TIME 3L - H-M-S: %s" % hex_time[0][6:8]+hex_time[1][0:4])
    print ("HEX pro_ID 3L: %s" % hex_ID[0]+hex_ID[1][0:4] )
    print ("HEX user_SN 3L: %s" % hex_sn_format )

    return hex_sn_format, hex_tm, pcktimes


def loc_data(codec_data):
    """
    Extracts and processes location data (GPS or LBS) from the codec data.

    Args:
        codec_data (str): Encoded data string.

    Returns:
        tuple: Longitude, latitude, and data type.
    """
    # Determine data type (LBS or GPS)
    if codec_data.find("51400008") != -1:
        Data_type = "LBS"
        DATA = findDATA("51400008", codec_data)  # Find flag for lbs data 51400008
    elif codec_data.find("50780008") != -1:
        Data_type = "GPS"
        DATA = findDATA("50780008", codec_data)  # Find flag for gps data 50780008
    else:
        print("ERROR: No location data found")
        return None, None, None

    temp_lon = DATA[1]  # Longitude X
    temp_lat = DATA[0]  # Latitude Y
    print ("HEX %s 2x2L - X-Y: %s, %s" % (Data_type, temp_lon, temp_lat))

    decDATA = hexDEC(DATA)
    # Divide to get readable data
    lat = decDATA[1]/float(1000000.00)
    lon = decDATA[0]/float(1000000.00)

    print ("DEC %s 2x2L - X-Y: %s, %s" % (Data_type, lon, lat))

    httpsend(lon, lat)

    return lon, lat, Data_type


def DATA_dandler(codec_data):
    """
    Handles the main GPS data processing.

    Args:
        codec_data (str): Encoded data string.
    """
    # Handle main gps data
    locDATA = loc_data(codec_data)
    if locDATA[0] is None:
        print("ERROR: No location data to handle")
        return
    # Handle rest data
    rest_data = restDATA(codec_data)
    # Send to html page
    gmap(locDATA[0], locDATA[1], rest_data[0], rest_data[1], rest_data[2], locDATA[2])
    amap(locDATA[0], locDATA[1], rest_data[0], rest_data[1], rest_data[2], locDATA[2])


def on_new_client(clientsocket,addr):
    """
    Handles a new client connection.

    Args:
        clientsocket (socket): Socket object for the client.
        addr (tuple): Client address.
    """
    while True:
        data = clientsocket.recv(182)  # Receive data

        codec_data = data.encode('hex')
        print (codec_data)
        if codec_data[0:4] == '7e7e':
            # Print simple demo info
            print ("INFO: star_char-%s, version-%s, action-%s, pack_times-%s" % (codec_data[0:4], codec_data[4:12], codec_data[12:16], codec_data[16:20]) )
            DATA_dandler(codec_data)
            clientsocket.send("Received at Electrodragon tracker")
        else:
            clientsocket.send("you come from telnet?")

    clientsocket.close()


# Main server loop
while True:
    conn, addr = s.accept()
    print ('Connected by ', addr)
    thread.start_new_thread(on_new_client, (conn, addr))

