


# SerDes-dat

- [[fiber-optic-dat]] - [[SerDes-dat]] - [[SGMII-dat]]

SerDes fiber (often referred to as optical SerDes) is the pairing of `SerDes (Serializer/Deserializer)` technology with fiber-optic links to move high-speed data over longer distances or higher bandwidths than copper allows. A SerDes converts wide parallel data streams inside a chip into a fast serial stream for transmission, then converts the serial stream back into parallel data at the receiving end.

How It Works with Fiber

- • Parallel-to-Serial Conversion: The serializer combines multiple parallel bits into a single high-speed serial data stream, reducing pin counts, wiring complexity, and signal skew.
- • Electrical-to-Optical Translation: In fiber links, a Synopsys or transceiver physical layer (PHY) pairs electrical SerDes lanes with optical transceivers (such as SFP+, QSFP+, or co-packaged optics) to send signals as light pulses over optical fiber and convert light back to electrical signals at the receiver.
- • High-Speed Signaling: Modern high-rate links use encoding (such as 8b/10b or 64b/66b) and modulation schemes like PAM-4 (four-level pulse amplitude modulation) alongside equalization and clock data recovery (CDR) to reach 10G, 25G, 112G, 200G, and 224G per lane.

Common Usage Examples

- • Data Centers & AI Clusters: Connecting GPUs/accelerators, top-of-rack and spine switches, and servers across racks where copper faces reach, power, or size limits.
- • High-Speed Networking & Storage: Ethernet (10GbE to 800G/1.6T), InfiniBand, and Fibre Channel links using optical transceivers.
- • Telecom & 5G Fronthaul/Backhaul: Transporting high-bandwidth traffic using protocols such as CPRI/eCPRI and Optical Transport Network (OTN) over fiber.

Related Terms & Synonyms

• Optical SerDes (most common direct equivalent for SerDes paired with fiber)
• SerDes over fiber or fiber-optic SerDes
• High-Speed Serial Interface (HSSI) or High-Speed SerDes (HSS) (broader serial link terms, which may use copper or fiber)
• Optical PHY / SerDes PHY (the physical-layer circuitry driving optical modules)



## ref 