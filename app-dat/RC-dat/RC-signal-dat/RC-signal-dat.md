
# RC-signal-dat.md

## RC-signals

- [[WIFI-dat]]


### Proprietary modulation schemes（专有调制方案）

Toy RC systems may use other modulation methods like [[DSSS-dat]], [[FHSS-dat]], or non-standard GFSK configurations.

- [[GFSK-dat]] = [[NRF24L01-dat]]

- [[SBUS-dat]] - [[PPM-dat]] - [[PWM-dat]]

Frequency Hopping:

Many toy-grade RC transmitters hop between frequencies.

#### DSSS (Direct Sequence Spread Spectrum)

DSSS (Direct Sequence Spread Spectrum) is a method of transmitting radio signals by spreading the signal over a wider frequency band than the original data rate requires.

**How DSSS Works:**

The original data signal is multiplied by a "chipping code", a sequence of faster bits called "chips."

This process spreads the energy of the signal over a wider bandwidth.

The receiver, knowing the same chipping code, can reconstruct the original data.

**Key Features:**

Spreads signal across wide frequency band (increases resistance to interference and jamming).

More secure and harder to intercept.

Improves signal robustness in noisy environments.

**DSSS in Real-World Use:**

Used in older Wi-Fi standards (like 802.11b).

Also found in some military and commercial RF systems.

Some toy-grade 2.4GHz systems may use simple DSSS-like techniques to reduce cost and avoid interference.

**Comparison with FHSS:**

DSSS spreads signal continuously across a wide band.

FHSS (Frequency Hopping Spread Spectrum) hops between frequencies in a sequence.

### Compare with WIFI 

| Feature     | Wi-Fi (ESP8266)             | DSSS RC (Toy/Hobby)            |
| ----------- | --------------------------- | ------------------------------ |
| Range       | 30–100m typical             | 20m (toy) to >1km (hobby)      |
| Latency     | Medium                      | Very low                       |
| Robustness  | Lower (affected by routers) | High (designed for RF control) |
| Ease of Use | Easy (phone control)        | Needs RC Tx/Rx                 |


## RC-protocols 

- [[edge-tx-dat]]

- [[CRSF-dat]] 
  
- [[FrSky-dat]] == [[CC2500-dat]] 

- [[ELRS-dat]] - [[ELRS-RX-dat]] - [[ELRS-TX-dat]]


## SDR 

Reverse engineering with a software-defined radio (SDR) (like RTL-SDR or HackRF).

    You could record the RF signal and analyze it to reverse engineer the protocol.

    This is complex and requires RF/digital signal processing (DSP) knowledge.

Sniffing with NRF24L01+ in promiscuous mode (some hacks exist, but limited).

    Might capture packets from other NRF24L01 devices only.

    Won’t work for general 2.4GHz devices.

- [[RTL-SDR-dat]] - [[hackrf-dat]]


## Step-by-Step: How to Sniff 2.4GHz RC Signal

1. Gather Tools
2. 
RTL-SDR dongle (most only go up to ~1.7 GHz → Not enough for 2.4GHz)

→ You need:

- A HackRF One (recommended – covers 1 MHz to 6 GHz)
- OR a CC2500 module (common 2.4GHz transceiver used in RC gear)
- OR an ESP32 with promiscuous mode (works only for Wi-Fi packets)



## ref 

- [[RC-dat]] - [[logic-analyzer-dat]]