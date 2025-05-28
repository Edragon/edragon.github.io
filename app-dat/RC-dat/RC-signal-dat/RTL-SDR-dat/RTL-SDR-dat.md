
# RTL-SDR-dat

1. What You Need

An RTL-SDR USB dongle (e.g., RTL2832U with R820T2)

A Windows, Linux, macOS, or Android device

An antenna (usually included)

Software (like SDR# or Universal Radio Hacker)

SDRSharp


4. Signal Analysis (for reverse engineering)
   
Use Universal Radio Hacker (URH):

Record raw signals from 2.4GHz toy remote (if within range)

Analyze bit patterns, timing, modulation

Use Audacity to visualize audio-like modulated signals.

5. On Android (Optional)
   
Use SDR Touch with an OTG cable and RTL-SDR dongle.

Works well for listening to FM, air band, etc.

What You Can Do With RTL-SDR

- Listen to FM radio, air traffic, police, weather stations
- Track airplanes (ADS-B)
- Capture RF from garage remotes, key fobs, toy RC
- Reverse engineer simple RF protocols



## Alternative: Use an SDR to Sniff Raw RF

To analyze the actual RF signal, you need a Software Defined Radio (SDR) like:

HackRF, LimeSDR, or USRP

Record the 2.4GHz spectrum

Analyze bursts from the remote

Use Universal Radio Hacker (URH) or GNU Radio to decode the signal