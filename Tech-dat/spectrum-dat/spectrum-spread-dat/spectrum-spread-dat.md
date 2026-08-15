
# spectrum-spread-dat


- [[DSSS-dat]] - [[FHSS-dat]] - [[spectrum-dat]] - [[spectrum-spread-dat]]


`DSSS (Direct Sequence Spread Spectrum)`

Direct Sequence Spread Spectrum is a modulation technique where the transmitted signal is spread over a much larger bandwidth than the original message by multiplying it with a high-rate pseudo-random noise (PN) code (often called a "chip" sequence).

How it works: The transmitter takes the original digital data stream and combines it with a high-speed bit sequence (chips) using an XOR operation. This distributes the signal's energy across a wide frequency spectrum.

Key Advantages:

High Resistance to Interference: Narrowband interference only affects a small fraction of the spread signal, and error-correction algorithms can easily recover the data.

Low Probability of Intercept: Because the energy is spread thin across a wide band, the signal looks like background noise to unintended receivers.

Common Use Cases: Wi-Fi (older 802.11b standards), GPS, and CDMA cellular networks.

`FHSS (Frequency Hopping Spread Spectrum)`

Frequency Hopping Spread Spectrum is a method where the carrier frequency of the transmitted signal rapidly changes (hops) among a large number of distinct frequencies in a pseudo-random sequence known to both the transmitter and receiver.

How it works: Instead of staying on one channel, the radio frequency switches rapidly—sometimes hundreds of times per second—according to a pre-arranged hopping pattern. If a particular frequency is jammed or experiencing heavy interference, data is only briefly affected before the system hops to a clear channel.

Key Advantages:

Excellent Coexistence: Multiple devices can operate in the same crowded frequency band (like the 2.4 GHz ISM band) without interfering with each other, as long as they use different hopping patterns.

Jamming Resilience: Harder to track, intercept, or jam than fixed-frequency transmissions.

Common Use Cases: Bluetooth, legacy Wi-Fi (802.11), military tactical radios, and cordless phones.



## ref 

